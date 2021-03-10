#include <std.h>
inherit WEAPONLESS;
void create() {
    ::create();
    set_name("clockwork terror");
    set_id(({"clockwork terror","clockwork","terror"}));
    set_short("Clockwork terror");
    set_long("
     This is large metallic spider that was part of a Gnomish experiment gone horribly wrong.  The Clockwork horror has a heavy alloy exoskeleton and is armed with various blades and saws.
");
    set_race("toc'lahar");
    set_hd(8,10);
    set_level(18);
    set_size(3);
    set_overall_ac(-20);
    set_class("fighter");
    set_guild_level("fighter",16);
    set_max_hp(210);
    set_hp(210);
    set_wielding_limbs(({"right grappler","left grappler"}));
       add_limb("right grappler","right grappler",96,1,4);
       add_limb("left grappler","left grappler",96,1,4);
       add_limb("ripsaw","ripsaw",96,1,4);
       add_limb("reciprocal saw","reciprocal saw",96,1,4);
       add_limb("fangs","fangs",96,1,4);
    set_attacks_num(2);
set_attack_limbs(({"fangs","left grappler","right grappler","ripsaw","reciprocal saw"}));
   set_base_damage_type("piercing");
    set_damage(1,10);
    set_body_type("arachnid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(9000);
    set_alignment(9);
}
void die(object ob) {
    message("environment",
    "%^BOLD%^%^YELLOW%^Clockwork terror explodes!"
    ,environment(TO));
    :: die(ob);
}
void aggfunc() {
    if(TP->is_class("thief")){
    force_me("emote chitters evilly sensing a kindred.");
	return 1;
    } else {
	TP->kill_ob(TO,0);
          force_me("emote lets out a shrill cry as it tries to dig its fangs into your forehead!");
    }
}
