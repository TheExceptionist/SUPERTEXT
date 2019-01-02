#ifndef ROOM_H
#define ROOM_H

#include "defs.h"
#include "option.h"
#include "entity.h"

#define MAX_OPTIONS 10
#define MAX_ENEMIES 6
#define MOVE_OPTIONS 5

#define TEST_ROOM -1
#define CELL_ROOM_1 0
#define CELL_HALL_1 1

struct player_t;

class Room
{
    public:
        Room(const int room_id, player_t* player, player_t* enemy = NULL)
        :  m_room_id(room_id), m_player(player), m_enemy(enemy)
        {
            init(m_room_id);
        }

        //For Testing Only
        Room(const std::string& title, const std::string& description, 
        const std::string& option_0 = " ",
        const std::string& option_1 = " ",
        const std::string& option_2 = " ",
        const std::string& option_3 = " ",
        const std::string& option_4 = " ",
        const std::string& option_5 = " ",
        const std::string& option_6 = " ",
        const std::string& option_7 = " ",
        const std::string& option_8 = " ") 
        :  m_title(title),  m_description(description), m_room_id(TEST_ROOM)
        {
            m_options[0] = option_0;
            m_options[1] = option_1;
            m_options[2] = option_2;
            m_options[3] = option_3;
            m_options[4] = option_4;
            m_options[5] = option_5;
            m_options[6] = option_6;
            m_options[7] = option_7;
        }

        ~Room();

        void init(const int room_id);
        void update();
        void executeOption(const int choice);

        std::string getTitle() const 
        {
            return m_title;
        }

        std::string getDescription() const
        {
            return m_description;
        }

        int getID() const { return m_room_id; }
        int getTechLevel() const { return m_techno_level; }

        void addOption(const int slot, Option* to);
    private:
        const int m_room_id;
        std::string m_title;
        std::string m_description;
        std::string m_visited_description;

        std::string m_options[MAX_OPTIONS];
        
        Option* m_exe_options[MAX_OPTIONS];
        player_t* m_player;
        player_t* m_enemy;

        //How advanced "rooms" technology is;
        int m_techno_level = 0;
        bool m_visited = false;
        bool m_in_battle = false;

        void setOption(int slot, Option& setTo);
        void executeBattle(player_t* enemy, player_t* player);
};

#endif