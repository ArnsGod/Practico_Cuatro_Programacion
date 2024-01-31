#include <iostream>// Esta biblioteca proporciona las funciones básicas de entrada y salida
#include <string>// Esta biblioteca proporciona el tipo de datos string y varias funciones y operaciones relacionadas con cadenas de caracteres
#include <cctype>//Esta biblioteca proporciona funciones para trabajar con caracteres y cadenas de caracteres. En particular, se utiliza la función tolower()
#include <ctime>// Esta biblioteca proporciona funciones relacionadas con el tiempo y la fecha
#include <climits>//Esta biblioteca define constantes con los límites de los tipos de datos enteros
#include <cstdlib> // Para system("cls"), para realizar operaciones relacionadas con el sistema para limpiar la pantalla de la consola. 
/*Esta biblioteca no estándar proporciona funciones para interactuar con la consola. En tu código, utilizas _getch(), que espera la pulsación de una tecla*/
#include <conio.h> // Para _getch()

using namespace std;

char opcion;
/*Un arreglo de cadenas de texto (string) llamado nombre. Contiene nombres predefinidos, Este arreglo tiene 10 elementos.*/
string nombre[] = {"Martina", "Alejandro", "Isabella", "Mateo", "Camila", "Juan", "Yandira", "Jesus", "Eduardo", "Rosa"};
string apellido[] = {"Torres", "Lopez", "Salame", "Fernandez", "Rodriguez", "Escobal", "Salvatierra", "Flores", "Escudero", "Gutierrez"};//Similar al arreglo de nombres
int notas[10];//Un arreglo de enteros llamado notas, que se utiliza para almacenar notas
string contra[10];//Otro arreglo de cadenas de texto llamado contra, utilizado para almacenar contraseñas ofuscadas
/*dos arreglos adicionales (nombreOfuscado y apellidoOfuscado, se utilicen para almacenar versiones ofuscadas de los nombres y apellidos originales*/
string nombreOfuscado[10];
string apellidoOfuscado[10];


void limpiarPantalla() //Funcion para limpiar Pantalla 
{
	system("cls");
}

void esperarClic() //Funcion para esperar click
{
	cout << "Presiona cualquier tecla para continuar..."<<endl;
	/*la función se llama simplemente para esperar la pulsación de una tecla*/
	_getch(); // Espera a que se presione una tecla
}
/*
	string& valor_dos: Una referencia a una cadena de texto (string) llamada valor_dos.
	El uso de & indica que la cadena se pasa por referencia, lo que significa que la función puede modificar directamente la cadena original en la memoria.
	char vocal: Un carácter que representa la vocal que se busca en la cadena.
	char numero: Un carácter que reemplazará las ocurrencias de la vocal en la cadena.
*/
void cambiarVocales(string& valor_dos, char vocal, char numero)//Funcion para Cambiar las letras por numero
{
	size_t site = 0;//Inicializa una variable site que se utilizará para rastrear la posición actual en la cadena.
	/*Se ejecuta un bucle do-while que busca continuamente la próxima ocurrencia de la vocal en la cadena utilizando find. 
	Este bucle se ejecuta hasta que no se encuentran más ocurrencias */
	do 
	{
		site = valor_dos.find(vocal, site);//Busca la próxima ocurrencia de la vocal a partir de la posición actual site. El resultado se almacena en site.
		/*Si se encontró una ocurrencia válida (es decir, no llegamos al final de la cadena), cambia el carácter en esa posición por el carácter numero*/
		if (site != string::npos)//npos es una representación convencional del "final de la cadena" o "no encontrado"
			valor_dos[site] = numero;
		/*Iteración =  repetir varias veces un proceso con la intención de alcanzar una meta deseada*/
		/*: Si se encontró una ocurrencia válida, incrementa la posición actual para buscar la próxima ocurrencia en la siguiente iteración*/
		if (site != string::npos)
			site++;
	} while (site != string::npos);// indica que no se encontró ninguna más
}

