#include <iosfwd>
#include<sstream>
#include <stdarg.h>

#ifndef chocker_HPP
#define chocker_HPP

class Node
{
public:
	float* startAdress = nullptr;
	ptrdiff_t size = 0;
	ptrdiff_t allocatedMemory = 0;

	Node() = default;
	explicit Node(const ptrdiff_t length);
	Node(const Node& obj);
	Node(Node&& obj) noexcept;

	[[nodiscard]] Node& operator=(const Node& obj);
	[[nodiscard]] Node& operator=(Node&& obj) noexcept;

	float& operator[](const ptrdiff_t ind);
	const float& operator[](const ptrdiff_t ind) const;

	void Resize(const int newSize);

};


class Chocker
{
private:
	Node* startAdress = nullptr;
	ptrdiff_t size = 0;
public:
	Chocker() = default;
	explicit Chocker(const ptrdiff_t ncol, const ptrdiff_t nrow);
	Chocker(const Chocker& obj);
	Chocker(Chocker&& obj) noexcept;

	[[nodiscard]] Chocker& operator=(const Chocker& obj);
	[[nodiscard]] Chocker& operator=(Chocker&& obj) noexcept;

	float& At(const ptrdiff_t  row, const ptrdiff_t  col);
	const float& At(const ptrdiff_t  row, const ptrdiff_t  col) const;

	void Resize(const ptrdiff_t nrow);
	void Resize(const ptrdiff_t ncol, const ptrdiff_t nrow);
};

#endif // !ArrayD_HPP