/*
 * UdpMessage.h
 *
 *  Created on: May 30, 2015
 *      Author: ubuntu
 */

#ifndef UDPMESSAGE_H_
#define UDPMESSAGE_H_
#include <vector>
#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sstream>

using namespace std;

//--------------------------------------------------
//
// this class is to represent a udpmessage with headers
// this message is going to be sent across the tcp connection
// we use this object in 2 cases
// 1- Parsing an incoming message using the constructor with
// char* input and internally this will parse the list of IPs
// and get the stripped message to be then sent internally
// 2- creating a new message when internal multicast happens
// then it adds the required headers and gets it ready to be
// sent to through the TCP connection

class UdpMessage {
public:
	UdpMessage(char*);		// used when you recieve a message through TCP
	UdpMessage();			// used to create a new udp message to be sent this call is then followed by addstripped message
	virtual ~UdpMessage();
    void AddIP(char*);		// Add my own Ip to the list
    bool MyIpExists(char*);// check if my IP exists in the message
    void AddStrippedMessage(char*, char*);
    char* GetRawMessage();	// get the char* raw message to be sent across the TCP connection
    char* GetStrippedMessage();		// get the stripped message to be sent to the local group
private:

    vector<string> IpList;
    char* RawMessage;
    char* StrippedMessage;
};



#endif /* UDPMESSAGE_H_ */
