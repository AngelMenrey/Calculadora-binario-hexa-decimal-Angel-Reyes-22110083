//ANGEL EMANUEL MENDOZA REYES
//22110083
//LUIS MANUEL MORALES MEDINA
//PROGRAMACION ORIENTADA A OBJETOS
//PARCIAL 2
//CETI COLOMOS
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Calculator{
private:
	int opc;
	int *decimal;
	char *bin, *hex;
	int menu=1;
	
//decimal a binario y hexadecimal
public:
char* Decimal_a_Binario (int *decimal){
int i=0 ,*paso,*dec_aux;
char *bin,*aux;
paso = (int *) malloc (sizeof(int));
dec_aux = (int *) malloc (sizeof(int));
bin = (char *) malloc (sizeof(char)*32);
aux = (char *) malloc (sizeof(char)*3);
*paso = 0;
*dec_aux = *decimal;
strcpy (aux,"\0");
strcpy (bin,"\0");
while (true)
 {
  *paso=*decimal/2;
  itoa (*decimal%2,aux,10);
  *(aux+1) = '\0';
  *decimal=*paso;
  *(bin+i) = *(aux+0);
      *(aux+0) = '\0';
  i++;
   if (*paso == 0)
    break;
 }
 *decimal = *dec_aux;
 *(bin+i)='\0';
 strrev (bin);
 return bin;
 free (paso);
 free (dec_aux);
 free (bin);
 free (aux);
}
char* Decimal_a_Hexadecimal (int *decimal){
	int i=0 ,*paso,*dec_aux;
 char *hex,*aux;
 paso = (int *) malloc (sizeof(int));
 dec_aux = (int *) malloc (sizeof(int));
 hex = (char *) malloc (sizeof(char)*12);
 aux = (char *) malloc (sizeof(char)*3);
 *paso = 0;
 *dec_aux = *decimal;
 strcpy (aux,"\0");
 strcpy (hex,"\0");
 while (true)
 {
  *paso=*decimal/16;
  if (*decimal%16 < 10)
   itoa (*decimal%16,aux,10);
  else
  {
   switch (*decimal%16)
   {
    case 10:
     *(aux+0) = 'A';
     break;
    case 11:
     *(aux+0) = 'B';
     break;
    case 12:
     *(aux+0) = 'C';
     break;
    case 13:
     *(aux+0) = 'D';
     break;
    case 14:
     *(aux+0) = 'E';
     break;
    case 15:
     *(aux+0) = 'F';
     break;
   }
  }
  *(aux+1) = '\0';
  *decimal=*paso;
  *(hex+i) = *(aux+0);
  *(aux+0) = '\0';
  i++;
  if (*paso == 0)
   break;
 }
 *decimal = *dec_aux;
 *(hex+i)='\0';
 strrev (hex);
 return hex;
 free (paso);
 free (dec_aux);
 free (hex);
 free (aux);
}

//binario a hexadecimal y decimal
char*Binario_a_Hexadecimal (char *bin){
		int i=0;
 char *hex,*aux;
 hex = (char *) malloc (sizeof(char)*12);
 aux = (char *) malloc (sizeof(char)*5);
 strcpy (hex, "\0");
 strcpy (aux, "\0");
 i = strlen (bin) - 1;
 while (i >= 0)
 {
  *(aux+0) = *(bin+(i-3));
  *(aux+1) = *(bin+(i-2));
  *(aux+2) = *(bin+(i-1));
  *(aux+3) = *(bin+i);
  *(aux+4) = '\0';
  for (int j = 0 ; j < 4 ; j++)
   if (*(aux+j) != '0' && *(aux+j) != '1')
    *(aux+j) = '0';
  if (strcmp (aux,"0000") == 0)
   strcat (hex ,"0");
  else if (strcmp (aux,"0001") == 0)
   strcat (hex ,"1");
  else if (strcmp (aux,"0010") == 0)
   strcat (hex ,"2");
  else if (strcmp (aux,"0011") == 0)
   strcat (hex ,"3");
  else if (strcmp (aux,"0100") == 0)
   strcat (hex ,"4");
  else if (strcmp (aux,"0101") == 0)
   strcat (hex ,"5");
  else if (strcmp (aux,"0110") == 0)
   strcat (hex ,"6");
  else if (strcmp (aux,"0111") == 0)
   strcat (hex ,"7");
  else if (strcmp (aux,"1000") == 0)
   strcat (hex ,"8");
  else if (strcmp (aux,"1001") == 0)
   strcat (hex ,"9");
  else if (strcmp (aux,"1010") == 0)
   strcat (hex ,"A");
  else if (strcmp (aux,"1011") == 0)
   strcat (hex ,"B");
  else if (strcmp (aux,"1100") == 0)
   strcat (hex ,"C");
  else if (strcmp (aux,"1101") == 0)
   strcat (hex ,"D");
  else if (strcmp (aux,"1110") == 0)
   strcat (hex ,"E");
  else if (strcmp (aux,"1111") == 0)
   strcat (hex ,"F");
  i -= 4;
  *(aux+0) = '\0';
 }
 strrev (hex);
 return hex;
 free (hex);
 free (aux);
}
 int Binario_a_Decimal (char *bin){
 int *decimal;
 char *bin_aux,*aux;
 decimal = (int *) malloc (sizeof(int));
 bin_aux = (char *) malloc (sizeof(char)*32);
 aux = (char *) malloc (sizeof(char)*2);
 *decimal = 0;
 strcpy (bin_aux,"\0");
 strcpy (aux,"\0");
 strcpy (bin_aux,bin);
 strrev (bin_aux);
 for (int i = 0 ; i < strlen (bin_aux) ; i++)
 {
  *(aux+0) = *(bin_aux+i);
  *(aux+1) = '\0';
  *decimal += (pow (2.0,i) * atoi(aux));
 }
 return *decimal;
 free (decimal);
 free (bin_aux);
 free (aux);
 }
 
 //hexadecimal a decimal y binario
 int Hexadecimal_a_Decimal (char *hex){
 int *decimal;
 char *hex_aux,*aux;
 decimal = (int *) malloc (sizeof(int));
 hex_aux = (char *) malloc (sizeof(char)*12);
 aux = (char *) malloc (sizeof(char)*2);
 *decimal = 0;
 strcpy (hex_aux,"\0");
 strcpy (aux,"\0");
 strupr (hex);
 strcpy (hex_aux,hex);
 strrev (hex_aux);
 for (int i = 0 ; i < strlen (hex_aux) ; i++)
 {
  if (*(hex_aux+i) >= '0' && *(hex_aux+i) <= '9')
  {
   *(aux+0) = *(hex_aux+i);
   *(aux+1) = '\0';
   *decimal += (pow (16.0,i) * atoi(aux));
  }
  else
  {
   switch (*(hex_aux+i))
   {
    case 'A':
     *decimal += (pow (16.0,i) * 10);
     break;
    case 'B':
     *decimal += (pow (16.0,i) * 11);
     break;
    case 'C':
     *decimal += (pow (16.0,i) * 12);
     break;
    case 'D':
     *decimal += (pow (16.0,i) * 13);
     break;
    case 'E':
     *decimal += (pow (16.0,i) * 14);
     break;
    case 'F':
     *decimal += (pow (16.0,i) * 15);
     break;
   }
  }
 }
 return *decimal;
 free (decimal);
 free (hex_aux);
 free (aux);
}
char*  Hexadecimal_a_Binario (char *hex){
 char *bin;
 bin = (char *) malloc (sizeof(char)*32);
 strcpy (bin, "\0");
 strupr (hex);
 for (int i = 0 ; i < strlen (hex) ; i++)
 {
  switch (*(hex+i))
  {
   case '0':
    strcat (bin ,"0000");
    break;
   case '1':
    strcat (bin ,"0001");
    break;
   case '2':
    strcat (bin ,"0010");
    break;
   case '3':
    strcat (bin ,"0011");
    break;
   case '4':
    strcat (bin ,"0100");
    break;
   case '5':
    strcat (bin ,"0101");
    break;
   case '6':
    strcat (bin ,"0110");
    break;
   case '7':
    strcat (bin ,"0111");
    break;
   case '8':
    strcat (bin ,"1000");
    break;
   case '9':
    strcat (bin ,"1001");
    break;
   case 'A':
    strcat (bin ,"1010");
    break;
   case 'B':
    strcat (bin ,"1011");
    break;
   case 'C':
    strcat (bin ,"1100");
    break;
   case 'D':
    strcat (bin ,"1101");
    break;
   case 'E':
    strcat (bin ,"1110");
    break;
   case 'F':
    strcat (bin ,"1111");
    break;
  }
 }
 return bin;
 free (bin);
}
};

