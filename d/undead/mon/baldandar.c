#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create() 
{
    ::create();
    set_name("baldandar");
    set_id(({"baldandar"}));
    set_short("%^RED%^Baldandar");
    set_long("%^RED%^This is a incredibly bulky creature with squared shoulders "
        "and a bull neck.  Its skin is a deep red in color and its eyes shimmer "
        "like living quicksilver.  The very air seems to shift about it, shadows "
        "blending with each of its steps.  This baldandar is a very unusual mix "
        "of brute force, and subtle deception.");
    set_race("baldandar");
    set_body_type("human");
    set_gender("male");
    set_size(3);
    set_overall_ac(-6);
    set_class("fighter");
    set_level(25);
    set_mlevel("fighter",25);
    set_hp(400);
    set_stats("strength",20);
    set_stats("dexterity",18);
    set_stats("constitution",20);
    set_speed(35);
    nogo("one");
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(22000);
    set_new_exp(25,"very high");
    set_alignment(9);
    set_invis();
    set_funcs(({"bite"}));
    set_func_chance(30);
    set_speed(20);
    new(OBJS"club_of_titans.c")->move(TO);
    command("wield club");
}

void bite(object targ) 
{
    
    if(!ROLLSAVE(targ,PPD)) 
    {
        tell_object(targ,"%^BLUE%^The baldandar lunges at you and sinks his fangs "
            "into your chest! His bite strikes and poisons you!%^RESET%^");
        tell_room(environment(targ),"%^BLUE%^The baldandar lunges at "+targ->QCN+" and "
            "sinks his hideous fangs into "+targ->QS+"!%^RESET%^",targ);
        TO->set_property("magic",1);
	    targ->do_damage("torso",roll_dice(3,8));
        TO->set_property("magic",-1);
	    tell_object(targ,"%^RED%^You feel the monster's venomous bite cause "
            "your body to constrict in pain!%^RESET%^");
        targ->set_paralyzed(random(10)+15,"%^GREEN%^The venom still siezes your muscles!%^RESET%^");
        targ->add_poisoning(roll_dice(3,6));
        return;
    }

    tell_object(targ,"%^BLUE%^The baldandar lunges at you and sinks his fangs "
        "into your chest! His bite strikes and hurts you!%^RESET%^");
    tell_room(environment(targ),"%^BLUE%^The baldandar lunges at "+targ->QCN+" and "
        "sinks his hideous fangs into "+targ->QS+"!%^RESET%^",targ);
	targ->do_damage("torso",roll_dice(2,6));
    return;
}
