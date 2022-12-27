// --------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------
// ----------------------------------- �������� ������ ----------------------------------------
// --------------------------------------------------------------------------------------------
// -------���� ����������� �������, ���������� ������� ����� ��������� �������� ������---------
// --------------------------------------------------------------------------------------------




// ����������� ����������� ���������:
#include <fstream>




// ����������� ������������ ����������� ����: 
using namespace std;




// ����������� ������ ������ ���������:
#include "structures_definition.h"
#include "constants.h"




// ���������� �������:




// �������� ���� ������ (�������� ����������� ������)
void delete_all_data(buses_linear_singly_linked_list* buses);

// �������� ���� ������ (�������� ����������� ������)
void delete_all_data(buses_linear_doubly_linked_list* buses);

// ������� ��������� ������� � �������� ����������� ������:
void delete_next_bus(bus_from_linear_singly_linked_list* bus);

// ������� ��������� ������� � �������� ����������� ������:
void delete_next_bus(bus_from_linear_doubly_linked_list* bus);

// ������� ����� �������� ������:
void clear_storage_file();

// ������� ����� �������� ������:
void clear_output_file();




// ����������� �������:




// �������� ���� ������ (�������� ����������� ������):
void delete_all_data(buses_linear_singly_linked_list* buses) {


    // ������� ����� �������� ������ (��� �������� ��):
    clear_storage_file();


    // ������� ����� �������� ������:
    clear_output_file();


    // �������� ����������-������� ��� "��������" �� ������:
    bus_from_linear_singly_linked_list* iterator_bus = buses->buses_first_bus;  // ���������� �� ������ ������ (����� ���� NULL)

    // ���� � ������ ��� �� ������ ��������, �� ������ ������� ���������:
    if (iterator_bus == NULL) return;


    // ������� ������ � ������ ��������:
    buses->buses_first_bus = NULL;


    // ���������� ��������:
    while (iterator_bus->bus_next_bus != NULL) { // ���� ��� ���� �������� ����� ������

        delete_next_bus(iterator_bus); // ������� ��������� ������� (�� ���� ������ "�����������" � ������)

    } // ����� ����� "���������� ��������"

    // ������� ���������� �������� ��������� ��������:
    iterator_bus->bus_data = NULL;

} // ����� ����� "�������� ���� ������ (�������� ����������� ������)"



// �������� ���� ������ (�������� ����������� ������):
void delete_all_data(buses_linear_doubly_linked_list* buses) {


    // ������� ����� �������� ������ (��� �������� ��):
    clear_storage_file();


    // ������� ����� �������� ������:
    clear_output_file();


    // �������� ����������-������� ��� "��������" �� ������:
    bus_from_linear_doubly_linked_list* iterator_bus = buses->buses_first_bus; // ���������� �� ������ ������ (����� ���� NULL)


    // ���� � ������ ��� �� ������ ��������, �� ������ ������� ���������:
    if (iterator_bus == NULL) return;


    // ������� ������ � ������ � ��������� ���������:
    buses->buses_first_bus = NULL;
    buses->buses_last_bus = NULL;


    // ���������� ��������:
    while (iterator_bus->bus_next_bus != NULL) { // ���� ��� ���� �������� ����� ������

        delete_next_bus(iterator_bus); // ������� ��������� ������� (�� ���� ������ "�����������" � ������)

    } // ����� ����� "���������� ��������"


    // ������� ���������� �������� ��������� ��������:
    iterator_bus->bus_data = NULL;


    // ���������� ��������� ������� ������ �� ������ � ������� ��� ����������:
    iterator_bus->bus_previous_bus = NULL;
    iterator_bus->bus_data = NULL;


} // ����� ����� "�������� ���� ������ (�������� ����������� ������)"




// ������� ��������� ������� � �������� ����������� ������:
void delete_next_bus(bus_from_linear_singly_linked_list* bus) {


    // ���������� ����������:

    bus_from_linear_singly_linked_list* tmp_bus; // �������������� �������


    // ���� ������� �������� ���, �� ������ ������:
    if (bus == NULL) return;

    
    // ���� ���������� �������� ���, �� ������ ������:
    if (bus->bus_next_bus == NULL) return;


    // ������� ������ �� ���������� ��������:
    bus->bus_next_bus->bus_data = NULL;


    // �������� ��������� �� ��������� �������:
    tmp_bus = bus->bus_next_bus->bus_next_bus;


    // ������� �� ���������� �������� ��������� �� ��������� �� ��������� �������:
    bus->bus_next_bus->bus_next_bus = NULL;


    // ������ ������ ������� ����� � tmp_bus:
    bus->bus_next_bus = tmp_bus;


} // ����� ����� "������� ��������� ������� � �������� ����������� ������"




// ������� ��������� ������� � �������� ����������� ������:
void delete_next_bus(bus_from_linear_doubly_linked_list* bus) {


    // ���������� ����������:

    bus_from_linear_doubly_linked_list* tmp_bus; // �������������� �������


    // ���� ������� �������� ���, �� ������ ������:
    if (bus == NULL) return;


    // ���� ���������� �������� ���, �� ������ ������:
    if (bus->bus_next_bus == NULL) return;


    // ������� ������ �� ���������� ��������:
    bus->bus_next_bus->bus_data = NULL;


    // �������� ��������� �� ��������� �������:
    tmp_bus = bus->bus_next_bus->bus_next_bus;


    // ������� �� ���������� �������� ��������� �� �������� ��������:
    bus->bus_next_bus->bus_next_bus = NULL;
    bus->bus_next_bus->bus_previous_bus = NULL;


    // ������ ������ ������� ����� � tmp_bus, � ����� tmp_bus ����� ������ �������:
    bus->bus_next_bus = tmp_bus;
    tmp_bus->bus_previous_bus = bus;


} // ����� ����� "������� ��������� ������� � �������� ����������� ������"




// ������� ����� �������� ������:
void clear_storage_file() {


    // ���������� ����������:

    ofstream storage_file; // ����� ������ � ����


    // ��������� ���� �������� ������ � ������ ������, ��� ����� ������ ��� ����������:
    storage_file.open(gl_bus_station_storage_file, std::ofstream::out | std::ofstream::trunc);


    // ��������� ����:
    storage_file.close();


} // ����� ����� "������� ����� �������� ������"




// ������� ����� �������� ������:
void clear_output_file() {


    // ���������� ����������:

    ofstream output_file; // ����� ������ � ����


    // ��������� ���� �������� ������ � ������ ������, ��� ����� ������ ��� ����������:
    output_file.open(gl_output_file, std::ofstream::out | std::ofstream::trunc);


    // ��������� ����:
    output_file.close();


} // ����� ����� "������� ����� �������� ������"