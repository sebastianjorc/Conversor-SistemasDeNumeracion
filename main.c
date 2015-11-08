#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int longitud(char *cadena) { 

	int valor = 0; 
	for(int i=0; cadena[i]!='\0'; i++)	valor++; 
	return valor; 
} 

char *convertir_a_string(int val, int base){
	static char buf[32] = {0};
	int i = 30;
	for(; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return &buf[i+1];
}

int convertir_entero(char *cadena) { 

	int potencias[5]={1,10,100,1000,10000}; 
	int valor = 0; 
	int lon = longitud(cadena); 

	for(int i=lon-1; i>=0; i--)	
		valor += (cadena[i]-'0') * potencias[(lon-i-1)]; 
	return valor; 
}

int solo_enteros(char *x, int max){
	int valor, tam=longitud(x);
	for(int i=tam-1; i>=0; i--)	{
		valor = (x[i]-'0');
		if ( valor<0 || valor>max ){
		 	printf("Error al ingresar el valor.\n");
			return 0;
		}
	}
	return 1; 
}

int renstriccion_hexadecimal(char *x){
	int valor, flag, tam=longitud(x);
	char letras[13]="ABCDEFabcdef";
	
	for(int i=tam-1; i>=0; i--)	{
		
		flag=1;
		for (int j=0; j<12; j++){
			if (x[i]==letras[j]){
				printf("\n%c\n",letras[j]);getchar();
				flag=0; break;
			}
		}
		
		if (flag==1){	
			valor = (x[i]-'0');			
			if ( (valor<0 || valor>9) ){
				printf("Error al ingresar el valor.\n");
				return 0;
			}
		}
	}
	return 1; 
}

int renstricciones(int op, char *x){

	switch (op){
		case 1:
			return solo_enteros(x,1);
		case 2:
			return solo_enteros(x,7);
		case 3:
			return solo_enteros(x,9);
		case 4:
			return renstriccion_hexadecimal(x);
	}
	return 0;
}

void tipos (){

	printf("1. Binario\n");
	printf("2. Octal\n");
	printf("3. Decimal\n");
	printf("4. Hexadecimal\n");
}

void tipos_renstricciones (int op){
	
	switch (op){
		case 1: 
			printf ("Los valores binario solo poseen digitos 0 y 1\n"); 	
			printf ("Ingrese su valor Binario : ");	break;
		case 2: 
			printf ("Los valores octales se leen de 0 hasta 7\n"); 
			printf ("Ingrese su valor Octal: ");	break;
		case 3: 
			printf ("Los valores decimales se leen de 0 hasta 9\n"); 	
			printf ("Ingrese su valor Decimal: ");	break;
		case 4: 
			printf ("Los valores Hexadecimal de leen de 0 hasta 9 siendo:\n A=10, B=11, C=12, D=13, E=14, F=15\n"); 
			printf ("Ingrese su valor Hexadecimal: ");	break;
	}
}

char* ingresado (int op){
	int flag=0;
	char* x;
	while (flag==0){
				
		tipos_renstricciones(op);
		scanf("%s",x);getchar();		
		if (renstricciones(op,x))
			flag=1;
	}	
	return x;		
}

char* transformar_a_decimal(int op_entrada, char *x){
	
	int base;
	int valor=0;
	switch (op_entrada){
		case 1: base=2;	break;
		case 2: base=8;	break;
		case 4: base=16;break;
	}		
	
	if (op_entrada!=4){
		
		int tam=longitud(x);
		int a=base;
		int b;
		for (int p=0; p<tam-2; p++)	a=a*base;
		
		for (int i=0; i<tam; i++){
			b=(x[i]-'0');
			valor=valor+(b*a);	
			a=a/base;		
		}						
	}
	char *salida=convertir_a_string(valor,10);	
	return salida;	
}

char* desde_decimal(char* x, int op_salida){
	
	int base;
	switch (op_salida){
		case 1: base=2;	break;
		case 2: base=8;	break;
		case 3: base=10;break;
		case 4: base=16;break;
	}					
	int valor=convertir_entero(x);	
	int restos[20];
	int flag=1;
	int i=-1;
	
	while(flag){
			i++;						
		restos[i]=valor%base;
		valor=valor/base;
		if (valor<base){
			i++;						
			restos[i]=valor;
			flag=0;
		}
	}
	long long a=10;
	for (int p=0; p<i-1; p++)	a=a*10;
	
	valor=0;		
	while (i>=0){
		
		valor=valor + (a*restos[i]);
		a=a/10;
		i--;
	}
	printf("x = %i base %i\n",valor,base);getchar();
	char *salida=convertir_a_string(valor,10);
	
	return salida; 
		
}

char* convertido (int opcion_entrada, int opcion_salida, char* ingresado){

	if (opcion_entrada==3){
		return desde_decimal(ingresado,opcion_salida);
		
	}
	else{ getchar();
		return desde_decimal(transformar_a_decimal(opcion_entrada,ingresado),opcion_salida);
	}
}

void menu (){

	int opcion_entrada,opcion_salida,op,flag=1;
	char* x;
	char* y;

	while (flag){

		printf("Escoga el tipo de valor a convertir: \n");
		tipos();
		scanf("%i",&op);getchar();

		while (op!=1 && op!=2 && op!=3 && op!=4){
			
			printf("\nLa opción no es valida, intende nuevamente\n");
			tipos();
			scanf("%i",&op);getchar();
		}

		opcion_entrada=op;
		x=ingresado(opcion_entrada);

		printf("Escoga el tipo de valor al cual quiere transformar: \n");
		tipos();
		scanf("%i",&op);getchar();

		while ( (op!=1 && op!=2 && op!=3 && op!=4) || (op==opcion_entrada) ){

			if (op==opcion_entrada) 
				printf("\nEl dato ya está en esta opción, escoga una opción correcta:\n");
			else 
				printf("\nLa opción no es valida, intende nuevamente:\n");
			tipos();
			scanf("%i",&op);getchar();
		}

		opcion_salida=op;
		y=convertido(opcion_entrada, opcion_salida, x);
		flag=0;
		printf("%s",y);	getchar();
	}

}

int main(){
	printf("Bienvenido a mi programa para conversor de tipos de numero.\n");
	menu();
	return 0;
}
