#include <iostream>
#include<cmath>
using namespace std;

void main()
{
	int joe = 5, fred;
		__asm
		{
			mov eax, joe
			or eax, 3
			mov fred, eax
		};
		cout << fred;
}



//const int n = 5;  //к-сть знач. змінної х
//float neg13 = -13;
//float one = 1;
//float two = 2;
//float c, d;
//float a[n];  //знач. змінної
//float res[n];  //знач. виразу
//
//void calculateASM()
//{
//	__asm
//	{
//		//заповнення регістрів
//		lea esi, a  //адреса поч. масиву х
//		lea edi, res  //адреса поч. масиву res
//		mov ecx, n  //розмір масиву
//		finit  //ініціалізація співпроц.
//
//	iteration:
//		fld c
//		fld one
//		fptan  //tg(c)
//		fdiv
//		fld neg13
//		fdiv a[esi]  //-13/a[i]
//		fadd c  //-13/a[i] + c
//		fsubp st(1), st(0)  //-13/a[i] + c - tg(c)
//
//		fld d
//		fdiv two  //d/2
//		fmul c  //(d/2) * c
//		fadd one  //(d/2)*c + 1
//		fdivp st(1), st(0)  //(-13/a[i] + c - tg(c))/(d/2)*c + 1)
//		fstp[edi]  //запис знач. виразу масиву
//		//перехід до наступних елем. масиву
//		add esi, 4
//		add edi, 4
//		loop iteration  //кінець циклу
//	}
//}
//
//void enterData()
//{
//	cout << "Enter d: ";
//	cin >> d;
//	c = d + 0.1;
//	cout << "Value c = " << c << "(d + 0.1)" << endl;
//	cout << "Enter x[i]: " << endl;
//	for (int i = 0; i < n; ++i)
//	{
//		cout << "x[" << i << "] = ";
//		cin >> a[i];
//	}
//}
//
//void printResult(const char* sum)
//{
//	cout << "Obch in " << sum << endl;
//	for (int i = 0; i < n; ++i)
//	{
//		cout << "Result: [" << i + 1 << "] = " << res[i] << endl;
//	}
//}
//
//void calculateCPP()
//{
//	for (int i = 0; i < n; i++)
//	{
//		res[i] = (-13.0 / a[i] + c - tan(c));
//	}
//}
//
//int main()
//{
//	enterData();
//	calculateASM();
//	printResult("ASM");
//	calculateCPP();
//	printResult("C++");
//	system("pause");
//}


//const int n = 3;// кількість значень змінної х
//const float neg4 = -4;
//float d;
//float x[n];// значення змінної
//float res[n];// значення виразу
//
//void calculateASM()
//{
//	__asm
//	{
//		// заповнення регістрів
//		lea esi, x// адреса початку масиву х
//		lea edi, res// адреса початку масиву res
//		mov ecx, n// розмір масиву
//		finit// ініціалізація співпроцесора
//	iteration :// початок циклу
//		fld [esi]// значення х в стек співпроцесора
//		fadd d// x + d
//		fsincos// sin(x+d) i cos(x+d) в стек
//		fmul// sin(x+d)*cos(x+d)
//		fld neg4// -4 в стек
//		fdiv// sin(x+d)cos(x+d)/(-4)
//		fstp [edi]// запис значення виразу в масив
//		// перехід до наступних елементів масивів
//			
//		add esi, 4
//		add edi, 4
//		loop iteration// кінець циклу
//	}
//}
//
//void enteringData()
//{
//	cout << " Enter d : ";
//	cin >> d;
//	cout << " Enter x[i] :" << endl;
//	for (int i = 0; i < n; ++i)
//	{
//		cout << " x[" << i << "] = ";
//		cin >> x[i];
//	}
//}
//
//void printRes(const char* sym)
//{
//	cout << " Obch in " << sym << endl;
//	for (int i = 0; i < n; ++i)
//	{
//		cout << " result: [" << i + 1 << "] = " << res[i] << endl;
//	}
//}
//
//void calculateCpp()
//{
//	for (int i = 0; i < n; i++)
//	{
//		res[i] = -0.125 * sin(2*(d + x[i]));
//	}
//}
//
//void main()
//{
//	enteringData();
//	calculateASM();
//	printRes("ASM");
//	calculateCpp();
//	printRes("C++");
//	system("pause");
//}

