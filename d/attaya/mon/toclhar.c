#include <std.h>
inherit WEAPONLESS;
void create() {
    ::create();
    set_name("toc'lahar");
    set_id(({"toc'lahar","toclahar","toc lahar","aberration"}));
    set_short("A hideous Toc'lahar");
    set_long(
      "A spindley spider-like creature that attacks by launching barbs at it's opponent.  They ride upon tall legs that are very thin.\n The Toc'lahar is an intelligent creature, and it is an effective hunter.  The body of the Toc'lahar is covered in a thick exoskeleton."
    );
    set_race("toc'lahar");
    set_hd(20,10);
     set_speed(30);
    set_level(20);
    set_size(3);
    set_overall_ac(-6);
    set_class("fighter");
    set_guild_level("fighter",16);
    set_max_hp(210);
    set_hp(210);
    set_wielding_limbs(({"right grappler","left grappler"}));
    add_limb("right grappler","right grappler",96,1,4);
    add_limb("left grappler","left grappler",96,1,4);
    add_limb("3 pronged barb","3 pronged barb",96,1,4);
    add_limb("2 pronged barb","2 pronged barb",96,1,4);
    add_limb("fangs","fangs",96,1,4);
    set_attacks_num(2);
    set_attack_limbs(({"fangs","left grappler","right grappler","3 pronged barb","2 pronged barb"}));
    set_base_damage_type("piercing");
    set_damage(1,8);
    set_body_type("arachnid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",16);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(3000);
    set_alignment(9);
    set_emotes(3,({
	"Toc'lahar shrieks horribly!",
      }),0);
}
void die(object ob) {
    message("environment",
      "%^BOLD%^%^MAGENTA%^Toc'lahar falls on it's side, then rolls on it's back and curls up it's legs."
      ,environment(TO));
    :: die(ob);
}
int aggfunc() {
    string mguild=TP->query_class();
    if(wizardp(TP)) return 1;
    if (mguild == "thief") {
	force_me ("chitter evilly sensing a kindred");
	return 1;
    } else {
	TP->kill_ob(TO,0);
	force_me("emote lets out a shrill cry as it tries to dig it's fangs into your forehead!");
    }
}
