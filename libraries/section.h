#pragma once
#include <iostream>
#include <exception>

class section{
private:
    std::string name; //название раздела
    unsigned int initial_byte; //начальный Мбайт
    unsigned int final_byte; //конечный Мбайт
    std::string file_system_type; //тип файловой системы
    unsigned int amount_of_memory_used; //объем занятой системы (МБ)
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
    void print();
};