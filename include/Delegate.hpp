// Delegate.hpp

#ifndef __DELEGATE_HPP__
#define __DELEGATE_HPP__

// STD Includes
#include <functional>
#include <vector>

template<typename Ret, typename... Args> class Delegate
{
  public:
    template<typename U> Delegate& Add(const U& p_Function);
    template<typename U> Delegate& Remove(const U& p_Function);
    template<typename U> Delegate& RemoveAll();

    std::vector<Ret> operator()(Args... p_Parameters);

  private:
    std::vector<std::function<Ret(Args...)>> m_Functions;
};

template<typename... Args> class Delegate<void, Args...>
{
  public:
    template<typename U> Delegate& Add(const U& p_Function);
    template<typename U> Delegate& Remove(const U& p_Function);
    template<typename U> Delegate& RemoveAll();

    void operator()(Args... p_Parameters);

  private:
    std::vector<std::function<void(Args...)>> m_Functions;
};

// Template Definition Include
#include "Delegate.tpp"

#endif
