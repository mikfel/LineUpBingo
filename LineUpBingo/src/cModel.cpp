#include "cModel.h"

cModel::cModel()
{
    Init();

}
//cModel cModel::operator++(int)
//{
//    cModel temp = *this;
//    ++*this;
//    return temp;
//}

cModel::cModel(cControler *aControler)
{
    Init();
    isWin();
    mControler = aControler;
}

cModel::~cModel()
{

}


int cModel::Init()
{

    plansza =
    {
        {'0','0','0','0','0','0','0'}, //0,0 0,1 0,2 ...
        {'0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0'},
        {'0','0','0','0','0','0','0'}
    };

//    txt_music.setFont(font);
//    txt_music.setString("Right arrow to change music");
//    txt_music.setCharacterSize(15);
//    txt_music.setFillColor(sf::Color::Green);
//    txt_music.setPosition(700,590);
//
//    txt_error1.setFont(font);
//    txt_error1.setString("Chose different\n column!!");
//    txt_error1.setCharacterSize(15);
//    txt_error1.setFillColor(sf::Color::Red);
//    txt_error1.setPosition(830,100);

    //Deklaracja dzwiekow

}
void cModel::new_board(float k[])
{
    for (int i=0;i<7;i++)
        k[i]=0;
    //zerowanie wektora plansza
    for (auto & rzad : plansza)
    {
        for (char & kolumna : rzad)
        {
             kolumna='0';
        }
    }
}

void cModel::mov_alg(int p, int turn)
{

    if (6-k[p]/118.33>=0&&k[p]<=595)
   {
        k[p]+=118.33;
        int r=7-(k[p]/118);

        if (!turn)
            {
            plansza[r][p] = '+';

            }
        else if (turn)
            {
            plansza[r][p] = '-';
            }
   }
}

bool cModel::isWinPoz()
{
    for (size_t kolumna=plansza.size()-1;kolumna>0;kolumna--)
    {
        for (size_t rzad=0;rzad<plansza[kolumna].size()-3;rzad++)
        {
            if (plansza[kolumna][rzad]=='-')
                if (plansza[kolumna][rzad+1]=='-')
                    if (plansza[kolumna][rzad+2]=='-')
                        if (plansza[kolumna][rzad+3]=='-')
                            {
                                //std::cout<<"Wygrana_POZ";
                                return true;
                            }
            if (plansza[kolumna][rzad]=='+')
                if (plansza[kolumna][rzad+1]=='+')
                    if (plansza[kolumna][rzad+2]=='+')
                        if (plansza[kolumna][rzad+3]=='+')
                        {
                            //std::cout<<"Wygrana_POZ";
                            return true;
                        }
        }
    }
    return false;
}
bool cModel::isWinPion()
{
    for (size_t kolumna=0;kolumna<plansza[kolumna].size();kolumna++)
    {
        for(int r=0;r<plansza.size()-3;r++)
           {
                if (plansza[r][kolumna]=='+')
                    if (plansza[r+1][kolumna]=='+')
                        if (plansza[r+2][kolumna]=='+')
                            if (plansza[r+3][kolumna]=='+')return true;//std::cout<<"WygranaPion";
                if (plansza[r][kolumna] == '-')
                    if (plansza[r+1][kolumna] == '-')
                        if (plansza[r+2][kolumna] == '-')
                            if (plansza[r+3][kolumna] == '-')return true;//std::cout<<"WygranaPion";
            }
    }
    return false;
}
bool cModel::isWinDiag() //Diag_P do sprawdzenia
{
    int pom_m=0;
    int pom_p=0;
    for (int k=0;k<3;k++)
{
    int j=0;
    for (int i=5-k;i>=0;i--)
    {
        if (plansza[i][j]=='-') pom_m++;
        else pom_m=0;
        if (plansza[i][j]=='+') pom_p++;
        else pom_p=0;
            j++;
    if (pom_m>=4 || pom_p>=4)
    {
        //std::cout<<"Wygrana DIAG_L!!\n`";
        return true;
    }
    }
    pom_m=0;
    pom_p=0;
}

for (int k=0;k<3;k++)
{
    int j=6;
    for (int i=0+k;i<=5;i++)
    {
        if (plansza[i][j]=='-') pom_m++;
        else pom_m=0;
        if (plansza[i][j]=='+') pom_p++;
        else pom_p=0;
        j--;
        if (pom_m>=4 || pom_p>=4)
        {
            //std::cout<<"Wygrana DIAG_L!!\n";
            return true;
        }
    }
    pom_m=0;
    pom_p=0;
}
//sprawdzanie przekatnych prawo-lewo
for (int k=0;k<3;k++)
{
    int j=6;
    for (int i=5-k;i>=0;i--)
    {
        if (plansza[i][j]=='-') pom_m++;
        else pom_m=0;
        if (plansza[i][j]=='+') pom_p++;
        else pom_p=0;
        j--;

        if (pom_m>=4 || pom_p>=4)
        {
            //std::cout<<"Wygrana DIAG_P!!\n";
            return true;
        }
    }
    pom_m=0;
    pom_p=0;
}

for (int k=0;k<3;k++)
{
    int j=5-k;
    for (int i=5;i>=0+k;i--)
    {
        if (plansza[i][j]=='-') pom_m++;
        else pom_m=0;
        if (plansza[i][j]=='+') pom_p++;
        else pom_p=0;
        j--;
        if (pom_m>=4 || pom_p>=4)
        {
            //std::cout<<"Wygrana DIAG_P!!\n";
            return true;
        }
    }
    pom_m=0;
    pom_p=0;
}
return false;
}
bool cModel::isWin()
{
    if ( isWinPoz()||isWinPion()||isWinDiag())
    {
      return true;
    }
    else
        return false;
}

void cModel::n_board()
{
    new_board(k);

}
