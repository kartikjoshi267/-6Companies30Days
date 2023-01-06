class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        stack<int> st;
        for (auto s : tokens){
            if (s == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first+second);
            } else if (s == "-"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second-first);
            } else if (s == "*"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first*second);
            } else if (s == "/"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second/first);
            } else {
                int num = stoi(s);
                st.push(num);
            }
        }
        
        return st.top();
    }
};
