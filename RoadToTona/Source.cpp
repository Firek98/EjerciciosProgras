#include <iostream>
#include <string>
#include <ctime>
//// Exercise 0
//Una funci�n dumpArrayInt que dada una array  y su tama�o como par�metros
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
//Una funci�n swapInArray que dada una array de enteros y dos �ndices
//intercambie los elementos que hay en esos �ndices
//bonus: hazlo sin crear ninguna variable m�s
void swapInArray(int arr[], int i1, int i2)
{
	arr[i1] += arr[i2];
	arr[i2] = arr[i1] - arr[i2];
	arr[i1] -= arr[i2];
}
//// Exercise 2
//Una funci�n toUpper que dada una array de car�cteres y el n�mero de elementos
//recorra la array haciendo que las min�sculas pasen a ser may�sculas.
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
//Una funci�n reverseArray que reciba una array, un �ndice "first" y un �ndice "last"
//y modifique la array para que los elementos los elementos entre "first" y "last"
//(ambos inclusivos) est�n al rev�s, por ejemplo ([2 6 1 7 9] , 1, 3) -> [2 7 1 6 9]
//bonus: hazlo utilizando s�lo dos puntos y coma
void reverseArray(int arr[], int first, int last)
{
	if (first < last)
	{
		swapInArray(arr, first, last);
		reverseArray(arr, first+1, last-1); 
	}
}
//// Exercise 4
//Una funci�n minInArray que dadas:
//una array de enteros, un �ndice "first", un �ndice "last" y un entero "index"
//modifique el entero "index" para apunte al elemento de la array m�s peque�o entre
//los elementos first y last (ambos incluidos)
//bonus: hazlo con un �nico punto y coma, asumid que "index" vale "first" al llamar a la funci�n
//bonus2: haz una versi�n alternativa minInArrayPure que en vez de pasar index por referencia, lo devuelva
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
//Una funci�n sort que dada una array de n�meros enteros y el tama�o de la misma
//ordene los elementos de la array para que esten ordenados de mayor a menor.
//bonus: utiliza las funci�n minInArray
//bonus2: hazlo con un �nico punto y coma
void sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i + 1] > arr[i])
			swapInArray(arr, i + 1, i);
	}
}
//// Exercise 6
//Haz una funci�n randomNumber tal que dados:
//* Un n�mero m�nimo (incluido), por ejemplo 0.5
//* Un n�mero m�ximo (no incluido), por ejemplo 1.5
//* Un valor de precisi�n, por ejemplo 0.001
//Devuelva un n�mero aleatorio (originado en rand()) entre min y max(no incluido)
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
//Una funci�n randomItem que cree y devuelva un item random
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
//Una funci�n dropLoot que dada una array de items y el tama�o
//de la array, inicialice todos los elementos de la array utilizando randomItem
void dropLoot(Item arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = randomItem();
	}
}
// Crea una funci�n que genere n�meros aleatorios entre 1 y 9
// en una array tridimensional de tama�o 5 x 5 x 5
// a continuaci�n imprime la posici�n de todos los n�meros 3
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
// Crea una funci�n que imprima por pantalla el n�mero que
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
////////////////////////////////////////////////////////////
//////////////// TONA PRIMER CURSO /////////////////////////
////////////////////////////////////////////////////////////

// A02 

enum EnemyType
{
	zombie, vampire, ghost, witch, MAX
};

std::string nombres[5]{ "paco", "marc", "mar", "ramon"};

struct Enemy
{
	EnemyType type;
	std::string name;
	int health;
	bool operator()(Enemy a, Enemy b)
	{
		if (a.name == b.name && a.type == b.type)
		{
			return true;
		}
		else return false;
	}
};

Enemy CreateRandomEnemy()
{
	Enemy enemigo;

	enemigo.health = rand() % 301;
	enemigo.type = static_cast<EnemyType>(rand() % MAX);
}