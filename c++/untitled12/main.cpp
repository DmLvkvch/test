#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

struct Open
{
    char resulte[26]={' '};
    float weight=0;
    int prior = 0;
};

int main ()
{
    std::vector<Open> solution;//������ �������
    Open *curr_sol;
    char first_edge, second_edge,//������� ������
         initial_vertex, terminal_vertex,
         str[26] = {0}, *finish = nullptr;
    bool vertex_duplication;
    float weight_cur, fin_w;
    int sol = 0, current = 0;//��������������� ����������
    float graf[26][26] = {0};

    std::cin >> initial_vertex >> terminal_vertex;
    current = initial_vertex - 97;

    while (std::cin >> first_edge >> second_edge >> weight_cur){
        graf[(int)first_edge - 97][(int)second_edge - 97] = weight_cur;
    }
    weight_cur = 0;

    while(1)
    {
        for (int i = 0; i < 26; i++)
            if (graf[current][i] != 0)
            {
                vertex_duplication = false;// ���� ������������ �������
                for (int j = 0; j < strlen(str); j++)
                    if((char)(i + 97) == str[j]) {vertex_duplication = true; break;}//����� ����������� �������
                if ((vertex_duplication == false) && ((char)(i + 97) != initial_vertex))
                {
                    curr_sol = new Open;//������ �������� � ������
                    solution.push_back(*curr_sol);
                    strcpy(solution.at(sol).resulte, &str[0]);
                    solution.at(sol).resulte[strlen(str)]=(char)(i + 97);
                    solution.at(sol).weight=graf[current][i] + weight_cur;
                    solution.at(sol).prior=terminal_vertex - 97 - i;
                    delete curr_sol;
                    sol++;
                }
            }
        sol--;
        std::sort(solution.begin(), solution.end(), [](const Open& a, const Open& b) {//���������� �� ��������
                  return (a.weight+a.prior) > (b.weight+b.prior);});

        if(finish != nullptr)//���� ���� ��� �����-�� ���������, �� �������� �������, ������ ��� ������ ����������
        {
            while (sol >=0)
                {
                    if(solution.at(sol).weight < fin_w) break;
                    else {solution.erase(solution.begin() + sol); sol--;}
                }
            if (sol == -1) break; //����� �� �������� �����
        }
        if(solution.at(sol).resulte[strlen(solution.at(sol).resulte) - 1] == terminal_vertex)
        {
            if(finish == nullptr) //���������� ������������� �������
            {
                finish = new char(strlen(solution.at(sol).resulte));
                strcpy(finish, &solution.at(sol).resulte[0]);
                fin_w=solution.at(sol).weight;
                solution.erase(solution.begin() + sol);
            }
            else {
                if(solution.at(sol).weight < fin_w)
                    {
                        delete[] finish; finish = new char(strlen(solution.at(sol).resulte));
                        strcpy(finish, &solution.at(sol).resulte[0]);
                        fin_w=solution.at(sol).weight;
                    }
                    solution.erase(solution.begin() + sol);
                }
            sol--;
            while (sol >=0)//�������� �������, ������ ������� ���
            {
                if(solution.at(sol).weight < fin_w) break;
                else {solution.erase(solution.begin() + sol); sol--;}
            }

            if (sol == -1) break;//����� �� �������� �����
        }
        current = (int)(solution.at(sol).resulte[strlen(solution.at(sol).resulte) - 1]) - 97;
        std::cout<<current<<" "<<strlen(solution.at(sol).resulte) - 1<<" "<<solution.at(sol).resulte[strlen(solution.at(sol).resulte) - 1]<<std::endl;
        strcpy(str, &solution.at(sol).resulte[0]);
        weight_cur = solution.at(sol).weight;
    }
    std::cout<<initial_vertex<<finish<<std::endl;
    return 0;
}
