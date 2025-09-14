#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node
{
  long phoneno;
  char Name[50];
  struct Node *link;
};
typedef struct Node *coninfo;

coninfo newnode()
{
  coninfo newNodePtr = (coninfo)malloc(sizeof(struct Node));
  if (newNodePtr == NULL)
  {
    printf("\nError allocating dynamic memory!!\n");
    exit(0);
  }
  return newNodePtr;
}

coninfo fnnewcontact(coninfo listptr, long phnum, char name[])
{

  coninfo temp, cur;
  temp = newnode();
  temp->phoneno = phnum;
  strcpy(temp->Name, name);
  temp->link = NULL;

  if (listptr == NULL)
    return temp;
  else
  {
    cur = listptr;
    while (cur->link != NULL)
      cur = cur->link;
    cur->link = temp;
  }
  return listptr;
}

void fndisplaycontact(coninfo listptr)
{
  coninfo cur;
  if (listptr == NULL)
  {
    printf("\nContact List is empty\n");
  }
  else
  {
    cur = listptr;
    printf("\nList contents : \n");
    while (cur != NULL)
    {
      printf("%s : %li\n", cur->Name, cur->phoneno);
      cur = cur->link;
    }
  }
  printf("\n");
}

coninfo fndeletecontact(coninfo listptr, char name[])
{
  coninfo temp, prev, cur;

  if (listptr == NULL)
  {
    printf("\nContact List is Empty\n");
    return listptr;
  }

  if (strcmp(listptr->Name, name) == 0)
  {
    temp = listptr;
    listptr = listptr->link;
    printf("\nContact Deleted : %s\n", name);
    free(temp);
    return listptr;
  }

  prev = NULL;
  cur = listptr;
  while (cur != NULL && strcmp(cur->Name, name) != 0)
  {
    prev = cur;
    cur = cur->link;
  }

  if (cur == NULL)
  {
    printf("\nContact not found\n");
  }
  else
  {
    prev->link = cur->link;
    printf("\nDeleted Contact : %s\n", cur->Name);
    free(cur);
  }
  return listptr;
}

bool conditiona(coninfo cur, char name[])
{
  return strcmp(cur->Name, name) == 0;
}

void fnsearchcontact(coninfo listptr, char name[])
{
  coninfo cur;

  if (listptr == NULL)
  {
    printf("\nList is empty\n");
  }
  else
  {
    cur = listptr;
    while (cur != NULL && !conditiona(cur, name))
    {
      cur = cur->link;
    }

    if (cur == NULL)
    {
      printf("\nContact %s not found.\n", name);
    }
    else
    {
      printf("\nContact Name : %s\nContact Number : %li\n", cur->Name, cur->phoneno);
    }
  }
}

bool isDuplicate(coninfo listptr, char name[], long phonenumber)
{
  coninfo cur = listptr;
  while (cur != NULL)
  {
    if (cur->phoneno == phonenumber)
      return true;
    cur = cur->link;
  }
  return false;
}

int main()
{
  coninfo lastptr = NULL;
  long number;
  char name[50];
  int choice;

  printf("\n1.Add new contact\n2.Display all contacts\n3.Delete a Contact\n");
  printf("4.Search a Contact\n5.Exit\n");

  while (1)
  {

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("\nEnter the Phone Number(10 digits) : ");
      scanf("%li", &number);
      if (isDuplicate(lastptr, name, number))
      {
        printf("\nContact already exists.\n\n");
      }
      printf("Enter the Contact's name : ");
      scanf("%49s", name);
      lastptr = fnnewcontact(lastptr, number, name);
      break;

    case 2:
      fndisplaycontact(lastptr);
      break;

    case 3:
      printf("\nEnter the Contact's Name to be Deleted : ");
      scanf("%49s", name);
      lastptr = fndeletecontact(lastptr, name);
      break;

    case 4:
      printf("\nEnter the Contact's Name to be Searched : ");
      scanf("%49s", name);
      fnsearchcontact(lastptr, name);
      break;

    case 5:
      printf("\nExit\n");
      exit(0);

    default:
      printf("\nInvalid Choice !!\n");
      break;
    }
  }
  return 0;
}
