
#ifndef  _KOLEJKA_FIFO
#define _KOLEJKA_FIFO

typedef struct tagQItem
{
	int nKey;
	tagQItem* pNext;
} QItem;

typedef struct
{
	QItem* pHead;
	QItem* pTail;
} Kolejka;

Kolejka* Create( );
int isEmpty( Kolejka* q );     						// Sprawdza, czy kolejka jest pusta
void EnQueue( Kolejka* q, int x );			    	// Wk�ada do kolejki
int DeQueue( Kolejka* q );					      	// Wyrzu� z kolejki
void Clear( Kolejka* q );                         	// Czy�ci wszystko, zostawia kolejk� jako struktur�
void Del( Kolejka** q );                          	// Usuni�cie ca�ej kolejki


#endif


