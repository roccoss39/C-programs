#include <iostream>
#include <string>
using namespace std;

string BusStop(int Number);

int main()
{
    cout << BusStop(1) << endl;
    cout << BusStop(2) << endl;
}

string BusStop(int Number)
{
    string BusStops[] = {
        "Dworzec Glowny",
        "Plac Wolnosci",
        "Nowy Swiat",
        "Rondo Solidarnosci",
        "Park Saski",
    };
    string NextBusStop("Next Bus stop: ");
    NextBusStop += BusStops[Number - 1];
    return NextBusStop;
}
