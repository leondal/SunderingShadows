#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create() 
{
    ::create();
    set_name("gargoyle");
    set_id(({"gargoyle","iron gargoyle"}));
    set_short("%^BOLD%^%^RED%^Iron Gargoyle");
    set_long("The Iron Gargoyle is a powerfull constructed created by the "
        "dark Master of this Tomb to serve as one of his guardians.  Known "
        "for their incredible size and strength the Iron Gargoyle are known "
        "throughout the realm as skilled warriors.");
    set_race("gargoyle");
    set_body_type("humanoid");
    set_gender("male");
    set_hd(25,6);
    set_size(3);
    set_overall_ac(-10);
    set_class("fighter");
    set_hp(700);
    add_limb("jaws", "head", 0, 0, 0);
    add_limb("right claw", "right hand", 0, 0, 0);
    add_limb("left claw", "left hand", 0, 0, 0);
    add_limb("right wing", "torso", 0, 0, 0);
    add_limb("left wing", "torso", 0, 0, 0);
    set_attack_limbs(({"jaws",
                       "right claw",
                       "left claw",
                       "right wing",
                       "left wing"
                    }));
    set_attacks_num(3);
    set_damage(1,8);
    set_base_damage_type("slashing");
    set_property("swarm",1);
    set_stats("strength",20);
    set_stats("dexterity",22);
    set_stats("constitution",22);
    set("aggressive","aggfunc");
    set_alignment(5);
    set_exp(18000);
    set_new_exp(25,"high");
    set_emotes(5,({"The Gargoyle glares at you, evil intent written in his eyes.",
        "The Gargoyle screaches in rage at your very presense.",}),0);
    set_funcs( ({"fly", "fire"}) );
    set_func_chance(30);
}

void die(object ob) 
{
    tell_room(ETO,"%^BOLD%^%^MAGENTA%^The Gargoyle's eyes go blank as it "
        "falls to the floor...dead!",TO);
    ::die(ob);
    return;
}

int aggfunc() 
{
    string mrace=TP->query_race();
    if (mrace == "undead") 
    {
        command("say Greetings, Master.");
	    return 1;
    } 
    else 
    {
	    TP->kill_ob(TO,0);
        force_me("grin");
        force_me("say %^RED%^ For the Glory of the Master!");
    }
}

void fire(object targ) 
{
    if(ROLLSAVE(targ,BW)) 
    {
        tell_object(targ,"%^BOLD%^%^RED%^A blazing cone of flame shoots forth from "
            "the Gargoyle's mouth and burns you!");
        tell_room(environment(targ),"%^BOLD%^%^RED%^A blazing cone of flame shoots "
            "forth from the Gargoyle's mouth!  The flame engulfs "+targ->QCN+"!%^RESET%^",targ);
        TO->set_property("magic",1);
        targ->do_damage("torso",roll_dice(1,12));
        TO->set_property("magic",-1);
        return;
    }
    
    tell_object(targ,"%^BOLD%^%^RED%^A blazing cone of flame shoots forth from "
        "the Gargoyle's mouth and burns you!");
    tell_room(environment(targ),"%^BOLD%^%^RED%^A blazing cone of flame shoots "
        "forth from the Gargoyle's mouth!  The flame engulfs "+targ->QCN+"!%^RESET%^",targ);
    TO->set_property("magic",1);
    targ->do_damage("torso",roll_dice(3,12));
    tell_object(targ,"%^RED%^A wave of flame burns at your body!\n");
    TO->set_property("magic",-1);
    return;

}

void fly(object targ) 
{
  string dam;
  
    if(ROLLSAVE(targ,PPD)) 
    {
        tell_object(targ,"%^BLUE%^The Gargoyle flies up above you on its mighty "
            "wings...then comes crashing down on you!");
        tell_room(environment(targ),"%^BOLD%^The Gargoyle flies up on his mighty "
            "wings...then comes crashing down on "+targ->QCN+"!",targ);
        targ->do_damage("torso",roll_dice(2,12));
        return;
    }

    tell_object(targ,"%^BLUE%^The Gargoyle flies up above you on its mighty "
        "wings...then comes crashing down on you!");
    tell_room(environment(targ),"%^BOLD%^The Gargoyle flies up on his mighty "
        "wings...then comes crashing down on "+targ->QCN+"!",targ);
    targ->do_damage("torso",roll_dice(4,12));
    tell_object(targ,"You feel the life being crushed out of you by the "
        "Gargoyle's metal form!");
    targ->set_paralyzed(random(5)+15,"%^BOLD%^%^RED%^You can't seem to get "
        "out from under the Gargoyle!");
    return;

}
