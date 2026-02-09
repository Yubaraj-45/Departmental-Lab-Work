#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    int fd;
    char buf[1];

    if (argc < 2) {
        write(1, "Usage: ./a.out <filename>\n", 27);
        return 1;
    }

    /* Write stdin to file */
    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        write(1, "File open error\n", 16);
        return 1;
    }

    write(1, "Enter text (Ctrl+D to stop):\n", 29);
    while (read(0, buf, 1) > 0) {
        write(fd, buf, 1);
    }
    close(fd);

    /* Read file and print to stdout */
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        write(1, "File read error\n", 16);
        return 1;
    }

    write(1, "\nFile contents:\n", 16);
    while (read(fd, buf, 1) > 0) {
        write(1, buf, 1);
    }
    close(fd);

    return 0;
}