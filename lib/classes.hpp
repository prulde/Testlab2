#pragma once

#include <string>
#include <vector>
#include <map>

struct BankCard
{
	int cvc;
	int money;
	std::string bank;
	int number;
};

enum ProcedureType {
	Injection = 1,
	Massage = 2
};

struct Procedure {
	ProcedureType name;
	int price;
};

struct Analysis {
	std::string name;
	int price;
};

class Doctor;
class Registry;
class Protocol;

class Patient
{
public:
	std::string full_name;
	std::vector<std::string> complaints;
	Protocol* protocol;
	BankCard* card;

	Patient(const std::string &name, std::vector<std::string> complaints);
	bool pay(int price);
};

struct Protocol
{
	std::vector<std::string> complaints;
	Doctor *doctor;
	Patient *patient;
};

class MedRecord
{
public:
	Patient* patient;
	std::vector<Protocol*> protocols;

	MedRecord(Patient* patient);
	void add(Protocol* protocol);
};

class Doctor
{
public:
	std::string full_name;
	bool on_vacation;
	int energy;

	Doctor(const std::string& full_name, bool on_vacation, int energy);
	Protocol* visit(Patient* patient, Registry* r);
};

class MedStaff
{
public:
	std::string full_name;
	bool on_vacation=false;
	int energy;

	MedStaff(const std::string& full_name, bool on_vacation, int energy);
	void massage(Patient* p) {};
	void injection(Patient* p) {};
};

class TreatmentRoom {
public:
	std::vector<MedStaff*> med_staff;

	TreatmentRoom() = default;
	bool perform(Patient* patient, Procedure* procedure);
};

class Laboratory {
public:
	std::vector<MedStaff*> med_staff;

	Laboratory() = default;
	void take_analysis(Patient* patient, Analysis* analysis) {};
};

class Registry {
public:
	std::map<Patient*, MedRecord*> records = std::map<Patient*, MedRecord*>();

	std::vector<Doctor*> doctors;

	int price = 10;
	TreatmentRoom* t_room;
	Laboratory* lab;

	std::vector<Procedure*> procedures;
	std::vector<Analysis*> analyzes;


	Registry(TreatmentRoom* t, Laboratory* lab, std::vector<Doctor*> d, std::map<Patient*, MedRecord*> map);
	Doctor* make_an_appointment(Patient* p);
	TreatmentRoom* make_an_appointment(Patient* p, Procedure* d);
	Laboratory* make_an_appointment(Patient* p, Analysis* d);
	MedRecord* patient_record(Patient* patient);
	void add_record(Patient* patient, MedRecord* med_record);
};