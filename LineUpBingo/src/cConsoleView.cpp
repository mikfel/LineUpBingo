#include "cConsoleView.h"

cConsoleView::cConsoleView()
{
    counter_m=0;
}

cConsoleView::~cConsoleView()
{
    //dtor
}

int cConsoleView::Init()
{
    cConsoleView c;
    std::cout<<"Nothing to initialize here!";
    //std::cout<<c;
}

void cConsoleView::Pwyswietl(cModel &model)
{
    for (size_t rzad=0;rzad<model.plansza.size();rzad++)
    {
        for (size_t kolumna=0;kolumna<model.plansza[rzad].size();kolumna++)
        {
            std::cout << "[" << model.plansza[rzad][kolumna] << "]";
        }
        std::cout << "\n";
    }
    std::cout << " 0  1  2  3  4  5  6\n";
}

void cConsoleView::show()
{
    Pwyswietl(*mModel);
}

void cConsoleView::show_tokens(cModel &model)
{
     for (size_t rzad=0;rzad<model.plansza.size();rzad++)
    {
        for (size_t kolumna=0;kolumna<model.plansza[rzad].size();kolumna++)
        {
            if (model.plansza[rzad][kolumna]=='-') counter_m++;
        }
    }
    std::cout<<"\nIlosc zoltych: "<<counter_m;
}
