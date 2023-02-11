#ifndef CMODEL_H
#define CMODEL_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

class cControler;

class cModel
    {
    public:
        cModel();
        cModel(cControler*);
        virtual ~cModel();
        void new_board(float k[7]);
        void n_board();
        virtual int Init();
        void GameLoop();
        void Pwyswietl();
        void mov_alg(int p,int turn); //M
        bool isWin();   //M
        bool isWinPion(); //M
        bool isWinPoz(); //M
        bool isWinDiag(); //M
        std::vector<std::vector<char>> plansza;

    private:
        const static int nr=7;
        cControler *mControler;

        float k[nr]={};
};

#endif // CMODEL_H
