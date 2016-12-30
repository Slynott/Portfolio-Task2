//System.h
#ifndef SYSTEM_H
#define SYSTEM_H


class System
{
    public:
        System();
        virtual ~System();

        void idle();
        void Sensing();
        void Processing();

    protected:

    private:
        State idle()
        State Sensing()
        State Processing()
};

#endif // SYSTEM_H
