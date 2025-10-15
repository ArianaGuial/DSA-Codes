#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char answers[10];
} BitVect;

void setAnswer(BitVect* profile, int index, int value);
int getAnswer(BitVect profile, int index);
int countYesAnswers(BitVect profile);
void printAnswers(BitVect profile);
int compareProfiles(BitVect a, BitVect b);

BitVect unionProfiles(BitVect a, BitVect b);
BitVect intersectProfiles(BitVect a, BitVect b);
BitVect differenceProfiles(BitVect a, BitVect b);

// write your funcitons here...
void setAnswer(BitVect* profile, int index, int value)
{
    if(index >= 0 && index < 10)
    {
        profile->answers[index] = value ? 1 : 0;
    }
}

int getAnswer(BitVect profile, int index)
{
    if(index >= 0 && index < 10)
    {
        return profile.answers[index];
    }
    return 0;
}

int countYesAnswers(BitVect profile)
{
    int count = 0;
    
    for(int i = 0; i < 10; i++)
    {
        if(profile.answers[i] == 1)
        {
            count++;
        }
    }
    return count;
}

void printAnswers(BitVect profile)
{
    for(int i = 9; i >= 0; i--)
    {
        printf("%d", profile.answers[i]);
    }
    printf("\n");
}

int compareProfiles(BitVect a, BitVect b)
{
    int matches = 0;
    for(int i = 0; i < 10; i++)
    {
        if(a.answers[i] == b.answers[i])
        {
            matches++;
        }
    }
    return matches;
}

BitVect unionProfiles(BitVect a, BitVect b)
{
    BitVect result = {0};
    
    for(int i = 0; i < 10; i++)
    {
        result.answers[i] = (a.answers[i] || b.answers[i]) ? 1 : 0;
    }
    
    return result;
}

BitVect intersectProfiles(BitVect a, BitVect b)
{
    BitVect result = {0};
    
    for(int i = 0; i < 10; i++)
    {
        result.answers[i] = (a.answers[i] && b.answers[i]) ? 1 : 0;
    }
    
    return result;
}

BitVect differenceProfiles(BitVect a, BitVect b)
{
    BitVect result = {0};
    
    for(int i = 0; i < 10; i++)
    {
        result.answers[i] = (a.answers[i] == 1 && b.answers[i] == 0) ? 1 : 0;
    }
    
    return result;
}

int main() {
    BitVect inie = {0};
    BitVect jobo = {0};

    setAnswer(&inie, 0, 1); // Q1: Yes
    setAnswer(&inie, 1, 1); // Q2: Yes
    setAnswer(&inie, 3, 1); // Q4: Yes
    setAnswer(&inie, 5, 1); // Q6: Yes
    setAnswer(&inie, 8, 1); // Q9: Yes
    setAnswer(&jobo, 0, 1); // Q1: Yes
    setAnswer(&jobo, 2, 1); // Q3: Yes
    setAnswer(&jobo, 4, 1); // Q5: Yes
    setAnswer(&jobo, 5, 1); // Q6: Yes
    setAnswer(&jobo, 6, 1); // Q7: Yes
    setAnswer(&jobo, 7, 1); // Q8: Yes

    printf("\nInie's answers: ");
    printAnswers(inie);

    printf("Jobo's answers: ");
    printAnswers(jobo);

    printf("\nMatching answers: %d\n", compareProfiles(inie, jobo));

    printf("Jobo answered %s to question %d\n",(getAnswer(jobo,0))?"yes":"no",1);
    printf("Jobo answered %s to question %d\n",(getAnswer(jobo,1))?"yes":"no",2);
    printf("Inie said yes to %d questions\n\n", countYesAnswers(inie));

	BitVect unionSet = unionProfiles(inie, jobo);
	BitVect intersectSet = intersectProfiles(inie, jobo);
	BitVect diffSet = differenceProfiles(inie, jobo);

	printf("Union:        "); printAnswers(unionSet);
	printf("Intersection: "); printAnswers(intersectSet);
	printf("Difference:   "); printAnswers(diffSet);

	return 0;
}