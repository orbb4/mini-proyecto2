#include <string>

using namespace std;

class Ciudad
{
private:
public:
	string Country,City,AccentCity, region;
	int Population,Latitude,Longitude;

	void readCityData(string str);

	Ciudad();
	~Ciudad();
};