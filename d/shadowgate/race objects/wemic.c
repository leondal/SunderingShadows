#include <std.h>
#include <daemons.h>
#include <objects.h>

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
    if((string)who->query_gender() == "male") choices += ({"black"});
    else choices += ({"golden"});
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
        case 18..30:
            choices += ({"blue"});
        case 15..17:
            choices += ({"amber", "caramel", "emerald", "chocolate", "coffee", "sable"});
        case 12..14:
            choices += ({"green", "brown"});
        case 0..11:
            choices += ({"gold"});
            break;
    }
    return choices;
}
