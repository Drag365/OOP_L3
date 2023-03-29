template<class T> class List {
private:
    int n = 0;
    T* mas;
    T* new_a;

    void increase_arr(T*& a, int k) {
        int new_n = n + k;
        new_a = new T[new_n];
        memcpy(new_a, a, n * sizeof(T));
        delete[] a;
        a = new_a;
        n = new_n;
    };
public:
    List() {
        mas = new T[n];
    };

    List(const List& List) {
        n = List.n;
        mas = new T[n];
        for (int i = 0; i < n; ++i)
            mas[i] = this->mas[i];
    }
    ~List() {
        delete[] mas;
    }

    void push_back(T* x) {
        increase_arr(mas, 1);
        for (int i = n - 1; i > 0; i--)
            mas[i] = mas[i - 1];
        mas[0] = *x;
    };

    void push(T* x) {
        increase_arr(mas, 1);
        mas[n - 1] = *x;
    };

    void Del(int j) {
        if (n == 0)
            return;
        for (int i = j; i < n; i++)
            mas[i] = mas[i + 1];
        increase_arr(mas, -1);
    };

    void Set(T* x, int j) {
        if (n != 0)
            mas[j] = *x; 
    };

    void Add(T* x, int j) {
        increase_arr(mas, 1);
        for (int i = n - 1; i >= j; i--)
            mas[i] = mas[i - 1];
        mas[j] = *x;
    };

  


    T get(int i) {
        return mas[i];
    }
    int getSize() {
        return n;
    }
};