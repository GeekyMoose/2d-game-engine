#pragma once

/**
 * Uncopyable class.
 * Anyone that inherite from this class can't be copied anymore.
 *
 * \author  Constantin Masson
 * \date    Oct 2017
 */
template<class T>
class Uncopyable {
    public:
        Uncopyable() = default;
        virtual ~Uncopyable() = default;

    private:
        Uncopyable(Uncopyable<T> const& other) = delete;
        Uncopyable<T>& operator=(Uncopyable<T> const& other) = delete;
};
