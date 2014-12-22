#ifndef JOHNSONTROTTER_h
#define JOHNSONTROTTER_h

#include <iostream>
#include <vector>

typedef unsigned int uint;

namespace JT
{
    uint factorial(uint f)
    {
        uint res = 1;
        for(uint i=2; i<=f; ++i)
            res *= i;

        return res;
    }

    template <typename T> std::vector<std::vector<T> > johnsonTrotter(std::vector<T>& seq)
    {
        //initialization
        uint pos, s, l, fac;
        fac = factorial(seq.size());
        std::vector<std::vector<T> > perms, tmp;
        perms.reserve(fac);
        tmp.reserve(fac);

        std::vector<T> first;
        first.push_back(seq[0]);
        perms.push_back(first);

        if(seq.size() <= 1)
            return perms;

        //for each letter in original sequence
        for(uint i=1; i<seq.size(); ++i)
        {
            //preparation
            tmp.clear();

            s = perms.size();
            l = perms[0].size();
            for(uint j=0; j<s; ++j)
            {
                for(uint k=0; k<=l; ++k)
                {
                    tmp.push_back(perms[j]);
                }
            }
            perms.swap(tmp);

            pos = 0;
            for(uint j=0; j<perms.size(); ++j)
            {
                perms[j].insert((perms[j].begin()+pos), seq[i]);
                ++pos;
                if(pos >= perms[j].size())
                {
                    pos = 0;
                }
            }
        }
        return perms;
    }

}

#endif //JOHNSONTROTTER_H
