#include "engine.h"
#include <cmath>
#include <QMessageBox>
#include <sstream>
using namespace std;

bool prev(string s1, string s2) {
    if (s1 == "^" || s1 == "*" || s1 == "/" || s1 == "|")
        return true;
    else if ((s1 == "+" || s1 == "-") && (s2 == "+" || s2 == "-"))
        return true;
    else
        return false;
}

int Engine::_atoi(string s,int radix) {
    int ans=0;
    for(int i=0;i<s.size();i++){
        char t=s[i];
        if(t>='0'&&t<='9') ans=ans*radix+t-'0';
        else ans=ans*radix+t-'a'+10;
    }
    return ans;
}

string Engine::_itoa(int n, int radix) {
    string ans = "";
    do {
        int t = n % radix;
        if (t >= 0 && t <= 9)
            ans += t + '0';
        else
            ans += t - 10 + 'a';
        n /= radix;
    } while (n != 0);
    reverse(ans.begin(), ans.end());
    return ans;
}

inline bool ishex(char ch) {
    return (ch=='a'||ch=='b'||ch=='c'||ch=='d'||ch=='e'||ch=='f');
}

bool Engine::numericCheck(string str) {
    for(auto i:str) {
        if(!isdigit(i)&&!ishex(i)) return false;
    }
    return true;
}

string Engine::convert(int predix, int radix) {
    if(!numericCheck(eq)) {
        QMessageBox::warning(NULL,"Error","No operators allowed in conversion",QMessageBox::Ok);
    }
    int n = _atoi(eq,predix);
    return _itoa(n,radix);
}

bool Engine::BracketCheck(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char chr = str[i];
        int l = -1, r = -1;
        l = dl.find(chr);
        r = dr.find(chr);
        if (l >= 0)
            s.push(chr);
        else if (r >= 0){
            if (!s.isEmpty() && s.top() == dl[r])
                s.pop();
            else
                return false;
        }
    }
    return s.isEmpty();
}

bool Engine::scanCheck(string str) {
    int cnt = 0;
    for(int i = 0; i < str.length(); i++) {
        if(isdigit(str[i])) {
            for(int j=i+1;j<str.length();j++) {
                if(!isdigit(str[j])) {
                    cnt++;
                    i=j;
                    break;
                }
            }
        }
    }
    bool flag = true;
    for(int i = 0; i < str.length(); i++) {
        flag=true;
        if(isdigit(str[i])) {
            flag=false;
            int pos = 0;
            for(int j=i+1;j<str.length();j++) {
                if(!isdigit(str[j])) {
                    cnt--;
                    pos=j;
                    break;
                }
            }
            for(int j=pos;j<str.length();j++) {
                if(str[j]=='+'||str[j]=='-'||str[j]=='*'||str[j]=='/'||str[j]=='^'||str[j]=='.') {
                    flag=true;
                }
                if(isdigit(str[j])) break;
            }
            if(cnt<=1) return true;
            if(!flag) return false;
        }

    }
    return true;
}

string process(string str) {
    bool mark = false;
    bool mark2 = false;
    string s2;
    for(int i=0;i<str.length();i++) {
        if(str[i]==')') {
            mark=true;
            continue;
        }
        if(mark&&str[i]==' ') continue;
        if(str[i]!='(') {
            mark=false;
            continue;
        }
        if(str[i]=='('&&mark) {
            for(int j=0;j<i;j++) {
                s2.push_back(str[j]);
            }
            s2.append("* ");
            for(int j=i;j<str.length();j++) {
                s2.push_back(str[j]);
                mark2=true;
            }
        }
    }
    if(mark2) return s2;
    else return str;
}

void Engine::result(string opr) {
    if(opr== "_") {
        double x = num.top();
        num.pop();
        num.push(-x);
        return;
    }
    if(opr== "l") {
        double x = num.top();
        num.pop();
        if(x<0) {
            QMessageBox::warning(NULL,"Error","log() must be positive",QMessageBox::Ok);
        }
        num.push(log(x));
        return;
    }
    if(opr== "|") {
        double x = num.top();
        num.pop();
        if(x==0) {
            QMessageBox::warning(NULL,"Error","Divide by zero",QMessageBox::Ok);
        }
        num.push(1/x);
        return;
    }
    if(opr== "s") {
        double x = num.top();
        num.pop();
        num.push(sin(x));
        return;
    }
    if(opr== "c") {
        double x = num.top();
        num.pop();
        num.push(cos(x));
        return;
    }
    if(opr== "t") {
        double x = num.top();
        num.pop();
        num.push(tan(x));
        return;
    }
    if(opr== "o") {
        double x = num.top();
        num.pop();
        num.push(1/tan(x));
        return;
    }
    double x = num.top();
    num.pop();
    double y = num.top();
    num.pop();
    double re = 0.0;
    if (opr == "+")
        re = y + x;
    else if (opr == "-")
        re = y - x;
    else if (opr == "*")
        re = y * x;
    else if (opr == "/"){
        if(x==0) {
            QMessageBox::warning(NULL,"Error","Divide by zero",QMessageBox::Ok);
        }
        re = y / x;
    }
    else if (opr == "^")
        re = pow(y, x);
    num.push(re);
}

Engine::Engine(string s) {
    eq = s;
    op.push("0");
}

string Engine::calc() {
    eq=process(eq);
    if(!BracketCheck(eq)) {
        QMessageBox::warning(NULL,"Error","Bracket doesn't match!",QMessageBox::Ok);
        return "Error";
    }
    if(!scanCheck(eq)) {
        QMessageBox::warning(NULL,"Error","Missing basic operators between two numbers",QMessageBox::Ok);
        return "Error";
    }
    string opr, s;
    double x;
    stringstream ss;
    ss.str(eq);
    while (ss >> opr) {
        if (opr == "+" || opr == "-" || opr == "*" || opr == "/") {
            s = op.top();
            while (prev(s, opr)) {
                result(s);
                op.pop();
                s = op.top();
            }
            op.push(opr);
        } else if (opr == "^" || opr == "(")
            op.push(opr);
        else if (opr == ")") {
            s = op.top();
            while (s != "(") {
                result(s);
                op.pop();
                s = op.top();
            }
            op.pop();
        } else if (opr == "=") {
            s = op.top();
            while (s != "0") {
                result(s);
                op.pop();
                s = op.top();
            }
            double x = num.top();
            num.pop();
            stringstream s2;
            s2<<x;
            if(op.ok&&num.ok)
            return s2.str();
            else return "Error";
        }else if(opr== "l") {
            op.push(opr);
        }
        else if(opr== "_") {
            op.push(opr);
        }
        else if(opr== "|") {
            op.push(opr);
        }
        else if(opr== "s") {
            op.push(opr);
        }
        else if(opr== "c") {
            op.push(opr);
        }
        else if(opr== "t") {
            op.push(opr);
        }
        else if(opr== "o") {
            op.push(opr);
        }
        else {
            x = atof(const_cast<const char *>(opr.c_str()));
            num.push(x);
        }
    }
}
