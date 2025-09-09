// //
// // Created by atame on 08.06.2025.
// //

 #include <iostream>
 #include <vector>
 #include <memory>
#include "../../kolej/include/typedefs.h"
#include "../../kolej/include/model/ClientManager.h"
#include "../../kolej/include/model/TrainManager.h"
#include "../../kolej/include/model/TicketManager.h"
#include "../../kolej/include/model/PassengerTrain.h"
#include "../../kolej/include/model/LargeGoodsTrain.h"
#include "../../kolej/include/model/StudentDiscount.h"
#include "../../kolej/include/model/Ticket.h"
#include "../../kolej/include/model/Route.h"
#include "../../kolej/include/model/DiscountRate.h"


using namespace std;

int main() {
   //     cout <<".";

   // Tworzenie przykładowej trasy
    RoutePtr route = make_shared<Route>("Warszawa", "Kraków", 2.5, "10 przystanków");

    // Tworzenie pociągu pasażerskiego
    TrainPtr passengerTrain = make_shared<PassengerTrain>("Pendolino", 101, 200);

    // Tworzenie dużego pociągu towarowego
    TrainPtr largeGoodsTrain = make_shared<LargeGoodsTrain>("CargoX", 102, 0, 5000, 10000);

    // Tworzenie klienta
    ClientPtr client = make_shared<Client>("Jan", "Kowalski", 123456789, 150.0);

    // Tworzenie zniżki studenckiej
    DiscountRatePtr studentDiscount = make_shared<StudentDiscount>();

    // Tworzenie harmonogramu
    vector<TrainPtr> trainSchedule = {passengerTrain, largeGoodsTrain};
    vector<RoutePtr> routeSchedule = {route};
    SchedulePtr schedule = make_shared<Schedule>("2025-06-16", "Warszawa", "Kraków", trainSchedule, routeSchedule, "06:00", "22:30");

    // Tworzenie biletu z klientem, harmonogramem i zniżką
    TicketPtr ticket = make_shared<Ticket>(*client, *schedule, *studentDiscount); // Używa referencji
    ticket->setPrice(ticket->calculatePrice());
    ticket->setTicketId(1);
    ticket->setSeatNumber(42);

    // Tworzenie menedżerów do zarządzania danymi
    TrainManager trainManager;
    trainManager.createTrain({passengerTrain, largeGoodsTrain}, {});

    TicketManager ticketManager;
    ticketManager.createTicket({ticket}, {});

    ClientManager clientManager;
    clientManager.getAllClients({client});

    // Wyświetlanie szczegółów w konsoli
    cout << "Informacje o trasie:" << endl;
    cout << route->getFirstStation() << " -> " << route->getLastStation()
         << ", czas: " << route->getDuration() << "h, liczba stacji: "
         << route->getNumberOfStations() << endl << endl;

    cout << "Informacje o pociągu pasażerskim:" << endl;
    cout << passengerTrain->getInfo() << endl << endl;

    cout << "Informacje o dużym pociągu towarowym:" << endl;
    cout << largeGoodsTrain->getInfo() << endl << endl;

    cout << "Informacje o kliencie:" << endl;
    cout << client->getInfo() << endl << endl;

    cout << "Informacje o bilecie:" << endl;
    cout << ticket->getInfo() << endl;

    cout << "Liczba pociągów w systemie: " << trainManager.countTrains() << endl;
    cout << "Liczba biletów w systemie: " << ticketManager.countTickets() << endl;

    return 0;

 }
