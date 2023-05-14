#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "\n*********************Welcome to the Seasons of Code************************\n";
    int N, M;
    cout << "\nEnter the no. participants are participating\n";
    cin >> N;
    double roll_number[N];
    int participant[N][5];
    cout << "Enter the participant information in the following format of\n1) roll number\n2) HTML level\n3) Python level\n4) DSA level\n5) Java level\n6) SQL level\nLevels are between 0 to 5\n";
    for (int i = 0; i < N; i++)
    {
        cout << "Enter the credentials of candidate " << i + 1 << endl;
        cin >> roll_number[i];
        for (int j = 0; j < 5; j++)
        {
            cin >> participant[i][j];
        }
        cout << endl;
    }
    cout << "Enter no. of projects \n";
    cin >> M;
    string project_name[M];
    int project[M][5];
    cout << "Enter the project information in the following format of\n1) Project Name\n2) HTML level\n3) Python level\n4) DSA level\n5) Java level\n6) SQL level\nLevels are between 0 to 5\n";
    for (int i = 0; i < M; i++)
    {
        cout << "Enter the credentials of candidate " << i + 1 << endl;
        cin >> project_name[i];
        for (int j = 0; j < 5; j++)
        {
            cin >> project[i][j];
        }
        cout << endl;
    }
    int project_completed = M;
    int participants_5[5] = {0};
    int project_5[5] = {0};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (participant[i][j] == 5)
            {
                participants_5[j]++;
            }
        }
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (project[i][j] == 5)
            {
                project_5[j]++;
            }
        }
    }
    int difference[5];
    for (int i = 0; i < 5; i++)
    {
        difference[i] = participants_5[i] - project_5[i];
    }
    int count = 1;
    while (count < 5)
    {
        for (int i = 0; i < 5 - count; i++)
        {
            if (difference[i] > difference[i + 1])
            {
                int temp = difference[i];
                difference[i] = difference[i + 1];
                difference[i + 1] = temp;
                for (int j = 0; j < M; j++)
                {
                    int k = project[j][i];
                    project[j][i] = project[j][i + 1];
                    project[j][i + 1] = k;
                }
            }
        }
        count++;
    }
    int t1 = 0;
    int z1 = 5;
    for (int i = 0; i < 6; i++)
    {
        for (int j = t1; j < M; j++)
        {
            if (project[j][0] == z1)
            {
                if (j != t1)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        int a1 = project[j][k];
                        project[j][k] = project[t1][k];
                        project[t1][k] = a1;
                    }
                }
                t1++;
            }
        }
        z1--;
    }
    int a2_1 = 0, a2_2 = 0;
    for (int i = 5; i >= 0; i--)
    {
        for (int j = 0; j < M; j++)
        {
            if (project[j][0] == i)
            {
                a2_1++;
            }
        }
        int z2 = 5;
        for (int l = 0; l < 6; l++)
        {
            for (int j = a2_2; j < a2_1; j++)
            {
                if (project[j][1] == z2)
                {
                    if (j != a2_2)
                    {
                        for (int k = 0; k < 5; k++)
                        {
                            int a1 = project[j][k];
                            project[j][k] = project[a2_2][k];
                            project[a2_2][k] = a1;
                        }
                    }
                    a2_2++;
                }
            }
            z2--;
        }
        a2_2 = a2_1;
    }
    int difference_X[5] = {0};
    for (int l = 5; l >= 0; l--)
    {
        int participants_X[5] = {0};
        int project_X[5] = {0};
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (participant[i][j] == l)
                {
                    participants_X[j]++;
                }
            }
        }
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (project[i][j] == l)
                {
                    project_X[j]++;
                }
            }
        }
        if (l == 5)
        {
            for (int i = 0; i < 5; i++)
            {
                difference_X[i] = participants_X[i] - project_X[i];
            }
        }
        else
        {
            for (int i = 0; i < 5; i++)
            {
                difference_X[i] = difference_X[i] + participants_X[i] - project_X[i];
            }
        }

        for (int i = 0; i < 5; i++)
        {
            while (difference_X[i] < 0)
            {
                for (int j = 0; j < M - 1; j++)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        project[j][k] = project[j + 1][k];
                    }
                }
                difference[i]++;
                M--;
            }
        }
    }
    if (M * 5 < N)
    {
        cout << "Total no. of projects that will be done" << M;
    }
    else
    {
        cout << "Total no. of projects that will be done" << N / 5;
    }
    return 0;
}