#include "lists.h"
#include <string.h>
#include <stdio.h>

/**
 * add_node - add a new node at the beginning of `list_t` list
 * @head: double pointer to head
 * @str: string to be saved in new node, must be duplicated
 * Return: Address of new element or NULL if failed
 */
list_t *add_node(list_t **head, const char *str) {
    if (str == NULL) {
        return NULL;
    }

    list_t *newNode = malloc(sizeof(list_t));
    if (newNode == NULL) {
        return NULL;
    }

    newNode->str = strdup(str);
    if (newNode->str == NULL) {
        free(newNode);
        return NULL;
    }

    newNode->next = *head;
    *head = newNode;

    return newNode;
}
