# Vigenère Cipher Encryption Tool

##  Project Description
This project is a C++ implementation of the **Vigenère Cipher**, a polyalphabetic substitution cipher that improves upon standard monoalphabetic ciphers (like Caesar) by using a keyword to shift letters variably. 

The program serves as a command-line tool that allows users to:
1.  **Encrypt** a plaintext message using a custom keyword.
2.  **Decrypt** a ciphertext back to its original state.
3.  **Verify** the integrity of the encryption process through automated testing.

This tool demonstrates fundamental concepts of cryptography, specifically symmetric key encryption, and illustrates how modular arithmetic is applied in computer science security.

##  Programming Approach
The implementation avoids using a complex 2D Vigenère Square (Tabula Recta). Instead, it utilizes an **Algebraic Implementation** based on Modular Arithmetic in $\mathbb{Z}_{26}$.

The core logic maps the English alphabet to integers $0-25$ ($A=0, B=1, ... Z=25$) and applies the following formulas:

* **Encryption:** $E_i = (P_i + K_i) \pmod{26}$
* **Decryption:** $D_i = (E_i - K_i + 26) \pmod{26}$

**Key Features:**
* **Input Sanitization:** Automatically strips spaces, numbers, and symbols to ensure mathematical consistency.
* **Cyclic Key Generation:** Dynamically repeats the user's keyword to match the length of the plaintext message.
* **Automated Testing:** Includes a suite of verification tests to ensure algorithm accuracy before user interaction.

##  Project Structure
```text
/
├── README.md           # Project documentation and instructions
└── src/
    └── project.cpp     # Main C++ source code
