#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Check for valid input
  if (argc < 2) {
    printf("Usage: wcat enter filename...\n");
    return 1;
  }

  // Iterate over each file
  for (int i = 1; i < argc; i++) {
    // Open the file
    FILE* fp = fopen(argv[i], "r");
    if (fp == NULL) {
      printf("wcat: cannot open file %s\n", argv[i]);
      return 1;
    }

    // Read the file and print its contents
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
      printf("%s", buffer);
    }

    // Close the file
    fclose(fp);
  }

  return 0;
}
