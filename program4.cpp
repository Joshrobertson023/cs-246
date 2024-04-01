//**********************************************************************
//*                                                                    *
//* Program Name: PROG04 - Manage Straight-Sided Geometric Shapes      *
//* Author:       Josh Robertson                                       *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: March 7, 2024                                        *
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
//*                                                                    *
//**********************************************************************

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NUMBER        "CS246" // PCC assigned course number
#define COURSE_NAME          "Object-Oriented Programming and Design"
                                     // PCC assigned course name
#define PROGRAM_NUMBER       4       // Teacher assigned program number
#define RT_TRIANGE_ALLOC_ERR 1       //
#define SQUARE_ALLOC_ERR     2       //
#define RECTANGLE_ALLOC_ERR  3       //

//**********************************************************************
//*                           Program Classes                          *
//**********************************************************************
// The base shape
class base_shape
{
    float perimeter,    //
          area;         //
    int   unique_sides, //
          total_sides;  //
public:
    //
    virtual void show_shape() {};

    // Set the data members
    void set_perimeter(float user_perimeter) { perimeter = user_perimeter; return; };
    void set_area(float user_area) { area = user_area; return; };
    void set_unique_sides(int user_unique_sides) { unique_sides = user_unique_sides; return; };
    void set_total_sides(int user_total_sides) { total_sides = user_total_sides; return; };

    // Get the data members
    float get_perimeter() { return perimeter; };
    float get_area() { return area; };
    int get_unique_sides() { return unique_sides; };
    int get_total_sides() { return total_sides; };

    // Print fatal error message
    void fatal_error(const char* p_function_name, int error_number);
};

// The derived right triangle class
class right_triangle : public base_shape
{
    float base,       //
        height,     //
        hypotenuse; //
    char* p_name;    //
public:
    // Constructor, create a right triangle
    right_triangle(const char* p_shape_name, float* p_base, float* p_height);

    // Destructor, destroy a right triangle
    ~right_triangle();

    //
    void show_shape();
};

//**********************************************************************
//* Constructor, create a right triangle
//**********************************************************************
right_triangle::right_triangle(const char* p_shape_name, float* p_base, float* p_height)
{
    if ((p_name = (char*)malloc(strlen(p_shape_name) + 1)) == NULL)
        fatal_error("RIGHT_TRIANGE_1", RT_TRIANGE_ALLOC_ERR);

    strcpy_s(p_name, strlen(p_shape_name) + 1, p_shape_name);

    base = *p_base;
    height = *p_height;
    set_total_sides(3);
    set_unique_sides(3);
    hypotenuse = sqrtf(pow(base, 2) + pow(height, 2));
    set_area((base * height) / 2);
    set_perimeter(base + height + hypotenuse);

    cout << "Creating right triangle shape \"" << p_name << "\"";
    cout << "     with base = " << base
        << " and height = " << height;

    show_shape();
}

//**********************************************************************
//* Show the right triangle specifications
//**********************************************************************
void right_triangle::show_shape()
{
    cout << "The specification sof a right triangle shape are:";
    cout << "-------------------------------------------------";
    cout << "Name of the shape:       " << p_name;
    cout << "Total number of sides:   " << get_total_sides();
    cout << "Number of unique sides:  " << get_unique_sides();
    cout << "Length of base:          " << base;
    cout << "Length of height:        " << height;
    cout << "Length of hypotenuse:    " << hypotenuse;
    cout << "Area:                    " << get_area();
    cout << "Perimeter:               " << get_perimeter();
}

//**********************************************************************
//* Print fatal error message
//**********************************************************************
void base_shape::fatal_error(const char* p_function_name, int error_number)
{
    cout << "Error #" << error_number << " in " << p_function_name;
    cout << "Cannot allocate memory for the " << p_function_name;
    cout << "The program is aborting.";
    exit(RT_TRIANGE_ALLOC_ERR);
}

//**********************************************************************
//*                         Function Prototypes                        *
//**********************************************************************
void print_heading();
// Print the program heading

//**********************************************************************
//*                            Main Function                           *
//**********************************************************************
int main()
{
    base_shape user_shape,    //
        * p_user_shape; //

    p_user_shape = &user_shape;

    // Print the program heading
    print_heading();

    // Create a right triangle
    right_triangle right_triangle_1("RIGHT_TRIANGLE_1", 5.99f, 11.99f);

    //
    p_user_shape = &right_triangle_1;
    p_user_shape->show_shape();

    // Say goodbye and terminate the program
    cout << "Thanks for shaping things up today ;)";
    cout << "\n\n\n\n\n\n";
    return 0;
}

//**********************************************************************
//*                      Print the program heading                     *
//**********************************************************************
void print_heading()
{
    cout << "\n\n\n\n\n\n     " << COURSE_NUMBER
        << " " << COURSE_NAME
        << " - Program " << PROGRAM_NUMBER;
    cout << "\n\n                      This program draws a rectangle";
    cout << "\n                      ==============================";
    return;
}