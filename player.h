#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <memory>

#include "room.h"
#include "entity.h"

//Used to store collections of  entities
struct player_t
{
    void moveRoom(Room& room)
    {
        m_curr_room = &room;
    }
    
    void addMember(Entity* new_member)
    {
        party.push_back(new_member);
    }

    Entity* getCharacter(std::string name)
    {
        for(auto iter = party.begin(); iter != party.end(); iter++)
        {
            if((*iter)->getName() == name)
            {
                return *iter;
            }
        }

        return NULL;
    }

    Entity* getMainCharacter()
    {
        return party.front();
    }

	Room* m_curr_room;
    std::vector<Entity*> party;
};

#endif