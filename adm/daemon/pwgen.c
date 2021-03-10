#include <std.h>

#define B64 "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

/**
 * Simple function to generate random string
 *
 * @param len - string lenght
 * @param str - input symbols
 * @return random string
 */
public string random_string(int len, string str)
{
    int symblen;
    int i;
    string ret;

    symblen = strlen(str);

    ret = "";

    for (i=0; i < len; i++)
    {
        ret+=sprintf("%c",str[random(symblen)]);
    }
    return ret;
}

/**
 * Generates random salt
 *
 * @param len - password lenght
 * @return B64 string
 */
public string random_salt(int len)
{
    return random_string(len,B64);
}
