#include <stdio.h>
#include <stdlib.h>

int found (char list[], int num, char ch);

int main () {
 char backwards[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','M','N','L','K','J','I','H','G','F','E','D','C','B','A'};
 char key[20] =  {};
 char alp[26] = {};
 char ch = ' ';
 int i, j, x,  size = 0;    
 int y = 0;
 int b = 0;

 // read the key from the keyboard into array key (length of the key is less than 20)
 printf ("Enter key (max 20 characters):\n");    
 while (ch=getchar(), size<20 && ch!='\n'){
 key[size++] = ch;
 x++;
 }


 // write code below to store the key in array alp after removing duplicate letters
 for (i=0; i < x; i++)
    if( (found(key, x, key[i]) == 1) && found(alp, x, key[i]) == 0 ){
        alp[b++] = key[i];
        
    }

 // write code below to fill up the rest of array alp with other characters of the
 // alphabet in reverse order

  for (i=0; i < 26; i++)
    if(alp[i] == 0){
        alp[i] = backwards[y];
        y++;
    }   
 // print characters in array alp
 for (i=0; i < 26; i++)
 printf("%c", alp[i]);
 printf("\n");

 return 0;
}

// search the first num characters in array list for character ch
// return true if it is found; false, otherwise
int found(char list[], int num, char ch) {
 int i;
 for (i=0; i<num; i++)
 if (list[i] == ch)
 return 1;
 return 0;
} 
