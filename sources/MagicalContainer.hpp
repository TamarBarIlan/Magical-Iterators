#include <vector>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <cmath>

namespace ariel
{

    class MagicalContainer
    {

    private:
        std::vector<int> elements;
        std::vector<int *> primeElements;

    public:
        MagicalContainer() = default;
        MagicalContainer(const MagicalContainer &other);
        ~MagicalContainer();

        void addElement(int element);
        void removeElement(int element);
        int size() const;
        void setElements(std::vector<int> &elements);
        std::vector<int> &getElements();
        std::vector<int *> &getPrimeElements();
        bool isPrime(int);

        // ***************************************//
        // AscendingIterator                      //
        // ***************************************//
        class AscendingIterator
        {
        private:
            MagicalContainer &mContainer;
            int index;

        public:
            AscendingIterator() = delete;
            AscendingIterator(MagicalContainer &mContainer) : mContainer(mContainer), index(0) {}
            AscendingIterator(const AscendingIterator &iter) : mContainer(iter.mContainer), index(iter.index) {}
            ~AscendingIterator() = default;

            // assignment operator
            AscendingIterator &operator=(AscendingIterator &&iter) noexcept
            {
                if (this != &iter)
                {
                    this->mContainer = std::move(iter.mContainer);
                    this->index = iter.index;
                }
                return *this;
            }

            // comparison operators
            bool operator==(AscendingIterator &iter)
            {
                if (typeid(*this) != typeid(iter))
                {
                    throw std::runtime_error("Compare different types of iterators ");
                }

                return this->index == iter.index;
            }

            //	Inequality comparison
            bool operator!=(AscendingIterator &iter)
            {
                return !(this->index == iter.index);
            }

            // GT comparison
            bool operator<(const AscendingIterator &iter) const
            {
                return index < iter.index;
            }

            // LT comparison
            bool operator>(const AscendingIterator &iter) const
            {
                return index > iter.index;
            }

            // dereference operator
            int &operator*()
            {
                if (index >= mContainer.getElements().size())
                {
                    throw std::runtime_error("Out of bounds");
                }
                return mContainer.getElements()[static_cast<std::vector<int>::size_type>(index)];
            }

            // pre-increment operator
            AscendingIterator &operator++()
            {
                if (index >= mContainer.getElements().size())
                {
                    throw std::runtime_error("You are in the last element");
                }
                ++index;
                return *this;
            }

            AscendingIterator &begin()
            {
                index = 0;
                return *this;
            }

            AscendingIterator &end()
            {
                index = mContainer.getElements().size();
                return *this;
            }

        }; // AscendingIterator

        class SideCrossIterator
        {
        private:
            MagicalContainer &mContainer;
            int index;

        public:
            SideCrossIterator() : mContainer(*(new MagicalContainer)), index(0) {}
            SideCrossIterator(MagicalContainer &mContainer) : mContainer(mContainer), index(0) {}
            SideCrossIterator(SideCrossIterator &iter) : mContainer(iter.mContainer), index(iter.index) {}
            ~SideCrossIterator() = default;

            // assignment operator
            SideCrossIterator &operator=(SideCrossIterator &iter)
            {
                if (this != &iter)
                {
                    mContainer = iter.mContainer;
                    index = iter.index;
                }
                return *this;
            }

            // comparison operators
            bool operator==(SideCrossIterator &iter)
            {
                // return this->mContainer == iter.mContainer && this->index == iter.index;
                return true;
            }
            bool operator!=(SideCrossIterator &iter)
            {
                return !(this->index == iter.index);
            }
            bool operator<(SideCrossIterator &iter)
            {
                return false;
            }
            bool operator>(SideCrossIterator &iter)
            {
                return false;
            }

            // dereference operator
            int &operator*()
            {
                return mContainer.getElements()[static_cast<std::vector<int>::size_type>(index)];
            }

            // pre-increment operator
            SideCrossIterator &operator++()
            {
                index++;
                return *this;
            }
            SideCrossIterator &begin()
            {
                index = 0;
                return *this;
            }
            SideCrossIterator &end()
            {
                index = mContainer.getElements().size();
                return *this;
            }

        }; // SideCrossIterator

        class PrimeIterator
        {
        private:
            MagicalContainer &mContainer;
            int index;

        public:
            PrimeIterator() : mContainer(*(new MagicalContainer)), index(0) {}
            PrimeIterator(MagicalContainer &mContainer) : mContainer(mContainer), index(0) {}
            PrimeIterator(PrimeIterator &iter) : mContainer(iter.mContainer), index(iter.index) {}
            ~PrimeIterator() = default;

            // assignment operator
            PrimeIterator &operator=(PrimeIterator &iter)
            {
                if (this != &iter)
                {
                    mContainer = iter.mContainer;
                    index = iter.index;
                }
                return *this;
            }

            // comparison operators
            bool operator==(PrimeIterator &iter)
            {
                return true;

                // return this->mContainer == iter.mContainer && this->index == iter.index;
            }
            bool operator!=(PrimeIterator &iter)
            {
                return !(this->index == iter.index);
            }
            bool operator<(PrimeIterator &iter)
            {
                return false;
            }
            bool operator>(PrimeIterator &iter)
            {
                return false;
            }

            // dereference operator
            int &operator*()
            {
                return mContainer.getElements()[static_cast<std::vector<int>::size_type>(index)];
            }

            // pre-increment operator
            PrimeIterator &operator++()
            {
                index++;
                return *this;
            }
            PrimeIterator &begin()
            {
                index = 0;
                return *this;
            }
            PrimeIterator &end()
            {
                index = mContainer.getElements().size();
                return *this;
            }

        }; // PrimeIterator

    }; // MagicalContainer

}