#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


int delete_dir(const char * path) {
    struct dirent* entry;
    DIR *dp = opendir(path);
    if (dp==NULL) {
        perror("opendir");
        return -1;
    }
    while ((entry = readdir(dp))!=NULL) {
        if (strcmp(entry->d_name, ".")==0 || strcmp(entry->d_name, "..")==0) continue;
        char full_path[4096];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name );

        struct stat stat
    }
}


int main(int argc, char* argv[], char* envp[]) {
    if (argc<2) {
        printf("invalid number of arguments \n");
        return 1;
    }
    if (delete_dir(argv[1])==0) {
        printf("Director '%s' deleted successfully. \n");
        
    }else {
        fprintf(stderr, "Failed to delete directory \n");
    }
    return 0;
}