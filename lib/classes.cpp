#include "classes.hpp"

// Patient
Patient::Patient(const std::string& full_name) :full_name(full_name){}

// MedRecord
MedRecord::MedRecord(Patient* patient) :patient(patient){}
void MedRecord::add(Protocol* protocol) {
	this->protocols.push_back(protocol);
}

// Doctor
Doctor::Doctor(const std::string& full_name, bool on_vacation, int energy):full_name(full_name),on_vacation(on_vacation),energy(energy){}
Protocol* Doctor::visit(Patient* patient, Registry* r) {
	return NULL;
}

// MedStaff
MedStaff::MedStaff(const std::string& full_name, bool on_vacation, int energy):full_name(full_name), on_vacation(on_vacation), energy(energy) {}

// TreatmentRoom
TreatmentRoom::TreatmentRoom(){}
void TreatmentRoom::perform(Patient* p, Procedure* procedure) {

}

// Laboratory
Laboratory::Laboratory(){}
void Laboratory::take_analysis(Patient* p, Analysis* a) {

}

// Registry
Registry::Registry(TreatmentRoom* t, Laboratory* lab, std::vector<Doctor*> d, std::map<Patient*, MedRecord*> map):t_room(t),lab(lab),doctors(d),records(map){}
Doctor* Registry::make_an_appointment(Patient* p) {
	Doctor* d = NULL;
	for (Doctor* s : doctors) {
		if (s->energy > 0 && s->on_vacation == false) {
			d = s;
		}
	}
	return d;
}

TreatmentRoom* Registry::make_an_appointment(Patient* p, Procedure* procedure) {
	bool one = false;
	for (MedStaff* s : t_room->med_staff) {
		if (s->energy > 0 && s->on_vacation == false) {
			one = true;
		}
	}
	if (!one)
		return NULL;

	return t_room;
}

Laboratory* Registry::make_an_appointment(Patient* p, Analysis* a) {
	bool one = false;
	for (MedStaff* s : lab->med_staff) {
		if (s->energy > 0 && s->on_vacation == false) {
			one = true;
		}
	}
	if (!one)
		return NULL;

	return lab;
}