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
    string *choices = ({}), subrace;
    int cha;
    cha = (int)who->query_stats("charisma");
    subrace = (string)who->query("subrace");
    if(!stringp(subrace) || subrace == "lightfoot halfling")
    {
        if(cha > 8 && cha < 16) cha += random(3);
        else if(cha > 15) cha += random(5);
        switch(cha) 
        {
            case 19..30:
                choices += ({"ebony", "golden"});
            case 13..18:
                choices += ({"sable", "auburn", "scarlet", "crimson"});
            case 0..12:
                choices += ({"black", "brown", "blonde", "red"});
                break;
        }
    }
    else if(subrace == "ghostwise halfling" || subrace == "strongheart halfling")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha) 
        {
            case 17..30:
                choices += ({"ebony"});
            case 13..16:
                choices += ({"sable"});
            case 0..12:
                choices += ({"black", "brown"});
                break;
        }
    }
    return choices;
}

varargs string *query_eye_colors(object who) 
{
    string *choices = ({}), subrace;
    int cha;
    cha = (int)who->query_stats("charisma");
    subrace = (string)who->query("subrace");
    
    if(!stringp(subrace) || subrace == "lightfoot halfling")
    {
        if(cha > 8 && cha < 16) cha += random(3);
        else if(cha > 15) cha += random(5);
        switch(cha) 
        {
            case 19..30:
                choices += ({"emerald", "sapphire"});
            case 13..18:
                choices += ({"azure", "sable", "chocolate", "coffee"});
            case 0..12:
                choices += ({"blue", "green", "brown", "hazel"});
                break;
        }
    }
    else if(subrace == "ghostwise halfling" || subrace == "strongheart halfling")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha)
        {
            case 17..30:
                choices += ({"sable", "chocolate", "coffe"});
            case 13..16:
                choices += ({"brown"});
            case 0..12:
                choices += ({"black"});
                break;
        }
    }
    return choices;
}

string *query_subraces(object who)
{
    return ({"lightfoot halfling", "strongheart halfling", "ghostwise halfling"});
}