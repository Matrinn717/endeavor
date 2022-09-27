class Solution {
    private:
    void reverse(string& s,int left,int right){
        while(left<=right){
            swap(s[left],s[right]);
            ++left;
            --right;
        }
    }
public:
    string reverseLeftWords(string s, int n) {
        int num=s.size()-1;
        reverse(s,0,num);
        reverse(s,0,num-n);
        reverse(s,num-n+1,num);
        return s;
    }
};