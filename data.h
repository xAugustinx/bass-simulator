
const char * gryfMp3[4][13] = {
 //   {"E4_f_n", "F4_f_n", "Fs4_f_n", "G4_f_n", "Gs4_f_n", "A4_f_n", "As4_f_n", "B4_f_n", "C5_f_n", "Cs5_f_n", "D5_f_n", "Ds5_f_n", "E5_f_n"},
//    {"B3_f_n", "C4_f_n", "Cs4_f_n", "D4_f_n", "Ds4_f_n", "E4_f_n", "F4_f_n", "Fs4_f_n", "G4_f_n", "Gs4_f_n", "A4_f_n", "As4_f_n", "B4_f_n"},
    {"G3_f_n", "Gs3_f_n", "A3_f_n", "As3_f_n", "B3_f_n", "C4_f_n", "Cs4_f_n", "D4_f_n", "Ds4_f_n", "E4_f_n", "F4_f_n", "Fs4_f_n", "G4_f_n"},
    {"D3_f_n", "Ds3_f_n", "E3_f_n", "F3_f_n", "Fs3_f_n", "G3_f_n", "Gs3_f_n", "A3_f_n", "As3_f_n", "B3_f_n", "C4_f_n", "Cs4_f_n", "D4_f_n"},
    {"A2_f_n", "As2_f_n", "B2_f_n", "C3_f_n", "Cs3_f_n", "D3_f_n", "Ds3_f_n", "E3_f_n", "F3_f_n", "Fs3_f_n", "G3_f_n", "Gs3_f_n", "A3_f_n"},
    {"E2_f_n", "F2_f_n", "Fs2_f_n", "G2_f_n", "Gs2_f_n", "A2_f_n", "As2_f_n", "B2_f_n", "C3_f_n", "Cs3_f_n", "D3_f_n", "Ds3_f_n", "E3_f_n"}
};
const int gryfLiczby[4][10] = {
    {-1, 30, 31, 32, 33, 34, 35, 36, 37, 38}, // Rząd 1: (-1), 1, 2, 3, 4, 5, 6, 7, 8, 9
    {-1, 20, 26, 8,  21, 23, 28, 24, 12, 18}, // Rząd 2: (-1), Q, W, E, R, T, Y, U, I, O
    {-1, 4,  22, 7,  9,  10, 11, 13, 14, 15}, // Rząd 3: (-1), A, S, D, F, G, H, J, K, L
    {-1, 29, 27, 6,  25, 5,  17, 16, 54, 55}  // Rząd 4: (-1), Z, X, C, V, B, N, M, ,, .
};

const int wlaczniki[4] = {42, 49, 40, 229};
