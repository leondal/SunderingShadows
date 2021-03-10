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
    if(!stringp(subrace) || subrace == "shield dwarf")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha)
        {
            case 19..30:
                choices += ({"golden"});
            case 13..18:
                choices += ({"scarlet", "crimson", "blonde"});
            case 0..12:
                choices += ({"brown", "red", "gray", "white"});
                break;
        }
    }
    else if(subrace == "gray dwarf")
    {
        choices += ({"bald"});
    }
    else if(subrace == "gold dwarf")
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
    
    if(!stringp(subrace) || subrace == "shield dwarf")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha) 
        {
            case 19..30:
                choices += ({"silver", "emerald", "sapphire"});
            case 13..18:
                choices += ({"azure"});
            case 0..12:
                choices += ({"blue", "green"});
                break;
        }
    }
    else if(subrace == "gray dwarf")
    {
        choices += ({"black"});
    }
    else if(subrace == "gold dwarf")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha)
        {
            case 17..30:
                choices += ({"sable", "chocolate", "coffee"});
            case 13..16: 
                choices += ({"hazel"});
            case 0..12:
                choices += ({"brown"});
                break;
        }
    }
    return choices;
}

string *query_subraces(object who)
{
    string *subraces;
    subraces = ({"shield dwarf", "gold dwarf"});
    if(OB_ACCOUNT->is_high_mortal(who->query_true_name())) subraces += ({"gray dwarf"});
    return subraces;     
}