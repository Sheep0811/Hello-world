//sudoku.cpp
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios_base;
#include "sodu.h"

//��ȡ�ļ�����ʼ������
sudoku::sudoku()
{
    //��ȡ�ļ�������
    ifstream infile;
    infile.open("sudoku.txt");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            infile >> ques_sudoku[i][j];
        }
    }
    infile.close();

    //��ʼ����ѡ��
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (ques_sudoku[i][j] == 0)
            {
                for (int k = 0; k < 9; k++)
                {
                    solv_sudoku[i][j][k] = 1;
                }
            }
            else
            {
                for (int k = 0; k < 9; k++)
                {
                    solv_sudoku[i][j][k] = 0;
                }
            }
        }
    }
}

//��������Ƿ���ȷ
//��ȷ����1�����󷵻�0
int sudoku::checksudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (ques_sudoku[i][j] < 0 || ques_sudoku[i][j] >9)
            {return 0; }

            for (int k = 0; k < 9; k++)
            {
                for (int l = 0; l < 9; l++)
                {
                    if (i == k && ques_sudoku[i][j] == ques_sudoku[k][l] && ques_sudoku[i][j] && j != l)
                    {return 0; }
                    if (j == l && ques_sudoku[i][j] == ques_sudoku[k][l] && ques_sudoku[i][j] && i != k)
                    {return 0; }
                    if (((i >= 0 && i <= 2) && (j >= 0 && j <= 2) && (k >= 0 && k <= 2) && (l >= 0 && l <= 2) && ques_sudoku[i][j] == ques_sudoku[k][l]) && ques_sudoku[i][j] && i != k && j != l)
                    {return 0; }
                    if (((i >= 3 && i <= 5) && (j >= 0 && j <= 2) && (k >= 3 && k <= 5) && (l >= 0 && l <= 2) && ques_sudoku[i][j] == ques_sudoku[k][l]) && ques_sudoku[i][j] && i != k && j != l)
                    {return 0; }
                    if (((i >= 6 && i <= 8) && (j >= 0 && j <= 2) && (k >= 6 && k <= 8) && (l >= 0 && l <= 2) && ques_sudoku[i][j] == ques_sudoku[k][l]) && ques_sudoku[i][j] && i != k && j != l)
                    {return 0; }
                    if (((i >= 0 && i <= 2) && (j >= 3 && j <= 5) && (k >= 0 && k <= 2) && (l >= 3 && l <= 5) && ques_sudoku[i][j] == ques_sudoku[k][l]) && ques_sudoku[i][j] && i != k && j != l)
                    {return 0; }
                    if (((i >= 3 && i <= 5) && (j >= 3 && j <= 5) && (k >= 3 && k <= 5) && (l >= 3 && l <= 5) && ques_sudoku[i][j] == ques_sudoku[k][l]) && ques_sudoku[i][j] && i != k && j != l)
                    {return 0; }
                    if (((i >= 6 && i <= 8) && (j >= 3 && j <= 5) && (k >= 6 && k <= 8) && (l >= 3 && l <= 5) && ques_sudoku[i][j] == ques_sudoku[k][l]) && ques_sudoku[i][j] && i != k && j != l)
                    {return 0; }
                    if (((i >= 0 && i <= 2) && (j >= 6 && j <= 8) && (k >= 0 && k <= 2) && (l >= 6 && l <= 8) && ques_sudoku[i][j] == ques_sudoku[k][l]) && ques_sudoku[i][j] && i != k && j != l)
                    {return 0; }
                    if (((i >= 3 && i <= 5) && (j >= 6 && j <= 8) && (k >= 3 && k <= 5) && (l >= 6 && l <= 8) && ques_sudoku[i][j] == ques_sudoku[k][l]) && ques_sudoku[i][j] && i != k && j != l)
                    {return 0; }
                    if (((i >= 6 && i <= 8) && (j >= 6 && j <= 8) && (k >= 6 && k <= 8) && (l >= 6 && l <= 8) && ques_sudoku[i][j] == ques_sudoku[k][l]) && ques_sudoku[i][j] && i != k && j != l)
                    {return 0; }
                }
            }
        }
    }
    return 1;
}

