/* CS261- Assignment 1 - Program6*/
/* Name: Austin Dubina
 * Date: 6/30/2012
 * Solution description:
    -performs sticky caps on a single word of 256 chars provided by user
    -functions only performs sticky caps on ascii letters a-z or A-Z.
*/

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
    /*Convert to sticky caps*/
    int i;
    for(i = 0; word[i] != '\0'; i++){
        if(word[i] >= 'a' && word[i] <= 'z'){
            word[i] = toUpperCase(word[i]);
        }
    }
    for(i = 1; word[i] != '\0'; i = i + 2){
        word[i] = toLowerCase(word[i]);
    }
}

int main(){
    /*Input a word*/
    char string[256];
	printf("Please enter a single word only using characters a - z: ");    
scanf("%s",string);
    /*Call sticky*/
    sticky(string);
    /*Print the new word*/
    printf("%s \n",string);
    return 0;
}
