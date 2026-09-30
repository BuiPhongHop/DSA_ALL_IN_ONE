#include<bits/stdc++.h>
using namespace std;

template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
    ~ArrayList(){ delete[] data; }
    void add(T e);
    void add(int index, T e);
    int size();
    bool    empty();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
    void ensureCapacity(int index);
};

/*Question 18*/
template<class T>
void ArrayList<T>::ensureCapacity(int cap){
    if(cap > capacity){
        int new_capacity = 1.5 * capacity;
        // if new_capacity is still smaller than cap
        if(new_capacity < cap){
            new_capacity = cap;
        }
        
        T* newArray = new T[new_capacity];
        for(int i = 0; i < capacity; i++){
            newArray[i] = data[i];
        }
        delete[] data;
        data = newArray;
        capacity = new_capacity;
    }
}

template <class T>
void ArrayList<T>::add(T e) {
    ensureCapacity(count + 1);
    data[count] = e;
    ++count;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    ensureCapacity(count + 1);
    for(int i = count; i > index; i--){
        data[i] = data[i - 1];
    }
    data[index] = e;
    ++count;
}

template<class T>
int ArrayList<T>::size() {
    return count;
}


/*Question 19*/
template <class T>
T ArrayList<T>::removeAt(int index) {
    // 1. Kiếm tra index hợp lệ
    if (index < 0 || index >= count) {
        throw std::out_of_range("index is out of range");
    }
    // 2. Lưu lại giá trị cần trả về
    T remove_data = data[index];
    // 3. Dồn các phần tử đằng sau sang trái
    for (int i = index; i < count - 1; i++) {
        data[i] = data[i + 1];
    }
    // 4. Giảm số lượng phần tử
    --count;
    return remove_data;
}

template <class T>
bool ArrayList<T>::removeItem(T item) {
    for (int i = 0; i < count; i++) {
        if (data[i] == item) {
            removeAt(i);
            return true;
        }
    }
    return false;
}

template <class T>
void ArrayList<T>::clear() {
    // Giải phóng bộ nhớ mảng cũ
    if (data != NULL) {
        delete[] data;
    }
    // Đưa danh sách về trạng thái ban đầu
    capacity = 5;
    count = 0;
    data = new T[capacity];
}


/* Question 22 */
bool consecutiveOnes(vector<int>& nums) {
    int first = -1;
    int last = -1;

    // Tìm vị trí đầu tiên và cuối cùng của số 1
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] == 1) {
            if (first == -1) {
                first = i; // Vị trí xuất hiện đầu tiên
            }
            last = i; // Cập nhật vị trí xuất hiện cuối cùng
        }
    }

    // Nếu mảng không chứa số 1 nào
    if (first == -1) {
        return true;
    }

    // Kiểm tra xem tất cả các phần tử từ first đến last có phải là 1 hay không
    for (int i = first; i <= last; i++) {
        if (nums[i] != 1) {
            return false;
        }
    }

    return true;
}


/* Question 23 */
int buyCar(int* nums, int length, int k) {
    sort(nums, nums + length);
    int sum = 0;
    int count = 0;
    while(sum < k){
        sum += nums[count];
        if(sum <= k){
            ++count;
        }
    }
    return count;
}

/* Question 24 */
int equalSumIndex(vector<int>& nums) {
    long long totalSum = 0;
    // Tính tổng tất cả các phần tử trong mảng
    for (int num : nums) {
        totalSum += num;
    }
    
    long long leftSum = 0;
    // Duyệt qua từng chỉ số từ trái sang phải
    for (int i = 0; i < (int)nums.size(); i++) {
        // rightSum = Tổng toàn mảng - Tổng bên trái - Giá trị tại vị trí i
        long long rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum) {
            return i; // Trả về chỉ số i nhỏ nhất thỏa mãn
        }
        // Cập nhật leftSum cho phần tử tiếp theo
        leftSum += nums[i];
    }

    return -1; // Không tìm thấy vị trí thỏa mãn
}


/* Question 25 */
int longestSublist(vector<string>& words) {
    if (words.empty()) return 0;

    int max_len = 0;
    int current_len = 0;
    char last_char = '\0'; // Lưu chữ cái đầu của từ trước đó

    for (const string& word : words) {
        // Kiểm tra chuỗi rỗng để tránh lỗi crash khi truy cập word[0]
        if (word.empty()) {
            current_len = 0;
            last_char = '\0';
            continue;
        }

        // Nếu cùng chữ cái đầu với từ ngay trước đó
        if (word[0] == last_char) {
            current_len++;
        } else {
            // Khởi tạo dãy mới bắt đầu từ từ này
            current_len = 1;
            last_char = word[0];
        }

        // Cập nhật độ dài lớn nhất
        if(current_len > max_len) max_len = current_len;
    }

    return max_len;
}