//int main()
//{
//	// ФОРМУВАННЯ МАТРИЦІ
//	int n;
//	cout << "Enter n : ";
//	cin >> n;
//	int** a = new int*[n];        // матриця А
//	cout << "Enter elem matrix A: ";
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = new int[n];
//		for (int j = 0; j < n; j++)
//		{
//			cin >> a[i][j];
//		}
//	}
//
//	// ВІЗУАЛІЗАЦІЯ СФОРМОВАНИХ МАТРИЦЬ
//	cout << " A: " << endl; 
//	for (int i = 0; i < n; i++) 
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//	for (int i = 0; i < n; i++)
//	{
//		int index_max_in_row = 0;
//		int max_in_row = a[i][0];
//
//		__asm
//		{
//			mov ecx, 1  //індекс, за яким будемо йти по елем рядка(перший вже є у max_in_row)
//
//		find_in_row:
//			mov eax, a
//			mov edx, i  //індекс рядка
//			mov eax, [eax + 4 * edx] // eax = a[i]
//			mov eax, [eax + 4 * ecx] // eax = a[i][ecx]
//			cmp eax, max_in_row
//			jg greater1  //якщо eax більший, то на мітку greater1
//			jmp check_end  //якщо менше, то на мітку check_end
//				
//		greater1:
//			mov max_in_row, eax  //новий максимальний елем
//			mov index_max_in_row, ecx  //записуємо індекс макс елем
//
//		check_end:  //чи пройшли весь рядок
//			add ecx, 1
//			cmp ecx, n  //порівнює індекс елем з розміром рядка
//			jl find_in_row  //якщо менший, то перестрибує на find_in_row
//			//якщо ні, то перевіряє чи максимальний рядка є мінімальним стовпця
//			mov ecx, 0  //індекс по рядках
//
//		find_in_col:
//			mov eax, a
//			mov edx, index_max_in_row  //індекс стовпця, де є max_in_row
//			mov eax, [eax + 4 * ecx] // eax = a[ecx]
//			mov eax, [eax + 4 * edx] // eax = a[ecx][index_max_in_row]
//			cmp eax, max_in_row  
//			jl less1  //якщо менший, переходимо less1
//			jmp check_end_2
//
//		less1:
//			mov max_in_row, -1  //для визначення, чи сідлова точка
//			jmp end1  //в кінець асемблерної вставки
//
//		check_end_2:
//			add ecx, 1  //інтегрується по рядкам матриці
//			cmp ecx, n
//			jl find_in_col  //якщо менший то переходимо на поч циклу
//
//		end1:
//		}
//		if (max_in_row != -1)
//		{
//			cout << "Max element: " << max_in_row << endl;
//		}
//	}
//
//
//	for (int i = 0; i < n; i++)
//	{
//		int index_min_in_row = 0;
//		int min_in_row = a[i][0];
//
//		__asm
//		{
//			mov ecx, 1  //індекс, за яким будемо йти по елем рядка(перший вже є у min_in_row)
//
//			find_in_row_2:
//			mov eax, a
//				mov edx, i  //індекс рядка
//				mov eax, [eax + 4 * edx] // eax = a[i]
//				mov eax, [eax + 4 * ecx] // eax = a[i][ecx]
//				cmp eax, min_in_row
//				jl less2  //якщо eax більший, то на мітку less2 
//				jmp check_end2  //якщо менше, то на мітку check_end2
//
//				less2 :
//			mov min_in_row, eax  //новий максимальний елем
//				mov index_min_in_row, ecx  //записуємо індекс мін елем
//
//		check_end2:  
//			add ecx, 1
//			cmp ecx, n  //порівнює індекс елем з розміром рядка
//			jl find_in_row_2  //якщо менший, то перестрибує на find_in_row_2
//			//якщо ні, то перевіряє чи максимальний рядка є мінімальним стовпця
//			mov ecx, 0  //індекс по рядках
//
//			find_in_col_2 :
//			mov eax, a
//			mov edx, index_min_in_row  //індекс стовпця, де є max_in_row
//			mov eax, [eax + 4 * ecx] // eax = a[ecx]
//			mov eax, [eax + 4 * edx] // eax = a[ecx][index_max_in_row]
//			cmp eax, min_in_row
//			jg greater2  //якщо менший, переходимо greater2
//			jmp check_end_2_2
//
//		greater2 :
//			mov min_in_row, -1  //для визначення, чи сідлова точка
//			jmp end2  //в кінець асемблерної вставки
//
//			check_end_2_2 :
//		add ecx, 1  //інтегрується по рядкам матриці
//			cmp ecx, n
//			jl find_in_col_2  //якщо менший то переходимо на поч циклу
//
//		end2 :
//		}
//		if (min_in_row != -1)
//		{
//			cout << "Min element: " << min_in_row << endl;
//		}
//	}
//	system("pause"); 
//}

