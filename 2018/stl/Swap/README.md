Main point is to use swap();

template <class T> void swap ( T& a, T& b )
{
  T c(a); a=b; b=c;
}
