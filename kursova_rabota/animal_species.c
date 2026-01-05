#include <stdio.h>
#include <string.h>

void showCategory(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Грешка: не мога да отворя файла %s\n", filename);
        return;
    }

    char names[50][50];    
    long populations[50];   
    int count = 0;

   
    while (fscanf(file, "%49s %ld", names[count], &populations[count]) == 2) {
        count++;
    }

    fclose(file);

    
    printf("\nМоля избери животно:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }
    printf("%d. обратно\n", count + 1);

    int choice;
    printf("\nВъведи избор: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= count) {
        printf("\nВ света има приблизително %ld броя %s.\n\n",
               populations[choice - 1], names[choice - 1]);
    } else {
        printf("\nВръщане...\n\n");
    }
}
int main() {
    int choice;

    while (1) {
        printf("1. Бозайници\n");
        printf("2. Птици\n");
        printf("3. Риби\n");
        printf("4. Влечуги\n");
        printf("5. Изход\n");
        printf("Избор: ");

        scanf("%d", &choice);

        if (choice == 1) showCategory("mammals.txt");
        else if (choice == 2) showCategory("birds.txt");
        else if (choice == 3) showCategory("fish.txt");
        else if (choice == 4) showCategory("reptiles.txt");
        else if (choice == 5) {
            printf("Излизане...\n");
            break;
        }
        else {
            printf("Невалиден избор!\n\n");
        }
    }

    return 0;
}

