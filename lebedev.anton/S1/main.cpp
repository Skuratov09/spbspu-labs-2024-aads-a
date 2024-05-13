#include <iostream>
#include "io_datastruct.hpp"
#include "list.hpp"

int main()
{
  using namespace lebedev;
  listOfPairs list_of_pairs;
  size_t max_pair_size = 0;
  max_pair_size = inputDS(std::cin, list_of_pairs);
  if (list_of_pairs.empty())
  {
    std::cout << "0\n";
    return 0;
  }
  try
  {
    List< size_t > sums;
    countSums(list_of_pairs, sums, max_pair_size);
    if (max_pair_size != 0)
    {
      outputPairsNames(std::cout, list_of_pairs);
      std::cout << '\n';
    }
    outputSequences(std::cout, list_of_pairs, max_pair_size);
    std::cout << '\n';
    outputSums(std::cout, sums);
    std::cout << '\n';
  }
  catch (const std::overflow_error & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (...)
  {
    std::cerr << "Error\n";
    return 1;
  }
  return 0;
}
