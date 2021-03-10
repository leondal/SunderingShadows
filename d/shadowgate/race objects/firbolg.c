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

string *query_hair_colors(object who) 
{ 
    int cha;
    string *choices = ({});
    cha = (int)who->query_stats("charisma");
    cha += random(10);
    switch(cha) 
    {
        case 18..40:
            choices += ({"black", "brown"});
        case 13..17:
            choices += ({"golden", "auburn", "scarlet", "crimson"});
        case 0..12:
            choices += ({"blonde", "red", "gray"});
            break;
    }
    return choices;
}

string *query_eye_colors(object who) 
{
    int cha;
    string *choices = ({});
    cha = (int)who->query_stats("charisma");
    if(cha > 8) cha += random(5);
    switch(cha) 
    {
        case 16..40:
            choices += ({"silver", "emerald", "sapphire", "azure", "cyan", "sable", "chocolate", "coffee"});
        case 9..15:
            choices += ({"green", "hazel"});
        case 0..8:
            choices += ({"brown", "blue", "gray"});
            break;
    }
    return choices;
}