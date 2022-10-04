#include "Source.h"
#define Pow(first) first * first



int EditInt() {
	printf("Введите целочисленное число\n");
	int editint;
	scanf_s("%d", &editint);
	return editint;
}
int mulpdel(int (*f)(int), int a, int b) {
	return f(a, b);
}

double dlot(int x1, int y1, int x2 ,int y2) {

	return sqrt(Pow((x2 - x1)) + Pow((y2 - y1)), 2);
}


void treyg(double a, double b, double c) {
	int x1, y1, x2, y2, x3, y3;

	printf("Введите x1\n");
	scanf_s("%d", &x1);
	printf("Введите y1\n");
	scanf_s("%d", &y1);
	printf("Введите x2\n");
	scanf_s("%d", &x2);
	printf("Введите y2\n");
	scanf_s("%d", &y2);
	printf("Введите x1\n");
	scanf_s("%d", &x3);
	printf("Введите y1\n");
	scanf_s("%d", &y3);
	a = dlot(x1,y1,x2,y2);
	b = dlot(x2, y2, x3, y3);

}
int main()
{
	system("chcp 1251>nul");
	int editint = 0;
	int firstnum = 0;
	int secondnum = 0;
	int thery = 0;
	int eit = 0;
	int* editint_adress = &editint;
	int (*f)(int, int);
	int result = 0;
	
	while (1)
	{
		printf("\nЦелочисленная переменная равна: %d", *editint_adress);
		printf("\nИзменение целочисленной переменной: 1\nДинамическое создание/удаление массива: 2\nДинамическое создание массива заданной размерностью: 3\nВывод массива ввиде треугольной матрицы: 4\nДействия :5\n");
		int choose;
		scanf_s("%d", &choose);
		switch (choose)
		{
		case 1: // Изменение целочисленной переменной
			editint = EditInt();
			break;
		case 2: // Инициализация массива из 1000000 элементов, с последующим удалением его из памяти
			InitArrayElem1000000();
			break;
		case 3:
			printf("Введите размер массива:\n");
			int size;
			scanf_s("%d", &size);
			int* initarray = malloc(size * sizeof(int));

			free(InitArrayElemInf(initarray,size)); // Инициализация массива произвольной длины и последующим выводом его в консоль
			break;
		case 4:
			NDimensionalArray(); // Инициализация массива произвольной длины и выводом его ввиде треугольной матрицы
			break;
		case 5:
			printf("Выберите операцию над числами \nСумма: 1\nРазность:2\nУмножение: 3\nДеление: 4\n");
			scanf_s("%d\n", &choose);
			switch (choose)
			{
			case 1: // Указатель на функцию
				f = Sum; 
				scanf_s("%d", &firstnum); scanf_s("%d", &secondnum);
				printf("Сумма чисел равна: %d", f(firstnum, secondnum));
				system("pause>nul");
				break;
			case 2:
				 scanf_s("%d", &firstnum); scanf_s("%d", &secondnum);
				 printf("%d", mulpdel(Razn,firstnum,&secondnum));
				 system("pause>nul");
				break;
			case 3:
				scanf_s("%d", &firstnum); scanf_s("%d", &secondnum);
				printf("%d", mulpdel(Multp, firstnum, &secondnum));
				system("pause>nul");
				break;
			case 4:
				scanf_s("%d", &firstnum); scanf_s("%d", &secondnum);
				printf("%d", mulpdel(Delen, firstnum, &secondnum));
				system("pause>nul");
				break;
			default:
				break;
			}
		case 6:
			scanf_s("%d", &firstnum);
			printf("%d", Pow(firstnum) );
			
			break;
		case 7:

			dlot(1,2,3,4);
			break;
		case 8:
			treyg(4,6,5);
			break;
			

			break;
		default:
			break;
		}
	}
	
}


void InitArrayElem1000000() {
	system("cls");
	int size = 1000000;
	int* initarray = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
		initarray[i] = i;

	printf("Память выделена\n");
	system("pause>nul");
	free(initarray);
	printf("Память очищена\n");
	system("pause>nul");
}

int* InitArrayElemInf(int* initarray, int size) {
	system("cls");
	for (int i = 0; i < size; i++)
	{
		initarray[i] = i+i;
		printf("%d ", initarray[i]);
	}
	return initarray;
}



void NDimensionalArray() {
	system("cls");
	int size;
	printf("Введите размер массива\n");
	scanf_s("%d", &size);
	printf("\n");
	int** initarray = malloc(size* sizeof(int));
	int c = 0;
	for (int i = 0; i < size; i++)  // Заполнение массива
	{
		initarray[i] = malloc(i + 1 * sizeof(int));
		for (int j = 0; j <= i; j++)
		{
			initarray[i][j] = c;
			c++;
		}
	}
	for (int i = 0; i < size; i++)  // Вывод массива ввиде треугольника
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%d ", initarray[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	system("pause");
}

