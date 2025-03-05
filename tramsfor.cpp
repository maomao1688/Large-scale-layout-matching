#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;

struct Point{
    int x;
    int y;
};

void R90(Point vertices[], int numVertices, int a, int b) {
    for (int i = 0; i < numVertices; i++) {
        int w = vertices[i].x;
        int t = vertices[i].y;
        vertices[i].x = a + t;
        vertices[i].y = b - w;
    }
}

void R180(Point vertices[], int numVertices, int a, int b) {
    for (int i = 0; i < numVertices; i++) {
        int w = vertices[i].x;
        int t = vertices[i].y;
        vertices[i].x = a - w;
        vertices[i].y = b - t;
    }
}

void R270(Point vertices[], int numVertices, int a, int b) {
    for (int i = 0; i < numVertices; i++) {
        int w = vertices[i].x;
        int t = vertices[i].y;
        vertices[i].x = a - t;
        vertices[i].y = b + w;
    }
}

void MX(Point vertices[], int numVertices, int a, int b) {
    for (int i = 0; i < numVertices; i++) {
        vertices[i].x = a + vertices[i].x;
        vertices[i].y = b - vertices[i].y;
    }
}

void MXR270(Point vertices[], int numVertices, int a, int b) {
    for (int i = 0; i < numVertices; i++) {
        int w = vertices[i].x;
        int t = vertices[i].y;
        vertices[i].x = a + t;
        vertices[i].y = b + w;
    }
}

void MXR180(Point vertices[], int numVertices, int a, int b) {
    for (int i = 0; i < numVertices; i++) {
        int w = vertices[i].x;
        int t = vertices[i].y;
        vertices[i].x = a - w;
        vertices[i].y = b + t;
    }
}

void MXR90(Point vertices[], int numVertices, int a, int b) {
    for (int i = 0; i < numVertices; i++) {
        int w = vertices[i].x;
        int t = vertices[i].y;
        vertices[i].x = a - t;
        vertices[i].y = b - w;
    }
}


int main() {
    // Define the given vertices
    Point vertices[] = {{0 , 0 }, {1 , 0 }, {1 , 1 }, {2 , 1 }, {2 , 2 },
                        {1 , 2 }, {1 , 3 }, {2 , 3 }, {2 , 4 }, {0 , 4 }};
    int numVertices = sizeof(vertices) / sizeof(vertices[0]);
    int l = 0 ;
    int h = 0 ;//standing vertic(l,h)
    printf("R0     INPUT 1\nR90    INPUT 2\nR180   INPUT 3\nR270   INPUT 4\nMX     INPUT 5\nMXR270 INPUT 6\nMXR180 INPUT 7\nMXR90 INPUT  8\n");
    int s;
    printf("please input s\n");
    scanf("%d",&s);
    switch(s){
        case 1:
        // Print the R0-transformed vertices
        printf("R0-transformed vertices:\n");
        for (int i = 0; i < numVertices; i++) {
        printf("(%d, %d)", vertices[i].x, vertices[i].y);
        if (i < numVertices - 1) {
            printf(",");
         	}
        } break;
        case 2:
        R90(vertices, numVertices, l, h);
        // Print the R90-transformed vertices
         printf("R90-transformed vertices:\n");
        for (int i = 0; i < numVertices; i++) {
        printf("(%d, %d)", vertices[i].x, vertices[i].y);
        if (i < numVertices - 1) {
            printf(",");
         	}
        } break;
        case 3:
        R180(vertices, numVertices, l, h);
        // Print the R180-transformed vertices
         printf("R180-transformed vertices:\n");
        for (int i = 0; i < numVertices; i++) {
        printf("(%d, %d)", vertices[i].x, vertices[i].y);
        if (i < numVertices - 1) {
            printf(",");
         	}
        } break;
        case 4:
        R270(vertices, numVertices, l, h);
        // Print the R270-transformed vertices
         printf("R270-transformed vertices:\n");
        for (int i = 0; i < numVertices; i++) {
        printf("(%d, %d)", vertices[i].x, vertices[i].y);
        if (i < numVertices - 1) {
            printf(",");
         	}
        } break;
        case 5:
        MX(vertices, numVertices, l, h);
        // Print the MX-transformed vertices
         printf("MX-transformed vertices:\n");
        for (int i = numVertices - 1; i > -1; i--) {
        printf("(%d, %d)", vertices[i].x, vertices[i].y);
        if (i > 0) {
            printf(",");
         	}
        } break;
        case 6:
        MXR270(vertices, numVertices, l, h);
        // Print the MXR270-transformed vertices
         printf("MXR270-transformed vertices:\n");
        for (int i = numVertices - 1; i > -1; i--) {
        printf("(%d, %d)", vertices[i].x, vertices[i].y);
        if (i > 0) {
            printf(",");
         	}
        } break;
        case 7:
        MXR180(vertices, numVertices, l, h);
        // Print the MXR180-transformed vertices
         printf("MXR180-transformed vertices:\n");
        for (int i = numVertices - 1; i > -1; i--) {
        printf("(%d, %d)", vertices[i].x, vertices[i].y);
        if (i > 0) {
            printf(",");
        	}
        } break;
        case 8:
        MXR90(vertices, numVertices, l, h);
        // Print the MXR90-transformed vertices
         printf("MXR90-transformed vertices:\n");
        for (int i = numVertices - 1; i > -1; i--) {
        printf("(%d, %d)", vertices[i].x, vertices[i].y);
        if (i > 0) {
            printf(",");
         	}
        } break;
        default:printf("please input again\n");
    }
    return 0;
}
