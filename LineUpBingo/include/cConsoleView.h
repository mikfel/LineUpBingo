#ifndef CCONSOLEVIEW_H
#define CCONSOLEVIEW_H
#include "cModel.h"
#include <iostream>

class cNumberOfTokens : public cModel
{
public:
    virtual void show_tokens(cModel &model)=0;
};


class cConsoleView : public cNumberOfTokens
{
    public:
        int counter_m=0;
        cModel *mModel;
        cConsoleView();
        virtual ~cConsoleView();
        void Pwyswietl(cModel &model);
        int Init();
        void show();
        virtual void show_tokens(cModel &model) override;

};

class cToken_p : public cNumberOfTokens
{

public:
    int counter_p=0;
    virtual void show_tokens(cModel &model) override
{
     for (size_t rzad=0;rzad<model.plansza.size();rzad++)
    {
        for (size_t kolumna=0;kolumna<model.plansza[rzad].size();kolumna++)
        {
            if (model.plansza[rzad][kolumna]=='+') counter_p++;
        }
    }
    std::cout<<"\nIlosc czerwonych: "<<counter_p<<std::endl;
}
private:
};




#endif // CCONSOLEVIEW_H
