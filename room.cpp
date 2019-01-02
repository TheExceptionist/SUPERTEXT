#include <memory>

#include "room.h"
#include "optiontypes.h"
#include "player.h"

Room::~Room()
{

}

//Overflow - need to correct later
void Room::init(const int room_id)
{
    std::string main_character_name = m_player->getMainCharacter()->getName();

    if(m_enemy != NULL) m_in_battle = true;

    switch(room_id)
    {
        case CELL_ROOM_1:
        {
            m_title = "Inigo's Cell";
            m_description = main_character_name + " wakes up in a dank, empty cellroom. He feels nauseous, completely unaware of why he's there or what just happen to him.";
            m_visited_description = "A small cell used to hold prisoners";
        }
        break;
        case CELL_HALL_1:
        {
            m_title = "Cell Hallway";
            m_description = main_character_name + " enters a long hallway full of doors to other cells and on the opposite side, a large door that leads someone else..";
            m_visited_description = "A long hallway that connects many cells to an exit.";
        }
        break;
    }

    setOption(9, ExitOption::get());
}

void Room::addOption(const int slot, Option* to)
{
    setOption(slot, *to);
}

void Room::setOption(int slot, Option& setTo)
{
    m_exe_options[slot] = &setTo;
    m_options[slot] = setTo.getName();
}

void Room::update()
{
    using namespace e_std;

    if(m_in_battle)
    {
        
        
        m_in_battle = false;
    }
    else
    {
        int choice = 0;

        println(m_title);
        println("=================");
        
        if(!m_visited)
        {
            println(m_description);
            m_visited = true;
        }
        else
        {
            println(m_visited_description);
        }

        println("=================");
        for(int i = 0; i < MAX_OPTIONS; i++)
        {
            printf("%d: %s\n", i, m_options[i].c_str());
        }

        choice = acceptInt("?");

        if(choice > -1 && choice < 10)
        {
            executeOption(choice);
        }
    }
}

void Room::executeOption(const int choice)
{
    e_std::clear();
    
    if(m_exe_options[choice] != NULL) m_exe_options[choice]->execute();
}