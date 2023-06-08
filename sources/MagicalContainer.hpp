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

            AscendingIterator &operator=(const AscendingIterator &iter)
            {
                if (&mContainer != &iter.mContainer)
                {
                    throw std::runtime_error("Iterators are pointing to different containers.");
                }
                index = iter.index;
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

        // ***************************************//
        // SideCrossIterator                     //
        // ***************************************//
        class SideCrossIterator
        {
        private:
            MagicalContainer &mContainer;
            int index;

        public:
            SideCrossIterator() = delete;
            SideCrossIterator(MagicalContainer &mContainer) : mContainer(mContainer), index(0) {}
            SideCrossIterator(const SideCrossIterator &iter) : mContainer(iter.mContainer), index(iter.index) {}
            ~SideCrossIterator() = default;

            SideCrossIterator &operator=(const SideCrossIterator &iter)
            {
                if (&mContainer != &iter.mContainer)
                {
                    throw std::runtime_error("You try to pointing at different containers");
                }
                if (this != &iter)
                {
                    this->index = iter.index;
                }
                return *this;
            }

            // comparison operators
            bool operator==(SideCrossIterator &iter)
            {
                if (typeid(*this) != typeid(iter))
                {
                    throw std::runtime_error("Compare different types of iterators ");
                }

                return this->index == iter.index;
            }

            //	Inequality comparison
            bool operator!=(SideCrossIterator &iter)
            {
                return !(this->index == iter.index);
            }

            // GT comparison
            bool operator<(const SideCrossIterator &iter) const
            {
                return index < iter.index;
            }

            // LT comparison
            bool operator>(const SideCrossIterator &iter) const
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
            SideCrossIterator &operator++()
            {
                if (index == mContainer.size())
                {
                    throw std::runtime_error("You are in the last element");
                }
                if (index == (mContainer.size() / 2))
                {
                    index = mContainer.size();
                    return *this;
                }

                if (index < (mContainer.size() / 2))
                {
                    index = mContainer.size() - index - 1;
                    return *this;
                }

                else if (index > (mContainer.size() / 2))
                {
                    index = mContainer.size() - index;
                    return *this;
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
                index = mContainer.size();
                return *this;
            }

        }; // SideCrossIterator

        // ***************************************//
        // PrimeIterator                      //
        // ***************************************//
        class PrimeIterator
        {
        private:
            MagicalContainer &mContainer;
            int index;

        public:
            PrimeIterator() = delete;
            PrimeIterator(MagicalContainer &mContainer) : mContainer(mContainer), index(0) {}
            PrimeIterator(const PrimeIterator &iter) : mContainer(iter.mContainer), index(iter.index) {}
            ~PrimeIterator() = default;

            PrimeIterator &operator=(const PrimeIterator &iter)
            {
                if (&mContainer != &iter.mContainer)
                {
                    throw std::runtime_error("Iterators are pointing to different containers.");
                }
                index = iter.index;
                return *this;
            }

            // comparison operators
            bool operator==(PrimeIterator &iter)
            {
                if (typeid(*this) != typeid(iter))
                {
                    throw std::runtime_error("Compare different types of iterators ");
                }

                return this->index == iter.index;
            }

            //	Inequality comparison
            bool operator!=(PrimeIterator &iter)
            {
                return !(this->index == iter.index);
            }

            // GT comparison
            bool operator<(const PrimeIterator &iter) const
            {
                return index < iter.index;
            }

            // LT comparison
            bool operator>(const PrimeIterator &iter) const
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
                return *mContainer.getPrimeElements()[static_cast<std::vector<int>::size_type>(index)];
            }

            // pre-increment operator
            PrimeIterator &operator++()
            {
                if (index >= mContainer.getPrimeElements().size())
                {
                    throw std::runtime_error("You are in the last element");
                }
                ++index;
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