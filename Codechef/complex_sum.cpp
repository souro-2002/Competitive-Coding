#include<iostream>
using namespace std;
class complex{
    int a,b;
    public:
        void assign_val(int v1,int v2){
            a=v1;
            b=v2;
        }
        void print(){
            cout<<"The sum of the complex number is "<<a<<" + "<<b<<'i'<<endl;
        }
        friend complex sum_complex(complex c1,complex c2);
};
complex sum_complex(complex c1,complex c2){
    complex sum;
    sum.assign_val((c1.a+c2.a),(c1.b+c2.b));
    return sum;
}
int main(){
    complex c1,c2,sum;
    int a1,a2,b1,b2;
    cout<<"Enter the specifications of the first complex number ="<<endl;
    cout<<"Integer part: ";
    cin>>a1;
    cout<<endl;
    cout<<"Imaginary part: ";
    cin>>b1;
    cout<<endl;
    cout<<"Enter the specifications of the second complex number ="<<endl;
    cout<<"Integer part: ";
    cin>>a2;
    cout<<endl;
    cout<<"Imaginary part: ";
    cin>>b2;
    cout<<endl;
    c1.assign_val(a1,b1);
    c2.assign_val(a2,b2);
    sum=sum_complex(c1,c2);
    sum.print();
}
    
