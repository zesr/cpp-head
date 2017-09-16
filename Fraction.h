#pragma once
#ifndef iostream
#include<iostream>
#endif // !iostream


struct Fraction {
	Fraction(int const &a, int const &b) :numerator(a), denomiator(b) { init(); }
	Fraction() :numerator(0), denomiator(1) {}
	friend Fraction operator + (const Fraction &a, const Fraction &b);
	friend std::ostream& operator << (std::ostream& os, Fraction const &a);
private:
	int numerator;
	int denomiator;

	void init() {//simplification;
		int i = gcd(numerator, denomiator);
		if (i == 1)
			return;
		numerator /= i;
		denomiator /= i;
		init();
	}

	int gcd(int const &a, int const &b) {
		int c = a % b;
		if (c == 0)
			return b;
		return gcd(b, c);
	}
};

Fraction operator + (const Fraction &a, const Fraction &b) {
	return Fraction(a.numerator*b.denomiator + b.numerator*a.denomiator, a.denomiator*b.denomiator);
}

std::ostream& operator << (std::ostream& os, Fraction const &a) {
	os << a.numerator << '/' << a.denomiator;
	return os;
}