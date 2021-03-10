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
    if(!stringp(subrace) || subrace == "rock gnome")
    {
        if(cha < 9) cha += 0;
        else if(cha > 8 && cha < 16) cha += random(3);
        else if(cha > 15) cha += random(5);
        switch(cha) 
        {
            case 19..30:
                choices += ({"silver", "golden"});
            case 0..18:
                choices += ({"brown", "blonde", "gray", "white", "bald"});
                break;
        }
    }
    else if(subrace == "forest gnome")
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
    else if(subrace == "deep gnome")
    {
        if((string)who->query_gender() != "male") 
        {
            choices += ({"gray", "white"});
        }
        else { choices += ({"bald"}); }
    }
    return choices;
}

varargs string *query_eye_colors(object who) 
{
    string *choices = ({}), subrace;
    int cha;
    cha = (int)who->query_stats("charisma");
    subrace = (string)who->query("subrace");
    if(!stringp(subrace) || subrace == "rock gnome")
    {
        if(cha < 9) cha += 0;
        else if(cha > 8 && cha < 16) cha += random(3);
        else if(cha > 15) cha += random(5);
        switch(cha) 
        {
            case 19..30:
                choices += ({"violet", "amethyst"});
            case 13..18:
                choices += ({"sapphire", "azure"});
            case 0..12:
                choices += ({"blue", "gray"});
                break;
        }
    }
    else if(subrace == "forest gnome")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha)
        {
            case 17..30:
                choices += ({"sable", "chocolate", "coffee", "emerald", "sapphire"});
            case 13..16:
                choices += ({"brown", "hazel", "azure"});
            case 0..12:
                choices += ({"green", "blue"});
                break;
        }
    }
    else if(subrace == "deep gnome")
    {
        choices += ({"black", "gray"});
    }
    return choices;
}

string *query_subraces(object who)
{
    string *subraces;
    subraces = ({"rock gnome", "forest gnome"});
    if(OB_ACCOUNT->is_high_mortal(who->query_true_name())) 
    { 
        subraces += ({"deep gnome"});
    }
    return subraces;
}