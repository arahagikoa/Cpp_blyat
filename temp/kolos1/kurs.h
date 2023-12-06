    #ifndef KURS_H
    #define KURS_H
    #include <iostream>
    #include <fstream>
    using namespace std;

    class kurs {
    private:
    string convert(string const str) const {
            string year  = str.substr(0, 4);
            string day   = str.substr(4, 2);
            string month = str.substr(6, 2);
            return day+"-"+month+"-"+year;
    }
    public:
        int n;
        float* curs;
        string* data;
        string nazwa_pliku;
        kurs(string nazwa_pliku) : curs(new float[n]), data(new string[n]) {
            wczytaj_plik(nazwa_pliku, *this);
        }
        ~kurs(){
            delete[] curs;
            delete[] data;
        }
        void wczytaj_plik(string nazwa, kurs& zmienna);
        kurs operator/(const kurs& other) const {
        kurs result(nazwa_pliku);  // Inicjalizuję result w razie, gdy ilości n nie są równe
        if (n == other.n) {
            result = kurs(nazwa_pliku);  // Jeśli ilości n są równe, tworzę nowy obiekt kurs
            for (int i = 0; i < n; i++) {
                result.data[i] = this->data[i];
                result.curs[i] = curs[i] / other.curs[i];
            }
        }
        return result;
        }

        void print() const;
    };

#endif
