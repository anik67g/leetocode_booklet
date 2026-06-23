class Solution {
public:
vector<int> findnse(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
         while(!st.empty()&& arr[st.top()]>=arr[i]) {
            st.pop();
         }
         if(st.empty()){
            ans[i]=n;
         }
         else{
            ans[i]=st.top();
         }
         st.push(i);
         
    } 
    return ans; 
}

vector<int> findpsee(vector<int>&arr){
    int n=arr.size();
stack<int> st;
vector<int> ans(n);
for(int i =0;i<n;i++){
    while(!st.empty() && arr[st.top()]>arr[i]){
        st.pop();
    }
    if(st.empty()){
        ans[i] = -1; 
    }
    else{
        ans[i]=st.top();
    }
    st.push(i);
}
return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
      int n =arr.size();
      int mod = (int)(1e9+7);

      long long total = 0;
vector<int>nse = findnse(arr);
vector<int>psee = findpsee(arr);
for(int i=0;i<n;i++){


int right = nse[i] -i;
int left = i-psee[i];

 long long val=(left*right*1LL*arr[i]*1LL)%mod;
total=(total+val)%mod;
}
  return total;
    }
};