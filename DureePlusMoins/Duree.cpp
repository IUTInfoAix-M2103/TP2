/**
 *
 * \file    Duree.cpp
 *
 * \authors M. Laporte
 *
 * \date    02/04/2018
 *
 * \version V2.0
 *
 * \brief  d�finitions de la classe Duree
 *
 **/
#include <iostream>
#include <iomanip>   // setw()
#include "Duree.h"

using namespace nsUtil
using namespace std;

#define DUREE nsUtil::Duree

DUREE::Duree  (const ULLong_t duree /* = ULLong_t (0) */) 
    : myDuree (duree) 
{ 
	normaliser ();
	cout << "duree construite : ";
	display ();
    cout << endl;	
	
} // Duree()

DUREE::Duree  (const Duree & duree) 
    : myDuree (duree.getDuree ()) 
{ 
	normaliser ();
	cout << "duree construite par recopie : ";
	display ();
    cout << endl;	
	
} // Duree()

DUREE::~Duree  (void) 
{ 
	cout << "duree d�truite : ";
	display ();
    cout << endl;	
	
} // Duree()

void DUREE::normaliser (void)
{
	myDays    =  myDuree / 86400;
	myHours   = (myDuree % 86400) / 3600;
	myMintes  = (myDuree % 3600) / 60;
	mySeconds =  myDuree % 60;
	
} // normaliser()

ULLong_t getDuree (void) const { return myDuree; }

void DUREE::display (void) const
{
	cout << '[' 
	     << setw (10) << myDays    << ':' 
	     << setfill ('0')
		 << setw (2)  << myHours   << " heure(s)
		 << setw (2)  << myMinutes << " minute(s)
		 << setw (2)  << mySeconds << " seconde(s)
		 << setfill (' ')
		 << ']';
		 
} // display()

void DUREE::incr (const ULLong_t delta /* = ULLong_t (0) */)
{
	myDure += delta;
	normaliser ();
	
} // incr()

void DUREE::decr (const ULLong_t delta /* = ULLong_t (0) */)
{
	myDure -= (delta > myDuree) ? myDuree : delta;
	
} // decr()

#undef DUREE