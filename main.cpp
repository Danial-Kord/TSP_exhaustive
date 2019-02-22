#include <vector>
#include <iostream>
#include<math.h>
#include <algorithm>
using namespace std;
typedef struct point{
    double_t x;
    double y;
    long double des(point in){
        long double output = pow(pow(x-in.x,2) + pow(y-in.y,2),0.5);
        return output ;
    }
}Point;
vector<double> all_des;
void permute(Point a[], int l, int r)
{

    if (l == r){
        double des=0;
        for(int i =1;i<=r;i++){
            des += a[i-1].des(a[i]);
            cout << " +=  : " << des;
        }
        des += a[r].des(a[0]);
        cout << "des  " << des<<endl;
        cout << endl;
        all_des.push_back(des);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {cout << a[l].x<<"  in "<<a[i].x<<endl;
            cout << endl;
            swap(a[l], a[i]);
            cout << a[l].x<<"  "<<a[i].x<<endl;
            cout << endl;
            permute(a, l+1, r);
            swap(a[l], a[i]);
            cout << a[l].x<<" 2 "<<a[i].x<<endl;
            cout << endl;
        }
    }
}
int main() {
    int n = 0;
    cin >> n;
    Point points[n];
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x;
        cin >> points[i].y;
    }
    permute(points,0,n-1);
    sort(all_des.begin(),all_des.end());
cout<< "..............."<<endl;
    for (int j = 0; j < all_des.size(); ++j) {
        cout << all_des.at(j) << endl;
    }

    return 0;
}