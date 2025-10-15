#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char String[30];
typedef struct Node {
    String spell;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
}Set;

// Create a new empty set
Set* createSet();

// Add a spell to the set (no duplicates)
bool addSpell(Set* set, String spell);

// Remove a spell from the set
bool removeSpell(Set** set, String spell);

// Check if a spell exists in the set
bool containsSpell(Set* set, String spell);

// Print all spells in the set
void printSet(Set* set);

// Free all memory associated with the set
void destroySet(Set* set);

Set* unionSets(Set* set1, Set* set2);
Set* intersectSets(Set* set1, Set* set2);

// write your functions here...
Set* createSet() 
{
    Set* set = (Set*)malloc(sizeof(Set));
    set->head = NULL;
    set->size = 0;
    return set;
}

bool addSpell(Set* set, String spell) 
{
    if (containsSpell(set, spell)) 
    {
        return false;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->spell, spell);
    newNode->next = set->head;
    set->head = newNode;
    set->size++;
    
    return true;
}

bool removeSpell(Set** setPtr, String spell) 
{
    Set* set = *setPtr;
    Node* current = set->head;
    Node* prev = NULL;

    while (current != NULL) 
    {
        if (strcmp(current->spell, spell) == 0) 
        {
            if (prev == NULL) 
            {
                set->head = current->next;
            } 
            else 
            {
                prev->next = current->next;
            }
            free(current);
            set->size--;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

bool containsSpell(Set* set, String spell) 
{
    Node* current = set->head;
    while (current != NULL) 
    {
        if (strcmp(current->spell, spell) == 0) 
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void printSet(Set* set) 
{
    Node* current = set->head;
    int index = 1;
    
    if (current == NULL) 
    {
        printf("No spells in the set.\n");
        return;
    }
    
    while (current != NULL) 
    {
        printf("  %d. %s\n", index, current->spell);
        current = current->next;
        index++;
    }
}

void destroySet(Set* set) 
{
    Node* current = set->head;
    
    while (current != NULL) 
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    free(set);
}

Set* unionSets(Set* set1, Set* set2) 
{
    Set* result = createSet();
    Node* current = set1->head;
    
    while (current != NULL) 
    {
        addSpell(result, current->spell);
        current = current->next;
    }
    
    current = set2->head;
    
    while (current != NULL) 
    {
        addSpell(result, current->spell);
        current = current->next;
    }
    return result;
}

Set* intersectSets(Set* set1, Set* set2) 
{
    Set* result = createSet();
    Node* current = set1->head;
    
    while (current != NULL) 
    {
        if (containsSpell(set2, current->spell)) 
        {
            addSpell(result, current->spell);
        }
        current = current->next;
    }
    return result;
}

int main() {
    String spell;
    Set* fireSpells = createSet();
    Set* waterSpells = createSet();

	strncpy(spell,"Flame Burst",12);
	spell[11]='\0';
	addSpell(fireSpells, spell);

	strncpy(spell,"Inferno",8);
	spell[7]='\0';
	addSpell(fireSpells, spell);

	strncpy(spell,"Aqua Jet",9);
	spell[8]='\0';
	addSpell(waterSpells, spell);

	strncpy(spell,"Inferno",8);
	spell[7]='\0';
	addSpell(waterSpells, spell);

	Set* commonSpells = intersectSets(fireSpells, waterSpells);
	Set* allSpells = unionSets(fireSpells, waterSpells);

	printf("\nCommon Spells:\n");
	printSet(commonSpells);

	printf("\nAll Spells:\n");
	printSet(allSpells);

	strncpy(spell,"Aqua Jet",9);
	spell[8]='\0';
	removeSpell(&allSpells,spell);

	printf("\nAll Spells:\n");
	printSet(allSpells);

	destroySet(fireSpells);
	destroySet(waterSpells);
	destroySet(commonSpells);
	destroySet(allSpells);

return 0;
}