// Delegate.tpp

// HD Includes
#include <HD/Delegate.hpp>

#ifdef __HD_DELEGATE_HPP__

namespace HD
{
  template<typename Ret, typename... Args> template<typename U> Delegate<Ret, Args...>& Delegate<Ret, Args...>::Add(const U& p_Function)
  {
    m_Functions.push_back(std::function<Ret(Args...)>(p_Function));

    return *this;
  }

  template<typename Ret, typename... Args> template<typename U> Delegate<Ret, Args...>& Delegate<Ret, Args...>::Remove(const U& p_Function)
  {
    m_Functions.erase(m_Functions.remove(m_Functions.begin(), m_Functions.end(), p_Function), m_Functions.end());

    return *this;
  }

  template<typename Ret, typename... Args> template<typename U> Delegate<Ret, Args...>& Delegate<Ret, Args...>::RemoveAll()
  {
    m_Functions.clear();

    return *this;
  }

  template<typename Ret, typename... Args> std::vector<Ret> Delegate<Ret, Args...>::operator()(Args... p_Parameters)
  {
    std::vector<Ret> ret;
    for (auto function : m_Functions)
    {
      m_Functions.push_back(function(p_Parameters...));
    }

    return ret;
  }

  template<typename... Args> template<typename U> Delegate<void, Args...>& Delegate<void, Args...>::Add(const U& p_Function)
  {
    m_Functions.push_back(std::function<void(Args...)>(p_Function));

    return *this;
  }

  template<typename... Args> template<typename U> Delegate<void, Args...>& Delegate<void, Args...>::Remove(const U& p_Function)
  {
    m_Functions.erase(m_Functions.remove(m_Functions.begin(), m_Functions.end(), p_Function), m_Functions.end());

    return *this;
  }

  template<typename... Args> template<typename U> Delegate<void, Args...>& Delegate<void, Args...>::RemoveAll()
  {
    m_Functions.clear();

    return *this;
  }

  template<typename... Args> void Delegate<void, Args...>::operator()(Args... p_Parameters)
  {
    for (auto function : m_Functions)
    {
      function(p_Parameters...);
    }
  }
}

#endif
