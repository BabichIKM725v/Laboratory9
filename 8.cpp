#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int ROWS = 5;
    const int COLS = 5;
    float array[ROWS][COLS];

    srand(time(NULL));

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            array[i][j] = (rand() % 100) / 10.0;
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << array[i][j] << '\t';
        }
        cout << endl;
    }

    float max_val = array[0][0];
    int max_r = 0, max_c = 0;
    float sum_diag = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (array[i][j] > max_val)
            {
                max_val = array[i][j];
                max_r = i;
                max_c = j;
            }
        }

        sum_diag += array[i][i] + array[i][COLS - 1 - i]; // додаємо елементи головної та побічної діагоналі
    }

    float avg_diag = sum_diag / (ROWS * 2);

    cout << "\nMax element is " << max_val << " at Row: " << max_r + 1 << ", Col: " << max_c + 1 << endl;
    cout << "Average of both diagonals: " << avg_diag << endl;

    return 0;
}
