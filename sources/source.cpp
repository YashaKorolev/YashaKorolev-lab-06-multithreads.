// Copyright 2018 Your Name <your_email>

#include <header.hpp>
#include <boost/lexical_cast.hpp>
#include <thread>
#include <ctime>
#include <boost/log/utility/setup.hpp>
#include <vector>


int main(int argc, char*argv[]) {

    srand(time(0));


    size_t t_count = std::thread::hardware_concurrency();

    if (argc > 1)
        t_count = boost::lexical_cast<size_t>(argv[1]);

    boost::log::add_file_log("../LOG.log");
    boost::log::add_console_log(std::cout);

    std::vector<std::thread> threads;
    for (size_t i = 0; i < t_count; ++i){
        threads.emplace_back(Sha256::getting_a_hash);
    }

     for (std::thread& thread : threads){
         thread.join();
     }


}