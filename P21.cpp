# include <iostream>
# include <stdlib.h>
# include <assert.h>
# include <ctime>
/*
Collin Ward
cmw0147@auburn.edu
COMP 2710-002
project2_Ward_cmw0147

Coded in Visual Studio and Complied with Visual Studio Command Prompt and Auburn Linux Server current g++ version

*/

using namespace std;
bool aaronAlive = true;
bool bobAlive = true;
bool charlieAlive = true;
int duels = 10000;
int indexStart = 0;
int hit = 1;
int winner;
int loser;
int strat1;
int strat2;


bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
	if (A_alive == false && (B_alive == false || C_alive == false)) {
		return false;
	}
	if (B_alive == false && (A_alive == false || C_alive == false)) {
		return false;
	}
	return true;
}


void aaron_shoots1(bool B_alive, bool C_alive) {

		if (C_alive == true) {
			charlieAlive = false;
		}
		else {
			bobAlive = false;
		}
	
}
void Bob_shoots(bool A_alive, bool C_alive) {
	
		if (C_alive == true) {
			charlieAlive = false;
		}
		else {
			aaronAlive = false;
		}
	
}
void Charlie_shoots(bool A_alive, bool B_alive) {
	if (B_alive == true) {
		bobAlive = false;
	}
	else {
		aaronAlive = false;
	}

}

void aaron_shoots2(bool B_alive, bool C_alive) {
	charlieAlive = C_alive;
	bobAlive = B_alive;

}


int strategy1() {
	double aaron = 0;
	double bob = 0;
	double charlie = 0;
	double total = 0;

	for (int i = indexStart; i < 10000; i++) {
		aaronAlive = true;
		bobAlive = true;
		charlieAlive = true;
	
		while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
			int ahit = 1 + rand() % 3;
			int bhit = 1 + rand() % 2;

			if (aaronAlive == true && ahit == hit) {
				aaron_shoots1(bobAlive,charlieAlive);
			}


			if (bobAlive == true && bhit == hit) {
				Bob_shoots(aaronAlive, charlieAlive);
			}

			if (charlieAlive == true) {
				Charlie_shoots(aaronAlive,bobAlive);
			}

		}
		if (aaronAlive == true) {
			aaron++;
		}
		if (bobAlive == true) {
			bob++;
		}
		if (charlieAlive == true) {
			charlie++;
		}
		total++;

	}
	cout << "Aaron won " << aaron << "/" << duels << " duels or " << (aaron / total * 100) << "%" << "\n";
	cout << "Bob won " << bob << "/" << duels << " duels or " << (bob / total * 100) << "%" << "\n";
	cout << "Charlie won " << charlie << "/" << duels << " duels or " << (charlie / total * 100) << "%" << "\n\n";
	return aaron;
}

int strategy2() {
	double aaron = 0;
	double bob = 0;
	double charlie = 0;
	double total = 0;
	
	for (int i = indexStart; i < 10000; i++) {
		aaronAlive = true;
		bobAlive = true;
		charlieAlive = true;
		if (aaronAlive == true && bobAlive == true && charlieAlive == true) {
			int ahit = 1 + rand() % 3;
			int bhit = 1 + rand() % 2;
		

			if (bobAlive == true && bhit == hit) {
				Bob_shoots(aaronAlive, charlieAlive);
			}

			if (charlieAlive == true) {
				Charlie_shoots(aaronAlive, bobAlive);
			}


		}
		while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
			int ahit = 1 + rand() % 3;
			int bhit = 1 + rand() % 2;

			if (aaronAlive == true && ahit == hit) {
				aaron_shoots1(bobAlive, charlieAlive);
			}


			if (bobAlive == true && bhit == hit) {
				Bob_shoots(aaronAlive, charlieAlive);
			}

			if (charlieAlive == true) {
				Charlie_shoots(aaronAlive, bobAlive);
			}
		}
		
		if (aaronAlive == true) {
			aaron++;
		}
		if (bobAlive == true) {
			bob++;
		}
		if (charlieAlive == true) {
			charlie++;
		}
		total++;
	}
	cout << "Aaron won " << aaron << "/" << duels << " duels or " << (aaron / total * 100) << "%" << "\n";
	cout << "Bob won " << bob << "/" << duels << " duels or " << (bob / total * 100) << "%" << "\n";
	cout << "Charlie won " << charlie << "/" << duels << " duels or " << (charlie / total * 100) << "%" << "\n\n";
	return aaron;
}

