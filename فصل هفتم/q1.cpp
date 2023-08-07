#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>  

const int h = 6;
const int w = 77;
std::vector<std::vector<char>> matrix;
int carRow;
int carCol;
int score = 0;

struct Vehicle {
    char symbol;
    int speed;
};

std::vector<Vehicle> vehicles = {
    {'C', 4},  
    {'M', 2},  
    {'B', 3},  
    {'T', 1}   
};

Vehicle randomVehicle;

void initializeMatrix() {
    int randomIndex = rand() % vehicles.size();
    randomVehicle = vehicles[randomIndex];
    matrix.clear();
    matrix.resize(h, std::vector<char>(w, ' '));

     
    matrix[0] = std::vector<char>(w, '-');
    matrix[h - 1] = std::vector<char>(w, '-');

     
    srand(time(nullptr));
    int count = 0;
    while (count < 10) {
        int row = rand() % (h - 2) + 1;
        int col = rand() % (w - 5) + 5;   
        if (matrix[row][col] == ' ') {
            matrix[row][col] = (count % 2 == 0) ? '*' : '|';
            count++;
        }
    }

     
    carRow = h / 2;
    carCol = 0;
}

void drawMatrix() {
    system("cls");  
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i == carRow && j == carCol) {
                std::cout << randomVehicle.symbol;  
            } else {
                std::cout << matrix[i][j];
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Score: " << score << std::endl;
}

void checkCollision() {
    if (matrix[carRow][carCol] == '*' || (randomVehicle.speed > 1 && matrix[carRow][carCol + 1] == '*')) {
        score++;
        matrix[carRow][carCol] = ' ';  
        if(randomVehicle.speed > 1 && matrix[carRow][carCol + 1] == '*'){
            matrix[carRow][carCol + 1] = ' ';
        }
    } else if (matrix[carRow][carCol] == '|' || carCol == w - 1 || carCol >= w|| (randomVehicle.speed > 1 && matrix[carRow][carCol + 1] == '|')) {
        system("cls");  
        std::cout << "Game Over!" << std::endl;
        std::cout << "Score: " << score << std::endl;
        if (carCol == w - 1) {
            std::cout << "You Win!" << std::endl;
        } else {
            std::cout << "You Lose!" << std::endl;
        }
        std::cout << "Play again? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            initializeMatrix();
            score = 0;
            carCol = 0;
        } else {
            exit(0);
        }
    }
}

void gameLoop() {
    drawMatrix();
    checkCollision();

     
    char key = getch();  
    if (key == 'w' && carRow > 0) {
        carRow--;
    } else if (key == 'd' && carCol < w - 1) {
        carCol+=randomVehicle.speed;
    } else if (key == 's' && carRow < h - 2) {
        carRow++;
    }

     
    gameLoop();
}

int main() {
    initializeMatrix();
    gameLoop();
    return 0;
}