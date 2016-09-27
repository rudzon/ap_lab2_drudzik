#include <curses.h>
#include <stdio.h>
#include <math.h> // sqrt
#include <stdlib.h> // Я отсюда юзаю exit()

void error(char* errorMsg) {
	printf("\n %s \n ", errorMsg);
	exit(0);
}

void showCalculations(float side_A, float side_B, float side_C) //Подсчёты
{
    float   per, halfper;//Периметр и полпериметр
    double  S;//Площадь
    double  ht_to_A, ht_to_B, ht_to_C;//Высоты
    float   medi_to_A, medi_to_B, medi_to_C;//Медианы
    double  bisectr_to_A, bisectr_to_B, bisectr_to_C; //Бисектрисы

	per = side_A+side_B+side_C; //Периметр
	printf("\n Perimeter: %f", per); //%f Юзает значения которые за скобочками (полезно)

	halfper = per/2; //Половина периметра
	printf("\n Half Perimeter: %f", halfper);

	S = (sqrt(halfper*(halfper-side_A)*(halfper-side_B)*(halfper-side_C))); //Должна быть площадь
	printf("\n Area: %f \n", S);

	//Heights
	ht_to_A = ((S*2)/side_A); //Высота к А
	printf("\n Height to side A: %f", ht_to_A);
	ht_to_B = ((S*2)/side_B); // H to B
	printf("\n Height to side B: %f", ht_to_B);
	ht_to_C = ((S*2)/side_C); // H to C
	printf("\n Height to side C: %f\n", ht_to_C);

	//Medians
	medi_to_A = (sqrt((2*(side_B*side_B))+(2*(side_C*side_C))-(side_A*side_A))*0.5);//Медиана к А
	printf("\n Median to side A: %f", medi_to_A);
	medi_to_B = (sqrt((2*(side_A*side_A))+(2*(side_C*side_C))-(side_B*side_B))*0.5);
	printf("\n Median to side B: %f", medi_to_B);
	medi_to_C = (sqrt((2*(side_A*side_A))+(2*(side_B*side_B))-(side_C*side_C))*0.5);
	printf("\n Median to side C: %f\n", medi_to_C);

	//Bisectors
	bisectr_to_A = (((sqrt((side_B*side_C*halfper)*(halfper-side_A)))*2)/(side_B+side_C));//Бисектриса к А
	printf("\n Bisectr to side A: %f", bisectr_to_A);
	bisectr_to_B = (((sqrt((side_A*side_C*halfper)*(halfper-side_B)))*2)/(side_A+side_C));
	printf("\n Bisectr to side B: %f", bisectr_to_B);
	bisectr_to_C = (((sqrt((side_A*side_B*halfper)*(halfper-side_C)))*2)/(side_A+side_B));
	printf("\n Bisectr to side C: %f\n", bisectr_to_C);
}

float prompt(char* str) {
    float res;

    printf("\n %s", str);
    scanf("%f", &res);

    if (res < 0) {
        error("Wrong format");
    }

    if (res == 0) {
        error("Wrong format");
    }

    return res;
}

int main(void) {
    float side_A = prompt("Enter any positive number for your side A:");
    float side_B = prompt("Enter any positive number for your side B:");
    float side_C = prompt("Enter any positive number for your side C:");

    printf("\n Triangle A: %f B: %f C: %f \n", side_A, side_B, side_C);

    if(!((side_A+side_B) > side_C && (side_A+side_C) > side_B && (side_B+side_C) > side_A)) {
		error("That triangle does not exist!");
	}

    showCalculations(side_A, side_B, side_C);
}
