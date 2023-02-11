#ifndef CWIDOKMENU_H
#define CWIDOKMENU_H
#include "../SFML-2.5.1/include/SFML/Graphics.hpp"
#include "cModelGra.h"

struct Field
{
    int sizeX;
    int sizeY;
    int posX;
    int posY;
    std::string info;
    int mID;    // identyfikator pola
    unsigned int sizeString;

    Field (int sizeX, int sizeY, int posX, int posY, std::string info, int sizeString, int aID) :
        sizeX(sizeX), sizeY(sizeY), posX(posX), posY(posY), info(info), sizeString(sizeString), mID(aID) {}

    bool isThisField(int X, int Y)
    {
        int x0 = posX;
        int x = posX + sizeX;
        int y0 = posY;
        int y = posY + sizeY;
        if (X > x0 and X < x and Y > y0 and Y < y)
        {
            return  true;
        }
        return false;
    }
};


/*
 * To jest fabryka rysuj¹ca.
 * Przesy³asz jej strukturê z danymi i ona rysuje pole okreœlone w strukturze field.
 * */
class DrawFields
{
    Field & field;
    sf::RenderWindow & window;
    sf::Font font;
    sf::Text text;

public:
    DrawFields(Field & field, sf::RenderWindow & window) :
        field(field), window(window)
    {
        font.loadFromFile("res/Inkfree.ttf");
        text.setFont(font);
    }

    void drawfield()
    {
        ///Menu

        sf::CircleShape circle;
        circle.setPosition(field.posX, field.posY);
        circle.setFillColor(sf::Color(249,196,196));
        circle.setRadius(15);

        ///Circle

        text.setFillColor(sf::Color::White);
        text.setPosition(field.posX+2, field.posY+2);
        text.setString(field.info);
        text.setCharacterSize(field.sizeString);

        window.draw(circle);
        window.draw(text);
    }
};


// Ta klasa obsluguje okno z menu oraz okno z gra, poniewaz gra i menu sa wykonywane w tym samym oknie!!

class cWidokMenu
{
    public:
        cWidokMenu();
        virtual ~cWidokMenu();
        int RysujOknoMenu();
        int SprawdzZdarzeniaMenu();
        int isOpen();
        int RysujOknoGry();
        int SprawdzZdarzeniaOknaGry();
        void setModel(cModelGra *aModel);
        int SprawdzZdarzenia();
    protected:

    private:
         std::vector < Field* > mPolaGry;
         std::vector < Field* > mWynikiGry;
         sf::RenderWindow mOkno;
         sf::Texture mPlanszaGrafika;
         sf::Sprite mPlanszaGrafikaa;
         sf::Event mEvent;
         Field instrukcja_klocek = Field(100,30, 150, 150, "Instrukcja", 20, 2);
         Field zagraj_klocek = Field(100, 30, 150, 50, "Zagraj!", 20, 1);
         cModelGra* mModel;
         int mAktywneOkno; // zmienna pomocnicza pamietajaca ktora plansza jest aktualnie narysowana w oknie, poniewaz mamy jedno okno w ktorym wyswietlamy rozne rzeczy. Musimy wiedziec jakie zdarzenia wykrywac
};

#endif // CWIDOKMENU_H
