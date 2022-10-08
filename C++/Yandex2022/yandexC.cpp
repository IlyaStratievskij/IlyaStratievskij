/*
Наконец-то с царством Морфея удалось наладить дипломатические отношения! Первым делом в магазины поступили самые корректные и полные сонники, 
составленные в сотрудничестве с главными сномагами царства.
Ваш близкий друг Тирания Вампадур купила такой сонник одной из первых. Но тут же её ждало разочарование. 
Оказалось, что некоторые сны образуют целую последовательность сюжетов, которую надо интерпретировать только целиком.
И у Тирании оказалась именно такая ситуация. Когда-то давно ей приснилось двоичное дерево из N вершин, занумерованных целыми числами от 1 до N.
Вершина 1 являлась корнем. У каждой вершины v было до двух сыновей: левый имел номер 2 v, правый — 2 v+1 (при условии, что их номера не превосходилиN). 
Таким образом, зная число N, дерево можно было однозначно восстановить.Но, к сожалению, следующие Q  ночей Тирании снились похожие сны: 
одна из вершин дерева v менялась местами с её предком (если v была корнем дерева, то ничего не происходило). Причем эти изменения переносились между снами, 
всё больше и больше изменяя оригинальное дерево. Чтобы верно интерпретировать значение снов, Тирании нужно узнать итоговую структуру дерева 
после всех произошедших с ним изменений. Она просит вас помочь ей и по последовательности менявшихся вершин найти итоговую структуру дерева из её снов.
Понимая, что в этом деле важна точность, вы расспросили Тиранию насчет процесса обмена местами вершины v  с её предком.
Введем обозначения:
p — предок вершины v,pp — предок вершины p (если таковые существуют);
vl — левый ребенок v, vr — правый ребенок v;
pl — левый ребенок p, pr — правый ребенок p.
В таком случае обмен задаётся следующими условиями:
Изменение предка: если
p — левый ребенок вершины pp, то v становится левым ребенкомpp, иначе — правым.
если v — левый ребенок вершины p, то: p становится левым ребенком v;
vr остаётся правым ребенком v; vl становится левым ребенком p;
pr остаётся правым ребенком p.

аналогично, если v — правый ребенок вершины p, то: p становится правым ребенком v; 
vl остаётся левым ребенком v; vr становится правым ребенком p;
pl остаётся левым ребенком p.

Формат ввода
Первая строка содержит два целых числа
N и Q (1≤N≤750;1≤Q≤106) — количество вершин в дереве и количество изменений, произошедших с деревом.
В следующей строке даноQ целых чисел v1,v2,…,vq (1≤vi≤N), где vi — номер вершины, обменявшейся местами со своим предком вi-ю ночь.

Формат вывода
В единственной строке через пробел требуется вывести номера вершин дерева после всех изменений в формате
LVR, начиная с корня дерева. Формат LVR(v) определяется рекурсивно для вершины v.
если у вершины v есть левый ребенок lv, то сначала выводится всё поддерево lv в форматеLVR(lv);
выводится номер вершины v;если у вершины v есть правый ребенок rv, то выводится всё поддерево rv в форматеLVR(rv);
Пример
Ввод	
10 6
5 7 4 7 8 7
Вывод
7 10 5 2 8 4 9 1 6 3
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool myEnd = false;
int i, temp = 0, n, q, change;

struct OBJ {
    int letter, parent;
    struct OBJ* leftTag, * rightTag;
} ;

void Add(int x, int parent, OBJ** Node) {
    (*Node) = new OBJ;
    (*Node)->leftTag = (*Node)->rightTag = NULL;
    (*Node)->letter = x;
    (*Node)->parent = parent;
}

void Show(OBJ** Node)
{
    if ((*Node) == NULL)    return;    //Если дерева нет, выходим

    Show(&(*Node)->leftTag); //Обошли левое поддерево
    cout << (*Node)->letter << " "; //Посетили узел
    Show(&(*Node)->rightTag); //Обошли правое поддерево   
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    OBJ *myTree = NULL;

    Add(1, 0, &myTree);
    vector <OBJ> mapTree;
    mapTree.push_back(*myTree);
    change = 0;
    for (i = 2; i <= n; i++) {
        change++;
        if (mapTree[temp].leftTag == NULL) {
            Add(i, i / 2, &mapTree[temp].leftTag);
            mapTree.push_back(*mapTree[temp].leftTag);
        }
        else if (mapTree[temp].rightTag == NULL) {
            Add(i, i / 2, &mapTree[temp].rightTag);
            mapTree.push_back(*mapTree[temp].rightTag);
        }
        if (change == 2) {
            temp++;
            change = 0;
        }
    }
    for (i = mapTree.size(); i > 1; i--) {
        if (i % 2 == 0) mapTree[i / 2 - 1].leftTag = &mapTree[i-1];
        else mapTree[i / 2 - 1].rightTag = &mapTree[i-1];
    }
    
    temp = 0;
    for (i = 0; i < q; i++) {
        //change = 1 + rand() % n;
        cin >> change;
        int myParent = mapTree[change - 1].parent;
        if (myParent == 0) continue;
        else if (mapTree[myParent-1].parent == 0) {
            if (mapTree[myParent - 1].leftTag != NULL) {
                if (mapTree[myParent - 1].leftTag->letter== mapTree[change-1].letter) {
                    OBJ* tempV = &mapTree[change - 1];
                    OBJ* tempVL = tempV->leftTag;
                    tempV->leftTag = NULL;
                    OBJ* tempP = &mapTree[myParent - 1];
                    tempP->leftTag = NULL;

                    tempP->leftTag = tempVL;
                    tempV->leftTag = tempP;

                    mapTree[change - 1].parent = 0;
                    temp = change - 1;
                    mapTree[myParent - 1].parent = mapTree[change - 1].letter;
                    if (mapTree[myParent - 1].leftTag != NULL) mapTree[myParent - 1].leftTag->parent = mapTree[myParent - 1].letter;
                    continue;
                }
            }
            if (mapTree[myParent - 1].rightTag != NULL) {
                if (mapTree[myParent - 1].rightTag->letter == mapTree[change - 1].letter) {
                    OBJ* tempV = &mapTree[change - 1];
                    OBJ* tempVR = tempV->rightTag;
                    tempV->rightTag = NULL;
                    OBJ* tempP = &mapTree[myParent - 1];
                    tempP->rightTag = NULL;

                    tempP->rightTag = tempVR;
                    tempV->rightTag = tempP;

                    mapTree[change - 1].parent = 0;
                    temp = change - 1;
                    mapTree[myParent - 1].parent = mapTree[change - 1].letter;
                    if (mapTree[myParent - 1].rightTag != NULL) mapTree[myParent - 1].rightTag->parent = mapTree[myParent - 1].letter;
                    continue;
                }
            }
        }
        else {
            if (mapTree[myParent - 1].leftTag != NULL) {
                if (mapTree[myParent - 1].leftTag->letter == mapTree[change - 1].letter) {
                    OBJ* tempV = &mapTree[change - 1];
                    OBJ* tempVL = tempV->leftTag;
                    tempV->leftTag = NULL;
                    OBJ* tempP = &mapTree[myParent - 1];
                    tempP->leftTag = NULL;

                    tempP->leftTag = tempVL;
                    tempV->leftTag = tempP;

                    if (mapTree[mapTree[myParent - 1].parent - 1].leftTag != NULL)
                        if (mapTree[mapTree[myParent - 1].parent - 1].leftTag->letter == tempP->letter)
                            mapTree[mapTree[myParent - 1].parent - 1].leftTag = tempV;
                    if (mapTree[mapTree[myParent - 1].parent - 1].rightTag != NULL)
                        if (mapTree[mapTree[myParent - 1].parent - 1].rightTag->letter == tempP->letter)
                            mapTree[mapTree[myParent - 1].parent - 1].rightTag = tempV;

                    mapTree[change - 1].parent = mapTree[mapTree[myParent - 1].parent - 1].letter;
                    mapTree[myParent - 1].parent = mapTree[change - 1].letter;
                    if (mapTree[myParent - 1].leftTag != NULL) mapTree[myParent - 1].leftTag->parent = mapTree[myParent - 1].letter;
                    continue;
                }
            }
            if (mapTree[myParent - 1].rightTag != NULL) {
                if (mapTree[myParent - 1].rightTag->letter == mapTree[change - 1].letter) {
                    OBJ* tempV = &mapTree[change - 1];
                    OBJ* tempVR = tempV->rightTag;
                    tempV->rightTag = NULL;
                    OBJ* tempP = &mapTree[myParent - 1];
                    tempP->rightTag = NULL;

                    tempP->rightTag = tempVR;
                    tempV->rightTag = tempP;

                    if (mapTree[mapTree[myParent - 1].parent - 1].leftTag != NULL)
                        if (mapTree[mapTree[myParent - 1].parent - 1].leftTag->letter == tempP->letter)
                            mapTree[mapTree[myParent - 1].parent - 1].leftTag = tempV;
                    if (mapTree[mapTree[myParent - 1].parent - 1].rightTag != NULL)
                        if (mapTree[mapTree[myParent - 1].parent - 1].rightTag->letter == tempP->letter)
                            mapTree[mapTree[myParent - 1].parent - 1].rightTag = tempV;

                    mapTree[change - 1].parent = mapTree[mapTree[myParent - 1].parent-1].letter;
                    mapTree[myParent - 1].parent = mapTree[change - 1].letter;
                    if (mapTree[myParent - 1].rightTag != NULL) mapTree[myParent - 1].rightTag->parent = mapTree[myParent - 1].letter;
                    continue;
                }
            }
        }
    }
    myTree = &mapTree[temp];

    Show(&myTree);
}