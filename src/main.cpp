#include <sys/stat.h>
#include <fstream>
#include <iostream>

inline void print_usage()
{
    printf("Creates a new file.\n\n");
    printf("TOUCH [filename]\n\n");
}

int main(int arg_count, char *args[])
{
    const int actual_arg_count = arg_count - 1;

    if (actual_arg_count > 0)
    {
        const char *filepath = (args[1]);

        struct stat buffer;
        const bool exists = stat((const char *const)filepath, &buffer) == 0;

        if (!exists)
        {
            std::ofstream dest_file((char *)filepath);
            dest_file << "";
            dest_file.close();
        }
        else
        {
            printf("[Files] File with name %s already exists.\n", filepath);
        }
    }
    else
    {
        print_usage();
    }

    return 0;
}