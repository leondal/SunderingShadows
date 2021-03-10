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
    cha = (int)who->query_stats("charisma");
    if(cha > 13) cha += random(3);
    if(cha > 17) cha += random(3);
    switch(cha) 
    {
        case 18..40:
            choices += ({"ebony"});
        case 14..17:
            choices += ({"sable"});
        case 0..13:
            choices += ({"black", "brown", "gray"});
            break;
    }
    return choices;
}

string *query_eye_colors(object who) 
{
    int cha;
    string *choices = ({});
    cha = (int)who->query_stats("charisma");
    if(cha > 13) cha += random(3);
    if(cha > 17) cha += random(3);
    switch(cha)
    {
        case 20..40:
            choices += ({"violet", "purple"});
        case 16..19:
            choices += ({"sable", "chocolate", "coffee"});
        case 0..15:
            choices += ({"black", "gray", "brown"});
            break;
    }
    return choices;
}
