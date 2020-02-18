#include <cstddef>

// 単純な動的配列を生成する関数
void function1A(size_t count);
// RAIIクラスを利用して動的配列を生成する関数
void function1B(size_t count);

// RAII を実現する配列ラッパークラス。
template<typename T> class ArrayWrapper {
    size_t m_count;
    T* m_data;
public:
    ArrayWrapper() : m_count(), m_data() {}
    explicit ArrayWrapper(size_t count) : m_count(count), m_data(new T[count]()) {}
    ~ArrayWrapper() { delete[] m_data; }
    size_t count() const { return m_count; }
    T* data() { return m_data; }
    const T* data() const { return m_data; }
    T& operator[](size_t index) { return m_data[index]; }
    const T& operator[](size_t index) const { return m_data[index]; }
    // コピーは禁止とする。所有権の移動もサポートしない。
private:
    ArrayWrapper(const ArrayWrapper&);
    ArrayWrapper& operator=(const ArrayWrapper&);
};
