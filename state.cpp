#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class CombinationLock
{
    vector<int> combination;
    int combination_len;
    string combination_str;
public:
    string status;

    CombinationLock(const vector<int> &combination) : combination(combination) {
        std::stringstream ss;
        for (auto digit : combination)
        {
            ss << digit;
        }
        combination_str = ss.str();
        combination_len = combination.size();
        status = "LOCKED";
    }

    void enter_digit(int digit)
    {
      if (status == "ERROR" ||
          status == "LOCKED")
      {
          status = std::to_string(digit);
      }
      else if (status.size() == combination_str.size())
      {
          status = std::to_string(digit);
      }
      else
      {
          status += std::to_string(digit);
      }

      if (status.size() == combination_str.size())
      {
          if (status == combination_str)
          {
              status = "OPEN";
          }
          else
          {
              status = "ERROR";
          }
      }
    }
};
