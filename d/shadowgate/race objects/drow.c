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
        case 15..30:
            choices += ({"silver"});
        case 0..14:
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
    switch(cha) 
    {
        case 16..30:
            choices += ({"blue"});
        case 14..15:
            choices += ({"brown", "yellow", "amber", "violet", "purple"});
        case 0..13:
            choices += ({"black", "red"});
            break;
    }
    return choices;
}