#ifndef OPTION_TYPES_H
#define OPTION_TYPES_H

#include "defs.h"
#include "player.h"
#include "entity.h"

class MoveOption : public Option
{
    public:
        MoveOption(player_t& player, Room& dest)
        :  m_player(player), m_dest(dest)
        {
            m_name =  "Move to "+dest.getTitle();
        }

        virtual ~MoveOption();

        virtual void execute();
    protected:
        player_t& m_player;
        Room& m_dest;
};

class InspectRoom : public Option
{
    public:
        InspectRoom(const Room& source)
        :  m_source(source)
        {
            m_name = "Inspect "+source.getTitle();
        }

        virtual void execute();
    protected:
        const Room& m_source;
};

class InspectPerson : public Option
{
    public:
        InspectPerson(const Entity& source)
        :  m_source(source)
        {
            m_name = "Inspect "+source.getName();
        }

        virtual void execute();
    protected:
        const Entity& m_source;
};

class TalkOption : public Option
{
    public:
        TalkOption()
        {
            m_name = "  Talks to ";
        }

        virtual void execute();
    protected:

};

class ExitOption : public Option
{
    public:
        ExitOption()
        {
            m_name = "Exit";
        }

        virtual void execute() {exit(0);}

        static ExitOption& get() 
        {
            static ExitOption* exit = new ExitOption();
            return *exit;
        }
};


#endif