int main(){
Calculator calculator;//objeto
int opc;
int *decimal;
char *bin, *hex;
int menu=1;
decimal = (int *) malloc (sizeof(int));
bin = (char *) malloc (sizeof(char)*32);
hex = (char *) malloc (sizeof(char)*12);
*decimal = 0;
while (menu!= 0){
strcpy (bin, "\0");
strcpy (hex,"\0");
cout<<"BIENVENIDO A LA CALCULADORA DE CONVERSION DE DECIMAL-BINARIO-HEXADECIMAL"<<endl;
cout<<"........................................................................"<<endl;
cout<<"1-CONVERTIR DE DECIMAL A BINARIO Y HEXADECIMAL"<<endl;
cout<<".............................................."<<endl;
cout<<"2-CONVERTIR DE HEXADECIMAL A BINARIO Y DECIMAL"<<endl;
cout<<".............................................."<<endl;
cout<<"3-CONVERTIR DE BINARIO A DECIMAL Y HEXADECIMAL"<<endl;
cout<<".............................................."<<endl;
cin>>opc;
system("cls");

switch(opc){
 case 1:
 	cout<<"INGRESE EL NUMERO DECIMAL"<<endl;
 	cin>> *decimal;
 	cout<<"BINARIO: "<<calculator.Decimal_a_Binario(decimal)<<endl;
 	cout<<"HEXADECIMAL: "<<calculator.Decimal_a_Hexadecimal(decimal)<<endl;
 			break;
 	case 2:
 		cout<<"INGRESE EL NUMERO HEXADECIMAL"<<endl;
 		fflush (stdin);
 			gets (hex); 
 			cout<<"DECIMAL: "<<calculator.Hexadecimal_a_Decimal(hex)<< endl;
 			cout<<"BINARIO: "<<calculator.Hexadecimal_a_Binario(hex)<<endl;
 				break;
 		case 3:
 			cout<<"INGRESE EL NUMERO BINARIO"<<endl;
 			fflush (stdin);
 		 			 gets (bin);
 		 			 cout<<"DECIMAL: "<<calculator.Binario_a_Decimal(bin)<<endl;
 		 			 cout<<"HEXADECIMAL: "<<calculator.Binario_a_Hexadecimal(bin)<<endl;
 							break;
}
 cout<<".................................."<<endl;
 cout<<"1-PARA CONTINUAR EN LA CALCULADORA"<<endl;
 cout<<"................................"<<endl;
 cout<<"0-PARA SALIR DE LA CALCULADORA" <<endl;
 cin>>menu;
 if (menu > 3){
 cout<<"OPCION INVALIDA, SALIR AUTOMATICAMENTE DE LA CALCULADORA"<<endl;
 menu=0;
}
}
system("pause");
free(decimal);
free(hex);
free(bin);
return 0;
}


