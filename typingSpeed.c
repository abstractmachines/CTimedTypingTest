/*
***** ***** The Typing Timed Test ***** *****
Amanda Falke 2014
c / linux / gdb 

Quick brown fox jumpin' over lazy dogs standard stuff

using time.h structs + functionality.


SCOPE OF THE GAME :
Time the user on how long it takes user to *correctly* type in 9 words, which 
are randomly given to user.

RULES :
#1: The user has an infinite amount of time to type in each word correctly.
#2: The 9 words appear at random (all permutations are possible).
#3: Each word appears only once.
#4: The user has an infinite number of attempts to type in each word correctly. 
#5: Case sensitive.
#6: Tell the user how long the game took them.
#7: Tell the user if they're wrong.
#8: Typescript the Terminal session.

Final note: I'm a Mr T fan, as you will see in the user interaction flow.
-Amanda
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define MAX 100


//struct timeval beginAGame(struct &beginGame);


int main(int argc, char * argv[])
{

// ************************* VARIABLES _________________________

 int idx; // iterate 9 times for 9 words
 int randArray = 0; // integer to seed randArray 9 times - once for each word
 int modCount = 9;  // decrementing modulus ensures each word used only once
 char  userInput[MAX]; // get userInput of characters
 int correctWord = 0; // error check for correct word
// all above, inside for loop.


// ******* THE USER INPUT:
 char * timedTyping = malloc (MAX*sizeof(char));
 if (timedTyping == NULL)
 {
  printf("\n No Memory! \n");
  return 1;
 }


// ************* THE ARRAY: 9 words

 char * typeTest[9];
 
 for (idx = 0; idx < 9; ++idx )
 {
  typeTest[idx] = malloc(10*sizeof(char));
  // max size 10 for each word 10x4 = 40
 }

// copy values in. 
// This array will later be changed with the modulus operator,
// the modulus operator will replace array elements to ensure appearing once.
 strcpy(typeTest[0],"The");
 strcpy(typeTest[1],"quick");
 strcpy(typeTest[2],"brown");
 strcpy(typeTest[3],"fox");
 strcpy(typeTest[4],"jumps");
 strcpy(typeTest[5],"over");
 strcpy(typeTest[6],"the");
 strcpy(typeTest[7],"lazy");
 strcpy(typeTest[8],"dog");



// Word Selection Algorithm: random seed using clock.

 struct timeval timeSeed;
 gettimeofday(&timeSeed, NULL);

 srand(timeSeed.tv_usec );
// seed srand() using usec (microseconds) field from call to gettimeofday



// TIME THE USER Algorithm:
 struct timeval beginGame;
 struct timeval endGame;
 struct timeval computeTime; // timeSub() subtracts the difference.
 


// END VARIABLE/CONSTRUCT DECLARATION SECTION




// ****************** BEGIN GAME HERE ______________________________

 char intro[] = "Pity the fool who can't type quickly! Let's begin. \n\n"; 
 
 printf("%s\n", intro);

 printf("Type the following words, sucka! \n\n");

  


 
 for (idx = 0; idx < 9; ++idx )
 {

//    --modCount; 

   randArray = rand()%(modCount);
//  randArray = rand()%1;


  if ( idx == 0 )
  {
   gettimeofday(&beginGame, NULL);
  }

  do
  {
     printf("word %d is %s\n", idx+1, typeTest[randArray]); 

     scanf("%s", userInput);


     if ( (strcmp(userInput,typeTest[randArray])) == 0)
       {
         printf("Well done! You can pity the fool, instead of being the fool.\n");
        

        --modCount;

         strcpy(typeTest[randArray],  typeTest[modCount]); 
         //--modCount; 


         correctWord = 1;
       }

      else
       {
         printf("Pain!! You messed up that word. Try again! \n");
         correctWord = 0;
       }

  
   } while ( correctWord == 0 ) ;
 

   if ( idx == 8 )
   {
      printf("Game over! You have been TIMED! \n");

      gettimeofday(&endGame, NULL);
   }

 }// for



// ***************************** END GAME _____________ 



// subtract the difference between starting and ending times:
 timersub(&beginGame, &endGame, &computeTime);

 printf("You took this long\n %li microseconds \n", computeTime.tv_usec);


// ************** end program __________________________
 return 0;

};

