// Nozama.cpp, Project 1b, Comp 15

// Annamira O'Toole 10/11/16

// implements the Nozama class

#include <iostream>
#include <stdexcept>

#include "Nozama.h"

using namespace std;

Nozama::Nozama(int numOfPackers, string algName, string inputFileName){
    
    clock = -1; // starts the clock with time 0

    // sets numPackers variable to number desired by client
    numPackers = numOfPackers;
    
    // depending on the algorithim desired by the client,
    // the int algorithim variable is set
    if (numPackers == 1)
        algorithim = ONE_PACKER;
    else if (algName == "FEWEST_ITEMS")
        algorithim = FEWEST_ITEMS;
    else if (algName == "SHORTEST_TIME")
        algorithim = SHORTEST_TIME;
    else if (algName == "ROUND_ROBIN")
        algorithim = ROUND_ROBIN;

    // fills Orderqueue ordersLeft variable with orders from input file
    read_file(inputFileName);

    for (int i = 0; i < numPackers; i++){
        packerTimesLeft[i] = 0;
    }

}

Nozama::~Nozama(){

}

// uses Parser to fill ordersLeft with all the orders from input file
void Nozama::read_file(string filename){;
    Parser p(filename);
    while (!p.is_done()) {
        Order order = p.read_order();
        ordersLeft.push(order);
    }
}

// the next five functions return the index of the next packer to be used
// depending on which algorithim the client requested

int Nozama::next_fewest_items(){
    int val = 0; // starting index number guess = 0
    for (int i = 0; i < numPackers; i++){
        // compares val with i
        if ((toBePacked[i].size() + (packing[i].valid ? 1 : 0))
            < toBePacked[val].size() + (packing[val].valid ? 1 : 0))
            val = i;
    }
    return val; // returns final value of val
}

int Nozama::next_shortest_time(){
    int val = 0; // starting index guess = 0
    for (int i = 0; i < numPackers; i++){
        // compares val with i
        if (packerTimesLeft[i] < packerTimesLeft[val])
            val = i;
    }
    return val; // returns final value of val
}

// does NOT change lastPackerUsed
int Nozama::next_round_robin(){
    if (lastPackerUsed == numPackers - 1)
        return 0;
    else 
        return lastPackerUsed + 1;
}

// returns 0, the index of the only packer in the array "packers"
int Nozama::next_one_packer(){
    return 0;
}

// combines all four next_ functions (previous four functions^^^)
// into one function
int Nozama::next_packer(){
    if (algorithim == FEWEST_ITEMS)
        return next_fewest_items();
    else if (algorithim == SHORTEST_TIME)
        return next_shortest_time();
    else if (algorithim == ROUND_ROBIN)
        return next_round_robin();
    else
        return next_one_packer();
}

// increments time correctly, and carries out the actions/events
// that need to happen at that new timestamp
void Nozama::increment_time(){

    // INCREMENTS TIME UP ONE FIRST

    clock++;

    // THEN SETS STAGE TO WHAT IT WILL LOOK LIKE AT THE BEGINNING OF THAT TIME

    // look at the "fetching" variable:

    // check if fetching empty (if so, pop from ordersLeft
    // (iff top Order has arrived) and DONT start fetching)
    if (!fetching.valid){
        if ((!ordersLeft.isEmpty())
            && (ordersLeft.top().arrival_timestamp <= clock)){
            fetching = ordersLeft.pop();
        }
    }

    // if fetching not empty:
    else {
         // fetching's total time = current time - arrival time
        fetching.total_time = clock - fetching.arrival_timestamp;
         // fetching's fetching time left = fetching time left - 1
        fetching.fetch_time_left--;
        
        if (fetching.fetch_time_left == 0){ // if fetching time left = 0
            
            int p = next_packer();

            // pushes fetching onto correct next toBePacked Orderqueue 
            toBePacked[p].push(fetching);
            
             // update time left for correct packer
            packerTimesLeft[p] = packerTimesLeft[p] + fetching.pack_duration;
         
            lastPackerUsed = p; // updates lastPackerUsed;

            if ((!ordersLeft.isEmpty()) 
                && (ordersLeft.top().arrival_timestamp <= clock)){
                fetching = ordersLeft.pop();
            } else {
                fetching.valid = false;
            }
        }
    }

    // look at each packer:
    for (int i = 0; i < numPackers; i++){

        // check if packer empty
        if (!packing[i].valid){
             // checks if toBePacked[i] is empty
            if (!toBePacked[i].isEmpty()){
                // if it isn't empty, pop from respective packer queue
                // and DONT start packing
                packing[i] = toBePacked[i].pop(); 
            }
        }


        // if packer not empty:
        else if (packing[i].valid){
             // that Order's total time = current time - arrival time
            packing[i].total_time = clock - packing[i].arrival_timestamp;
            // that Order's packing time left = packing time left - 1
            packing[i].pack_time_left--; 
            if (packing[i].pack_time_left == 0){ // if packing time left = 0
                print_order( packing[i] ); // print order to cout

                // update aggregate statistics!
                numOrders++;
                if (packing[i].total_time < min)
                    min = packing[i].total_time;
                if (packing[i].total_time > max)
                    max = packing[i].total_time;
                timeSum = timeSum + packing[i].total_time;

                // checks if toBePacked[i] is empty... 
                if (!toBePacked[i].isEmpty()){ 
                    // if it isn't empty, pop from respective packer queue
                    // and DONT start packing      
                    packing[i] = toBePacked[i].pop(); 
                } else {
                    packing[i].valid = false;
                }
            }
            if (packerTimesLeft[i] > 0)
                packerTimesLeft[i]--;
        }
    }

}

// prints to cout the info for an order when it leaves the warehouse
void Nozama::print_order(Order order){ 
    cout << "<Order(";
    cout << order.id; // not a string
    cout << ") arrival_timestamp = ";
    cout << order.arrival_timestamp; // not a string
    cout << " fetch_duration = ";
    cout << order.fetch_duration; // not a string
    cout << " pack_duration = ";
    cout << order.pack_duration; // not a string
    cout << " total_time = ";
    cout << order.total_time; // not a string;
    cout << ">" << endl;
}

// DELETES EVERYTHING IN ordersLeft!!!!!!!!!!
void Nozama::print_ordersLeft(){
    while (!ordersLeft.isEmpty()){
        print_order(ordersLeft.pop());
    }
}

// returns true if all packer queues are empty and packers are not packing
bool Nozama::idlePackers(){
    for (int i = 0; i < numPackers; i++){
        if (!toBePacked[i].isEmpty() || packing[i].valid)
            return false;
    }
    return true;
}

void Nozama::simulate(){
    while (!(ordersLeft.isEmpty() && !fetching.valid && idlePackers())){
        increment_time();
    }

    // print out statistics
    cout << "min elapsed time " << min << " minutes" << endl;
    cout << "max elapsed time " << max << " minutes" << endl;
    cout << "mean elapsed time " << (timeSum / numOrders);
    cout << " minutes" << endl;
    cout << numOrders << " orders processed" << endl;

    print_ordersLeft();
}

