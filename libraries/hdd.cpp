#include "hdd.h"
const std::string invalid_argument = "invalid argument";
const std::string out_of_range = "out of range";

std::ostream& operator<<(std::ostream& os, const Type& type){
    switch (type)
    {
    case Type::GPT:
        os << "GPT";
        break;
    
    case Type::MBR:
        os << "MBR";
        break;
    
    case Type::None:
        os << "None";
        break;
    default:
        break;
    }
    return os;
}
hdd::hdd(std::string r_firm, std::string r_model, std::string r_ser, std::string r_tip, int r_volume, int r_countr, int r_volume_countr, Type r_type_table)
{
    if(r_firm.empty()){
        r_firm = "Undefined";
    }
    firm = r_firm;
    if(r_model.empty()){
        r_model = "Undefined";
    }
    model = r_model;
    if(r_ser.empty()){
        r_ser = "Undefined";
    }
    ser = r_ser;

     if(r_tip.empty()){
        r_tip = "Undefined";
    }
    tip = r_tip;

    if(r_volume < 0 || r_volume > INT32_MAX)
        throw std::invalid_argument(invalid_argument);
    volume = r_volume;

    if(r_countr < 0 || r_countr > INT32_MAX)
        throw std::invalid_argument(invalid_argument);
    countr = r_countr;

    if(r_volume_countr < 0 || r_volume_countr > INT32_MAX)
        throw std::invalid_argument(invalid_argument);
    volumer = r_volume_countr;

    type_table = r_type_table;
    section_vector = {};
}
std::string hdd::getFirm() {
    return firm;
}
std::string hdd::getModel() {
    return model;
}
std::string hdd::getSer(){
    return ser;
}
std::string hdd::getTip() {
    return tip;
}
int hdd::getVolume() {
    return volume;
}
int hdd::getCountr() {
    return countr;
}
int hdd::getVolumeCountr() {
    return volumer;
}
Type hdd::getTypeTable() {
    return type_table;
}

int hdd::getFreespace() {
    return (volume * pow(2, 10)) - volumer;
}

void hdd::createTypeTable(int volume) {
    if(volumer + volume <= this->volume)
    {
        countr += 1;
        volumer += volume;
        return;
    }
    throw std::invalid_argument(invalid_argument);
    
}
bool hdd::hasTable() {
    return type_table == Type::None ? false : true; 
}

void hdd::print() {
    std::cout << "-------------------------------------------\n";
    std::cout << "Название фирмы: " << firm << std::endl;
    std::cout << "Название модели: "<< model << std::endl;
    std::cout << "Серия модели: " << ser << std::endl;
    std::cout << "Тип накопителя: " << tip << std::endl;
    std::cout << "Объем: " << volume << std::endl;
    std::cout << "Количество разделов: " << countr << std::endl;
    std::cout << "Объем разделов: " << volumer << std::endl;
    std::cout << "Тип таблицы разделов: " << type_table << std::endl;
    std::cout << "-------------------------------------------\n";
}
void hdd::addSection(section sec){
    if(section_vector.empty()){
        section_vector.push_back(sec);
        return;
    }
    if(section_vector.back().getFinalByte() < sec.getInitialByte())
        section_vector.push_back(sec);
    else
        throw std::invalid_argument("wrong initial byte value");
}
void hdd::deleteSectionByIndex(int index){
    if(index < 0 || index > section_vector.size())
        throw std::out_of_range(out_of_range);
    section_vector.erase(section_vector.begin() + index);
}
void hdd::printSections(){
    int i = 1;
    for(auto item : section_vector){
        std::cout << "-------------------------------------------\n";
        std::cout << "Section " << i << std::endl;
        item.print();
        std::cout << "-------------------------------------------\n";
        i++;
    }
}