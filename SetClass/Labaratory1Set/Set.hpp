#include<string>
struct Field {
	bool SumAsoc = true;
	bool MultAsoc = true;
	bool SumCom = true;
	bool MultCom = true;
	bool SumO = true;
	std::string O="0";
	bool MultE = true;
	std::string E="0";
	bool SumStep = true;
	bool MultStep = true;
	bool Dist = true;
	int i = 9;
};
class Set {
private:
	int SizeSet;
	std::string* MainSet;
	std::string** SetSum;
	std::string** SetMult;
public:
	Field Is;
	bool IsField; 
	Set() { SizeSet = 1; MainSet = new std::string[1]; SetSum = new std::string * [1]; SetSum[0] = MainSet; SetMult = SetSum; IsField = true; };
	Set(std::string FileName);
	int SetInt(std::string Name);
	std::string Sum(int OneI, int TwoI) { return SetSum[OneI][TwoI]; };
	std::string Mult(int OneI, int TwoI) { return SetMult[OneI][TwoI]; };
	void ShowSet();
	void ShowSetSum();
	void ShowSetMult();
	bool SetIsField();
};