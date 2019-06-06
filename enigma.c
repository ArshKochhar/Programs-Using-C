#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Arsh Kochhar 17ak126, 20104779
#define USERCHARS 200
#define ROTORLEN 26
#define NROTORS 3



int rotorZero[ROTORLEN] = {18,7,10,0,17,9,12,11,8,3,16,22,15,2,14,13,6,23,4,19,20,1,5,25,21,24,};
int rotorOne[ROTORLEN] = {4,11,23,20,15,8,7,9,12,24,17,0,1,10,6,22,19,2,16,13,21,14,3,5,18,25,};
int rotorTwo[ROTORLEN] = {2,25,21,19,13,20,24,16,15,7,18,10,3,8,5,17,12,0,4,9,11,14,1,23,6,22,};
int reflector[ROTORLEN] = { 3, 16, 12, 0, 18, 11, 24, 22, 25, 17, 15, 5, 2, 23, 20, 10, 1, 9, 4, 21, 14, 19, 7, 13, 6, 8 };
int backwards (int  lettersValue, int array[], int rpos);// States the new method and its parameters
int forward(int index, int rotor[], int rpos);// States a new method and its parameters
int rotorPosition[ROTORLEN] = {13,21,2};
/* main function:
 * Read a line of input and encrypt each letter to produce a new line of input.
 *    -- For each letter, check if it is a letter, if not ignore
 *    -- convert the the letter number A = 0, B = 1, C = 3, ...
 */
int main(int argc, char** argv)
{

//Declaring variables
	int i;
	int letter, letterNum, rotor0Out, rotor1Out, rotor2Out, reflectorOut, position0,position1,position2;
	char userInput[USERCHARS];
// Print statements
	printf("WELCOME TO ENIGMA\n\n");
	printf("\nEnter Transmission: \t\n\n");

	// Takes sures input and changes it to a numerical value that can be used in the encryption.
// These numbers range from 0-25 and represent all 26 letters of the alphabet
	fgets(userInput,USERCHARS,stdin);
	while (strcmp(userInput,"done\n") != 0) {
		for (i = 0; i < strlen(userInput); i++) {
			letter = userInput[i];

			if(isalpha(letter)) {//checks to see if the value ended is a letter
				if(isupper(letter)) {// checks if the value is upper or lower case
					letterNum = letter - 'A';



				} else {
					letterNum = letter - 'a';


				}
//simulates the encryption portion of the enigma machine.
// Passes the numerical value of the letter, the rotor being used, and the rotors position into the forward method
				rotor0Out = forward(letterNum, rotorZero, rotorPosition[0]);
				rotor1Out = forward(rotor0Out, rotorOne, rotorPosition[1]);
				rotor2Out = forward(rotor1Out, rotorTwo, rotorPosition[2]);
				reflectorOut = reflector[rotor2Out];// passes rotor2Out into the reflector.

//Passes the numerical value , rotor in use, and the position of the rotor being used to the backwards method

				position2 = backwards(reflectorOut, rotorTwo, rotorPosition[2]);
				position1 = backwards(position2, rotorOne, rotorPosition[1]);
				position0 = backwards(position1, rotorZero, rotorPosition[0]);
				rotateRotors(rotorPosition); // Moves the rotors position
				letterNum = position0 +'A';// the letters Numerical value is equal to the last position calculated + the ascii value of A (32)

				printf("%c",letterNum);// Prints the ascii value as its corresponding character


			}


		}
		// opens another time when the user can enter in a new letter or phrase
		printf("\n");
		fgets(userInput,USERCHARS,stdin);

	}

	return 0;// returns 0 to the int main
}
int backwards (int  lettersValue, int array[], int rpos)// The new method backwards
{
	for( int j = 0; j < ROTORLEN; j++) {// For loop used to go through the array and search for the previous value given under the parameter of lettersValue
		if (lettersValue == array[j]) {

			return (j + ROTORLEN - rpos)% ROTORLEN; // finds the true j value based on the changing position of the rotor
		}

	}

}
int forward (int index, int rotor[], int rpos) // States the new method called forward
{
	int newIndex = (index + rpos)%ROTORLEN;//  finds the true index based on the changing value of the rotors position
	return rotor[newIndex];
}
void rotateRotors(int pos[])// Moves the rotors position after each new character is produced
{

	pos[0]++;// moves the first rotor one space forward after each character
	if (pos[0] == ROTORLEN) {// if the first rotor is equal to 26 it resets the position of rotor 0 and moves rotor 1 by one
		pos[0] = 0;
		pos[1]++;

	}
	if (pos[1] == ROTORLEN) {//if the second rotor is equal to 26 it rests the position of the rotor 1 and moves rotor 2 by one
		pos[1] = 0;
		pos[2]++;
	}
	if (pos[2] == ROTORLEN) {//if the third rotor is equal to 26 it rests the position of the rotor 2 and moves rotor 3 by one
		pos[2] = 0;
	}


}
