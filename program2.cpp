//**********************************************************************
//*                                                                    *
//* Program Name: PROG02 - Demonstrate Function Overloading            *
//* Author:       Josh Robertson                                       *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: February 15, 2024                                    *
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
//* This program asks for a circle's diameter, a rectangle's length,   *
//* width, and depth, then calculates and prints the area of the       *
//* circle, the area of the rectangle, and the volume of the           *
//* rectangular solid.                                                 *
//*                                                                    *
//**********************************************************************

#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NUMBER    "CS246"  // PCC assigned course number
#define COURSE_NAME      "Object-Oriented Programming and Design"
                                  // PCC assigned course name
#define PROGRAM_NUMBER   1        // Teacher assigned program number
#define PI               3.141593 // Mathematical constant pi

//**********************************************************************
//*                         Function Prototypes                        *
//**********************************************************************
void print_heading();
   // Print the program heading
void get_dimensions(float *p_depth,  float *p_diameter,
                    float *p_length, float *p_width);
   // Get the circle and rectangle dimensions
void calculate_dimensions(float diameter);
   // Calculate the area of a circle
void calculate_dimensions(float length, float width);
   // Calculate the area of a rectangle
void calculate_dimensions(float depth, float length, float width);
   // Calculate the volume of a rectangular solid

//**********************************************************************
//*                            Main function                           *
//**********************************************************************
int main()
{
   float depth,    // Rectangular solid's depth
         diameter, // Circle's diameter
         length,   // Rectangle's length
         width;    // Rectangle's width

   // Print the program heading
   print_heading();

   // Get the dimensions for the geometric shapes
   get_dimensions(&depth, &diameter, &length, &width);

   // Calculate and display the geometric shape dimensions
   cout << "\n\nHere are the requested areas and volume:";
   cout <<   "\n----------------------------------------";
   calculate_dimensions(diameter);
   calculate_dimensions(length, width);
   calculate_dimensions(depth, length, width);

   // Say goodbye and terminate the program
   cout << "\n\nThanks for calculating geometric shapes today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                      Print the program heading                     *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n     " << COURSE_NAME 
        << " - Program "           << PROGRAM_NUMBER;
   cout << "\n===========================================================";
   cout << "\n         Calculate geometric shape areas and volume";
   return;
}

//**********************************************************************
//*              Get the circle and rectangle dimensions               *
//**********************************************************************
void get_dimensions(float *p_depth,  float *p_diameter,
                    float *p_length, float *p_width)
{
   cout << "\n\n\nEnter the geometric shape dimensions as follows:";
   cout <<     "\n    Circle diameter: ";
   cin  >> *p_diameter;
   cout <<       "   Rectangle length: ";
   cin  >> *p_length;
   cout <<       "    Rectangle width: ";
   cin  >> *p_width;
   cout <<       "    Rectangle depth: ";
   cin  >> *p_depth;
   return;
}

//**********************************************************************
//*                   Calculate the area of a circle                   *
//**********************************************************************
void calculate_dimensions(float diameter)
{
   cout << "\nArea of a circle with diameter " << diameter << ":";
   cout << "   " << ((1/4) * PI * (diameter * diameter)) << " square units";
   return;
}

//**********************************************************************
//*                  Calculate the area of a rectangle                 *
//**********************************************************************
void calculate_dimensions(float length, float width)
{
   cout << "\nArea of a rectangle of length " << length << " by width " 
        << width << ":";
   cout << "   " << (length * width) << " square units";
   return;
}

//**********************************************************************
//*             Calculate the volume of a rectangular solid            *
//**********************************************************************
void calculate_dimensions(float depth, float length, float width)
{
   cout << "\nVolume of a rectangular solid of length " << length 
        << ", width " << width << ", depth " << depth << ":";
   cout << "   " << (length * width * depth) << " cubic units";
   return;
}