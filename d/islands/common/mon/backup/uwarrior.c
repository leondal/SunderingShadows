#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("warrior");
    set_id(({"undead warrior","undead","warrior"}));
    set_short("Undead Warrior");
    set_long("
    It is a potent warrior in rusty armor that still has accents of gold.
");
    set_race("undead");
    set_gender("male");
    set_hd(25,10);
    set_size(2);
    set_overall_ac(-6);
    set_class("fighter");
    set_guild_level("fighter",35);
    set_max_hp(query_hp());
    set_hp(250+random(200));
    set_wielding_limbs(({"right hand"}));
    set_body_type("humanoid");
    set_property("swarm",1);
    set_property("full attacks",1);
    set_property("no bump",1);
    set_stats("strength",18);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_mob_magic_resistance("average");
    set_exp(9000);
    set_alignment(9);
    new("/d/attaya/obj/rusts.c")->move(TO);
    command("wear shield");
    new("/d/attaya/obj/rustb.c")->move(this_object());
    command("wield blade in right hand");
    set_property("add kits",10);
}
void die(object ob) {
    message("environment",
        "%^RED%^The undead warrior collapses into a pile of bones and armor."
    ,ETO);
    :: die(ob);
}
int aggfunc() {
    string mrace=TP->query_race();
    if (mrace == "undead") {
	force_me ("grin");
	return 1;
    } else {
	TP->kill_ob(TO,0);
	force_me("say %^RED%^Death to all who oppose us!");
    }
}
int kill_ob(object who, int which){
    int hold;
     hold = ::kill_ob(who,which);
     "cmds/spells/d/_dispel_magic"->use_spell(TO,0,34,100,"mage");
    return hold;
}
