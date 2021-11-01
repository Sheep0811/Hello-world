//sudoku.cpp
#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::ios_base;
#include "sodu.h"

//读取文件并初始化数组
sudoku::sudoku()
{
    //读取文件到数组
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

    //初始化候选数
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

//检查数独是否正确
//正确返回1，错误返回0
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

//删除不可能的候选数
void sudoku::clear_solv_sudoku(int num1, int num2, int key)
{
    //清理自身
    for (int k = 0; k < 9; k++)
    {
        solv_sudoku[num1][num2][k] = 0;
    }

    for (int i = 0; i < 9; i++)
    {
        solv_sudoku[i][num2][key - 1] = 0;//清理行
        solv_sudoku[num1][i][key - 1] = 0;//清理列
    }

    //清理区块
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

//填写唯一候选数到数独
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

//返回数独空格数
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

//摒除求解
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

//打印数独
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

//搜索求解
int sudoku::search()
{
    //搜索第一个空格
    int blank_x, blank_y;//第一个空格地址
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

    //清理第一个数字此key可能性
    int test_key;//第一个要测试的key
    int test_key_count = 0;
    for (int k = 0; k < 9; k++)//没有其余选择跳出
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

    //记录数独
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

    //清理该解所有可能性
    for (int k = 0; k < 9; k++)
    {
        solv_sudoku[blank_x][blank_y][k] = 0;
    }

    //试填该解
    ques_sudoku[blank_x][blank_y] = test_key + 1;

    //摒除求解
    int result = solve();

    //返回值判断
    if (result == 1)
    {return 0; }

    //回溯
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
    //搜索求解
    search();
    return 0;
}

//求解
int sudoku::solve()
{
    for (int test = 0;;)
    {
        //检查完全性
        if (checkclear() == 0)
        {return 1; }

        //摒除数独
        base_solve();
        test = checkclear();

        //检查正确性
        int result = checksudoku();
        if (result == 1)//是-继续
        { }
        if (result == 0)//否-返回0
        {return 0; }

        //检查完全性
        int search_result;
        if (checkclear() == 0)
        {return 1; }

        //检查是否可以继续摒除
        if (checkclear() == test)
        {search_result = search(); }
        
        //回溯上一次搜索
        if (search_result == 1)
        {return 0; }
    }
}

//输出解文件
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