#include <iostream>
//#include <getDistance>

class Actor {
	unsigned short health;
	float height;
	unsigned short weight;
	unsigned short speedOfWalk;
	unsigned int time;
	float distance;
public:
	void SetHealth(unsigned short value) {
		health = value;
	}
	void SetHeight(float height) {
		this->height = height;
	}
	void SetWeight(unsigned short weight) {
		this->weight = weight;
	}
	void SetSpeedOfWalk(unsigned short speed) {
		speedOfWalk = speed;
	}
	void SetTime(unsigned int time) {
		this->time = time;
	}
	friend unsigned short getDecreaseHealth(Actor &object);
	friend void Print(Actor &object);
	unsigned int getCalcDist(Actor &object);
	unsigned short getIncreaseSpeed(Actor& object);
	Actor() = default;
};
void Print(Actor &object) {
	std::cout << "Health: " << object.health << " Speed: " << object.speedOfWalk << std::endl;
}
unsigned short getDecreaseHealth(Actor &Soldier) {
	return Soldier.health--;
}
unsigned int Actor::getCalcDist(Actor &object) {
	return object.speedOfWalk * object.time;
}
inline unsigned short Actor::getIncreaseSpeed(Actor &object) {
	return object.speedOfWalk++;
};


int main(void) {
	Actor Soldier;
	Soldier.SetHealth(100);
	Soldier.SetSpeedOfWalk(10);
	Soldier.SetTime(50);
	Print(Soldier);
	getDecreaseHealth(Soldier);
	getDecreaseHealth(Soldier);
	getDecreaseHealth(Soldier);
	getDecreaseHealth(Soldier);
	Soldier.getIncreaseSpeed(Soldier);
	Soldier.getIncreaseSpeed(Soldier);
	Soldier.getIncreaseSpeed(Soldier);
	
	std::cout << "Current health: " << getDecreaseHealth(Soldier) << std::endl;
	std::cout << "Distance: " << Soldier.getCalcDist(Soldier) << " meters" << std::endl;
	std::cout << "Speed: " << Soldier.getIncreaseSpeed(Soldier) << std::endl;
}

