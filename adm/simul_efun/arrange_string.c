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
                         "C064" : "", "C000" : "", "C001" : "", "C002" : "", "C003" : "", "C004" : "",
                         "C004" : "", "C005" : "", "C006" : "", "C007" : "", "C008" : "", "C009" : "",
                         "C010" : "", "C011" : "", "C012" : "", "C013" : "", "C014" : "", "C015" : "",
                         "C016" : "", "C017" : "", "C018" : "", "C019" : "", "C020" : "", "C021" : "",
                         "C022" : "", "C023" : "", "C024" : "", "C025" : "", "C026" : "", "C027" : "",
                         "C028" : "", "C029" : "", "C030" : "", "C031" : "", "C032" : "", "C033" : "",
                         "C034" : "", "C035" : "", "C036" : "", "C037" : "", "C038" : "", "C039" : "",
                         "C040" : "", "C041" : "", "C042" : "", "C043" : "", "C044" : "", "C045" : "",
                         "C046" : "", "C047" : "", "C048" : "", "C049" : "", "C050" : "", "C051" : "",
                         "C052" : "", "C053" : "", "C054" : "", "C055" : "", "C056" : "", "C057" : "",
                         "C058" : "", "C059" : "", "C060" : "", "C061" : "", "C062" : "", "C063" : "",
                         "C064" : "", "C065" : "", "C066" : "", "C067" : "", "C068" : "", "C069" : "",                         
                         "C070" : "", "C071" : "", "C072" : "", "C073" : "", "C074" : "", "C075" : "",                         
                         "C076" : "", "C077" : "", "C078" : "", "C079" : "", "C080" : "", "C081" : "",
                         "C082" : "", "C083" : "", "C084" : "", "C085" : "", "C086" : "", "C087" : "",
                         "C088" : "", "C089" : "", "C090" : "", "C091" : "", "C092" : "", "C093" : "",
                         "C094" : "", "C095" : "", "C096" : "", "C097" : "", "C098" : "", "C099" : "",
                         "C100" : "", "C101" : "", "C102" : "", "C103" : "", "C104" : "", "C105" : "",
                         "C106" : "", "C107" : "", "C108" : "", "C109" : "", "C110" : "", "C111" : "",
                         "C112" : "", "C113" : "", "C114" : "", "C115" : "", "C116" : "", "C117" : "",
                         "C118" : "", "C119" : "", "C120" : "", "C121" : "", "C122" : "", "C123" : "",
                         "C124" : "", "C125" : "", "C126" : "", "C127" : "", "C128" : "", "C129" : "",
                         "C130" : "", "C131" : "", "C132" : "", "C133" : "", "C134" : "", "C135" : "",
                         "C136" : "", "C137" : "", "C138" : "", "C139" : "", "C140" : "", "C141" : "",
                         "C142" : "", "C143" : "", "C144" : "", "C145" : "", "C146" : "", "C147" : "",
                         "C148" : "", "C149" : "", "C150" : "", "C151" : "", "C152" : "", "C153" : "",
                         "C154" : "", "C155" : "", "C156" : "", "C157" : "", "C158" : "", "C159" : "",
                         "C160" : "", "C161" : "", "C162" : "", "C163" : "", "C164" : "", "C165" : "",
                         "C166" : "", "C167" : "", "C168" : "", "C169" : "", "C170" : "", "C171" : "",
                         "C172" : "", "C173" : "", "C174" : "", "C175" : "", "C176" : "", "C177" : "",
                         "C178" : "", "C179" : "", "C180" : "", "C181" : "", "C182" : "", "C183" : "",
                         "C184" : "", "C185" : "", "C186" : "", "C187" : "", "C188" : "", "C189" : "",
                         "C190" : "", "C191" : "", "C192" : "", "C193" : "", "C194" : "", "C195" : "",
                         "C196" : "", "C197" : "", "C198" : "", "C199" : "", "C200" : "", "C201" : "",
                         "C202" : "", "C203" : "", "C204" : "", "C205" : "", "C206" : "", "C207" : "",
                         "C208" : "", "C209" : "", "C210" : "", "C211" : "", "C212" : "", "C213" : "",
                         "C214" : "", "C215" : "", "C216" : "", "C217" : "", "C218" : "", "C219" : "",
                         "C220" : "", "C221" : "", "C222" : "", "C223" : "", "C224" : "", "C225" : "",
                         "C226" : "", "C227" : "", "C228" : "", "C229" : "", "C230" : "", "C231" : "",
                         "C232" : "", "C233" : "", "C234" : "", "C235" : "", "C236" : "", "C237" : "",
                         "C238" : "", "C239" : "", "C240" : "", "C241" : "", "C242" : "", "C243" : "",
                         "C244" : "", "C245" : "", "C246" : "", "C247" : "", "C248" : "", "C249" : "",
                         "C250" : "", "C251" : "", "C252" : "", "C253" : "", "C254" : "", "C255" : "",
                         "C256" : "", "CRST" : "",
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
