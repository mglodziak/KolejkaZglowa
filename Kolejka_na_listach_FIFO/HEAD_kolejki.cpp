#include "Head_kolejki.h"
#include <stdlib.h>
#include <stdio.h>

Kolejka* Create( )
{
	Kolejka* q = ( Kolejka* )calloc( 1, sizeof( Kolejka ) );
	QItem* r = ( QItem* )calloc( 1, sizeof( QItem ) );

	if ( !q || !r )
		printf( "Error Creating!!!" );

	q->pHead = q->pTail = r;
	return q; //nigdzie nie ma nulla

}
//----------
int isEmpty( Kolejka* q )
{
	return ( !q->pHead->pNext );
}
//----------
void EnQueue( Kolejka* q, int x )
{
	QItem* nowy_elem = ( QItem* )calloc( 1, sizeof( QItem ) );
	if ( !nowy_elem )
	{
		printf ( "Error: nie udalo sie zaalokowac pamieci do nowego elementu\n" );
		return;
	}
	q->pTail->pNext = nowy_elem;
	q->pTail = nowy_elem;
	nowy_elem->nKey = x;
}
//----------
int DeQueue( Kolejka* q )
{
	if ( isEmpty( q ) )
	{
		printf ( "Error: kolejka jest juz pusta" );
		return 0;
	}
	QItem* top = q->pHead->pNext;
	q->pHead->pNext = top->pNext;
	int wynik = top->nKey; // wynik juz mamy 
	free ( top );

	if ( isEmpty( q ) )
		q->pTail = q->pHead;
	
	return wynik;
}
//----------
void Clear( Kolejka* q )
{
	if ( !q )
	{
		printf( "\nError: Brak kolejki do usuniecia!!\n" );
		return;
	}
	while ( !isEmpty ( q ) )
		DeQueue ( q );

}
//----------
void Del( Kolejka** q )
{
	Clear ( *q ); //nie sprawdzam juz czy jest kolejka, sprawdza sie w clear
	free (( *q )->pHead);
	free( *q );
	*q = NULL;
}

