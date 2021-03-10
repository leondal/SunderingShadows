#include <std.h>
inherit MONSTER;
void create() {
    object ob;
    ::create();
    set_name("red skeleton");
    set_id(({"skeleton","red skeleton","undead","dead"}));
    set_short("Red skeleton");
    set_property("undead",1);
set_long(
"An animated pile of bones, still covered in tough leathery flesh gapes at you.  It slowly sways back and forth as it watches you with darkened sockets.\n The bones have been coated and hardened in a blood-red magic resin that forms a tighter bond with the departed spirit's fury."
);
    set_race("undead");
    set_gender("male");
    set_property("full attacks",1);
    set_hd(40,10);
    set_size(3);
    set_overall_ac(-15);
    set_class("fighter");
    set_guild_level("fighter",40);
    set_max_hp(600);
    set_hp(600);
    set_wielding_limbs(({"right hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",25);
    set_stats("dexterity",24);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(37000);
    set_alignment(9);
new("/d/attaya/obj/hammer.c")->move(TO);
    command("wield hammer in right hand");
    new("/d/attaya/obj/moonrobe")->move(TO);
    command("wear robe");
    ob = new("/d/common/obj/brewing/herb_special_inherit");
    ob->set_herb_name("bone dust");
    ob->move(TO);
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}
void die(object ob) {
    message("environment",
        "%^RED%^The skeleton falls into a pile of shattered bones."
    ,environment(TO));
    :: die(ob);
}
int aggfunc() {
    string mrace=TP->query_race();
    if( wizardp(TP) ) return 0;
    if (mrace == "undead") {
	force_me ("grin");
	return 1;
    } else {
	TP->kill_ob(TO,0);
        force_me("emote shrieks horribly!");
    }
}
