#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h> // strcmp

// funkciju enumeracija
enum func_list {
	SIN,
	COS,	
	TAN,
	SQRT,
	POW,
	FLOOR,
	CEIL,
	COUNT // bendras skaicius 
};

// laipsniai i radianus
double to_radians(double a){
	const double PI = 3.14159265359;
	double angl_in_radians = a * PI/180;	
	return angl_in_radians; 
}

// sin funkcija
double sinus_f(double a){			
	double sinus = sin(to_radians(a));
	return sinus; 
}

// cos funkcija
double cosinus_f(double a){
	double cosinus = cos(to_radians(a));
	return cosinus; 
}

// tan funkcija
double tangent_f(double a){
	double tangent = tan(to_radians(a));
	return tangent; 
}

// saknis funkcija
double square_f(double a){
	double square = sqrt(a);
	return square; 
}

// kelimo laipsniu funkcija
double pow_f(double a, double b){
	double power = pow(a, b);
	return power; 
}

// apval i maz puse
double floor_f(double a){
	double flo = floor(a);
	return flo; 
}
// apval i did puse
double ceil_f(double a){
	double cei = ceil(a);
	return cei; 
}

void help (){
	printf("Program calculate %d following functions: sin, cos, tan, sqrt, pow, floor, ceil.\n", COUNT);
	printf("For all programs except pow, ceil and floor enter 3 args sepparated by space: name of command, value and precision(1-9, decimals after point)\n");
	printf("EXAMPLE: sin 60 .2\n");
	printf("For pow enter 4 args sepparated by space: name of command, value to power, power number and precision(1-9, decimals after point)\n");
	printf("EXAMPLE: pow 2 3 .2\n");
	printf("For ceil and floor only two arguments(name of command and value)\n");	
}


int main(int argc, char *argv[]){
	
	// Naudojimosi instrukcija/help kvietimas
	if (strcmp(argv[1], "/help") == 0){
		help ();	
	}
	
		
	// parametras (skaiciai po tasko) po kablelio su tasku vedamas
	float num_transfer = atof(argv[3])*10; 
	int num = (int) num_transfer;
	
	
	enum func_list selection; 
	char *fun[] = {"sin", "cos", "tan", "sqrt", "pow", "floor", "ceil"}; // massyvas lyginimui
	
	// palyginam argv su esamom reiksmem kad issirinkti reikiama funkcija.
	for (int i = SIN; i <= CEIL; i++) {
			if (strcmp(argv[1], fun[i]) == 0){
				selection = i;
			}
	}
	
	// pasirenkam reikiama skaiciavimo funkcija	per switch su enumerate 	
	switch(selection) {
		
		// sinusas
		case SIN:; 
			float my_val_1 = atof(argv[2]);
			double rez1 = sinus_f(my_val_1);	
			if (num > 0)
				printf("%.*f", num, rez1);
			else 
				printf("%f", rez1);
			break;
		
		// cosinusas
		case COS:;
			float my_val_2 = atof(argv[2]);
			double rez2 = cosinus_f(my_val_2);
			if (num > 0)
				printf("%.*f", num, rez2);
			else 
				printf("%f", rez2);
			break;
		
		// tangentas
		case TAN:;
			float my_val_3 = atof(argv[2]);
			double rez3 = tangent_f(my_val_3);
			if (num > 0)
				printf("%.*f", num, rez3);
			else 
				printf("%f", rez3);
			break;
			
		// saknis
		case SQRT:;
			float my_val_4 = atof(argv[2]);
			double rez4 = square_f(my_val_4);
			if (num > 0)
				printf("%.*f", num, rez4);
			else 
				printf("%f", rez4);
			break;
			
		// skaiciaus kelimas laipsniu 
		case POW:;
			float my_val_51 = atof(argv[2]);
			float my_val_52 = atof(argv[3]);
			float num2 = atof(argv[4])*10; // pow funkcijai vedami 4 argumentai todėl čia reikia kito 4 argv
			int num = (int) num2;
			double rez5 = pow_f(my_val_51, my_val_52);
			if (num > 0)
				printf("%.*f", num, rez5);
			else 
				printf("%f", rez5);
			break;
	
		// apval i maz puse
		case FLOOR:;
			float my_val_6 = atof(argv[2]);
			double rez6 = floor_f(my_val_6);
			printf("%.0f", rez6);
			break;
			
		// apval i did puse
		case CEIL:;
			float my_val_7 = atof(argv[2]);
			double rez7 = ceil_f(my_val_7);
			printf("%.0f", rez7);
			break;
		
		default:
			// Jei blogai iveda argumenta.
			printf("'%s' is not valid argument check /help", argv[1] );
			break;
		
	}

	return 0;
}



