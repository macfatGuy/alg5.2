#include <iostream>
#include <vector>
#include <string>

void print_pyramid(const std::vector<int>& pyramid) {
  
}

void print_node(int index, const std::vector<int>& pyramid) {
    if (index >= pyramid.size() || index < 0) {
        std::cout << "Ошибка: Индекс вне диапазона" << std::endl;
        return;
    }

    int level = 0;
    int currentIndex = 0;
    int nodesAtLevel = 1;
    int parentIndex = -1;

    while (currentIndex < index) {
        currentIndex += nodesAtLevel;
        nodesAtLevel *= 2;
        level++;
    }

    if (level == 0) std::cout << level << " root " << pyramid[index] << std::endl;
    else {
        parentIndex = (index - nodesAtLevel / 2) / 2;
        std::cout << level << " " << ((index - currentIndex + nodesAtLevel / 2) % 2 == 0 ? "left" : "right") << "(" << pyramid[parentIndex] << ") " << pyramid[index] << std::endl;
    }

}

int get_parent(int index) {
    if (index == 0) return -1; 
    return (index - 1) / 2;
}

int get_left_child(int index, int size) {
    int leftChildIndex = 2 * index + 1;
    return (leftChildIndex < size) ? leftChildIndex : -1;
}

int get_right_child(int index, int size) {
    int rightChildIndex = 2 * index + 2;
    return (rightChildIndex < size) ? rightChildIndex : -1;
}


int main() {
    std::vector<int> pyramid = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

    std::cout << "Исходный массив: ";
    for (int val : pyramid) std::cout << val << " ";
    std::cout << std::endl;
    print_pyramid(pyramid);
    std::cout << std::endl;

    int currentIndex = 0;
    std::string command;

    while (true) {
        print_node(currentIndex, pyramid);
        std::cout << "Введите команду (up, left, right, exit): ";
        std::cin >> command;

        if (command == "up") {
            int parent = get_parent(currentIndex);
            if (parent == -1) {
                std::cout << "Ошибка! Отсутствует родитель." << std::endl;
            }
            else {
                currentIndex = parent;
                std::cout << "Ок" << std::endl;
            }
        }
        else if (command == "left") {
            int leftChild = get_left_child(currentIndex, pyramid.size());
            if (leftChild == -1) {
                std::cout << "Ошибка! Отсутствует левый потомок." << std::endl;
            }
            else {
                currentIndex = leftChild;
                std::cout << "Ок" << std::endl;
            }
        }
        else if (command == "right") {
            int rightChild = get_right_child(currentIndex, pyramid.size());
            if (rightChild == -1) {
                std::cout << "Ошибка! Отсутствует правый потомок." << std::endl;
            }
            else {
                currentIndex = rightChild;
                std::cout << "Ок" << std::endl;
            }
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Ошибка! Неверная команда." << std::endl;
        }
    }

    return 0;
}

