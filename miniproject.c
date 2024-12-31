#include <stdio.h>
#include <string.h>
#define MAX_PATIENTS 100
struct Patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};
struct Patient patients[MAX_PATIENTS];
int patientCount = 0;
void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Cannot add more patients, memory full.\n");
        return;
    }
    struct Patient newPatient;
    printf("Enter Patient ID: ");
    scanf("%d", &newPatient.id);
    getchar(); 
    printf("Enter Patient Name: ");
    fgets(newPatient.name, 50, stdin);
    newPatient.name[strcspn(newPatient.name, "\n")] = '\0'; 
    printf("Enter Patient Age: ");
    scanf("%d", &newPatient.age);
    getchar(); 
    printf("Enter Disease: ");
    fgets(newPatient.disease, 50, stdin);
    newPatient.disease[strcspn(newPatient.disease, "\n")] = '\0'; 
    patients[patientCount++] = newPatient;
    printf("Patient added successfully.\n");
}
void displayPatients() {
    if (patientCount == 0) {
        printf("No patients available.\n");
        return;
    }

    printf("List of Patients:\n");
    for (int i = 0; i < patientCount; i++) {
        printf("\nPatient ID: %d\n", patients[i].id);
        printf("Name: %s\n", patients[i].name);
        printf("Age: %d\n", patients[i].age);
        printf("Disease: %s\n", patients[i].disease);
    }
}
void updatePatient() {
    int id, found = 0;
    printf("Enter Patient ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            found = 1;
            getchar();
            printf("Enter new Patient Name: ");
            fgets(patients[i].name, 50, stdin);
            patients[i].name[strcspn(patients[i].name, "\n")] = '\0';
            printf("Enter new Patient Age: ");
            scanf("%d", &patients[i].age);
            getchar(); 
            printf("Enter new Disease: ");
            fgets(patients[i].disease, 50, stdin);
            patients[i].disease[strcspn(patients[i].disease, "\n")] = '\0';
            printf("Patient record updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Patient not found.\n");
    }
}
void deletePatient() {
    int id, found = 0;
    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            found = 1;
            for (int j = i; j < patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            patientCount--;
            printf("Patient record deleted successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Patient not found.\n");
    }
}
void searchPatient() {
    int id, found = 0;
    printf("Enter Patient ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < patientCount; i++) {
        if (patients[i].id == id) {
            found = 1;
            printf("\nPatient ID: %d\n", patients[i].id);
            printf("Name: %s\n", patients[i].name);
            printf("Age: %d\n", patients[i].age);
            printf("Disease: %s\n", patients[i].disease);
            break;
        }
    }

    if (!found) {
        printf("Patient not found.\n");
    }
int main() {
    int choice;
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Update Patient\n");
        printf("4. Delete Patient\n");
        printf("5. Search Patient\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                updatePatient();
                break;
            case 4:
                deletePatient();
                break;
            case 5:
                searchPatient();
                break;
            case 6:
                printf("Exiting system...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}