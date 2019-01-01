//haffmantree 
//����
//1�������ļ������ɱ��룬���ļ���������Ƶ�ʹ���haffman��
//2��������뵽�ı�
//3�������ļ�����
//4��������뵽�ı�
//ע�⣬ѡ��ĳ�ʼ�ı��ַ�������������
#define SHOW_CONSOLE
#include<fstream>
#include<cstdio>
#include<iostream>
#include<string>
#include<graphics.h>
#include<cmath>
#define MAXSIZE 200 
using namespace std;
typedef string *Hcode;
typedef struct {
	char c;
	int weight;
	int lch, rch, parent;
}node;
typedef node HuffmanTree[MAXSIZE];
/*  ���湦��ѭ����1������ 2�����루�����ļ����������������棩 3���루�����ļ����������������棩 4�ع�haffman����������Ȩ��txt��5�˳�*/
//��ʼ��haffman��
int Find_Root(HuffmanTree H, int r) {
	if (abs(H[1].weight)<2000) {
		if (r != -1) {
			if (H[r].parent != -1) {
				return Find_Root(H, H[r].parent);
			}
			else {
				return r;
			}
		}
		else return -1;
	}
	else {
		cerr << "δ��ʼ�����������루����ִ�� ��ѡ�" << endl;
	}
	return -1;
}
int Not_duplicated(string a, char b, int n) { //ԭʼ�ַ������Ƚ��ַ����ַ������С
	const char*str = a.c_str();
	int flag = 1;//����101Ϊû���ظ�
	for (int i = 0; i < n; i++) {
		if (b == a[i]) {
			flag = 0;
			break;
		}
	}
	return flag;
}
void StrCount(int* n, string *a, string* d, int*c) { //���ظ�������ԭʼ�������ظ��ַ��������ظ�ͳ��
	if (a->length()>0) {
		int nn = (int)(*a).length();
		int co = 0;
		for (int i = 0; i < nn; i++) {
			if (Not_duplicated((*a), (*a)[i], i)) {
				c[co]++; co++;
				*d = *d + (*a)[i];
			}
			else {
				for (int j = 0; j <= co; j++) {
					if ((*a)[i] == (*d)[j]) {
						c[j] ++; break;
					}
				}
			}
		}
		*n = co;
	}
	else {
		printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t�U             ���ַ�����             �U\n");
		printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
	}

}
void ReadFile(string ffname, string *a, int* n, string *drop, int *c) {//�ļ�����ԭʼ�ַ��������ظ����������ظ��ַ��������ظ�ͳ��
	string fname = ffname;
	string str = "";
	string buffer;
	ifstream in;
	in.open(fname.c_str(), ios::out);
	if (in.is_open()) {
		while (getline(in, buffer)) {
			str = str + buffer;
		}
	}
	else {
		printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t�U           δ�ɹ����ļ�           �U\n");
		printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
		return;
	}
	in.close();
	//ͳ��
	for (int i = 0; i < MAXSIZE; i++)c[i] = 0;
	StrCount(n, &str, drop, c);
	*a = str;//ԭʼ�ַ���
};
void InitialTree(HuffmanTree H, int n) {//�������������ظ�����
	if (n>0) {
		for (int i = 0; i < MAXSIZE; i++) {
			H[i].c = ' ';
			H[i].weight = 0;
			H[i].lch = -1;
			H[i].rch = -1;
			H[i].parent = -1;
		}
		printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t�U        �ɹ���ʼ����������          �U\n");
		printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
	}
	else {
		printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t�U       δ�ɹ���ʼ����������         �U\n");
		printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
		return;
	}
};
void InputWeight(HuffmanTree H, string *se, int*c, int n) {//���ظ��ַ��������ظ�ͳ�ƣ����ظ�����
	if (n>0)
	{
		const char* cc = (*se).c_str();
		for (int i = 0; i < n; i++) {
			H[i].c = cc[i];
			H[i].weight = c[i];
		}
		printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t�U            �ɹ�����Ȩ��            �U\n");
		printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
	}
	else {
		printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t�U           ����Ȩ��ʧ��             �U\n");
		printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
	}
};//����Ȩ��
void SelectTwoMin(HuffmanTree HT, int end, int *s1, int *s2) {//�������������ֵ����Сһ����С��
	int min1 = 999999;
	int min2 = 999999;
	int i, j;
	for (i = 0; i < end; i++) {
		if (HT[i].parent == -1)//���ڵ�
			if (HT[i].weight <= min1) {
				min1 = HT[i].weight;
				*s1 = i;
			}
	}
	for (j = 0; j < end; j++) {
		if (HT[j].parent == -1)//���ڵ�
			if (HT[j].weight <= min2 && (*s1) != j) {
				min2 = HT[j].weight;
				*s2 = j;
			}
	}
};//ѡ��������С�Ľڵ�
void CreatTree(HuffmanTree H, string fname, int *nn) {
	int n = 0;//���ظ��ַ�������
	string first;//ԭʼ�����ַ���
	string nodustr = "";//���ظ��ַ���
	int count[MAXSIZE];//���ظ��ַ�ͳ��
	ReadFile(fname, &first, &n, &nodustr, count);
	InitialTree(H, n);
	InputWeight(H, &nodustr, count, n);
	*nn = n;
	int p1 = -1, p2 = -1;
	for (int i = n; i < 2 * n - 1; i++) {//��ײ㸸�ڵ㹹��
		SelectTwoMin(H, i, &p1, &p2);
		H[p1].parent = i;
		H[p2].parent = i;
		H[i].lch = p1;
		H[i].rch = p2;
		H[i].weight = H[p1].weight + H[p2].weight;
	}
};//����������������,�����һ����������
void Print(HuffmanTree H, int x, int y, int r, int boo, int xlen, int ylen, int sub, int subb) {//�������ڵ�x��y,���ڵ㣬���ң�x����y��������
	if (H[r].weight >= -1) {
		Print(H, x - xlen, y + ylen, H[r].lch, 0, xlen - (sub - subb), ylen, (sub - subb), subb);//left
		fillellipse(x, y, 15, 15);
		if (H[r].c != ' ') {
			outtextxy(x - 5, y - 5, H[r].c);
		}
		if (r != Find_Root(H, r)) {
			line(x, y, boo == 0 ? (x + xlen + sub) : (x - xlen - sub), y - ylen);
			outtextxy(boo == 0 ? (x + (xlen + sub) / 2) : (x - (xlen + sub) / 2), y - (ylen) / 2, char('0' + boo));
		}
		Print(H, x + xlen, y + ylen, H[r].rch, 1, xlen - (sub - subb), ylen, (sub - subb), subb);//right
	}
	else return;
}
void Struct_print(HuffmanTree H, int x, int y, int r, int n) {//������������x,��y��������Ŀ
	if (n>0) {
		initgraph(1500, 600);
		outtextxy(20, 20, "�ñ���Ĺ���������");
		outtextxy(20, 40, "����������˳���");
		outtextxy(20, 60, "���νṹ");
		setcolor(EGERGB(248, 248, 255));
		//setbkcolor(EGERGB(0x0, 0x40, 0x0));//(0x0, 0x0, 0x40)ǳ����(0xFF, 0xFF, 0x0)�ƣ�(0x0, 0x40, 0x0)�̣�(0xFF, 0x0, 0x80)�� 0x80, 0x0, 0xFF�� (0xFF, 0x0, 0x0)��
		setfillcolor(EGERGB(0xFF, 0x0, 0x0));
		setfontbkcolor(EGERGB(0x0, 0x40, 0x0));
		Print(H, x, y, r, 0, 170, 50, 32, 0);
		getch();
		closegraph();
	}
	else {
		cerr << "δ�������������루����ִ�� ��ѡ�" << endl;
		printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t�U            �����������            �U\n");
		printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		getchar();
	}
}
Hcode HcGeneration(HuffmanTree H, Hcode hc, int n) {//���ɽ����Ĺ���������
	if (n>0) {
		hc = new string[n];
		int p, c, i;
		for (i = 0; i < n; i++) {
			for (c = i, p = H[i].parent; p != -1; c = p, p = H[p].parent) {
				if (H[p].lch == c) {//����
					hc[i] = "0" + hc[i];
				}
				else {
					hc[i] = "1" + hc[i];
				}
			}
		}
		return hc;
	}
	else {
		printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t�U         ���������봴��ʧ��         �U\n");
		printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
		return NULL;
	}
};//���ɹ��������ı���
void Encode(string Original, string CodeFile, Hcode hc, HuffmanTree HT, int n) {//ԭ�ַ��ļ�����������ļ������������������,����
	if (Original.length()>0 && CodeFile.length()>0 && n>0) {
		string str = "";//�����ԭʼ����
		string Hfcode = "";
		string buffer;
		int len;
		ifstream in;
		in.open(Original.c_str(), ios::in | ios::out);
		if (in.is_open()) {
			while (getline(in, buffer)) {//����
				str = str + buffer;
			}
			in.close();
			len = str.length();
			printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			cout << "\t\tԭ������Ϊ��\n\t\t" << str << "\n\t\t" << "����Ϊ��" << len << endl;
			printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
			const char* ch = str.c_str();
			int k = 0, i;
			while (ch[k] != '\0') {
				for (i = 0; i < len; i++) {
					if (ch[k] == HT[i].c) {
						Hfcode += hc[i];
						break;
					}
				}
				k++;
			}
			printf("");
			printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			cout << "\t\t���ѱ���Ϊ��\n" << "\t\t" << Hfcode << "\n\t\t" << "����Ϊ��" << Hfcode.length() << endl;
			printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n");
			ofstream out;
			out.open(CodeFile.c_str(), ios::out);
			if (out.is_open()) {
				out << Hfcode.c_str() << endl;
				out.close();
				printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				cout << "\t\t�ѳɹ���������ļ�����д���ļ���" << CodeFile.c_str() << endl;
				printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n");
			}
			else {
				printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("\t\t�U           δ�ɹ�д���ļ�           �U\n");
				printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
			}
		}
		else {
			printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			printf("\t\t�U           δ�ɹ����ļ�           �U\n");
			printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
		}
	}
	else {
		printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t�U    �ļ���û��ֵ��û�й��������룡  �U\n");
		printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
	}
};//���������б���
void Decode(string CodeFile, string TextFile, HuffmanTree HT, int n) {//�����ļ����������ļ������������������ظ��ַ���
	if (CodeFile.length() > 0 && TextFile.length() > 0 && n>0) {
		char ch = ' ';
		string str = "";//Ҫ������ַ�
		string Hfcode = "";//����Ĺ���������
		string buffer;
		int len, i = 0;
		int j = Find_Root(HT, 1);//2 * n - 1 - 1;//�Ӹ��ڵ���������
		ifstream in;
		in.open(CodeFile.c_str(), ios::in | ios::out);
		if (in.is_open()) {
			while (getline(in, buffer)) {//����
				Hfcode = Hfcode + buffer;
			}
			in.close();
			len = Hfcode.length();
			printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			cout << "\t\tԭ����������Ϊ��\n\t\t" << Hfcode << "\n\t\t" << "���ȣ�" << len << endl;
			printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
			if (HT == NULL) {
				printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("\t\t�U           ���ȱ��루�����ڣ�       �U\n");
				printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
				return;
			}
			const char* code = Hfcode.c_str();
			while (code[i] != '\0') {
				if (code[i] == '0') {//0
					j = HT[j].lch;
				}
				else {//1
					j = HT[j].rch;
				}
				if (HT[j].rch == -1&&HT[j].lch == -1) {
					ch = HT[j].c;
					str += ch;
					/*j = n * 2 - 1 - 1;*/
					j = Find_Root(HT, 1);
				}
				i++;
			}
			//��ʼд��
			printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			cout << "\t\t���ѽ���Ϊ��\n" << "\t\t" << str << "\n\t\t����Ϊ��" << str.length() << endl;
			printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n");
			ofstream out;
			out.open(TextFile.c_str(), ios::out);
			if (out.is_open()) {
				out << str.c_str() << endl;
				out.close();
				printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				cout << "\t\t�ѳɹ��������ļ�����д���ļ���" << TextFile.c_str() << endl;
				printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n");
			}
			else {
				printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("\t\t�U           δ�ɹ�д���ļ�           �U\n");
				printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
			}
		}
		else {
			printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			printf("\t\t�U           δ�ɹ����ļ�           �U\n");
			printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
		}
	}
	else {
		printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
		printf("\t\t�U   �ļ���û��ֵ��û�й��������룡   �U\n");
		printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n");
	}
};//���������н���
void PrintHfcode(HuffmanTree H, Hcode hc, int n) {//��������������ظ��ַ���
	if (n>0) {
		printf("\t\t�ı��ַ���Ӧ�Ĺ������������£�\n");
		printf("\t\t�������ı�������� %d\n", n);
		for (int i = 0; i < n; i++) {
			cout << "\t\t" << H[i].c << "  :    " << hc[i] << endl;
		}
	}
	else { cout << "δ�ɹ����" << endl; }
}
int StartUI() {
	getchar();
	system("cls");
	printf("\t\t�n�n�n�n�n�n�k�k�k�k�k�k�k�k�k�k�n�n�n�n�n�n\n");
	printf("\t\t�X�T�T�T�k�k ����������������� �k�k�T�T�T�[\n");
	printf("\t\t�U\t����.��ȡ�������ļ� \t\t  �U\n");
	printf("\t\t�U\t����.���������뱣�� \t\t  �U\n");
	printf("\t\t�U\t����.���������뱣�� \t\t  �U\n");
	printf("\t\t�U\t����.��ӡ��������   \t\t  �U\n");
	printf("\t\t�U\t����.��ʾ����״̬   \t\t  �U\n");
	printf("\t\t�U\t����.�˳�ϵͳ       \t\t  �U\n");
	printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n");
	printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t�U�T�T�T�T�T�T�T�������ѡ��T�T�T�T�T�T�T�T�U:\n");
	printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n>>> ");
	int c;
	cin >> c;
	return c;
};
void Status(HuffmanTree H, Hcode HC, int n, string *A, string *B, string *C, int *HH, int *HCC, int *NN, int*a, int*b, int*c) {
	//�������������������룬������ԭ���������������������ֱ��Ӧ����
	int i, flag = 1;
	for (i = 0;i < 2;i++) {
		if (abs(H[i].weight) > 5000) {
			flag = 0;break;
		}
	}
	*HH = flag;flag = 1;//����������
	if (NULL == HC) {
		flag = 0;;
	}
	*HCC = flag;flag = 1;//����������
	if (n <= 0) {
		flag = 0;
	}*NN = flag;flag = 1;//�ַ���
	if ((*A).length() == 0)(*a) = 0;
	if ((*B).length() == 0)(*b) = 0;
	if ((*C).length() == 0)(*c) = 0;
};
string Panduan(int a) {
	if (a)return "yes";
	else return "no ";
}
void main() {//PrintTree�д�
	system("color 3F");
	//system("mode con cols=80 lines=40");
	int n = 0;
	int flag = 1;
	Hcode hc = NULL;//����������
	string frname = "";//ԭ�ļ���
	string foname = "";//�����ļ���
	string fyname = "";//�����ļ���
	HuffmanTree H;//node����
	printf("\t   �n�n�n�n�n�n�n�n�k�k�k�k�k�k�k�k�k�k�n�n�n�n�n�n�n�n\n");
	printf("\t   �X�T�T�T�T�k�k��ӭʹ�ù����������������k�k�T�T�T�T�[\n");
	printf("\t   �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n\n\n");
	printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
	printf("\t\t�U            ���س�������            �U\n");
	printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	while (flag) {
		switch (StartUI()) {
		case 1: {
			printf("\t��Ŀ¼�µ�����txt�ļ�������ʾ��\n");
			printf("\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			system("dir *.txt");
			printf("\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
			printf("\n\t������ѡ������������ļ�����txt�ļ���:\n");
			printf("\t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n>>> ");
			cin >> frname;
			CreatTree(H, frname.c_str(), &n);
			hc = HcGeneration(H, hc, n);
			printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			printf("\t\t�U            ���س�������            �U\n");
			printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
			getchar();
		} break;
		case 2: {
			printf("\t���������뱣�������ļ���\n");
			printf("\t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n>>>");
			cin >> foname;
			printf("\t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
			Encode(frname.c_str(), foname.c_str(), hc, H, n);
			printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			printf("\t\t�U            ���س�������            �U\n");
			printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");getchar(); }break;
		case 3: {
			printf("\t���������뱣��������ļ���\n");
			printf("\t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n>>>");
			cin >> fyname;
			printf("\t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
			Decode(foname.c_str(), fyname.c_str(), H, n);
			printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			printf("\t\t�U            ���س�������            �U\n");
			printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");getchar(); }  break;
		case 4:Struct_print(H, 600, 50, Find_Root(H, 0), n);  break;
		case 5: {
			int HH = 1, HCC = 1, NN = 1, RR = 1, OO = 1, YY = 1;
			Status(H, hc, n, &frname, &foname, &fyname, &HH, &HCC, &NN, &RR, &OO, &YY);
			printf("\t\t����������/����ϵͳ��Ϣ��\n");
			printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			printf("\t\t�U�T�T�T�T�T�T�T�T�T�T�T�T�T�T�U\n");
			printf("\t\t�U���������Ƿ�����  |    ");cout << Panduan(HH) << "�U" << endl;
			printf("\t\t�U�����������Ƿ�����|    ");cout << Panduan(HCC) << "�U" << endl;
			printf("\t\t�Uԭ�ı��ַ�����������|    ");cout << Panduan(NN) << "�U" << endl;
			printf("\t\t�U�ѳ��Խ���ԭ�����ݣ�|    ");cout << Panduan(RR) << "�U" << endl;
			printf("\t\t�U�ѳ���ִ�б��������|    ");cout << Panduan(OO) << "�U" << endl;
			printf("\t\t�U�ѳ���ִ�н��������|    ");cout << Panduan(YY) << "�U" << endl;
			printf("\t\t�U�T�T�T�T�T�T�T�T�T�T�T�T�T�T�U\n");
			printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
			if (HH&&HCC&NN)PrintHfcode(H, hc, n);
			printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			printf("\t\t�U            ���س�������            �U\n");
			printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
			getchar();
		}  break;
		case 6: {
			printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
			printf("\t\t�U               ���˳�               �U\n");
			printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");flag = 0; } break;
		default: {if (cin.fail()) {
			cin.clear();cin.ignore();
		}
				 printf("\t\t�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				 printf("\t\t�U  �Ƿ�ѡ��!������ѡ��!(���س�����)  �U\n");
				 printf("\t\t�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
				 getchar();
		}break;
		}
	}
	system("pause");
}