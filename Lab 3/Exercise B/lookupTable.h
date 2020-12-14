// LookupTable.h
// ENSF 480 - Fall 2019 - Lab 3, Ex A

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H
#include <iostream>
using namespace std;

// class LookupTable: GENERAL CONCEPTS
//
//    key/datum pairs are ordered.  The first pair is the pair with
//    the lowest key, the second pair is the pair with the second
//    lowest key, and so on.  This implies that you must be able to
//    compare two keys with the < operator.
//
//    Each LookupTable has an embedded iterator class that allows users
//    of the class to traverse trhough the list and  have acess to each
//    node. 

#include "customer.h"

//    In this version of the LookupTable a new struct type called Pair
//    is introduced which represents a key/data pair.


typedef int LT_Key; 
typedef Customer LT_Datum;
template <typename T> class LookupTable;
 
template <typename T>
struct Pair 	
{
  Pair(LT_Key keyA,T datumA):key(keyA), datum(datumA)
  {
  } 
  
  LT_Key key;
  T datum;
};

template <typename T>
class LT_Node {
  friend class LookupTable<T>;
private:
  Pair<T> pairM;
  LT_Node *nextM;

  // This ctor should be convenient in insert and copy operations.
  LT_Node(const Pair <T> &pairA, LT_Node *nextA);
};

template <typename T>
class LookupTable {
 public:

  // Nested class
  class Iterator {
    friend class LookupTable ;
    LookupTable *LT;
//    LT_Node* cursor;
    
  public:
    Iterator():LT(0){}
    Iterator(LookupTable & x): LT(&x){}
    const T&  operator *();
    const T& operator ++();
    const T& operator ++(int);
    int operator !();

    void step_fwd(){  assert(LT->cursor_ok());
    LT->step_fwd();}
  };

  LookupTable();
  LookupTable(const LookupTable  & source);
  LookupTable& operator =(const LookupTable& rhs);
  ~LookupTable();

  LookupTable& begin();

  int size() const;
  // PROMISES: Returns number of keys in the table.

  int cursor_ok() const;
  // PROMISES: 
  //   Returns 1 if the cursor is attached to a key/datum pair,
  //   and 0 if the cursor is in the off-list state.

  const LT_Key& cursor_key() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns key of key/datum pair to which cursor is attached.

  const T& cursor_datum() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns datum of key/datum pair to which cursor is attached.

  void insert(const Pair <T> &pariA);
  // PROMISES:
  //   If keyA matches a key in the table, the datum for that
  //   key is set equal to datumA.
  //   If keyA does not match an existing key, keyA and datumM are
  //   used to create a new key/datum pair in the table.
  //   In either case, the cursor goes to the off-list state.

