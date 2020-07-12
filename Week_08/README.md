### 初级排序
```
class Sort {
public:
    void bubbleSort(vector<int>& arr) {
        int len = arr.size();
        for(int i = 0; i < len - 1; i++) {
            for(int j = 0; j < len() - i - 1; j++) {
                if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
            }
        }
    }

    void selectionSort(vector<int>& arr) {
        int len = arr.size(), minIndex = 0;
        for(int i = 0; i < len - 1; i++) {
            minIndex = i;
            for(int j = i + 1; j < len; j++) {
                if(arr[minIndex] > arr[j]) minIndex = j;
            }
            swap(arr[minIndex], arr[i]);
        }
    }

    void insertionSort(vector<int>& arr) {
        int len = arr.size(), preIndex = 0, current = 0;
        for(int i = 1; i < len; i++) {
            preIndex = i - 1;
            while(preIndex >= 0 && arr[preIndex] > current) {
                arr[preIndex + 1] = arr[preIndex];
                preIndex--;
            }
            arr[preIndex + 1] = current;
        }
    }
};
```