#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <TGraphErrors.h>
#include <TF1.h>
#include <TAxis.h>
#include <TCanvas.h>

using namespace std;

void media_ponderada()
{
    // system("clear");
    scientific;
    cout.precision(4);

    Double_t c = 299792458, e = 1.60217662e-19;

    double valor[] = {0.99, 0.94, 0.81, 0.70, 0.96, 0.81};
    double incerteza[] = {0.08, 0.23, 0.14, 0.09, 0.13, 0.10};
    int n = sizeof(valor) / sizeof(valor[0]);


    double soma_media = 0, soma_peso = 0;

    for (int i=0; i < n; i++)   
    {
        soma_media += valor[i]/(incerteza[i]*incerteza[i]);
        soma_peso += 1./(incerteza[i]*incerteza[i]);
    }

    soma_media = (soma_media / soma_peso);
    cout << "\nmedia = " << soma_media << "  +-  " << 1./sqrt(soma_peso) << endl;

}