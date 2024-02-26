#include <iostream>

class DynamicArray {
private:
    int *array;
    int capacity;
    int length;

public:
    DynamicArray() {
        capacity = 1;
        length = 0;
        array = new int[capacity];
    }

    ~DynamicArray() {
        delete[] array;
    }

    void append_element(int element) {
        if (length == capacity) {
            resize();
        }
        array[length] = element;
        length++;
    }

    int get_element_at_index(int index) {
        if (index < 0 || index >= length) {
            return 0;
        }
        return array[index];
    }

    int size() {
        return length;
    }

    void reset() {
        capacity = 1;
        length = 0;
        delete[] array;
        array = new int[capacity];
    }

private:
    void resize() {
        capacity *= 2;
        int *new_array = new int[capacity];
        for (int i = 0; i < length; ++i) {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;
    }
};

// Example usage
int main() {
    DynamicArray dynamic_array;
    dynamic_array.append_element(5);
    dynamic_array.append_element(10);
    dynamic_array.append_element(15);
    
    std::cout << "Size: " << dynamic_array.size() << std::endl;  // Output: 3
    std::cout << "Element at index 1: " << dynamic_array.get_element_at_index(1) << std::endl;  // Output: 10
    
    dynamic_array.reset();
    
    std::cout << "Size after reset: " << dynamic_array.size() << std::endl;  // Output: 0
    
    return 0;
}
