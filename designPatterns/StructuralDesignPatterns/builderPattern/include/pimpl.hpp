#ifndef PIMPL_HPP
#define PIMPL_HPP

#include <memory>

/**
 * @brief a library class to make the pimpl idiom simpler. 
 * This class will be used to expose the impl object and make it easy to use.
 * 
 * @tparam T any type that includes the implementation details.
 */
template<typename T> class pimpl {
    public: 
        pimpl();
        ~pimpl();

        /**
         * @brief Construct a new pimpl object
         * Forwarding constructor
         * 
         * @tparam Args 
         * @param args 
         */
        template <typename ...Args> pimpl(Args&& ...args);

        T* operator->();
        T& operator*();

    private:
        std::unique_ptr<T> impl;
};

template<typename T>
pimpl<T>::pimpl() 
    : impl{new T{}}{
    //
}

template<typename T>
pimpl<T>::~pimpl() {
    //
}

template<typename T>
template<typename ...Args>
pimpl<T>::pimpl(Args&& ...args) 
    : impl{new T{std::forward<Args>(args)...}}{
    //
}

template<typename T>
T* pimpl<T>::operator->() {
    return impl.get();
}

template<typename T>
T& pimpl<T>::operator*(){
    return *impl.get();
}

#endif /* PIMPL_HPP */