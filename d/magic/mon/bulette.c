//changed to inherit weaponless and use natural weapons.  It did 
//pull claws and teeth from Bane's dir, but it started erroring 
//because that dir was deleted.  Circe 7/23/04
#include "summoned_monster.h"
inherit WEAPONLESS;
void create(){
    ::create();
    set_id( ({"bulette"}) );
    set_name("Bulette");
    set_short("A bulette");
    set_long(
	"This monster is a terrifying predator. It is nearly 10 feet long "+
	"and looks like an armadillo. Its armored shell provides it very "+
      "good protection, he looks like a tough opponent."
    );
    set_body_type("quadruped");
    set_race("bulette");
    set_gender("male");
    set_size(2);
    set_hd(13,1);
    set_hp(215);
    set_overall_ac(0);
    set_exp(4000);
    set("aggressive",24);
    set_class("fighter");
    set_guild_level("fighter",9);
    add_money("gold",random(500));
/*    set_wielding_limbs(({"right hand","left hand","head"}));
    new("/realms/bane/obj/buletteclaw")->move(this_object());
    command("wield claw in right hand");
    new("/realms/bane/obj/buletteclaw")->move(this_object());
    command("wield claw in left hand");
    new("/realms/bane/obj/buletteteeth")->move(this_object());
    command("wield teeth in head");
*/
    add_limb("teeth","head",0,0,0);
    add_limb("right claws","right foreleg",0,0,0);
    add_limb("left claws","left foreleg",0,0,0);
    set_damage(2,5);
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right claws","left claws","teeth"}));
}
