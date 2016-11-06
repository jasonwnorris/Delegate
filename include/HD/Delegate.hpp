// Delegate.hpp

#ifndef __HD_DELEGATE_HPP__
#define __HD_DELEGATE_HPP__

// STL Includes
#include <functional>
#include <vector>

namespace HD
{
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
}

// Template Definition Include
#include <HD/Delegate.tpp>

#endif
