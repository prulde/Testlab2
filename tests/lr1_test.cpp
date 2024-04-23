#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include <fstream>
#include <iterator>
#include <sstream>
#include <lib/classes.hpp>

// Подробнее https://google.github.io/googletest/reference/testing.html

std::vector<int> read_file(std::string path)
{
	std::vector<int> res;
	std::ifstream file_in(path);
	if (!file_in)
	{
	}
	int number;
	while (file_in >> number)
	{
		res.push_back(number);
	}
	file_in.close();

	return res;
}

class LR2T : public ::testing::Test
{

};

TEST_F(LR2T, TestPatient)
{
	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));
	docs.push_back(new Doctor("doc2", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* p = new Patient("p1", complaints);

	Protocol* pr = new Protocol();
	pr->complaints = complaints;
	p->protocol = pr;

	TreatmentRoom* t = new TreatmentRoom();
	Laboratory* lab = new Laboratory();


	EXPECT_EQ(p->full_name, "p1");
	EXPECT_EQ(p->complaints, complaints);
	EXPECT_EQ(p->protocol, pr);
	EXPECT_EQ(p->complaints, pr->complaints);
}

TEST_F(LR2T, TestDoctor)
{
	std::vector<Procedure*> proc;
	proc.push_back(new Procedure());
	proc.push_back(new Procedure());

	std::vector<Analysis*> an;
	an.push_back(new Analysis());
	an.push_back(new Analysis());

	Doctor* doc = new Doctor("doc1", false, 10);
	std::vector<Doctor*> docs;
	docs.push_back(doc);
	doc->energy = 10;


	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");
	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));

	Laboratory* lab = new Laboratory();
	TreatmentRoom* room = new TreatmentRoom();

	Registry* r = new Registry(room, lab, docs, ma);

	BankCard* bc = new BankCard();
	bc->cvc = 111;
	bc->bank = "bank";
	bc->money = 100;
	bc->number = 111222;

	pat->card = bc;

	Protocol* prot = r->make_an_appointment(pat)->visit(pat, r);

	EXPECT_EQ(doc->full_name, "doc1");
	EXPECT_EQ(doc->on_vacation, false);
	EXPECT_EQ(doc->energy, 9);
	EXPECT_EQ(prot->complaints, complaints);
}

TEST_F(LR2T, TestAnalysis)
{
	Analysis* d = new Analysis();
	d->name = "s";
	d->price = 10;

	EXPECT_EQ(d->name, "s");
	EXPECT_EQ(d->price, 10);
}

TEST_F(LR2T, TestProcedure)
{
	Procedure* p = new Procedure();
	p->name = Massage;
	p->price = 10;

	EXPECT_EQ(p->name, Massage);
	EXPECT_EQ(p->price, 10);
}

TEST_F(LR2T, TestProtocol)
{
	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	Doctor* d = new Doctor("doc1", false, 10);

	Protocol* p = new Protocol();
	p->complaints = complaints;
	p->doctor= d;
	p->patient = pat;

	EXPECT_EQ(p->complaints, complaints);
	EXPECT_EQ(p->doctor, d);
	EXPECT_EQ(p->patient, pat);
}

TEST_F(LR2T, TestMedStaff)
{
	MedStaff* p = new MedStaff("staff1",false,10);

	EXPECT_EQ(p->full_name, "staff1");
	EXPECT_EQ(p->on_vacation, false);
	EXPECT_EQ(p->energy, 10);
}

TEST_F(LR2T, TestBankCard)
{
	BankCard* p = new BankCard();
	p->cvc = 111;
	p->bank = "bank";
	p->money = 100;
	p->number = 111222;

	EXPECT_EQ(p->cvc, 111);
	EXPECT_EQ(p->bank, "bank");
	EXPECT_EQ(p->money, 100);
	EXPECT_EQ(p->number, 111222);
}

TEST_F(LR2T, TestMedicalRecord)
{
	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	std::vector<Protocol*> records;
	records.push_back(new Protocol());
	records.push_back(new Protocol());

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	p->protocols = records;

	Protocol* p1 = new Protocol();
	p1->patient = pat;


	EXPECT_EQ(p->patient, pat);
	EXPECT_EQ(p->protocols, records);

	p->add(p1);

	EXPECT_EQ(p->protocols[p->protocols.size()-1], p1);
}

TEST_F(LR2T, TestLab)
{
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	Laboratory* lab = new Laboratory();
	lab->med_staff = staff;
	
	EXPECT_EQ(lab->med_staff, staff);
}

TEST_F(LR2T, TestRoom)
{
	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	Procedure* proc1 = new Procedure();
	proc1->name = Massage;
	Procedure* proc2 = new Procedure();
	proc2->name = Injection;

	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;

	EXPECT_EQ(room->med_staff, staff);
	EXPECT_EQ(room->perform(pat,proc1), true);
	EXPECT_EQ(room->perform(pat, proc2), true);
}

