#ifndef CVIEW_H
#define CVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <iostream>


class cControler;

class cView
{
    public:
        int p=0;
        float k[7]={};
        int moves=0;
        int reset=0;

        cView(cControler*);
        virtual ~cView();
        void GameLoop();
        void ClearBoard();

        void setTokenPos(int,int*,int*);
        void wyswietl();

        void WinRed();
        void WinYellow();
        float GetPosX();

        int isOpen();
        int checkEvents();
        void Update();
        bool checkMove();

        int Turn();
        bool checkButton();


    protected:

    private:
        int onClick=1;
        int Init();
        cControler *mControler;
        int turn=0;
        int x = 0; //setPosition x
        int y = 0; // setPosition y
        bool enabled=true;
        std::vector<sf::CircleShape> circs;

        float* windowWidth = new float (828); //828
        float* windowHight = new float (710);

        sf::CircleShape yellow_token; //(55)
        sf::CircleShape red_token;

        sf::Event event;

        sf::RenderWindow window;
        sf::Texture texture;
        sf::Sprite background;

        sf::Texture win_yellow;
        sf::Sprite S_wygrana_y;

        sf::Texture win_red;
        sf::Sprite S_wygrana_r;


        //sf::Text txt_error1;
        sf::Text txt_reset;
        sf::Font font;
       //sf::Text txt_music;

        sf::SoundBuffer s_buffer;
        sf::Sound sound;

        sf::SoundBuffer background_buffer;
        sf::Sound bck_sound;

        sf::SoundBuffer background2_buffer;
        sf::Sound bck2_sound;

};

//class Menu

//class Game

#endif // CVIEW_H
