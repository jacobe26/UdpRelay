/*
 * UdpRelay.h
 *
 *  Created on: May 30, 2015
 *      Author: ubuntu
 */

#ifndef UDPRELAY_H_
#define UDPRELAY_H_

#include <string>
#include "UdpMulticast.h"
#include <pthread.h>
#include "Socket.h"
#include <vector>
#include <algorithm>
#include "UdpMessage.h"
#include <map>

class UdpRelay {
public:
	UdpRelay(char*);
	virtual ~UdpRelay();
	void ParseInput(char*, char*, int*);
private:
    string get_ip(const string&, const char*);
    vector<string> string_split(const string &, const char*, bool);
    void GetIpandPortFromInput(char*,char* , int& );
};

#endif /* UDPRELAY_H_ */
