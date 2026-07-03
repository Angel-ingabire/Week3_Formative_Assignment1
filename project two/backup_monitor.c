#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

int main(void)
{
    const char *log_path = "backup.log";
    const char *data_path = "backup_data.txt";
    const char *message = "Backup started\n";
    int fd;
    ssize_t written;
    char buffer[128];

    fd = open(data_path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("open data file");
        return 1;
    }

    written = write(fd, message, strlen(message));
    if (written < 0)
    {
        perror("write data file");
        close(fd);
        return 1;
    }

    if (close(fd) < 0)
    {
        perror("close data file");
        return 1;
    }

    fd = open(log_path, O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd < 0)
    {
        perror("open log file");
        return 1;
    }

    written = write(fd, "Backup log entry\n", 18);
    if (written < 0)
    {
        perror("write log file");
        close(fd);
        return 1;
    }

    if (close(fd) < 0)
    {
        perror("close log file");
        return 1;
    }

    fd = open(data_path, O_RDONLY);
    if (fd < 0)
    {
        perror("open data file for read");
        return 1;
    }

    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0)
    {
        perror("read data file");
        close(fd);
        return 1;
    }

    buffer[bytes_read] = '\0';
    printf("Read content: %s", buffer);

    if (close(fd) < 0)
    {
        perror("close read file");
        return 1;
    }

    return 0;
}
