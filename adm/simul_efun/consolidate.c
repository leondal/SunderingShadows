#define NUMBER ({ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" })

string consolidate(int x, string str)
{
    string tmp;
    string* words;
    int i, y;

    if (x == 1) {
        return str;
    }
    i = sizeof(words = explode(str, " "));
    if ((tmp = lower_case(words[0])) == "a" || tmp == "an" || tmp == "the") {
        i = sizeof(words = words[1..i - 1]);
    }
    if ((y = member_array("of", words)) > 0) {
        words[y - 1] = pluralize(words[y - 1]);
    } else {
        words[i - 1] = pluralize(words[i - 1]);
    }
    if (x > 10) {
        tmp = "numerous ";
    } else {
        tmp = NUMBER[x] + " ";
    }
    return tmp + implode(words, " ");
}

string consolidate_number(int x)
{
    if (x < 0) {
        return "";
    }
    if (x > 10) {
        return "numerous";
    } else {
        return NUMBER[x];
    }
}
