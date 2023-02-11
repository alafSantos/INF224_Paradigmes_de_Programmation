#include "Group.h"

Group::Group(std::string name) : name(name) {}

std::string Group::getName() const
{
    return this->name;
}

void Group::showGroup(std::ostream &dst) const
{
    dst << "Group Name: " << this->getName() << std::endl;
    for (auto it = this->begin(); it != this->end(); ++it)
    {
        (*it)->showVariables(dst);
    }
}