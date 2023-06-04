#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

MagicalContainer::MagicalContainer(MagicalContainer &other) : elements(other.elements) {}

MagicalContainer &MagicalContainer::operator=(MagicalContainer &other)
{
    if (&other != this)
    {
        elements = other.elements;
    }
    return *this;
}

std::vector<int> &MagicalContainer::getElements()
{
    return this->elements;
}

void MagicalContainer::addElement(int element)
{
    auto space = std::upper_bound(this->elements.begin(), this->elements.end(), element);
    this->elements.insert(space, element);
}
void MagicalContainer::removeElement(int element)
{
    auto it = std::find(elements.begin(), elements.end(), element);
    if (it != elements.end())
    {
        elements.erase(it);
    }
    else
    {
        throw runtime_error("Removing a non-existing element");
    }
}
int MagicalContainer::size()
{
    return this->elements.size();
}

bool MagicalContainer::operator==(MagicalContainer &other)
{
    return this->elements == other.elements;
}
int MagicalContainer::at(int index)
{
    if (index < 0)
    {
        __throw_out_of_range("Index cannot be negative.");
    }
    return elements.at(static_cast<std::vector<int>::size_type>(index));
}