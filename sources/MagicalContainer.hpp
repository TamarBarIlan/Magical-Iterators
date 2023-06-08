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
        std::vector<int*> primeElements;

    public:
        MagicalContainer() = default;
        MagicalContainer(const MagicalContainer &other);
        ~MagicalContainer();

        void addElement(int element);
        void removeElement(int element);
        int size() const;
        void setElements(std::vector<int>& elements);
        std::vector<int>& getElements();
        std::vector<int*>& getPrimeElements();
        bool isPrime(int);

        class AscendingIterator
        {
        private:
            MagicalContainer &mContainer;
            int index;

        public:
            AscendingIterator() : mContainer(*(new MagicalContainer)), index(0) {}
            AscendingIterator(MagicalContainer &mContainer) : mContainer(mContainer), index(0) {}
            AscendingIterator(AscendingIterator &iter) : mContainer(iter.mContainer), index(iter.index) {}
            ~AscendingIterator() = default;

            // assignment operator
            AscendingIterator &operator=(AscendingIterator &iter)
            {
                if (this != &iter)
                {
                    mContainer = iter.mContainer;
                    index = iter.index;
                }
                return *this;
            }

            // comparison operators
            bool operator==(AscendingIterator &iter)
            {
                return this->mContainer == iter.mContainer && this->index == iter.index;
            }
            bool operator!=(AscendingIterator &iter)
            {
                return !(this->index == iter.index);
            }
            bool operator<(const AscendingIterator &iter) const
            {
                return false;
            }
            bool operator>(const AscendingIterator &iter) const
            {
                return false;
            }

            // dereference operator
            int &operator*()
            {
                return mContainer.getElements()[static_cast<std::vector<int>::size_type>(index)];
            }

            // pre-increment operator
            AscendingIterator &operator++()
            {
                index++;
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
                return this->mContainer == iter.mContainer && this->index == iter.index;
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
                return this->mContainer == iter.mContainer && this->index == iter.index;
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