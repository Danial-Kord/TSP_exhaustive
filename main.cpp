#include <vector>
#include <iostream>
#include<math.h>
#include <algorithm>
#include <chrono>
using namespace std::chrono;
using namespace std;
typedef struct point{
    double_t x;
    double y;
    long double des(point in){
        long double output = pow(pow(x-in.x,2) + pow(y-in.y,2),0.5);
        return output ;
    }
}Point;
class Stopwatch
{
private:
    steady_clock::time_point start;

public:
    Stopwatch(){
        reset();
    }

    ~Stopwatch(){}

    // Start the clock
    void reset(){ start = steady_clock::now(); }

    // Read time elapsed in nanoseconds
    double getTime(){
        //    return duration<double, std::nano>(steady_clock::now() - start).count();
        return std::chrono::nanoseconds (steady_clock::now() - start).count();
    }
};

double answer =-1;
vector<Point> points;
void permute(Point a[], int l, int r)
{

    if (l == r){
        double des=0;
        for(int i =1;i<=r;i++){
            des += a[i-1].des(a[i]);

        }
        des += a[r].des(a[0]);
        if(answer == -1) {
            points.clear();
            for (int i = 0; i <= r; ++i) {
                points.push_back(a[i]);
            }
            points.push_back(a[0]);
            answer = des;
        }
        else{
            if(answer > des) {
                answer = des;
                points.clear();
                for (int i = 0; i <= r; ++i) {
                    points.push_back(a[i]);
                }
                points.push_back(a[0]);
            }
        }
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l+1, r);
            swap(a[l], a[i]);
        }
    }
}
int main() {
    int n = 0;
    cin >> n;
    Point points[n];
    for (int i = 0; i < n; ++i) {
//        cin >> points[i].x;
//        cin >> points[i].y;
        points[i].x = rand() % 20000;
        points[i].y = rand() % 20000;
    }
    Stopwatch sw;
    permute(points,0,n-1);//O(n!)
cout<< "........ result ......."<<endl;
    cout << "points : [ " ;
    for (int j = 0; j <n ; ++j) {//O(n^2)
        cout << "x : " <<points->x << " y : "<<points->y<<",";
    }
    cout << "]"<<endl;
    cout << "min : "<< answer;
    cout<<endl<< "#####Execution time: " <<sw.getTime() <<" nanoseconds" <<endl;
    return 0;
}