void wastOfTime() {
	cout << "Press Enter to continue...";
	cin.ignore().get();
}


void test_at_least_two_alive(void) {
	cout << "Unit Testing 1: Function – at_least_two_alive()\n";
	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(true, true, true));
	cout << "\tCase passed ...\n";
	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\tCase passed ...\n";
	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\tCase passed ...\n";
	cout << "\tCase 4: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed ...\n";
	cout << "\tCase 5: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\tCase passed ...\n";
	cout << "\tCase 6: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\tCase passed ...\n";
	
}

void test_aaron_shoots1(void) {
	cout << "\nUnit Testing 2 Function Aaron_shoots1\n";

	cout << "\tCase 1: Bob alive, Charlie alive\n";
	aaron_shoots1(true,true);
	assert(false == charlieAlive);
	cout << "\tCase 2: Bob alive, Charlie dead\n";
	aaron_shoots1(true, false);
	assert(false == bobAlive);
	cout << "\tCase 3: Bob dead, Charlie alive\n";
	aaron_shoots1(false, true);
	assert(false == charlieAlive);
	
}

void test_aaron_shoots2(void) {
	cout << "\nUnit Testing 5: Function Aaron_shoots2\n";
		cout << "\tCase 1: Bob alive, Charlie alive\n";
	aaron_shoots2(true, true);
	assert(true == charlieAlive);
	assert(true == bobAlive);
	
	
}

void test_Bob_shoots(void) {
	cout << "\nUnit Testing 3: Function Bob_shoots\n";
	cout << "\tCase 1: Aaron alive, Charlie alive\n";
	Bob_shoots(true, true);
	assert(false == charlieAlive);
	Bob_shoots(true, false);
	cout << "\tCase 2: Aaron alive, Charlie dead\n";
	assert(false == aaronAlive);
	Bob_shoots(false, true);
	cout << "\tCase 3: Aaron dead, Charlie alive\n";
	assert(false == charlieAlive);
	
}

void test_Charlie_shoots(void) {
	cout << "\nUnit Testing 4: Function charlie_shoots\n";
	cout << "\tCase 1: Aaron alive, Bob alive\n";
	Charlie_shoots(true, true);
	assert(false == bobAlive);
	Charlie_shoots(true, false);
	cout << "\tCase 2: Aaron alive, Bob dead\n";
	assert(false == aaronAlive);
	Charlie_shoots(false, true);
	cout << "\tCase 3: Aaron dead, Bob alive\n";
	assert(false == bobAlive);
}



int main() {
	srand(time(0));
	test_at_least_two_alive();
	wastOfTime();
	test_aaron_shoots1();
	wastOfTime();
	test_Bob_shoots();
	wastOfTime();
	test_Charlie_shoots();
	wastOfTime();
	test_aaron_shoots2();
	wastOfTime();
	cout << "Ready to test strategy 1 (run " << duels << " times):\n";
	wastOfTime();
	strat1 = strategy1();
	wastOfTime();
	cout << "Ready to test strategy 2 (run " << duels << " times):\n";
	wastOfTime();
	strat2 = strategy2();

	if (strat2 > strat1) {
		winner = 2;
		loser = 1;
	}
	else {
		winner = 1;
		loser = 2;
	}
	cout << "Strategy " << winner << " is better than strategy " << loser;

	
}
