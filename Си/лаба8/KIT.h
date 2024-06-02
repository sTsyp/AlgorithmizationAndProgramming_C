#pragma once
struct parameter 
{
	int weight;
	int height;
	int widht;
};

struct kit 
{
	char name[100];
	int price;
	struct  parameter character;
};

struct kit testing_vec[10] = { 
{{"name_one"}, {1}, {13, 2, 3}},
{{"name_two"}, {1}, {12, 2, 1}},
{{"name_three"}, {3}, {100, 69, 19}},
{{"name_four"}, {20}, {12, 100, 12}},
{{"name_five"}, {12}, {12, 35, 14}},
{{"name_six"}, {9}, {122, 31, 1}},
{{"name_seven"}, {7}, {12, 38, 1}},
{{"name_eight"}, {2}, {12, 69, 71}},
{{"name_nine"}, {96}, {2, 7, 11}},
{{"name_ten"}, {69}, {1, 33, 17}}};