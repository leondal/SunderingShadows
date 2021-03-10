#include <std.h>
inherit WEAPONLESS;
void create() {
    ::create();
    set_name("grimwall");
    set_id(({"grimwall","tomb","wall"}));
    set_short("Grimwall: the living wall");
    set_long(
      "It is an everchanging mass of stone fragments and bricks.  It even has a few metal ornamentations!  It most resembles a giant vulture that has been coated in tar and dipped in a mason's scrap pile."
    );
    set_race("wall");
    set_hd(8,10);
    set_level(25);
    set_size(2);
    set_overall_ac(-10);
    set_class("fighter");
    set_guild_level("fighter",25);
    set_max_hp(330);
    set_hp(330);
    set_wielding_limbs(({"iron clasp","tomb buffer"}));
    add_limb("stone slab","stone slab",96,1,4);
    add_limb("jagged slab","jagged slab",96,1,4);
    add_limb("rotating blade","rotating blade",96,1,4);
    add_limb("stone spike","stone spike",96,1,4);
    add_limb("iron clasp","iron clasp",96,1,4);
    add_limb("tomb buffer","tomb buffer",96,1,4);
    set_attacks_num(4);
    set_attack_limbs(({"tomb buffer","stone slab","jagged slab","rotating blade","stone spike","iron clasp","tomb buffer"}));
    set_base_damage_type("piercing");
    set_damage(1,8);
    set_body_type("fowl");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",20);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("very low");
    set_exp(25000);
    set_alignment(9);
    new("/d/attaya/obj/shroud.c")->move(this_object());
    command("wear shroud");
    set_emotes(3,({
	"The wall near you shuffles around!",
	"You see glowing slits like eyes in a nearby wall!",
      }),0);
}

void init(){
// added ::init() to fix/prevent bugs & changed wizardp to check true invis 2/23/03 *Styx*
    ::init();
    if(TP->query_invis() && !TP->query_true_invis()) {
//    if(TP->query_invis()&&!wizardp(TP)){
	tell_room(ETO,"%^BOLD%^%^RED%^A nearby wall comes to life and attacks you!");
	TP->set_invis();
	kill_ob(TP,1);
    }
}
void die(object ob) {
    message("environment",
      "%^BOLD%^The wall collapses and crumbles into a pile.\n"
      "%^BLUE%^In the brief flash of light as the wall explodes, you notice a %^YELLOW%^brass lever%^BLUE%^!"
      ,environment(TO));
    :: die(ob);
}

void aggfunc() {
    string mrace=TP->query_race();
    if (mrace == "undead") {
	force_me ("grin");
	return 1;
    } else {
	if(wizardp(TP)) return 1;
	TP->kill_ob(TO,0);
	force_me("say %^RED%^A giant wall transforms into a huge stone monster and attacks you!");
    }
}