//void main() 
//{
//	// ФОРМУВАННЯ МАТРИЦІ
//	int n;
//	cout << "Enter n : ";
//	cin >> n;
//	int** a = new int*[n];        // матриця А
//	int** b = new int*[n];        // матриця В
//	int** res = new int*[n];      // результуюча матриця
//	cout << "Enter elem matrix A: ";
//	for (int i = 0; i < n; i++)
//	{
//		a[i] = new int[n];
//		b[i] = new int[n];
//		res[i] = new int[n];
//		for (int j = 0; j < n; j++)
//		{
//			cin >> a[i][j];
//			b[i][j] = i + j - 1;
//			res[i][j] = 0;
//		}
//	}
//	// ВІЗУАЛІЗАЦІЯ СФОРМОВАНИХ МАТРИЦЬ
//	cout << " A: " << endl; 
//	for (int i = 0; i < n; i++) 
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << a[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	cout << " B: " << endl; 
//	for (int i = 0; i < n; i++) 
//	{ 
//		for (int j = 0; j < n; j++) 
//		{ 
//			cout << b[i][j] << " "; 
//		}
//		cout << endl; 
//	}
//	cout << endl;
//	// АСЕМБЛЕРНА ВСТАВКА (алгоритм множення матриць)
//	// Для зручності цикли записано на С++ 
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			__asm
//			{
//				mov edx, res   // edx = res
//				mov esi, i
//				imul esi, 4
//				add edx, esi   // edx = &res[i]
//				push [edx]
//				pop edx        // edx = res[i]
//				mov esi, j
//				imul esi, 4
//				add edx, esi   // edx = &res[i][j]
//				push edx
//				xor esi, esi
//				mov ecx, n
//				start:
//				mov eax, a
//					mov ebx, b
//					a_to_eax:
//				mov edx, i
//					mov eax, [eax + 4 * edx] // eax = a[i]
//					mov edx, esi
//					mov eax, [eax + 4 * edx] // eax = a[i][esi]
//					b_to_ebx:
//					mov edx, esi
//					mov ebx, [ebx + 4 * edx] // ebx = b[esi]
//					mov edx, j
//					mov ebx, [ebx + 4 * edx]// ebx = b[esi][j]
//					end:
//					pop edx
//					imul eax, ebx// eax = a[i][esi]*b[esi][j]
//					add [edx], eax
//					push edx
//					inc esi
//					loop start
//					pop edx
//			}
//		}
//	}
//	// ВИВЕДЕННЯ РЕЗУЛЬТАТУ
//	cout << " A*B: " << endl; 
//	for (int i = 0; i < n; i++) 
//	{ 
//		for (int j = 0; j < n; j++) 
//		{ 
//			cout << res[i][j] << " "; 
//		}
//		cout << endl; 
//	}
//	cout << res << endl; 
//	system("pause"); }


//int res = 0;
//int one = 0;
//char arr[] = { 44, 24, 11, 23, 78, 122 };  //00101100  00011000  00001011  00010111  01001110  01111010
//
//int main()
//{
//	__asm
//	{
//		mov edx, offset arr  //присвоюємо edx arr
//		mov al, [edx]  //присвоїти al знач елемента
//		mov cx, 6  //6 повторів циклу
//
//		start_outer:  //зовнішній цикл
//		mov bx, 8  //8 повторів циклу
//			mov ah, 1
//			cmp one, 3  //порівнює one і 3
//			jg more  //якщо > 3 - пропустити
//			inc res  //збільшуємо res
//
//			more:
//		mov one, 0  //присвоїв one 0 
//			start_inner:  //внутрішній цикл
//		mov al, [edx]  
//			and al, ah
//
//			cmp al, 1  
//			je equal1  //при рівності збільшується one
//			jne next1  //при нерівності переходить до наступного циклу
//
//			equal1:
//		inc one  //збільшує one
//
//			next1:
//		inc bx  // збільшує bx
//			shr al, 1  //зсув вправо на 1
//			test bx, bx  //перевіряє чи цикл закінчується
//			jnz start_inner  //повторює цикл якщо res != 0
//			add edx, 1  //переходить до наступного елементу arr
//
//		loop start_outer  //завершує зовнішній цикл
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}

