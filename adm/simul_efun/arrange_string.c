/**
 * @file
 * @brief Functions to arrange string layout.
 */

/**
 * Removes colors from a string
 */
string strip_colors(string str)
{
    string ret;
    mapping Uncolor = ([ "RESET" : "\b", "BOLD" : "", "ULINE" : "", "FLASH" : "", "BLACK" : "", "RED" : "",
                         "BLUE" : "", "CYAN" : "", "MAGENTA" : "", "ORANGE" : "", "YELLOW" : "",
                         "GREEN" : "", "WHITE" : "", "BLACK" : "", "B_RED" : "", "B_ORANGE" : "",
                         "B_YELLOW" : "", "B_BLACK" : "", "B_CYAN" : "", "B_WHITE" : "", "B_GREEN" : "",
                         "B_MAGENTA" : "", "STATUS" : "", "WINDOW" : "", "INITTERM" : "", "B_BLUE" : "",
                         "ENDTERM" : ""]);
    ret = terminal_colour(str, Uncolor);
    return replace_string(ret, "\b", "");
}

string strip_punctuation(string word)
{
    string* bad = ({ ",", "!", "@", "#", "$", "%", "^", "&", "*", "_", "+", "=", ":", ";", " ", "." });
    int i;
    for (i = 0; i < sizeof(bad); i++) {
        word = replace_string(word, bad[i], "");
    }
    return word;
}

/**
 * Arranges string.
 * @code{.c}
 * arrange_string("This is a long string.", 7);
 * @endcode
 * returns "This is".
 * @code{.c}
 * arrange_string("short", 15);
 * @endcode
 * returns "short          "
 *
 * @param str String to arrange
 * @param x String length to which a string should be arranged.  If
 * the first argument is longer than the specified length, then all
 * remaining characters are chopped off.  If it is shorter,then the
 * remaining characters will be filled with spaces. Defaults ot 79
 * @return Arranged string
 */
varargs string arrange_string (string str, int x)
{
    string *letters;
    int NewLen, z, bare, tmp1 = -1, tmp2 = -1, real_letters;
    if(!x) x = 79;
    if(!stringp(str)) { if(intp(str)) { str = ""+str; } else { return ""; } }
    bare = strlen(strip_colors(str));
    if(x == bare) return str;
    if(x < strlen(str))
    {
        NewLen = x;
        NewLen += (strlen(str) - bare);
        letters = explode(str, "");
        for(z = 0;z < sizeof(letters);z++)
        {
            if(real_letters >= x)
            {
                if(tmp2 != -1)
                {
                    if(tmp2 < z) NewLen = z;
                    else NewLen = tmp2;
                    break;
                }
                if(tmp1 != -1)
                {
                    NewLen = tmp1-1;
                    break;
                }
                if(letters[z] == "%" && letters[z+1] == "^") NewLen = z-1;
                else NewLen = z;
                break;
            }
            if((z+1) < sizeof(letters))
            {
                if(letters[z] == "%" && letters[z+1] == "^")
                {
                    if(tmp1 != -1)
                    {
                        if(tmp2 == -1)
                        {
                            z++;
                            tmp2 = z;
                            tmp1 = -1;
                            continue;
                        }
                    }
                    if(tmp1 == -1)
                    {
                        tmp1 = z;
                        tmp2 = -1;
                        continue;
                    }
                    continue;
                }
            }
            if(tmp2 == -1 && tmp1 == -1) real_letters++;
            if(tmp2 != -1 && tmp1 == -1) real_letters++;
            continue;
        }
        str = str[0..(NewLen-1)];
    }
    bare = strlen(strip_colors(str));
    if(x == bare) return str;
    if(x >= bare)
    {
        z = x - bare;
        while(z > 0)
        {
            z--;
            str += " ";
            continue;
        }
        return str;
    }
    return str;
}
