#include <iostream>
#include "../include/cWidokMenu.h"
#include "../include/cWidokInstrukcjiObslugi.h"

using namespace std;

cWidokMenu::cWidokMenu()
{
    mOkno.create(sf::VideoMode(400, 400), "Gra Kamyki"); // tworzymy okno metoda create zamiast w konstruktorze. Jest to r�wnowa�ne.
    mModel = nullptr;
}

cWidokMenu::~cWidokMenu()
{
}


int cWidokMenu::RysujOknoMenu()
{


    if(!mPlanszaGrafika.loadFromFile("res/plansza.png"))
    {
        return EXIT_FAILURE;
    }

    mPlanszaGrafikaa.setTexture(mPlanszaGrafika);

    DrawFields instruk(instrukcja_klocek, mOkno);

    DrawFields zgr(zagraj_klocek, mOkno);

    mOkno.setActive();

    mOkno.clear(sf::Color(190,240,248));
    instruk.drawfield();
    zgr.drawfield();
    mOkno.display();
    mAktywneOkno = 1;
    return (0);
}

int cWidokMenu::isOpen()
{
    return mOkno.isOpen();
}

void cWidokMenu::setModel(cModelGra* aModel)
{
    mModel = aModel;
}
int cWidokMenu::SprawdzZdarzenia()
{
    if(mAktywneOkno == 1)
    {
        SprawdzZdarzeniaMenu();
    }
    else if(mAktywneOkno == 2)
    {
        SprawdzZdarzeniaOknaGry();
    }
    else
    {
        cout << "Nie wiem ktore okno \n";
    }
  return(0);
}

int cWidokMenu::SprawdzZdarzeniaMenu()
{
    if (mOkno.isOpen() && mOkno.pollEvent(mEvent))
    {
        if (mEvent.type == sf::Event::Closed)
        {
            mOkno.close();
        }
        if (mEvent.type == sf::Event::MouseButtonPressed)
        {
            if (mEvent.mouseButton.button == sf::Mouse::Left)
            {
                if(zagraj_klocek.isThisField(mEvent.mouseButton.x,mEvent.mouseButton.y))
                {
                    cout << "Kliknieto zagraj!\n";
                    RysujOknoGry();
                }
            }
            if(instrukcja_klocek.isThisField(mEvent.mouseButton.x,mEvent.mouseButton.y))
            {
                cout << "Kliknieto instrukcja!\n";
                cWidokInstrukcjiObslugi oknoZinstrukcja;
                oknoZinstrukcja.RysujOkno();

                while(oknoZinstrukcja.isOpen()) // Czekamy az okno zostanie zamkniete
                {
                    oknoZinstrukcja.SprawdzZdarzenia();
                }

            }
        }


    }
  return(0);
}

int cWidokMenu::RysujOknoGry()      // Ta funkcja odmalowuje stan planszy na podstawie danych pobranych z modelu!! W modelu ma sie znajdowac logika gry.
{
    mOkno.clear();
    mOkno.draw(mPlanszaGrafikaa);

    // Kasujemy pola z wektora zanim utworzymy je na nowo zeby wycieku pamieci nie bylo
    for ( int i = 0; i < mPolaGry.size(); i++ )
    {
        delete mPolaGry.at(i);
    }
    mPolaGry.clear();
    for ( int i = 0; i < mWynikiGry.size(); i++ )
    {
        delete mWynikiGry.at(i);
    }
    mWynikiGry.clear();
    // Kasujemy pola z wektora zanim utworzymy je na nowo zeby wycieku pamieci nie bylo

    for (int i = 0; i < 12; ++i)
    {
        string no = to_string(mModel->mData[i]);

        if (i < 6)
        {
            mPolaGry.push_back(new Field(20, 20, 50 + i * 60, 100, no, 15, i));

            //Field field(20, 20, 50 + i * 60, 100, no, 15, i);
            DrawFields draw(*mPolaGry.at(i), mOkno);
            draw.drawfield();
        }
        if (i >= 6)
        {
            mPolaGry.push_back(new Field(20, 20, 50 + (i-6)* 60, 280, no, 15, i));
            //Field field (20, 20, 50 + (i-6)* 60, 280, no, 15, i);
            DrawFields draw(*mPolaGry.at(i), mOkno);
            draw.drawfield();
        }

    }
    for( int i=0; i<2; i++)

    {
        string no = to_string(mModel->mWyniki[i]);
        mWynikiGry.push_back(new Field(20, 20, 20 + (i)* 350, 220, no, 15, i));
        //Field wyniki(20, 20, 20 + (i)* 350, 220, no, 15, i);
        DrawFields draw(*mWynikiGry.at(i), mOkno);
        draw.drawfield();
    }
    mOkno.display();
    mAktywneOkno = 2;
  return(0);
}


int cWidokMenu::SprawdzZdarzeniaOknaGry()
{
    if (mOkno.isOpen() && mOkno.pollEvent(mEvent))
    {
        if (mEvent.type == sf::Event::Closed)
        {
            mOkno.close();
        }
        if (mEvent.type == sf::Event::MouseButtonPressed)
        {
            if (mEvent.mouseButton.button == sf::Mouse::Left)
            {
                cout << "Kliknieto w miejsce x: " << mEvent.mouseButton.x << " y: " << mEvent.mouseButton.y << "\n";    // pomocniczo wyswietlam na ekran
                // Tu bedzie obsluga zdarzen w oknie gry
                // W tym miejscu po kliknieciu w pole ma byc wywolana odpowiednia metoda z klasy cModelGra->JakasMetoda A nastepnie wywolujemy metody RysujOknoGry zeby odwiezyc widok planszy.

                for ( int i = 0; i < mPolaGry.size(); i++ )
                {
                    if(mPolaGry.at(i)->isThisField(mEvent.mouseButton.x,mEvent.mouseButton.y))
                    {
                        cout << "Kliknieto w pole gry o id: " << mPolaGry.at(i)->mID << "  zrob cos z tym:)!\n";
                        mModel->mNacisnijPole(mPolaGry.at(i)->mID);

                    }


                }

            }

        RysujOknoGry();
        }

    }
  return(0);
}