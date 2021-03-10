#include <std.h>
#include <daemons.h>

inherit OBJECT;
void create() 
{
    ::create();
    set_short("");
    set_long("");
    set_property("no drop", 1);
    set_property("death keep", 1);
    set_id(({"setter object"}));
    set_weight(0);
    set_property("no animate", 1);
    set_property("soulbound", 1);
}

string *query_hair_colors(int cha) 
{ 
    string *choices = ({});
    switch(cha+x) 
    {
        case 17..30:
            choices += ({"golden", "crimson", "scarlet", "auburn", "ebony"});
        case 13..16:
            choices += ({"red", "blonde", "stable"});
        case 0..12:
            choices += ({"brown", "black"});
            break;
    }
    return choices;
}

string *query_eye_colors(int cha) 
{
    string *choices = ({});
    switch(cha) 
    {
        case 17..30:
            choices += ({"emerald", "sable"});
        case 0..16:
            choices += ({"brown", "green", "hazel"});
            break;
    }
    return choices;
}