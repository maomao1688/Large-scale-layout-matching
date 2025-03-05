#include <stdio.h>

typedef struct Point {
    int x;
    int y;
} Point;

void generateGrid(int start_x, int start_y, int row_spacing, int col_spacing, int row_width, int col_width) {
    FILE* file = fopen("net.txt", "w");
    if (file == NULL) {
        printf("Could not create the file.\n");
        return;
    }

    int rows = row_width / row_spacing;
    int cols = col_width / col_spacing;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Point point;
            point.x = start_x + j * col_spacing;
            point.y = start_y + i * row_spacing;

            fprintf(file, "%d %d\n", point.x, point.y);
        }
    }

    fclose(file);
}

int main() {
    int start_x = 1; // Starting x coordinate
    int start_y = 3; // Starting y coordinate
    int row_spacing = 4; // Row spacing
    int col_spacing = 5; // Column spacing
    int row_width = 200; // Row width
    int col_width = 200; // Column width

    generateGrid(start_x, start_y, row_spacing, col_spacing, row_width, col_width);
    printf("Grid coordinates have been saved to net.txt.\n");

    return 0;
}
