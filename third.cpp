#include <iostream>
#include <ctime>

const int gMaxArraySize = 9999;

void quick_sort(double *array, int array_size)
{
    if (array_size <= 1) 
        return;  // базовый случай
        
    int middle = array_size / 2; // находим середину массива
    std::cout << middle << std::endl;
    double *left = array;
    double *right = array + middle;

    int left_size = middle;
    int right_size = array_size - left_size;

    quick_sort(left, left_size);
    quick_sort(right, right_size);
    
    // работа с двумя отсортированными группами массива
    double *buffer = new double[array_size];
    int left_i = 0;
    int right_i = 0;
    int buffer_i = 0;
    
    while (left_i < left_size && right_i < right_size) 
    {
        if (left[left_i] <= right[right_i]) {
            // берем наименьшее число из левой части массива
            buffer[buffer_i] = left[left_i];
            left_i++;
            buffer_i++;
        } else 
        {
            // берем наименьшее число из правой части массива
            buffer[buffer_i] = right[right_i];
            right_i++;
            buffer_i++;
        }
    }
    
    while (left_i < left_size) 
    { 
        // если остались элементы в левой части, копируем их
        buffer[buffer_i] = left[left_i];
        left_i++;
        buffer_i++;
    }
    
    while (right_i < right_size) 
    { 
        // если остались элементы в правой части, копируем их
        buffer[buffer_i] = right[right_i];
        right_i++;
        buffer_i++;
    }
    
    // перемещаем числа из буффера в исходный массив
    for(int i = 0; i < array_size; i++) 
    {
        array[i] = buffer[i];
    }
    
    delete[] buffer;
}

void enter_array(double *array, int size)
{
    for (int i = 0; i < size; i++) 
    {
        std::cin >> array[i];
    }
}

void print_array(double *array, int size)
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    int array_size;
    
    std::cout << "Enter array size: " << std::endl;
    std::cin >> array_size;
    
    if (array_size <= 0 || array_size > gMaxArraySize) 
    {
        std::cerr << "Invalid array size" << std::endl;
        return 1;
    }
    
    double *array = new double[array_size];
    
    std::cout << "Enter numbers in array: " << std::endl;
    
    enter_array(array, array_size);
    quick_sort(array, array_size);
    
    std::cout << "Sorted array: " << std::endl;
    
    print_array(array, array_size);

    delete[] array;

    return 0;
}