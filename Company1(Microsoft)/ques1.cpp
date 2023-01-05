class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();

        for(int i=0; i<n; i++){
            string s = tokens[i];
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                if(s=="+"){
                    st.push(op1+op2);
                }
                else if(s=="-"){
                    st.push(op1-op2);
                }
                else if(s=="*"){
                    st.push(op1*op2);
                }
                else{
                    st.push(op1/op2);
                }
            }
            else{
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};