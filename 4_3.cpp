#include<iostream>
using namespace std;
class fuels{
    string fuel;
public:
    fuels(string f){
        fuel=f;
        cout<<"the fuel type of the car is:"<<fuel<<endl;
    }
};

class brand_info{
    string brand;
public:
    brand_info(string b){
        brand=b;
        cout<<"The brand of car is:"<<brand<<endl;
    }
};

class combined_info:private fuels,private brand_info{
    string car_name;
    int year;
public:
    combined_info(string f,string b,string name,int y):fuels(f),brand_info(b){
        car_name=name;
        year=y;
        cout<<"the car name is:"<<car_name<<endl;
        cout<<"the year bought is:"<<year<<endl;
    }
};

int main(){
    string fu,info,car;
    int year_bought;
    cout<<"Enter the fuel type in your car:";
    cin>>fu;
    cout<<endl;
    cout<<"Enter the brand of your car:";
    cin>>info;
    cout<<endl;
    cout<<"Enter the car name:";
    cin>>car;
    cout<<endl;
    cout<<"Enter the year the car was bought:";
    cin>>year_bought;
    cout<<endl;
    combined_info ci(fu,info,car,year_bought);
    cout<<endl<<"\n24CE076_PatelDarshan"<<endl;
}
