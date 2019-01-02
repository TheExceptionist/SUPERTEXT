#ifndef SKILL_H
#define SKILL_H

#include "defs.h"
#include "entity.h"

class Skill
{
    public:
        Skill(const std::string name, const int phys, const int eltr, const int cold, const int hot, const int plas, const int heal, const int accuracy = 90, 
        const bool is_attack = true, const int max_level = 10, 
        const int level_incr = 0, const bool is_techno = false)
        : m_name(name), m_is_attack(is_attack), m_is_techno(is_techno), m_accuracy(accuracy), m_heal(heal), m_level_incr(level_incr),
            m_phys_dam(phys), m_eltr_dam(eltr), m_cold_dam(cold), m_hot_dam(hot), m_plas_dam(plas)
        {
            m_curr_level = m_active_level = 1;
            m_max_level = max_level;

            if(m_max_level < m_curr_level)
            {
                m_curr_level = m_max_level;
            }
        }

        virtual ~Skill();
        virtual void use(Entity* entity);

        const std::string getName() const { return m_name; }
        int getCurrentLevel() const { return m_curr_level; }
        int getActiveLevel() const { return m_active_level; }
        int getMaxLevel() const { return m_max_level; }
        int getHeal() const { return m_heal; }
        int getLevelIncr() const { return m_level_incr; }
        bool isTechno() const { return m_is_techno; }
        bool isAttack() const { return m_is_attack; }
        int getDefAttr(const int type) const;
        int getAccuracy() const { return m_accuracy; }
        int getUses() const { return m_uses; } 

        void setCurrentLevel(const int level) { m_curr_level = level; }
        void setActiveLevel(const int level) { m_active_level = level; }
        void setMaxLevel(const int level) { m_max_level = level; }
        void setHeal(const int heal) { m_heal = heal; }
        void setLevelIncr(const int incr) { m_level_incr = incr; }
        void setTechno(const bool techno) { m_is_techno = techno; }
        void setAttack(const bool attack) { m_is_attack = attack; }   
        void setDefAttr(const int type, const int value);
        void setAccuracy(const int accuracy) { m_accuracy = accuracy; } 
        void setUses(const int uses) { m_uses = uses; }    
    protected:
        const std::string m_name;
        std::string m_custom_msg;

        int m_curr_level, m_active_level, m_max_level;
        int m_phys_dam, m_eltr_dam, m_cold_dam, m_hot_dam, m_plas_dam;

        //How much  to increase  the level  if  used
        int m_heal, m_level_incr;
        int m_accuracy;
        int m_uses;
        
        bool m_is_techno, m_is_attack;
};

#endif