/******************************************************************************

Practising Lambda with STL
Aman,
2022-04-08

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> 

class Person {
private:
   friend std::ostream& operator<<(std::ostream& os, const Person& p);
   std::string name;
   int age;

public:
   Person() = default;
   Person(std::string name, int age) : name{ name }, age{ age } {}
   ~Person() = default;
   std::string get_name() const {
      return name;
   }
   void sett_name(std::string name) {
      this->name = name;
   }
   int get_age() const {
      return age;
   }
   void sett_name(int age) {
      this->age = age;
   }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
   os << "[Person: " << p.name << " : " << p.age << " ]" << std::endl;
}

int main() {

   std::cout << "\n****************************************************" << std::endl;
   std::vector<int> nums{ 10,20,30,40,50 };

   // Example 1: Using a lambda expression with for_each to print each element of nums
   std::for_each(nums.begin(), nums.end(), [](int num) {
      std::cout << num << " ";
   });
   std::cout << std::endl;

   std::cout << "\n****************************************************" << std::endl;
   std::vector<int> score_vec{ 93,88,79,89,69 };
   int bonus_points{ 5 };

   // Example 2: Using a lambda expression with transform to add bonus points to each score in score_vec
   std::transform(score_vec.begin(), score_vec.end(), score_vec.begin(), [bonus_points](int score) {
      return score += bonus_points;
   });

   // Printing the updated scores
   std::for_each(score_vec.begin(), score_vec.end(), [](int n) {
      std::cout << n << " ";
   });
   std::cout << std::endl;

   std::cout << "\n ***************************************************** " << std::endl;
   std::vector<int> nums2{ 1,2,3,4,5,6,7,8,9,10 };

   // Example 3: Using a lambda expression with erase and remove_if to remove even numbers from nums2
   nums2.erase(std::remove_if(nums2.begin(), nums2.end(), [](int num) {
      return num % 2 == 0;
   }), nums2.end());

   // Printing the updated vector and its size
   std::for_each(nums2.begin(), nums2.end(), [](int num) {
      std::cout << num << " ";
   });
   std::cout << std::endl << "The size of the vector is: " << nums2.size() << std::endl;

   std::cout << "\n***************************************************" << std::endl;
   Person person1{ "Aman", 17 };
   Person person2{ "Leah", 18 };
   Person person3{ "Nancy", 20 };
   Person person4{ "Viktor", 15 };
   Person person5{ "Jane", 21 };
   Person person6{ "Maria", 19 };

   std::vector<Person> people{ person1, person2, person3,person4,person5,person6 };

   // Example 4: Using a lambda expression with sort to sort people vector by age
   std::sort(people.begin(), people.end(), [](Person lhs, Person rhs) {
      return lhs.get_age() < rhs.get_age();
   });

   // Printing the sorted vector
   std::cout << std::endl;
   for (auto per : people) {
      std::cout << per;
   }

   // Example 5: Using a lambda expression with sort to sort people vector by name
   std::sort(people.begin(), people.end(), [](Person lhs, Person rhs) {
      return lhs.get_name() < rhs.get_name();
   });
   std::cout << std::endl;

   // Printing the sorted vector
   for (auto per : people) {
      std::cout << per;
   }

   std::cout << "\n*******************************************************" << std::endl;
   std::cout << std::boolalpha << std::endl;

   // Example 6: A simple comparison using lambda expression
   std::cout << (1 == 1) << std::endl; // TRUE

   std::vector<int> nums1(30);

   // Example 7: Using iota to fill nums1 with consecutive numbers starting from 0
   std::iota(nums1.begin(), nums1.end(), 0);

   // Printing the vector
   for (auto num : nums1) {
      std::cout << num << " ";
   }

   return 0;
}
