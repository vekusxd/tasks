#pragma once

#include <memory>

class Any{
public:
    Any() : _value{nullptr}
    {}

    template<typename T>
    Any(const T& value)
        : _value{std::make_unique<Model<T>>(value)}
    {}

    bool isEmpty() const{
        return _value == nullptr;
    }

    void clear(){
        _value.reset();
    }

    template<typename U>
    U getValue() const{
        if(typeid(U) != _value->getType()){
            throw std::runtime_error("Bad any cast");
        }
        return static_cast<Model<U>*>(_value.get())->hold_value;
    }

    Any(const Any& other)
        : _value{other._value->clone()}
    {}

    Any& operator=(const Any& other){
        Any temp(other);
        std::swap(_value, temp._value);
        return *this;
    }

    Any(Any&& other) = default;
    Any& operator=(Any &&other) = default;
    ~Any() = default;


private:
    struct Concept{
        virtual ~Concept() = default;
        virtual const std::type_info& getType() const = 0;
        virtual std::unique_ptr<Concept> clone() const = 0;
    };

    template<typename T>
    struct Model : Concept{
        Model(const T& value) 
            : hold_value{value}
        {}

        const std::type_info& getType() const override{
            return typeid(hold_value);
        }

        std::unique_ptr<Concept> clone() const override{
            return std::make_unique<Model>(*this);
        }

        T hold_value;
    };
    std::unique_ptr<Concept> _value; 
};