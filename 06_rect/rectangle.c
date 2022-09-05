#include <stdio.h>
#include <stdlib.h>

//I've provided "min" and "max" functions in
//case they are useful to you

int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

//Declare your rectangle structure here!
typedef struct rectangle_t {
  int x;
  int y;
  int width;
  int height;
} rectangle;

void canonicalize_axis(int * ptr_coord, int * ptr_length) {
  if(*ptr_length < 0) {
    *ptr_coord += *ptr_length;
    *ptr_length *= -1;
  }
}

rectangle canonicalize(rectangle r) {
  // canonicalize x axis using canonicalize_axis(r.x, r.width)
  canonicalize_axis(&r->x, &r->width);

  // canonicalize y axis using canonicalize_axis(r.y, r.height)
  canonicalize_axis(&r->y, &r->height);

  // RETURN r
  return r;
}

int next_coord(coord, length) {
  return coord + length;
}

void axis_intersection(int * ptr_coord1, int * ptr_length1, int * ptr_coord2,int * ptr_length2, int * ptr_ri_coord, int * ptr_ri_length) {
  //set ri_coord to the max of coord1 and coord2 using max(coord1, coord2)
  *ptr_ri_coord = max(*ptr_coord1, *ptr_coord2);

  // set next_coord1 using next_coord(coord1, length1)
  int next_coord1 = next_coord(*ptr_coord1, *ptr_length1);

  //set next_coord2 using next_coord(coord2, length2)
  int next_coord2 = next_coord(*ptr_coord2, *ptr_length2);

  //set ri_next_coord using min(next_coord1, next_coord2)
  int ri_next_coord = min(next_coord1, next_coord2);

  //set ri_length to ri_next_coord - ri_coord
  *ptr_ri_length = ri_next_coord - *ptr_ri_coord;

  //IF ri_length < 0:
  if(*ptr_ri_length < 0) {
    //set ri_length to 0
    *ptr_ri_length = 0;
  }

}

rectangle intersection(rectangle r1, rectangle r2) {
  // canonicalize r1 using canonicalize(r1) 
  r1 = canonicalize(r1);

  // canonicalize r2 using canonicalizer(r2)
  r2 = canonicalize(r2);

  // declare rectangles' intersection as ri
  rectangle ri;

  // set ri's x axis intersection using axis_intersection
  axis_intersection(&r1->x, &r1->width, &r2->x, &r2->width, &ri->x, &ri->width);

  // set ri's y axis intersection using axis_intersection
  axis_intersection(&r1->y, &r1->length, &r2->y, &r2->length, &ri->y, &ri->length);

  // RETURN ri
  return ri;
}

//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, 
	                           r.x + r.width, r.y + r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = 4;
  r2.y = 5;
  r2.width = -5;
  r2.height = -7;
  printf("r2 is ");
  printRectangle(r2);

  r3.x = -2;
  r3.y = 7;
  r3.width = 7;
  r3.height = -10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = 0;
  r4.y = 7;
  r4.width = -4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);

  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);

  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);

  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);

  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;

}
