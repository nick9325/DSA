class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;
        
        for(auto x:tokens){


            if(x=="+" || x=="-" || x=="*" || x=="/"){
                    long op2=st.top(); st.pop();
                    long op1=st.top(); st.pop();

                    switch(x.front()){

                        case '+':
                            op2=op1+op2;
                            break;
                        case '-':
                            op2=op1-op2;
                            break;
                        case '*':
                            op2=op1*op2;
                            break;
                        case '/':
                            op2=op1/op2;
                            break;
                    }
                    st.push(op2);
            }
            else{
                st.push(stoi(x));
            }
        }

        return st.top();
    }
};