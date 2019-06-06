#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio4.h>

int main(int argc, char **argv)
{
    
    int ret = 0;
    const int MAXCHARS = 100;
    char wordArray[MAXCHARS];
    
    char userInput[MAXCHARS];
    
    
    FILE* infile;
    
    long startMsec = 0;
    long endMsec = 0;
    float totalTime = 0;
    
    int rightWords = 0;
    int totalWords = 0;   //
    double wpm = 0;   //words per minute
    
    
    infile = fopen("../typingTest.txt","r");
    
    if(infile==NULL) {
        
        printf("This file could not be opened");
        exit(1);
    }
        startMsec = getmSecs();
        
        while(fgets(wordArray,MAXCHARS,infile)) {
            
            printf("%s",wordArray);
            fgets(userInput,MAXCHARS,stdin);
            ret = strcmp(wordArray,userInput);
            
            if(ret == 0) {
                
                rightWords++;
            }
            
            while(ret != 0) {
                printf("Error, please type again\n");
                fgets(userInput,MAXCHARS,stdin);
                ret = strcmp(wordArray,userInput);
                
                
            }
            
            totalWords++;
            
        }
        printf("Test complete\n");
        endMsec = getmSecs();
        totalTime = endMsec - startMsec;  // Time taken in milliseconds
        totalTime /= 1000;  // Time taken in Seconds
        printf("The total time is: %f (secs) \n", totalTime);
        printf("The total right words are: %d\n", rightWords);
        
        totalTime /= 60;     // Time taken in minutes
 
        wpm = totalWords/totalTime;
       
        printf("The total words per minute is: %f\n", wpm);
            
}