#Funcion imprimir
def imprimir (n):
	if (n<0):
		print (0)
	elif (n<=1):
		print n,
	else:
	#	changeHex(n/16)
		x=(n%16)
		if(x<10):
			print(x),
		elif (x==10):
			print("A"),
		elif (x==11):
			print("B"),
		elif (x==12):
			print("C"),
		elif (x==13):
			print("D"),
		elif (x==14):
			print("E"),
		elif (x==15):
			print("F"),
	
#Funcion convertir desde decimal
def desde_decimal (numero, base_salida):
	salida = ''
	while numero // base_salida != 0:
		print (numero)
		salida = str (numero % base_salida) + salida
		numero = numero  // base_salida

	return str(numero)+salida

#Funcion convertir desde cualquier tipo a decimal
def a_decimal(numero,base_entrada):
	return int(str(numero),base_entrada)

#Programa principal
base_entrada = int(input('Introdusca la base del numero a ingresar: '))
numero = int (input('Introduce numero a convertir: '))
#HACE FALTA COMPROVAR SI OPCION INGRESADA ES ACORDE A BASE DEL NUMERO
base_salida = int(input('Base a convertir: '))

if base_entrada==10:
	if base_salida==16:
		imprimir(numero);
	else:		
		print(desde_decimal(numero,base_salida))
else:
	if base_salida==16:
		imprimir(numero);
	else:		
		print(desde_decimal(a_decimal(numero,base_entrada),base_salida))
