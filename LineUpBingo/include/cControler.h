#ifndef CCONTROLER_H
#define CCONTROLER_H

#include "cView.h"
#include "cModel.h"

class cControler
{
    public:
        cControler(cView *);
        cControler();
        virtual ~cControler();
        void Game();

    protected:

    private:
    cView *mView;
    cModel *mModel;
};

#endif // CCONTROLER_H
