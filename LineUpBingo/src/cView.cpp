#include "cView.h"

cView::cView(cControler *aControler)
{
    mControler = aControler;
    Init();
    //window.setKeyRepeatEnabled(false);
}

cView::~cView()
{
    delete windowHight;
    delete windowWidth;
}

int cView::Init()
{

    window.create(sf::VideoMode(*windowWidth,*windowHight),"Line Up Bingo");

    //Deklaracaja planszy
    if (!texture.loadFromFile("resources/board1kx1k.png")){
            return EXIT_FAILURE;
    }
    background.setTexture(texture);

    //Deklaracja wygranej dla zoltego
    if(!win_yellow.loadFromFile("resources/yellow_win.png"))
    {
        return EXIT_FAILURE;
    }
    S_wygrana_y.setTexture(win_yellow);
    S_wygrana_y.setPosition(100,100);

    //Deklaracja wygranej dla czerwonego
    if(!win_red.loadFromFile("resources/red_win.png"))
    {
        return EXIT_FAILURE;
    }
    S_wygrana_r.setTexture(win_red);
    S_wygrana_r.setPosition(100,100);

    //Deklaracja tokenów
    yellow_token.setRadius(55);
    red_token.setRadius(55);
    yellow_token.setFillColor(sf::Color::Yellow);
    red_token.setFillColor(sf::Color::Red);

    //Deklaracja Tekstu
    if (!font.loadFromFile("resources/arial.ttf"))
    {
       return EXIT_FAILURE;
    }
    txt_reset.setFont(font);
    txt_reset.setString("R-reset board");
    txt_reset.setCharacterSize(15);
    txt_reset.setFillColor(sf::Color::Red);
    txt_reset.setPosition(730,690);
        if(!s_buffer.loadFromFile("resources/win_sound.wav"))
    {
        return EXIT_FAILURE;
    }
    sound.setBuffer(s_buffer);

    if(!background_buffer.loadFromFile("resources/background1_sound.wav"))
    {
        return EXIT_FAILURE;
    }
    bck_sound.setBuffer(background_buffer);
    bck_sound.play();

    if(!background2_buffer.loadFromFile("resources/background2_sound.wav"))
    {
        return EXIT_FAILURE;
    }
    bck2_sound.setBuffer(background2_buffer);

}



void cView::ClearBoard()
{
    circs.clear();
    window.clear();
    window.draw(background);
    window.display();
    for (int i=0;i<7;i++)
        k[i]=0;
    turn=0;
    reset=1;
    system("cls");
}
void cView::setTokenPos(int p,int *x,int *y)
{
    yellow_token.setPosition(5+(118.2857*p),595-k[p]);
    red_token.setPosition(5+(118.2857*p),595-k[p]);
    if (6-k[p]/118.33>0&&k[p]<=595)
    {
        if (!turn)
            {
            circs.push_back(yellow_token);
            turn=1;
            k[p]+=118.33;
            }
        else if (turn)
            {
            circs.push_back(red_token);
            turn=0;
            k[p]+=118.33;
            }
    }
}

void cView::wyswietl()
{
            window.clear();
            window.draw(background);

            for (const auto& r : circs)
                window.draw(r);

             window.display();
}
void cView::WinRed()
{
    window.clear();
    window.draw(background);

    for (const auto& r : circs)
            window.draw(r);

    window.draw(S_wygrana_r);
    window.draw(txt_reset);

    if (enabled) sound.play();

    enabled=false;
    window.display();
}

void cView::WinYellow()
{
    window.clear();
    window.draw(background);

    for (const auto& r : circs)
            window.draw(r);

    window.draw(S_wygrana_y);
    window.draw(txt_reset);
    if (enabled) sound.play();

    enabled=false;
    window.display();

}

float cView::GetPosX()
{
    return sf::Mouse::getPosition(window).x;

}
int cView::Turn()
{
    return turn;
}

int cView::isOpen()
{
    return window.isOpen();
}
int cView::checkEvents()
{

    if (window.isOpen() && window.pollEvent(event))
    {

    if (event.type == sf::Event::Closed) window.close();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
    {
        ClearBoard(); //reset planszy View
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) //zmiana muzyki
    {
        bck_sound.stop();
        bck2_sound.play();
    }
    }
    if (enabled)
        wyswietl();
}
bool cView::checkMove()
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && enabled&&onClick)
    {
        onClick=0;
        if(sf::Mouse::getPosition(window).x>0 &&sf::Mouse::getPosition(window).x<120 )
        {
            p=0;
            setTokenPos(p,&x,&y);
        }
        else if (sf::Mouse::getPosition(window).x>120 &&sf::Mouse::getPosition(window).x<240)
        {
            p=1;
            setTokenPos(p,&x,&y);

        }
        else if (sf::Mouse::getPosition(window).x>240 &&sf::Mouse::getPosition(window).x<360)
        {
            p=2;
            setTokenPos(p,&x,&y);
        }
        else if (sf::Mouse::getPosition(window).x>360 &&sf::Mouse::getPosition(window).x<475)
        {
            p=3;
            setTokenPos(p,&x,&y);
        }
        else if (sf::Mouse::getPosition(window).x>475 &&sf::Mouse::getPosition(window).x<592)
        {
            p=4;
            setTokenPos(p,&x,&y);
        }
        else if (sf::Mouse::getPosition(window).x>592 &&sf::Mouse::getPosition(window).x<710)
        {
            p=5;
            setTokenPos(p,&x,&y);
        }
        else if (sf::Mouse::getPosition(window).x>710 &&sf::Mouse::getPosition(window).x<828)
        {
            p=6;
            setTokenPos(p,&x,&y);
        }
        moves+=1;
    }
    if (event.type == sf::Event::MouseButtonReleased)    onClick=1;
    else
        return false;

}
bool cView::checkButton()
{
    if (sf::Event::MouseButtonPressed)
        return true;
    return false;
}
