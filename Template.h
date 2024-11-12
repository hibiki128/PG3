#pragma once
template <typename T1, typename T2>
class Template
{
private:
    T1 value1;
    T2 value2;
public:
    // コンストラクタ
    Template(T1 a, T2 b) : value1(a), value2(b) {}

    // 2つの引数のうち小さい方の値を返すメンバ関数
    auto Min() const -> decltype((value1 < value2) ? value1 : value2) {
        return (value1 < value2) ? value1 : value2;
    }

};

