// Abu Osama
// 15 November 2000
// Azha

#include <std.h>

inherit MONSTER;

void stab(object targ);

void create() {
    object ob;
    ::create();
    set_name("thuggist leader");
    set_id(({ "thuggist leader", "leader", "thuggist" }));
    set_short("Abu Osama, Thuggist Leader");
    set_long(
@AZHA
Abu Osama is a man born and bred on pure hatred for the Empire and all
who follow its laws.  The son of Shia bin Drasi, the leader of the
Thuggist movement, he shares his father's dark skin, blue eyes and dark
hair as well as his hate of those who dare to live in peace without his
consent.  His presence in Azha does not bode well for this frontier
town.
AZHA
    );
    set_race("human");
    set_class("thief");
    set_level(27);
    set_gender("male");
    set_hd(27,1);
    set_size(2);
    set_overall_ac(-2);
    set_mlevel("thief",27);
    set_max_hp(200);
    set_hp(200);
	set_exp(2500);
    set_wielding_limbs(({"right hand","left hand"}));
    set_body_type("humanoid");
    set_property("no_bump",1);
    set_stats("strength",18);
    set_stats("dexterity",19);
    set_stats("constitution",17);
    set_thief_skill("move silently",95);
    set_thief_skill("hide in shadows",95);
    add_search_path("/cmds/thief");
    set("aggressive","aggfunc");
    set_alignment(9);
    ob = new("/d/shadow/obj/weapon/longsword");
    ob->set_property("monsterweapon",1);
    ob->set_property("enchantment",2);
    ob->move(TO);
    command("wield dagger in right hand");
    ob = new("/d/shadow/obj/weapon/dagger");
    ob->set_property("monsterweapon",1);
    ob->set_property("enchantment",1);
    ob->move(TO);
    command("wield dagger in left hand");
    set_invis();
}

void die(object ob) {
    message("environment",
      "%^YELLOW%^BOLD%^Abu Osama screams a curse at you as he expires!"
      "%^RESET%^"
      ,environment(TO));
    :: die(ob);
}

int aggfunc() {
  if(wizardp(TP)) return 1;
  command("say %^BOLD%^RED%^Your severed head will be my latest trophy, fool!");
  stab(TP);
}

void stab(object targ) {
    set_invis();
    command("stab "+targ->query_name());
}
