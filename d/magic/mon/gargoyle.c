//changed to inherit weaponless and use natural weapons.  It did 
//pull claws and teeth from Bane's dir, but it started erroring 
//because that dir was deleted.  Circe 7/23/04
#include "summoned_monster.h"
inherit WEAPONLESS;
void create(){
    ::create();
    set_name("Gargoyle");
    set_short("A Gargoyle");
    set_id(({"gargoyle"}));
    set_long(
	"A wretched looking stone gargoyle. The massive creature stares at "+
	"you with a burning hatred. Its huge stone claws scrap against the "+
	"the ground. Its wings move slowly, back and forth, up and down..."
    );
    set_body_type("fowl");
    set_race("gargoyle");
    set_gender("male");
    set_size(2);
    set_hd(15,5);
    set_hp(210);
    set_stats("strength",14);
    set_stats("dexterity",17);
    set_stats("constitution",22);
    set_exp(1500);
    set_overall_ac(2);
    set("aggressive",12);
    set_class("fighter");
    set_guild_level("fighter",15);
    add_money("silver",random(100));
/*
    set_wielding_limbs(({"right hand","left hand","head","torso"}));
    new("/realms/bane/obj/garclaw")->move(this_object());
    command("wield claw in right hand");
    new("/realms/bane/obj/garclaw")->move(this_object());
    command("wield claw in left hand");
    new("/realms/bane/obj/garteeth")->move(this_object());
    command("wield teeth in head");
    new("/realms/bane/obj/garhorns")->move(this_object());
    command("wield horns in torso");
*/
    add_limb("teeth","head",0,0,0);
    add_limb("horns","head",0,0,0);
    set_damage(3,4);
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right claw","left claw","teeth","horns"}));
}
