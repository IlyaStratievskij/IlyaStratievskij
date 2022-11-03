/*
непрерывный рюкзак

Первая строка содержит количество предметов 3 и вместимость рюкзака 6
Каждая из следующих nn строк задаёт стоимость и объём предмета. 
Выведите максимальную стоимость частей предметов (от каждого предмета можно отделить любую часть, 
стоимость и объём при этом пропорционально уменьшатся), помещающихся в данный рюкзак,
с точностью не менее трёх знаков после запятой.

Sample Input:

3 50
60 20
100 50
120 30
Sample Output:

180.000
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

double get_profit(const Item &item) {
    return static_cast <double> (item.weight) / item.value;
}

double get_backpack(int capacity, vector<Item> items) {
    double value = 0.0;
    sort (items.begin(), items.end(), [](const Item &lhs,const Item &rhs) {
        return get_profit(lhs) < get_profit(rhs);
    });
    
    for (auto &item: items) {
        if (capacity > item.weight) {
            capacity -= item.weight;
            value += item.value;
        } else {
            value += item.value * (static_cast<double>(capacity) / item.weight);
            break;
        }
    }
    return value;
    
}

int main() {
    int numbers, capacity;
    cin >> numbers >> capacity;
    vector <Item> items(numbers);
    for (int i = 0; i < numbers; i++) 
        cin >> items[i].value >> items[i].weight;
    
    cout << setprecision(3) << fixed;
    cout << get_backpack(capacity, move(items));;
    
    return 0;   
}