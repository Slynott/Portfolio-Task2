//Button.h
#ifndef BUTTON_H
#define BUTTON_H



class Button
{
    public:
        Button();
        virtual ~Button();

        void pressButton();
        void resetButton();

    protected:

    private:
        Button pressed();

};

#endif // BUTTON_H
