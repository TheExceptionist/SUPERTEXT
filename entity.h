#ifndef ENTITY_H
#define ENTITY_H

#include "defs.h"

#define INVALID_ATTR -66

enum def_attr
{
    PHYS,
    ELTR,
    HOT,
    COLD,
    PLAS
};

enum entity_ids
{
	INIGO_ID,
	AGNES_ID,
	WALLACE_ID,
	DARCY_ID,
	IVA_ID,
	GUARD_ID,

};


class Entity
{
    public:
        Entity(std::string name, std::string codename, const int id, const int health = 20, const int dodge = 0, const int level = 1, const int req = 10, 
            const int phys = 0, const int eltr = 0, const int hot = 0, const int cold = 0, const int plas = 0, const bool is_organic = true)
        : m_name(name), m_id(id), m_dodge(dodge), m_codename(codename), m_level(level), m_skill_req(req), m_is_organic(is_organic)
        {
            m_health = m_max_health = health;
            m_phys_def = m_max_phys_def = phys;
            m_eltr_def = m_max_eltr_def = eltr;
            m_hot_def = m_max_hot_def = hot;
            m_cold_def = m_max_cold_def = cold;
            m_plas_def = m_max_plas_def = plas;
        }

        virtual ~Entity();

        const std::string& getName() const { return m_name; }
        const std::string& getCodeName() const { return m_codename; }
        int getMaxHealth() const { return m_max_health; }
        int getHealth() const { return m_health; }
        int getLevel() const { return m_level; }
        int getSkillReq() const { return m_skill_req; }
        int getDefAttr(const int type) const;
        int getMaxDefAttr(const int type) const; 
        int getDodge() const  { return m_dodge; }
        bool isOrganic() const { return m_is_organic; }
        int getID() const { return m_id; }

        void setName(std::string& name) { m_name = name; }
        void setCodeName(std::string& codename) { m_codename = codename; }
        void setMaxHealth(const int health) { m_max_health = health; }
        void setHealth(const int health) { m_health = health; }
        void setLevel(int level) { m_level = level; }
        void setSkillReq(int req) { m_skill_req = req; }
        void setDefAttr(const int type, const int value); 
        void setMaxDefAttr(const int type, const int value);
        void setDefence(const int type, const int value);  
        void setDodge(int dodge) { m_dodge = dodge; }
        void setOrganic(const bool is_organic) { m_is_organic = is_organic; }
    protected:
        std::string m_name;
        std::string m_codename;
        const int m_id;

        int m_health, m_max_health;
        int m_level;
        int m_skill_req;
        int m_dodge;

        int m_phys_def, m_max_phys_def;
        int m_eltr_def, m_max_eltr_def;
        int m_hot_def, m_max_hot_def;
        int m_cold_def, m_max_cold_def;
        int m_plas_def, m_max_plas_def;

        bool m_is_organic;
};

#endif