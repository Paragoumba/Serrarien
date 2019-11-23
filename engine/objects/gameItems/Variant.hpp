#ifndef SERRARIEN_VARIANT_HPP
#define SERRARIEN_VARIANT_HPP

template <class T>
class Variant {
protected:
    Variant() = default;

    T variant;

public:

    T getVariant(){

        return variant;

    }
};

#endif //SERRARIEN_VARIANT_HPP
