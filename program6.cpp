//**********************************************************************
//*                                                                    *
//* Program Name: PROG06 - Manage Company Employee Bonuses             *
//* Author:       Josh Robertson                                       *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: March 28, 2024                                       *
//*                                                                    *
//**********************************************************************

//**********************************************************************
//*                                                                    *
//* I pledge this assignment is my own first time work.                *
//* I pledge I did not copy or try to copy any work from the Internet. *
//* I pledge the only person I asked for help from was my teacher.     *
//* I pledge I did not attempt to help any student on this assignment. *
//* I understand if I violate this pledge I will receive a 0 grade.    *
//*                                                                    *
//*                                                                    *
//*                      Signed: _____________________________________ *
//*                                           (signature)              *
//*                                                                    *
//*                                                                    *
//**********************************************************************


//**********************************************************************
//*                                                                    *
//* This program asks for the company name, number of employees, year  *
//* the bonuses are being given, and the yearly bonus amount, then     *
//* lists the company information. For each employee, the program asks *
//* for the service years if they exist, calculates year hired and     *
//* bonus amount, then lists the employees in table form, sorted by    *
//* id, then sorted ascending by year hired.                           *
//*                                                                    *
//**********************************************************************

// *** TODO ***
// Change strcpy to strcpy_s

#include <iostream>
#include <new>
#include <cstdlib>
#include <cstring>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NUMBER      "CS246" // PCC assigned course number
#define COURSE_NAME        "Object-Oriented Programming and Design"
                                   // PCC assigned course name
#define PROGRAM_NUMBER     5       // Teacher assigned program number
#define MAX_NAME_LENGTH    80      // Maximum valid company name length
#define COMPANY_ALLOC_ERR  1       // Company info memory allocation error
#define NAME_ALLOC_ERR     2       // Company name memory allocation error
#define EMPLOYEE_ALLOC_ERR 3       // Employee memory allocation error

//**********************************************************************
//*                         Program Structures                         *
//**********************************************************************
// The company information
struct company_info
{
   char  *p_company_name;     // Points to the company's name
   int   number_of_employees, // Number of employees
         bonus_year;          // Year the bonuses are being processed
   float bonus_amount;        // Bonus amount per year employee was hired
};
typedef struct company_info COMPANY_INFO;

//**********************************************************************
//*                          Program Classes                           *
//**********************************************************************
// An employee bonus record
class employee_bonus_record
{
   int   year_hired,    // Year the employee was hired
         service_years, // Number of years the employee has been in service
         id;            // Employee's id number
   float bonus;         // Employee's bonus amount

public:
    // Set the data members
    void  set_year_hired   (int   y_h) {year_hired    = y_h;};
    void  set_service_years(int   s_y) {service_years = s_y;};
    void  set_id           (int   i)   {id            = i;};
    void  set_bonus        (float b)   {bonus         = b;};

    // Get the data members
    int   get_year_hired   ()          {return year_hired;};
    int   get_service_years()          {return service_years;};
    int   get_id           ()          {return id;};
    float get_bonus        ()          {return bonus;};

    // Destructor, destroy an employee bonus record
    ~employee_bonus_record ()          {cout << "\n\nDestructor executing ...";};
};

//**********************************************************************
//*                        Function Prototypes                         *
//**********************************************************************
void print_heading();
   // Print the program heading and instructions
COMPANY_INFO* get_company_info();
   // Get the company information
employee_bonus_record* get_employees(COMPANY_INFO *p_company_info);
   // Get the employee bonus records
void print_employees(employee_bonus_record *p_employee_bonus_record,
                     int number_of_employees, const char *p_method);
   // Print the employee bonus records
void sort_employees(employee_bonus_record *p_employee_database,
                    int number_of_employees);
   // Sort the employee bonus records ascending by year hired
void fatal_error(int error_number, const char *p_function_name,
                 const char *p_memory_allocating);
   // Print fatal error message and abort the program