void ofuscar()//Funcion para ejecutar la ufuscado de los nombres y apellidos y usarlos como contraseña
{
	for (int i = 0; i < 10; i++) {
		nombreOfuscado[i] = nombre[i];// Crea una copia del nombre original en el nuevo arreglo nombreOfuscado
		apellidoOfuscado[i] = apellido[i];//Crea una copia del nombre original en el nuevo arreglo apellidoOfuscado
		/*se utiliza la función cambiarVocales para reemplazar ciertas vocales en los nombres y apellidos con números específicos.*/
		cambiarVocales(nombreOfuscado[i], 'a', '4');
		cambiarVocales(nombreOfuscado[i], 'e', '3');
		cambiarVocales(nombreOfuscado[i], 'i', '1');
		cambiarVocales(nombreOfuscado[i], 'o', '0');
		cambiarVocales(nombreOfuscado[i], 's', '5');
		cambiarVocales(nombreOfuscado[i], 't', '7');
		
		cambiarVocales(apellidoOfuscado[i], 'a', '4');
		cambiarVocales(apellidoOfuscado[i], 'e', '3');
		cambiarVocales(apellidoOfuscado[i], 'i', '1');
		cambiarVocales(apellidoOfuscado[i], 'o', '0');
		cambiarVocales(apellidoOfuscado[i], 's', '5');
		cambiarVocales(apellidoOfuscado[i], 't', '7');
		
		/*Concatena los nombres y apellidos ofuscados para formar contraseñas. Las contraseñas resultantes se almacenan en el arreglo contra*/
		contra[i] = nombreOfuscado[i] + apellidoOfuscado[i]; // Contraseña es la concatenación de nombre y apellido ofuscados
	}
}

void generarCon() //Funcion para generar la contraseña ofusgada
{
	ofuscar(); // Llamar a la función de ofuscación
	cout << "Contraseñas" << endl;//Muestra en la consola un encabezado indicando que las siguientes líneas son las contraseñas generadas
	/* Utiliza un bucle para imprimir cada contraseña ofuscada almacenada en el arreglo contra. 
	La variable i itera sobre las 10 contraseñas generadas, y contra[i] accede a cada contraseña para imprimirse en una nueva línea*/
	for (int i = 0; i < 10; i++) {
		cout << contra[i] << endl;
	}
}

void imprimirContra()//Funcion para poder imprimir la contraseña
{
	for (int i = 0; i < 10; i++) {
		cout << contra[i] << endl;//Impime la generacion de contraseñas
	}
}

int generarNota() //Genera valores aleatorios entre 0 - 30
{
	return rand() % 31;//Genera valores aleatorios de 0-30
}

string nombreU() //Genera un orden aleatorio de nombres de la cadena nombre[]
{
	return nombre[rand() % 10]; // Genera un orden aleatorio en el vector de nombre
}

string apellidoU() //Genera un orden aleatorio de nombres de la cadena apellido[]
{
	return apellido[rand() % 10];//Genera un orden aleatorio en el vector apellido
}


void imprimir() //Muestra los valores de nombre, apellido y nota
{
	cout << "Datos de los estudiantes" << endl;
	cout << "Nombre   \t  \t  |  Apellido   \t  \t   | Nota" << endl;//Mostar como va a estar ordenado 
	for (int i = 0; i < 10; i++)// para iterar sobre cada estudiante (representado por el índice i desde 0 hasta 9)
	{
		/* Imprime en la consola los datos del estudiante actual. Cada línea muestra el nombre, apellido y nota del estudiante, separados por columnas y tabulaciones (\t*/
		cout << nombre[i] << "\t  "<<"\t  " <<"  |  "<< apellido[i] << " \t "<<"\t  " <<"  |  "<< notas[i] << endl;
	}
}

