#ifndef TEXAS_TRAIL_UI_H
#define TEXAS_TRAIL_UI_H
class TexasTrail;

class UI {
    public:
        enum class Menu {
            MAIN,
            LOAD,
            NEW_GAME,
            PARTY,
        };
    public:
        UI(TexasTrail& game);
        virtual ~UI();

        virtual Menu getUI();
        virtual void init();
        virtual void setUIMain();
        virtual void setUILoad();
        virtual void setUINewGame();
        virtual void setUIParty();
        virtual void setUIConfirmNewGame();
        virtual void printTitle() const;

    private:
        Menu _menu;
        TexasTrail& _game;
};

#endif