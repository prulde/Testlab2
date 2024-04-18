#pragma once

#include <string>
#include <vector>
#include <map>

struct Procedure {
	std::string name;
};

struct Analysis {
	std::string name;
};

class Doctor;
class Registry;

class Patient
{
public:
	std::string full_name;
	std::vector<std::string> complaints;

	Patient(const std::string &name);
};

struct Protocol
{
	std::vector<std::string> complaints;
	Doctor *doctor;
	Patient *patient;
};

class MedRecord
{
private:
	Patient* patient;
	std::vector<Protocol*> protocols;

public:
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
	int energy=10;

	MedStaff(const std::string& full_name, bool on_vacation, int energy);
};

class TreatmentRoom {
public:
	std::vector<MedStaff*> med_staff;

	TreatmentRoom();
	void perform(Patient* patient, Procedure* procedure);
};

class Laboratory {
public:
	std::vector<MedStaff*> med_staff;

	Laboratory();
	void take_analysis(Patient* patient, Analysis* analysis);
};

class Registry {
private:
	std::map<Patient*, MedRecord*> records;

	std::vector<Doctor*> doctors;

	TreatmentRoom* t_room;
	Laboratory* lab;

public:
	std::vector<Procedure*> procedures;
	std::vector<Analysis*> analyzes;


	Registry(TreatmentRoom* t, Laboratory* lab, std::vector<Doctor*> d, std::map<Patient*, MedRecord*> map);
	Doctor* make_an_appointment(Patient* p);
	TreatmentRoom* make_an_appointment(Patient* p, Procedure* d);
	Laboratory* make_an_appointment(Patient* p, Analysis* d);
	MedRecord patient_record(Patient* patient);
};