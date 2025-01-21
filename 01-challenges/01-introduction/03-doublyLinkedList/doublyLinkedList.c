// Header files
#include <stdio.h>
#include <stdlib.h>

// Global Function signatures

// Global variables
struct node
{
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node* NODEPTR;

// Entry Point Function
int main()
{
  // function declarations
  NODEPTR getnode();
  void displayList(NODEPTR);
  void insert(NODEPTR);
  void find(NODEPTR);
  void delete();


  // variable declarations
  NODEPTR q;
  NODEPTR pList;
  int ch = 0;

  pList = getnode();

  if (pList == NULL)
  {
    printf("p = getnode() failed!\n");
  }
  else
  {
    pList->data = -1;
    pList->next = NULL;
    pList->prev = NULL;
  }

  while (ch != 5)
  { 

    printf("What would you like to do today?\n1. display doubly linked list\n2. insert element\n3. find element\n4. delete element\n5. quit program\n");
    scanf("%d", &ch);
    printf("Selected option: %d\n", ch);
    
    switch (ch)
    {
      case 1:
        displayList(pList);
        break;
      case 2:
        insert(pList);
        break;
      case 3:
        find(pList);
        break;
      case 4:
        delete(pList);
        break;
      case 5:
        printf("Thank you for using this program! Bye!\n");
        return 0;
      default:
        printf("Incorrect option entered, please try again!\n");
        break;
   }
  }
}

void displayList(NODEPTR pList)
{
  // code
  NODEPTR p;
  NODEPTR q;

  printf("Display list in normal order\n");
  for (p = pList; p != NULL; p = p->next)
  {
    printf("%d\n", p->data);
  }

  printf("Display list in reverse (using reverse traversal in doubly linked list)\n");

  for (q = pList; q->next != NULL; q = q->next);

  while (q->prev != NULL)
  {
    printf("%d\n", q->data);
    q = q->prev;
  }

}

void insert(NODEPTR pList)
{
  // function declarations
  NODEPTR getnode();

  // code
  NODEPTR p;
  NODEPTR q;
  int val;

  printf("Enter new value to be inserted into linked list\n");
  scanf("%d", &val);

  q = getnode();

  if (q == NULL)
  {
    printf("q = getnode() in insert() failed!\n");
  }
  else
  {
    // place new data in list
    for (p = pList; p->next != NULL; p = p->next);

    p->next = q;
    q->data = val;
    q->next = NULL;
    q->prev = p;

    printf("\nNew element inserted\n");
  }
}

void find(NODEPTR pList)
{
  // variable declarations
  NODEPTR p;
  int val = -1;
  int i = 0;
  // code

  printf("Which number do you wish to find?\n");
  scanf("%d", &val);

  printf("Searching %d in the list\n", val);

  for (p = pList; p->next != NULL; p = p->next)
  {
    i++;

    if (p->data == val)
    {
      printf("Value found at index: %d\n", i);
    }

    p = p->next;
  }
}

void delete(NODEPTR pList)
{
  // variable declarations
  NODEPTR p;
  int val;

  printf("Enter value to be deleted\n");
  scanf("%d", &val);

  // code

  for (p = pList; p->next != NULL; p = p->next)
  {
    if (p->data == val)
    {
      p->next->prev = p->prev;
      p->prev->next = p->next;
      break;
    }
  }
  
  while(p->prev != NULL)
  {
    p = p->prev;
  }

  pList = p;

}

NODEPTR getnode()
{
  return (struct node*)malloc(sizeof(struct node*));
}

