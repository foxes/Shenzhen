#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>



char c;
int lines;
double words;
double characters;
double average;
bool notblank = false;

char prev = '\n';

int
main()
{

        printf ("Enter text (Ctrl-D to quit).\n");    
        while ((c = getchar()) != EOF) {
         if (c == '\n') {
             lines++;
             
        }
         if (!isspace(c) && !notblank) {
             
             notblank = true;
             words++;
                
        }
          if (isspace(c) && notblank) {
                
              notblank = false;
              prev = c;
              characters--;
                
        }
    
        characters++;
        
    }
    
    average = characters / words;
    printf("\n");
    printf("words:%.0f \n",words);
    //printf("Lines:%d \n",lines);
    printf("Characters:%.0f \n",characters);
    printf("Average:%.2f \n",average);
    
}
