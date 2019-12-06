//Copyright 2019 CrazyOverdose

#ifndef  INCLUDE_HEADER_HPP_
#define  INCLUDE_HEADER_HPP_

#include "picosha2.hpp"
#include <string>
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <random>
#include <ctime>
#include <boost/log/trivial.hpp>

class Sha256 {
public:
    static void getting_a_hash() {
        while (true) {
            const std::string end_hash = "0000";
            //случайные взодные данные
            std::mt19937 gener(time(0));
            //gener.seed(time(0));
            std::string random = std::to_string(gener());

            //значение хеш-функции
            if (picosha2::hash256_hex_string(random).substr(60) == end_hash) {
                //сообщения журнала на консоли
                BOOST_LOG_TRIVIAL(info) << "Suitable Sha256(\"" 
                    << random << "\") = \""
                                        << picosha2::hash256_hex_string(random) <<
                    "\";" << std::endl;
            } else {
                BOOST_LOG_TRIVIAL(info) << "Thread ID " <<
                    std::this_thread::get_id() << "  UNSuitable Sha256(\""
                                        << random << ") = \"" <<
                    picosha2::hash256_hex_string(random) << ";"
                                        << std::endl;
            }

        }
    }
};

#endif // INCLUDE_HEADER_HPP_
