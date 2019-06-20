// Copyright 2019 Soumya Nag Suman soumya@bu.edu
// Copyright 2019 Rahul Rajaram rrajaram@bu.edu
// Copyright 2019 Jennifer Hong hongjt@bu.edu
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "timer.h"

using std::vector;
using std::string;
using std::cout;
using std::sort;

double currentFib(int n) {
  double val = (1 + sqrt(5)) / 2;
  double fibout = round(pow(val, n + 1) / sqrt(5));
  return fibout;
}


class Arrangements {
 private:
  // your private data

 public:
  int tablelength;
  string thenames;
  // more stuff here. data and methods
  Arrangements() {
    tablelength = 52;
    thenames = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  }
  explicit Arrangements(string names) {
    tablelength = names.length();
    thenames = names;
  }
  vector<string> panel_shuffles(int n);
  vector<string> dinner_shuffles(int n);
  double panel_count(int n);
  double dinner_count(int n);
  vector<string> add_character(int n);

  // more methods if you want
};

vector<string> Arrangements::add_character(int n) {
  std::vector<string> begin;
  begin = panel_shuffles(n - 1);
  // length of vector begin
  int begin_length = begin.size();
  for (int i = 0; i < begin_length; i++) {
    // add the character to the string
    // std::cerr << i << n << begin.size() << thenames.length() << "\n";
    (begin.at(i)) += (thenames.at(n - 1));
  }
  return begin;
}

vector<string> Arrangements::panel_shuffles(int n) {
  std::vector<string> one;
  std::vector<string> two;
  std::vector<string> final;
  std::vector<string> A  = {{thenames.at(0)}};
  std::string string1 = thenames.substr(0, 2);
  string string2 = string1;
  std::swap(string2.at(0), string2.at(1));
  std::vector<string> B = {string1, string2};

  int a = n;
  if (a > thenames.length()) {
    throw a;
  }

  if (n == 1) {
    return A;
  } else if (n == 2) {
    return B;
  } else {
    std::vector<string> add_char = add_character(n);
    one = add_char;

    // swap checker and then swap
    // loop through each string of the vector
    int one_length = one.size();
    for (int j = 0; j < one_length; j++) {
      int strilength = one.at(0).length();
      int thenames_length = thenames.length();

      if (one.at(j).at(strilength - 2) == thenames.at(n - 2)) {
        std::swap(one.at(j).at(strilength - 2), one.at(j).at(strilength - 1));
        two.push_back(one.at(j));
      }
    }
    // concatenate two vector
    final.reserve(add_char.size() + two.size());
    final.insert(final.end(), add_char.begin(), add_char.end());
    final.insert(final.end(), two.begin(), two.end());
  }
  return final;
}

std::vector<string> Arrangements::dinner_shuffles(int n) {
  std::vector<string> A  = {{thenames.at(0)}};
  std::string string1 = thenames.substr(0, 2);
  string string2 = string1;
  std::swap(string2.at(0), string2.at(1));
  std::vector<string> B = {string1, string2};

  int a = n;
  if (a > thenames.length()) {
    throw a;
  }

  std::vector<string> dinner_first = panel_shuffles(n);
  std::vector<string> dinner_last = add_character(n);

  std::vector<string> done;
  std::vector<string> three;
  if (n == 1) {
    return A;
  } else if (n == 2) {
    return B;
  } else {
    int dinner_last_length = dinner_last.size();
    for (int j = 0; j < dinner_last_length; j++) {
      int len = dinner_last.at(0).length();
      int thenames_length = thenames.length();
      if (dinner_last.at(j).at(0) == thenames.at(0)) {
        std::swap(dinner_last.at(j).at(0), dinner_last.at(j).at(len - 1));
        three.push_back(dinner_last.at(j));
      }
    }
    /*string n_char_thenames;
    for (int i = 0; i <= n-1; i++) {
      n_char_thenames.push_back(thenames.at(i));
    }
    // mmoving left
    std::vector<string> four:

    // moving right
    std::vector<string> five;*/

    std::string first_n = thenames.substr(0, n);

    string caseright = first_n;
    caseright = caseright.substr(0, first_n.length() - 1);
    char right = first_n.at(first_n.length() - 1);
    caseright = right + caseright;
    vector <string> r;
    r.reserve(caseright.size());
    r.push_back(caseright);


    string caseleft = first_n;
    caseleft = first_n.substr(1, caseleft.length() - 1);
    char left = first_n.at(0);
    caseleft = caseleft + left;
    vector <string> l;
    l.reserve(caseleft.size());
    l.push_back(caseleft);
    done.reserve(dinner_first.size() + three.size() + r.size() + l.size());
    done.insert(done.end(), dinner_first.begin(), dinner_first.end());
    done.insert(done.end(), three.begin(), three.end());
    done.insert(done.end(), r.begin(), r.end());
    done.insert(done.end(), l.begin(), l.end());
    return done;
  }
}

