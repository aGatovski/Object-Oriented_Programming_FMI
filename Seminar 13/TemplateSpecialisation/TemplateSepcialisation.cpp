#include <iostream>
template<typename T>
    void sort( T* data, size_t N) {
        for (size_t i = 1; i < N; i++){
            int temp = data[i];
            int j = i - 1;
            while (j>=0 && data[j]>temp) {
                data[j + 1] = data[j];
                j--;
            }
            data[j + 1] = temp;
        }
    }

template< >
void sort<char>(char* data, size_t N) {
    int tempArray[256]{0};
    for (size_t i = 0; i < N; i++){
        tempArray[data[i]  ]++;
    }

    int j = 0;

    for (size_t k = 0; k < 256; k++){
        if (tempArray[k] != 0) {
            for (size_t i = 0; i < tempArray[k]; i++){
                data[j++] = k;
            }
        }
    }

}

int main()
{
char a[4] = { 101 ,97,98,0};
sort((char*)a, 3);
}
