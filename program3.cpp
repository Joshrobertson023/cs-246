//**********************************************************************
//*                                                                    *
//* Program Name: PROG03 - Draw Rectangle Picture and Print its        *
//*                        Specifications                              *
//* Author:       Josh Robertson                                       *
//* Installation: Pensacola Christian College, Pensacola, Florida      *
//* Course:       CS246, Object-Oriented Programming and Design        *
//* Date Written: March 1, 2024                                        *
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
//* This program asks for the length and width of a rectangle,         *
//* calculates the area and perimeter, then draws a picture of the     *
//* rectangle and prints its specifications.                           *
//*                                                                    *
//**********************************************************************

#include <iostream>
using namespace std;

//**********************************************************************
//*                         Symbolic Constants                         *
//**********************************************************************
#define COURSE_NUMBER         "CS246" // PCC assigned course number
#define COURSE_NAME           "Object-Oriented Programming and Design"
                                      // PCC assigned course name
#define PROGRAM_NUMBER        1       // Teacher assigned program number
#define MIN_RECT_LENGTH       1.0f    // Minimum allowed rectangle length
#define MIN_RECT_WIDTH        1.0f    // Minimum allowed rectangle width
#define RECT_BORDER_CHARACTER '*'     // Character used for rectangle border
#define RECT_CENTER_CHARACTER ' '     // Character used for rectangle center
#define SCALE_FACTOR          1.5f    // Amount to scale rectangle's length

//**********************************************************************
//*                           Program Classes                          *
//**********************************************************************
// A rectangle
class rectangle
{
   float area,      // Area of the rectangle
         length,    // Rectangle's length
         perimeter, // Perimeter of the rectangle
         width;     // Rectangle's width
public:
   // Constructor, create a rectangle
        rectangle     (float length, float width);

   // Destructor, delete a rectangle
        ~rectangle    ();

   // Draw a picture of the rectangle
   void draw_rectangle();

   // Print the rectangle's specifications
   void show_rectangle();
};

//**********************************************************************
//*                         Create a rectangle                         *
//**********************************************************************
rectangle::rectangle(float user_length, float user_width)
{
   length    = user_length;
   width     = user_width;
   area      =         length * width;
   perimeter = 2.0f * (length + width);
}

//**********************************************************************
//*                         Delete a rectangle                         *
//**********************************************************************
rectangle::~rectangle()
{
   cout << "The rectangle object is being destructed now.";
}

//**********************************************************************
//*                   Draw a picture of the rectangle                  *
//**********************************************************************
void rectangle::draw_rectangle()
{
   int columns,  // Counts the number of columns printed
       i_length, // Rectangle's length as an integer
       i_width,  // Rectangle's width as an integer
       rows;     // Counts the number of rows printed

   // Check to see if the rectangle meets size requirements
   if (width < MIN_RECT_WIDTH || length < MIN_RECT_LENGTH)
   {
      cout << "\n\n\nA "                    << width 
           << " by "                        << length 
           << " rectangle is too small to draw.";
      cout << "\nIt must be at least size " << MIN_RECT_WIDTH 
           << " by "                        << MIN_RECT_LENGTH 
           << " (length by width).";
   }
   else
   {
      // Convert the rectangle dimensions to whole numbers and 
      // scale the length
      i_width  = int(width);
      i_length = int(length * SCALE_FACTOR);

      // Print the rectangle's title
      cout << "\n\n\n\nHere is a picture of your rectangle:";

      // Print the top rectangle row
      cout << "\n";
      for (columns = 1; columns < i_length + 1; columns++)
         cout << RECT_BORDER_CHARACTER;

      // Print the middle of the rectangle
      for (rows = 1; rows < i_width - 1; rows++)
      {
         cout << "\n";
         cout << RECT_BORDER_CHARACTER;
         for (columns = 1; columns < i_length - 1; columns++)
               cout << RECT_CENTER_CHARACTER;
         cout << RECT_BORDER_CHARACTER;
      }

      // Print bottom border of the rectangle
      if (i_width >= 2)
      {
         cout << "\n";
         for (columns = 1; columns < i_length + 1; columns++)
            cout << RECT_BORDER_CHARACTER;
      }
   }

   return;
}

//**********************************************************************
//*                 Print the rectangle's specifications               *
//**********************************************************************
void rectangle::show_rectangle()
{
   cout << "\n\n\nThe rectangle specifications are:";
   cout <<     "\n        Length = " << length    << " units";
   cout <<     "\n         Width = " << width     << " units"; 
   cout <<     "\n          Area = " << area      << " sq. units";
   cout <<     "\n     Perimeter = " << perimeter << " units";
   return;
}

//**********************************************************************
//*                         Function Prototypes                        *
//**********************************************************************
void print_heading();
   // Print the program heading
void get_length_width(float *p_length, float *p_width);
   // Get the user specified rectangle length and width

//**********************************************************************
//*                            Main Function                           *
//**********************************************************************
int main()
{
   float user_length, // User entered rectangle length
         user_width;  // User entered rectangle width

   // Print the program heading
   print_heading();

   // Get a rectangle's user length and width
   get_length_width(&user_length, &user_width);

   // Create a rectangle with user entered length and width, and
   // calculate the area and perimeter
   rectangle rectangle(user_length, user_width);

   // Draw a picture of the rectangle and print the specifications
   rectangle.draw_rectangle();
   rectangle.show_rectangle();

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
   cout << "\n\n\n\n\n\n     " << COURSE_NUMBER
        << " "                 << COURSE_NAME 
        << " - Program "       << PROGRAM_NUMBER;
   cout << "\n\n                      This program draws a rectangle";
   cout <<   "\n                      ==============================";
   return;
}

//**********************************************************************
//*          Get the user specified rectangle length and width         *
//**********************************************************************
void get_length_width(float *p_length, float *p_width)
{
   cout << "\n\nEnter the rectangle length now: ";
   cin  >> *p_length;
   cout <<     "Enter the rectangle width here: ";
   cin  >> *p_width;
   return;
}