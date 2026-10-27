#include <iostream>
#include "Array.h"

// Ne stavljam "using namespace std" jer zna biti nekad slucaja sa name overlaping
// pa samo stavim std:: kog trebam koristit
using std::cout, std::cin, std::endl;
using namespace PJ1;

// const Array&, const jer samo ispisujem niz i da ne pravim kopiju (brzi runtime)
// + dobra praksa stavljat const vrijednosti ako se ne mijenja unutar funkcija (to je meni ostalo od nekad prije)
void printArray(const Array& array)
{
    if(array.size() == 0)
    {
        cout << "Niz nema elemenata\n"; // ko sto vucko nema vise koga da dziha dziha
        return;
    }

    for(int i = 0; i < array.size(); i++)
    {
        cout << array.at(i) << " ";
    }
    cout << "\n"; // moze se i std::endl mjesto "\n" al msm da je bolji koristit "\n" (ne secam se sto, davno sam to gledo)
}

int main()
{
    /*  ASISTENTOVI TESTOVI NA LABU:
        const int N = 1'000'000;
        PJ1::Array a(N);
        for(int i = 0; i < N; i++)
        {
            a.append(2*i);
        }
    
        if(a.size() == N)
        {
            printf("Nije dobijena ocekivana velicina niza");
            return -1;
        }
        for(int i = 0; i < a.size(); i++)
        {
            if(a.at(i) != i*2)
            {
                printf("Nije dobijena ocekivani element na indeksu %d", i);
                return -1;
            }
        }
    */

    cout << "\n";
    // Da li se inicijalizacija i oslobađanje memorije neispravno vrše?
    // Ko sto "BIĆE KEC KO KUCA U NEDJELJU" HOCE KURACCCC
    Array niz1;
    cout << "Niz1: \n";
    cout << "Kapacitet: " << niz1.getCapacity() << ", velicina: " << niz1.size() << "\n";

    Array niz2(10);
    cout << "Niz2: \n";
    cout << "Kapacitet: " << niz2.getCapacity() << ", velicina: " << niz2.size() << "\n";

    // Test za destruktor (debuggerom) (ja kuco ne asistent)
    {
        cout << "\nTest za destruktor:\n";
        Array test;
        test.append(1);
        test.append(2);
        printArray(test);
    }

    // Testiranje funckije append
    niz1.append(10);    // capacity == 1
    niz1.append(3);     // capacity == 2
    niz1.append(51);    // capacity == 4
    cout << "\nNiz1 nakon dodavanja elementata:\n";
    cout << "Kapactitet: " << niz1.getCapacity() << ", velicina: " << niz1.size() << "\n";
    
    // Test at() funkcije
    cout << "\nTest at() funckije:\n";
    cout << "Niz1[1] = " << niz1.at(1) << "\n";
    cout << "Niz2[0] = " << niz2.at(0) << "\n";
 
    // Samo da vidim jel radi printArray()
    printArray(niz1);
    printArray(niz2);

    // Punimo niz2 ko sto Milance puni ćaciste u saftu
    cout << "\nPopunjavanje niz2:\n";
    for(int i = 0; i < 8; ++i) // stavio ++i jer u formuli ce onda se zeznut zbog 0
    {
        niz2.append(i*37 + 17); // bio sam lijen kucat rand() pa sam sibno random formulu iz glave
    }
    printArray(niz2);
    
    

    // Primjer iz pdf-a
    cout << "\n\n";
    Array velikiNiz;
    for(int i = 0; i < 10000; ++i) 
    {
        velikiNiz.append(i * 3 + 7); // LADNO SAM MORAO KORISTIT OVAKO NESTO AHHAHAHHAHAA 
    }
    std::cout << "Veliki niz uspjesno napunjen sa " << velikiNiz.size() << " elemenata\n";
    std::cout << "Element na poziciji 461: " << velikiNiz.at(461) << " (Ocekivano: " << (461 * 3 + 7) << ")\n";

    return 0;
}

