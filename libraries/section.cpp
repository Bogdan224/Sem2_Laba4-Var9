#include "section.h"
const std::string invalid_argument = "invalid argument";

section::section(unsigned int initial_byte_r, unsigned int final_byte_r){
    if(final_byte_r < initial_byte_r)
        throw std::invalid_argument("final byte > initial byte");
    name = "Undefined";
    if(initial_byte_r > UINT32_MAX)
        throw std::invalid_argument(invalid_argument);
    initial_byte = initial_byte_r;
    if(final_byte_r > UINT32_MAX)
        throw std::invalid_argument(invalid_argument);
    final_byte = final_byte_r;
    file_system_type = "Undefined";
    amount_of_memory_used = final_byte - initial_byte;
}
section::section(std::string name_r, unsigned int initial_byte_r, unsigned int final_byte_r, std::string file_system_type_r){
    if(final_byte_r < initial_byte_r)
        throw std::invalid_argument("final byte > initial byte");
    name = name_r;
    if(initial_byte_r > UINT32_MAX)
        throw std::invalid_argument(invalid_argument);
    initial_byte = initial_byte_r;
    if(final_byte_r > UINT32_MAX)
        throw std::invalid_argument(invalid_argument);
    final_byte = final_byte_r;
    file_system_type = name_r;
    amount_of_memory_used = final_byte - initial_byte;
}
std::string section::getName(){
    return name;
}
unsigned int section::getInitialByte(){
    return initial_byte;
}
unsigned int section::getFinalByte(){
    return final_byte;
}
std::string section::getFileSystemType(){
    return file_system_type;
}
unsigned int section::getAmountOfMemoryUsed(){
    return amount_of_memory_used;
}
void section::setName(std::string name_r){
    name = name_r;
}
void section::setFileSystemType(std::string file_system_type_r){
    file_system_type = file_system_type_r;
}
void section::print(){
    std::cout << "Название раздела: " << name << std::endl;
    std::cout << "Начальный Мбайт: " << initial_byte << std::endl;
    std::cout << "Конечный Мбайт: " << final_byte << std::endl;
    std::cout << "Тип файловой системы: " << file_system_type << std::endl;
    std::cout << "Объем занятой системы(МБ): " << amount_of_memory_used << std::endl;
}