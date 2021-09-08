#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "dirent.h"

constexpr auto MPL = 300;

void traverseTree(const char* path, const int level = 0) {
	DIR* dirp = opendir(path);
	if (!dirp) {
		//printf("Unable to open : %s\n", path);
		return;
	}

	char child_path[MPL];
	
	struct dirent* dp;
	while (dp = readdir(dirp)) {
		printf("\t");
		for (int t = 0; t < level; ++t) {
			if (t % 4) printf(" ");
			else printf("%c", 186);
		}
		printf("%c%c %s\n", 204, 205, dp->d_name);

		if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..")) {
			strcpy_s(child_path, path);
			strcat_s(child_path, "\\");
			strcat_s(child_path, dp->d_name);

			traverseTree(child_path, level + 4);
		}
	}

	if (closedir(dirp) == -1) {
		printf("Error closing directory\n");
	}
}


int main(void) {
	char file_path[MPL] = "..\\";

	printf("path : %s\n", file_path);
	traverseTree(file_path);
	
	return 0;
}