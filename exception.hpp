#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP
#include <string>

class Graph_validation {

public:
   Graph_validation(const std::string& msg) : msg_(msg) {}
  ~Graph_validation() {}

   std::string getMessage() const { 
        return(msg_);
   }
private:
   std::string msg_;
};

#endif  //EXCEPTION_HPP