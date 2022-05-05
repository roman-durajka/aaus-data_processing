#include <string>


namespace ground_units
{
class GroudUnit
{
public:
    GroudUnit(std::string type);
    const std::string& getType() const { return type_; }
protected:
    std::string type_;
};


inline GroudUnit::GroudUnit(std::string type) :
    type_(type)
{
}
}



