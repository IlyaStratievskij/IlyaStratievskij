#include <stdio.h>
#include <locale.h>

void in_comment(int);
void search(int);
void in_quotes(int);

FILE *file;

int roundBrackets, figureBrackets, cubeBrackets, quotes1, quotes2;

int main() {
    setlocale(LC_ALL, "RUS");

    int c;
    char file_name[25];
    printf("������� �������� ��������� �����: ");
    gets(file_name); // ��������� �������� �����

    file = fopen(file_name, "rb");  // ��������� �������� ���� ��� ������
    if (file == NULL) {             // ��������� ������ �� ����
        printf("Don't open file.");
        perror(file_name);
        return 1;
    }
    while ((c = fgetc(file)) != EOF) { // ���� �������� ������� �� �� ����� �� ����� �����
        if (c == '/') {
            if ((c = fgetc(file)) == '*') {
                in_comment(c);
            }
            else
                search(c);
        }
        else if (c == '\'' || c == '"') {
            if (c == '\'')
                quotes1++;
            if (c == '"')
                quotes2++;
            in_quotes(c);
        }
        else search(c);

        if (roundBrackets < 0) {
            printf("�������� ������� ������.\n");
            roundBrackets = 0;
        }
        if (cubeBrackets < 0) {
            printf("�������� ���������� ������.\n");
            cubeBrackets = 0;
        }
        if (figureBrackets < 0) {
            printf("�������� �������� ������.\n");
            figureBrackets = 0;
        }
        if (quotes1 < 0) {
            printf("�������� ��������� �������.\n");
            quotes1 = 0;
        }
        if (quotes2 < 0) {
            printf("�������� ������� �������.\n");
            quotes2 = 0;
        }
    }
    if (roundBrackets > 0) {
        printf("�������� ������� ������.\n");
        roundBrackets = 0;
    }
    if (cubeBrackets > 0) {
        printf("�������� ���������� ������.\n");
        cubeBrackets = 0;
    }
    if (figureBrackets > 0) {
        printf("�������� �������� ������.\n");
        figureBrackets = 0;
    }
    if (quotes1 > 0) {
        printf("�������� ��������� �������.\n");
        quotes1 = 0;
    }
    if (quotes2 > 0) {
        printf("�������� ������� �������.\n");
        quotes2 = 0;
    }
}

void in_comment(int c) {
    int d;
    c = fgetc(file);
    d = fgetc(file);
    while (c != '*' && d != '/') {
        c = d;
        d = fgetc(file);
    }
}

void search(int c) {
    if (c == ')')
        roundBrackets--;
    if (c == '(')
        roundBrackets++;

    if (c == '[')
        cubeBrackets++;
    if (c == ']')
        cubeBrackets--;

    if (c == '}')
        figureBrackets--;
    if (c == '{')
        figureBrackets++;
}

void in_quotes(int c) {
    int d;
    while (d != ']' && d != ';' && d != ')' && d != ',' && d != '}') {
        d = fgetc(file);
        if (d == '\\')
            getchar();
        if (d == '\'')
            quotes1--;
        if (d == '\"')
            quotes2--;
    }
    if(d == ')')
        roundBrackets--;
    if(d == ']')
        cubeBrackets--;
    if(d == '}')
        figureBrackets--;
}


