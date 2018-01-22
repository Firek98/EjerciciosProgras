#include <iostream>

//// Exercise 0
//Una función dumpArrayInt que dada una array  y su tamaño como parámetros
//imprima los elementos de la array en el formato [ 0, 1, 2, 3]
void dumpArrayInt(int arr[], int size)
{
	std::cout << '[';
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ', ';
	}
	std::cout << ']';
}
//// Exercise 1
//Una función swapInArray que dada una array de enteros y dos índices
//intercambie los elementos que hay en esos índices
//bonus: hazlo sin crear ninguna variable más

void swapInArray(int arr[], int i1, int i2)
{
	arr[i1] += arr[i2];
	arr[i2] = arr[i1] - arr[i2];
	arr[i1] -= arr[i2];
}
//// Exercise 2
//Una función toUpper que dada una array de carácteres y el número de elementos
//recorra la array haciendo que las minúsculas pasen a ser mayúsculas.
//bonus: hazlo sin mirar la tabla ascii
void toUpper(char arr[], int size)
{
	int aux = 'a' - 'A';
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 'a' && arr[i] < 'z')
		{
			arr[i] += aux;
		}
	}
}
//// Exercise 3
//Una función reverseArray que reciba una array, un índice "first" y un índice "last"
//y modifique la array para que los elementos los elementos entre "first" y "last"
//(ambos inclusivos) estén al revés, por ejemplo ([2 6 1 7 9] , 1, 3) -> [2 7 1 6 9]
//bonus: hazlo utilizando sólo dos puntos y coma
void reverseArray(int arr[], int first, int last)
{
	if (first < last)
	{
		swapInArray(arr, first, last);
		reverseArray(arr, first+1, last-1); 
	}
}
//// Exercise 4
//Una función minInArray que dadas:
//una array de enteros, un índice "first", un índice "last" y un entero "index"
//modifique el entero "index" para apunte al elemento de la array más pequeño entre
//los elementos first y last (ambos incluidos)
//bonus: hazlo con un único punto y coma, asumid que "index" vale "first" al llamar a la función
//bonus2: haz una versión alternativa minInArrayPure que en vez de pasar index por referencia, lo devuelva
void minInArray(int arr[], int first, int last, int &index)
{
	if (first < last)
	{
		minInArray(arr, first++, last, index = arr[first] < arr[last] ? first : index);
	}
}

int minInArrayPure(int arr[], int first, int last, int index)
{
	return (first < last)
		? minInArrayPure(arr, first++, last, index = arr[first] < arr[last] ? first : index)
		: index;
}
//// Exercise 5
//Una función sort que dada una array de números enteros y el tamaño de la misma
//ordene los elementos de la array para que esten ordenados de mayor a menor.
//bonus: utiliza las función minInArray
//bonus2: hazlo con un único punto y coma
void sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i + 1] > arr[i])
			swapInArray(arr, i + 1, i);
	}
}
//// Exercise 6
//Haz una función randomNumber tal que dados:
//* Un número mínimo (incluido), por ejemplo 0.5
//* Un número máximo (no incluido), por ejemplo 1.5
//* Un valor de precisión, por ejemplo 0.001
//Devuelva un número aleatorio (originado en rand()) entre min y max(no incluido)
//por ejemplo 0.5 o 1.499
float randomNumber(float min, float max, float pre)
{
	return (min + rand() % static_cast<int>((max - min) * 1.0f/ pre))*pre;
}
//// Exercise 7
//Haz una estructura Item que tenga componentes
//* "defensa", "ataque" y "velocidad" entre 0.01 y 0.99
//* un componente que diga si el Item es ARMA o ARMADURA
struct Item
{
	float defensa = randomNumber(0.01, 0.99, 0.01);
	float ataque  = randomNumber(0.01, 0.99, 0.01);
	float velocidad = randomNumber(0.01, 0.99, 0.01);
	enum tipo
	{
		ARMA, ARMADURA
	};
	tipo type;
};
//// Exercise 8
//Una función randomItem que cree y devuelva un item random
//* Si el ataque es mayor que la defensa, es un ARMA
//* Si la defensa es mayor que el ataque, es una ARMADURA

Item randomItem()
{
	Item objeto;
	if (objeto.ataque > objeto.defensa)
	{
		objeto.type = objeto.ARMA;
		return objeto;
	}
	else
		objeto.type = objeto.ARMADURA;
		return objeto;
}
//// Exercise 9
//Una función dropLoot que dada una array de items y el tamaño
//de la array, inicialice todos los elementos de la array utilizando randomItem
void dropLoot(Item arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = randomItem();
	}
}
// Crea una función que genere números aleatorios entre 1 y 9
// en una array tridimensional de tamaño 5 x 5 x 5
// a continuación imprime la posición de todos los números 3
void Array3D1()
{
	int arr[5][5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				arr[i][j][k] = 1 + rand() % (9 - 1);
				if (arr[i][j][k] == 3)
				{
					std::cout << arr[i][j][k];
				}
			}
		}
	}
}
// Crea una función que imprima por pantalla el número que
// aparece menos veces en una array tridimensional 2 x 2 x 2
void LessFrequent(int arr[][2][2], int size)
{
	int aux = arr[0][0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				
			}
		}
	}
}
// Crea una función que lea palabra a palabra un archivo y imprima
// la primera y última letra de cada palabra así como el tamaño de la misma.

// Crea una función que lea un mensaje de entrada estándar (cin)
// y escriba en un archivo los carácteres ascii que la componen,
// separados por comas. (ej: AAA 65,65,65)

// Investiga la función string::substr y string::append.
// Crea una función que lea por entrada estandar dos strings utilizando cin
// la función tendrá que imprimir una palabra compuesta por la mitad de los
// carácteres de cada una de las palabras.

// Crea una función que transforme todos los elementos de una string
// que sean carácteres en minúscula a mayúscula.

// Crea una función log, que reciba una string, la función
// debe añadirla al final de un fichero sin borrarla

// Crea otra función que lea un archivo codificado en ascii,
// (el descrito en el apartado anterior) y imprima por pantalla
// el mensaje original

//// Ejercicios de punteros

// 1) Suponiendo que compila correctamente, en la expresión 
int b = 5;
int * a = &b;
// a) Qué tipo es b y cuanto vale?
// b) Qué tipo es a?
// c) Qué hace &b?
// d) Cómo podríamos ver el valor de a?
// e) Cómo podríamos ver el valor al que apunta a?

// 2) Qué hace la siguiente función
void magic(int * a, int * b) {
	*b = a[1];
}

// 3) Dada la siguiente función:
int& magic2(int * a, int * b) {
	b = a + 1;
	return *b;
}
// a) Qué esta devolviendo?

// 4) Haz una función que dado un puntero a int
// y sabiendo que en *i esta el primer elemento
// de una array cuyo último elemento es 0,
// imprima todos los elementos de la array.
