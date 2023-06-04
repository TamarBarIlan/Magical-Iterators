#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

MagicalContainer::MagicalContainer(MagicalContainer &other) : elements(other.elements), primeElements(other.primeElements) {}

MagicalContainer &MagicalContainer::operator=(MagicalContainer &other)
{
    if (&other != this)
    {
        elements = other.elements;
        primeElements = other.primeElements;
    }
    return *this;
}

std::vector<int> &MagicalContainer::getElements()
{
    return this->elements;
}
std::vector<int> &MagicalContainer::getPrimeElements() 
{
    return this->primeElements;
}

void MagicalContainer::addElement(int element)
{
    if (isPrime(element))
    {
        auto spacePrime = std::upper_bound(this->primeElements.begin(), this->primeElements.end(), element);
        this->primeElements.insert(spacePrime, element);
    }
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
bool MagicalContainer::isPrime(int number)
{
    if (number <= 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (int i = 3; (i * i) <= number; i += 2)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}