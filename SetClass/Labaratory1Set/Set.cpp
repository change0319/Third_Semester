#include <fstream>
#include<iostream>
#include"Set.hpp"
int Set::SetInt(std::string Name) {
	for (int i = 0; i < this->SizeSet; i++) {
		if (this->MainSet[i] == Name) {
			return i;
		}
	}
	return -1;
}
Set::Set(std::string FileName) {
	std::fstream F1(FileName);
	F1 >> this->SizeSet;
	this->MainSet = new std::string[this->SizeSet];
	for (int i = 0; i < this->SizeSet; i++) {
		F1 >> this->MainSet[i];
	}
	this->SetSum = new std::string * [this->SizeSet];
	for (int i = 0; i < this->SizeSet; i++) {
		this->SetSum[i] = new std::string[this->SizeSet];
		for (int j = 0; j < this->SizeSet; j++) {
			F1 >> this->SetSum[i][j];
		}
	}
	this->SetMult = new std::string * [this->SizeSet];
	for (int i = 0; i < this->SizeSet; i++) {
		this->SetMult[i] = new std::string[this->SizeSet];
		for (int j = 0; j < this->SizeSet; j++) {
			F1 >> this->SetMult[i][j];
		}
	}
	this->IsField = this->SetIsField();
	F1.close();
}
void Set::ShowSet() {
	for (int i = 0; i < this->SizeSet; i++) {
		std::cout << this->MainSet[i] << ' ';
	}
	std::cout << '\n';
}
void Set::ShowSetSum(){
	for (int i = 0; i < this->SizeSet; i++) {
		for (int j = 0; j < this->SizeSet; j++) {
			std::cout << this->SetSum[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
void Set::ShowSetMult() {
	for (int i = 0; i < this->SizeSet; i++) {
		for (int j = 0; j < this->SizeSet; j++) {
			std::cout << this->SetMult[i][j] << ' ';
		}
		std::cout << '\n';
	}
}
bool Set::SetIsField() {
	Field Ans;
	//коммутативная таблица сложения симметрична 
	for (int i = 0; i < this->SizeSet; i++) {
		for (int j = 0; j < this->SizeSet; j++) {
			if (this->SetSum[i][j] != this->SetSum[j][i]) {
				Ans.SumCom = false;
				Ans.i--;
			}
		}
	}
	//коммутативная таблица умножения симметрична
	for (int i = 0; i < this->SizeSet; i++) {
		for (int j = 0; j < this->SizeSet; j++) {
			if (this->SetMult[i][j] != this->SetMult[j][i]) {
				Ans.MultCom = false;
				Ans.i--;
			}
		}
	}
	//нулевой элемент
	for (int i = 0; i < this->SizeSet; i++) {
		Ans.SumO = true;
		for (int j = 0; j < this->SizeSet; j++) {
			if (this->SetSum[i][j] != this->MainSet[j] || this->SetSum[j][i] != this->MainSet[j]) {
				Ans.SumO = false;
			}
		}
		if (Ans.SumO == true) {
			Ans.O = this->MainSet[i];
			break;
		}
	}
	if (Ans.SumO == false) {
		Ans.i--;
	}
	//единичный элемент
	for (int i = 0; i < this->SizeSet; i++) {
		Ans.MultE = true;
		for (int j = 0; j < this->SizeSet; j++) {
			if (this->SetMult[i][j] != this->MainSet[j] || this->SetMult[j][i] != this->MainSet[j]) {
				Ans.MultE= false;
			}
		}
		if (Ans.MultE == true) {
			Ans.E = this->MainSet[i];
			break;
		}
	}
	if (Ans.MultE == false) {
		Ans.i--;
	}
	//противоположный элемент
	for (int i = 0; i < this->SizeSet; i++) {
		Ans.SumStep = false;
		for (int j = 0; j < this->SizeSet; j++) {
			if (this->SetSum[i][j] == Ans.O) {
				Ans.SumStep = true;
			}
		}
		if (Ans.SumStep == false) {
			Ans.i--;
			break;
		}
	}
	//обратный элемент
	for (int i = 0; i < this->SizeSet; i++) {
		Ans.MultStep = false;
		for (int j = 0; j < this->SizeSet; j++) {
			if (this->SetMult[i][j] == Ans.E ) {
				Ans.MultStep = true;
			}
		}
		int f1 = 1;
		for (int j = 0; j < this->SizeSet; j++) {
			if (this->SetMult[i][j] != "0") {
				f1 = 0;
				break;
			}
		}
		if (Ans.MultStep == false && f1==0) {
			Ans.i--;
			break;
		}
	}
	//ассоциативность суммы
	for (int i = 0; i < this->SizeSet; i++) {
		for (int j = 0; j < this->SizeSet; j++) {
			for (int k = 0; k < this->SizeSet; k++) {
				int I = this->SetInt(this->SetSum[i][j]);
				int I2 = this->SetInt(this->SetSum[j][k]);
				if (this->SetSum[I][k] != this->SetSum[i][I2]) {
					Ans.SumAsoc = false;
					Ans.i--;
					break;
				}
			}
			if (Ans.SumAsoc == false) { break; };
		}
		if (Ans.SumAsoc == false) { break; };
	}
	//ассоциативность умножения
	for (int i = 0; i < this->SizeSet; i++) {
		for (int j = 0; j < this->SizeSet; j++) {
			for (int k = 0; k < this->SizeSet; k++) {
				int I = this->SetInt(this->SetMult[i][j]);
				int I2 = this->SetInt(this->SetMult[j][k]);
				if (this->SetMult[I][k] != this->SetMult[i][I2]) {
					Ans.MultAsoc = false;
					Ans.i--;
					break;
				}
			}
			if (Ans.MultAsoc == false) { break; };
		}
		if (Ans.MultAsoc == false) { break; };
	}
	//дистрибутивность
	for (int i = 0; i < this->SizeSet; i++) {
		for (int j = 0; j < this->SizeSet; j++) {
			for (int k = 0; k < this->SizeSet; k++) {
				int I = this->SetInt(this->SetSum[i][j]);
				int U = this->SetInt(this->SetMult[i][k]);
				int U1 = this->SetInt(this->SetMult[j][k]);
				if (this->SetMult[I][k] != this->SetSum[U][U1]) {
					Ans.Dist = false;
					Ans.i--;
					break;
				}
			}
			if (Ans.Dist == false) { break; };
		}
		if (Ans.Dist == false) { break; };
	}
	this->Is = Ans;
	if (Ans.i == 9) {
		return true;
	}
	else {
		return false;
	}
}