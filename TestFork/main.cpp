#include <iostream>
#include <stdio.h>
#include <unistd.h>

int main()
{
    std::cout << "getpid(): " << getpid() << std::endl;
    int p_id = fork();
    std::cout << "getpid(): " << getpid() << " id1: " << p_id << std::endl;
    std::cout << "getpid(): " << getpid() << " id: " << getpid() << std::endl;
    execl();
    pipe();

    return 0;
}