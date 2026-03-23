[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Gu7VbefZ)
# ECE231_Assignment6
# Lab Assignment 6
We will be making a doubly-linked list in this lab assignment.  The linked list will keep track of x-y coordinate pairs.  The program will randomly generate a number of x-y pairs given by the user on the command line.  Actual values will be generated randomly.  A function to determine the closest x-y point to another x-y point will be written that prints out the distance and the x-y point closest.  Program in C++

# Struct data type
Create a struct in a header file called coordinate.h with a structure defined as
```
struct _coordinate
{
  float x;
  float y;
  int coord_id;
  struct _coordinate *next;
  struct _coordinate *previous;
};
typedef struct _coordinate Coordinate;
```
coord_id should be automatically incremented in the add_coordinate function based on the length of the list

Create the following functions
```
void add_coordinate(Coordinate *list_end, float x, float y);
void forward_display(Coordinate *list_beginning);
void backward_display(Coordinate *list_end);
void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete);
int list_length(Coordinate *list_beginning);
void closest_to(Coordinate *list_beginning, float x, float y);
```
function descriptions
```
add_coordinate: add's a coordinate to the end of the linked list
forward_display: displays all coordinates from beginning to end
backwards_display: displays all coordinates from end to beginning
delete_coordinate: removes a coordinate from the linked list (free memory!)
list_length: return the length of the list
closest_to: find the coordinate that is closest to the given x, y and output the distance between the 2
```

# Program Use
Use random numbers to fill the x and y coordinates, make the number of coordinates arbitrary and taken from the command line, the user will run the program like
```
./main 10
```
and will make 10 x-y pair coordinates that are randomly generated.

Use each function in the main.c file to add coordinates, display the list, delete a coordinate, and find the closest to.  You can just supply values to the function of delete coordinate and closest to functions.


