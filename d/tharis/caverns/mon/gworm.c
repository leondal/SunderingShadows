//changed to inherit weaponless and use natural weapons.  It did 
//pull claws and teeth from Bane's dir, but it started erroring 
//because that dir was deleted.  Circe 7/23/04
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"worm","giant worm"}));
    set_name("Giant Worm");
    set_short("Giant Worm");
    set_long("An enormous worm, it stretches over 30 feet long! Its body "+
	"is covered in long bristles. It looks mean, dangerous, and hungry."
    );
    set_body_type("snake");
    set_race("worm");
    set_size(3);
    set_gender("female");
    set_hd(11,1);
    set_hp(121);
    set_exp(3000);
    set_overall_ac(1);
    set("aggressive",13);
    set_class("fighter");
    set_guild_level("fighter",12);
    add_money("gold",random(150));
    add_money("silver",random(300));
    add_money("copper",random(200));
/*
    set_wielding_limbs(({"head"}));
    new("/realms/bane/obj/wormteeth")->move(this_object());
    command("wield teeth in head");
*/
    add_limb("teeth","head",0,0,0);
    set_damage(1,8);
    set_attacks_num(1);
    set_base_damage_type("slashing");
    set_attack_limbs(({"teeth"}));
}
