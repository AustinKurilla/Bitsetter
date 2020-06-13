
/*Austin Kurilla
 * 3-4-20
 * Lab 5
 * This program prefroms bit operations on a custom bitset to set and clear bits
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef unsigned short bitSet;

//creates a new bitset initalized to all zeros
bitSet makeBitSet(){
	return 0;
}

//Sets bit 'index' of the bitset to 1
void setBit(bitSet* bs, int index){
	*bs = ((*bs)|(1 << index));
}

//Sets bit 'index' of the bitset to 0
void clearBit(bitSet* bs, int index){
	*bs = ((*bs) & (~(1 << index)));
}

//Returns the value of the bit at 'index' (1 or 0)
unsigned bitValue(bitSet bs, unsigned index){
	if((bs >> index)&1){
		return 1;
	}
	else{
		return 0;
	}
}

//Creates a dynamically-allocated string representation of the bitset in the form "11001010100"
char *toCString(bitSet bs){
	char *bit = (char*) malloc (17);
	int i;
	for(i =0; i < 16;){
		if(bitValue(bs,15-i)==1){
			bit[i]='1';
			i++;
		}
		else{
			bit[i]='0';
			i++;
		}
	}
	bit[i] = '\0';
	return bit;
}

//Displays the 16 bits of the bitset to the screen in the form "1100110010101"
void displayBitSet(bitSet bs){
	char *bitset = toCString(bs);
	printf("The current bitset is : %s\n", bitset);
	free(bitset);
	}

//This method takes in a char array representing a binary number and converts it into an integer
int binToDec(bitSet bin){
	int dec =0,i=0,rem;
	while(bin != 0){
		rem = bin % 10;
		bin /= 10;
		dec += rem * pow(2,i);
		i++;
	}
	return dec;
}

int main(){
	int xexit = 0;
	int input;
	char stringinput[100];
	bitSet set;
	int decimalnum;

	printf("Bitsetter - Created by Austin Kurilla - \n To begin enter a number\n");
	scanf("%hu",&set);
	while(xexit == 0){
		printf("\n\n");
		displayBitSet(set);
		decimalnum = binToDec(set);
		printf("Equals - %d",decimalnum);
		printf("\n To set a new bit enter 'set' \n To clear a bit enter 'clear' \n To input a new bitset enter 'change' \n Enter 'exit' to exit \n");
		scanf("%s",stringinput);
		if(strcmp(stringinput,"set") == 0){
			input = -1;
			while(input < 0 || input > 16){
			printf("Enter a bitnumber (0-15) to set\n");
			scanf("%d",&input);
		}
			setBit(&set,input);
		}
		else if(strcmp(stringinput,"clear") == 0){
			input = -1;
			while(input < 0 || input > 16){
			printf("Enter a bitnumber (0-15) to clear\n");
			scanf("%d",&input);
			}
			clearBit(&set,input);
		}
		else if(strcmp(stringinput,"change") == 0){
			printf("Enter a new number for a base bitset \n");
			scanf("%hu",&set);

		}
		else if(strcmp(stringinput,"exit") ==0){
			printf("Goodbye!\n\n");
			exit(0);
		}
		else{
			printf("Invalid Entry \n");
		}

}
}
