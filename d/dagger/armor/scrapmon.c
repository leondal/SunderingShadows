#include <std.h>

inherit WEAPONLESS;

void create() {
    ::create();
    set_name("scrapmetal");
    set_id( ({"scrapmetal", "scrapmetal monster", "scrap", "monster"}) );
    set_short("monster of scrapmetal");
    set_long(
      "This monster is made entirely of the scrapmetal found below the armor shop.  Some unknown magic has caused the metal to combine and animate into a roughly human shape.  Its hands form crude yet sharp claws that reach towards you, ready to rend your body."
    );
    set_race("construct");
    add_search_path("/cmds/fighter");
    set_gender("neuter");
    set_overall_ac(-11);
    set_mob_magic_resistance("average");
    set_size(1+random(2));
    set_class("fighter");
    set_mlevel("fighter", 45);
    set_hd(45,2);
    set_max_hp(750);
    set_hp(750);
    set_wielding_limbs( ({"right hand", "left hand"}) );
    add_limb("right claw", "right claw",50,1,1);
    add_limb("left claw", "left claw",50,1,1);
    set_attacks_num(4);
    set_attack_limbs( ({"right claw", "left claw"}) );
    set_base_damage_type("slashing");
    set_damage(3,4);
    set_body_type("humanoid");
    set("aggressive", 50);
    set_alignment(5);
    set_property("no bows", 1);
    add_money("gold", 500 + random(500));
}

void die(object ob) {
    message("environment",
      "The monster trembles, and collapses into a heap of scrap metal surrounding a shining red suit of armor that is left behind"
      ,environment(TO));
    new("/d/dagger/armor/c_armor.c")->move(environment(TO));
    :: die(ob);
}

void init(){
    ::init();
    if(TP->query_invis()&&!wizardp(TP)) {
	tell_room(ETO, "The demon peers deep into your eyes, into your soul, and pulls you from your deception.");
	TP->set_invis();
	kill_ob(TP,1);
    }
}
