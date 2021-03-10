#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create()
{
    ::create();
    set_name("ghoul");
    set_id(({"ghoul"}));
    set_name("ghoul");
    set_short("%^RESET%^%^RED%^Ghoul%^RESET%^");
    set_long("This is one of the many warriors captured from the Army of"
        "Light, and corrupted by the Master into his slave. Fed off"
        "the blood of their Master they fight with an uncanny strength.");
    set_race("undead");
    set_body_type("human");
    set_gender("male");
    set_level(20);
    set_hd(20,8);
    set_hp(400);
    set_size(2);
    add_limb("fangs", "head", 0, 0, 0);
    add_limb("right claw", "right hand", 0, 0, 0);
    add_limb("left claw", "left hand", 0, 0, 0);
    set_attack_limbs(({"fangs","right claw","left claw"}));
    set_attacks_num(3); 
    set_damage(1,6);
    set_base_damage_type("slashing");
    set_overall_ac(0);
    set("aggressive",25);
    set_class("fighter");
    set_mlevel("fighter",25);
    set_stats("strength",19);
    set_stats("constitution",17);
    set_stats("dexterity",20);
    set_alignment(9);
    set_exp(9000);
    set_new_exp(25,"normal");
    add_money("gold",random(75)+1);
    set_hit_funcs((["fangs":(:TO,"special":)]));
    set_resistance("negative energy",10);
    set_resistance("positive energy",-10); 
}

void special(object targ) 
{

    if(!ROLLSAVE(targ,PPD))
    {
        tell_object(targ,"%^BOLD%^%^RED%^The Ghoul sinks his fangs into your neck!%^RESET%^");
        tell_room(environment(targ),"%^BOLD%^%^RED%^The Ghoul quenches his bloody thirst on "
            ""+targ->QCN+"'s neck!%^RESET%^",targ);
        targ->do_damage("neck",roll_dice(4,8));
        targ->set_paralyzed(15,"%^RED%^You are too weak to move!");
        return;
    }
    return;    
}

void die(object ob) 
{
    tell_room(ETO,"%^BOLD%^%^BLUE%^The Ghoul spits up its last bit of blood as you "
        "snuff the life from it!%^RESET%^",TO);
    ::die(ob);
    return;
}
