#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct MyAlloc : allocator<T> {
    T* allocate(size_t size) {
        cout << "Allocate Memory of Size = " << size << endl;
        return new T[size];
    }

    void deallocate(T* ptr, size_t size) {
        cout << "Deallocating Memory of Size = " << size << endl;
        delete[] ptr;
    }
};

int main(void) {
    vector<int, MyAlloc<int>> v;  // Pass an instance of MyAlloc to vector

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);
    v.push_back(70);

    // Access elements to trigger allocation and deallocation
    for(const auto& element : v) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
