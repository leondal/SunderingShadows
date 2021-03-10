#include <daemons.h>
string article(string str)
{
    string letter;
    if(!str) return "a";
    str = FILTERS_D->filter_colors(str);
    letter = str[0..0];
    if(member_array(letter,({"a","e","i","o","u","A","E","I","O","U"})) == -1) { return "a"; } 
    else { return "an"; }
}

