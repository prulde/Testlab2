#include "classes.hpp"

// Patient
Patient::Patient(const std::string& full_name, std::vector<std::string> complaints) :full_name(full_name), complaints(complaints){}

// MedRecord
MedRecord::MedRecord(Patient* patient) :patient(patient){}
void MedRecord::add(Protocol* protocol) {
	this->protocols.push_back(protocol);
}

// Doctor
Doctor::Doctor(const std::string& full_name, bool on_vacation, int energy):full_name(full_name),on_vacation(on_vacation),energy(energy) {}
Protocol* Doctor::visit(Patient* patient, Registry* r) {
	Protocol* p = new Protocol();
	MedRecord* rec=r->patient_record(patient);
	p->complaints = patient->complaints;
	p->doctor = this;
	p->patient = patient;
	rec->add(p);
	return p;
}

// MedStaff
MedStaff::MedStaff(const std::string& full_name, bool on_vacation, int energy):full_name(full_name), on_vacation(on_vacation), energy(energy) {}

// Registry
Registry::Registry(TreatmentRoom* t, Laboratory* lab, std::vector<Doctor*> d, std::map<Patient*, MedRecord*> map):t_room(t),lab(lab),doctors(d),records(map){}
Doctor* Registry::make_an_appointment(Patient* p) {
	Doctor* d = NULL;
	for (Doctor* s : doctors) {
		if (s->energy > 0 && s->on_vacation == false) {
			d = s;
		}
	}
	p->card->money -= this->price;
	if (p->card->money < 0)
		return NULL;

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
	p->card->money -= procedure->price;
	if (p->card->money < 0)
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
	p->card->money -= a->price;
	if (p->card->money < 0)
		return NULL;

	return lab;
}

void Registry::add_record(Patient* patient, MedRecord* med_record) {
	this->records.insert(std::pair<Patient*, MedRecord*>(patient, med_record));
}

MedRecord* Registry::patient_record(Patient* p) {
	return records.at(p);
}