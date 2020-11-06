#ifndef LINKED_LIST_C
#define LINKED_LIST_C

#include "LinkedList.h"

/**
 * Allocates a new Node and returns it.
 * 
 * data: First node content
 * next: Pointer to the next node.
 */
Node* llNewList(void* data, Node* next)
{
    Node* result = 
        (Node*)malloc(sizeof(Node));

    result->data          = data;
    result->next          = next;
    
    return result;
}


/**
 * Add a new Node to the list
 * Return the reference to the new node for extern uses
 * 
 * start: A pointer to list first node
 * data: The content of the next node
 * callback: Pointer to function of next node 
 * autoreset: Boolean indicating if autoreset or not
 */
Node* llAddElement(Node* start, void* data)
{ 
  // Pointer to last list element
  Node* last = llGetLast(start);
  
  if (last == NULL)
    return NULL;
  
  // Create the new Node with specified data
  Node* newNode = llNewList(data, NULL);
  // Adding it to the list
  last->next = newNode;
  
  return newNode;
}


/**
 * Gets the pointer to the last element of the list
 * 
 * start: A pointer to list
 */
Node* llGetLast(Node* start)
{
    if (start == NULL) return NULL;

    // Used to cycle though the elements
    register Node* current;
    
    // Cycle untill next is found
    for (current = start; 
         current->next != NULL; 
         current = current->next);
    
    return current;
}

/**
 * Gets the pointer to the specified element of the list
 * 
 * start: A pointer to list
 * index: index of the element you want
 */
Node* llElementAt (Node* start, unsigned int index)
{
  if (start == NULL) return NULL;

    // Used to cycle though the elements
    register Node* current;
    register int i;
    
    // Cycle untill next is found
    for (current = start, i = 0; 
         current->next != NULL && i != index; 
         current = current->next, i++);
    
    return current;
}

/**
 * Gets the number of elements in the list
 * 
 * start: A pointer to list
 */
unsigned int llGetLength (Node* start)
{
    if (start == NULL)
        return 0;

    unsigned int count;
    register Node* current;
    
    for (
        current = start, count = 1;
        current->next != NULL;
        current = current->next, count++);

    return count;
}

/**
 * Remove the Node at specified index from the list
 * 
 * start: A pointer to pointer to list first node
 * index: the index of the node to remove
 */
void llRemoveElementAt(Node** start, unsigned int index)
{ 
  if(index != 0)
  {
    Node* indexNode = llElementAt(*start, index);
    
    // link the previous node with the next one
    llElementAt(*start, index-1)->next = indexNode->next;
    
    // Free the memory of the unused node
    free(indexNode);
  }
  else
  {
    // Save reference to head
    Node* tmp = *start;
    
    // Change reference to head
    *start = (*start)->next;
      
    // Free unused node
    free(tmp);
  }
}

/**
 * Search a specified node in the list
 * Returns a boolean: true if found, false else
 * 
 * start: A pointer to pointer to list first node
 * node: the node to be searched
 */
bool llContains(Node* start, Node* node)
{
  register Node* current;
  
  // Cycle all the list
  for (current = start; 
         current != NULL; 
         current = current->next)
    if (current == node)
      return true;
  return false;
}

/**
 * Remove a specified node in the list
 * 
 * start: A pointer to pointer to list first node
 * node: the node to be removed
 */
void llRemoveElement(Node** start, Node* node)
{
    // If first node change head pointer
    if (*start == node)
    {
        *start = node->next;
        free(node);
        return;
    }
    
    // Else search for element
    register Node* current;
    for (
         current = *start;
         current != NULL;
         current = current->next)
    {
        // Link previous with next
        if (current->next == node)
            current->next = node->next;
        
        // Free unused memory
        free(node);
        return;
    }
}

#endif // !LINKED_LIST_C
