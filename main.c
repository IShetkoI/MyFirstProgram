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

#define sHello(bFirstLaunch) ((bFirstLaunch) ? ("Hello, you have started the \"Hospital patient database\".\nTo get help, type \"-h\" and press \"Enter\"\n\nWhat can I do for you?") : ("\n\nWhat can I do for you?"))
#define sHelp "When you type \"-i\" I will prompt you to enter the new patient's data, viz: The patient's name, room number, and diagnosis.\n\nBy typing \"-d\" I will prompt you to enter the name of the patient to be removed from the database.\n\nIf you type \"-all\" I will display a table with all the patients in it.\n\nIf you type \"-e\" I will terminate the program."

struct patient *struct_array;
int size_array = 0;

struct patient {
    char cFullName[100];
    char cRoomNumber[100];
    char cDiagnosis[100];
};

void Help(){
    puts(sHelp);
}

void resize_array(size_t n){
    struct_array = realloc(struct_array, n * sizeof *struct_array);
}

struct patient get_data(void){
    struct patient thisdata;
    char str [100];
   // Набор символов, которые должны входить в искомый сегмент
    char sep [10]=", ";
    // Переменная, в которую будут заноситься начальные адреса частей
    // строки str
    char *istr;
    printf ("Input FIO:\n");
    getchar();
    fgets(str, 100, stdin);
    fflush(stdin);
    // Выделение первой части строки
    istr = strtok (str,sep);
    strcpy(thisdata.cFullName, istr);
    // Выделение последующих частей
    if (istr != NULL)
    {
        istr = strtok (NULL,sep);
        strcpy(thisdata.cRoomNumber, istr);
    }
    if (istr != NULL)
    {
        istr = strtok (NULL,sep);
        strcpy(thisdata.cDiagnosis, istr);
    }
    return thisdata;
}

void Increase(){
    resize_array(++size_array);
    struct_array[--size_array]=get_data();
    ++size_array;
}

void Decrease(){

}

void Output(size_t n){
    for(int i = 0; i < n; i++){
        puts(struct_array[i].cFullName);
        puts(struct_array[i].cRoomNumber);
        puts(struct_array[i].cDiagnosis);
    }
}

void All(){
    Output(size_array);
}

int Exit(){
    free(struct_array);
    exit(EXIT_SUCCESS);
}

int main() {
    char cCommand[2];
    char bFirstLaunch = 1;
    struct_array = malloc(8 * sizeof(int));
    void (*operation[5])() = {Help,  Increase, Decrease, All, Exit};
    for(;;){
        puts(sHello(bFirstLaunch));
        bFirstLaunch = 0;
        scanf("%s", cCommand);
        fflush(stdin);
        if(cCommand[0] == '-')
            switch(cCommand[1]){
                case 'h': operation[0](); break;
                case 'i': operation[1](); break;
                case 'd': operation[2](); break;
                case 'a': operation[3](); break;
                case 'e': operation[4](); break;
            }
    }
    return 0;
}
