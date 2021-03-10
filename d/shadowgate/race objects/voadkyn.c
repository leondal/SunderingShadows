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
    string *choices = ({}), subrace;
    choices += ({"bald"});
    return choices;
}

string *query_eye_colors(object who) 
{
    int cha;
    string *choices = ({});
    cha = (int)who->query_stats("charisma");
    if(cha > 8 && cha < 17) cha += random(3);
    else if(cha > 16) cha += random(5);
    switch(cha)
    {
        case 21..30:
            choices += ({"yellow", "amber"});
        case 20:
            choices += ({"violet", "purple"});
        case 16..19:
            choices += ({"silver", "emerald", "sapphire", "azure", "cyan", "sable", "chocolate", "coffee"});
        case 9..15:
            choices += ({"green", "hazel"});
        case 0..8:
            choices += ({"brown", "blue", "gray"});
            break;
    }
    return choices;
}
