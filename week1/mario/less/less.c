#include <stdio.h>
#include <cs50.h>

void repeat(char c, int times)
{
    while (times-- > 0)
    {
        printf("%c", c);
    }
}

int main()
{
    int height;

    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        int num_spaces = height - i - 1;
        int num_hashes = i + 1;

        repeat(' ', num_spaces);
        repeat('#', num_hashes);

        printf("\n");
    }
}