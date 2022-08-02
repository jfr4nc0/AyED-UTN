#include <iostream>

using namespace std;

int main()
{
    char c;
    int cantpalabras=0, cant_a=0, cant_e=0, cant_i =0, cant_o =0, cant_u=0;
    int longpalabra=0, longmaxpalabra=0;
    /* use system call to make terminal send all keystrokes directly to stdin */
    system ("/bin/stty raw");
    c = getchar();
    while (c != '.')
    {
        switch (c)
        {
            case 'a':
                cant_a++;
                break;
            case 'e':
                cant_e++;
                break;
            case 'i':
                cant_i++;
                break;
            case 'o':
                cant_o++;
                break;
            case 'u':
                cant_u++;
                break;
            case ' ':
                cantpalabras++;
                if (longpalabra>longmaxpalabra)
                    longmaxpalabra = longpalabra;
                longpalabra = 0;
                break;
        }
        if (c!= ' ')
            longpalabra++;
        c = getchar(); //lee el siguiente caractér
    }
    if (longpalabra>longmaxpalabra)
        longmaxpalabra = longpalabra;
    /* use system call to set terminal behaviour to more normal behaviour */
    system ("/bin/stty cooked");
    cout << endl;
    cout << "Cantidad de a:" << cant_a << endl;
    cout << "Cantidad de e:" << cant_e << endl;
    cout << "Cantidad de i:" << cant_i << endl;
    cout << "Cantidad de o:" << cant_o << endl;
    cout << "Cantidad de u:" << cant_u << endl;
    cout << "La cantidad de palabras fue: " << cantpalabras+1 << endl;
    cout << "La palabra más larga tuvo: " << longmaxpalabra << " letras." << endl;
    return 0;
}