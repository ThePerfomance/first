//Скорость движения ленты проката на выходе из клети фиксируется датчиком каждую секунду. 
//Все данные сохраняются в файл. 
//Определите количество резких превышений среднего значения скорости прокатки (более 5%).
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

double random(double min, double max)
{  
    return (double)(rand()) / 0x7fff * (max - min) + min;
}

int main()
{
    srand((unsigned int)time(NULL));
    setlocale(LC_ALL, "Rus");
    //fvfvjfvndjfv
    int WorkTime;
    cout << "Введите время работы датчика в секундах: ";
    cin >> WorkTime;
    ofstream fout;
    fout.open("TimeData5minute.txt");
    double MoveSpeed;
    for (int i = 0; i < WorkTime; i++)//1 
    {
        MoveSpeed = random(0,2);
        fout << MoveSpeed << endl;  
    }
    fout.close();


    ifstream fin("TimeData5minute.txt");
    float ch, SumResult = 0;
    int Count = 0, CountFinal = 0;
    while (fin >> ch)//2 2n
        Count++;
    cout << "Замеров скорости движения за 5 минут измерений : " << Count << endl;
    fin.close();

    float* mass = new float[Count];
    ifstream file("TimeData5minute.txt");
    for (int i = 0; i < Count; i++) //3 4n+2
    {
        file >> mass[i];
        SumResult= SumResult+mass[i];
    } 
    file.close();

    float AverageSpeed= SumResult / Count;// 1
    cout << "Средняя cкорость движения ленты = " << AverageSpeed << " м/с, или " << AverageSpeed * 3.6 << " км/ч."<<endl;
    for (int i = 0; i < Count; i++)//4 5n+2
    {
        if (mass[i]> AverageSpeed*1.05)
        {
            CountFinal++;
        }
    }
    cout << "Количество измерений превышающих среднюю скорость движения ленты более чем на 5% : " << CountFinal<<endl;
    int ClockWorkProgramm = clock();
    cout << "Время выполнения задачи составило " << ClockWorkProgramm << " мс"<<endl;

    system("pause");
    delete[]  mass;
    return 0;//T(n)=11n+4
}

