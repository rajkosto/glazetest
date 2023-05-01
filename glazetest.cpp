#include <string>
#include <iostream>
#include <glaze/core/write.hpp>
#include <glaze/json/write.hpp>

struct StructOne
{
	int status = 0;
	struct glaze 
	{
		using T = StructOne;
		static constexpr auto value = glz::object("status",&T::status);
	};
};


struct StructTwo
{
	std::string status;
	struct glaze 
	{
		using T = StructTwo;
		static constexpr auto value = glz::object("status",&T::status);
	};
};

template<typename ObjectType>
inline std::string ObjectToString(const ObjectType& obj)
{
	std::string buf;
	glz::write_json(obj,buf);
	return buf;
}

int main()
{
	StructOne resp1;
	std::cout << ObjectToString(resp1) << '\n';
	StructTwo resp2;
	std::cout << ObjectToString(resp2) << '\n';
    return 0;
}
