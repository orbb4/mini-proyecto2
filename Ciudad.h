#include <string>

using namespace std;

class Ciudad
{
private:
public:
	string Country,City,AccentCity;
	int region, Population,Latitude,Longitude;

	void readCityData(string str);

	Ciudad();
	~Ciudad();
};