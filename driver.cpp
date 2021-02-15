#include "TravelOptions.h"

#include <stdlib.h>
#include <iostream>

 using namespace std;
#include "TravelOptions.h"

#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  TravelOptions *options_p, *options_p2, *options_p3;

  std::vector<std::pair<double, double>>
	vec{ {2, 2}, {4, 4}, {8, 5}, {10, 6}};

  std::vector<std::pair<double, double>> *vec2;

  // remember:  from_vec is a static function (hence, TravelOptions:: form)
  options_p = TravelOptions::from_vec(vec);
  options_p2 = TravelOptions::from_vec(vec);

  options_p->display();
  std::cout << "size: " << options_p->size() << std::endl;

  TravelOptions::Relationship r;
  r = TravelOptions::compare(5.0, 2.9, 9.0, 1.9);
  if(r == TravelOptions::incomparable)
     std::cout << "INCOMPARABLE!" << std::endl;
  else if(r == TravelOptions::better)
     cout << "\nOption A is better\n" << endl;
  else
     cout << "\nOption A is worse\n" << endl;

  vec2 = options_p->to_vec();

  std::cout << "CONTENTS OF EXPORTED VECTOR:\n";
  for(int i=0; i<vec2->size(); i++) {
     std::cout << (*vec2)[i].first << (*vec2)[i].second << std::endl;
  }

  std::cout << "\n";
// sorted test
  if(options_p->is_sorted())
     std::cout << "it is sorted" << std::endl;
  if(options_p->is_sorted() == false)
        cout << "it's not sorted" << endl;

// pareto test

    if( options_p->is_pareto() )
     std::cout << "PARETO!" << std::endl;
    if( options_p->is_pareto() == false)
     std::cout << "not PARETO!" << std::endl;

    if(options_p->is_pareto_sorted())
     std::cout << "PARETO! and sorted" << std::endl;
    if(options_p->is_pareto_sorted()== false)
     std::cout << "not PARETO! and not sorted" << std::endl;

    if(options_p->insert_sorted(4.0, 1.0))
     std::cout << "INSERT_SORTED WORKED!" << std::endl;

   // if(options_p->insert_pareto_sorted(8.0, 4.0))
   //  std::cout << "INSERT_PARETO_SORTED WORKED!" << std::endl;


    options_p->display();
    std::cout << "size: " << options_p->size() << std::endl;


  return 0;
}
