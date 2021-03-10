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
    if(cha > 12) cha += random(3);
    switch(cha)
    {
        case 16..30:
            choices += ({"silver"});
        case 13..15:
            choices += ({"blonde", "brown"});
        case 0..12:
            choices += ({"white"});
            break;
    }
    return choices;
}

string *query_eye_colors(object who) 
{
    int cha;
    string *choices = ({});
    cha = (int)who->query_stats("charisma");
    if(cha > 12) cha += random(3);
    switch(cha)
    {
        case 17..30:
            choices += ({"blue"});
        case 14..16:
            choices += ({"brown", "chocolate", "coffee", "sable"});
        case 0..13:
            choices += ({"black", "red"});
            break;
    }
    return choices;
}