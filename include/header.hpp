//Copyright 2019 CrazyOverdose

#ifndef  INCLUDE_HEADER_HPP_
#define  INCLUDE_HEADER_HPP_
#include "/home/absinthetoxin/CrazyOverdose/lab-06-multithreads/third-party/PicoSHA2/picosha2.h"
#include <string>
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <boost/log/trivial.hpp>

class SHA256{
public:
    static void getting_a_hash() {
        for (;;) {
            std::string end_hash = "0000";
            //случайные взодные данные
std::string random = std::to_string(rand());
            //значение хеш-функции
std::string hash_for_random = picosha2::hash256_hex_string(random);

            if (hash_for_random.substr(60) == end_hash) {
                //сообщения журнала на консоли
                BOOST_LOG_TRIVIAL(info) << "Suitable SHA256(\"" << random
 << "\") = \"" << hash_for_random << "\";"
<< std::endl;} else {
                BOOST_LOG_TRIVIAL(info) << "Thread ID "
  << std::this_thread::get_id() << "  UNSuitable SHA256(\"" << random
 << "\") = \"" << hash_for_random << "\";" << std::endl; }
        }
    }
};
#endif // INCLUDE_HEADER_HPP_
