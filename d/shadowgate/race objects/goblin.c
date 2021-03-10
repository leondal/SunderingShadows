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
        case 19..40:
            choices += ({"dark brown"});
        case 0..18:
            choices += ({"black"});
         break;
    }
    return choices;
}

string *query_eye_colors(object who) 
{
    int cha;
    string *choices = ({});
    choices += ({"yellow", "red"});
    return choices;
}