TEST_F(LR2T, TestRegistry)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 100;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;
	
	Registry* r = new Registry(room,lab,docs,ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	EXPECT_EQ(r->make_an_appointment(pat)->full_name, "doc1");
	EXPECT_EQ(r->make_an_appointment(pat, proc1), room);
	EXPECT_EQ(r->make_an_appointment(pat, an1), lab);
	EXPECT_EQ(r->patient_record(pat), p);
	EXPECT_EQ(pat->card->money, 70);
	EXPECT_EQ(r->t_room, room);
	EXPECT_EQ(r->lab, lab);
	EXPECT_EQ(r->doctors, docs);
	EXPECT_EQ(r->records, ma);
	EXPECT_EQ(r->procedures, proc);
	EXPECT_EQ(r->analyzes, an);
	EXPECT_EQ(r->price, 10);
}

TEST_F(LR2T, TestCase1)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 100;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	Doctor* doc = r->make_an_appointment(pat);
	Protocol* proto = doc->visit(pat, r);
	pat->protocol = proto;

	EXPECT_EQ(doc->full_name, "doc1");
	EXPECT_EQ(r->patient_record(pat)->protocols.size(), 1);
	EXPECT_EQ(r->patient_record(pat)->protocols[0]->complaints, complaints);
	EXPECT_EQ(pat->protocol, proto);
	EXPECT_EQ(pat->card->money, 90);
}


TEST_F(LR2T, TestCase2)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 100;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	Procedure* pr1 = r->procedures[0];
	TreatmentRoom* room1 = r->make_an_appointment(pat, pr1);
	room1->perform(pat, pr1);

	EXPECT_EQ(proc1, pr1);
	EXPECT_EQ(room, room1);
	EXPECT_EQ(pat->card->money, 90);
}


TEST_F(LR2T, TestCase3)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 100;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	Analysis* a1 = r->analyzes[0];
	Laboratory* lab1= r->make_an_appointment(pat, a1);
	lab1->take_analysis(pat, a1);

	EXPECT_EQ(a1, an1);
	EXPECT_EQ(lab1, lab);
	EXPECT_EQ(pat->card->money, 90);
}

TEST_F(LR2T, TestModel1)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 100;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	EXPECT_EQ(r->make_an_appointment(pat), (Doctor*)NULL);
}

TEST_F(LR2T, TestModel2)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 9;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;


	EXPECT_EQ(r->make_an_appointment(pat), (Doctor*)NULL);
	EXPECT_EQ(pat->card->money, -1);
}

TEST_F(LR2T, TestModel3)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 100;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	Doctor* doc = r->make_an_appointment(pat);
	Protocol* proto = doc->visit(pat, r);
	pat->protocol = proto;

	EXPECT_EQ(doc->full_name, "doc1");
	EXPECT_EQ(r->patient_record(pat)->protocols.size(), 1);
	EXPECT_EQ(r->patient_record(pat)->protocols[0]->complaints, complaints);
	EXPECT_EQ(pat->protocol, proto);
	EXPECT_EQ(pat->card->money, 90);
}

TEST_F(LR2T, TestModel4)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 100;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	//staff.push_back(new MedStaff("doc1", false, 10));
	//staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	Procedure* pr1 = r->procedures[0];

	EXPECT_EQ(r->make_an_appointment(pat, pr1), (TreatmentRoom*)NULL);
}

TEST_F(LR2T, TestModel5)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 9;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	Procedure* pr1 = r->procedures[0];

	EXPECT_EQ(r->make_an_appointment(pat, pr1), (TreatmentRoom*)NULL);
	EXPECT_EQ(pat->card->money,-1);
}

TEST_F(LR2T, TestModel6)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 11;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	Procedure* pr1 = r->procedures[0];

	EXPECT_EQ(r->make_an_appointment(pat, pr1), room);
	EXPECT_EQ(pat->card->money, 1);
}

TEST_F(LR2T, TestModel7)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 100;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	//staff.push_back(new MedStaff("doc1", false, 10));
	//staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	Analysis* a1 = r->analyzes[0];

	EXPECT_EQ(r->make_an_appointment(pat,a1), (Laboratory*)NULL);;
}

TEST_F(LR2T, TestModel8)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 9;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	Analysis* a1 = r->analyzes[0];

	EXPECT_EQ(a1, an1);
	EXPECT_EQ(r->make_an_appointment(pat,a1), (Laboratory*)NULL);
	EXPECT_EQ(pat->card->money, -1);
}

TEST_F(LR2T, TestModel9)
{
	BankCard* card = new BankCard();
	card->cvc = 111;
	card->bank = "bank";
	card->money = 11;
	card->number = 111222;

	Procedure* proc1 = new Procedure();
	proc1->price = 10;
	std::vector<Procedure*> proc;
	proc.push_back(proc1);

	Analysis* an1 = new Analysis();
	an1->price = 10;
	std::vector<Analysis*> an;
	an.push_back(an1);

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");

	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));
	pat->card = card;

	Laboratory* lab = new Laboratory();
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;
	lab->med_staff = staff;

	Registry* r = new Registry(room, lab, docs, ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	Analysis* a1 = r->analyzes[0];

	EXPECT_EQ(r->make_an_appointment(pat,a1), lab);
	EXPECT_EQ(pat->card->money, 1);
}