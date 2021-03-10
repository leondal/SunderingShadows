#include <std.h>
inherit OBJECT;
int info_stage;

int is_invincible() { return 1; }

void create() 
{
    ::create();
    set_name("an observation object");
    set_value(0);
    set_weight(0);	
    set_id(({"dallyhinfoobj"}));
    set_property("no animate", 1);
    set_property("temporary_item", 1);
    set_heart_beat(1);
}

void inform_me()
{
    string info_tmp, info_tmp2;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    
    info_stage++;
    info_tmp = "%^BOLD%^%^CYAN%^A faint voice whispers to you:%^RESET%^ :";
    switch(info_stage)
    {
        case 1:
            info_tmp2 = info_tmp;
            info_tmp2 += " For many years I have kept up this facade.... but I grow WEARY of it... "+
            "and still the forest ACHES for help...\n";
            info_tmp2 += info_tmp;
            info_tmp2 += " You see, long ago there was a peaceful Queen who dwelled on this island, and a King... They were "+
            "hopelessly in love with one another but neither dared let their people know.%^RESET%^\n";
            break;
        case 2:
            info_tmp2 = info_tmp;
            info_tmp2 += " A tragedy befell, it was targeted at the Queen, but through sheer manipulation decided to "+
            "destroy the King and pervert his castle. It did such through the power of an ancient demon... \n";
            info_tmp2 += info_tmp;
            info_tmp2 += " Eventually the demons spread from the marsh and killed most of the Natives... \n";
            break;
        case 3:
            info_tmp2 = info_tmp;
            info_tmp2 += " The Queen died last... but for years I have maintained that she still lived, in hope that someone would see "+
            "fit to help. \n";
            info_tmp2 += info_tmp;
            info_tmp2 += " I have been here for time immemorial.. and I found the peace to my liking..";
            break;
        case 4:
            info_tmp2 = info_tmp;
            info_tmp2 += " The demons though, they present a nuisance that I can no longer tolerate at all. I WILL "+
            "no longer TOLERATE!\n";
            info_tmp2 += info_tmp;
            info_tmp2 += " If you are brave enough, journey to the cliffs, descend into the marsh... find where the castle "+
            "once stood... there you will find a portal, seal it!\n";            
            break;
        case 5:
            info_tmp2 = info_tmp;
            info_tmp2 += " Be WARNED that the demons will not like being disturbed... and it is highly likely that "+
            "once that portal is sealed another shall open somewhere within the marsh... seal ALL of them that open!";
            info_tmp2 += info_tmp;
            info_tmp2 += " If you are able to accomplish this, then return here and I shall grant you a boon of my favor!\n";
            info_tmp2 += info_tmp;
            info_tmp2 += " Now BEGONE from here until you have accomplished your task!";
            break;            
    }
    tell_object(ETO, info_tmp2);
    if(info_stage < 5)
    {
        tell_room(EETO, ETOQCN +"%^BOLD%^%^WHITE%^ continues to stare blankly into the orb of light!%^RESET%^", ETO);
        call_out("inform_me", 25);
        if(!ETO->query_paralyzed() && !avatarp(ETO)) 
        {
            ETO->set_paralyzed(1000, "%^BOLD%^%^WHITE%^You are captivated by the "+
            "brilliant light!%^RESET%^");
        }
        return;
    }
    else
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ finally manages to pull "+ETO->QP+" gaze away from the orb of light and leaves the "+
        "shelter!", ETO);
        ETO->remove_paralyzed();
        tell_object(ETO, "%^BOLD%^%^WHITE%^You leave the shelter quickly and decisively, as the light commanded!%^RESET%^");
        ETO->force_me("north");
        TO->remove();
        return;
    }
    return;
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(ETO->query_ghost())
    {
        ETO->set_paralyzed(0);
        TO->remove();
        return;
    }
    if(!ETO->query_paralyzed() && !avatarp(ETO)) 
    {
        ETO->set_paralyzed(1000, "%^BOLD%^%^WHITE%^You are captivated by the "+
        "brilliant light!%^RESET%^");
        if(objectp(EETO)) 
        {
            tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^Stares blankly into the orb "+
            "of light!%^RESET%^", ETO);
        }
        return;
    }
}

