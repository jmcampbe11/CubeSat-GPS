#ifndef LORIS_GPS
#define LORIS_GPS

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstring>
#include <vector>
#include "minmea.h"
#include <fstream>
#include <sstream>
#include "GPSMessageInterface.hpp"


//Gathered from https://github.com/AndrewWay/cubesat/tree/develop on July 11th, 2019
#include "Message.h"
#include "MessageBuilder.h"
//#include "MessageSenderInterface.h"
#include <fstream>
#define INDENT_SPACES "  "

#include "SanityCheck.h" // Only needed for testing

using namespace std;

bool gpsOn = false;

int main(int argc, char *argv[]);
int gps_loop();
void test();
bool init_gps();
bool poll(string *message);
void decode(string raw);
string toStringTime(struct gps_time *time);
unsigned int encode_time_as_int(struct minmea_time *time);

#endif

#ifndef CURRENT_TIME
#define CURRENT_TIME chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count()
#endif