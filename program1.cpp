//**********************************************************************
//*                                                                    *
//* Program Name: PROG01 - Draw rectangle picture and specifications   *
//* Author:       Josh Robertson                                       *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: February 1, 2020                                     *
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
//* This program asks for a length and width of a rectangle, then      *
//* prints out a picture of the rectangle and its specifications such  *
//* as the length, width, area, and perimeter.                         *
//*                                                                    *
//**********************************************************************

#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NUMBER    "CS246" // PCC assigned course number
#define COURSE_NAME      "Object-Oriented Programming and Design"
#define PROGRAM_NUMBER   1       // Teacher assigned program number
#define MIN_RECT_LENGTH  1       // Minimum allowed rectangle length
#define MIN_RECT_WIDTH   1       // Minimum allowed rectangle width
#define RECT_BORDER_CHAR "*"     // Character used for rectangle border
#define RECT_CENTER_CHAR " "     // Character used for rectangle center
#define SCALE_FACOR      1.5     // Amount to scale rectangle's length

//**********************************************************************
//*                         Program Structures                         *
//**********************************************************************
// 
struct rectangle
{
   float area,      // Area of the rectangle
         perimeter, // Perimeter of the rectangle
         width,     // Rectangle's width
         length;    // Rectangle's length
};

//**********************************************************************
//*                         Function Prototypes                        *
//**********************************************************************
void print_heading();
   // Print the program heading
void get_rectangle(struct rectangle *p_rectangle);
   // Get and calculate the specifications of the rectangle
void draw_rectangle(float f_width, float f_length);
   // Draw the rectangle and print the specifications
void show_rectangle(float width, float length,
                    float area,  float perimeter);
   // Print the rectangle specifications

//**********************************************************************
//*                            Main function                           *
//**********************************************************************
int main()
{
   struct rectangle rectangle; // The rectangle to be printed out

   // Print the program heading
   print_heading();

   // Get the rectangle length and width and calculate the area and
   // perimeter
   get_rectangle(&rectangle);

   // Draw a picture of the rectangle and draw the specifications
   draw_rectangle(rectangle.width, rectangle.length);
   show_rectangle(rectangle.width, rectangle.length,
                  rectangle.area,  rectangle.perimeter);

   // Say goodbye and terminate the program
   cout << "\n\nThanks for drawing a rectangle today ;)";
   cout << "\n\n\n\n\n\n";
   return 0;
}

//**********************************************************************
//*                      Print the program heading                     *
//**********************************************************************
void print_heading()
{
   cout << "\n\n\n\n\n\n         " << COURSE_NAME 
        << " - Program "           << PROGRAM_NUMBER;
   cout << "\n\n                      This program draws a rectangle";
   cout <<   "\n                      ==============================";
   return;
}

//**********************************************************************
//*            Get and calculate the rectangle specifications          *
//**********************************************************************
void get_rectangle(struct rectangle *p_rectangle)
{
   cout << "\n\n\nEnter the rectangle length now: ";
   cin  >> p_rectangle->length;
   cout <<     "\nEnter the rectangle width here: ";
   cin  >> p_rectangle->width;

   p_rectangle->area      =      p_rectangle->length * p_rectangle->width;
   p_rectangle->perimeter = 2 * (p_rectangle->length + p_rectangle->width);

   return;
}

//**********************************************************************
//*                          Draw the rectangle                        *
//**********************************************************************
void draw_rectangle(float f_width, float f_length)
{
   int i_width,  // Rectangle's width as an integer
       i_length, // Rectangle's length as an integer
       columns,  // Number of columns printed
       rows;     // Number of rows printed

   // Check to see if the rectangle meets requirements
   if (f_width < MIN_RECT_WIDTH || f_length < MIN_RECT_LENGTH)
   {
      cout << "\n\n\nA "                    << f_width 
           << " by "                        << f_length 
           << " rectangle is too small to draw.";
      cout << "\nIt must be at least size " << MIN_RECT_WIDTH 
           << " by "                        << MIN_RECT_LENGTH 
           << " (length by width).";
   }
   else
   {
      // Convert floats to integers and scale the length
      i_width  = int(f_width);
      i_length = int(f_length * SCALE_FACOR);

      // Print rectangle's title
      cout << "\n\n\n\nHere is a picture of your rectangle:";

      // Print the top border of the rectangle
      cout << "\n";
      for (rows = 0; rows < i_length; rows++)
         cout << RECT_BORDER_CHAR;
      cout << "\n";

      // Print the middle of the rectangle
      for (columns = 0; columns < i_width - 2; columns++)
      {
         cout << RECT_BORDER_CHAR;
         for (rows = 0; rows < i_length - 2; rows++)
               cout << RECT_CENTER_CHAR;
         cout << RECT_BORDER_CHAR << "\n";
      }

      // Print bottom border of the rectangle
      for (rows = 0; rows < i_length; rows++)
         cout << RECT_BORDER_CHAR;
   }

   return;
}

//**********************************************************************
//*                 Print the rectangle's specifications               *
//**********************************************************************
void show_rectangle(float width, float length, 
                    float area,  float perimeter)
{
   cout << "\n\n\nThe rectangle specifications are:";
   cout <<     "\n        Length = " << length    << " units";
   cout <<     "\n         Width = " << width     << " units"; 
   cout <<     "\n          Area = " << area      << " sq. units";
   cout <<     "\n     Perimeter = " << perimeter << " units";
   return;
}