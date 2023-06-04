#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("MagicalContainer AscendingIterator - Ascending order")
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::AscendingIterator ascIter(container);

    std::vector<int> asc = {2, 3, 9, 17, 25};
    std::vector<int>::size_type index = 0;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
    {
        CHECK(*it == asc[index]);
        ++index;
    }
}

TEST_CASE("MagicalContainer AscendingIterator - Remove element")
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    container.removeElement(9);

    MagicalContainer::AscendingIterator ascIter(container);

    std::vector<int> asc = {2, 3, 17, 25};
    std::vector<int>::size_type index = 0;
    for (auto it = ascIter.begin(); it != ascIter.end(); ++it)
    {
        CHECK(*it == asc[index]);
        ++index;
    }
}

TEST_CASE("MagicalContainer AscendingIterator - Empty container")
{
    MagicalContainer emptyContainer;

    MagicalContainer::AscendingIterator ascIter(emptyContainer);
    CHECK(ascIter.begin() == ascIter.end());
}

TEST_CASE("MagicalContainer SideCrossIterator - Cross order")
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::SideCrossIterator crossIter(container);

    std::vector<int> cross = {17, 3, 2, 9, 25};
    std::vector<int>::size_type index = 0;
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it)
    {
        CHECK(*it == cross[index]);
        ++index;
    }
}

TEST_CASE("MagicalContainer SideCrossIterator - Remove element")
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    container.removeElement(9);

    MagicalContainer::SideCrossIterator crossIter(container);

    std::vector<int> cross = {17, 3, 2, 25};
    std::vector<int>::size_type index = 0;
    for (auto it = crossIter.begin(); it != crossIter.end(); ++it)
    {
        CHECK(*it == cross[index]);
        ++index;
    }
}

TEST_CASE("MagicalContainer SideCrossIterator - Empty container")
{
    MagicalContainer emptyContainer;

    MagicalContainer::SideCrossIterator crossIter(emptyContainer);
    CHECK(crossIter.begin() == crossIter.end());
}

TEST_CASE("MagicalContainer PrimeIterator - Prime numbers")
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    MagicalContainer::PrimeIterator primeIter(container);

    std::vector<int> primes = {2, 3, 17};
    std::vector<int>::size_type index = 0;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
    {
        CHECK(*it == primes[index]);
        ++index;
    }
}

TEST_CASE("MagicalContainer PrimeIterator - Remove prime number")
{
    MagicalContainer container;
    container.addElement(17);
    container.addElement(2);
    container.addElement(25);
    container.addElement(9);
    container.addElement(3);
    container.removeElement(17);

    MagicalContainer::PrimeIterator primeIter(container);

    std::vector<int> primes = {2, 3};
    std::vector<int>::size_type index = 0;
    for (auto it = primeIter.begin(); it != primeIter.end(); ++it)
    {
        CHECK(*it == primes[index]);
        ++index;
    }
}

TEST_CASE("MagicalContainer PrimeIterator - Empty container")
{
    MagicalContainer emptyContainer;
    MagicalContainer::PrimeIterator primeIter(emptyContainer);
    CHECK(primeIter.begin() == primeIter.end());
}