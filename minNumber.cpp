class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string ans;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), [](string &s1, string &s2){return s1 + s2 < s2 + s1;});
        //[](string &s1, string &s2){return s1 + s2 < s2 + s1}
        //lambda表达式
        //sort函数当中的compare即为自定义的字符串升序比较器
    //     sort(strs.begin(), strs.end(), compare);
    //     static bool compare(const string& str1, const string& str2) {
    //     return str1 + str2 < str2 + str1;
    // }
        for(int i = 0; i < strs.size(); i++)
            ans += strs[i];
        return ans;
    }




};

bool operator()(string x, string y) {
    //仿函数
    return x + y < y + x;
}
string minNumber(vector<int>& nums){
    vector<string> retarr;
    for(auto e : nums){
        string temp = to_string(e);
        retarr.push_back(temp);
    }
    sort(retarr.begin(), retarr.end(), operator());
    string ret;
    for(auto e : retarr)
        ret += e;
    return ret;
}



























class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for(int i = 0; i < nums.size(); i++)
            strs.push_back(to_string(nums[i]));
        quickSort(strs, 0, strs.size()-1);
        string res;
        for(string s : strs)
            res.append(s);
        return res;
    }
private:
    void quickSort(vector<string> &strs, int l, int r){
        if(l >= r) return ;
        int i = 1, j = r;
        while(i < j){
            while(strs[j] + strs[l] >= strs[l] + strs[j]) j--; //找到比l小的j
            while(strs[i] + strs[l] <= strs[l] + strs[i]) i++; //找到比l大的i
            swap(strs[i], strs[j]);
        }
        swap(strs[i], strs[l]);
        quickSort(strs, l, i - 1);
        quickSort(strs, i +1, r);
    }
};