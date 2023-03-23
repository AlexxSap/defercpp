#pragma once

namespace metafunc
{
template <class FunctionType>
class DeferFunc
{
public:
    explicit DeferFunc(FunctionType f) :
        f(f) { }
    ~DeferFunc() { f(); }

private:
    FunctionType f;
};

template <class FunctionType>
std::unique_ptr<DeferFunc<FunctionType>> deferFunc(FunctionType f)
{
    return std::make_unique<DeferFunc<FunctionType>>(f);
}

#define CONCAT(a, b) CONCAT_INNER(a, b)
#define CONCAT_INNER(a, b) a##b

#define defer(x) \
    auto CONCAT(defer_, __COUNTER__) = deferFunc([&]() { x(); })

} // namespace metafunc

