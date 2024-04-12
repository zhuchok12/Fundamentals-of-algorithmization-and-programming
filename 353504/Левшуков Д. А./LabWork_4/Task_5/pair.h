#ifndef PAIR_H
#define PAIR_H
//#include "myvector.h"
template<typename f, typename s>
struct Pair{
    f first;
    s second;


    Pair(f first_, s second_):first(first), second(second){}

    Pair() = default;

    void swap(Pair<f, s>& other) {
        f buf1 = first;
        first = other.first;
        other.first = buf1;
        s buf2 = second;
        second = other.second;
        other.second = buf2;
    }

    Pair<f, s>& operator=(const Pair<f, s>& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }
};

template <typename f, typename s>
Pair<f, s> make_pair(const f& first, const s& second) {
    return Pair<f, s>(first, second);
}


#endif // PAIR_H
