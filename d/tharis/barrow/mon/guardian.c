#include "/d/tharis/barrow/short1.h"
#include <std.h>
inherit "/std/monster";
int xx,y;
object ob;

void create() {
    :: create();
    set_name("guardian");
    set_id(({"guardian","skeleton","my_guardian","skeleton guardian",
	"skeletal guardian" }));
    set_short("a skeletal guardian");
    set_long(
      "%^RESET%^%^RED%^The skeletal guardian is dressed in rotting robes " 
      " and armour. It stares through hollow eyes at it's surroundings and "
      "seems to carry an aura of power that is stronger than the "
      "average undead.%^RESET%^"
    );
    set_gender("male");
    set_hd(20,4);
    set_weight(175);
   set_max_level(25);
    set_ac(-2);
    set_stats("strength",20);
    set_stats("constitution",20);
    set_stats("dexterity",21);
    set_stats("wisdom",19);
    set_stats("intelligence",18);
    set_stats("charisma",10);
    set_hp(340);
    set_max_hp(340);
    set_property("no bump",1);
    set_property("full attacks",1);
   remove_property("swarm");
    set_alignment(9);
    set_body_type("humanoid");
    set_wielding_limbs(({"right hand","left hand"}));
   set_race("undead");
    set_class("fighter");
    set("aggressive","agg_fun");
    ob = new(OPATH "slayer");
    ob->move(TO);
    ob->set_property("monsterweapon",1);
    set_exp(8000);
   command("wield slayer");
    set_funcs(({"moves"}));
    set_func_chance(25);
    set_emotes(3, ({
	"%^RED%^The skeletal guardian cackles evilly!%^RESET%^",
	"%^RED%^%^BOLD%^The skeletal warrior claws at your face!%^RESET%^",
	"%^RED%^%^BOLD%^You feel sick and dizzy!%^RESET%^"
    }),1);
}
int moves() {
object me = this_object();
object vic = me->query_current_attacker();
    xx=random(2)+1;
    switch(xx) {
    case 1:
    set_property("magic",1);
	me->force_me("roar");
    tell_room(ETO,"%^BOLD%^%^RED%^The %^YELLOW%^Skeletal Guardian's%^RED%^ eyes blaze brightly!");
        vic->heal(-(random(10)+5));
        vic->do_damage("torso",1);
      vic->set_blind(1);
   remove_property("magic");
	return 1;
    case 2:
    set_property("magic",1);
        if((int)me->query_hp() < 75) {
	    return 1;
        }
        me->force_me("snarl");
        tell_room(ETO,
	    "%^BOLD%^%^BLACK%^The skeletal guardian looks upon "
	    +vic->query_cap_name()+" and drains "+vic->query_possessive()+
	    " inner essense!%^RESET%^",({TO,vic}));
        tell_object(vic,
	    "%^BOLD%^%^BLACK%^The skeletal guardian looks upon you and "
	    "drains you of your inner essense!%^RESET%^"	);
        vic->heal(-(random(20)+5));
        vic->add_poisoning(1);
        vic->do_damage("torso",0);
        vic->set_paralyzed(8,"You are weak from the draining!");
   remove_property("magic");
	return 1;
    }
}
int agg_fun(object ob) {
    if((int)TP->query_level() > 1349) {
	force_me ("bow");
	return 1;
    } else {
    set_property("magic",1);
        force_me("kill "+TP->query_name());
	force_me("scream "+TP->query_name());
        tell_object(TP,
        "%^BOLD%^%^BLACK%^The skeletal guardian looks upon you and "
	     "drains you of your inner essense!%^RESET%^");
        TP->heal(-(random(40)+10));
        TP->add_poisoning(5);
        TP->do_damage("torso",0);
        TP->set_paralyzed(8,"You are weak from the draining!");
	TO->set_magic_round();
	TO->set_disable();
   remove_property("magic");
        return 1;
    }
}

void die(object ob) {
    message("environment",
	"%^RED%^%^BOLD%^The skeletal guardian takes one final swing "
	"as he dies!%^RESET%^",environment(TO));
    ::die(ob);
}

void init() {
  ::init();
}
