#include <stdio.h>
#include <stdbool.h>

typedef short int CompWord;

void setAnswer(CompWord* profile, int index, int value);
int getAnswer(CompWord profile, int index);
int countYesAnswers(CompWord profile);
void printAnswers(CompWord profile);
int compareProfiles(CompWord a, CompWord b);

CompWord unionProfiles(CompWord a, CompWord b);
CompWord intersectProfiles(CompWord a, CompWord b);
CompWord differenceProfiles(CompWord a, CompWord b);

// write your functions here...
void setAnswer(CompWord* profile, int index, int value)
{
    if(value == 1)
    {
        *profile |= (1 << index);
    }
    else
    {
        *profile &= ~(1 << index);
    }
}

int getAnswer(CompWord profile, int index)
{
    return (profile >> index) & 1;
}

int countYesAnswers(CompWord profile)
{
    int count = 0;
    
    for(int i = 0; i < 10; i++)
    {
        if((profile >> i) & 1)
        {
            count++;
        }
    }
    return count;
}

void printAnswers(CompWord profile)
{
    for(int i = 9; i >= 0; i--)
    {
        printf("%d", (profile >> i) & 1);
    }
    printf("\n");
}

int compareProfiles(CompWord a, CompWord b)
{
    int count = 0;
    
    for(int i = 0; i < 10; i++)
    {
        if(((a >> i) & 1) == ((b >> i) & 1))
        {
            count++;
        }
    }
    return count;
}

CompWord unionProfiles(CompWord a, CompWord b)
{
    return a | b;
}

CompWord intersectProfiles(CompWord a, CompWord b)
{
    return a & b;
}

CompWord differenceProfiles(CompWord a, CompWord b)
{
    return a & ~b;
}

int main() {
    CompWord inie = 0;
    CompWord jobo = 0;

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

	CompWord unionSet = unionProfiles(inie, jobo);
	CompWord intersectSet = intersectProfiles(inie, jobo);
	CompWord diffSet = differenceProfiles(inie, jobo);

	printf("Union:        "); printAnswers(unionSet);
	printf("Intersection: "); printAnswers(intersectSet);
	printf("Difference:   "); printAnswers(diffSet);

	return 0;
}