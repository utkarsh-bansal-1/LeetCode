class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c : s){
            if(c=='(' || c=='[' || c=='{'){
                stk.push(c);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                char c2=stk.top();
                if((c==')'&& c2=='(')||(c=='}' && c2=='{')||(c==']' && c2=='[')){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }


        return stk.empty();
    }
};