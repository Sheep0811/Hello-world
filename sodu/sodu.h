//sudoku.h
class sudoku
{
public:
    sudoku();//��ȡ�ļ�����ʼ������
    void printsudo();//��ӡ����
    int solve();//���
    void outputsudoku();//������ļ� 
    int checksudoku();//��������Ƿ���ȷ
private:    
    int search();//�������
    int checkclear();//����δ��д�ĸ�����
    void base_solve();//������
    void clear_solv_sudoku(int, int, int);//ɾ�������ܵĺ�ѡ��
    void update_ques_sudoku();//��дΨһ��ѡ��������
    int ques_sudoku[9][9];//����
    int solv_sudoku[9][9][9];//��ѡ��
};