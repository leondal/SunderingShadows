#include <std.h>
inherit WEAPONLESS;

void create(){
    ::create();
    set_id( ({"bulette"}) );
    set_name("Bulette");
    set_short("A bulette");
    set_long(
	"This monster is a terrifying predator. It is nearly 10 feet long "+
	"and looks like an armadillo. Its armored shell provides it very good protection, he looks like a tough opponent."
    );
    set_body_type("dog");
    set_race("bulette");
    set_gender("male");
    set_size(2);
    set_hd(9,1);
    set_hp(90);
    set_overall_ac(0);
    set_exp(4000);
    set("aggressive",24);
    set_class("fighter");
    set_guild_level("fighter",9);
    add_money("gold",random(500));
    add_limb("left claw","left hand",0,0,0);
    add_limb("right claw","right hand",0,0,0);
    set_attack_limbs(({"left claw", "right claw"}));	
    set_attacks_num(4);
    set_damage(2,4);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
