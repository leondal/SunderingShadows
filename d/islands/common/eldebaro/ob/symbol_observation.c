#include <std.h>
#include "../area_stuff.h"
inherit OBJECT;
int observation_stage;

int is_invincible() { return 1; }

void create() 
{
    ::create();
    set_name("an observation object");
    set_value(0);
    set_weight(0);	
    set_id(({"eldebarosymbolobservationxxsaide"}));
    set_property("no animate", 1);
    set_property("temporary_item", 1);
    set_heart_beat(1);
}


void do_observations()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    
    observation_stage++;
    switch(observation_stage)
    {
        case 1:
            tell_object(ETO, "%^BOLD%^%^WHITE%^You are seeing the same chamber that you are currently in.....\n ");
            tell_object(ETO, "%^BOLD%^%^BLACK%^However, there are numerous giants, each with %^RESET%^%^MAGENTA%^"+
            "violet%^BOLD%^%^BLACK%^ flesh gathered around a larger, female giant, waiting for her to speak....\n");
            tell_object(ETO, "%^BOLD%^%^GREEN%^You sense that you are seeing something from another time!\n\n\n");
            call_out("do_observations", 15);
            break;
        case 2:
            tell_object(ETO, "%^BOLD%^%^WHITE%^The larger, female giant speaks and her voice ECHOES through the "+
            "chamber!!\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^She says: %^RESET%^THE TIME HAS COME!!! THE WORLD WILL BOW BEFORE US!!! "+
            "AND THOSE WHO REFUSE SHALL BE TURNED TO PULP!!!\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^She continues: %^RESET%^EVEN NOW HE PREPARES FOR US!! HE GOES TO FACE THE "+
            "WARRIOR GENERAL INTRUDER AND THE DEMON!!! HE WILL RETURN VICTORIOUS AND THEN WE SHALL MARCH!!!\n");
            tell_object(ETO, "%^BOLD%^%^WHITE%^All those gathered around CHEER in unison and shout together: %^RESET%^"+
            "AS YOU WILL IT ASANTRA, SO IT SHALL BE!!!!\n\n");
            call_out("do_observations", 25);
            break;
        case 3:
            tell_object(ETO, "%^BOLD%^%^WHITE%^Before your very eyes time flows quickly... you are still "+
            "observing the same chamber, but some time has obviously passed... now only the female giant and an "+
            "ornately armored male stand alone in the chamber, facing each other.%^RESET%^\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^The male giant speaks:%^RESET%^ I have changed my mind... we must ally "+
            "with Intruder. It is how it was destined to be from the time of the primordials.\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^She interjects: %^RESET%^But my King, we are meant to RULE! Our race, as "+
            "one! We should not ally with something so foul as the warrior general!\n");
            tell_object(ETO, "%^BOLD%^%^WHITE%^The male giant backhands her viciously, sending her sliding across the chamber.\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^The male giant speaks again: %^RESET%^Do not question my authority again, Asantra. "+
            "I am your KING! It is my will that shall be done. Do not forget that.%^RESET%^\n\n");
            call_out("do_observations", 25);
            break;
        case 4:
            tell_object(ETO, "%^BOLD%^%^WHITE%^Time again flows before your very eyes, this time more rapidly... and your heart "+
            "begins beating LOUDLY in your chest. You see the same chamber, with only the female giant and a human cloaked in "+
            "dark robes.\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^The human speaks quietly: %^RESET%^Asantra, his will has been perverted by the ancients. "+
            "There is nothing that you can do to change that... your race, your people, they will be remembered as puppets. Not as conquerors. "+
            "You must do something while there is still time.....\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^The female giant sobs loudly for a few moments before speaking: %^RESET%^"+
            "so be it... send word... my guards and I will accept your offer. It is better to die with honor than to live as puppets "+
            "for something so foul. We will disable the wards within the castle. BUT he will know as soon as the first one is "+
            "disabled. This castle is HIS and he is KING.\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^She continues with more resolve:%^RESET%^ Your people best come prepared... less "+
            "they realize how powerful my KING is.\n\n");
            call_out("do_observations", 25);
            break;
        case 5:
            tell_object(ETO, "%^BOLD%^%^WHITE%^Time speeds by again and this time when it clears you see another chamber, even "+
            "larger than this one... your heart beats even quicker now and you sense that something is WRONG, as if "+
            "your presence is not unfelt... and a group of humans, each cloaked in dark robes enter.\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^The humans talk quietly amongst themselves and seem to be pointing at you, unsure "+
            "of what to do, they seem to ignore your presence....\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^The humans all begin chanting in unison as the very chamber you are observing "+
            "begins changing... the symbols begin appearing all over the stones and you sense that they are somehow warding the "+
            "chamber.%^RESET%^\n");
            tell_object(ETO, "%^BOLD%^%^WHITE%^The larger female giant walks briskly into the chamber and looks ENRAGED.\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^She roars:%^RESET%^ What are your people doing??? This is not what was supposed "+
            "to happen!!! She charges at them.\n\n");
            call_out("do_observations", 25);
            break;
        case 6:
            tell_object(ETO, "%^BOLD%^%^BLACK%^You watch her charge... before she makes it to them she shudders and falls, her "+
            "very body beginning to freeze.%^RESET%^\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^She holds her chest and seems to be struggling against the cold.%^RESET%^\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^One of the humans points at you, somewhat excitedly and mumbles:%^RESET%^ "+
            capitalize(ETO->QS) + " is from then!! From when we were told of!! What does that mean???\n");
            tell_object(ETO, "%^BOLD%^%^BLACK%^Another human screams at you:%^RESET%^ The third in the series is IDOL!!! MAKE "+
            "sure she stays GONE!!%^RESET%^");
            tell_object(ETO, "%^BOLD%^%^BLACK%^The female giant notices you and her eyes fill with %^BOLD%^%^RED%^IMMENSE RAGE "+
            "%^BOLD%^%^BLACK%^right before they go closed and you watch in amazement as her body is ENTOMBED in a "+
            "%^BOLD%^%^WHITE%^block of ice!%^RESET%^\n");
            tell_object(ETO, "%^BOLD%^%^CYAN%^Suddenly you pull away from the symbols and find yourself still in the present, as "+
            "your pulse finally starts slowing down...%^RESET%^\n\n");
            break;
            
    }
    if(observation_stage < 6)
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^ continues to stare blankly at the strange symbols, "+ETO->QP+
        " eyes slightly glazed over!%^RESET%^", ETO);
        return;
    }
    else
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^ finally manages to pull "+ETO->QP+" gaze away from the symbols!", ETO);
        ETO->set_paralyzed(0);
        TO->remove();
        return;
    }
    return;
}



void start_observing()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    tell_object(ETO, "%^BOLD%^%^CYAN%^You stare at the strange symbols, captivated by them!%^RESET%^");
    tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^ observes the symbols and seems captivated by them!%^RESET%^", ETO);
    if(!avatarp(ETO)) 
    {
        ETO->set_paralyzed(1000, "%^BOLD%^%^RED%^You are captivated by the "+
        "%^BOLD%^%^CYAN%^symbols%^BOLD%^%^RED%^!%^RESET%^");    
    }
    call_out("do_observations", 10);
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
        ETO->set_paralyzed(1000, "%^BOLD%^%^RED%^You are captivated by the "+
        "%^BOLD%^%^CYAN%^symbols%^BOLD%^%^RED%^!%^RESET%^");
        if(objectp(EETO)) 
        {
            tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ stares blankly at the "+
            "%^BOLD%^%^CYAN%^symbols%^BOLD%^%^RED%^!%^RESET%^", ETO);
        }
        return;
    }
}

