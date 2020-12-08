
#include <iostream>
#include <iomanip>
#include <memory>
#include <numeric>
#include <algorithm>
#include <array>
#include <vector>
#include <random>

using namespace std::literals::string_literals;

size_t constexpr elmts = 100;

int main(int argc, char const * argv[]) {

  size_t cc;
  size_t constexpr cl = 10;

  auto lprt = [&cc](auto & nn) {
    std::cout << std::setw(4)
              << nn
              << ((++cc % cl == 0) ? "\n"s : ""s);
  };

  std::random_device rd;
  std::mt19937 re(rd());

  std::unique_ptr<std::array<int32_t, elmts>>
    mntery(std::make_unique<std::array<int32_t, elmts>>());

  int yy[elmts];

  auto ua = std::make_shared<std::vector<int16_t>>(elmts);
  auto up = ua.get();
  auto ux = *ua;
//  std::cout << up << ' ' << ux << std::endl;

  std::cout << "iota:"s << std::endl;
  std::iota(ua->rbegin(), ua->rend(), 0);
  cc = 0;
  std::for_each(ua->begin(), (*ua).end(), lprt);
  std::cout << std::endl;

  std::array<int32_t, elmts> const *pt = mntery.get();

  std::cout << mntery.get() << '+' << '\n'
            << (*mntery.get())[0] << '\n'
            << (*mntery)[0] << '+'
            << std::endl;

  std::cout << " ua        " << ua << '-' << '\n'
            << " up        " << up << '\n'
            << " ux.size() " << ux.size() << '\n'
            << " ua->at(0) " << ua->at(0) << '\n'
            << " ux.at(0)  " << ux.at(0) << '-'
            << std::endl;
  cc = 0;
  for (auto dx : *ua) {
    lprt(dx);
  }

  // iota
  std::cout << "iota:"s << std::endl;
  std::iota((*mntery).rbegin(), (*mntery).rend(), 0);
  cc = 0;
  for (auto ii : (*mntery)) {
    lprt(ii);
  }
  std::cout << std::endl;

  {
    //  shuffle
    std::cout << "shuffle:"s << std::endl;

    std::shuffle((*mntery).begin(), (*mntery).end(), re);

    std::cout << "for_each (std::array):"s << std::endl;
    cc = 0;
    std::for_each((*mntery).rbegin(), (*mntery).rend(), lprt);
    std::cout << std::endl;

    std::cout << "for_each (C array):"s << std::endl;
    for (size_t i_ = 0; i_ < elmts; ++i_) {
      yy[i_] = (*mntery)[i_];
    }
  }

  {
    cc = 0;
    std::for_each(std::cbegin(yy), std::cend(yy), lprt);
    std::cout << std::endl;

    //  make_heap
    std::cout << "make_heap (std::array):"s << std::endl;
    std::make_heap((*mntery).begin(), (*mntery).end());
    cc = 0;
    std::for_each((*mntery).begin(), (*mntery).end(), lprt);
    std::cout << std::endl;
    std::cout << "sort_heap (std::array):"s << std::endl;
    std::sort_heap(std::begin(*mntery), std::end(*mntery));
    cc = 0;
    std::for_each((*mntery).cbegin(), (*mntery).cend(), lprt);
    std::cout << std::endl;
  }

  {
    // sort_heap
    std::cout << "make_heap (C array - reverse iterator):"s << std::endl;
    std::make_heap(std::rbegin(yy), std::rend(yy));
    cc = 0;
    std::for_each(std::cbegin(yy), std::cend(yy), lprt);
    std::cout << std::endl;

    std::cout << "sort_heap (C array - reverse iterator):"s << std::endl;
    std::sort_heap(std::rbegin(yy), std::rend(yy));
    cc = 0;
    std::for_each(std::cbegin(yy), std::cend(yy), lprt);
    std::cout << std::endl;
  }

  {
    //  sort
    std::cout << "shuffle:"s << std::endl;
    std::shuffle((*mntery).begin(), (*mntery).end(), re);
    cc = 0;
    std::for_each((*mntery).begin(), (*mntery).end(), lprt);
    std::cout << std::endl;
    std::cout << "sort:"s << std::endl;
    std::sort((*mntery).begin(), (*mntery).end());
    cc = 0;
    std::for_each((*mntery).cbegin(), (*mntery).cend(), lprt);
    std::cout << std::endl;
  }

  {
    //  stable_sort
    std::cout << "shuffle:"s << std::endl;
    std::shuffle(std::begin(yy), std::end(yy), re);
    cc = 0;
    std::for_each(std::cbegin(yy), std::cend(yy), lprt);
    std::cout << std::endl;

    std::cout << "stable_sort:"s << std::endl;
    std::stable_sort(std::begin(yy), std::end(yy));
    cc = 0;
    std::for_each(std::cbegin(yy), std::cend(yy), lprt);
    std::cout << std::endl;
  }

//  std::unique_ptr<int> xx(std::make_unique<int>(yy));

  return 0;
}
