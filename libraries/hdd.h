#pragma once
#include <iostream>
#include <vector>
#include <float.h>
#include "section.h"
#include <exception>
#include <cmath>

enum class Type{
    GPT,
    MBR,
    None  
};
std::ostream& operator<<(std::ostream& os, const Type& type);

class hdd {
private:
    std::string firm; //производитель
    std::string model; //модель
    std::string ser; //серийный номер
    std::string tip; //тип диска
    int volume; //объем (ГБ)
    int countr; //количество разделов
    int volumer; //суммарный объем разделов (МБ)
    Type type_table; //тип таблицы разделов
    std::vector<section> section_vector;
public:
    hdd(std::string r_firm, std::string r_model, std::string r_ser, std::string r_tip, int r_volume, int r_countr, int r_volume_countr, Type r_type_table);

    std::string getFirm();
    std::string getModel();
    std::string getSer();
    std::string getTip();
    int getVolume();
    int getCountr();
    int getVolumeCountr();
    Type getTypeTable();

    int getFreespace();
    
    void createTypeTable(int volume);
    bool hasTable();

    void print();

    void addSection(section sec);
    void deleteSectionByIndex(int index);
    void printSections();
};