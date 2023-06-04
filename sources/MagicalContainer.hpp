#include <vector>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <cmath>

namespace ariel
{

    class MagicalContainer
    {

    private:
        std::vector<int> elements;
        std::vector<int> primeElements;

    public:
        MagicalContainer() = default;
        MagicalContainer(MagicalContainer &other);
        ~MagicalContainer() = default;

        MagicalContainer &operator=(MagicalContainer &other);
        std::vector<int> &getElements();
        std::vector<int> &getPrimeElements();
        void addElement(int element);
        void removeElement(int element);
        int size();
        bool operator==(MagicalContainer &other);
        int at(int index);
        bool isPrime(int number);

        class AscendingIterator
        {
        private:
            MagicalContainer &mContainer;
            int index;

        public:
            AscendingIterator(MagicalContainer &mContainer) : mContainer(mContainer), index(0) {}
            AscendingIterator(AscendingIterator &iter) : mContainer(iter.mContainer), index(iter.index) {}
            ~AscendingIterator() = default;

            // assignment operator
            AscendingIterator &operator=(AscendingIterator &iter)
            {
                if(this->mContainer != iter.mContainer)
                {
                    throw std::runtime_error("different containers");
                }
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
                return &index < &iter.index;
            }
            bool operator>(const AscendingIterator &iter) const
            {
                return &index > &iter.index;
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
            // SideCrossIterator() : mContainer(*(new MagicalContainer)), index(0) {}
            SideCrossIterator(MagicalContainer &mContainer) : mContainer(mContainer), index(0) {}
            SideCrossIterator(SideCrossIterator &iter) : mContainer(iter.mContainer), index(iter.index) {}
            ~SideCrossIterator() = default;

            // assignment operator
            SideCrossIterator &operator=(SideCrossIterator &iter)
            {
                if(this->mContainer != iter.mContainer)
                {
                    throw std::runtime_error("different containers");
                }
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
                return &index < &iter.index;
            }
            bool operator>(SideCrossIterator &iter)
            {
                return &index > &iter.index;
            }

            // dereference operator
            int &operator*()
            {
                return mContainer.getElements()[static_cast<std::vector<int>::size_type>(index)];
            }

            // pre-increment operator
            SideCrossIterator &operator++()
            {
                int end = this->end().index;
                if (index == end)
                {
                    throw std::runtime_error("index out of bounds");
                    // return this->end();
                }
                if (index < end)
                {
                    index = (int)mContainer.getElements().size() - index - 1;
                }
                else if (index > end)
                {
                    index = (int)mContainer.getElements().size() - index;
                }
                return *this;
            }
            SideCrossIterator &begin()
            {
                index = 0;
                return *this;
            }
            SideCrossIterator &end()
            {
                std::cout <<"in end() index == " << std::ceil(mContainer.getElements().size() / 2) << std::endl;
                index = std::ceil(mContainer.getElements().size() / 2);
                return *this;
            }

        }; // SideCrossIterator

        class PrimeIterator
        {
        private:
            MagicalContainer &mContainer;
            int index;

        public:
            // PrimeIterator() : mContainer(*(new MagicalContainer)), index(0) {}
            PrimeIterator(MagicalContainer &mContainer) : mContainer(mContainer), index(0) {}
            PrimeIterator(PrimeIterator &iter) : mContainer(iter.mContainer), index(iter.index) {}
            ~PrimeIterator() = default;

            // assignment operator
            PrimeIterator &operator=(PrimeIterator &iter)
            {
                if(this->mContainer != iter.mContainer)
                {
                    throw std::runtime_error("different containers");
                }
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
                return index < iter.index;
            }
            bool operator>(PrimeIterator &iter)
            {
                return index > iter.index;
            }

            // dereference operator
            int &operator*()
            {
                return mContainer.getPrimeElements()[static_cast<std::vector<int>::size_type>(index)];
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
                index = mContainer.getPrimeElements().size();
                return *this;
            }

        }; // PrimeIterator

    }; // MagicalContainer

}