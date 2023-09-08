#include<iostream>
#include<iomanip>
using namespace std;

int month_day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int month_day2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

bool check_run(int x){
  if(x%4 ==0 && x%100!=0 || x%400==0) return true;
  return false;
}

class Date {
    int year, month, day;
public:
    Date();                             // 缺省构造函数，给year、month、day分别赋值为1900、1、1
    Date(int y, int m, int d);          // 带参构造函数，给year、month、day分别赋参数的值
    int getYear();                      // 返回当前日期的年份
    int getMonth();                     // 返回当前日期的月份
    int getDay();                       // 返回当前日期的日
    void setDate(int y, int m, int d);  // 按参数重设日期的值
    void print();                       
    void addOneDay();                   // 在当前日期上加一天
};

Date::Date(){
  year=1900;month=1;day=1;
}
Date::Date(int y,int m,int d){
  year=y;month=m;day=d;
}
int Date::getYear(){
  return year;
}
int Date::getMonth(){
  return month;
}
int Date::getDay(){
  return day;
}
void Date::setDate(int y, int m, int d){
  year=y;month=m;day=d;
}
void Date::print(){
  cout
  <<setfill('0')
  <<year<<'/'
  <<setw(2)<<month<<'/'
  <<setw(2)<<day<<'\n';
}
void Date::addOneDay(){
  ++day;
  int flag=check_run(year);
  if(day>month_day[month] && !flag || flag && day>month_day2[month]){
    day=1;
    ++month;
    if(month>12){
      month=1;
      ++year;
    }
  }
}
int main(){
  int t;cin >> t;
  while(t--){
    int y,m,d;cin >> y >> m >> d;
    Date Mydate(y,m,d);
    cout << "Today is ";
    Mydate.print();
    Mydate.addOneDay();
    cout << "Tomorrow is ";
    Mydate.print();
  }
}