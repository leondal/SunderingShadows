#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id( ({"horror","hook horror"}) );
    set_name("Hook Horror");
    set_short("A Hook Horror");
    set_long(
	"This beast is covered in a grey exoskeleton like that of an insects. "+
	"It stands about 9 feet tall and its arms come to an end with sharp "+
	"12 inch claws. Its head is shaped like a vultures, its eyes are "+
	"large and multi-faceted. This creature sure lives up to its name."
    );
    set_body_type("human");
    set_race("Hook Horror");
    set_gender("male");
    set_size(2);
    set("aggressive",12);
    set_hd(8,1);
    set_hp(85);
    set_overall_ac(3);
    set_exp(200);
    set_class("fighter");
    set_guild_level("fighter",8);
    add_money("electrum",random(30));
    remove_limb("right hand");
    remove_limb("left hand");
    add_limb("beak","head",0,0,0);
    add_limb("right hook","right arm",0,0,0);
    add_limb("left hook","left arm",0,0,0);
    set_attack_limbs(({"right hook","left hook","beak"}));
    set_attacks_num(3);
    set_base_damage_type("piercing");
    set_damage(1,8);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
