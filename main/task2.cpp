#include <iostream>

class LegacyInt
{
private:
	int num_ {};

public:
	LegacyInt(int num) : num_(num) {}

	bool operator==(const LegacyInt& other) const
	{
		return num_ == other.num_;
	}

	bool operator<(const LegacyInt& other) const
	{
		return num_ < other.num_;
	}

	bool operator>(const LegacyInt& other) const
	{
		return num_ > other.num_;
	}

};

class ModernInt
{
private:
	int num_ {};

public:
	ModernInt(int num) : num_(num) {}

	auto operator<=>(const ModernInt& other) const = default;
};


int main()
{
    LegacyInt a(10), b(20);
    ModernInt c(10), d(20);

    std::cout << (a == b) << '\n';
    std::cout << (a < b) << '\n';
    std::cout << (a > b) << '\n';

    std::cout << (c == d) << '\n';
    std::cout << (c < d) << '\n';
    std::cout << (c > d) << '\n';

    return 0;
}
