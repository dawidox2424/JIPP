#include <iostream>
#include <thread>
#include <windows.h>
#include <mutex>

using namespace std;



void jedzenie(int x,mutex widelce[])
{
    printf("Filozof nr %d mysli \n",x);

    widelce[x].lock();
    widelce[(x + 1) % 5].lock();

    printf("Filozof nr %d zabral widelce \n",x);

    printf("Filozof nr %d je! \n",x);


    widelce[x].unlock();
    widelce[(x + 1) % 5].unlock();

    printf("Filozof nr %d upuszcza widelce \n",x);
}


int main()
{
    thread filozof[5];

    mutex widelce[5];

    for(int i = 0; i<5; i++)
    {
        filozof[i] = thread(jedzenie, i, widelce);
    }

    for(int i = 0; i<5; i++)
    {
        filozof[i].join();
    }
}


