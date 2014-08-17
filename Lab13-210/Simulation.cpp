
// Lab 13
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// PriorityQueueBigOh.cpp by Michael Monitto (0985765)

#include <iostream>
using namespace std;

#include <fstream>
#include <iomanip>
#include <queue>
#include <vector>
#include <algorithm>
#include <ctime> // for time()
#include <cmath>
#include <cstdlib>


//Create a struct or class to represent a customer.
struct customer
{
  int arrivalTime;  //time that the customer arrives
  int serviceTime;  //time that the customers service starts
  int completionTime;  //time that the customer service ends
  char ID;
};

//Create a struct or class to represent a service event,
//that has an overloaded operator-less-than so that events can be stored in a priority queue based on their event time.
struct ServiceEvent
{
  int serviceStartTime;  //time for the event to take place
  int serverNumber;    //server number
  bool operator<(const ServiceEvent& se) const
  {
    if(serviceStartTime < se.serviceStartTime)
      return false;
    else
      return true;
  }
};
int getRandomNumberOfServiceRequests(double);
void layOut();
int getServerIndex(bool[],int);
int getShortQueue(queue<customer>[],int);
bool isFull(queue<customer>[],int);

int main()
{
  //Opens .txt file gathers info
  //read the input values from a text file, one per line, in the order specified above
  ifstream fin;
  fin.open("simulation.txt");
  if(!fin.good()) throw "I/O error";

  int numOfServers;
  fin >> numOfServers;

  double averageArrivalRate;
  fin >> averageArrivalRate;

  int maximumLengthQueue;
  fin >> maximumLengthQueue;

  int minimumServiceTime;
  fin >> minimumServiceTime;

  int maximumServiceTime;
  fin >> maximumServiceTime;

  int newArrivalStop;
  fin >> newArrivalStop;

  fin.close();

  cout << "Lab 13" <<endl;
  cout <<"Programmer: Michael Monitto" <<endl;
  cout << "Practice in the simulation of a physical system." << endl;
  cout << "Displays a customer service simulation using priority queue." << endl;
  cout << endl;

  //displays the gathered info from the .txt file
  cout << "number of server:   " << numOfServers<< endl;
  cout << "customer arrival rate: " << averageArrivalRate << " per minute, for " << newArrivalStop << " minutes" << endl;
  cout << "maximum queue length:  " << maximumLengthQueue << endl;
  cout << "minimum service time:  " << minimumServiceTime << " minutes" << endl;
  cout << "maximum service time:  " << maximumServiceTime << " minutes" << endl;


  //declare and create and assign arrays and queues to be used in the solutions
  srand(time(0)); //new seed value to rand
  customer inQueue;
  int turnAway = 0;
  int n = 0;
  double result = 0;
  double TurnedAway = 0;

  //Using a dynamic array of queues to represent the wait queues for the servers.
  //The queues should store customer objects.
  queue<customer>* const queues = new queue<customer>[maximumLengthQueue];

  //Using an STL priority_queue to store the service events that get scheduled each time service begins.
  priority_queue<ServiceEvent> serviceEvents;

  //Use a stack, queue, list, or vector to store customer objects after service is completed.
  //It will be iterated over to determine the average time from arrival to end of service per served customer.
  vector<customer> serviceCompleted;
  vector<customer>::iterator it;

  //Create the server array as a dynamic array of customer objects to
  //represent the customers being served by each server.
  customer* server = new customer[numOfServers];

  //Include another corresponding dynamic array of boolean values, set to true if
  //the customer object at that index position is being served,
  //false otherwise, indicating that the server is idle.
  bool* beingServed = new bool[numOfServers]();
  beingServed[numOfServers] = false;
  //Use the random number generator to determine the service time when a customer starts being served,
  //and create and store a service event in the priority queue to schedule it.
  //The possible values are whole numbers between the minimum service time and maximum service time, inclusive, all equally likely.
  //If the minimum service time and maximum service time are the same, the service time is always the same.
  int r = rand(); //prime rand();
  int serviceTime = minimumServiceTime + r % (maximumServiceTime - minimumServiceTime + 1); //determine service time
  ServiceEvent event;
  event.serverNumber = 0;
  event.serviceStartTime = serviceTime;
  serviceEvents.push(event);
  for(int time = 0;;time++)
  {
    while(!serviceEvents.empty() && event.serviceStartTime == time)
    {
      event = serviceEvents.top();
      serviceEvents.pop();
      for(int i = 0; i < numOfServers; i++)
      {
        if(event.serverNumber == i && beingServed[i])
        {
          server[i].completionTime = time;
          serviceCompleted.push_back(server[i]);
          beingServed[i] = false;
        }
      }
    }
    if(time < newArrivalStop)
    {
      //get the #of of arrivals from the Poisson process (a whole number >= 0)
      int newArrival = getRandomNumberOfServiceRequests(averageArrivalRate);
      for(int i = 0; i < newArrival; i++)
      {
        customer newCustomer;
        newCustomer.arrivalTime = time;
        newCustomer.ID = (char)('A' + (n++ % 26));
        int idleServer = getServerIndex(beingServed,numOfServers);
        int shorterQueue = getShortQueue(queues,maximumLengthQueue);
        bool FULL = isFull(queues,maximumLengthQueue);
        if(idleServer == 0 && queues[idleServer].empty())
        {
          queues[idleServer].push(newCustomer);
        }
        else if(FULL)
        {
          turnAway++;
          break;
        }
        else
          queues[shorterQueue].push(newCustomer);
        }
      }
    //for idle servers move customer from wait queue and begin service
    for(int i = 0; i < numOfServers; i++)
    {
      if(!beingServed[i] && !queues[i].empty())
      {
        customer next = queues[i].front();
        queues[i].pop();
        server[i] = next;
        beingServed[i] = true;
        server[i].serviceTime = time;
        r = rand(); //prime rand();
        int completeService = minimumServiceTime + r % (maximumServiceTime - minimumServiceTime + 1); //determine service time
        event.serviceStartTime = completeService + time;
        event.serverNumber = i;
        serviceEvents.push(event);
        event = serviceEvents.top();
      }
    }
    cout << "Time: " << time << endl;
    layOut();
    for(int i = 0; i < numOfServers; i++)
    {
      if(beingServed[i] == false)
        cout << setw(2) << i << setw(8) << setw(12);
      else
        cout << setw(2) << i << setw(8) << server[i].ID << setw(12);

     for (queue<customer> cpy = queues[i]; !cpy.empty(); cpy.pop())
     {
       inQueue = cpy.front();
       cout << inQueue.ID;
     }

      cout << endl;
    }
    cout << "---------------------------" << endl;
    cout << endl;
    //summerize performance
    if(time < newArrivalStop)
    {
      for(it = serviceCompleted.begin(); it < serviceCompleted.end(); it++)
      {
        result = (it->completionTime - it->arrivalTime)/averageArrivalRate;
      }
      if(time == 0)
        TurnedAway = 0;
      else
        TurnedAway = (double)turnAway/time;
    }
    cout << "Avg time: " << setprecision(5) << result << ". ";
    cout << "Turned away per minute: " << setprecision(5) << TurnedAway << endl;
    cout << endl;
    //if user wants to quit, break out of this loop
    cout << "Press ENTER to continue, X-ENTER to quit...\n";
    if (cin.get() > 31) break;
  }

  delete[] server;
  delete[] queues;
  delete[] beingServed;
}

