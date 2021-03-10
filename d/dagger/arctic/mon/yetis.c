#include <std.h>
#include "../arctic.h"
inherit CREATURE;

int FLAG = 0;

void create() 
{        
    ::create();
    set_name("Small Yeti");
    set_id(({"Yeti", "yeti", "small yeti", "arcticmon"}));
    set_race("yeti");
    set_body_type("human");
    set_gender((random(2)?"male":"female"));
    set_size(2);
    set_short("small yeti");
    set_long("%^RESET%^%^BOLD%^Shaggy white fur covers the body of the yeti "
             "making it very difficult to see in the snow.  "
             "The beast stands around five feet tall when "
             "on two feet, and weighs close to one hundred "
             "fifty pounds.  Two very light blue eyes peer out from "
             "behind a protruding brow.  Its clawed hands don't "
             "look quite as dangerous as those of the adult yeti, "
             "but those claws are still dangerous.%^RESET%^");
    set_hd(17,1);
    set_level(17);
    set_class("fighter");
    set_mlevel("fighter", 17);
    set_hp((random(100)+100));
    set_exp(1500);
    set_property("swarm", 1);
    set_overall_ac(-1);
    set_stats("strength",17);
    set_stats("dexterity",12);
    set_stats("intelligence",8);
    set_stats("wisdom",8);
    set_stats("constitution",17);
    set_stats("charisma",5);
    set_attacks_num(2);
    set_damage(3,2);
    set_base_damage_type("bludgeoning");
    add_limb("left claw", "left hand", 0, 0, 0);
    add_limb("right claw", "right hand", 0, 0, 0);
    set_attack_limbs(({"right claw","left claw"}));
    set("aggressive", 20);
    set_funcs( ({"call_help"}) );
    set_func_chance(20);
    set_speed(20);
    nogo("NOGO1");
    add_money("electrum",random(100)+100);
    set_resistance("cold",10);
}

void call_help()
{
    call_out("call_for_help",5,TO);
}


void call_for_help()
{
    if(!objectp(TO)) return;
    if(FLAG == 1) return;
    
    tell_room(ETO, "%^BOLD%^" +TO->QCN+ " looks around "
    "frantically and screams loudly!%^RESET%^", ETO);
    switch(random(25))
    {
    case 0..15:
        tell_room(ETO, "%^RED%^The scream goes "
        "unanswered!%^RESET%^", ETO);
        break;
    case 16..20:
        tell_room(ETO, "%^RED%^An adult yeti hears the "
        "scream and rushes in to help!%^RESET%^", ETO);
        new(MON"yeti")->move(ETO);
        break;
    case 21..24:
        tell_room(ETO, "%^RED%^Two adult yetis hear the "
        "scream and rush in to help!%^RESET%^", ETO);
        new(MON"yeti")->move(ETO);
        new(MON"yeti")->move(ETO);
        break;
    }

    FLAG = 1;
}

