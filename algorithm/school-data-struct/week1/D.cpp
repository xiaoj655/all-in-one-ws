#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

class Point
{
    double x, y;
public:
    Point();
    Point(double x_value, double y_value);      // 缺省构造函数，给 x, y 分别赋值为0
    ~Point();                                   // 析构函数
    double getX();                              // 返回x的值
    double getY();                              // 返回y的值
    void setXY(double x1, double y1){x = x1; y = y1;}
    void setX(double x_value);                  // 设置x的值
    void setY(double y_value);                  // 设置y的值
    double getDisTo(const Point &p);                  // 计算当前点到参数点p的距离
    Point(const Point&);
};
Point::Point(){
  x=0;y=0;
}
Point::Point(double x,double y):x(x),y(y){ cout << "Constructor.\n"; }
Point::~Point(){ cout << "Distructor.\n"; }
double Point::getX(){ return x; }
double Point::getY(){ return y; }
void Point::setX(double x1){ x=x1; }
void Point::setY(double y1){ y=y1; }
double Point::getDisTo(const Point &p){
  double distance = sqrt(pow(p.x-x,2)+pow(p.y-y,2));
  return distance;
}
Point::Point(const Point& other) {

}
int main(){
  int T;cin>> T;
  while(T--){
    int n;cin >>n;
    Point* ps = new Point[n];
    for(int i=0;i<n;i++){
      int x,y;cin >> x >> y;
      new (&ps[i]) Point(x,y);
    }
    double max = 0, cur;
    int s,e;
    for(int i=0;i<n;i++){
      for(int k=i+1;k<n;k++){
        cur = ps[i].getDisTo(ps[k]);        
        if(max < cur){
          s = i; e=k;
          max = cur;
        }
      }
    }
    cout << "The longeset distance is "<< fixed << setprecision(2) << max << ",between p["
          << s << "] and p[" << e << "].\n";
    for(int i=0;i<n;i++){
      ps[i].~Point();
    }
  }
}