void imprimirTodo() //Muestra los valores de nombre, apellido, nota y contraseña
{
	cout << "Datos de los estudiantes" << endl;
	cout << "Nombre\t            Apellido\t     Nota\t        contraseña" << endl;//Agregamos la funcion contraseña
	for (int i = 0; i < 10; i++) // para iterar sobre cada estudiante (representado por el índice i desde 0 hasta 9) con la contraseña generada previamente
	{
		/*Imprime en la consola los datos del estudiante actual. Cada línea muestra el nombre, apellido y nota del estudiante, separados por columnas y tabulaciones (\t*/
		cout << nombre[i] << "\t  " << "\t  " << " | " << apellido[i] << " \t "  << "\t  " <<" | "<< notas[i]<<"\t  "<< "\t  " <<" | "<< contra[i] << endl;
	}
}

void antDuplicadoNom() //Evita que se duplique cierta cantidad de nombres
{
	for (int i = 0; i < 10; i++) 
	{
		for (int j = i + 1; j < 10; j++) 
		{
			while (nombre[i] == nombre[j]) //Si encuentra un "nombre" identico genera uno nuevo
			{
				nombre[j] = nombreU();
			}
		}
	}
}

void MediaNota()//Funcion para verificar la medio de calificaciones
{
	int suma = 0;//Se inicializa una variable suma con el valor cero. Esta variable se utilizará para acumular la suma de todas las calificaciones
	/*Utiliza un bucle for para iterar sobre las calificaciones de los 10 estudiantes y acumula la suma de esas calificaciones en la variable suma*/
	for (int i = 0; i < 10; i++) 
	{
		suma += notas[i];
	}
	/*Calcula la media dividiendo la suma de las calificaciones entre el número total de estudiantes*/
	/*static_cast<double>(suma) se realiza para asegurar que la división se realice con números de punto flotante y no entera, lo que garantiza una respuesta más precisa.*/
	double media = static_cast<double>(suma) / 10;
	cout << "Promedio de todas las notas: " << media << endl;// Muestra en la consola el resultado del cálculo
}

void MayorAndMenor() //Funcion para ver la mayor y menor nota total
{
	int notaMayor = INT_MIN;//Inicializa la variable notaMayor con el valor mínimo posible para un entero (INT_MIN). Esta variable se utilizará para rastrear la nota más alta encontrada.
	int notaMenor = INT_MAX;//Inicializa la variable notaMenor con el valor máximo posible para un entero (INT_MAX). Esta variable se utilizará para rastrear la nota más baja encontrada.
	/* Inicializa dos variables de cadena (estudianteMayor y estudianteMenor) que almacenarán los nombres y apellidos de los estudiantes con las notas más alta y más baja*/
	string estudianteMayor, estudianteMenor;
	
	for (int i = 0; i < 10; i++) //Utiliza un bucle for para iterar sobre las notas de los 10 estudiantes.
	{
		/*
		Compara la nota actual con la nota más alta registrada hasta ahora. 
		Si la nota actual es mayor, actualiza notaMayor y estudianteMayor con la nueva nota y la información del estudiante.
		*/
		if (notas[i] > notaMayor) 
		{
			notaMayor = notas[i];
			estudianteMayor = nombre[i] + " " + apellido[i];
		}
		/*
		compara la nota actual con la nota más baja registrada hasta ahora. 
		Si la nota actual es menor, actualiza notaMenor y estudianteMenor con la nueva nota y la información del estudiante.
		*/
		if (notas[i] < notaMenor) 
		{
			notaMenor = notas[i];
			estudianteMenor = nombre[i] + " " + apellido[i];
		}
	}
	
	cout << "Estudiante con la nota más alta: " << estudianteMayor << ", Nota: " << notaMayor << endl;//Muestra en la consola el estudiante con la nota más alta y la nota correspondiente.
	cout << "Estudiante con la nota más baja: " << estudianteMenor << ", Nota: " << notaMenor << endl;//Muestra en la consola el estudiante con la nota más baja y la nota correspondiente.
}

