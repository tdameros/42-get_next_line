# GNL Project

## Description
The get_next_line project is a component of the 42 school curriculum that requires creating a function capable of reading a line from a file descriptor. The function should be able to handle multiple file descriptors and read from them independently without losing the reading thread.

## Description

The get_next_line function reads one line at a time from a file descriptor. Each time the function is called, it returns the next line from the file until the end of the file is reached.

The function prototype is as follows:

```c
char	*get_next_line(int fd);
```

The function returns `NULL` if the end of the file has been reached or if an error occurs.

## Usage

To use the get_next_line function, simply include the header file `get_next_line.h` in your project and call the function as follows:

```c
#include <stdlib.h>
#include <fcntl.h>

#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        // Do something with the line
        free(line);
	line = get_next_line(fd);
    }
    return (0);
}
```

## Conclusion

The get_next_line project is an essential project for any programmer as it teaches how to read from a file descriptor and handle multiple file descriptors. By implementing this function, one will gain a deeper understanding of how file I/O works in C and how to write efficient code.