/******************************************************************************

Practising Lambda with STL

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> 

class Person{
private:
   friend std::ostream&operator<<(std::ostream &os,const Person & p);
   std::string name;
   int age;
public:
   Person() = default;
   Person(std::string name, int age) : name{name}, age{age}{}
   ~Person() = default;
   std::string get_name() const {
      return name;
   }
   void sett_name(std::string name){
      this->name = name;
   }
   int get_age()const {
      return age;
   }
   void sett_name(int age){
      this->age = age;
   }
};


std::ostream& operator<<(std::ostream & os, const Person &p){
   os << "[Person: " << p.name << " : " << p.age << " ]" << std::endl;
}

int main(){

   std::cout << "\n****************************************************" << std::endl;
   std::vector<int> nums{10,20,30,40,50};
   
   std::for_each(nums.begin(), nums.end(),[](int num){
      std::cout << num << " ";
   });

   std::cout << "\n****************************************************" << std::endl;
   std::vector<int> score_vec{93,88,79,89,69};
   int bonus_points{5};
   std::for_each(score_vec.begin(), score_vec.end(),[](int n){
      std::cout << n << " ";
   });
   std::cout <<  std::endl;
   std::transform(score_vec.begin(), score_vec.end(), score_vec.begin(),[bonus_points](int score){
      return score+= bonus_points;
   });
   
   std::for_each(score_vec.begin(), score_vec.end(),[](int n){
      std::cout << n << " ";
   });


   std::cout << "\n ***************************************************** " << std::endl;
   std::vector<int> nums2{1,2,3,4,5,6,7,8,9,10};
   nums2.erase(std::remove_if(nums2.begin(), nums2.end(), [](int num){
      return num % 2 == 0;
   }), nums2.end());
   std::for_each(nums2.begin(), nums2.end(), [](int num){
      std::cout << num<< " ";
   });
   std::cout << std::endl << "The size of vector is: " << nums2.size()<< std::endl;


   std::cout << "\n***************************************************" << std::endl;
   Person person1{"Aman", 17};
   Person person2{"Leah", 18};
   Person person3{"Nancy", 20};
   Person person4{"Viktor", 15};
   Person person5{"Jane", 21};
   Person person6{"Maria", 19};
   
   std::vector<Person> people{person1, person2, person3,person4,person5,person6};
   std::sort(people.begin(), people.end(), [](Person lhs, Person rhs){
      return lhs.get_age() <rhs.get_age();
   });
      std::cout << std::endl;
   for(auto per : people){
      std::cout << per;
   }
   std::sort(people.begin(), people.end(), [](Person lhs, Person rhs){
      return lhs.get_name() <rhs.get_name();
   });
   std::cout << std::endl;
   
   for(auto per : people){
      std::cout << per;
   }

// 1,2,3,4,5,7,8,9,90
// 2-7
// 2,3,4,5,7


   std::cout << "\n*******************************************************" << std::endl;
   std::cout << std::boolalpha << std::endl;
   std::cout << (1==1) << std::endl; // TRUE
   std::vector<int> nums1(30);
   std::iota(nums1.begin(), nums1.end(), 0);
   for(auto num : nums1){
      std::cout << num << " ";
   }

    return 0;
}

