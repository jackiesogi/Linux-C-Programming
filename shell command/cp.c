#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{

    if(argc != 3)
    {
        printf("Usage: cp <source> <destinantion>\n");
    }
    else
    {
        int in, out;    // input, output file descripter
        char buf[100];  // buffer of reading source file
        int n;          // bytes has read

        in = open(argv[1], O_RDONLY);

        if (in == -1)
        {
            fprintf(stderr, "[ABORT] Cannot reach the file \"%s\"\n", argv[1]);
            exit(1);
        }

        out = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0x0777);

        if (out == -1)
        {
            fprintf(stderr, "[ABORT] Cannot reach the file \"%s\"\n", argv[2]);
            exit(1);
        }

        while ( (n = read(in, buf, 100)) > 0 )
        {
            if ( write(out, buf, n) != n )
            {
                fprintf(stderr, "[ABORT] Cannot write to the output file\n");
                exit(1);
            }

        }

        printf("OK\n");

        close(in);
        close(out);

    }

    return 0;
}