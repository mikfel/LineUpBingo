#include "cControler.h"
#include "cConsoleView.h"
#include "cNumberOfMoves.h"

cControler::cControler()
{
    mView = new cView(this);
    mModel = new cModel(this);
}

cControler::~cControler()
{
    //dtor
}

void cControler::Game()
{
    cConsoleView *c_view = new cConsoleView;
    cToken_p p;
    cNumberOfMoves numb;
    int turns=0;
    int tmp=0;
    bool consolewin=1;
    while(mView->isOpen())
    {
        mView->checkEvents();
        if (mView->checkMove()&&tmp<mView->moves)
        {
            mModel->mov_alg(mView->p,mView->Turn());
            tmp=mView->moves;
            turns++;
            c_view->Pwyswietl(*mModel);
        }
        if (mView->reset)
        {
            mModel->n_board();
            mView->reset=0;
        }
      if (mModel->isWin())
        {
            if (mView->Turn()) mView->WinYellow();

            else mView->WinRed();
        if (consolewin)
            {
            c_view->show_tokens(*mModel);
            p.show_tokens(*mModel);

            numb.operator++(turns);
            numb.display_moves();
            numb.operator--(turns);
            numb.display_reset();
            consolewin=0;
            }
        }

    }
}
