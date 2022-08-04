#include <iostream>
#include <string>
#include "yaml-cpp/yaml.h"

int main()
{
    /* load the file */
    YAML::Node config = YAML::LoadFile("../config.yaml");

    /* output */
    std::cout << "name:" << config["name"].as<std::string>() << std::endl;
    std::cout << "sex:"  << config["sex"].as<std::string>()  << std::endl;
    std::cout << "age:"  << config["age"].as<int>()          << std::endl;

    /* output by direct */
    std::cout << "output by direct ----------------------------------------------------------- " << std::endl;
    std::cout << "skills c++:"     << config["skills"]["c++"].as<int>()     << std::endl;
    std::cout << "skills java:"    << config["skills"]["java"].as<int>()    << std::endl;
    std::cout << "skills android:" << config["skills"]["android"].as<int>() << std::endl;
    std::cout << "skills python:"  << config["skills"]["python"].as<int>()  << std::endl;

    /* output by iterator */
    std::cout << "output by iterator --------------------------------------------------------- " << std::endl;
    for(YAML::const_iterator it = config["skills"].begin(); it != config["skills"].end(); it++)
    {
        std::cout << it->first.as<std::string>() << ":" << it->second.as<int>() << std::endl;
    }

    /* output after assignment */
    int skills_0 = config["skills"]["c++"].as<int>();
    int skills_1 = config["skills"]["java"].as<int>();
    int skills_2 = config["skills"]["android"].as<int>();
    int skills_3 = config["skills"]["python"].as<int>();
    std::cout << "output after assignment ---------------------------------------------------- " << std::endl;
    std::cout << "skills c++:"     << skills_0 << std::endl;
    std::cout << "skills java:"    << skills_1 << std::endl;
    std::cout << "skills android:" << skills_2 << std::endl;
    std::cout << "skills python:"  << skills_3 << std::endl;

    return 0;
}