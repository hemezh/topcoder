void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}


#define SIZE 10010
#define MAX (SIZE - 3) / 2
vi primes;
void optSieve() {
        bitset<MAX + 1> bset;
        for (int i = 0; i*i <= SIZE ; i++) {
            if(bset[i] == false)
                for (int j = i+1; (2*j+1)*(2*i+3) <= SIZE; j++)
                    bset[((2*j + 1)*(2*i + 3) - 3) / 2] = true;
        }
        primes.push_back(2);
        for (int i = 0; i <= MAX ; i++) {
            if(bset[i] == false)
                primes.push_back(2*i + 3);
        }
}

