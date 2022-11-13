/*
 * my_hello_world.cc
 *
 *  Created on: Nov 12, 2022
 *      Author: quantifier
 */

#include <omnetpp.h>

using namespace omnetpp; // bring omnetpp library into scope

class My_node: public cSimpleModule {
protected:
    void initialize() override;                 // called at beginning of the simulation to start the process
    void handleMessage(cMessage *msg) override; // called whenever a message arrives at the node
};

Define_Module(My_node); // register My_node with OMNeT++

void My_node::initialize() {
    if (strcmp("node2", getName()) == 0) {
        cMessage *msg = new cMessage("Hello!"); // node2 sends the first message
        send(msg, "out_gate");                  // send msg through out_gate
    }
}

void My_node::handleMessage(cMessage *msg) {
    send(msg, "out_gate");  // passes msg to out_gate
}
