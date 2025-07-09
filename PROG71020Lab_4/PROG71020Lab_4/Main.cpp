#include <iostream>
#include <cmath>
using namespace std;

#define MAX 20  // The MAX that an array can hold/how much space we draw in

// Function to draw from the array
void Draw(int arr[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (arr[i][j] == 0) {
                cout << " ";
            }
            else {
                cout << "*";
            }
        }
        cout << "\n";
    }
}

// Function to calculate area based on filled cells
int CalculateArea(int arr[MAX][MAX]) {
    int count = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}
//since area is just the space a shape fills this is an alteritive to 

// Rectangle constructor 
void DrawRectangle(int arr[MAX][MAX], int top, int left, int height, int width) {
    for (int i = top; i < top + height && i < MAX; i++) {
        for (int j = left; j < left + width && j < MAX; j++) {
            arr[i][j] = 1;
        }
    }
}

// circle constructor
void DrawCircle(int arr[MAX][MAX], int centerX, int centerY, int radius) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            int dx = j - centerX;
            int dy = i - centerY;
            if (dx * dx + dy * dy <= radius * radius) {
                arr[i][j] = 1;
            }
        }
    }
}

int main() {

    //array place holder for classes
    int array[MAX][MAX];

    // Clear array
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            array[i][j] = 0;
        }
    }

    //construct rectangle
    DrawRectangle(array, 1, 1, 5, 8);
    cout << "Rectangle:\n";

    // Draw Rectangle 
    Draw(array);
    int rectArea = CalculateArea(array);
    cout << "Rectangle Area: " << rectArea << " units²\n\n";

    // Clear array for next shape
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            array[i][j] = 0;
        }
    }

    //constrruct circle
    DrawCircle(array, MAX / 2, MAX / 2, 6);
    cout << "Circle:\n";

    // Draw Circle
    Draw(array);
    int circleArea = CalculateArea(array);
    cout << "Circle Estimated Area: " << circleArea << " units²\n";

    return 0;
}