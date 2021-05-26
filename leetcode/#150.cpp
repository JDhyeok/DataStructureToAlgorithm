class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        
        for(auto s:tokens){
            if(s.size()>1 || isdigit(s[0]))
                st.push(stoi(s));
            else{
                auto num1 = st.top(); 
                st.pop();
                auto num2 = st.top(); 
                st.pop();
                
                switch(s[0]){
                    case '+':
                        st.push(num2+num1);
                        break;
                    case '-':
                        st.push(num2-num1);
                        break;
                    case '*':
                        st.push(num2*num1);
                        break;
                    case '/':
                        st.push(num2/num1);
                        break;
                }
            }
        }
        

        return st.top();
    }
};