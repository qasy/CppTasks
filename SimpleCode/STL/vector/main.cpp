#include <iostream>
#include <vector>

/*
    std::vector
*/

int main()
{
    std::vector<int> myVector;

    std::vector<int> myVector2{1, 2, 3, 4, 5};
    std::vector<int> myVector3 = {1, 2, 3, 4, 5};

    myVector.push_back(2);
    myVector.push_back(44);
    myVector.push_back(77);
    myVector.push_back(9);

    std::cout << "Количество элементов в векторе: " << myVector.size() << std::endl;

    // myVector[2000] = 1000; // Может быть ошибка, так как обращаемся в память, которая нам не доступна (можно
    // проверить valgrind)

    // myVector.at(2000); // Ошибка всегда, тут вызовется исключение std::out_of_range. Такно медленнее, т.к.
    // осуществляет проверку на диапазон)

    for (size_t i = 0; i != myVector.size(); ++i)
    {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    myVector.pop_back(); // Удаляем последний элемент
    std::cout << "Количество элементов в векторе: " << myVector.size() << std::endl;

    myVector.clear(); // Очищаем вектор
    std::cout << "Количество элементов в векторе: " << myVector.size() << std::endl;
    return 0;
}

// -Werror -pedantic-errors -Wall -Wextra -Wpedantic -Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy
// -Wduplicated-branches -Wduplicated-cond -Wextra-semi -Wfloat-equal -Wlogical-op -Wnon-virtual-dtor -Wold-style-cast
// -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo