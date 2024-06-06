#pragma once
#include <iostream>
#include <vector>
#include <float.h>
#include "section.h"

enum class Type{
    GPT,
    MBR,
    None  
};
std::ostream& operator<<(std::ostream& os, const Type& type);

class hdd {
private:
    std::string firm;
    std::string model;
    std::string ser;
    std::string tip;
    int volume;
    int countr;
    int volumer;
    Type type_table;
    std::vector<section> section_vector;
public:
    hdd(std::string r_firm, std::string r_model, std::string r_ser, int r_tip, int r_volume, int r_countr, int r_volume_countr, Type r_type_table);

    std::string getFirm();
    std::string getModel();
    std::string getSer();
    std::string getTip();
    int getVolume();
    int getCountr();
    int getVolumeCountr();
    Type getTypeTable();
    bool SetTable(int count, int volumep);
    int getFreespace(int volumep);
    void setCreatable(Type tabler);
    bool tablerr();
    void input();
    void print();
    void addSection(section sec);
    void deleteSectionByIndex(int index);
};