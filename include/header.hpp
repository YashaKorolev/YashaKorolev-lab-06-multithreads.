// Copyright 2018 Your Name <your_email>
#include "/home/absinthetoxin/CrazyOverdose/lab-06-multithreads/third-party/PicoSHA2/picosha2.h"
#include <string>
#include <iostream>
#include <thread>
#include <boost/log/trivial.hpp>

using namespace std;

class SHA256{

public:
    static void getting_a_hash() {
        for (;;) {
            string end_hash = "0000";
            string random = to_string(rand()); //случайные взодные данные
            string hash_for_random = picosha2::hash256_hex_string(random); //значение хеш-функции

            if (hash_for_random.substr(60) == end_hash) {
                BOOST_LOG_TRIVIAL(info) << "Suitable SHA256(\"" << random << "\") = \"" << hash_for_random << "\";"
                                        << endl; //сообщения журнала на консоли
            }
            else {
                BOOST_LOG_TRIVIAL(info) << "Thread ID " << this_thread::get_id() << "  UNSuitable SHA256(\"" << random
                                        << "\") = \"" << hash_for_random << "\";" << endl;
            }
        }
    }
};