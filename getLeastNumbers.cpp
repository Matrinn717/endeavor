class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
       sort(arr.begin(),arr.end());
       ans.assign(arr.begin(),arr.begin()+k);
       return ans;
    }
};

//快排
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quickSort(arr, 0, arr.size()-1);
        vector<int> res;
        res.assign(arr.begin(), arr.begin() + k);
        return res;

    }
private:
    void quickSort(vector<int>& arr, int l, int r){
        //子数组长度为 1 时停止递归
        if (l >= r) return ;
        //哨兵划分操作（以 arr[l] 作为基准数）
        int i = 1, j = r;
        while(i < j){
            while(i < j && arr[j] >= arr[l]) j--;
            while(i < j && arr[i] >= arr[l]) i++;
            swap(arr[i],arr[j]);
        }
        swap(arr[l],arr[i]);
        // 递归左（右）子数组执行哨兵划分
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }
};