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



//const int n = 5;  //�-��� ����. ����� �
//float neg13 = -13;
//float one = 1;
//float two = 2;
//float c, d;
//float a[n];  //����. �����
//float res[n];  //����. ������
//
//void calculateASM()
//{
//	__asm
//	{
//		//���������� �������
//		lea esi, a  //������ ���. ������ �
//		lea edi, res  //������ ���. ������ res
//		mov ecx, n  //����� ������
//		finit  //����������� �������.
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
//		fstp[edi]  //����� ����. ������ ������
//		//������� �� ��������� ����. ������
//		add esi, 4
//		add edi, 4
//		loop iteration  //����� �����
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


//const int n = 3;// ������� ������� ����� �
//const float neg4 = -4;
//float d;
//float x[n];// �������� �����
//float res[n];// �������� ������
//
//void calculateASM()
//{
//	__asm
//	{
//		// ���������� �������
//		lea esi, x// ������ ������� ������ �
//		lea edi, res// ������ ������� ������ res
//		mov ecx, n// ����� ������
//		finit// ����������� ������������
//	iteration :// ������� �����
//		fld [esi]// �������� � � ���� ������������
//		fadd d// x + d
//		fsincos// sin(x+d) i cos(x+d) � ����
//		fmul// sin(x+d)*cos(x+d)
//		fld neg4// -4 � ����
//		fdiv// sin(x+d)cos(x+d)/(-4)
//		fstp [edi]// ����� �������� ������ � �����
//		// ������� �� ��������� �������� ������
//			
//		add esi, 4
//		add edi, 4
//		loop iteration// ����� �����
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
//	// ���������� �����ֲ
//	int n;
//	cout << "Enter n : ";
//	cin >> n;
//	int** a = new int*[n];        // ������� �
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
//	// ²���˲��ֲ� ����������� �������
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
//			mov ecx, 1  //������, �� ���� ������ ��� �� ���� �����(������ ��� � � max_in_row)
//
//		find_in_row:
//			mov eax, a
//			mov edx, i  //������ �����
//			mov eax, [eax + 4 * edx] // eax = a[i]
//			mov eax, [eax + 4 * ecx] // eax = a[i][ecx]
//			cmp eax, max_in_row
//			jg greater1  //���� eax ������, �� �� ���� greater1
//			jmp check_end  //���� �����, �� �� ���� check_end
//				
//		greater1:
//			mov max_in_row, eax  //����� ������������ ����
//			mov index_max_in_row, ecx  //�������� ������ ���� ����
//
//		check_end:  //�� ������� ���� �����
//			add ecx, 1
//			cmp ecx, n  //������� ������ ���� � ������� �����
//			jl find_in_row  //���� ������, �� ���������� �� find_in_row
//			//���� �, �� �������� �� ������������ ����� � ��������� �������
//			mov ecx, 0  //������ �� ������
//
//		find_in_col:
//			mov eax, a
//			mov edx, index_max_in_row  //������ �������, �� � max_in_row
//			mov eax, [eax + 4 * ecx] // eax = a[ecx]
//			mov eax, [eax + 4 * edx] // eax = a[ecx][index_max_in_row]
//			cmp eax, max_in_row  
//			jl less1  //���� ������, ���������� less1
//			jmp check_end_2
//
//		less1:
//			mov max_in_row, -1  //��� ����������, �� ������ �����
//			jmp end1  //� ����� ���������� �������
//
//		check_end_2:
//			add ecx, 1  //����������� �� ������ �������
//			cmp ecx, n
//			jl find_in_col  //���� ������ �� ���������� �� ��� �����
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
//			mov ecx, 1  //������, �� ���� ������ ��� �� ���� �����(������ ��� � � min_in_row)
//
//			find_in_row_2:
//			mov eax, a
//				mov edx, i  //������ �����
//				mov eax, [eax + 4 * edx] // eax = a[i]
//				mov eax, [eax + 4 * ecx] // eax = a[i][ecx]
//				cmp eax, min_in_row
//				jl less2  //���� eax ������, �� �� ���� less2 
//				jmp check_end2  //���� �����, �� �� ���� check_end2
//
//				less2 :
//			mov min_in_row, eax  //����� ������������ ����
//				mov index_min_in_row, ecx  //�������� ������ �� ����
//
//		check_end2:  
//			add ecx, 1
//			cmp ecx, n  //������� ������ ���� � ������� �����
//			jl find_in_row_2  //���� ������, �� ���������� �� find_in_row_2
//			//���� �, �� �������� �� ������������ ����� � ��������� �������
//			mov ecx, 0  //������ �� ������
//
//			find_in_col_2 :
//			mov eax, a
//			mov edx, index_min_in_row  //������ �������, �� � max_in_row
//			mov eax, [eax + 4 * ecx] // eax = a[ecx]
//			mov eax, [eax + 4 * edx] // eax = a[ecx][index_max_in_row]
//			cmp eax, min_in_row
//			jg greater2  //���� ������, ���������� greater2
//			jmp check_end_2_2
//
//		greater2 :
//			mov min_in_row, -1  //��� ����������, �� ������ �����
//			jmp end2  //� ����� ���������� �������
//
//			check_end_2_2 :
//		add ecx, 1  //����������� �� ������ �������
//			cmp ecx, n
//			jl find_in_col_2  //���� ������ �� ���������� �� ��� �����
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
//	// ���������� �����ֲ
//	int n;
//	cout << "Enter n : ";
//	cin >> n;
//	int** a = new int*[n];        // ������� �
//	int** b = new int*[n];        // ������� �
//	int** res = new int*[n];      // ����������� �������
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
//	// ²���˲��ֲ� ����������� �������
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
//	// ���������� ������� (�������� �������� �������)
//	// ��� �������� ����� �������� �� �++ 
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
//	// ��������� ����������
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
//		mov edx, offset arr  //���������� edx arr
//		mov al, [edx]  //�������� al ���� ��������
//		mov cx, 6  //6 ������� �����
//
//		start_outer:  //������� ����
//		mov bx, 8  //8 ������� �����
//			mov ah, 1
//			cmp one, 3  //������� one � 3
//			jg more  //���� > 3 - ����������
//			inc res  //�������� res
//
//			more:
//		mov one, 0  //������� one 0 
//			start_inner:  //�������� ����
//		mov al, [edx]  
//			and al, ah
//
//			cmp al, 1  
//			je equal1  //��� ������ ���������� one
//			jne next1  //��� �������� ���������� �� ���������� �����
//
//			equal1:
//		inc one  //������ one
//
//			next1:
//		inc bx  // ������ bx
//			shr al, 1  //���� ������ �� 1
//			test bx, bx  //�������� �� ���� ����������
//			jnz start_inner  //�������� ���� ���� res != 0
//			add edx, 1  //���������� �� ���������� �������� arr
//
//		loop start_outer  //������� ������� ����
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
//		mov cx, 8 // ������� ������� �����
//		mov eax, 1 // �����
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
//		mov cx, 8 // ������� ������� �����
//		mov eax, 1 // �����
//
//	start_outer: // ������� ���������� ����� (�� ������)
//		mov bx, 4 // ������� ������� ����������� ����� 
//		xor di, di // ��������� ��������� �������
//
//	start_inner:// ������� ���������� ����� (�� ����)
//		mov edx, arr 
//		and edx, eax // ���������� �����
//		jz go_next// ���� ��������� � 0
//		inc di// ���� ��������� � 1, �������� ��������
//
//	go_next:
//		shl eax, 1// �������� ���� ���� �� 1 ��
//		dec bx// �������� �������� ������� �� 1
//		test bx, bx// ���������� ����� ���������� �����
//		jnz start_inner// ���������� ����, ���� ��������� �� 0
//		and di, 1// �������� �� �������
//		jnz end_// ���� �������
//		inc res// ���� �����, �������� �������� 
//
//	end_:
//		loop start_outer// ��������� ���������� �����
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
//		mov eax, a  //����� �
//		mov ebx, x  //�������� �
//		cmp ebx, 12  //��������� � � 12
//		jl less_than_twelve
//		jge greater_or_equal_twelve
//
//	less_than_twelve :
//		mov y1, 12  //�������� 12
//		jmp Y2;
//
//	greater_or_equal_twelve:
//		add ebx, 1  //������ 1 �� �
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
//int values[5]; // ����� ��� ���������� �(�)
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
//		push eax // ���������� � ���� ������ ������� ������
//		mov cx, 5 // ������� ������� ����� 
//
//		start: // ������� �����
//			mov ax, 3 // ��� ���������� x = 3 - �� 
//			sub ax, cx // �������� ������� �������� �
//			cwde // ���������� ax �� eax
//			mov ebx, eax // �������� x � ebx
//			mov eax, a // ����� �
//
//			cmp ebx, 1 // ��������� � � ��������
//			jl lessl // ���� � ����� 1, ���������� �� ���� less
//			je equals // ���� � ������� 1, ���������� �� equals
//			// ���� � > 1:
//			imul eax // a^2
//			sub eax, ebx // a^2-x
//			cdq // ���������� a^2-x �� ��������� �����
//			mov ebx, c // ����� c
//			idiv ebx // (a^2-x)/c
//			jmp result // ���������� �� ���� result
//
//		lessl :
//			mov edx, 2
//			imul edx // a*2
//			imul ebx // a*2*x
//			add eax, 5 // a*2*x+5
//			jmp result // ���������� �� ���� result
//
//		equals :
//			mov ebx, b // ����� b
//			sub eax, ebx // a-b
//			cdq // ���������� a-b �� ��������� �����
//			mov ebx, d // ����� d
//			idiv ebx // (a-b)/d
//			jmp result // ���������� �� ���� result
//
//		result :
//			pop ebx // ���������� � ����� ������ ������
//			mov[ebx], eax // �������� ��������� �� �������� �������
//			add ebx, 4 // ������� �������� ������
//			push ebx // ���������� � ���� ���� ������
//			loop start // ����� �����
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
//		//�������� � ebx 0, ���� , �������, ������� � �������,
//		//���� �� ����������
//		mov ebx, 0
//		mov ecx, 400  //�������� � exc 400 - �����, �� ��� �� ������ �����
//		//� ��������� ������
//		mov eax, year  //�������� � eax �������� year
//		cdq  //������������ ������� ����� � �������
//		div ecx  //����� �������� � eax �� �������� � ecx
//		test edx, edx
//		//jz - jump zero - ���� ��������� �������� ������ 0, ��
//		//������������ �� ���� is_leap
//		jz is_leap
//		//���� � - �� ���������� �������� ��������
//		mov eax, year  //����� �������� �������� year � eax
//		cdq
//		mov ecx, 4
//		div ecx  //����� � ���������� ������ �� ������ �� 4
//		test edx, edx
//		//���� ���� 0 - ������������ �� ���� maybe_leap
//		jz maybe_leap
//		//� - ������������ �� ���������
//		jmp result
//
//		//����� ���� - ���� ����� ����� ���������
//		is_leap :
//		//�������� � ebx ������� � �������� �� ���� result
//			mov ebx, 1
//			jmp result
//
//		//����� ���� - �����, ��������� ��������
//		maybe_leap :
//			//����� �������� � eax ��
//			mov eax, year
//			cdq
//			mov ecx, 100
//			div ecx
//			test edx, edx
//			//� ���������� ������ �� ������ �� 100
//			jz result
//			//������ - �� is_leap
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
//	//��������� ���
//	int dm, answer;
//	cin >> dm;
//	__asm
//	{
//		mov eax, dm  //� ������ eax ������ dm
//		cdq  //������������ ������� ����� � �������
//		mul dm  //������� �� dm
//		mov answer, eax  //� answer �������� ���������
//		cdq
//		mul dm
//		mov answer, eax
//	}
//	cout << answer << endl;
//}
