#include "section.h"

section::section(unsigned int initial_byte_r, unsigned int final_byte_r){
    name = "";
    initial_byte = initial_byte_r;
    final_byte = final_byte_r;
    file_system_type = "";
    amount_of_memory_used = 0;
    if(final_byte > initial_byte)
        amount_of_memory_used = final_byte - initial_byte;
}
section::section(std::string name_r, unsigned int initial_byte_r, unsigned int final_byte_r, std::string file_system_type_r){
    name = name_r;
    initial_byte = initial_byte_r;
    final_byte = final_byte_r;
    file_system_type = name_r;
    amount_of_memory_used = 0;
    if(final_byte > initial_byte)
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