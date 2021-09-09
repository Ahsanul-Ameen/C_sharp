#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

const int MPL = 300;

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
			else printf("%c", '|');
		}
		printf("%c%c%c %s\n", '|', '-', '-', dp->d_name);

		if (strcmp(dp->d_name, ".") && strcmp(dp->d_name, "..")) {
			strcpy(child_path, path);
			strcat(child_path, "/");
			strcat(child_path, dp->d_name);

			traverseTree(child_path, level + 4);
		}
	}

	if (closedir(dirp) == -1) {
		printf("Error closing directory\n");
	}
}


int main(void) {
	char file_path[MPL] = "..";

	printf("Enter path: ");
	scanf("%s", file_path);

	printf("path : %s\n", file_path);

	traverseTree(file_path);
	
	return 0;
}

// g++ -o file_tree.exe file_tree.c && ./file_tree.exe