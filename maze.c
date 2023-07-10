nclude <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_USERS 100
#define USERNAME_LENGTH 20
#define PASSWORD_LENGTH 20

// Structure to store user information
typedef struct {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    bool isLoggedIn;
} User;

User users[MAX_USERS];
int numUsers = 0;

// Function to print the maze
void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to generate the maze
void generateMaze(char maze[ROWS][COLS]) {
    // Maze generation logic goes here

    // For illustration purposes, let's initialize the maze with walls and an exit
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS - 1 && j == COLS - 1) {
                maze[i][j] = 'E'; // Exit
            } else {
                maze[i][j] = '#'; // Wall
            }
        }
    }
}

// Function to sign up a new user
void signUp() {
    if (numUsers >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    // Check if the username already exists
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }

    newUser.isLoggedIn = false;
    users[numUsers++] = newUser;

    printf("User created successfully!\n");
}

// Function to log in an existing user
void logIn() {
    char username[USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            users[i].isLoggedIn = true;
            printf("Logged in successfully!\n");
            return;
        }
    }

    printf("Invalid username or password.\n");
}

// Function to access the user's personalized profile
void accessProfile() {
    char username[USERNAME_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, username) == 0) {
            if (users[i].isLoggedIn) {
                printf("Welcome to your profile, %s!\n", username);
                // Access the user's profile logic goes here
                return;
            } else {
                printf("You need to log in first to access your profile.\n");
                return;
            }
        }
    }

    printf("User not found.\n");
}

int main() {
    char maze[ROWS][COLS];

    generateMaze(maze);

    signUp();
    signUp();  // You can sign up additional users if needed

    logIn();

    printMaze(maze);

    accessProfile();

    return 0;
}
