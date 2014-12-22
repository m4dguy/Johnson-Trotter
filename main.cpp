#include <iostream>

#include "johnsonTrotter.h"

int main()
{
    std::vector<uint> seq;
    std::vector<std::vector<uint> > perms;

    for(uint i=1; i<=3; ++i)
        seq.push_back(i);

    std::cout << "sequence: " << std::endl;
    for(uint i=0; i<seq.size(); ++i)
        std::cout << seq[i] << ", ";
    std::cout << std::endl << std::endl;

    perms = JT::johnsonTrotter(seq);

    std::cout << "number of perms: " << perms.size() << std::endl;
    for(uint i=0; i<perms.size(); ++i)
    {
        for(uint j=0; j<perms[i].size(); ++j)
        {
           std::cout << perms[i][j] << ", ";
        }
        std::cout << std::endl;
    }


    return 0;
}
