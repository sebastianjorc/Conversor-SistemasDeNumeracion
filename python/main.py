#Funcion convertir desde decimal
def desde_decimal (numero, base_salida):
	salida = ''
	while numero // base_salida != 0 :
		if ((numero % base_salida)==10):
			salida = str('A')+salida
		elif ((numero % base_salida)==11):
			salida = str('B')+salida
		elif ((numero % base_salida)==12):
			salida = str('C')+salida
		elif ((numero % base_salida)==13):
			salida = str('D')+salida
		elif ((numero % base_salida)==14):
			salida = str('E')+salida
		elif ((numero % base_salida)==15):
			salida = str('F')+salida
		else:
			salida = str (numero % base_salida) + salida
		numero = numero  // base_salida
	
	if (numero==10):
		return str('A')+salida
	elif (numero==11):
		return str('B')+salida
	elif (numero==12):
		return str('C')+salida
	elif (numero==13):
		return str('D')+salida
	elif (numero==14):
		return str('E')+salida
	elif (numero==15):
		return str('F')+salida
	else:		
		return str(numero)+salida

#Funcion convertir desde cualquier tipo a decimal
def a_decimal(numero,base_entrada):
	return int(str(numero),base_entrada)

#Programa principal
base_entrada = int(input('Introdusca la base del numero a ingresar: '))
#	HACE FALTA INGRESAR DESDE UN HEXADECIMAL
numero = int (input('Introduce numero a convertir: '))
#	HACE FALTA COMPROVAR SI OPCION INGRESADA ES ACORDE A BASE DEL NUMERO
base_salida = int(input('Base a convertir: '))

if base_entrada==10:
	print(desde_decimal(numero,base_salida))
else:
	print(desde_decimal(a_decimal(numero,base_entrada),base_salida))
