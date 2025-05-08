#include <iostream>
#include <string>

using namespace std;

struct word_entry {
    char* word;
    int count;
};

bool is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

bool is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_alnum(char c) {
    return is_upper(c) || is_lower(c) || is_digit(c);
}

char to_lower(char c) {
    if (is_upper(c)) return c + 32;
    return c;
}

bool is_word_char(char c) {
    return is_alnum(c) || c == '\'';
}

void to_lower_case(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = to_lower(str[i]);
    }
}

char* copy_word(const char* start, int length) {
    char* word = new char[length + 1];
    for (int i = 0; i < length; i++) {
        word[i] = to_lower(start[i]);
    }
    word[length] = '\0';
    return word;
}

bool compare_words(const char* a, const char* b) {
    int i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i]) return false;
        i++;
    }
    return a[i] == b[i];
}

int find_word(word_entry* entries, int size, const char* word) {
    for (int i = 0; i < size; ++i) {
        if (compare_words(entries[i].word, word))
            return i;
    }
    return -1;
}

void free_entries(word_entry* entries, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] entries[i].word;
    }
    delete[] entries;
}

int main() {
    const int initial_capacity = 10;
    int capacity = initial_capacity;
    int size = 0;
    word_entry* entries = new word_entry[capacity];

    string paragraph;
    getline(cin, paragraph);

    const char* text = paragraph.c_str();
    const char* ptr = text;
    while (*ptr) {
        while (*ptr && !is_word_char(*ptr)) ptr++;
        const char* start = ptr;
        while (*ptr && is_word_char(*ptr)) ptr++;
        int length = ptr - start;
        if (length > 0) {
            char* word = copy_word(start, length);
            int index = find_word(entries, size, word);
            if (index >= 0) {
                entries[index].count++;
                delete[] word;
            } else {
                if (size == capacity) {
                    capacity *= 2;
                    word_entry* new_entries = new word_entry[capacity];
                    for (int i = 0; i < size; ++i)
                        new_entries[i] = entries[i];
                    delete[] entries;
                    entries = new_entries;
                }
                entries[size].word = word;
                entries[size].count = 1;
                size++;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        cout << entries[i].word << ": " << entries[i].count << endl;
    }

    free_entries(entries, size);

    cout<<"\n24CE076_PatelDarshan\n";
    return 0;
}
