#include <iostream>
#include <string>
#include <vector>

class SmartVectorClass
{
public:
    static const int size_pointers;
    static std::vector<std::string> pointers;
    ;

    SmartVectorClass(int size)
    {
        this->data = new int[size];
        this->size = size;

        for (int i = 0; i < size_pointers; ++i)
        {
            // pointers.push_back(std::string{})
            std::to_string((void*)(this->data));
            // std::cout << (this->data)
            // if (!pointers[i])
            // {
            //     pointers[i] = &(this->data);
            //     break;
            // }
        }
    }

    static void printPointers()
    {
        for (int i = 0; i < SmartVectorClass::size_pointers; ++i)
        {
            // std::cout << i << " " << pointers[i] << std::endl;
        }
    }

    ~SmartVectorClass()
    {
        delete[] data;
        data = nullptr;
    }

private:
    int* data;
    int size;
};

const int SmartVectorClass::size_pointers = 10;
int** SmartVectorClass::pointers[SmartVectorClass::size_pointers];

int main()
{

    SmartVectorClass sv1(5);
    SmartVectorClass sv2(10);
    SmartVectorClass sv3(15);

    SmartVectorClass::printPointers();

    sv2.~SmartVectorClass();
    SmartVectorClass::printPointers();

    return 0;
}