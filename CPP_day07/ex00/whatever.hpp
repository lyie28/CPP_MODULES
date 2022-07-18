#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
T const & max(const T& a, const T& b)
{
   if(a > b)
      return a;
   else
      return b;
}

template <typename T>
T const & min(const T& a, const T& b)
{
   if(a < b)
      return a;
   else
      return b;
}

template <typename T>
void swap( T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
   return;
}

#endif
