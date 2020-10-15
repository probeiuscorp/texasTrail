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
            TIME_OF_YEAR,
        };
    public:
        UI(TexasTrail& game);
        virtual ~UI();

        virtual Menu getUI();
        virtual int init();
        virtual void setUIMain();
        virtual void setUILoad();
        virtual void setUINewGame();
        virtual void setUIParty();
        virtual void setUIConfirmNewGame();
        virtual void printTitle() const;
        virtual void clean() const;

    private:
        int _exit_status;
        Menu _menu;
        TexasTrail& _game;

        void exit(int exit_status);
};

#endif