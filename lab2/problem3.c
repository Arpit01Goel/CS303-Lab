#include <dirent.h>   
#include <unistd.h>   
#include <sys/stat.h> 
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void delete_dir(const char *path) {
    DIR *d = opendir(path);
    struct dirent *entry;
    char fullpath[1024];

    if (!d) return;

    while ((entry = readdir(d)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        struct stat st;
        stat(fullpath, &st);

        if (S_ISDIR(st.st_mode)) {
            delete_dir(fullpath); 
        } else {
            unlink(fullpath); 
        }
    }

    closedir(d);
    rmdir(path); 
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        perror("rmdir");
        return 1;
    }
    delete_dir(argv[1]);
    return 0;
}