// requires cmath and cstdlib (and srand and rand to seed the random number generator)
int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep)
{
  int requests = 0;
  double probOfnRequests = exp(-averageRequestsPerTimeStep);
  for (double randomValue = (double)rand() / RAND_MAX;
    (randomValue -= probOfnRequests) > 0.0;
    probOfnRequests *= averageRequestsPerTimeStep / (double)++requests);
  return requests;
}
//prints the layout
void layOut()
{
  cout << "----------------------------------" << endl;
  cout << "line" << " now serving" << "    waiting queue" << endl;
  cout << "----" << " -----------" <<"   ---------------" << endl;
}
//get the servers open index
int getServerIndex(bool q[], int serverCount)
{
  int serverIndex = -1;
  for(int i = 0; i < serverCount;i++)
  {
    if(q[i] == false)
    {
      serverIndex = i;
      break;
    }
  }
  return serverIndex;
}
//gets the shortest queue
int getShortQueue(queue<customer> q[],int queueCount)
{
  int shortest = 0;
  for(int i = 1; i < queueCount; ++i)
  {
    if(q[i].size() < q[shortest].size())
    {
      shortest = i;
    }
  }
  return shortest;
}
//returns if queue is full
bool isFull(queue<customer> q[],int max)
{
  for(int i = 0; i < max; i++)
  {
    if(q[i].size() == max)
      return true;
  }
  return false;
}