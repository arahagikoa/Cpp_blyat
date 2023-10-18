#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>

class Histogram{
private:
    std::vector<int> counts;

public:
    Histogram(int nbins);   
    int getSize() const;
    void fill(int x);
    void dice(int dices, int throws);
    int getCount(int bin) const;

    friend void draw(const Histogram& histogram);
};

#endif