void antDuplicadoApe()////Evita que se duplique cierta cantidad de apellidos
{
	for (int i = 0; i < 10; i++) 
	{
		for (int j = i + 1; j < 10; j++) 
		{
			while (apellido[i] == apellido[j]) //Si encuentra un "apellido" identico genera uno nuevo
			{
				apellido[j] = apellidoU();
			}
		}
	}
}

void generar()//Genera un orden aleatorio de nombres
{
	for (int i = 0; i < 10; i++) 
	{
		nombre[i] = nombreU();//Genera un orden aleatorio de nombres
		antDuplicadoNom();//llamada a las funciones antDuplicado para evitar que no se dupliquen nombres
		apellido[i] = apellidoU();//Genera un orden aleatorio de apellidos
		antDuplicadoApe();//llamada a las funciones antDuplicado para evitar que no se dupliquen apellidos
	}
}

void generarNotas() // Genera un orden aleatorio de valores de notas
{
	for (int i = 0; i < 10; i++) 
	{
		notas[i] = generarNota();//Genera un orden de numeros aleatorios para las notas
	}
}

void menu() //Menu principal
{
	cout << "(1)- Llenar nombres, apellidos y notas de forma aleatoria" << endl;
	cout << "(2)- Ofuscar nombres y apellidos para llenar las contraseñas" << endl;
	cout << "(3)- Sacar la media, el mayor y menor de todas las notas" << endl;
	cout << "(4)- Imprimir datos" << endl;
	cout << "(s/S)- Salir" << endl;
	cin >> opcion;
}

int main(int argc, char *argv[]) 
{
	/*
	srand es responsable de inicializar la semilla para el generador de números aleatorios. La semilla es un valor inicial que determina la secuencia de números aleatorios que se generará.
	time(nullptr) obtiene el tiempo actual en segundos desde el 1 de enero de 1970 (conocido como el epoch) hasta el momento de la llamada. Esencialmente, obtiene una marca de tiempo.
	srand(time(nullptr)); utiliza la marca de tiempo actual como semilla para el generador de números aleatorios. Al hacerlo, se asegura de que cada vez que ejecutes el programa, la secuencia de números aleatorios generada sea diferente.
	*/
	srand(time(nullptr));
	do {
		menu();//Llmada a la funcion menu
		opcion = tolower(opcion);//Tranfoma las mayusculas ingresadas en minusculas
			switch(opcion) 
			{
				case '1':
					limpiarPantalla();//llamada a la funcion limpiar Pantalla
					generar();//Llamada a la funcion generar nombre y apelldios
					generarNotas();//llamada a la funcion generar notas
					imprimir();//Funcion para mostar nombre , apellido, nota
					
					esperarClic();//Llamada a la funcion esperar el click
				break;
				case '2':
					limpiarPantalla();//llamada a la funcion limpiar Pantalla
					generarCon();//Genera una contraseña basada en su nombre apellido ofuscado
					esperarClic();//Llamada a la funcion esperar el clic
				break;
				case '3':
					limpiarPantalla();//llamada a la funcion limpiar Pantalla
					MediaNota();//Funcion para calcular el promedio de las notas generadas
					MayorAndMenor();//Funcion para ver cuales son los nombres con la notas mas alta y baja
					esperarClic();//Llamada a la funcion esperar el clic
				break;
				case '4':
					generarCon();//Genera una contraseña basada en su nombre apellido ofuscado
					limpiarPantalla();//llamada a la funcion limpiar Pantalla
					imprimirTodo();//Funcion para imprimir todos los datos junto a la contraseña
					esperarClic();//Llamada a la funcion esperar el clic
				break;
				case 's':
					limpiarPantalla();//llamada a la funcion limpiar Pantalla
					cout << "Saliendo del programa" << endl;
					esperarClic();//Llamada a la funcion esperar el clic
				break;
				default:
					limpiarPantalla();//llamada a la funcion limpiar Pantalla
					cout << "Opción no válida. Inténtelo de nuevo." << endl;
					esperarClic();//Llamada a la funcion esperar el clic
				break;
		}
	} while(opcion != 's');
	
	return 0;
}