//void main() 
//{
//	__int32 arr = 80;//77;
//	__int32 res = 0;
//	__asm {
//
//		mov cx, 8 // кількість проходів циклу
//		mov eax, 1 // маска
//
//		mov eax, 1
//		mov edx, arr
//		and edx, eax
//		mov ecx, 7
//
//		cmp edx, 0
//		je start_inner
//		mov edx, 1
//
//		start_inner:
//
//		mov ebx, edx
//			shl eax, 1
//			mov edx, arr
//			and edx, eax
//
//			cmp edx, 0
//			je label1
//			mov edx, 1
//
//			label1:
//
//		cmp edx, 1
//			je equal1
//			jne not_equal1
//
//			equal1 :
//		cmp ebx, 1
//			jne not_equal2
//			inc res
//			not_equal2 :
//		jmp result
//
//			not_equal1 :
//		jmp result
//
//			result :
//		loop start_inner
//			cmp res, 0
//			je result2
//			mov res, 1
//			result2 :
//	}
//	cout << res << endl;
//	system("pause");
//	return 0;
//}
//
//void main() 
//{
//	__int32 arr = 848843586; // (0011 0010 1001 1000
//							 // 0101 0011 0100 0010)
//	__int32 res=0;
//	__asm
//	{
//		mov cx, 8 // кількість проходів циклу
//		mov eax, 1 // маска
//
//	start_outer: // початок зовнішнього циклу (по словах)
//		mov bx, 4 // кількість проходів внутрішнього циклу 
//		xor di, di // обнулення лічильника одиниць
//
//	start_inner:// початок внутрішного циклу (по бітах)
//		mov edx, arr 
//		and edx, eax // накладання маски
//		jz go_next// якщо результат — 0
//		inc di// якщо результат — 1, збільшуємо лічильник
//
//	go_next:
//		shl eax, 1// побітовий зсув вліво на 1 біт
//		dec bx// зменшуємо лічильник проходів на 1
//		test bx, bx// перевіряємо умову завершення циклу
//		jnz start_inner// повторюємо цикл, якщо результат не 0
//		and di, 1// перевірка на парність
//		jnz end_// якщо непарне
//		inc res// якщо парне, збільшуємо лічильник 
//
//	end_:
//		loop start_outer// закінчення зовнішнього циклу
//	}
//	cout << res << endl;
//	system("pause");
//}

//void main()
//{
//	int a, x;
//	cout << "Element a: ";
//	cin >> a;
//	cout << "Element x: ";
//	cin >> x;
//	int y1 = 0, y2 = 0, y = 0;
//	__asm
//	{
//		mov eax, a  //стала а
//		mov ebx, x  //записуємо х
//		cmp ebx, 12  //порівнюємо х з 12
//		jl less_than_twelve
//		jge greater_or_equal_twelve
//
//	less_than_twelve :
//		mov y1, 12  //записуємо 12
//		jmp Y2;
//
//	greater_or_equal_twelve:
//		add ebx, 1  //додаємо 1 до х
//		mov y1, ebx
//
//	Y2:
//		cmp ebx, 2
//		jg greater_two
//		jle less_or_equal_two
//
//	greater_two:
//		mov y2, 2
//		jmp result
//
//	less_or_equal_two:
//		add eax, ebx
//		mov y2, eax
//
//	result:
//		mov eax, y1
//		mov ebx, y2
//		cdq
//		idiv ebx
//		mov y, eax
//	}
//	cout << "Y1: " << y1 << endl;
//	cout << "Y2: " << y2 << endl;
//	cout << "Y: " << y << endl;
//
//	system("pause");
//}

