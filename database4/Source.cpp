#include<iostream>
#include<conio.h>
#include <cstring>
#include "windows.h""
#include <ctype.h>
#pragma pack(push, 1)
using namespace std;
const int _down = 80, _up = 72, _right = 77, _left = 75, _enter = 13, _esc = 27, _space = 32, _backspace = 8;
bool exit_control = true;
int Length = 0, Length_add = 0, Length_dell = 0, k_Length_add = 0, Length_sort = 0,list_label=0;
char menu[110][40];
FILE *in, *out;
void setcur(int x, int y)//��������� ������� �� ������� x y 
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void color(int x)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((0 < 4) | x));
}
struct list_third_menu
{
	char mas[110];
	list_third_menu*next;
};
list_third_menu*beginning;
struct list
{
	char club[30] = "\0";
	char surname[30] = "\0";
	char name[30] = "\0";
	char patronymic[29] = "\0";
	//char data[30] = "\0";
	char number[16] = "\0";
	char height[16] = "\0";
	char weight[16] = "\0";
	char age[16] = "\0";
	char c = 0;
	list*next, *prev;
}*please,*search;
#pragma pack(pop, 236)
struct list_first_menu
{
	const char *outfile = "������� �� �����";
	const char *infile = "��������� � ����";
	//const char *add = "������� ���� � ���";
	const char *search = "�����";
	const char *sort = "����������";
	//const char *age = "������� �������";
	const char *del = "������� ������";
	const char *alldel = "������� ���� ������";
	const char *exit = "esc-�����";
};
struct _sort_input
{
	char in_alphabetical_order[30] = "�� � �� �";
	char not_in_alphabetical_order[30] = "�� � �� �";
};
struct sort_list
{
	char club[30] = "\0";
	char surname[30] = "\0";
	char name[30] = "\0";
	char patronymic[30] = "\0";
	//char data[30] = "\0";
	char number[16] = "\0";
	char height[30] = "\0";
	char weight[30] = "\0";
	char age[30] = "\0";
	sort_list*next, *prev;
};
void in_File()
{
	in = fopen("data.xlsx", "wt");
	fclose(in);
}
list* creat_list(list*start, list*tail, unsigned length)
{
	list *last = 0;
	for (unsigned i = 1; i <= length; ++i)
	{
		start = new list;
		if (!tail)
			tail = start;
		start->next = last;
		if (last)
			last->prev = start;
		last = start;
	}
	start->prev = 0;
	return start;
}
bool is_digit(const char *S) {
	const char *temp = "0123456789";


	for (int i = 0; i < strlen(S); i++) {
		if (strlen(S) > 2)
		{
			cin.clear();
			cin.sync();
			return false;
		}

		if (!strchr(temp, S[i]))
		{
			cin.clear();
			cin.sync();
			return false;
		}
		if (S[0] == '0')
		{
			cin.clear();
			cin.sync();
			return false;
		}
		if (S[0] == 32)
		{
			cin.clear();
			cin.sync();
			return false;
		}
	}
	return true;
}

bool is_digit1(const char *S) {
	const char *temp = "0123456789";

	for (int i = 0; i < strlen(S); i++) {
		if (strlen(S) > 5)
		{
			cin.clear();
			cin.sync();
			return false;
		}
		if (!strchr(temp, S[i]))
		{
			cin.clear();
			cin.sync();
			return false;
		}
		if (S[0] == 32)
		{
			cin.clear();
			cin.sync();
			return false;
		}
	}
	return true;
}

bool is_digit2(const char *S) {
	const char *temp = "�����������Ÿ�����������������������������������������������������";

	for (int i = 0; i < strlen(S); i++) {
		if (strlen(S) > 15)
		{
			cin.clear();
			cin.sync();
			return false;
		}
		if (!strchr(temp, S[i]))
		{
			cin.clear();
			cin.sync();
			return false;
		}
		if (S[0] == 32)
		{
			cin.clear();
			cin.sync();
			return false;
		}
	}
	return true;
}

