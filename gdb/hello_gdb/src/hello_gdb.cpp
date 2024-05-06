#include <iostream>

int mul2(int i)
{
	return i << 1;
}

int main()
{
	int i = mul2(7);
	std::cout << i << std::endl;
	return 0;
}