//**********************************************************************
//*                           Main Function                            *
//**********************************************************************
int main()
{
   COMPANY_INFO          *p_company_info; 
                                 // Points to the company information
   employee_bonus_record *p_employee_bonus_records;
                                 // Points to the employee bonus records

   // Print the program heading and instructions
   print_heading();

   // Get and print the company information
   p_company_info = get_company_info();
   cout << "\n\n\nCompany name:        " << p_company_info->p_company_name;
   cout <<     "\nYear of the bonuses: " << p_company_info->bonus_year;
   cout <<     "\nNumber of employees: " << p_company_info->number_of_employees;
   cout <<     "\nBonus per year:      " << p_company_info->bonus_amount;

   // Get and print the employee bonus records
   p_employee_bonus_records = get_employees(p_company_info);
   print_employees(p_employee_bonus_records,
                   p_company_info->number_of_employees,
                   "IN UNSORTED ORDER");

   // Sort and print the employee bonus records in ascending order by
   // year hired
   sort_employees (p_employee_bonus_records,
                   p_company_info->number_of_employees);
   print_employees(p_employee_bonus_records,
                   p_company_info->number_of_employees,
                   "SORTED BY YEAR HIRED");

   // Free the dynamically allocated memory
   delete   p_company_info;
   delete[] p_employee_bonus_records;

   // Say goodbye and terminate the program
   cout << "\n\nThanks for processing employee bonuses today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*             Print the program heading and instructions             *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n" << COURSE_NUMBER
        << " "            << COURSE_NAME
        << " - Program "  << PROGRAM_NUMBER;
   cout << "\n========================================================";
   cout << "\nThis program asks for information about your company and";
   cout << "\nabout each employee. It then calculates the bonus amount";
   cout << "\nowed each employee based on the number of service years.";
   return;
}

//**********************************************************************
//*                     Get the company information                    *
//**********************************************************************
COMPANY_INFO *get_company_info()
{
   char         temporary_company_name[MAX_NAME_LENGTH+1];
                                    // Temporary company name
   COMPANY_INFO *p_company_info = NULL;
                                    // Points to the company information

   // Try to allocate memory for the company information
   try
   {
      p_company_info = new COMPANY_INFO;
   }
   catch (bad_alloc xa)
   {
      fatal_error(COMPANY_ALLOC_ERR, "get_company_information()",
                  "company information struct");
   }

   // Get the company name, allocate memory for it, and abort if memory
   // is not available
   cout << "\n\n\nEnter the name of your company here (no spaces): ";
   cin  >> temporary_company_name;
   try
   {
      p_company_info->p_company_name
                             = new char[strlen(temporary_company_name)];
   }
   catch (bad_alloc xa)
   {
      fatal_error(NAME_ALLOC_ERR, "get_company_information()",
                  "company name");
   }
   strcpy(p_company_info->p_company_name, temporary_company_name);
   // strcpy_s(p_company_info->p_company_name, temporary_company_name,
   //          MAX_NAME_LENGTH+1);

   // Get the number of employees
   do
   {
      cout << "\nEnter your number of employees (1 or more): ";
      cin  >> p_company_info->number_of_employees;
      if (p_company_info->number_of_employees < 1)
         cout << "     The number of employees must be 1 or more.";
   }
   while (p_company_info->number_of_employees < 1);

   // Get the current year the bonuses are being given
   cout << "Enter the year in which the bonuses are given (YYYY): ";
   cin  >> p_company_info->bonus_year;

   // Get the yearly bonus amount per employee
   cout << "Give the yearly bonus amount per employee (in dollars): ";
   cin  >> p_company_info->bonus_amount;

   // Return the company information
   return p_company_info;
}

