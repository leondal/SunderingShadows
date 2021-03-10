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
    if(!stringp(subrace) || subrace == "moon elf")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha)
        {
            case 17..30:
                choices += ({"silver", "platinum", "ebony"});
            case 13..16:
                choices += ({"blue"});
            case 0..12:
                choices += ({"black"});
                break;
        }
    }
     else if(subrace == "sun elf" || subrace == "fey'ri")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha) 
        {
            case 17..30:
                choices += ({"golden", "crimson", "scarlet", "auburn", "ebony"});
            case 13..16:
                choices += ({"red"});
            case 0..12:
                choices += ({"blonde", "black"});
                break;
        }
    }
    else if(subrace == "wood elf" || subrace == "wild elf")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha)
        {
            case 17..30:
                choices += ({"golden", "crimson", "scarlet", "auburn", "ebony"});
            case 13..16:
                choices += ({"red", "blonde", "sable"});
            case 0..12:
                choices += ({"brown", "black"});
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
    
    if(!stringp(subrace) || subrace == "moon elf")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha) 
        {
            case 17..30:
                choices += ({"sapphire", "azure", "cyan"});
            case 13..16:
                choices += ({"emerald"});
            case 0..12:
                choices += ({"green", "blue"});
                break;
        }
    }
    else if(subrace == "sun elf" || subrace == "fey'ri")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha) 
        {
            case 17..30:
                choices += ({"emerald", "golden"});
            case 13..16:
                choices += ({"amber"});
            case 0..12:
                choices += ({"green"});
                break;
        }
    }
    else if(subrace == "wood elf" || subrace == "wild elf")
    {
        if(cha < 17) cha += random(3);
        else if(cha > 16) cha += random(5);
        switch(cha)
        {
            case 17..30:
                choices += ({"emerald", "sable"});
            case 0..16:
                choices += ({"brown", "green", "hazel"});
                break;
        }
    }
    return choices;
}

string *query_subraces(object who)
{
    string *subraces;
    subraces = ({"moon elf", "wood elf", "sun elf"});
    if(OB_ACCOUNT->is_high_mortal(who->query_true_name())) 
    { 
        subraces += ({"wild elf", "fey'ri"});
    }
    return subraces;
}