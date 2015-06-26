#!/bin/sh
g++ -pthread UdpMulticast.cpp Socket.cpp UdpRelay.cpp driver.cpp UdpMessage.cpp -std=c++11 -o UdpRelay

