> Богдан:
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Spec { ФТІ, ТН, МТЕ, КН, ІНФ };
string specStr[] = { "ФТІ", "ТН", "МТЕ", "КН", "ІНФ" };

struct Student
{
    string prizv;
    double physics;
    double math;
    double kurs;
    double Average;
    Spec spec;
    union
    {
        unsigned prog;
        unsigned chuslo;
        unsigned ped;
    };
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Sort(Student* p, const int N);
int* IndexSort(Student* p, const int N);
void PrintIndexSorted(Student* p, int* I, const int N);
//int BinSearch(Student* p, const int N, const string prizv, const Spec spec, const int avgGrade);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "Введіть кількість студентів N: "; cin >> N;
    Student* p = new Student[N];
    double proc;
    int ispec;
    Spec spec;
    string prizv;
    int physics;
    int matem;
    int inform;
    int found;
    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - фізичне впорядкування даних" << endl;
        cout << " [4] - бінарний пошук працівника за посадою та прізвищем" << endl << endl;
        cout << " [5] - індексне впорядкування та вивід даних"
            << endl << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;

        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl << endl << endl;
        switch (menuItem)
        {
        case 1:
            Create(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            Sort(p, N);
            break;
        case 4:
            //cout << Output_Bin_Search(p, N);

            break;
        case 5:
            PrintIndexSorted(p, IndexSort(p, N), N);
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);
    return 0;
}

void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " прізвище: "; getline(cin, p[i].prizv);
        cout << " курс: "; cin >> p[i].kurs;
        cout << " спеціальність (ФТІ - 0, ТН - 1, МТЕ - 2, КН - 3, ІНФ - 4): ";
        cin >> spec;
        p[i].spec = (Spec)spec;
        cout << " оцінка з фізики: "; cin >> p[i].physics;
        cout << " оцінка з математики: "; cin >> p[i].math;
        switch (p[i].spec)
        {
        case КН:
            cout << " оцінка з програмування: "; cin >> p[i].prog;
            break;
        case ІНФ:
            cout << " оцінка з чисельних методів: "; cin >> p[i].chuslo;
            break;
        case МТЕ:
        case ФТІ:
        case ТН:
            cout << " оцінка з педагогіки: "; cin >> p[i].ped;
            break;
        }
        p[i].Average = (p[i].physics + p[i].math + p[i].prog) / 3.;
        cout << endl;
    }
}

void Print(Student* p, const int N)
{
    cout << "==============================================================================================================="
        << endl;
    cout << "|  № |   прізвище   |  курс |  спец. |  фіз. |  мат. |  прог. | числ. |  педг. |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(13) << right << p[i].prizv
            << "| " << setw(5) << right << p[i].kurs << " "
            << "| " << setw(7) << right << specStr[p[i].spec]
            << "| " << setw(5) << right << p[i].physics << " "
            << "| " << setw(5) << right << p[i].math << " ";

    > Богдан:
    switch (p[i].spec)
    {
    case КН:
        cout << "| " << setw(6) << right << p[i].prog << " " << "| " << setw(8) << "| " << setw(8);
        break;
    case ІНФ:
        cout << "| " << setw(9) << "| " << setw(5) << right << p[i].chuslo << " " << "| " << setw(8);
        break;
    case МТЕ:
    case ФТІ:
    case ТН:
        cout << "| " << setw(9) << "| " << setw(8) << "| " << setw(6) << right << p[i].ped << " ";
        break;
    }
    cout << "|"
        << endl;
    }
    cout << "==============================================================================================================="
        << endl;
    cout << endl;
}


void Sort(Student* p, const int N)
{
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((p[i1].Average < p[i1 + 1].Average)
                ((p[i1].Average < p[i1 + 1].Average) && p[i1].spec < p[i1 + 1].spec)
                ((p[i1].Average < p[i1 + 1].Average) && p[i1].spec == p[i1 + 1].spec && p[i1].prizv < p[i1 + 1].prizv))
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
}

int* IndexSort(Student* p, const int N) {
    int* I = new int[N];
    for (int i = 0; i < N; i++)
        I[i] = i;

    int i, i1, value;
    for (i = 1; i < N; i++) {
        value = I[i];
        for (i1 = i - 1; i1 >= 0 &&
            ((p[i1].Average < p[i1 + 1].Average)
                ((p[i1].Average < p[i1 + 1].Average) && p[i1].spec < p[i1 + 1].spec)
                ((p[i1].Average < p[i1 + 1].Average) && p[i1].spec == p[i1 + 1].spec && p[i1].prizv < p[i1 + 1].prizv)); i1--) {
            I[i1 + 1] = I[i1];
        }
        I[i1 + 1] = value;
    }
    return I;
}

void PrintIndexSorted(Student* p, int* I, const int N)
{
    cout << "==============================================================================================================="
        << endl;
    cout << "|  № |   прізвище   |  курс |  спец. |  фіз. |  мат. |  прог. | числ. |  педг. |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << I[i] + 1 << " ";
        cout << "| " << setw(13) << right << p[I[i]].prizv
            << "| " << setw(5) << right << p[I[i]].kurs << " "
            << "| " << setw(7) << right << specStr[p[I[i]].spec]
            << "| " << setw(5) << right << p[I[i]].physics << " "
            << "| " << setw(5) << right << p[I[i]].math << " ";

        switch (p[I[i]].spec)
        {
        case КН:
            cout << "| " << setw(6) << right << p[I[i]].prog << " " << "| " << setw(8) << "| " << setw(8);
            break;
        case ІНФ:
            cout << "| " << setw(9) << "| " << setw(5) << right << p[I[i]].chuslo << " " << "| " << setw(8);
            break;
        case МТЕ:
        case ФТІ:
        case ТН:
            cout << "| " << setw(9) << "| " << setw(8) << "| " << setw(6) << right << p[I[i]].ped << " ";
            break;
        }
        cout << "|"
            << endl;
    }
    cout << "==============================================================================================================="
        << endl;
    cout << endl;
}
