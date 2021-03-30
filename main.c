#include <stdio.h>

//exercise 1-1
/*
int main(void) {
  printf("Hello World\n");
  return 0;
}
*/

//exercise 1-3
/*
int main(void) {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  
  fahr = lower;
  printf("farenheit celsius\n");
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %12.2f\n", fahr, celsius);
    fahr = fahr + step;
  }
  
  return 0;
}
*/

//exercise 1-4
/*
int main(void) {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  
  celsius = lower;
  printf("farenheit celsius\n");
  while (fahr <= upper) {
    //celsius = (5.0/9.0) * (fahr-32.0);
    fahr = celsius * (9.0/5.0) + 32;
    printf("%3.0f %12.2f\n", celsius, fahr);
    celsius = celsius + step;
  }
  
  return 0;
}
*/

//exercise 1-5
/*
int main(void) {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  
  printf("farenheit celsius");
  for (fahr = upper; fahr >= lower; fahr = fahr - 20) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f %12.2f\n", fahr, celsius);
  }
  
  return 0;
}
*/

//exercise 1-6
/*
int main(void) {
  // int c;

  // c = getchar();
  // while (c != EOF) {
  //   putchar(c);
  //   printf(" %i\n",c);
  //   c = getchar();
  // }
  
  int c;  
  
  c = getchar() != EOF;
  printf("%d", c);

  return 0;
}

*/

// exercise 1-7
/*
int main(void){
  printf("%d\n", EOF);
  return 0;
}
*/

//exercise 1-8
/*
int main() {
  int c, nl;
  nl = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t')
      ++nl;
    if (c == ' ')
      ++nl;
    if (c == '\n')
      ++nl;
  }
  printf("\n%d\n", nl);
  return 0;
}
*/

//exercise 1-9
//write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.
/*
int main() 
{
  int c, blanks;
  blanks = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == ' ')
    {
      if (blanks == 0) 
      {
        putchar(c);
        blanks = 1;
      }
    }
    else
    {
      putchar(c);
      blanks = 0;
    }
  }
  return 0;
}
*/

//exercise 1-10
//Write a program to copy its input to its output, replacing each tab by \t, each
//backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
//unambiguous way

/*
int main() 
{
  int c, blanks;
  blanks = 0;
  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
      printf("\\t");
    else if (c == '\b')
      printf("\\b");
    else if (c == '\\')
      printf("\\\\");
    else 
      putchar(c);
  }
  return 0;
}
*/

//exercise 1-11
// How would you test the word count program? What kinds of input are most
// likely to uncover bugs if there are any?

/*
#define IN 1
#define OUT 0

int main()
{
  int c, nl, nw, nc, state;
  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF) 
  {
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("\nlines: %d  words: %d characters: %d\n", nl, nw, nc);
  return 0;
}
*/

//answer this program states that a word is anything without whitespace
//I don't really see what is wrong with that though


//1-12
//Write a program that prints its input one word per line

/*

int main()
{
  int c, blanks, start;
  blanks = start = 0;
  while ((c = getchar()) != EOF) 
  { 
    printf("c: %d, blanks:%d start:%d\n", c, blanks, start);
    if (start == 0)
    {
      printf("\n");
      start = 1;
    }
    if (c == ' ' || c == '\n' || c == '\t')
    {
      if (blanks == 0) 
      {
        printf("\n");
        blanks = 1;
      }
    }
    else
    {
      putchar(c);
      blanks = 0;
    }
      
  }
  return 0;
}
*/

//1-13
//Write a program to print a histogram of the lengths of words in its input. It is
//easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging

//vertical is character count, an array
//horizontal how much each array thingy is


/* an example with */
// int main()
// {
//   int c, i, nwhite, nother;
//   int ndigit[10];
//   nwhite = nother = 0;
//   for (i = 0; i < 10; ++i)
//     ndigit[i] = 0;
//   while ((c = getchar()) != EOF)
//   if (c >= '0' && c <= '9')
//     ++ndigit[c-'0'];
//   else if (c == ' ' || c == '\n' || c == '\t')
//     ++nwhite;
//   else
//     ++nother;
//   printf("digits =");
//   for (i = 0; i < 10; ++i)
//     printf(" %d", ndigit[i]);
//   printf(", white space = %d, other = %d\n", nwhite, nother);
//   return 0;
// }

/*
#define IN 1
#define OUT 0

int main() 
{
  int c, characterCount, i, len, state;
  state = OUT;
  characterCount = 0;
  len = 100;
  int wordLengths[100];
  for (i = 0; i < len; i++)
    wordLengths[i] = 0;
  
  while ((c = getchar()) != EOF) 
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
      characterCount = 0;
    }
    else if (state == OUT)
    {
      state = IN;
      characterCount = 1;
      wordLengths[characterCount]++;
    }
    else if (state == IN)
    {
      wordLengths[characterCount]--;
      characterCount++;
      wordLengths[characterCount]++;
    }
      
  }
  //show histogram
  printf("\nthis is a histogram lol \n");
  for (i = 0; i < len; i++)
  {
    if (wordLengths[i] > 0){
      printf("%d ", i);
      for (int j = 0; j < wordLengths[i]; j++)
        printf("#");
      printf("\n");
    }
  }

  return 0;
}
*/




//1-14
//Write a program to print a histogram of the frequencies of different characters
// in its input.

/*

int main()
{
  int c, i;
  int characterFrequency[128];
  for (i = 0; i < 128; i++)
    characterFrequency[i] = 0;
  while ((c = getchar()) != EOF) 
    characterFrequency[c]++;
  for (i = 0; i < 128;  i++)
  {
    if (characterFrequency[i] > 0)
    {
      printf("\n");
      putchar(i);
      for (int j = 0; j < characterFrequency[i]; j++)
        printf(" -");
    }
  }
  return 0;
}

*/


//1-15

// Rewrite the temperature conversion program of Section 1.2 to use a function
// for conversion.

int tempConversionTable()
{
  int fahr, celsius, lower, upper, step;
  lower = 0; /* lower limit of temperature scale */
  upper = 300; /* upper limit */
  step = 20; /* step size */
  fahr = lower;
  while (fahr <= upper) {
    celsius = 5 * (fahr-32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }
  return celsius;
}

int main()
{
  tempConversionTable();
  return 0;
}