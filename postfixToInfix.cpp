//POSTFIX TO INFIX
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int convert(string postfix){
    string infix = "";
    int i = 0;
    int b1, b2;
    stack<int> s;
    
    while(postfix[i]!='\0'){
        if(postfix[i]>='0' && postfix[i]<='9'){
            s.push(postfix[i] - '0');
            i++;
        }else if(postfix[i]=='+'){
            
            b2 = s.top();
            s.pop();
            b1 = s.top();
            s.pop();
            int c;
            c=b1+b2;
            s.push(c);
            i++;
        }else if(postfix[i]=='-'){
            b2 = s.top();
            s.pop();
            b1 = s.top();
            s.pop();
            s.push(b1-b2);
            i++;
        }else if(postfix[i]=='/'){
            b2 = s.top();
            s.pop();
            b1 = s.top();
            s.pop();
            s.push(b1/b2);
            i++;
        }else if(postfix[i]=='*'){
            b2 = s.top();
            s.pop();
            b1 = s.top();
            s.pop();
            s.push(b1*b2);
            i++;
        }
    }
    return s.top();
}

int main(){
    string postfix;
    cin>>postfix;
    string infix;
    cout<<convert(postfix);
    cout<<"INFIX EXPRESSION: "<<infix<<endl;
    return 0;
}
