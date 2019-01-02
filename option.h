#ifndef OPTION_H
#define OPTION_H

class Option
{
    public:
	virtual ~Option(){}
        virtual void execute() = 0;

        virtual const std::string getName() const
        {
            return m_name;
        }
    protected:
        std::string m_name;
};

#endif
