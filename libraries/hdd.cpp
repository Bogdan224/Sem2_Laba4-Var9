#include "hdd.h"



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
hdd::hdd(std::string r_firm, std::string r_model, std::string r_ser, int r_tip, int r_volume, int r_countr, int r_volume_countr, Type r_type_table)
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
    tip = r_tip;
    volume = r_volume;
    countr = r_countr;
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
bool hdd::SetTable(int count, int volumep) {
    count = countr;
    volumep = volumer;
    if (count == 1 && volumep == 0){
        return false;
    if (count == 0 && volumep == 1)
        return false;
        }
    return true;
}

int hdd::getFreespace(int volumep) {
    return volume - volumep;
}
void hdd::setCreatable(Type tabler) {
    type_table = tabler;
}
bool hdd::tablerr() {
    if (type_table == Type::None)
       return false;
    else
        return true;
}
void hdd::print() {
    std::cout << "Название фирмы:" << firm << std::endl;
    std::cout << "Название модели: "<< model << std::endl;
    std::cout << "Серия модели:" << ser << std::endl;
    std::cout << "Тип накопителя" << tip << std::endl;
    std::cout << "Объем" << volume << std::endl;
    std::cout << "Количество разделов" << countr << std::endl;
    std::cout << "Объем разделов" << volumer << std::endl;
    std::cout << "Тип таблицы разделов" << type_table << std::endl;
}
void hdd::addSection(section sec){
    if(section_vector.back().getFinalByte() < sec.getInitialByte())
        section_vector.push_back(sec);
}
void hdd::deleteSectionByIndex(int index){
    if(index < 0 || index > section_vector.size())
        return;
    section_vector.erase(section_vector.begin() + index);
}