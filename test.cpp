#include <iostream>
using namespace std;

int main() {
    int num = 2;
    int nums[10] = {10,20,30,40,50};
    int* num_ptr = &num;
    cout << nums << endl;
    cout << &nums << endl;
    cout << *nums << endl;
    cout << num_ptr << endl;
    num_ptr++;
    cout << num_ptr << endl;
    cout << *num_ptr << endl;

    int* mem[1];
    for(int i = -1000; i < 1000; i++) {
        cout << mem[i] << endl;
    }

    return 0;
}
