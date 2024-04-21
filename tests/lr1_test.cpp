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
	Doctor* d = new Doctor("doc1", false, 10);

	EXPECT_EQ(d->full_name, "doc1");
	EXPECT_EQ(d->on_vacation, false);
	EXPECT_EQ(d->energy, 10);
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
	p->name = "s";
	p->price = 10;

	EXPECT_EQ(p->name, "s");
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

	EXPECT_EQ(p->patient, pat);
	EXPECT_EQ(p->protocols, records);
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
	std::vector<MedStaff*> staff;
	staff.push_back(new MedStaff("doc1", false, 10));
	staff.push_back(new MedStaff("doc2", false, 10));

	TreatmentRoom* room = new TreatmentRoom();
	room->med_staff = staff;

	EXPECT_EQ(room->med_staff, staff);
}

TEST_F(LR2T, TestRegistry)
{
	std::vector<Procedure*> proc;
	proc.push_back(new Procedure());
	proc.push_back(new Procedure());

	std::vector<Analysis*> an;
	an.push_back(new Analysis());
	an.push_back(new Analysis());

	std::vector<Doctor*> docs;
	docs.push_back(new Doctor("doc1", false, 10));
	docs.push_back(new Doctor("doc2", false, 10));

	std::vector<std::string> complaints;
	complaints.push_back("complaint1");
	complaints.push_back("complaint2");
	Patient* pat = new Patient("p1", complaints);
	MedRecord* p = new MedRecord(pat);
	std::map<Patient*, MedRecord*> ma = std::map<Patient*, MedRecord*>();
	ma.insert(std::pair<Patient*, MedRecord*>(pat, p));

	Laboratory* lab = new Laboratory();
	TreatmentRoom* room = new TreatmentRoom();
	
	Registry* r = new Registry(room,lab,docs,ma);
	r->analyzes = an;
	r->procedures = proc;
	r->price = 10;

	EXPECT_EQ(r->t_room, room);
	EXPECT_EQ(r->lab, lab);
	EXPECT_EQ(r->doctors, docs);
	EXPECT_EQ(r->records, ma);
	EXPECT_EQ(r->procedures, proc);
	EXPECT_EQ(r->analyzes, an);
	EXPECT_EQ(r->price, 10);
}