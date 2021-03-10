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
    subrace = (string)who->query("subrace");
    cha = (int)who->query_stats("charisma");
    if(cha > 8 && cha < 17) cha += random(3);
    else if(cha > 16) cha += random(8);
    switch(cha)
    {
        case 18..40:
            choices += ({"ebony", "golden", "silver"});
        case 13..17:
            choices += ({"sable", "auburn", "scarlet", "crimson"});
        case 0..12:
            choices += ({"black", "brown", "blonde", "red", "white", "gray", "bald"});
            break;
    }
    return choices;
}

string *query_eye_colors(object who) 
{
    int cha;
    string *choices = ({});
    cha = (int)who->query_stats("charisma");
    if(cha > 8 && cha < 17) cha += random(3);
    else if(cha > 16) cha += random(8);
    switch(cha)
    {
        case 25..40:
            choices += ({"violet", "purple"});
        case 24:
            choices += ({"yellow", "amber"});
        case 16..23:
            choices += ({"silver", "emerald", "sapphire", "azure", "cyan", "sable", "chocolate", "coffee"});
        case 9..15:
            choices += ({"green", "hazel"});
        case 0..8:
            choices += ({"brown", "blue", "gray"});
            break;
    }   
    return choices;
}

string *query_subraces(object who)
{
    string *subraces;
    subraces = ({"heartlander","zin'charu","aesatri","attayan","tsarven","morinnen","tonaz'tlacar","senzokuan","maalish"});
    if(OB_ACCOUNT->is_high_mortal(who->query_true_name())) 
    { 
        subraces += ({ "tiefling","aasimar","air genasi","earth genasi","fire genasi","water genasi" });
    }
    return subraces;
}