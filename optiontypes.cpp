#include "optiontypes.h"

MoveOption::~MoveOption()
{
    
}

void MoveOption::execute()
{
    m_player.moveRoom(m_dest);
}

void InspectRoom::execute()
{
    using namespace e_std;
    int room_id = m_source.getID();

    println("=================");
    println(m_source.getTitle());
    println("=================");

    switch(room_id)
    {
        case CELL_ROOM_1:
        {
            println("This cell's walls are made up of a black steel, with a barred window opposite to the locked steel door. Inigo knows that this cell must be technologically advanced despite it's crude and s imple appearance.");
        }
        break;
        case CELL_HALL_1:
        {

        }
        break;
    }

    int choice = acceptInt("Continue?(0)");
}

void InspectPerson::execute()
{
    using namespace e_std;
    int person_id = m_source.getID();

    println("=================");
    println(m_source.getName());
    println("=================");

    switch(person_id)
    {
        case INIGO_ID:
        {
            println("Inigo is a young man around 18 years old with long dark hair that goes down to his shoulders, dark eyes, and olive skin.");
        }
        break;
        case AGNES_ID:
        {

        }
        break;
        case WALLACE_ID:
        {

        }
        break;
        case DARCY_ID:
        {

        }
        break;
        case IVA_ID:
        {

        }
        break;
    }

    int choice = acceptInt("Continue?(0)");
}