//ɾ�������ܵĺ�ѡ��
void sudoku::clear_solv_sudoku(int num1, int num2, int key)
{
    //��������
    for (int k = 0; k < 9; k++)
    {
        solv_sudoku[num1][num2][k] = 0;
    }

    for (int i = 0; i < 9; i++)
    {
        solv_sudoku[i][num2][key - 1] = 0;//������
        solv_sudoku[num1][i][key - 1] = 0;//������
    }

    //��������
    if (num1 >= 0 && num1 <= 2)
    {
        if (num2 >= 0 && num2 <= 2)
        {
            for (int i = 0; i <= 2; i++)
            {
                for (int j = 0; j <= 2; j++)
                {
                    solv_sudoku[i][j][key - 1] = 0;
                }
            }
        }

        if (num2 >= 3 && num2 <= 5)
        {
            for (int i = 0; i <= 2; i++)
            {
                for (int j = 3; j <= 5; j++)
                {
                    solv_sudoku[i][j][key - 1] = 0;
                }
            }
        }

        if (num2 >= 6 && num2 <= 8)
        {
            for (int i = 0; i <= 2; i++)
            {
                for (int j = 6; j <= 8; j++)
                {
                    solv_sudoku[i][j][key - 1] = 0;
                }
            }
        }
    }

    if (num1 >= 3 && num1 <= 5)
    {
        if (num2 >= 0 && num2 <= 2)
        {
            for (int i = 3; i <= 5; i++)
            {
                for (int j = 0; j <= 2; j++)
                {
                    solv_sudoku[i][j][key - 1] = 0;
                }
            }
        }

        if (num2 >= 3 && num2 <= 5)
        {
            for (int i = 3; i <= 5; i++)
            {
                for (int j = 3; j <= 5; j++)
                {
                    solv_sudoku[i][j][key - 1] = 0;
                }
            }
        }

        if (num2 >= 6 && num2 <= 8)
        {
            for (int i = 3; i <= 5; i++)
            {
                for (int j = 6; j <= 8; j++)
                {
                    solv_sudoku[i][j][key - 1] = 0;
                }
            }
        }
    }

    if (num1 >= 6 && num1 <= 8)
    {
        if (num2 >= 0 && num2 <= 2)
        {
            for (int i = 6; i <= 8; i++)
            {
                for (int j = 0; j <= 2; j++)
                {
                    solv_sudoku[i][j][key - 1] = 0;
                }
            }
        }

        if (num2 >= 3 && num2 <= 5)
        {
            for (int i = 6; i <= 8; i++)
            {
                for (int j = 3; j <= 5; j++)
                {
                    solv_sudoku[i][j][key - 1] = 0;
                }
            }
        }

        if (num2 >= 6 && num2 <= 8)
        {
            for (int i = 6; i <= 8; i++)
            {
                for (int j = 6; j <= 8; j++)
                {
                    solv_sudoku[i][j][key - 1] = 0;
                }
            }
        }
    }
}

//��дΨһ��ѡ��������
void sudoku::update_ques_sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int count = 0;
            for (int k = 0; k < 9; k++)
            {
                if (solv_sudoku[i][j][k] == 1)
                {count++; }
            }
            if (count == 1)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (solv_sudoku[i][j][k] == 1)
                    {ques_sudoku[i][j] = k + 1; }
                }
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (ques_sudoku[i][j])
            {
                for (int k = 0; k < 9; k++)
                {
                    solv_sudoku[i][j][k] = 0;
                }
            }
        }
    }
}

//���������ո���
int sudoku::checkclear()
{
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (ques_sudoku[i][j] == 0)
            {count++; }
        }
    }
    return count;
}

//������
void sudoku::base_solve()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (ques_sudoku[i][j] != 0)
            {
                clear_solv_sudoku(i, j, ques_sudoku[i][j]);
            }
        }
    }
    update_ques_sudoku();
}

//��ӡ����
void sudoku::printsudo()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << ques_sudoku[i][j] << " ";
        }
        cout << endl;
    }
}

//�������
int sudoku::search()
{
    //������һ���ո�
    int blank_x, blank_y;//��һ���ո��ַ
    for (int i = 0, count = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (ques_sudoku[i][j] == 0)
            {
                blank_x = i;
                blank_y = j;
                count++;
                break;
            }
        }
        if (count)
        {break; }
    }

    //�����һ�����ִ�key������
    int test_key;//��һ��Ҫ���Ե�key
    int test_key_count = 0;
    for (int k = 0; k < 9; k++)//û������ѡ������
    {
        if (solv_sudoku[blank_x][blank_y][k] == 1)
        {
            test_key = k;
            solv_sudoku[blank_x][blank_y][k] = 0;
            test_key_count++;
            break;
        }
    }
    if (test_key_count == 0)
    {return 1; }

    //��¼����
    int mark_ques_sudoku[9][9];
    int mark_solv_sudoku[9][9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                mark_ques_sudoku[i][j] = ques_sudoku[i][j];
                mark_solv_sudoku[i][j][k] = solv_sudoku[i][j][k];
            }
        }
    }

    //����ý����п�����
    for (int k = 0; k < 9; k++)
    {
        solv_sudoku[blank_x][blank_y][k] = 0;
    }

    //����ý�
    ques_sudoku[blank_x][blank_y] = test_key + 1;

    //������
    int result = solve();

    //����ֵ�ж�
    if (result == 1)
    {return 0; }

    //����
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            for (int k = 0; k < 9; k++)
            {
                ques_sudoku[i][j] = mark_ques_sudoku[i][j];
                solv_sudoku[i][j][k] = mark_solv_sudoku[i][j][k];
            }
        }
    }
    //�������
    search();
    return 0;
}

//���
int sudoku::solve()
{
    for (int test = 0;;)
    {
        //�����ȫ��
        if (checkclear() == 0)
        {return 1; }

        //�������
        base_solve();
        test = checkclear();

        //�����ȷ��
        int result = checksudoku();
        if (result == 1)//��-����
        { }
        if (result == 0)//��-����0
        {return 0; }

        //�����ȫ��
        int search_result;
        if (checkclear() == 0)
        {return 1; }

        //����Ƿ���Լ������
        if (checkclear() == test)
        {search_result = search(); }
        
        //������һ������
        if (search_result == 1)
        {return 0; }
    }
}

//������ļ�
void sudoku::outputsudoku()
{
    ofstream outfile;
    outfile.open("sudokuanswer.txt");
    outfile << "The answer is:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            outfile << ques_sudoku[i][j] << " ";
        }
        outfile << endl;
    }
    outfile.close();
}