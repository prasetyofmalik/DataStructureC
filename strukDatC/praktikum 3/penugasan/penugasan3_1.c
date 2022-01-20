#include <stdio.h>

// Declaration of the structure candidate
struct candidate {
    int roll_no;
    char grade;
    // Array within the structure
    float marks[4];
};

// Function to displays the content of
// the structure variables
void displayRoll(struct candidate a[3]) { // array of structures
    int i, lent = 3;

    for(i=0; i<lent; i++){
        printf("Roll number : %d\n", a[i].roll_no);
        printf("Grade : %c\n", a[i].grade);
        printf("Marks secured:\n");
        int j;
        int len = sizeof(a[i].marks) / sizeof(float);

        // Accessing the contents of the
        // array within the structure
        for (j=0; j<len; j++) {
            printf("Subject %d : %.2f\n", j + 1, a[i].marks[j]);
        }
        printf("\n");
    }
}

// Driver Code
int pen3_1() {
    // Initialize a structure
    struct candidate a[3]
    = { {1, 'A', { 98, 77, 89, 90 }},
        {2, 'B', { 70, 70, 70, 70 }},
        {3, 'C', { 50, 50, 50, 50 }} };

    // Function to display structure
    displayRoll(a);
    return 0;
}