//int a, b, c, d, x;
//int values[5]; // масив для збереження у(х)
//
//void main()
//{
//	a = -6; 
//	b = 4; 
//	c = 8; 
//	d = 2;
//	__asm
//	{
//		mov eax, offset values
//		push eax // заштовхуємо у стек адресу початку масиву
//		mov cx, 5 // кількість проходів циклу 
//
//		start: // початок циклу
//			mov ax, 3 // для обчислення x = 3 - сх 
//			sub ax, cx // отримуємо поточне значення х
//			cwde // розширюємо ax до eax
//			mov ebx, eax // записуємо x в ebx
//			mov eax, a // стала а
//
//			cmp ebx, 1 // порівнюємо х з одиницею
//			jl lessl // якщо х менше 1, переходимо до мітки less
//			je equals // якщо х дорівнює 1, переходимо до equals
//			// якщо х > 1:
//			imul eax // a^2
//			sub eax, ebx // a^2-x
//			cdq // розширюємо a^2-x до четвірного слова
//			mov ebx, c // стала c
//			idiv ebx // (a^2-x)/c
//			jmp result // переходимо до мітки result
//
//		lessl :
//			mov edx, 2
//			imul edx // a*2
//			imul ebx // a*2*x
//			add eax, 5 // a*2*x+5
//			jmp result // переходимо до мітки result
//
//		equals :
//			mov ebx, b // стала b
//			sub eax, ebx // a-b
//			cdq // розширюємо a-b до четвірного слова
//			mov ebx, d // стала d
//			idiv ebx // (a-b)/d
//			jmp result // переходимо до мітки result
//
//		result :
//			pop ebx // виштовхуємо зі стеку адресу масиву
//			mov[ebx], eax // записуємо результат за поточною адресою
//			add ebx, 4 // зсуваємо вказівник масиву
//			push ebx // заштовхуємо в стек нову адресу
//			loop start // кінець циклу
//	}
//	for (int i = 0; i < 5; i++) 
//	{ 
//		cout << values[i] << endl; 
//	}
//	system("pause");
//}

//void main()
//{
//	int year, leap;
//	cin >> year;
//	__asm
//	{
//		//записуємо в ebx 0, який , можливо, змінтись у випадку,
//		//якщо рік високосний
//		mov ebx, 0
//		mov ecx, 400  //записуємо в exc 400 - число, на яке ми будемо ділити
//		//і перевіряти остачу
//		mov eax, year  //записуємо в eax значення year
//		cdq  //перетворюємо подвійне слово в четвірне
//		div ecx  //ділимо значення у eax на значення у ecx
//		test edx, edx
//		//jz - jump zero - якщо результат перевірки остачі 0, то
//		//перестрибуємо на мітку is_leap
//		jz is_leap
//		//якщо ні - то продовжуємо подальшу перевірку
//		mov eax, year  //знову запихаємо значення year у eax
//		cdq
//		mov ecx, 4
//		div ecx  //ділимо і перевіряємо остачу від ділення на 4
//		test edx, edx
//		//якщо вона 0 - перестрибуємо на мітку maybe_leap
//		jz maybe_leap
//		//ні - перестрибуємо на результат
//		jmp result
//
//		//перша мітка - коли точно знаємо результат
//		is_leap :
//		//записуємо у ebx одиницю і стрибаємо до мітки result
//			mov ebx, 1
//			jmp result
//
//		//друга мітка - друга, остаточна перевірка
//		maybe_leap :
//			//знову записуємо в eax рік
//			mov eax, year
//			cdq
//			mov ecx, 100
//			div ecx
//			test edx, edx
//			//і перевіряємо остачу від ділення на 100
//			jz result
//			//інакше - до is_leap
//			jmp is_leap
//
//		result :
//			mov leap, ebx
//	}
//	if (leap > 0) 
//	{
//		cout << "Yes" << endl; 
//	}
//	else 
//	{
//		cout << "No" << endl; 
//	}
//	system("pause");
//}

//void main()
//{
//	//знаходимо обєм
//	int dm, answer;
//	cin >> dm;
//	__asm
//	{
//		mov eax, dm  //в регістр eax додаємо dm
//		cdq  //перетворюємо подвійне слово в четвірне
//		mul dm  //множимо на dm
//		mov answer, eax  //у answer записуємо результат
//		cdq
//		mul dm
//		mov answer, eax
//	}
//	cout << answer << endl;
//}
