### 冒泡排序
```
class Solution {
public:
    void bubbleSort(vector<int>& arr) {
        int len = arr.size();
        for(int i = 0; i < len - 1; i++) {
            for(int j = 0; j < len() - i - 1; j++) {
                if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
            }
        }
    }
};
```

### 选择排序