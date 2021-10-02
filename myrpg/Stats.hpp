#ifndef Stats_hpp
#define Stats_hpp

class Stats
{


private:

    int strength;
    int skill;
    bool alive;

public:

	int getstrength();
	int getskill();
	bool isalive();


	void setstrength(int i);
	void killed();
	void setalive();

	void print();


	Stats(int st, int sk, bool a);


};

#endif /* Stats_hpp */
