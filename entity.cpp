#include "entity.h"

Entity::~Entity()
{

}

int Entity::getDefAttr(const int type) const
{
    switch(type)
    {
        case PHYS:
        {
            return m_phys_def;
        }
        case ELTR:
        {
            return m_eltr_def;
        }
        case HOT:
        {
            return m_hot_def;
        }
        case COLD:
        {
            return m_cold_def;
        }
        case PLAS:
        {
            return m_plas_def;
        }
        default:
            return INVALID_ATTR;
    }
}

int Entity::getMaxDefAttr(const int type) const  
{
    switch(type)
    {
        case PHYS:
        {
            return m_max_phys_def;
        }
        case ELTR:
        {
            return m_max_eltr_def;
        }
        case HOT:
        {
            return m_max_hot_def;
        }
        case COLD:
        {
            return m_max_cold_def;
        }
        case PLAS:
        {
            return m_max_plas_def;
        }
        default:
            return INVALID_ATTR;
    }
}

void Entity::setDefence(const int type, const int value)   
{
    setMaxDefAttr(type, value);
    setDefAttr(type, value);
}

void Entity::setDefAttr(const int type, const int value)   
{
    switch(type)
    {
        case PHYS:
        {
            if(m_max_phys_def < value) return;
            m_phys_def = value;
        }
        break;
        case ELTR:
        {
            if(m_max_eltr_def < value) return;
            m_eltr_def = value;
        }
        break;
        case HOT:
        {
            if(m_max_hot_def < value) return;
            m_hot_def = value;
        }
        break;
        case COLD:
        {
            if(m_max_cold_def < value) return;
            m_cold_def = value;
        }
        break;
        case PLAS:
        {
            if(m_max_plas_def < value) return;
            m_plas_def = value;
        }
        break;
    }
}

void Entity::setMaxDefAttr(const int type, const int value)   
{
    switch(type)
    {
        case PHYS:
        {
            m_max_phys_def = value;
        }
        break;
        case ELTR:
        {
            m_max_eltr_def = value;
        }
        break;
        case HOT:
        {
            m_max_hot_def = value;
        }
        break;
        case COLD:
        {
            m_max_cold_def = value;
        }
        break;
        case PLAS:
        {
            m_max_plas_def = value;
        }
        break;
    }
}