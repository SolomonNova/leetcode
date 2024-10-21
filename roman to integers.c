int romanToInt(char* s) {
    int arr[256] = {0};

    arr['I'] = 1;
    arr['V'] = 5;
    arr['X'] = 10;
    arr['L'] = 50;
    arr['C'] = 100;
    arr['D'] = 500;
    arr['M'] = 1000;

    int sum = 0;
    int prev_value = 0;

    for (int i = strlen(s) - 1; i >= 0; i--) {
        int current_value = arr[s[i]];


        if (current_value < prev_value) {
            sum -= current_value;
        } else {

            sum += current_value;
        }


        prev_value = current_value;
    }

    return sum;
}
