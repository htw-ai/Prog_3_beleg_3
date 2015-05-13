#include <iostream>

using namespace std;

int scmp(const char *s1, const char *s2);
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
  array[index] = array[index2];
  array[index2] = tmp;
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
      if (scmp(array[i-1], array[i]) > 0) {
        swapIndex(array, i, i-1);
        swaped = true;
      }
    }
  } while (swaped);
}

int main(int argc, const char * argv[]) {
  const char* sfeld[] = {
    "eins", "eins1", "eins2", "eins", "zwei", "drei", "vier", "fünf", "sechs", "sieben", "acht", "neun", "zehn"
  };
  int size = 13;

  bubbleSort(sfeld, size);

  for(int i = 0; i < size; i++)
    cout << sfeld[i] << endl;

  return 0;
}

