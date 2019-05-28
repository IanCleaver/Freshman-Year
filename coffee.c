/*
* Author: Ian Cleaver, icleaver2018@my.fit.edu
* Course: CSE 1001, Section 02
Fall 2018
* Project: Coffee
*/

#include <stdio.h>
#include <math.h>
int main (void) {

//Simple Variables

	double coolingconstant = 0.00150;
	double tempk1, tempc1, tempf1;
	double tempk2,tempc2,tempf2;
	double tempk3,tempc3,tempf3;
	double startingtemp1, startingtemp2, startingtemp3;
	int time1, time2, time3;

//input (ask for 3 different integer values for time and starting temperature

	printf("Enter the 1st time (min) and starting temperature (T0, Celsious):");
	scanf("%d %lf",&time1, &startingtemp1);
	printf("Enter the 2nd time (min) and starting temperature (T0, Celsious):");
	scanf("%d %lf",&time2, &startingtemp2);
	printf("Enter the 3rd time (min) and starting temperature (T0, Celsious):");
	scanf("%d %lf",&time3, &startingtemp3);

//Extra space to make it look the same way it looks in the Sample Interaction

printf("\n");

//Variables With Equations

	double surroundingtemp = 20 + 273.15;
	double startingtempk1 = startingtemp1 + 273.15;
	double startingtempk2 = startingtemp2 + 273.15;
	double startingtempk3 = startingtemp3 + 273.15;
	int time_sec1 = time1 * 60;
	int time_sec2 = time2 * 60;
	int time_sec3 = time3 * 60;

//I made e^(-kt) into a variable for my better understanding
	double epow1 = exp(-coolingconstant * time_sec1);
	double epow2 = exp(-coolingconstant * time_sec2);
	double epow3 = exp(-coolingconstant * time_sec3);

//Equation

tempk1 = surroundingtemp + (startingtempk1 - surroundingtemp) * epow1;
tempk2 = surroundingtemp + (startingtempk2 - surroundingtemp) * epow2;
tempk3 = surroundingtemp + (startingtempk3 - surroundingtemp) * epow3;

//Convert from Kelvin to Celcious and Kevin to Farenheit

tempc1 = tempk1 - 273.15;
tempc2 = tempk2 - 273.15;
tempc3 = tempk3 - 273.15;

tempf1 = (tempk1*(9.0/5.0))-459.67;
tempf2 = (tempk2*(9.0/5.0))-459.67;
tempf3 = (tempk3*(9.0/5.0))-459.67;

//Output

printf(" Time (s)      T0 K    T(t) C    T(t) F    T(t) K\n");
printf("%9.0d %9.2lf %9.2lf %9.2lf %9.2lf\n",time_sec1,startingtempk1,tempc1,tempf1,tempk1);
printf("%9.0d %9.2lf %9.2lf %9.2lf %9.2lf\n",time_sec2,startingtempk2,tempc2,tempf2,tempk2);
printf("%9.0d %9.2lf %9.2lf %9.2lf %9.2lf\n",time_sec3,startingtempk3,tempc3,tempf3,tempk3);

return 0;
}