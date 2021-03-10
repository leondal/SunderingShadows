#include <std.h>
#include "../arctic.h"
inherit CREATURE;


void create() {
        
    ::create();
    set_name("Mammoth");
    set_id(({"Mammoth", "mammoth", "arcticmon"}));
    set_race("elephant");
    set_body_type("quadruped");
    set_gender((random(2)?"male":"female"));
    set_size(5);
    set_short("wooly mammoth");
    set_long("%^ORANGE%^This towering elephant is covered with "
             "long, shaggy hair.  It has a nine foot long tusk on "
             "either side of its massive trunk, and large wooly "
             "ears.  The creature stands some fifteen feet high at "
             "the shoulder, and is close to thirty feet long.  The "
             "treelike legs that support the creature are the size "
             "of ogres, and could quite easily crush an average man "
             "to death.%^RESET%^");    
    set_hd(30,1);
    set_level(30);
    set_class("fighter");
    set_mlevel("fighter", 30);
    set_hp((random(500)+500));
    set_exp(10000);
    set_property("swarm", 0);
    set_overall_ac(-3);
    set_stats("strength",24);
    set_stats("dexterity",6);
    set_stats("intelligence",4);
    set_stats("wisdom",9);
    set_stats("constitution",22);
    set_stats("charisma",6);
    set_attacks_num(3);
    set_damage(5,5);
    add_limb("left tusk", "head", 0, 0, 0);
    add_limb("right tusk", "head", 0, 0, 0);
    add_limb("trunk", "head", 0, 0, 0);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"left tusk","right tusk","trunk"}));
    set("aggressive", 15);
    set_funcs( ({"trample"}) );
    set_func_chance(30);
    set_speed(50);
    nogo("NOGO1");
    add_money("silver",random(2500)+2500);
    set_resistance("cold",10);
}

void trample(object target)
{

    if(!objectp(target)) return;

    if(!ROLLSAVE(target, PPD))
    {
        tell_object(target, "%^RED%^The wooly mammoth "
        "tramples you under its massive front feet!%^RESET%^");
        tell_room(ETO, "%^RED%^The wooly mammoth tramples "
        ""+target->QCN+" under its front feet!%^RESET%^",target);
        TO->set_property("magic", 1);
        target->do_damage("torso", roll_dice(10,10));
        TO->set_property("magic", 0);
        target->set_paralyzed((random(10)+10),"You are "
        "trapped under the legs of the mammoth!");
        return;
    }
    tell_object(target, "%^RED%^The wooly mammoth "
    "charges past, almost trampling you!%^RESET%^");
    tell_room(ETO, "%^RED%^The wooly mammoth charges "
    "past "+target->QCN+" almost "
    "trampling "+target->QO+"!%^RESET%^",target);
    TO->set_property("magic", 1);
    target->do_damage("torso", roll_dice(10,10)/2);
    TO->set_property("magic", 0);
    return;
}