double Arrangements::panel_count(int n) {
  int a = n;
  if (a > thenames.size()) {
    throw a;
  }
  double out = currentFib(n);
  return out;
}



double Arrangements::dinner_count(int n) {
  double out1 = currentFib(n);
  double out2 = currentFib(n - 2);
  double outcount;
  int a = n;
  if (a > thenames.size()) {
    throw a;
  }
  if (n == 1 or n == 2) {
    outcount = n;
  } else {
    outcount = 1 + 1 + out2 + out1;
  }
  return outcount;
}




// Methods and constructors defined here:

// TESTING: leave this line and below as is.

void show_result(vector<string> v) {
  sort(v.begin(), v.end());
  for (auto c : v)
    cout << c << "\n";
  cout << "\n";
}

void show_partial_result(string testname, vector<string> res, int n) {
  if (res.empty()) return;

  sort(res.begin(), res.end());

  std::vector<uint64_t> locs{0, res.size() / 3,
                             2 * res.size() / 3, res.size() - 1};
  std::cout << "\n" << testname << " " << n << "\n";
  for (auto i : locs) {
    std::cout << " res.at(" << i
              << ") = " << res.at(i) << "\n";
  }
}


const int COUNTLIM = 100;
const int COUNTLIM_SMALL = 30;

void standard_tests();
void alternate_tests();
void interactive_main();

int main(int argc, char const ** argv) {
  if (argc > 1 and string(*(argv + 1)) == "alt")
    alternate_tests();
  else if (argc > 1 and (string(*(argv + 1)) == string("int")))
    interactive_main();
  else
    standard_tests();
}

// tests to be run for full credit, including performance.
void standard_tests() {
  int n;

  cout.precision(15);

  // Basic test
  Arrangements standard;

  cout << "\nPanel Shuffles for 4 panelists.\n";
  show_result(standard.panel_shuffles(4));

  cout << "\nDinner Shuffles for 4 guests.\n";
  show_result(standard.dinner_shuffles(4));

  // Test other names
  Arrangements numbers("123456789");
  Arrangements symbols("!@#$%^&*()_+");

  std::array<Arrangements*, 3> v{&standard, &numbers, &symbols};

  cout << "\nPanel Shuffles for 6 panelists, 3 sets of names.\n";
  for (auto arr : v)
    show_result(arr->panel_shuffles(6));

  cout << "\nDinner Shuffles for 6 guests, 3 sets of names.\n";
  for (auto arr : v)
    show_result(arr->dinner_shuffles(6));

  // Count tests
  Arrangements large(string(COUNTLIM, 'a'));

  Timer t_pc("panel count", true);
  n = 1;
  cout << "\nPanel Shuffle Count Table (0.1 seconds)\n";
  cout << "     N  panel(N)\n";

  while (n < COUNTLIM and t_pc.time() < 0.1) {
    t_pc.start();
    double pc = large.panel_count(n);
    t_pc.stop();
    cout << std::setw(6) << n << " "
         << std::setw(6) << pc << "\n";
    n++;
  }


  Timer t_dc("dinner count", true);
  n = 1;
  cout << "\nDinner Shuffle Count Table (0.1 seconds)\n";
  cout << "     N  dinner(N)\n";

  while (n < COUNTLIM and t_dc.time() < 0.1) {
    t_dc.start();
    double dc = large.dinner_count(n);
    t_dc.stop();
    cout << std::setw(6) << n << " "
         << std::setw(6) << dc << "\n";
    n++;
  }

  Timer t_panel("panel", true);
  n = 4;
  cout << "\nHow many panel shuffles can be created in 0.5 seconds?\n";

  while (t_panel.time() < 0.5)  {
    double last = t_panel.time();
    t_panel.start();
    vector<string> res = standard.panel_shuffles(n);
    t_panel.stop();
    show_partial_result("panel", res, n);
    cout << "time " << t_panel.time() - last << "\n";
    n++;
  }

  int largest_panel = n - 1;

  Timer t_dinner("dinner timing", true);
  n = 4;
  cout << "\nHow many dinner shuffles can be created in 0.5 seconds?\n";

  while (t_dinner.time() < 0.5)  {
    double last = t_dinner.time();
    t_dinner.start();
    vector<string> res = standard.dinner_shuffles(n);
    t_dinner.stop();
    show_partial_result("dinner", res, n);
    cout << "time " << t_dinner.time() - last << "\n";
    n++;
  }
  cout << "\nLargest panel shuffles performed: "
       << largest_panel << "\n";
  cout << "\nLargest dinner shuffles performed: " << n - 1 << "\n";

  // Error checking
  Arrangements small("abcd");
  cout << "\nError Handling Tests\n";

  try {
    small.panel_count(5);
  } catch (int n) {
    cout << n;
  }
  try {
    small.panel_shuffles(6);
  } catch (int n) {
    cout << n;
  }
  try {
    small.dinner_count(7);
  } catch (int n) {
    cout << n;
  }
  try {
    small.dinner_shuffles(89);
  } catch (int n) {
    cout << n;
  }
  try {
    large.dinner_shuffles(122);
  } catch (int n) {
    cout << n;
  }
  try {
    numbers.dinner_shuffles(9);
  } catch (int n) {
    cout << n;
  }
  try {
    numbers.dinner_shuffles(10);
  } catch (int n) {
    cout << n;
  }
  cout << "\n";
}

