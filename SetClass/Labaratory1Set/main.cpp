#include<iostream>
#include"Set.hpp"
int main() {
	Set set1("set.txt");
	set1.ShowSet();
	set1.ShowSetSum();
	set1.ShowSetMult();
	std::cout << set1.IsField << '\n';
	return 0;
}