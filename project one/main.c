#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/stat.h>

static void usage(const char *prog)
{
    fprintf(stderr, "Usage: %s <source_dir> <target_dir>\n", prog);
    exit(EXIT_FAILURE);
}

static int is_regular_file(const char *path)
{
    struct stat st;
    if (stat(path, &st) != 0)
    {
        return 0;
    }
    return S_ISREG(st.st_mode);
}

static int copy_file(const char *src_path, const char *dst_path)
{
    FILE *src = fopen(src_path, "rb");
    if (!src)
    {
        perror("fopen source");
        return -1;
    }

    FILE *dst = fopen(dst_path, "wb");
    if (!dst)
    {
        perror("fopen dest");
        fclose(src);
        return -1;
    }

    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0)
    {
        if (fwrite(buffer, 1, bytes, dst) != bytes)
        {
            perror("fwrite");
            fclose(src);
            fclose(dst);
            return -1;
        }
    }

    if (ferror(src))
    {
        perror("fread");
    }

    fclose(src);
    fclose(dst);
    return 0;
}

static void sync_directory(const char *src_dir, const char *dst_dir)
{
    DIR *dir = opendir(src_dir);
    if (!dir)
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char src_path[4096];
        char dst_path[4096];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst_dir, entry->d_name);

        if (is_regular_file(src_path))
        {
            printf("Syncing file: %s -> %s\n", src_path, dst_path);
            if (copy_file(src_path, dst_path) != 0)
            {
                fprintf(stderr, "Failed to sync %s\n", src_path);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        usage(argv[0]);
    }

    printf("Starting data_sync simulation from %s to %s\n", argv[1], argv[2]);
    sync_directory(argv[1], argv[2]);
    printf("Finished synchronization.\n");
    return EXIT_SUCCESS;
}
