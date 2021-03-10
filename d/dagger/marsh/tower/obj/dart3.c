#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit OBJECT;
void create() {
    ::create();
    set_name("dart");
    set("id",({"dart","steel dart","steel_dart_ob"}));
    set("short",
	"Steel dart"
    );
    set("long",
	"This steel dart is small, sharp and balanced for throwing perfectly. "
	"There is a small rune of confusion on the side of it."
    );
    set_value(500);
    set_weight(4);
}
void init(){
    ::init();
    add_action("throw_func","throw");
}
int throw_func(string str) {
    int dam;
    object ob;
    string who;	
    if(!userp(ETO)) return 0;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(environment(ETO))) return 0;
    if(!str) {
	notify_fail("Throw what at who?\n");
	return 0;
    }
    if(sscanf(str,"dart at %s",who) != 1) {
	notify_fail("Syntax: throw dart at <target>\n");
 	return 0;
    }
  if(ETO->query_bound() || ETO->query_unconscious()){
  ETO->send_paralyzed_message("info",ETO);
  return 1;
  }
    if(!(ob = present(who,environment(ETO)))) {
	notify_fail("No such target present!\n");
	return 0;
    }
    if(ob->query_property("no attack") || ob->query_property("no kill")) {
	notify_fail("You cannot attack that!\n");
	return 0;
    }   
    if(environment(ETO)->query_property("no attack")) {
        notify_fail("You cannot attack in this place!\n");
        return 0;
    }
    if(ETO->query_paralyzed() || ETO->query_disable()) return 0;
    if((int)ETO->query_level() < 20) {
	notify_fail("You are too inexperienced to use this item!\n");
	return 0;
    }
    if((int)ob->query_level() < 5) {	
	write("%^GREEN%^The dart misses!%^RESET%^");
	tell_object(ob,"%^GREEN%^"
	    +ETO->query_cap_name()+" hurls a dart at you, but it misses!%^RESET%^"
	);
	TO->remove();
	return 1;
    }
    if(!ETO->kill_ob(ob,0)) return 1;
    tell_object(ETO,"%^ORANGE%^"
	"You throw the dart towards "+ob->query_cap_name()+"!\n%^RED%^"
	"As the dart hits, "+ob->query_cap_name()+" gets a strange and confused look on "
	+ob->query_possessive()+
	" face!"
	"%^RESET%^"
    );
    tell_object(ob,"%^ORANGE%^"
	+ETO->query_cap_name()+" throws a dart towards you!\n%^RED%^"
	"As the dart hits you suddenly feel really strange and confused!%^RESET%^"
    );
    tell_room(environment(ETO),"%^ORANGE%^"
	+ETO->query_cap_name()+" throws a dart towards "+ob->query_cap_name()+"!\n%^RED%^"
	"As the dart hits, "+ob->query_cap_name()+" gets a strange and confused look on "
	+ob->query_possessive()+
	" face!%^RESET%^"
    ,({ETO,ob}));
    ETO->set_paralyzed(4,"You are busy hurling and watching the impressive dart!");
    dam = (int)ETO->query_level()/2;
    ob->set_paralyzed(random(dam)+(dam/3),"%^GREEN%^You are so confused you decide to remain really really still and maybe it will go away!%^RESET%^");
    TO->remove();
    return 1;
}
