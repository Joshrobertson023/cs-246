//**********************************************************************
//*                                                                    *
//* Program Name: PROG05 - Calculate a square to circle area ratio     *
//* Author:       Josh Robertson                                       *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: March 21, 2024                                       *
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
//* This program asks for a diameter of a circle, calculates and       *
//* prints that circle's specifications, calculates and prints         *
//* specifications of a square whose perimeter is equal to the         *
//* circumference of that circle, then calculates and prints the ratio *
//* of the area of that square to the area of that circle              *
//*                                                                    *
//**********************************************************************

#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NUMBER  "CS246"   // PCC assigned course number
#define COURSE_NAME    "Object-Oriented Programming and Design"
                                 // PCC assigned course name
#define PROGRAM_NUMBER 5         // Teacher assigned program number
#define QUIT_DIAMETER  0.0f      // Program quit value
#define MIN_DIAMETER   0.0f      // Minimum valid diameter
#define PI             3.141593f // Mathematical constant pi

//**********************************************************************
//*                           Program Classes                          *
//**********************************************************************
// Forward reference of the circle
class circle;

// The specifications of the square
class square
{
   float area      = 0.0f, // Area of the square
         perimeter = 0.0f, // Perimeter of the square
         side      = 0.0f; // A side of the square

public:
   // Constructors, create a square
                 square       ()        {};
                 square       (float s) {side = s;};

   // Set the data members
          void   set_area     (float a) {area = a;};
          void   set_perimeter(float p) {perimeter = p;};
          void   set_side     (float s) {side = s;};

   // Get the data members
          float  get_area     ()        {return area;};
          float  get_perimeter()        {return perimeter;};
          float  get_side     ()        {return side;};
    
   // Create a square similar to the circle
          square create_square(circle circle_1);

   // Calculate the square to circle area ratio
   friend float  area_ratio   (square square, circle circle);
};

// The specifications of the circle
class circle
{
   float area          = 0.0f, // Area of the circle
         circumference = 0.0f, // Circumference of the circle
         diameter      = 0.0f; // Diameter of the circle

public:
   // Constructors, create a circle
                 circle           ()        {};
                 circle           (float d) {diameter = d;};

   // Set the data members
          void   set_area         (float a) {area = a;};
          void   set_circumference(float c) {circumference = c;};
          void   set_diameter     (float d) {diameter = d;};

   // Get the data members
          float  get_area         ()        {return area;};
          float  get_circumference()        {return circumference;};
          float  get_diameter     ()        {return diameter;};

   // Create a square similar to the circle
   friend square create_square    (circle circle_1);

   // Calculate the square to circle area ratio
   friend float  area_ratio       (square square, circle circle);
};

//**********************************************************************
//*                Create a square similar to the circle               *
//**********************************************************************
square square::create_square(circle circle_1)
{
   square temporary_square; // A temporary square

   temporary_square.set_perimeter(circle_1.get_circumference());
   temporary_square.set_side     (temporary_square.get_perimeter() 
                                                               * 0.25f);
   temporary_square.set_area     (temporary_square.get_side() 
                                         * temporary_square.get_side());

   return temporary_square;
}

//**********************************************************************
//*              Calculate the square to circle area ratio             *
//**********************************************************************
float area_ratio(square square_1, circle circle_1)
{
   return (square_1.get_area() / circle_1.get_area());
}

//**********************************************************************
//*                         Function Prototypes                        *
//**********************************************************************
void print_heading();
   // Print the program heading
circle get_circle();
   // Create a new circle

//**********************************************************************
//*                            Main Function                           *
//**********************************************************************
int main()
{
   square new_square; // A new square
   circle new_circle; // A new circle

   // Print the program heading
   print_heading();

   // Loop processing circle and square specifications until the user quits
   while (new_circle = get_circle(), 
         (new_circle.get_diameter() != QUIT_DIAMETER))
   {
      // Print the new circle's specifications
      cout << "\n\n\nThe circle's specifications are:";
      cout <<     "\n--------------------------------";
      cout <<     "\n       diameter: " << new_circle.get_diameter();
      cout <<     "\n  circumference: " << new_circle.get_circumference();
      cout <<     "\n           area: " << new_circle.get_area();

      // Create a square equal to the circumference of the circle
      new_square = new_square.create_square(new_circle);

      // Print the new square's specifications
      cout <<   "\n\nThe squares's specifications are:";
      cout <<     "\n--------------------------------";
      cout <<     "\n           side: " << new_square.get_side();
      cout <<     "\n      perimeter: " << new_square.get_perimeter();
      cout <<     "\n           area: " << new_square.get_area();

      // Calculate and print the square to circle area ratio
      cout <<   "\n\nRatio of the square's area to the circle's area is:";
      cout <<     "\n---------------------------------------------------";
      cout <<     "\n               <**** " 
           << area_ratio(new_square, new_circle) << " ****>";
   }

   // Say goodbye and terminate the program
   cout << "\n\n\n Goodbye, and I hope you learned something about the"
        <<     "\nratio of the area of a square to the area of a circle,"
        <<     "\nwhere the perimeter of the square is exactly equal to"
        <<     "\n           the circumference of the circle";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                      Print the program heading                     *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n     " << COURSE_NUMBER
        << " "                 << COURSE_NAME
        << " - Program "       << PROGRAM_NUMBER;
   cout << "\n     ========================================================";
   return;
}

//**********************************************************************
//*                         Create a new circle                        *
//**********************************************************************
circle get_circle()
{
   float diameter; // Diameter of the circle

   do
   {
      cout << "\n\nEnter a circle diameter greater than " 
           << MIN_DIAMETER << " (or " << QUIT_DIAMETER << " to quit): ";
      cin  >> diameter;

      if (diameter < MIN_DIAMETER)
         cout << "     Invalid: diameter must be greater than "
              << MIN_DIAMETER << " (or " << QUIT_DIAMETER << " to quit).";
   } 
   while (diameter < MIN_DIAMETER);

   circle temporary_circle(diameter);

   temporary_circle.set_area         (0.25f * PI * (diameter * diameter));
   temporary_circle.set_circumference(PI * diameter);

   return temporary_circle;
}