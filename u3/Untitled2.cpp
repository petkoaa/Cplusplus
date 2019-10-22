#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void print(std::vector<int> const &input)
{
	std::copy(input.begin(),
			input.end(),
			std::ostream_iterator<int>(std::cout, " "));
}

int main()
{
	std::vector<int> input = { 1, 2, 3, 4, 5 };
	print(input);

	return 0;
}
