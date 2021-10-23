/* Задача на программирование: покрыть отрезки точками

По данным n отрезкам необходимо найти множество точек минимального размера, для которого каждый из отрезков содержит хотя бы одну из точек.
В первой строке дано число ≤n≤100 отрезков. Каждая из последующих n строк содержит по два числа 0 <= l <= r <= 10^9 , 
задающих начало и конец отрезка. Выведите оптимальное число mm точек и сами mm точек. Если таких множеств точек несколько, выведите любое из них.
*/

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

using Segment = pair<int, int>;

vector <int> get_covering_set(vector <Segment> segments) {
    vector <int> result;

    int currNumb = -1;
    for (auto s : segments) {
        if (currNumb < s.first) {
            currNumb = s.second;
            result.push_back(s.second);
        }
    }

  return result;
}

int main(void) {
    int segments_count;
    cin >> segments_count;
    vector <Segment> segments(segments_count);
    for (auto &s:segments) {
        cin >> s.first >> s.second;
    }
    sort(segments.begin(), segments.end(), [](const Segment & x,const Segment & y){return x.second < y.second;});
    auto points = get_covering_set(move(segments));
    cout << points.size() << endl;
    for (auto point:points) {
        cout << point << " ";
    }
    cout << endl;
}