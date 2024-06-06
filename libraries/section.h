#pragma once
#include <iostream>

class section{
private:
    std::string name;
    unsigned int initial_byte;
    unsigned int final_byte;
    std::string file_system_type;
    unsigned int amount_of_memory_used;
public:
    section() = delete;
    section(unsigned int initial_byte, unsigned int final_byte);
    section(std::string name ,unsigned int initial_byte, unsigned int final_byte, std::string file_system_type);
    std::string getName();
    unsigned int getInitialByte();
    unsigned int getFinalByte();
    std::string getFileSystemType();
    unsigned int getAmountOfMemoryUsed();
    void setName(std::string name_r);
    void setFileSystemType(std::string file_system_type_r);
};