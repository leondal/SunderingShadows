#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("skeleton");
    set_id(({"skeleton","undead","dead"}));
    set_short("Skeleton");
    set_long("
    An animated pile of bones, still covered in tough leathery flesh gapes at you.  It slowly sways back and forth as it watches you with darkened sockets.
");
    set_race("undead");
    set_gender("male");
    set_hd(16,10);
    set_size(2);
    set_overall_ac(-6);
    set_class("fighter");
    set_guild_level("fighter",16);
    set_max_hp(200);
    set_hp(200);
    set_wielding_limbs(({"right hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",18);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(7000);
    set_alignment(9);
    new("/d/attaya/obj/rustb.c")->move(this_object());
    command("wield blade in right hand");
}
void die(object ob) {
    message("environment",
        "%^RED%^The skeleton falls into a pile of shattered bones."
    ,environment(ob));
    :: die(ob);
}
int aggfunc() {
    string mrace=TP->query_race();
    if (mrace == "undead") {
	force_me ("grin");
	return 1;
    } else {
	TP->kill_ob(TO,0);
        force_me("emote shrieks horribly!");
    }
}
