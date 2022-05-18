#include<bits/stdc++.h>
using namespace std;

bool valid_input(string eq)
{
    int index = eq.substr(1,eq.size()-1).find(eq[0]);
    if(index < 0 || index >= eq.size()){
        return true;
    }
    return false;
}

string infixToPostfix(string s)
{
    map<char, int> priority; priority['\''] = 3, priority['&'] = 2, priority['|'] = 1;
    stack<char> st; 
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;
 
        else if (c == '(')
            st.push('(');
 
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
 
        else {
            while (!st.empty()
                   && priority[s[i]] <= priority[st.top()]) {
                if (c == '\'' && st.top() == '\'')
                    break;
                else {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
 
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    return result;
}

vector<string> excute(string postfix){
    vector<string> result;
    stack<string> chars;
    string excuted = "";
    
    for (int i = 0; i < postfix.length(); i++) {
        string excuted = "";
        char l = postfix[i];
        string c(1, postfix[i]);
        
        if ((l >= 'a' && l <= 'z') || (l >= 'A' && l <= 'Z')
            || (l >= '0' && l <= '9')) {
                chars.push(c);
            }
        else{
            if(l == '\''){
                excuted += chars.top() + c;
                chars.pop();
            }
            else {
                for(int i = 0; i < 2; i++) {
                    excuted += chars.top();
                    if(i == 0)
                    {
                        excuted += c;
                    }
                    chars.pop();
                }
                //cout << excuted << endl;
                result.push_back(excuted);
            }
            chars.push(excuted);
        }
    }
    
    return result;
}


int main()
{
    string exp = "a&b&c";
    string postfix = infixToPostfix(exp);
    cout << "Main: " << postfix << endl;
    vector<string> result = excute(postfix);
    for(auto u: result){
        cout << u << endl;
    }
    return 0;
}