bool is_digit3(const char *S) {
	const char *temp = "!@#$%^&*()-+=:%;�.,/\|_";

	for (int i = 0; i < strlen(S); i++) {
		if (strlen(S) > 20)
		{
			cin.clear();
			cin.sync();
			return false;
		}
		if (strchr(temp, S[i]))
		{
			return false;
		}
		if (S[0] == 32)
		{
			cin.clear();
			cin.sync();
			return false;
		}
	}
	return true;
}
void output_list(list*start)
{
	setlocale(0, "");
	int x = 40, y = 7, j = 0, k;
	int _coordx = x, _coordy = y;
	if (Length < 12)
		k = Length;
	else
		k = 12;
	for (int i = 0; i < k; ++i)
	{
		//if (list_label == 0 && start!=0 && start->c == 0)
		//if (start->c == 1)
		//{
			while (start != 0 && start->club[j] != '\0')
			{
				if (_coordx < 54 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->club[j];
					++_coordx;
				}
				else
				{
					_coordx = 40;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->surname[j] != '\0')
			{
				if (_coordx < 69 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->surname[j];
					++_coordx;
				}
				else
				{
					_coordx = 55;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->name[j] != '\0')
			{
				if (_coordx < 84 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->name[j];
					++_coordx;
				}
				else
				{
					_coordx = 70;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->patronymic[j] != '\0')
			{
				if (_coordx < 99 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->patronymic[j];
					++_coordx;
				}
				else
				{
					_coordx = 85;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->number[j] != '\0')
			{
				if (_coordx < 122 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->number[j];
					++_coordx;
				}
				else
				{
					_coordx = 115;
					_coordy++;
				}
				++j;
			}
			x += 8;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->height[j] != '\0')
			{
				if (_coordx < 130 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->height[j];
					++_coordx;
				}
				else
				{
					_coordx = 123;
					_coordy++;
				}
				++j;
			}
			x += 8;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->weight[j] != '\0')
			{
				if (_coordx < 138 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->weight[j];
					++_coordx;
				}
				else
				{
					_coordx = 131;
					_coordy++;
				}
				++j;
			}
			x += 8;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->age[j] != '\0')
			{
				if (_coordx < 146 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->age[j];
					++_coordx;
				}
				else
				{
					_coordx = 139;
					_coordy++;
				}
				++j;
			}
		//}
			if (start != NULL)
				start = start->next;
		//if (start != NULL)
			//start = start->next;
		y += 3;
		_coordy = y;
		x = 40;
		_coordx = x;
		j = 0;
	}
}
void output_list_(list*start)
{
	setlocale(0, "");
	int x = 40, y = 7, j = 0, k;
	int _coordx = x, _coordy = y;
	if (Length < 12)
		k = Length;
	else
		k = 12;
	for (int i = 0; i < k; ++i)
	{
		if (list_label == 0 && start != 0 && start->c == 0)
			//if(start->c==1)
		{
			while (start != 0 && start->club[j] != '\0')
			{
				if (_coordx < 54 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->club[j];
					++_coordx;
				}
				else
				{
					_coordx = 40;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->surname[j] != '\0')
			{
				if (_coordx < 69 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->surname[j];
					++_coordx;
				}
				else
				{
					_coordx = 55;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->name[j] != '\0')
			{
				if (_coordx < 84 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->name[j];
					++_coordx;
				}
				else
				{
					_coordx = 70;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->patronymic[j] != '\0')
			{
				if (_coordx < 99 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->patronymic[j];
					++_coordx;
				}
				else
				{
					_coordx = 85;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->number[j] != '\0')
			{
				if (_coordx < 122 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->number[j];
					++_coordx;
				}
				else
				{
					_coordx = 115;
					_coordy++;
				}
				++j;
			}
			x += 8;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->height[j] != '\0')
			{
				if (_coordx < 130 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->height[j];
					++_coordx;
				}
				else
				{
					_coordx = 123;
					_coordy++;
				}
				++j;
			}
			x += 8;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->weight[j] != '\0')
			{
				if (_coordx < 138 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->weight[j];
					++_coordx;
				}
				else
				{
					_coordx = 131;
					_coordy++;
				}
				++j;
			}
			x += 8;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->age[j] != '\0')
			{
				if (_coordx < 146 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->age[j];
					++_coordx;
				}
				else
				{
					_coordx = 139;
					_coordy++;
				}
				++j;
			}
		}
		else
		{
			while (start != 0 && start->club[j] != '\0')
			{
				if (_coordx < 54 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->club[j];
					++_coordx;
				}
				else
				{
					_coordx = 40;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->surname[j] != '\0')
			{
				if (_coordx < 69 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->surname[j];
					++_coordx;
				}
				else
				{
					_coordx = 55;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->name[j] != '\0')
			{
				if (_coordx < 84 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->name[j];
					++_coordx;
				}
				else
				{
					_coordx = 70;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->patronymic[j] != '\0')
			{
				if (_coordx < 99 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->patronymic[j];
					++_coordx;
				}
				else
				{
					_coordx = 85;
					_coordy++;
				}
				++j;
			}
			x += 15;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->number[j] != '\0')
			{
				if (_coordx < 122 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->number[j];
					++_coordx;
				}
				else
				{
					_coordx = 115;
					_coordy++;
				}
				++j;
			}
			x += 8;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->height[j] != '\0')
			{
				if (_coordx < 130 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->height[j];
					++_coordx;
				}
				else
				{
					_coordx = 123;
					_coordy++;
				}
				++j;
			}
			x += 8;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->weight[j] != '\0')
			{
				if (_coordx < 138 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->weight[j];
					++_coordx;
				}
				else
				{
					_coordx = 131;
					_coordy++;
				}
				++j;
			}
			x += 8;
			_coordx = x;
			_coordy = y;
			j = 0;
			while (start != 0 && start->age[j] != '\0')
			{
				if (_coordx < 146 && (_coordy - 1) <= y + 1)
				{
					setcur(_coordx, _coordy);
					cout << start->age[j];
					++_coordx;
				}
				else
				{
					_coordx = 139;
					_coordy++;
				}
				++j;
			}
			if (start != NULL)
				start = start->next;

			//if (start != NULL)
				//start = start->next;
			y += 3;
			_coordy = y;
			x = 40;
			_coordx = x;
			j = 0;
		}
	}
}

void file_mas()
{
	char ch;
	//int k = 0 ;
	int x = 0;
	int y = 0;
	int a = 0, b = 0;
	int count = 0;
	//char mas[148][44] ;
	for (int y = 0; y < 40; ++y)
	{
		for (int x = 0; x < 108; ++x)
			menu[x][y] = ' ';
		//cout << endl;
	}
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	out = fopen("third_menu.txt", "rt");
	x = 0;
	y = 0;
	list_third_menu*start = new list_third_menu;
	beginning = start;
	if (out)
	{
		while (!feof(out))
		{
			ch = fgetc(out);
			if (ch != '\n' && x < 110)
			{
				start->mas[x] = ch;
				//setcur(x, y);
				++x;

			}
			else
			{
				while (ch != '\n')
				{
					ch = fgetc(out);
				}
				start->mas[x] = '\0';
				x = 0;
				//++y;
				list_third_menu*head = new list_third_menu;
				start->next = head;
				start = start->next;
			}
		}
		fclose(out);
		//return;
	}
}
void first_menu(int k)
{
	//char ch = 0;
	int x = 0, y = 0;
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	list_first_menu *start = new list_first_menu;
	setcur(0, 0);
	color(3);
	cout << start->outfile << endl;
	cout << start->infile << endl;
	//cout << start->add << endl;
	//cout << start->age << endl;
	cout << start->search << endl;
	cout << start->sort << endl;
	cout << start->del << endl;
	cout << start->alldel << endl;
	cout << start->exit << endl;
	output_list(please);
	switch (k)
	{
	case 0:
		color(4);
		setcur(0, 0);
		cout << start->outfile << endl;
		break;
	case 1:
		color(4);
		setcur(0, 1);
		cout << start->infile << endl;
		break;
	/*case 2:
		setcur(0, 2);
		color(4);
		cout << start->add << endl;
		break;
	case 3:
		setcur(0, 3);
		color(4);
		cout << start->age << endl;
		break;*/
	case 2:
		setcur(0, 2);
		color(4);
		cout << start->search << endl;
		break;
	case 3:
		setcur(0, 3);
		color(4);
		cout << start->sort << endl;
		break;
	case 4:
		setcur(0, 4);
		color(4);
		cout << start->del << endl;
		break;
	case 5:
		setcur(0, 5);
		color(4);
		cout << start->alldel << endl;
		break;
	case 6:
		setcur(0, 6);
		color(4);
		cout << start->exit << endl;
		break;
	}
	output_list(please);
}
void second_menu(int k)
{
	char ch = 0;
	int x = 0;
	int y = 19;
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	in = fopen("second_menu.txt", "wt");
	out = fopen("second_menu.txt", "rt");
	if (out)
	{
		while (!feof(out))
		{
			first_menu(k);
			ch = fgetc(out);
			if (ch != '\n' && x < 30 && y != k)
			{
				setcur(x, y);
				++x;
				if (k == y)
					color(4);
				else
					color(3);
				cout << ch;
			}
			else
			{
				while (ch != '\n')
				{
					ch = fgetc(out);
				}
				x = 0;
				++y;
			}
		}
		fclose(out);
		return;
	}
}
void third_menu(int k)
{
	int x_menu = 39;
	int y_menu = 3;
	char str[110];
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	int x = 0, y = 0;
	//while(y != 40)
	list_third_menu *start = beginning;
	while (y_menu != 43)
	{
		//while (x != 108)
		//{
		color(3);
		setcur(x_menu, y_menu);
		//cout << menu;
		cout << start->mas;
		//++x;
		//++x_menu;
	//}
	//x_menu = 39;
	//x = 0;
	//++y;
		++y_menu;
		start = start->next;
		//setcur(39, 3);
		//cout << endl;
	}
	//setcur(39, 3);
	//first_menu(k);
}
void data_menu()
{
	char ch;
	//int k = 0 ;
	int x = 39;
	int y = 3;
	int a = 0, b = 0;
	int count = 0, Length_struct = 11;
	void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);
	//in = fopen("second_menu.txt", "wt");
	out = fopen("third_menu.txt", "rt");
	if (out)
	{
		while (!feof(out))
		{
			ch = fgetc(out);
			if (ch != '\n' && x < 200)
			{
				setcur(x, y);
				++x;

				cout << ch;
			}
			else
			{
				while (ch != '\n')
				{
					ch = fgetc(out);
				}
				x = 39;
				++y;
			}
		}
		fclose(out);
		return;
	}
}
list*tail_search(list*start, int index)
{
	list*end;
	for (int i = 0; i < index; ++i)
		start = start->next;
	end = start;
	return end;
}
/*list*add_element(list*start, int x)
{
		list *temp = new list;
		list*tail = start;
		int i = 0;
		while (tail->next!=0)
		{
			tail = tail->next;
		}
		//list*tail=0;
		//temp->x = x;
		temp->next = NULL;
		Length++;
		if (!start) {
			temp->prev = NULL;
			start = temp;
			tail = start;
		}
		else {
			temp->prev = tail;                  //���������, ��� ���������� ��������� ������ ������������ ������������, ����� ��������� ������� ������������� ������
			tail->next = temp;                  //��������� �� ��������� ������������ ��� ��������������� ������ ����������� ������� ������
			tail = temp;                        //����� ���� ��� ������� ��� ���� ��������� � ��� ����������, ���������, ��� ��������� ������������ ��� ������ ��� ����������� �������
		}
		return start;
}*/
list* add_element(list * help, int index)
{
	list * element = new list;
	list*start = help;
	list*tail;
	if (!index || !start)
	{
		start->prev = element;
		element->next = start;
		element->prev = 0;
		start = element;
		Length++;
		Length_dell++;
		return start;
	}
	if (index == Length)
	{
		tail = tail_search(start, index - 1);
		tail->next = element;
		element->prev = tail;
		element->next = 0;
		tail = element;
		Length++;
		Length_dell++;
		return help;
	}
	int i = 0;
	while (i < index - 1)
	{
		help = help->next;
		++i;
	}
	list*beginning2 = help->next;
	help->next = element;
	element->next = beginning2;
	beginning2->prev = element;
	element->prev = help;
	Length++;
	Length_dell++;
	return start;
}

list* delete_element(list*start, unsigned index)
{
	list*tail;
	if (index >= Length)
		return start;
	list * element;
	if (!index &&Length > 1)
	{
		element = start->next;
		delete start;
		start = element;
		start->prev = 0;
		Length--;
		return start;
	}
	else if (!index && Length == 1)
	{
		start->next = 0;
		start = 0;
		delete start;
		Length--;
		return start;
	}
	else if ((index == Length - 1) && Length > 1)
	{
		tail = tail_search(start, index);
		element = tail->prev;
		element->next = 0;
		delete tail;
		tail = element;
		Length--;
		return start;
	}
	else
	{
		list*beginning;
		element = start;
		for (int i = 0; i < index; ++i)
			element = element->next;
		beginning = element;
		beginning->prev->next = element->next;
		element->next->prev = beginning->prev;
		delete element;
		Length--;
		return start;
	}
}
list* delete_list(list* next)
{
	list*start = next;
	while (start)
	{
		next = start->next;
		delete start;
		start = next;
	}
	int length = 0;
	return start;
}
int cursor_movenment(int x, int ex)
{
	if (x >= 40 && x < 100 && ex == _right)
	{
		x += 15;
		return x;
	}
	if (x >= 100 && x < 124 && ex == _right)
	{
		x += 8;
		return x;
	}
	/*if (x >= 147 && x < 154 && ex == _right)
	{
		x += 7;
		return x;
	}*/
	if (x > 40 && x <= 100 && ex == _left)
	{
		x -= 15;
		return x;
	}
	if (x > 100 && x <= 124 && ex == _left)
	{
		x -= 8;
		return x;
	}
	/*if (x > 147 && x <= 154 && ex == _left)
	{
		x -= 7;
		return x;
	}*/
	return x;
}
void cursor_point()
{
	color(7);
	cout << "|";
}
list*delete_some_element(list* start, int a, int b)
{
	list*element = start;
	list*curr;
	list*beg;
	list*tail = tail_search(start, Length);
	int count = 0;
	if (a == b)
	{
		if (a == 0)
			start = delete_element(start, a);
		else
			delete_element(start, a);
		return start;
	}
	else
		if (b + 1 - a == Length)
		{
			start = delete_list(start);
			return start;
		}
		else
		{
			while ((count) != a)
			{
				element = element->next;
				++count;
			}
			if (a == 0 && b < (Length - 1))
			{
				curr = 0;
				beg = element;
				while (count != b + 1)
				{
					beg = element->next;
					delete element;
					element = beg;
					++count;
					--Length;
				}
				beg->prev = curr;
				start = beg;
				return start;
			}
			else if (a != 0 && b == (Length - 1))
			{
				curr = element->prev;
				beg = element;
				while ((b - a + 1) != 0)
				{
					beg = element->next;
					delete element;
					element = beg;
					--b;
					--Length;
				}
				curr->next = element;
				tail = element;
				return start;
			}
			else if (a != 0 && b != (Length - 1))
			{
				curr = element->prev;
				beg = element;
				while (count != b + 1)
				{
					beg = element->next;
					delete element;
					element = beg;
					++count;
					--Length;
				}
				curr->next = beg;
				beg->prev = curr;
				return start;
			}
		}
	return start;
}
void output_sort_list(sort_list*start, int k)
{
	setlocale(0, "");
	int x = 40, y = 7, j = 0;
	int _coordx = x, _coordy = y;
	/*if (Length < 12)
		k = Length;
	else
		k = 12;*/
	for (int i = 0; i < k; ++i)
	{
		while (start != 0 && start->club[j] != '\0')
		{
			if (_coordx < 54 && (_coordy - 1) <= y + 1)
			{
				setcur(_coordx, _coordy);
				cout << start->club[j];
				++_coordx;
			}
			else
			{
				_coordx = 40;
				_coordy++;
			}
			++j;
		}
		x += 15;
		_coordx = x;
		_coordy = y;
		j = 0;
		while (start != 0 && start->name[j] != '\0')
		{
			if (_coordx < 69 && (_coordy - 1) <= y + 1)
			{
				setcur(_coordx, _coordy);
				cout << start->name[j];
				++_coordx;
			}
			else
			{
				_coordx = 55;
				_coordy++;
			}
			++j;
		}
		x += 15;
		_coordx = x;
		_coordy = y;
		j = 0;
		while (start != 0 && start->surname[j] != '\0')
		{
			if (_coordx < 84 && (_coordy - 1) <= y + 1)
			{
				setcur(_coordx, _coordy);
				cout << start->surname[j];
				++_coordx;
			}
			else
			{
				_coordx = 70;
				_coordy++;
			}
			++j;
		}
		x += 15;
		_coordx = x;
		_coordy = y;
		j = 0;
		while (start != 0 && start->patronymic[j] != '\0')
		{
			if (_coordx < 99 && (_coordy - 1) <= y + 1)
			{
				setcur(_coordx, _coordy);
				cout << start->patronymic[j];
				++_coordx;
			}
			else
			{
				_coordx = 85;
				_coordy++;
			}
			++j;
		}
		x += 15;
		_coordx = x;
		_coordy = y;
		j = 0;
		/*while (start != 0 && start->data[j] != '\0')
		{
			if (_coordx < 114 && (_coordy - 1) <= y + 1)
			{
				setcur(_coordx, _coordy);
				cout << start->data[j];
				++_coordx;
			}
			else
			{
				_coordx = 100;
				_coordy++;
			}
			++j;
		}
		x += 15;
		_coordx = x;
		_coordy = y;
		j = 0;*/
		while (start != 0 && start->number[j] != '\0')
		{
			if (_coordx < 107 && (_coordy - 1) <= y + 1)
			{
				setcur(_coordx, _coordy);
				cout << start->number[j];
				++_coordx;
			}
			else
			{
				_coordx = 100;
				_coordy++;
			}
			++j;
		}
		x += 8;
		_coordx = x;
		_coordy = y;
		j = 0;
		while (start != 0 && start->height[j] != '\0')
		{
			if (_coordx < 115 && (_coordy - 1) <= y + 1)
			{
				setcur(_coordx, _coordy);
				cout << start->height[j];
				++_coordx;
			}
			else
			{
				_coordx = 108;
				_coordy++;
			}
			++j;
		}
		x += 8;
		_coordx = x;
		_coordy = y;
		j = 0;
		while (start != 0 && start->weight[j] != '\0')
		{
			if (_coordx < 123 && (_coordy - 1) <= y + 1)
			{
				setcur(_coordx, _coordy);
				cout << start->weight[j];
				++_coordx;
			}
			else
			{
				_coordx = 116;
				_coordy++;
			}
			++j;
		}
		x += 8;
		_coordx = x;
		_coordy = y;
		j = 0;
		while (start != 0 && start->age[j] != '\0')
		{
			if (_coordx < 131 && (_coordy - 1) <= y + 1)
			{
				setcur(_coordx, _coordy);
				cout << start->age[j];
				++_coordx;
			}
			else
			{
				_coordx = 124;
				_coordy++;
			}
			++j;
		}
		if (start != NULL)
			start = start->next;
		y += 3;
		_coordy = y;
		x = 40;
		_coordx = x;
		j = 0;
	}
}

int movement_y_third_menu(int y_third_menu)
{
	int count = 0, y = 7;
	while (count != Length)
	{
		if (y == y_third_menu && count <= Length && Length != 1)
		{
			//setcur(0, 25);
			//Sleep(2500);
			//cout << "��� ���� ��� �������";
			return 0;
		}
		if (y_third_menu == y + 3 && count == Length - 1)
			return 1;
		if (y_third_menu > y + 3 && count == Length - 1)
		{
			setcur(0, 25);
			Sleep(2500);
			cout << "�������� ���� � " << Length + 1 << " ������";
			return 0;
		}
		y += 3;
		count++;
	}
	return 0;
}
void headline_menu(int k)
{
	list_third_menu*start = beginning->next;
	int i = 1, count = 0;
	int x_menu = 40;
	int y_menu = 4;
	switch (k)
	{
	case 0:
		while (count != 1)
		{
			if (start->mas[i] == '!')
			{
				count++;
				break;
			}
			else
			{
				setcur(x_menu, y_menu);
				color(4);
				cout << start->mas[i];
			}
			++i;
			++x_menu;
		}
		break;
	case 1:
		x_menu = 55;
		i = 16;
		while (count != 1)
		{
			if (start->mas[i] == '!')
			{
				count++;
				break;
			}
			else
			{
				setcur(x_menu, y_menu);
				color(4);
				cout << start->mas[i];
			}
			++i;
			++x_menu;
		}
		break;
	case 2:
		x_menu = 70;
		i = 31;
		while (count != 1)
		{
			if (start->mas[i] == '!')
			{
				count++;
				break;
			}
			else
			{
				setcur(x_menu, y_menu);
				color(4);
				cout << start->mas[i];
			}
			++i;
			++x_menu;
		}
		break;
	case 3:
		x_menu = 85;
		i = 46;
		while (count != 1)
		{
			if (start->mas[i] == '!')
			{
				count++;
				break;
			}
			else
			{
				setcur(x_menu, y_menu);
				color(4);
				cout << start->mas[i];
			}
			++i;
			++x_menu;
		}
		break;
	case 4:
		x_menu = 100;
		i = 61;
		while (count != 1)
		{
			if (start->mas[i] == '!')
			{
				count++;
				break;
			}
			else
			{
				setcur(x_menu, y_menu);
				color(4);
				cout << start->mas[i];
			}
			++i;
			++x_menu;
		}
		break;
	case 5:
		x_menu = 108;
		i = 69;
		while (count != 1)
		{
			if (start->mas[i] == '!')
			{
				count++;
				break;
			}
			else
			{
				setcur(x_menu, y_menu);
				color(4);
				cout << start->mas[i];
			}
			++i;
			++x_menu;
		}
		break;
	case 6:
		x_menu = 116;
		i = 77;
		while (count != 1)
		{
			if (start->mas[i] == '!')
			{
				count++;
				break;
			}
			else
			{
				setcur(x_menu, y_menu);
				color(4);
				cout << start->mas[i];
			}
			++i;
			++x_menu;
		}
		break;
	case 7:
		x_menu = 124;
		i = 85;
		while (count != 1)
		{
			if (start->mas[i] == '!')
			{
				count++;
				break;
			}
			else
			{
				setcur(x_menu, y_menu);
				color(4);
				cout << start->mas[i];
			}
			++i;
			++x_menu;
		}
		break;
	}
}
list* search_sort_list(list*start,list*head,int k)
{
	int i = 0;
	list*temp = start;
	temp->prev = 0;
	while (i < k)
	{
		temp->next =new list;
		temp->next = head;
		temp = temp->next;
		++i;
	}
	temp->next = NULL;
	//temp = head;
	//list*head = new list;
	//int i = 0;
	return start;
}
void search_list(list*start)
{
	setlocale(0, "");
	color(4);
	setcur(7, 13);
	cout << "�������� ����";
	char str[30];
	int ex = 0, count = 0, x = 0, k = 0, i = 0, x_menu = 40, y_menu = 7;
	while (count == 0)
	{
		third_menu(k);
		headline_menu(x);
		ex = _getch();
		switch (ex)
		{
		case _right:
			if (x < 8)
				x++;
			break;
		case _left:
			if (x > 0)
				x--;
			break;
		case _enter:
			setcur(2, 10);
			count = 1;
			break;
		case _esc:
			return;
		}
	}
	count = 0;
	setcur(7, 13);
	cout << "������� ��������";
	setcur(10, 14);
	while (count != 1)
	{
		cin.getline(str, 28);
		if (strlen(str) > 28 && x < 5)
		{
			cin.clear();
			cin.sync();
			Sleep(2500);
			cout << "������";
		}
		else
			if (strlen(str) > 16 && x > 4)
			{
				cin.clear();
				cin.sync();
				Sleep(2500);
				cout << "������";
			}
			else
				count = 1;
	}
	count = 0;
	k = 0;
	list*head = start;
	list*help = NULL;
	//list*temp = help;
	list*temp = new list;
	list*tail = 0;
	//head=creat_list(head, temp, Length);
	//struct list *head = malloc(sizeof(struct list));
	//struct list *help = malloc(sizeof(struct list));
	switch (x)
	{
	case 0:
		while (count < Length && head->next != NULL)
		{
			if (!strcmp(str, head->club))
			{
				head->c = 1;
				list_label = 1;
			}
			head = head->next;
		}
		if (list_label == 0)
		{
			cout<<"������ �������� ����";
		}
		output_list(start);
		break;
	case 1:
		while (count < Length && head->next != NULL)
		{
			if (!strcmp(str, head->name))
			{
				head->c = 1;
				list_label = 1;
			}
			head = head->next;
		}
		if (list_label == 0)
		{
			cout << "������ �������� ����";
		}
		output_list(start);
		break;
	case 2:
		while (count < Length && head->next != NULL)
		{
			if (!strcmp(str, head->surname))
			{
				head->c = 1;
				list_label = 1;
			}
			head = head->next;
		}
		if (list_label == 0)
		{
			cout << "������ �������� ����";
		}
		output_list(start);
		break;
	case 3:
		while (count < Length && head->next != NULL)
		{
			if (!strcmp(str, head->patronymic))
			{
				head->c = 1;
				list_label = 1;
			}
			head = head->next;
		}
		if (list_label == 0)
		{
			cout << "������ �������� ����";
		}
		output_list(start);
		break;
	case 4:
		while (count < Length && head->next != NULL)
		{
			if (!strcmp(str, head->number))
			{
				head->c = 1;
				list_label = 1;
			}
			head = head->next;
		}
		if (list_label == 0)
		{
			cout << "������ �������� ����";
		}
		output_list(start);
		break;
	case 5:
		while (count < Length && head->next != NULL)
		{
			if (!strcmp(str, head->height))
			{
				head->c = 1;
				list_label = 1;
			}
			head = head->next;
		}
		if (list_label == 0)
		{
			cout << "������ �������� ����";
		}
		output_list(start);
		break;
	case 6:
		while (count < Length && head->next != NULL)
		{
			if (!strcmp(str, head->weight))
			{
				head->c = 1;
				list_label = 1;
			}
			head = head->next;
		}
		if (list_label == 0)
		{
			cout << "������ �������� ����";
		}
		output_list(start);
		break;
	case 7:
		while (count < Length && head->next != NULL)
		{
			if (!strcmp(str, head->age))
			{
				head->c = 1;
				list_label = 1;
			}
			head = head->next;
		}
		if (list_label == 0)
		{
			cout << "������ �������� ����";
		}
		output_list(start);
		break;
	};
}


/*
void sort(list **begin)
{
	list *temp;
	list *temp1;
	list *tmp1;
	list *tmp2;
	list *tmp3;
	list *tmp4;
	list *tmp5;
	list *tmp6;
	temp1 = *begin;
	while (temp1) 
	{
		temp = temp1;
		while (temp) 
		{
			if (temp->next == NULL)
			{
			}
			else if (temp->next->next == NULL && strcmp(temp->club, temp->next->club))
			{
				tmp1 = temp->prev;
				tmp2 = temp;
				tmp3 = temp->next;
				tmp1->next = tmp3;
				tmp3->prev = tmp1;
				tmp3->next = tmp2;
				tmp2->prev = tmp3;
				tmp2->next = NULL;

			}
			else if (strcmp(temp->club,temp->next->club) && temp->next != NULL && temp->prev != NULL && temp != NULL) {
				tmp1 = temp->prev;
				tmp2 = temp;
				tmp3 = temp->next;
				tmp4 = temp->next->next;
				tmp1->next = tmp3;
				tmp4->prev = tmp2;
				tmp2->prev = tmp3;
				tmp2->next = tmp4;
				tmp3->prev = tmp1;
				tmp3->next = tmp2;

			}
			temp = temp->next;
		}
		temp1 = temp1->next;
	}
}
void sortfirst(list **begin, list **Last) {

	list *temp;
	list *temp1;
	list *tmp1;
	list *tmp2;
	list *tmp3;
	bool flag = true;
	temp = *begin;
	temp1 = *begin;
	while (temp && flag) {
		if (strcmp(temp->club, temp1->club))
		{
			*begin = temp1->next;
			tmp1 = *begin;
			tmp1->prev = NULL;
			temp1->prev = temp->prev;
			temp1->next = temp;
			temp->prev = temp1;
			tmp1 = temp->prev;
			tmp1->next = temp1;
			flag = false;
			break;
		}
		temp = temp->next;
	}
}*/
list* sort_replacement(list*left, list*right, int k)
{
	list *temp =new list;
	memcpy(temp->club, left->club, sizeof(temp->club));
	memcpy(left->club, right->club, sizeof(left->club));
	memcpy(right->club, temp->club, sizeof(right->club));
	list*q = right;
	memcpy(temp->name, left->name, sizeof(temp->name));
	memcpy(left->name, right->name, sizeof(left->name));
	memcpy(right->name, temp->name, sizeof(right->name));
	memcpy(temp->surname, left->surname, sizeof(temp->surname));
	memcpy(left->surname, right->surname, sizeof(left->surname));
	memcpy(right->surname, temp->surname, sizeof(right->surname));
	memcpy(temp->patronymic, left->patronymic, sizeof(temp->patronymic));
	memcpy(left->patronymic, right->patronymic, sizeof(left->patronymic));
	memcpy(right->patronymic, temp->patronymic, sizeof(right->patronymic));
	memcpy(temp->number, left->number, sizeof(temp->number));
	memcpy(left->number, right->number, sizeof(left->number));
	memcpy(right->number, temp->number, sizeof(right->number));
	memcpy(temp->height, left->height, sizeof(temp->height));
	memcpy(left->height, right->height, sizeof(left->height));
	memcpy(right->height, temp->height, sizeof(right->height));
	memcpy(temp->weight, left->weight, sizeof(temp->weight));
	memcpy(left->weight, right->weight, sizeof(left->weight));
	memcpy(right->weight, temp->weight, sizeof(right->weight));
	memcpy(temp->age, left->age, sizeof(temp->age));
	memcpy(left->age, right->age, sizeof(left->age));
	memcpy(right->age, temp->age, sizeof(right->age));
	return q;
}
list* list_sort(list*start)
{
	list *left = start;
	list *right = start->next;
	list *temp = new list;
	setlocale(0, "");
	color(4);
	setcur(7, 13);
	cout << "�������� ����";
	char str[30];
	int ex = 0, count = 0, z=0,x = 0, i = 0, k=0,x_menu = 40, y_menu = 7;
	while (count == 0)
	{
		third_menu(z);
		headline_menu(k);
		ex = _getch();
		switch (ex)
		{
		case _right:
			if (k < 7)
				k++;
			break;
		case _left:
			if (k > 0)
				k--;
			break;
		case _enter:
			setcur(2, 10);
			count = 1;
			break;
		case _esc:
			return 0;
		}
	}
	count = 0;
	//count = 0;
	//k = 0;
	//list*temp = NULL;
	list*head = NULL;
	//head=creat_list(head, temp, Length);
	temp = head;
	list*help = start;
	while (left->next)
	{
		while (right)
		{
			if (strcmp(left->club, right->club) < 0 && k == 0)
			{
				right = sort_replacement(left, right, 1);
			}
			if (strcmp(left->name, right->name) < 0 && k == 2)
			{
				right = sort_replacement(left, right, 3);
			}
			if (strcmp(left->surname, right->surname) < 0 && k == 1)
			{
				right = sort_replacement(left, right, 2);
			}
			if (strcmp(left->patronymic, right->patronymic) < 0 && k == 3)
			{
				right = sort_replacement(left, right, 4);
			}
			if (strcmp(left->number, right->number) < 0 && k == 4)
			{
				right = sort_replacement(left, right, 5);
			}
			if (strcmp(left->height, right->height) < 0 && k == 5)
			{
				right = sort_replacement(left, right, 6);
			}
			if (strcmp(left->weight, right->weight) < 0 && k == 6)
			{
				right = sort_replacement(left, right, 7);
			}
			if (strcmp(left->age, right->age) < 0 && k == 7)
			{
				right = sort_replacement(left, right, 8);
			}
			right = right->next;
		}
		left = left->next;
		right = left->next;
	}
	output_list(start);
	return start;
}

void input_sort()
{
	int ex = 0, count = 0, x = 0, k = 0, i = 0;
	//char mas[200] = consider_sort();
	while (count == 0)
	{
		ex = _getch();
		switch (ex)
		{
		case _right:
			if (x < 11)
				x++;
			break;
		case _left:
			if (x > 0)
				x--;
			break;
		case _enter:
			setcur(2, 10);
			//cout << _sort->in_alphabetical_order;
			setcur(2, 11);
			//cout << _sort->not_in_alphabetical_order;
			count = 1;
		case _esc:
			return;
		}
	}
}

void SaveToFile(list*start)
{
	if (Length == 0)
	{
		cout << "�����.�������� ���� ������.";
		return;
	}
	in = fopen("data3.txt", "wb");
	if (!in)
	{
		cout << "�� ������� ������� ����!";
		return;
	}
	list *temp = start;
	for (int i = 0; i < Length; i++)
	{
		fwrite(temp, sizeof(struct list), 1, in);
		temp = temp->next;
	}
	fclose(in);
	//setcur(0, 10);
	//cout << "������ ��������� � ���� <<data.txt>>";
	Sleep(2500);
	//return start;
}
list* ReadFromFile(list*start)
{
	int count = 1;
	out = fopen("data3.txt", "rb");
	if (!out)
	{
		cout << "�� ������� ������� ����!";
		return start;
	}
	fseek(out, 0, SEEK_END);
	Length = ftell(out);
	if (Length == 0)
	{
		cout << "���� ����!";
		return start;
	}
	Length /= sizeof(struct list);
	list*tail = start;
	list *temp = creat_list(start, 0, Length);
	start = temp;
	fseek(out, 0, SEEK_SET);
	for (int i = 0; i < Length; i++)
	{
		fread(&temp->club, sizeof(char[30]), 1, out);
		fread(&temp->surname, sizeof(char[30]), 1, out);
		fread(&temp->name, sizeof(char[30]), 1, out);
		fread(&temp->patronymic, sizeof(char[29]), 1, out);
		//fread(&temp->data, sizeof(char[30]), 1, out);
		fread(&temp->number, sizeof(char[16]), 1, out);
		fread(&temp->height, sizeof(char[16]), 1, out);
		fread(&temp->weight, sizeof(char[16]), 1, out);
		fread(&temp->age, sizeof(char[16]), 1, out);
		//fread(&temp->amplua.mas, sizeof(char(14)), 1, out);
		//fread(&temp->minutes, sizeof(char(14)), 1, out);
		temp = temp->next;
		fseek(out, count * sizeof(struct list), SEEK_SET);
		count++;
	}
	fclose(out);
	output_list(start);
	return start;
}

void movement_list(list*start, int x, int y, char ex)
{
	setlocale(0, "");
	int y_list = 7, x_list = 40, count = -1, k = 0, i = 0, a = 12;
	list*head = start;
	//ex = ex - '48';
	/*if (Length_add > 0)
	{
		while (a != Length_add )
		{
			y_list += 3;
			++a;
		}
	}*/
	/*if (Length > 12)
	{
		while (a != Length)
		{
			y_list += 3;
			++a;
		}
	}*/
	while (y_list != y)
	{
		if (y_list < y)
		{
			head = head->next;
			y_list += 3;
		}
		/*if (y_list > y)
		{
			head = head->prev;
			y_list -= 3;
		}*/
	}
	if (x == 40 && x_list == 40)
		count = 1;
	while (x_list < x)
	{
		if (x >= 40 && x < 115)
		{
			if (count == -1)
				count = 1;
			x_list += 15;
			count++;
		}
		if (x >= 115 && x < 147)
		{
			if (count == -1)
			{
				x_list = 107;
				count = 5;
			}
			x_list += 8;
			count++;
		}
	}
	switch (count)
	{
	case 1:
		while ((head->club[i]) != '\0'&& i < 28)
		{
			++i;
		}
		if ((ex>='�'&&ex<='�')||(ex >= '�'&&ex <= '�'))
		{
			head->club[i] = ex;
			head->club[i + 1] = '\0';
		}
			break;
	case 3:
		while ((head->name[i]) != '\0'&& i < 28)
		{
			++i;
		}
		if ((ex >= '�'&&ex <= '�') || (ex >= '�'&&ex <= '�'))
		{
			head->name[i] = ex;
			head->name[i + 1] = '\0';
		}
		break;
	case 2:
		while ((head->surname[i]) != '\0'&& i < 28)
		{
			++i;
		}
		if ((ex >= '�'&&ex <= '�') || (ex >= '�'&&ex <= '�'))
		{
			head->surname[i] = ex;
			head->surname[i + 1] = '\0';
		}
		break;
	case 4:
		while ((head->patronymic[i]) != '\0'&& i < 28)
		{
			++i;
		}
		if ((ex >= '�'&&ex <= '�') || (ex >= '�'&&ex <= '�'))
		{
			head->patronymic[i] = ex;
			head->patronymic[i + 1] = '\0';
		}
		break;
	case 5:
		while ((head->number[i] != '\0' && i < 14))
		{
			++i;
		}
		if (ex>='0'&&ex<='9')
		{
			head->number[i] = ex;
			head->number[i + 1] = '\0';
		}
		break;
	case 6:
		while (i < strlen(head->height) && i < 14)
		{
			++i;
		}
		if (ex >= '0'&&ex <= '9')
		{
			head->height[i] = ex;
			head->height[i + 1] = '\0';
		}
		break;
	case 7:
		while ((head->weight[i]) != '\0'&& i < 14)
		{
			++i;
		}
		if (ex >= '0'&&ex <= '9')
		{
			head->weight[i] = ex;
			head->weight[i + 1] = '\0';
		}
		break;
	case 8:
		while ((head->age[i]) != '\0'&& i < 14)
		{
			++i;
		}
		if (ex >= '0'&&ex <= '9')
		{
			head->age[i] = ex;
			head->age[i + 1] = '\0';
		}
		break;
	}
	output_list(start);
}
void redactor(list*start, int x, int y)
{
	setlocale(0, "");
	int y_list = 7, x_list = 40, count = -1, k = 0, i = 0, a = 12;
	list*head = start;
	sort_list begin[100];
	//ex = ex - '48';
	/*if (Length_add > 0)
	{
		while (a != Length_add )
		{
			y_list += 3;
			++a;
		}
	}*/
	/*if (Length > 12)
	{
		while (a != Length)
		{
			y_list += 3;
			++a;
		}
	}*/
	while (y_list != y)
	{
		if (y_list < y)
		{
			head = head->next;
			y_list += 3;
		}
		/*if (y_list > y)
		{
			head = head->prev;
			y_list -= 3;
		}*/
	}
	if (x == 40 && x_list == 40)
		count = 1;
	while (x_list < x)
	{
		if (x >= 40 && x < 115)
		{
			if (count == -1)
				count = 1;
			x_list += 15;
			count++;
		}
		if (x >= 115 && x < 147)
		{
			if (count == -1)
			{
				x_list = 107;
				count = 5;
			}
			x_list += 8;
			count++;
		}
	}
	switch (count)
	{
	case 1:
		while ((head->club[i]) != '\0'&& i < 28)
		{
			++i;
		}
		head->club[i - 1] = '\0';
		break;
	case 2:
		while ((head->surname[i]) != '\0'&& i < 28)
		{
			++i;
		}
		head->surname[i - 1] = '\0';
		break;
	case 3:
		while ((head->name[i]) != '\0'&& i < 28)
		{
			++i;
		}
		head->name[i - 1] = '\0';
		break;
	case 4:
		while ((head->patronymic[i]) != '\0'&& i < 28)
		{
			++i;
		}
		head->patronymic[i - 1] = '\0';

		break;
		/*case 5:
			while ((head->data[i]) != '\0'&& i < 28)
			{
				++i;
			}
			head->data[i - 1] = '\0';

			break;*/
	case 5:
		while ((head->number[i] != '\0' && i < 14))
		{
			++i;
		}
		head->number[i - 1] = '\0';

		break;
	case 6:
		while (i < strlen(head->height) && i < 14)
		{
			++i;
		}
		head->height[i - 1] = '\0';

		break;
	case 7:
		while ((head->weight[i]) != '\0'&& i < 14)
		{
			++i;
		}
		head->weight[i - 1] = '\0';

		break;
	case 8:
		while ((head->age[i]) != '\0'&& i < 14)
		{
			++i;
		}
		head->age[i - 1] = '\0';

		break;
	}
	output_list(start);
}

void control()
{
	setlocale(0, "");
	char mas[120][30];
	int count = 0, input_label = 0, count_Length_add = 0, y_Length_add = 7, help_Length_add = 0, str, ex1;
	char ex = 0;
	int x = 40, y_first_menu = 0, flag = 0, y_third_menu = 7, y_add_menu = 40, input_header, input_string[50], k = 0;
	list*start = NULL, *tail = NULL, *help = start;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (count == 0)
	{
		setcur(0, 0);
		if (flag == 0)
			output_list(help);
		first_menu(y_first_menu);
		third_menu(y_first_menu);
		if (flag == 1)
		{
			setcur(x, y_third_menu);
			cursor_point();
			output_list(help);
		}
		ex1 = _getch();
		if (ex1 != 224)
			ex = ex1;
		else
		{
			ex = _getch();
			if (ex == _up || ex == _down || ex == _right || ex == _left || ex == _enter || ex == _esc || ex == _space || ex == _backspace)
				ex1 = ex;
			else
				ex = ex1;
		}
		switch (ex1)
		{
		case _up:
			if (y_first_menu > 0 && flag == 0)
			{
				y_first_menu--;
				output_list(start);
			}
			else
			{
				if (y_third_menu > 7 && y_third_menu != 40 && flag != 0)
				{
					count_Length_add = 0;
					y_Length_add = 7;
					y_third_menu -= 3;
					setcur(x, y_third_menu);
					cursor_point();
					output_list(help);
					if (k_Length_add == 0 && help->prev != 0)
						help = help->prev;
					if (k_Length_add > 0)
						k_Length_add--;
				}
				else
				{
					if (y_third_menu == 40 && y_add_menu > 40 && Length >= 12 && flag != 0)
					{

						if (k_Length_add == 0 && help->prev != 0)
							help = help->prev;
						if (k_Length_add > 0)
							k_Length_add--;

						y_add_menu -= 3;
						//setcur(x, y_third_menu);
						output_list(help);
					}
					else
					{
						if (y_third_menu == 40 && y_add_menu == 40 && flag != 0)
						{
							y_third_menu -= 3;
							if (k_Length_add == 0 && help->prev != 0)
								help = help->prev;
							if (k_Length_add > 0)
								k_Length_add--;
							output_list(help);
						}
					}
				}
			}
			break;
		case _down:
			if (y_first_menu != 6 && flag == 0)
			{
				y_first_menu++;
				output_list(start);
			}
			else
			{
				if (y_third_menu != 40 && flag != 0)
				{
					y_third_menu += 3;
					setcur(x, y_third_menu);
					cursor_point();
					output_list(help);
					//if (k_Length_add != 100)
					//	k_Length_add++;
				}
				else
				{
					if (y_third_menu == 40 && flag != 0 && Length >= 12 && y_add_menu < 304)
					{
						if (y_add_menu == 40)
							k_Length_add = 11;
						if (k_Length_add < 11 && y_add_menu >= 40)
							k_Length_add++;
						if (k_Length_add == 11 && y_add_menu >= 40 && help->next != 0)
							help = help->next;
						y_add_menu += 3;
						Length_add++;
						setcur(x, y_third_menu);
						output_list(help);
					}
				}
			}
			break;
		case _right:
			if (y_first_menu != -1)
			{
				k = y_first_menu;
				output_list(help);
			}
			y_first_menu = -1;
			if (x == 40 && y_third_menu == 7 && flag == 0)
			{
				setcur(x, y_third_menu);
				flag = 1;
				//color(4);
				//cout << "|";
				//cursor();
			}
			else
			{
				if (flag == 1)
				{
					//x += 21;
					x = cursor_movenment(x, ex);
					setcur(x, y_third_menu);
					//color(4);
					//cout << "|";
					//cursor();
				}
			}
			break;
		case _left:
			if (x > 40 && flag == 1)
			{
				//x -= 21;
				x = cursor_movenment(x, ex);
				setcur(x, y_third_menu);
				//color(4);
				//cout << "|";
				//cursor();
			}
			else
			{
				if (flag == 1)
				{
					y_first_menu = k;
					y_third_menu = 7;
					flag = 0;
				}
			}
			break;
		case _space:
		{
			if (flag == 0)
			{
				second_menu(y_first_menu);
				int i = 0, y_second_menu = 19;
				while (i != _enter)
				{
					second_menu(y_second_menu);
					i = _getch();
					switch (i)
					{
					case _down:
						if (y_second_menu > 18)
							y_second_menu--;
						break;
					case _up:
						if (y_second_menu != 21)
							y_second_menu++;
						break;
					}
				}
			}
			break;
		}
		case _enter:
			char pop[50];
			//if (flag == 0)
				//count = 1;
			if (flag == 0 && y_first_menu == 0)
			{
				start = ReadFromFile(start);
				help = start;
			}
			if (flag == 0 && y_first_menu == 1)
			{
				SaveToFile(start);
				output_list(help);
			}
			if (flag == 0 && y_first_menu == 2&&Length>0)
				search_list(start);
			if (flag == 0 && y_first_menu == 3 && Length>0)
			{
				//help = list_sort(start);
				//sort(&start);
				//sortfirst(&start, &tail);
				start=list_sort(start);
				help = start;
				output_list(help);
			}
			if (flag == 0 && y_first_menu == 4)
			{
				if (Length > 0)
				{
					int z = 0;
					setcur(0, 15);
					cout << "������� ����� ������";
					setcur(0, 16);
					cout << "������� ������ �������";
					setcur(5, 17);
					while (true)
					{
						cin.getline(pop, 50);
						if (is_digit(pop) && atof(pop) < 46) {
							break;
						}
						else {
							cout << "������!\n��������� ����:";
							continue;
						}
					}
					setcur(0, 0);
					help = delete_element(start, atof(pop));
					output_list(start);
				}
				else
					cout << "�������� ����!";
			}
			if (flag == 0 && y_first_menu == 5&&Length>0)
			{
				help = delete_list(start);
				start = NULL;
				setcur(2, 15);
				Sleep(2500);
				cout << "���� �������";
				//output_list(start);
				//y_first_menu = ;
				setcur(2, 15);
			}
			if (flag == 0 && y_first_menu == 6)
				break;
			break;
		case _esc:
			exit_control = false;
			return;
		case _backspace:
			if (flag == 1)
			{
				if (y_third_menu == 40 && y_add_menu > 40)
					redactor(start, x, y_add_menu);
				if (y_third_menu <= 40 && y_add_menu == 40)
					redactor(start, x, y_third_menu);
			}
			break;
		default:
			if (((ex >= 'A' &&ex <= 'Z') || (ex >= 'a'&&ex <= 'z') || (ex >= '�'&&ex <= '�') || (ex >= '�' && ex <= '�') || (ex >= '0'&&ex <= '9') || (ex == ':')) && (flag == 1))
			{
				if (Length == 0 && y_third_menu == 7)
				{
					Length = 1;
					start = creat_list(start, tail, Length);
					help = start;
					please = start;
				}
				else
				{
					if (Length == 0 && y_third_menu != 7)
					{
						y_third_menu = 7;
						setcur(0, 10);
						cout << "������� ��������� � ������ ������";
					}
				}
				if (y_third_menu == 40 && y_add_menu > 40)
				{
					if (movement_y_third_menu(y_add_menu))
					{
						add_element(start, Length);
					}
					movement_list(start, x, y_add_menu, ex);
				}
				if (y_third_menu <= 40 && y_add_menu == 40)
				{
					if (movement_y_third_menu(y_third_menu))
					{
						add_element(start, Length);
					}
					movement_list(start, x, y_third_menu, ex);
				}
			}

		}
		//setcur(0, 0);
	}
	if (flag == 0)
	{
		switch (y_first_menu)
		{


		}
	}
	else
	{

	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, 0);
	char mas[120][30];
	int length = 3;
	int c = sizeof(list);
	file_mas();
	while (exit_control)
	{
		control();
	}
	system("pause");
	return 0;
}