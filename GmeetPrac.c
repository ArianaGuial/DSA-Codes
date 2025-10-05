#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PALETTE_SIZE 64
#define MAX_NAME_LENGTH 50

typedef char String[MAX_NAME_LENGTH];

typedef struct 
{
    String colorName;
    int RGBVal[3]; // [R, G, B]
} Color;

typedef struct Node 
{
    Color data;
    struct Node *next;
} Node;

typedef struct 
{
    Node *buckets[PALETTE_SIZE];
} Dictionary;

int hashFunction(int rgb[3]);
void createDictionary(Dictionary *dict);
Node* createNode(Color newColor);
void insertColor(Dictionary *dict, Color newColor);
Color* searchColor(Dictionary *dict, int rgb[3]);
void displayDictionary(Dictionary *dict);
void destroyDictionary(Dictionary *dict);

int hashFunction(int rgb[3]) 
{
    return (rgb[0] * 3 + rgb[1] * 5 + rgb[2] * 7) % PALETTE_SIZE;
}

void createDictionary(Dictionary *dict) 
{
    for (int i = 0; i < PALETTE_SIZE; i++) 
    {
        dict->buckets[i] = NULL;
    }
}

Node* createNode(Color newColor) 
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode != NULL) 
    {
        newNode->data = newColor;
        newNode->next = NULL;
    }
    return newNode;
}

void insertColor(Dictionary *dict, Color newColor) 
{
    int index = hashFunction(newColor.RGBVal);
    Node *newNode = createNode(newColor);

    if (!newNode) 
    {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->next = dict->buckets[index];
    dict->buckets[index] = newNode;
    printf("-> Inserted '%s' (RGB: %d, %d, %d) into bucket [%d].\n",
           newColor.colorName,
           newColor.RGBVal[0],
           newColor.RGBVal[1],
           newColor.RGBVal[2],
           index);
}

Color* searchColor(Dictionary *dict, int rgb[3]) 
{
    int index = hashFunction(rgb);
    printf("Searching for RGB (%d, %d, %d) in bucket [%d]...\n", rgb[0], rgb[1], rgb[2], index);
    Node *current = dict->buckets[index];

    while (current != NULL) 
    {
        if (current->data.RGBVal[0] == rgb[0] &&
            current->data.RGBVal[1] == rgb[1] &&
            current->data.RGBVal[2] == rgb[2]) 
        {
            return &current->data;
        }
        current = current->next;
    }
    return NULL;
}

void displayDictionary(Dictionary *dict) 
{
    printf("\n--- Color Dictionary Content ---\n");

    for (int i = 0; i < PALETTE_SIZE; i++) 
    {
        Node *current = dict->buckets[i];

        if (current != NULL)
        {
            printf("Bucket [%d]: ", i);
            int count = 0;

            while (current != NULL) 
            {
                if (count > 0) 
                {
                    printf(" -> ");
                }
                printf("%s (%d,%d,%d)",
                       current->data.colorName,
                       current->data.RGBVal[0],
                       current->data.RGBVal[1],
                       current->data.RGBVal[2]);
                current = current->next;
                count++;
            }
            printf("\n");
        }
    }

    printf("--------------------------------\n");
}

void destroyDictionary(Dictionary *dict) 
{
    for (int i = 0; i < PALETTE_SIZE; i++) 
    {
        Node *current = dict->buckets[i];

        while (current != NULL) 
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
        dict->buckets[i] = NULL;
    }
}

int main() 
{
    Dictionary colorDict;
    createDictionary(&colorDict);

    Color red = {"Red", {255, 0, 0}};
    Color green = {"Green", {0, 255, 0}};
    Color blue = {"Blue", {0, 0, 255}};
    Color white = {"White", {255, 255, 255}};
    Color black = {"Black", {0, 0, 0}};
    Color darkGrey = {"Dark Grey", {10, 10, 10}};
    Color darkRed = {"Dark Red", {30, 0, 0}};

    printf("--- Inserting Colors ---\n");
    insertColor(&colorDict, red);
    insertColor(&colorDict, green);
    insertColor(&colorDict, blue);
    insertColor(&colorDict, white);
    insertColor(&colorDict, black);
    insertColor(&colorDict, darkGrey);
    insertColor(&colorDict, darkRed);

    Color lightGrey = {"Light Grey", {1, 1, 1}};
    Color slightlyRed = {"Slightly Red", {5, 0, 0}}; 

    printf("\n--- Inserting Colliding Colors ---\n");
    insertColor(&colorDict, lightGrey);
    insertColor(&colorDict, slightlyRed);

    displayDictionary(&colorDict);

    printf("\n--- Search Results ---\n");

    int searchRedRGB[3] = {255, 0, 0};
    Color *foundColor = searchColor(&colorDict, searchRedRGB);

    if (foundColor) 
    {
        printf("SUCCESS: Found Color: %s\n", foundColor->colorName);
    } 
    else 
    {
        printf("FAILURE: Color not found.\n");
    }

    int searchSlightlyRed[3] = {5, 0, 0};
    foundColor = searchColor(&colorDict, searchSlightlyRed);

    if (foundColor) 
    {
        printf("SUCCESS: Found Color: %s\n", foundColor->colorName);
    } 
    else 
    {
        printf("FAILURE: Color not found.\n");
    }

    int searchOrangeRGB[3] = {255, 165, 0}; // Hash = 54
    foundColor = searchColor(&colorDict, searchOrangeRGB);

    if (foundColor) 
    {
        printf("SUCCESS: Found Color: %s\n", foundColor->colorName);
    } 
    else 
    {
        printf("FAILURE: Color not found.\n");
    }

    destroyDictionary(&colorDict);
    return 0;
}