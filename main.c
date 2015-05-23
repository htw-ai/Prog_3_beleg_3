#include <stdio.h>
#include <assert.h>

typedef enum { false, true } bool;

int  scmp(const char *s1, const char *s2);
void bubbleSort(const char* array[], int size);
void swapIndex(const char *array[], int index, int index2);

int scmp(const char *s1, const char *s2)
{
  while((*s1 && *s2) && (*s1 == *s2))
    s1++,s2++;
  return *s1 - *s2;
}

void swapIndex(const char *array[], int index, int index2)
{
  const char *tmp = array[index];
  array[index]    = array[index2];
  array[index2]   = tmp;
}

void bubbleSort(const char* array[], int size)
{
  int swaped = false;
  // iterate until nothing was swaped in one run
  do {
    swaped = false;
    // move window one field to the right
    for(int i = 1; i < size; i++)
    {
      if (scmp(array[i-1], array[i]) > 0)
      {
        swapIndex(array, i, i-1);
        swaped = true;
      }
    }
  } while (swaped);
}

int main(int argc, const char * argv[])
{
  assert(argc > 2);
  // remove first element (name of script) from array
  argv++;
  argc--;

  bubbleSort(argv, argc);

  for(int i = 0; i < argc; i++)
    printf("%s \n", argv[i]);

  return 0;
}
