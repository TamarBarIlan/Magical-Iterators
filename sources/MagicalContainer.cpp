#include "MagicalContainer.hpp"
using namespace std;
using namespace ariel;

MagicalContainer::MagicalContainer(const MagicalContainer &other) : elements(other.elements), primeElements(other.primeElements) {}

MagicalContainer::~MagicalContainer()
{
    for (int *element : primeElements)
    {
        delete element;
    }
}

void MagicalContainer::addElement(int element)
{
    if (isPrime(element))
    {
        int* find_element = new int(element);
        auto spacePrime = std::lower_bound(primeElements.begin(), primeElements.end(), find_element, [](const int *x,const int *y) { return ((*x) < (*y)); });
        getPrimeElements().insert(spacePrime, find_element);
    }
    auto space = std::lower_bound(this->elements.begin(), this->elements.end(), element);
    this->elements.insert(space, element);
}

void MagicalContainer ::removeElement(int element)
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
    if(isPrime(element)){ 
        int* PrimeElement= new int(element);
        auto it = std::find(primeElements.begin(), primeElements.end(), PrimeElement);
        primeElements.erase(it);
        delete PrimeElement;
    }
}

int MagicalContainer:: size() const
{
    return this->elements.size();
}

std::vector<int>& MagicalContainer:: getElements()
{
    return this->elements;
}
std::vector<int*>& MagicalContainer:: getPrimeElements()
{
    return this->primeElements;
}

bool MagicalContainer::isPrime(int num)
{
    if (num <= 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if (num % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= std::sqrt(num); i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

