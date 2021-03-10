#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit WEAPONLESS;

int x;

void create() 
{
    ::create();
    set_name("hellfire golem");
    set_id( ({"golem","hellfire golem","fire golem", "saidedekufiremon"}));
    set_gender("neuter");
    set_race("golem");
    set_short("%^RED%^H%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^llf"+
    "%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^r%^BOLD%^%^BLACK%^e "+
    "%^RESET%^%^RED%^G%^BOLD%^%^BLACK%^o%^RESET%^%^RED%^l"+
    "%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^m%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This massive creature towers roughly "+
    "ten feet into the air.  The body of this being is made from what "+
    "appears to be a very hot and flowing lava.  The thick liquid "+
    "flesh of the creature is coated with an almost solid "+
    "rock crust.  The crust has cracked and broken away in several "+
    "places, revealing the strange substance that serves as flesh "+
    "just beneath.  The disturbing and freightening appearance of "+
    "this creature is only aided by the flames which leap "+
    "out from beneath the crust and wreathe its body in "+
    "an ever burning, eternal flame.  Each of its thick and "+
    "long arms end in a brightly burning fist of flame.  The only "+
    "hint of anything other than fire involved with this creature "+
    "comes from the two %^YELLOW%^yellow%^BOLD%^%^BLACK%^ orbs "+
    "that are set into its face.%^RESET%^");
    set_body_type("human");
    set_size(3);
    set_alignment(9);
    add_money("gold", 400 + random(250));
    set("aggressive",26);
    x = 22;
    set_hd(x,1);
    set_class("cleric");
    set_mlevel("cleric",x);
    set_guild_level("cleric",x);
    set_stats("strength",18);
    set_stats("intelligence",10);
    set_stats("constitution",16);
    set_stats("dexterity",10);
    set_stats("wisdom",18);
    set_stats("charisma",8);
    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_spells(({"handfire", "flame strike", "fire storm"}));    
    set_spell_chance(50);
    set_hp(245 + random(31));
    //set_exp(5000);
	set_new_exp(25, "normal");
    set_funcs(({"slam"}));
    set_func_chance(35);  
    add_limb("left flaming fist","left hand",0,0,0);
    add_limb("right flaming fist","right hand",0,0,0);
    set_attack_limbs(({"left flaming fist", "right flaming fist"}));
    set_attacks_num(3);
    set_damage(2,3);
    set_max_level(25);
    set_overall_ac(-3);
    set_speed(40 + random(41));
    set_nogo(({FTUN_ROOMS"kinordas_chamber", FTUN_ROOMS"war_mongrels_tunnel10"}));
}

void slam(object targ) 
{
    int x;
    string limb;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(targ->id("saidedekufiremon")) return;
    x = 2 + random(2);
    while(x) 
    {
        limb = targ->return_target_limb();
        tell_object(targ,"%^RED%^The golem slams you in the "+
        limb+" with its flaming fists!%^RESET%^");

        tell_room(ETO,"%^RED%^The golem slams "+targ->QCN+"%^RED%^ in "+
        "the "+limb+" with its flaming fists!%^RESET%^",targ);
        targ->cause_typed_damage(targ, "torso", roll_dice(3,10), "fire");
        x--;
    }
}