  void remove(const LT_Key& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the corresponding
  //   key/datum pair is removed from the table.
  //   If keyA does not match an existing key, the table is unchanged.
  //   In either case, the cursor goes to the off-list state.

  void find(const LT_Key& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the cursor is attached
  //   to the corresponding key/datum pair.
  //   If keyA does not match an existing key, the cursor is put in
  //   the off-list state.

  void go_to_first();
  // PROMISES: If size() > 0, cursor is moved to the first key/datum pair
  //   in the table.

  void step_fwd();
  // REQUIRES: cursor_ok()
  // PROMISES: 
  //   If cursor is at the last key/datum pair in the list, cursor
  //   goes to the off-list state.
  //   Otherwise the cursor moves forward from one pair to the next.

  void make_empty();
  // PROMISES: size() == 0.
	template <typename Y>
  friend  ostream& operator << (ostream& os, const LookupTable<T> &lt);

 private:
  int sizeM;
  LT_Node<T> *headM;
  LT_Node<T> *cursorM;

  void destroy();
  // Deallocate all nodes, set headM to zero.
  
  void copy(const LookupTable& source);
  // Establishes *this as a copy of source.  Cursor of *this will
  // point to the twin of whatever the source's cursor points to.
};

#endif

template <typename T>
LookupTable<T>& LookupTable<T>::begin(){
  cursorM = headM;
  return *this;
}

template <typename T>
LT_Node<T>::LT_Node(const Pair <T> &pairA, LT_Node *nextA)
  : pairM(pairA), nextM(nextA)
{
}

template <typename T>
LookupTable<T>::LookupTable()
  : sizeM(0), headM(0), cursorM(0)
{
}

template <typename T>
LookupTable<T>::LookupTable(const LookupTable<T> &source)
{
  copy(source);
}

template <typename T>
LookupTable<T>& LookupTable<T>::operator =(const LookupTable<T>& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

template <typename T>
LookupTable<T>::~LookupTable()
{
  destroy();
}

template <typename T>
int LookupTable<T>::size() const
{
  return sizeM;
}

template <typename T>
int LookupTable<T>::cursor_ok() const
{
  return cursorM != 0;
}

template <typename T>
const LT_Key& LookupTable<T>::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->pairM.key;
}

template <typename T>
const T& LookupTable<T>::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->pairM.datum;
}

template <typename T>
void LookupTable<T>::insert(const Pair <T> &pairA)
{
  // Add new node at head?
  if (headM == 0 || pairA.key < headM->pairM.key) {
    headM = new LT_Node<T>(pairA, headM);
    sizeM++;
  }

  // Overwrite datum at head?
  else if (pairA.key == headM->pairM.key)
    headM->pairM.datum = pairA.datum;

  // Have to search ...

  else {
    LT_Node <T> *before= headM;
    LT_Node <T> *after=headM->nextM;

    while(after!=NULL && (pairA.key > after->pairM.key))
      {
	before=after;
	after=after->nextM;
      }
    
    if(after!=NULL && pairA.key == after->pairM.key)
      {
	after->pairM.datum = pairA.datum;
      }
    else
      {
	before->nextM = new LT_Node<T>(pairA, before->nextM);
	sizeM++;
      }
  }
}

template <typename T>
void LookupTable<T>::remove(const LT_Key& keyA)
{

  if (headM == 0 || keyA < headM->pairM.key)
    return;

  LT_Node <T> *doomed_node = 0;
  if (keyA == headM->pairM.key) {
    doomed_node = headM;
    headM = headM->nextM;
    sizeM--;
  }
  else {
    LT_Node <T> *before = headM;
    LT_Node <T> *maybe_doomed = headM->nextM;
    while(maybe_doomed != 0 && keyA > maybe_doomed->pairM.key) {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != 0 && maybe_doomed->pairM.key == keyA) {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
      sizeM--;
    }      
  } 
  delete doomed_node;           // Does nothing if doomed_node == 0.
}

template <typename T>
void LookupTable<T>::find(const LT_Key& keyA)
{
  LT_Node <T> *ptr=headM;
  while (ptr != NULL && ptr->pairM.key != keyA)
    {
     ptr=ptr->nextM;
    }

   cursorM = ptr;
}

template <typename T>
void LookupTable<T>::go_to_first()
{
  cursorM = headM;
}

template <typename T>
void LookupTable<T>::step_fwd()
{
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

template <typename T>
void LookupTable<T>::make_empty()
{
  destroy();
  sizeM = 0;
  cursorM = 0;
}

template <typename T>
void LookupTable<T>::destroy()
{

  LT_Node <T> *ptr = headM;
  while (ptr!=NULL)
    {
      headM=headM->nextM;
      delete ptr;
      ptr=headM;

    }
  cursorM = NULL;
  sizeM=0;
}

template <typename T>
void LookupTable<T>::copy(const LookupTable<T>& source)
{

  headM=0;
  cursorM =0;

  if(source.headM ==0)
    return;
 
  for(LT_Node <T> *p = source.headM; p != 0; p=p->nextM)
    {
      insert(Pair<T> (p->pairM.key, p->pairM.datum));
      if(source.cursorM == p)
	find(p->pairM.key);
    }

}

template <typename T>
ostream& operator <<   (ostream& os, const LookupTable<T> &lt)
{
  if (lt.cursor_ok())
    os <<lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os<<"Not Found.";

  return os;
}

template <typename T>
const T& LookupTable<T>::Iterator::operator *()
{
  assert(LT ->cursor_ok());
  return LT->cursor_datum();
}

template <typename T>
const T& LookupTable<T>::Iterator::operator ++()
{
	assert(LT->cursor_ok());
 
  LT->step_fwd();
  return LT->cursor_datum();
}

template <typename T>
const T& LookupTable<T>::Iterator::operator ++(int)
{
  assert(LT->cursor_ok());
  const T & x = LT->cursor_datum();
  LT->step_fwd();
  return x;
}

template <typename T>
int LookupTable<T>::Iterator::operator!()
{
  return (LT->cursor_ok());
}


