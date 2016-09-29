////////////////////////////////////////////////////////////////////////////
//
// clisti.h
//
// CConstListIterator<class T> template definition
//
// Remi Coulom
//
// june 1996
//
////////////////////////////////////////////////////////////////////////////
#ifndef CLISTI_H
#define CLISTI_H

#include "list.h"

////////////////////////////////////////////////////////////////////////////
// CConstListIterator class definition
////////////////////////////////////////////////////////////////////////////
template<class T>
class CConstListIterator // listi
{
 private: //////////////////////////////////////////////////////////////////
  const CList<T>        *plt;
  const CListCell<T>    *pcellCurrent;
  const CListCell<T>    *pcellPrevious;

 public: ///////////////////////////////////////////////////////////////////
                CConstListIterator(const CList<T>& ltInit);

  void          Increment(void);
  void          Reset(void);

  const T&      Value(void) const;
  int           IsFirst(void) const {return !pcellPrevious;};
  int           IsAtTheEnd(void) const {return !pcellCurrent;};
};

////////////////////////////////////////////////////////////////////////////
// Constructor
////////////////////////////////////////////////////////////////////////////
template<class T>
        CConstListIterator<T>::CConstListIterator(const CList<T>& ltInit)
{
 plt = &ltInit;
 pcellPrevious = 0;
 pcellCurrent = ltInit.pcellFirst;
}

////////////////////////////////////////////////////////////////////////////
// Resets an iterator to the beginning of its list
////////////////////////////////////////////////////////////////////////////
template<class T>
void            CConstListIterator<T>::Reset(void)
{
 pcellPrevious = 0;
 pcellCurrent = plt->pcellFirst;
}

////////////////////////////////////////////////////////////////////////////
// Moves to the next position in a list
////////////////////////////////////////////////////////////////////////////
template<class T>
INLINE
void    CConstListIterator<T>::Increment(void)
{
 ASSERT(!IsAtTheEnd());
 pcellPrevious = pcellCurrent;
 pcellCurrent = pcellCurrent->Next();
}

////////////////////////////////////////////////////////////////////////////
// Reads the value contained by the current cell
////////////////////////////////////////////////////////////////////////////
template<class T>
INLINE
const T&        CConstListIterator<T>::Value(void) const
{
 ASSERT(!IsAtTheEnd());
 return pcellCurrent->Value();
}

#endif