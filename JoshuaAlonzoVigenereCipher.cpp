#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- Helper Functions ---

// 1. Clean string: Keep only letters and convert to Uppercase
string cleanString(string s) {
    string result = "";
    for (char &c : s) {
        if (isalpha(c)) {
            result += toupper(c);
        }
    }
    return result;
}

// 2. Generate cyclic key
string generateKey(string text, string key) {
    if (key.empty()) return ""; 
    int x = text.size();
    string newKey = "";
    for (int i = 0, j = 0; i < x; i++) {
        if (j == key.size()) j = 0;
        newKey += key[j];
        j++;
    }
    return newKey;
}

// 3. Encryption Logic
string encrypt(string text, string key) {
    string cipher_text = "";
    for (int i = 0; i < text.size(); i++) {
        int p = text[i] - 'A';
        int k = key[i] - 'A';
        int x = (p + k) % 26;
        cipher_text += (char)(x + 'A');
    }
    return cipher_text;
}

// 4. Decryption Logic
string decrypt(string cipher_text, string key) {
    string orig_text = "";
    for (int i = 0; i < cipher_text.size(); i++) {
        int e = cipher_text[i] - 'A';
        int k = key[i] - 'A';
        int x = (e - k + 26) % 26; // +26 ensures positive result
        orig_text += (char)(x + 'A');
    }
    return orig_text;
}

// --- Test Runner ---
void runTest(string testName, string rawPlaintext, string rawKey) {
    string text = cleanString(rawPlaintext);
    string keyword = cleanString(rawKey);
    string key = generateKey(text, keyword);
    string encrypted = encrypt(text, key);
    
    cout << "Test [" << testName << "]: ";
    if (text == decrypt(encrypted, key)) {
        cout << "PASSED (Input: " << rawPlaintext << " -> " << encrypted << ")" << endl;
    } else {
        cout << "FAILED" << endl;
    }
}

int main() {
    // --- PART 1: Automated Verification ---
    cout << "=== 1. RUNNING AUTOMATED CHECKS ===" << endl;
    runTest("Reference Check", "GEEKSFORGEEKS", "AYUSH");
    runTest("Wrap-Around", "Z", "B");
    runTest("Symbol Stripping", "Hello World! 123", "KEY");
    cout << "-----------------------------------\n" << endl;

    // --- PART 2: User Input ---
    cout << "=== 2. CUSTOM USER INPUT ===" << endl;
    string rawKeyword, rawText;

    cout << "Enter Keyword: ";
    getline(cin, rawKeyword);
    
    cout << "Enter Message to Encrypt: ";
    getline(cin, rawText);

    // Process User Input
    string text = cleanString(rawText);
    string keyword = cleanString(rawKeyword);

    if (keyword.empty()) {
        cout << "Error: Keyword cannot be empty or symbols only." << endl;
        return 1;
    }

    string key = generateKey(text, keyword);
    string encrypted = encrypt(text, key);
    string decrypted = decrypt(encrypted, key);

    cout << "\n--- Results ---" << endl;
    cout << "Cleaned Input:  " << text << endl;
    cout << "Generated Key:  " << key << endl;
    cout << "Encrypted:      " << encrypted << endl;
    cout << "Decrypted:      " << decrypted << endl;

    return 0;
}