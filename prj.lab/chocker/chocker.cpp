#include <iostream>


class Node
{
private:
	float* startAdress = nullptr;
	ptrdiff_t size = 0;
	ptrdiff_t allocatedMemory = 0;
public:
	Node() = default;
	explicit Node(const ptrdiff_t length)
	{
		size = length;
		allocatedMemory = length;
		startAdress = new float[allocatedMemory];
		std::memset(startAdress, 0.0f, sizeof(float) * allocatedMemory);
	}
	Node(const Node& obj)
	{
		size = obj.size;
		allocatedMemory = obj.allocatedMemory;
		startAdress = new float[allocatedMemory];
		std::copy(startAdress, startAdress + allocatedMemory, obj.allocatedMemory);
	}
	Node(Node&& obj) noexcept
	{
		std::swap(size, obj.size);
		std::swap(allocatedMemory, obj.allocatedMemory);
		std::swap(startAdress, obj.startAdress);
	}

	[[nodiscard]] Node& operator=(const Node& obj)
	{
		size = obj.size;
		allocatedMemory = obj.allocatedMemory;
		startAdress = new float[allocatedMemory];
		std::copy(startAdress, startAdress + allocatedMemory, obj.allocatedMemory);
	}
	[[nodiscard]] Node& operator=(Node&& obj) noexcept
	{
		std::swap(size, obj.size);
		std::swap(allocatedMemory, obj.allocatedMemory);
		std::swap(startAdress, obj.startAdress);
	}

	float& operator[](const ptrdiff_t ind)
	{
		if (ind >= size || ind < 0)
		{
			throw std::out_of_range("Index out of range");
		}
		return startAdress[ind];
	}
	const float& operator[](const ptrdiff_t ind) const
	{
		if (ind >= size || ind < 0)
		{
			throw std::out_of_range("Index out of range");
		}
		return startAdress[ind];
	}

	void Resize(const int newSize)
	{
		if (size < 0)
		{
			throw std::out_of_range("Can not resize to negative length");
		}
		if (size != newSize)
		{
			if (newSize <= allocatedMemory && newSize > size)
			{
				size = newSize;
				return;
			}
			else if (newSize < size || newSize > allocatedMemory * 2)
			{
				allocatedMemory = newSize;
			}
			else
			{
				allocatedMemory *= 2;
			}
			float* newStartAdress = new float[allocatedMemory];
			std::copy(startAdress, std::min(startAdress + size, startAdress + newSize), newStartAdress);
			if (newSize > size)
			{
				std::memset(startAdress + size + 1, 0.0f, sizeof(float) * (allocatedMemory - size));
			}
			size = newSize;
			if (startAdress != nullptr)
			{
				delete(startAdress);
			}
			startAdress = newStartAdress;
		}
	}

};
class Chocker
{
private:
	Node* startAdress = nullptr;
	ptrdiff_t size = 0;
public:
	Chocker() = default;
	explicit Chocker(const ptrdiff_t ncol, const ptrdiff_t nrow)
	{
		size = nrow;
		startAdress = new Node[size];
		for (int i = 0; i < size; i++)
		{
			startAdress[i] = std::move(Node(ncol));
		}
	}
	Chocker(const Chocker& obj)
	{
		size = obj.size;
		startAdress = new Node[size];
		for (int i = 0; i < size; i++)
		{
			startAdress[i] = obj.startAdress[i];
		}
	}
	Chocker(Chocker&& obj) noexcept
	{
		std::swap(size, obj.size);
		std::swap(startAdress, obj.startAdress);
	}

	[[nodiscard]] Chocker& operator=(const Chocker& obj)
	{
		size = obj.size;
		startAdress = new Node[size];
		for (int i = 0; i < size; i++)
		{
			startAdress[i] = obj.startAdress[i];
		}
	}
	[[nodiscard]] Chocker& operator=(Chocker&& obj) noexcept
	{
		std::swap(size, obj.size);
		std::swap(startAdress, obj.startAdress);
	}

	float& At(const ptrdiff_t  row, const ptrdiff_t  col)
	{
		if (row >= size || row < 0)
		{
			throw std::out_of_range("Index out of range");
		}
		return startAdress[row][col];
	}
	const float& At(const ptrdiff_t  row, const ptrdiff_t  col) const
	{
		if (row >= size || row < 0)
		{
			throw std::out_of_range("Index out of range");
		}
		return startAdress[row][col];
	}

	void Resize(const ptrdiff_t ncol, const ptrdiff_t nrow)
	{
		if (ncol < 0 || nrow < 0)
		{
			throw std::out_of_range("Can not resize to negative length");
		}
		if (size != nrow)
		{

			Node* newStartAdress = new Node[nrow];
			for (int i = 0; i < std::min(size, nrow); i++)
			{
				startAdress[i].Resize(ncol);
				newStartAdress[i] = std::move(startAdress[i]);
			}
			for (int i = size; i < nrow; i++)
			{
				newStartAdress[i] = Node(ncol);
			}
			startAdress = newStartAdress;
		}
	}
};

int main()
{

}