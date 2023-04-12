#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXTIMES 10

int divisiontest(int divisor1, int quotient1);

int main(void){
	int times, correct, divisor, quotient;
	int correctnumber = 0;
	srand((int) time (NULL));
	// generates random numbers for the divisor and quotient
	for(times = 0; times < MAXTIMES; times++){
		// 12 + 1 makes it so the divisor cannot be zero
		divisor = rand()%12+1;
		quotient = rand()%13;
		correct = divisiontest(divisor, quotient);
		correctnumber += correct;
	}
	printf("You got %d0%% correct.\n",correctnumber);
	return 0;
	
}
// set variables up to figure out the correct answer
int divisiontest(int divisor1, int quotient1){
	int divisor = divisor1;
	int quotient = quotient1;
	int dividend = quotient * divisor;
	int userresult;
	int numbertoreturn;
	printf("What is %d divided by %d?\n", dividend, divisor);
	scanf("%d",&userresult);
	numbertoreturn = ((userresult == quotient) ? 1 : 0);
	// judges if user got the answer wrong or right
	if (userresult == quotient){
		printf("You got it right\n");
	}else{
		printf("Wrong, the correct answer is %d \n", quotient);
	}		
	return numbertoreturn;
}
//1. the number of times the program runs would be inconsistent
//2. it is because the define line does not need a semi colon
//3. we do rand()12+1
//4. no it does not still work
