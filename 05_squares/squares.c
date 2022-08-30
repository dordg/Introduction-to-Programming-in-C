
#include <stdio.h>
#include <stdlib.h>

int max(int n1, int n2);

int InRange(int coord, int offset, int size);

int onBorder(int coord, int offset, int size);

int OnLine(int range_coord, int range_offset, int border_coord, int border_offset, int size);

void squares(int size1, int x_offset, int y_offset, int size2);

int main(void) {
  //squares(4, 1, 2, 3);
  //squares(3, 5, 8, 2);
  //squares(5, 2, 4, 6);
  squares(9, 2, 3, 4);
  return 0;
}

/*
* Get max of two numbers
*/
int max(int n1, int n2) {
  if(n1 >= n2) {
    return n1;
  }
  return n2;
}

/*
* determines if coord is in range
*/
int InRange(int coord, int offset, int size) {
   if(coord >= offset && coord < offset + size) {
    return 1;
   }
   return 0;
}

/*
* determins if coord is on a border
*/
int onBorder(int coord, int offset, int size) {
  if(coord == offset || coord == offset + size - 1) {
    return 1;
  }
  return 0;
}

/*
* Returns if given coord is on the line
*/
int OnLine(int range_coord, int range_offset, int border_coord, int border_offset, int size) {
  if (InRange(range_coord, range_offset, size) && onBorder(border_coord, border_offset, size)) {
    return 1;
  }
  return 0;
}

void squares(int size1, int x_offset, int y_offset, int size2) {
  //compute the max of size1 and (x_offset + size2).  Call this w
  int w = max(size1, x_offset + size2);
  //compute the max of size1 and (y_offset + size2).  Call this h
  int h = max(size1, y_offset + size2);
  //count from 0 to h. Call the number you count with y
  for (int y = 0; y < h; y++) {
    
    //count from 0 to w. Call the number you count with x
    for (int x = 0; x < w; x++) {
      
      //check if  EITHER
      //    ((x is between x_offset  and x_offset +size2) AND 
      //     y is equal to either y_offset OR y_offset + size2 - 1 )
      //  OR
      //    ((y is between y_offset and y_offset + size2) AND
      //     x is equal to either x_offset OR x_offset + size2 -1)
      // if so, print a *
      if(OnLine(x, x_offset, y, y_offset, size2) || OnLine(y, y_offset, x, x_offset, size2)) {
        printf("*");
      }

      //if not,
      // check if EITHER
      //    x is less than size1 AND (y is either 0 or size1-1)
      // OR
      //    y is less than size1 AND (x is either 0 or size1-1)
      //if so, print a #
      else if(OnLine(x, 0, y, 0, size1) || OnLine(y, 0, x, 0, size1)) {
        printf("#");
      }

      //else print a space
      else {
        printf(" ");
      }
    }
      
    //when you finish counting x from 0 to w, 
    //print a newline
    printf("\n");
  }
  
}