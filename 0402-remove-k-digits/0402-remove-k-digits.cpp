class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty()&& k>0&&(st.top()-'0')>(num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        // if digits remove is remanining 
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        if(st.empty()) return "0"; // edge casee..
        string res="";
        // adding digits in the result string..
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    // leading zereoes..
    while(res.size() > 0 && res.back()=='0'){
        res.pop_back();

    }
    // reverse the result array to match the testcase...
    reverse(res.begin() ,res.end());
    if(res.empty()) return "0";
        
        return res;
    }
};