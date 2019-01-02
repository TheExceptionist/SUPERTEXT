#include "skill.h"

Skill::~Skill()
{

}

int Skill::getDefAttr(const int type) const
{
    switch(type)
    {
        case PHYS:
        {
            return m_phys_dam;
        }
        case ELTR:
        {
            return m_eltr_dam;
        }
        case HOT:
        {
            return m_hot_dam;
        }
        case COLD:
        {
            return m_cold_dam;
        }
        case PLAS:
        {
            return m_plas_dam;
        }
        default:
            return INVALID_ATTR;
    }
}

void Skill::setDefAttr(const int type, const int value)   
{
    switch(type)
    {
        case PHYS:
        {
            m_phys_dam = value;
        }
        break;
        case ELTR:
        {
            m_eltr_dam = value;
        }
        break;
        case HOT:
        {
            m_hot_dam = value;
        }
        break;
        case COLD:
        {
            m_cold_dam = value;
        }
        break;
        case PLAS:
        {
            m_plas_dam = value;
        }
        break;
    }
}

void Skill::use(Entity* entity)
{
    m_uses++;
}