#pragma once

#include "Uncopyable.h"


/**
 * Singleton class. (Singleton Pattern).
 * Anyone that inherite this class is a singleton.
 */
template<class T>
class Singleton : virtual private Uncopyable<Singleton<T>> {

    private:
        friend T; // To allow private inheritence.

    private:
        Singleton() = default;
        virtual ~Singleton() = default;


    public:
        /**
         * Returns the instance of this singleton.
         *
         * \return The singleton instance.
         */
        static T& getInstance() {
            static T m_instance;
            return m_instance;
        }


    public:
        virtual void startup() = 0;
        virtual void shutdown() = 0;
};