//**********************************************************************
//*                   Get the employee bonus records                   *
//**********************************************************************
employee_bonus_record *get_employees(COMPANY_INFO *p_company_info)
{
   int                   employee_id = 1, // Employee id number
                         service_years;   // Employee's service years
   employee_bonus_record *p_employee,     // Points to each employee bonus record
                         *p_employee_bonus_records;
                                          // Points to the employee bonus records

   // try to allocate memory for the employee bonus records
   try
   {
      p_employee_bonus_records
         = new employee_bonus_record[p_company_info->number_of_employees];
   }
   catch (bad_alloc xa)
   {
      fatal_error(EMPLOYEE_ALLOC_ERR, "get_employees()",
                  "database of employee bonus records");
   }
   p_employee = p_employee_bonus_records;

   // Loop processing getting employee bonus records until all employees
   // are entered
   do
   {
      // Get the employee service years
      do
      {
         cout <<  "\n\nEnter the number of service years of employee #"
              <<                                             employee_id 
              <<                                                     ".";
         cout <<    "\nEnter 0 (zero) if this employee does not exist: ";
         cin  >> service_years;
         if (service_years < 0)
            cout <<   "     The service years must be 0 or greater.";
      }
      while (service_years < 0);

      // Get the employee id, year hired, and bonus amount
      if (service_years > 0)
      {
         p_employee->set_service_years(service_years);
         p_employee->set_id           (employee_id);
         p_employee->set_year_hired   (p_company_info->bonus_year
                                                         - service_years);
         p_employee->set_bonus        (p_company_info->bonus_amount 
                                       * p_employee->get_service_years());
         p_employee++;
      }
      employee_id++;
   }
   while ((p_employee - p_employee_bonus_records)
           < p_company_info->number_of_employees);

   // Return the employee records database
   return p_employee_bonus_records;
}

//**********************************************************************
//*                  Print the employee bonus records                  *
//**********************************************************************
void print_employees(employee_bonus_record *p_employee_start,
                     int number_of_employees, const char *p_sorted_condition)
{
   employee_bonus_record *p_employee; // Points to each employee bonus record

   cout << "\n\nHere is the employee database, " << p_sorted_condition
        <<                                                           ":";
   cout <<   "\n=======================================================";
   cout <<   "\nEmployee Id    Service Years    Year Hired    Bonus Amt";
   cout <<   "\n-----------    -------------    ----------    ---------";

   for (p_employee = p_employee_start;
       (p_employee - p_employee_start) < number_of_employees;
        p_employee++)
   {
      cout <<        "\n     " << p_employee->get_id()
           << "              " << p_employee->get_service_years()
           << "              " << p_employee->get_year_hired()
           <<     "         $" << p_employee->get_bonus();
   }

   return;
}

//**********************************************************************
//*      Sort the employee bonus records ascending by year hired       *
//**********************************************************************
void sort_employees(employee_bonus_record *p_employees_start,
                    int number_of_employees)
{
   employee_bonus_record *p_employee_outer,
                         // Points to the outer loop employee
                         *p_employee_inner,
                         // Points to the employees being compared
                         temporary_employee;
                         // Points to the temporary employee for the swap

   for (p_employee_outer = p_employees_start;
       (p_employee_outer - p_employees_start) < number_of_employees-1;
        p_employee_outer++)
      for (p_employee_inner = p_employees_start;
          (p_employee_inner - p_employees_start) < number_of_employees-1;
           p_employee_inner++)
         if (p_employee_inner->get_year_hired() 
              > (p_employee_inner+1)->get_year_hired())
            {
               temporary_employee    =  *p_employee_inner;
                *p_employee_inner    = *(p_employee_inner+1);
               *(p_employee_inner+1) = temporary_employee;
            }

   return;
}

//**********************************************************************
//*           Print fatal error message and abort the program          *
//**********************************************************************
void fatal_error(int error_number, const char *p_function_name,
                 const char *p_memory_allocating)
{
   cout << "\nError #"                         << error_number
        << " occurred in "                     << p_function_name;
   cout << "\nCannot allocate memory for the " << p_memory_allocating;
   cout << "\nThe program is aborting.";
   return;
}