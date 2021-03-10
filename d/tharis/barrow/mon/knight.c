#include "/d/tharis/barrow/short1.h"
#include <std.h>
inherit "/std/monster";
int xx,y;
object ob;
void create() {
    :: create();
    set_name("knight");
    set_id(({
      "knight","skeleton","my_knight","skeleton knight",
	"skeletal knight"
      }));
    set_short("a skeletal knight");
    set_long(
      "%^RESET%^%^RED%^The skeletal knight is dressed in glowing rotten "
      "and bloodstained robes." 
      " It stares through hollow eyes at it's surroudings and "
      "a faint trace of an evil smile seems to fold forth from it's "
      "toothy skeletal mouth.%^RESET%^"
    );
    set_gender("male");
    set_hd(22,6);
    set_weight(175);
    set_ac(-4);
    set_stats("strength",22);
    set_stats("constitution",19);
    set_stats("dexterity",23);
    set_stats("wisdom",19);
    set_stats("intelligence",18);
    set_stats("charisma",15);
    set_hp(246);
    set_max_hp(246);
    set_property("full attacks",1);
    set_alignment(9);
    set_body_type("humanoid");
    set_wielding_limbs(({"right hand","left hand"}));
    set("race","undead");
    set_class("fighter");
    set_exp(18000);
    set("aggressive","agg_fun");
    ob = new(OPATH "slayer");
    ob->move(TO);
    command("wield slayer");
    set_funcs( ({"moves"}) );
    set_func_chance(35);
    set_emotes(6, ({
	"%^MAGENTA%^The skeletal knight screams at you!%^RESET%^",
	"%^RED%^%^GREEN%^The skeletal knight barely misses your neck with "
	"it's rotten claws!%^RESET%^",
	"%^CYAN%^%^BOLD%^You feel as though you are losing your "
	"mind!%^RESET%^"
    }),1);
}
int moves() {
object me = this_object();
object vic = me->query_current_attacker();
    xx=random(2)+1;
    switch(xx) {
    case 1:
	me->force_me("cackle");
    set_property("magic",1);
        tell_room(ETO,
	    "%^BOLD%^%^RED%^The skeletal knight gazes upon "
	    +vic->query_cap_name()+" and steals "+vic->query_possessive()+" inner "
	    "essence!%^RESET%^"
	,({TO,vic}));
        tell_object(vic,
	    "%^BOLD%^%^RED%^The skeletal knight gazes upon you and "
	    "steals a portion of your inner essence!%^RESET%^"
	);
        vic->heal(-(random(30)+5));
        vic->add_poisoning(2);
        vic->do_damage("torso",5);
        vic->set_paralyzed((random(16)+6),"You are weak from the draining!");
   remove_property("magic");
	return 1;
        
    case 2:
    set_property("magic",1);
        if((int)me->query_hp() < 100) {
            me->force_me("frown");
            me->force_me("say Leave Now!!!");
	    return 1;
        }
        me->force_me("grin");
        tell_room(ETO,
	    "%^BOLD%^%^BLACK%^The skeletal knight creates a %^RED%^"
	    "BALL OF "
            "%^YELLOW%^F"
	    "%^RED%^L"
	    "%^YELLOW%^A"
	    "%^RED%^M"
	    "%^YELLOW%^E"
	    "%^RED%^S%^BLACK%^ "
            "within his hands and hurls it at "
	    +vic->query_cap_name()+" while laughing evilly!%^RESET%^"
	,({TO,vic}));
        tell_object(vic,
	    "%^BOLD%^%^BLACK%^The skeletal knight creates a %^RED%^"
	    "BALL OF "
            "%^YELLOW%^F"
	    "%^RED%^L"
	    "%^YELLOW%^A"
	    "%^RED%^M"
	    "%^YELLOW%^E"
	    "%^RED%^S%^BLACK%^ "
            "within his hands and hurls it at "
	    +vic->query_cap_name()+" while laughing evilly!%^RESET%^"
	);
        vic->do_damage("torso",(random(30)+20/3+10/2+5));
        vic->set_paralyzed(8,"You are recovering from the blow!");
	me->heal(-(10));
   remove_property("magic");
	return 1;
    }
}
int agg_fun(object ob) {
    if ((string)TP->query_name() == "grazzt") {
	force_me ("bow");
	return 1;
    } else {
    set_property("magic",1);
	force_me("kill "+TP->query_name());
	force_me("scream "+TP->query_name());
        tell_object(TP,
	    "%^BOLD%^%^ORANGE%^The skeletal knight looks upon you and "
	    "drains your life essence!%^RESET%^"
	);
        TP->add_hp(-(random(20)+10));
        TP->do_damage("torso",0);
        TP->set_paralyzed(16,"You are weak from the draining!");
   remove_property("magic");
        return 1;
    }
}
void die(object ob) {
    message("environment",
	"%^RED%^%^BOLD%^The skeletal knight collapses in defeat"
	"!%^RESET%^"
    ,environment(TO));
    ::die(ob);
}