void alternate_tests() {
  cout.precision(15);
  // Basic test
  Arrangements standard;

  cout << "\nPanel Shuffles for 4 panelists.\n";
  show_result(standard.panel_shuffles(4));

  cout << "\nPanel Shuffles for 10 panelists.\n";
  show_result(standard.panel_shuffles(10));

  int n = 1;

  // Count tests
  Timer t_pc("panel count", true);
  cout << "\nPanel Shuffle Count Table (0.1 seconds)\n";
  cout << "     N  panel(N)\n";
  while (n < 52 and t_pc.time() < 0.1) {
    t_pc.start();
    double pc = standard.panel_count(n);
    t_pc.stop();
    cout << std::setw(6) << n << " "
         << std::setw(6) << pc << "\n";
    n++;
  }

  cout << "\nHow many panel shuffles can be created in 0.5 seconds?\n";
  n = 4;

  Timer t_panel("panel", true);

  while (t_panel.time() < 0.5)  {
    t_panel.start();
    vector<string> res = standard.panel_shuffles(n);
    t_panel.stop();
    show_partial_result("panel", res, n);
    n++;
  }
  cout << "\nLargest panel shuffles performed: "
       << n - 1 << "\n";
}


void interactive_main() {
  std::string asktype, symbols;
  int number;
  cout << "Type quit to exit.\n";
  cout << "Commands:\npc names n\nps names n\ndc names n\nds names n\n";
  cout.precision(15);

  while (true) {
    std::cin >> asktype;
    if (asktype == "quit") break;
    std::cin >> symbols;
    Arrangements h(symbols);
    std::cin >> number;
    if (asktype == "pc") {
      std::cout << "panel_count(" << number <<  ") = ";
      std::cout << h.panel_count(number) << "\n";
    } else if (asktype == "ps") {
      std::cout << "panel_shuffles(" << number <<  ") = ";
      for (auto e : h.panel_shuffles(number) )
        std::cout << e << " ";
      std::cout << "\n";
    } else if (asktype == "dc") {
      std::cout << "dinner_count(" << number << ") = ";
      std::cout << h.dinner_count(number) << "\n";
    } else if (asktype == "ds") {
      std::cout << "dinner_shuffles(" << number <<  ") = ";
      for (auto e : h.dinner_shuffles(number))
        std::cout << e << " ";
      std::cout << "\n";
    }
  }
}