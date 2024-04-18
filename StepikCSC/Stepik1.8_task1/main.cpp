// #include <iostream>

// определите только функцию power, где
//    x - число, которое нужно возвести в степень
//    p - степень, в которую нужно возвести x
//

int power(int x, unsigned p)
{
    int answer = 1;
    for (unsigned n = 0; n < p; ++n)
    {
        answer *= x;
    }
    return answer;
}

int main()
{
    // std::cout << power(2, 4) << std::endl;
    power(2, 4);
    return 0;
}