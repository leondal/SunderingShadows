//changed to inherit weaponless and use natural weapons.  It did 
//pull claws and teeth from Bane's dir, but it started erroring 
//because that dir was deleted.  Circe 7/23/04
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"troll","giant troll"}));
    set_name("Giant Troll");
    set_short("Giant Troll");
    set_long(
	"This disgusting green skinned creature stands in front of you "+
	"at almost 10 feet tall. A rubbery skin covers its skinny limbs. "+
	"It has black hair growing out of its oblong head and its eyes "+
	"are hidden inside deep black sockets."
    );
    set_body_type("human");
    set_race("troll");
    set_gender("male");
    set_hd(10,6);
    set_hp(116);
    set_exp(2500);
    set_overall_ac(4);
    set("aggressive",22);
    set_class("fighter");
    set_guild_level("fighter",11);
    set_stats("strength",19);
    add_money("gold",random(300));
/*
    set_wielding_limbs(({"head","right hand","left hand"}));
    new("/realms/bane/obj/trteeth")->move(this_object());
    command("wield teeth in head");
    new("/realms/bane/obj/trclaw")->move(this_object());
    command("wield claw in right hand");
    new("/realms/bane/obj/trclaw")->move(this_object());
    command("wield claw in left hand");
*/
    add_limb("right claws","right hand",0,0,0);
    add_limb("left claws","left hand",0,0,0);
    add_limb("teeth","head",0,0,0);
    set_damage(1,10);
    set_attacks_num(3);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right claws","left claws","teeth"}));
}
void heart_beat(){
    ::heart_beat();
    if((TO->query_hp()+3)>TO->query_max_hp()){
	TO->set_hp(TO->query_max_hp());
    }
    else TO->add_hp(3);
}
