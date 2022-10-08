#include <stdio.h>  /*printf*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

//der laves et struct, der indeholder elementerne: int data og en pointer *next
typedef struct node 
{
  int data;
  struct node *next;
} node;


// funktion add, der får værdierne fra en pointer, og et heltal
void add(node *head, int x)
{
  /*pre: head points to the first, empty element. The last element's next is NULL
    post: a new node containing x is added to the end of the list*/

  // vores funktion laver assert, hvis vores pointer ikke er lig med nul.
  assert(head!=NULL); 

  // laver en struct pointer *p til vores pointer head, som vi har fået
  node *p = head;

  // et while-loop, der siger, at hvis vores pointer, der peger
  // hen mod det næste date ikke er lig med 0, så vil while-loopet køre
  // indtil vores pointer er lig NULL.
  while (p->next!=NULL)
  {
    // while loopet, kører indtil vores pointer *p peger hen mod det sidste element.
    p = p->next;
  } /*p points to the last element*/

  // når *p har ramt det sidste element vil der blive skabt en nyt element til listen.
  node *element = (node*) malloc(sizeof(node));

  // elementet får værdien NULL
  element->next = NULL;

  // og dataen i NULL får værdien x. 
  element->data = x;

  // Tilsidst har vi vores pointer *p, der peger hen mod vores nye værdi element med x og NULL.
  p->next = element; 
}

int size(node *l){
    // Excercise 3b)
    /*pre: head points to the first, empty element. The last element's next is NULL
    post: a new node containing x is added to the end of the list*/

    // vi skal returnere, hvor mange elementer, der er i vores liste.
    // laver en variabel, der kan tælle elementerne
    int x = 0;

    // tager vores pointer *l, og kalder den *p i vores funktion
    node *p = l;

    // laver et while-loop der kører indtil vi rammer slutningen af listen, NULL
    while(p->next != NULL)
    {
    // vi plusser med en, for hver gang vi kører igennem listen
      x++;
    // tager vores pointer og peger mod den næste værdi i listen
      p = p->next;
    }

    // tilsidst får vi antallet af elementer i vores liste igennem x

    return x;
}

void printout(node *l)
{
  /*Excercise 3d) Implement your changes.. 
    pre: head points to the first, empty element. The last element's next is NULL
    post: the values of the list are printed out*/

    // laver en pointer, der tager den kaldte pointer l->next.
    node *p = l->next;

    // så længe p ikk er lig med 0, kører while-loopet
    while(p != NULL)
    {
    // print, dataen for listens element værdi. 
      printf("%d, ",p->data);

    // ændring her!! 
    // for at funktionen ikke er fanget i while-loopet, så skal vi få
    // pointeren p til at pege mod det næste element i listen. 
      p = p->next;
    }
    printf("\n");
}

int largest(node *l){
    /*Excercise 3e) Add your code below.
      pre: head points to the first, empty element. The last element's next is NULL. size(l>0)
      post: returns the largest value of the list*/

    // laver en pointer, der tager den kaldte pointer l->next.
    node *p = l->next;

    // laver en variabel, der kan returnere den største værdi i listen.
    // starter med at sætte den til 0.
    int a = 0;

    // laver et while-loop, der kører gennem listen indtil pointeren p peger
    // mod det sidste element i listen, som er NULL
    while(p != NULL)
    {
    
    // hvis a er mindre elements data, så kører if-statementet.
      if(a < p->data)
      {
        // a antager den nye værdi, der er hidtil er den største
        a = p->data;
      }
    // kører videre til næste i loopet. 
      p = p->next;
    }
    
    // når while-loopet har været igennem hele listen,
    // vil den største værdi være fundet og gemt i variabel a.
    // returnere den største værdi i listen.
    return a; 
}
