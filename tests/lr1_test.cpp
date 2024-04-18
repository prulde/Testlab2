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

TEST_F(LR2T, Test1)
{
	std::vector<Doctor*> vec;
	vec.push_back(new Doctor("doc1", false, 10));
	vec.push_back(new Doctor("doc2", false, 10));

	Patient* p = new Patient("ss");

	TreatmentRoom* t = new TreatmentRoom();
	Laboratory* lab = new Laboratory();


	EXPECT_EQ(p->full_name, "ss");
	//EXPECT_EQ(output.errors[0], overflow);
}