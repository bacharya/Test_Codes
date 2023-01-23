#include "stdlib.h"
#include "stdio.h"
#include "stdint.h"
    
typedef struct test_type_
{
  uint32_t d1;
  uint16_t d2;
  uint16_t d3;
} test_type_t;

void
extract_buffer (char *buffer)
{

  test_type_t b1;

  b1 = *(test_type_t *) buffer;
  if (!buffer)
    {
      return;
    }
#if 0
  printf ("%x\n", b1.d1);
  printf ("%x\n", b1.d2);
  printf ("%x\n", b1.d3);
#endif
  printf ("%x\n", *(uint32_t *) buffer);
  printf ("%x\n", *(uint16_t *) (buffer + 4));
  printf ("%x\n", *(uint16_t *) (buffer + 6));
  return;
}

int
main ()
{
  char buffer[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
  //int n;

  extract_buffer (buffer);
  return 0;
}

