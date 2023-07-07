#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * The function "printBoard" prints a 10x10 puzzle board represented by a vector of vectors of
 * characters.
 * 
 * @param puzzle The parameter "puzzle" is a reference to a 2D vector of characters. It represents a
 * 10x10 grid or board.
 */
void printBoard(vector<vector<char>> &puzzle)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << puzzle[i][j];
        }
        cout << endl;
    }
}

/**
 * The function "checkHorizontal" checks if a word can be placed horizontally in a matrix and updates
 * the matrix accordingly.
 * 
 * @param x The x parameter represents the row index of the starting position for placing the word
 * horizontally in the matrix.
 * @param y The parameter "y" represents the starting column index in the matrix where the word will be
 * placed horizontally.
 * @param matrix A 2D vector representing the matrix of characters.
 * @param currentWord The currentWord parameter is a string that represents the word that we want to
 * check if it can be placed horizontally in the matrix.
 * 
 * @return a vector of vectors of characters (vector<vector<char>>).
 */
vector<vector<char>> checkHorizontal(int x, int y,vector<vector<char>> matrix,string currentWord)
{
    int n = currentWord.length();

    for (int i = 0; i < n; i++)
    {
        if (matrix[x][y + i] == '-' ||
            matrix[x][y + i] == currentWord[i])
        {
            matrix[x][y + i] = currentWord[i];
        }
        else
        {

            // this shows that word cannot
            // be placed horizontally
            matrix[0][0] = '@';
            return matrix;
        }
    }

    return matrix;
}

/**
 * The function "checkVertical" checks if a word can be placed vertically in a matrix and updates the
 * matrix accordingly.
 * 
 * @param x The x parameter represents the starting row index where the word will be placed vertically
 * in the matrix.
 * @param y The parameter "y" represents the column index in the matrix where the vertical word
 * placement starts.
 * @param matrix A 2D vector representing the matrix of characters.
 * @param currentWord The current word that we want to check if it can be placed vertically in the
 * matrix.
 * 
 * @return a vector of vectors of characters (vector<vector<char>>).
 */
vector<vector<char>> checkVertical(int x, int y,
                                   vector<vector<char>> matrix,
                                   string currentWord)
{
    int n = currentWord.length();

    for (int i = 0; i < n; i++)
    {
        if (matrix[x + i][y] == '-' ||
            matrix[x + i][y] == currentWord[i])
        {
            matrix[x + i][y] = currentWord[i];
        }
        else
        {

            // this shows that word
            // cannot be placed vertically
            matrix[0][0] = '@';
            return matrix;
        }
    }
    return matrix;
}


/**
 * The function "solveCrosswordPuzzle" recursively solves a crossword puzzle by checking all possible
 * alignments of words horizontally and vertically.
 * 
 * @param matrix The crossword puzzle grid, represented as a 2D vector of characters.
 * @param words The "words" parameter is a vector of strings that contains the words to be filled in
 * the crossword puzzle.
 * @param index The parameter "index" is used to keep track of the current word being placed in the
 * crossword puzzle. It starts with a value of 0 and is incremented each time a word is successfully
 * placed in the puzzle.
 * @param n The parameter `n` represents the size of the crossword puzzle grid. It indicates the number
 * of rows and columns in the `matrix` vector.
 * 
 * @return The function does not explicitly return a value. However, it does have a return statement at
 * the end of the function, which is used to exit the function and return control to the calling
 * function.
 */
void solveCrosswordPuzzle(vector<vector<char>> matrix, vector<string> &words, int index, int n)
{
    if (index < words.size())
    {
        string currentWord = words[index];
        int maxLen = n - currentWord.length();

        // loop to check the words that can align vertically.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= maxLen; j++)
            {
                vector<vector<char>> temp = checkVertical(j, i,
                                                          matrix, currentWord);

                if (temp[0][0] != '@')
                {
                    solveCrosswordPuzzle(temp, words, index + 1, n);
                }
            }
        }

        // loop to check the words that can align horizontally.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= maxLen; j++)
            {
                vector<vector<char>> temp = checkHorizontal(i, j,matrix, currentWord);

                if (temp[0][0] != '@')
                {
                    solveCrosswordPuzzle(temp, words, index + 1, n);
                }
            }
        }
    }
    else
    {

        printBoard(matrix);

        return;
    }
}

/**
 * The main function reads in a crossword puzzle grid and a list of words, and then calls a function to
 * solve the crossword puzzle.
 * 
 * @return The main function is returning an integer value of 0.
 */
int main()
{
    int row = 10;
    int col = 10;
    vector<vector<char>> puzzle(row, vector<char>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> puzzle[i][j];
        }
    }
    string words;
    cin >> words;
    vector<string> puzzleWords;
    string w = "";
    for (auto i : words)
    {
        if (i == ';')
        {
            puzzleWords.push_back(w);
            w = "";
        }
        else
        {
            w += i;
        }
    }
    puzzleWords.push_back(w);
    solveCrosswordPuzzle(puzzle, puzzleWords, 0, row);

    return 0;
}