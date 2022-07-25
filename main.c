//Запили консольную программу "база данных пациентов в больнице", которая может запускаться со следующими ключами:
//          -h (--help)
//          -i (--input)
//          -d (--del)
//          -all
//1.Программа должна выводить хелп мануал содержащий краткое писание функционала при вызове с ключем -h
//2. При вызове с ключем -i программа должна предложить пользователю ввести ФИО пациена, номер палаты, диагноз, и после нажатия ввода сохранить пациаента в массиве.
//3. При вызове с ключем -d программа должна предложить ввести ФИО пациента, которого нужно удалить из базы данных.
//4. При вызове с ключем -all необходимо вывести на экран всех зарегестрированных пациентов ввиде таблицы.
//
//
//При этом работу с массивами необходимо организовать
//с использованием указателей и адресной арифметики.
//
//Для работы с перечисленными аргументами создать массив указателей на функции, которые будут вызываться в зависимости от необходимого аргумента.
//
//Данные о пациентах хранить в виде структуры.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sHello(bFirstLaunch) ((bFirstLaunch) ? ("\nHello, you have started the \"Hospital patient database\".\nTo get help, type \"-h\" and press \"Enter\"\n\nWhat can I do for you?") : ("\nWhat can I do for you?"))
#define sHelp "\nWhen you type \"-i\" I will prompt you to enter the new patient's data, viz: The patient's name, room number, and diagnosis.\n\nBy typing \"-d\" I will prompt you to enter the name of the patient to be removed from the database.\n\nIf you type \"-all\" I will display a table with all the patients in it.\n\nIf you type \"-e\" I will terminate the program."

struct patient *aPatientsDB;
int iSizeDB = 0;

struct patient {
    char *cFullName;
    char *cWardNumber;
    char *cDiagnosis;
};

/*!
Получение от пользователя через консоль строки
\param iLengthSentence Длина введенной пользователем строки
\return cSentence Строка, введенная пользователем
*/
char *getString(int *iLengthSentence) {
    *iLengthSentence = 0;
    int iCapacitySentence = 1;
    char *cSentence = (char *) malloc(sizeof(char));
    char cSymbol = getchar();

    while (cSymbol != '\n') {
        cSentence[(*iLengthSentence)++] = cSymbol;

        if (*iLengthSentence >= iCapacitySentence) {
            iCapacitySentence *= 2;
            cSentence = (char *) realloc(cSentence, iCapacitySentence *
                                                    sizeof(char));
        }

        cSymbol = getchar();
    }

    cSentence[*iLengthSentence] = '\0';

    return cSentence;
}

/*!
Выводит список команд
*/
void help() {
    puts(sHelp);
}

/*!
Изменяет размер выделяемой памяти для базы пациентов
\param n Количество элементов в массиве
*/
void resizeArray(size_t n) {
    aPatientsDB = realloc(aPatientsDB, n * sizeof *aPatientsDB);
}

/*!
Создает новый объект структуры
\return stNewPatient Данные нового пациента
*/
struct patient getData(void) {
    struct patient stNewPatient;
    stNewPatient.cFullName = (char *) malloc(sizeof(char));
    stNewPatient.cWardNumber = (char *) malloc(sizeof(char));
    stNewPatient.cDiagnosis = (char *) malloc(sizeof(char));

    printf("\nEnter the name, ward and diagnosis of the patient (name, ward, diagnosis):\n");

    int iLengthString;
    char cSeparator[10] = ", ";
    char *cPartSentence;
    char *cSentence = getString(&iLengthString);

    cPartSentence = strtok(cSentence, cSeparator);
    stNewPatient.cFullName = (char *) realloc(stNewPatient.cFullName, strlen(cPartSentence) * sizeof(char));
    strcpy(stNewPatient.cFullName, cPartSentence);

    if (cPartSentence != NULL) {
        cPartSentence = strtok(NULL, cSeparator);
        stNewPatient.cWardNumber = (char *) realloc(stNewPatient.cWardNumber, strlen(cPartSentence) * sizeof(char));
        strcpy(stNewPatient.cWardNumber, cPartSentence);
    }

    if (cPartSentence != NULL) {
        cPartSentence = strtok(NULL, cSeparator);
        stNewPatient.cDiagnosis = (char *) realloc(stNewPatient.cDiagnosis, strlen(cPartSentence) * sizeof(char));
        strcpy(stNewPatient.cDiagnosis, cPartSentence);
    }

    free(cSentence);

    return stNewPatient;
}

/*!
Добавление нового пациента в базу данных
*/
void increase() {
    resizeArray(++iSizeDB);
    aPatientsDB[--iSizeDB] = getData();
    ++iSizeDB;
}

/*!
Удаление элемента в массиве
*/
void shift(int i) {
    for (; i < iSizeDB - 1; i++) { aPatientsDB[i] = aPatientsDB[i + 1]; }
    iSizeDB--;
}

/*!
Удаляет пользователя их базы данных
*/
void decrease() {
    printf("\nEnter the name of the patient to be removed from the database:\n");
    int iLengthSentence;
    char *cSentence = getString(&iLengthSentence);
    for (int i = 0; i < iSizeDB; i++) {
        if (strcmp(cSentence, aPatientsDB[i].cFullName) == 0) {
            shift(i);
            printf("\nThe patient has been found and removed from the database\n");
            resizeArray(iSizeDB);
            break;
        }
    }
}

/*!
Выводит в виде таблицы всех пациентов
*/
void all() {
    puts("\n-------------------------------------------------------------------------");
    puts("|\t#\t|\tFCs\t|\tWard \t|\tDiagnosis\t|");
    puts("-------------------------------------------------------------------------");

    for (int i = 0; i < iSizeDB; i++) {
        printf("|\t%i\t|\t%s\t|\t%s\t|\t%s%*s\t|\n", i, aPatientsDB[i].cFullName, aPatientsDB[i].cWardNumber,
               aPatientsDB[i].cDiagnosis, 5, " ");
        puts("-------------------------------------------------------------------------");
    }
}

/*!
Завершает программу
*/
int Exit() {
    free(aPatientsDB);
    exit(EXIT_SUCCESS);
}

int main() {
    char cCommand[2];
    char bFirstLaunch = 1;
    aPatientsDB = malloc(8 * sizeof(int));
    void (*Operation[5])() = {help, increase, decrease, all, Exit};

    for (;;) {
        bFirstLaunch = 0;

        puts(sHello(bFirstLaunch));
        scanf("%s", cCommand);
        fflush(stdin);

        if (cCommand[0] == '-')
            switch (cCommand[1]) {
                case 'h':
                    Operation[0]();
                    break;
                case 'i':
                    Operation[1]();
                    break;
                case 'd':
                    Operation[2](iSizeDB);
                    break;
                case 'a':
                    Operation[3]();
                    break;
                case 'e':
                    Operation[4]();
                    break;
            }
    }
    return 0;
}
