#include <iostream>
#include <string>

class Image
{
public:
    void GetImageInfo()
    {
        for (int i = 0; i < size; ++i)
        {
            std::cout << pxls[i].GetInfo() << std::endl;
        }
    }

private:
    class Pixel
    {
    public:
        Pixel(int r, int g, int b)
        {
            this->r = r;
            this->g = g;
            this->b = b;
        }

        std::string GetInfo()
        {
            return "r: " + std::to_string(r) + " g: " + std::to_string(g) + " b: " + std::to_string(b);
        }

    private:
        int r;
        int g;
        int b;
    };

    static const int size = 5;
    Pixel pxls[size]{Pixel(0, 0, 0), Pixel(0, 0, 0), Pixel(0, 0, 0), Pixel(0, 0, 0), Pixel(0, 0, 0)};
};

int main()
{
    Image img;
    img.GetImageInfo();
    return 0;
}