#include <std.h>
#include <daemons.h>
inherit OBJECT;
int charges;
void create() {
    ::create();
    set_name("wand");
    set("id",({"wand","frost wand","wand of frost"}));
    set("short",
	"%^BLUE%^Wand %^BOLD%^%^WHITE%^of "
	"%^RESET%^%^BLUE%^F%^BOLD%^%^BLUE%^r%^WHITE%^"
	"o%^BLUE%^s%^RESET%^%^BLUE%^t%^RESET%^"
    );
    set("long",
   "This wand has snow-covered runes along its surface and is "
	"very cold to the touch. The words `storm' and `icekyz' are "
	"written among the runes."
    );
    set_value(1000);
    set_weight(10);
    charges=random(80)+20;
}
void init(){
    ::init();
    add_action("icekyz","icekyz");
    add_action("storm","storm");
}
int icekyz(string str) {
    string dam;
    object ob;
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
    if(!query_wielded()) return notify_fail("Wield it first?\n");

     if(!TP->is_class("mage") && !TP->is_class("bard")){
	notify_fail("You are incapable of operating the wand!");
	return 0;
    }
    if((int)TP->query_level() < 15) {
	notify_fail("You are not skilled enough at the magical arts "
	    "to operate the wand!");
	return 0;
    }
    if(!str) {
	notify_fail("You failed to select a target for the wand.\n");
	return 0;
    }
    if(!(ob = present(str,environment(TP)))) {
	notify_fail("Not a valid target.\n");
	return 0;
    }
    if(charges<1) {
	tell_object(TP,
	    "The wand crackles and fizzles...but does nothing else!"
	);
	return 1;
    }
    if(wizardp(ob)) {
	notify_fail("You may not use this item on immortals!\n");
	return 0;
    }
    charges -=2;
    TP->set_paralyzed(8,"You are using the wand of frost.");
    tell_room(ETP,
	"%^BLUE%^%^BOLD%^A cone of frost shoots from the wand held "
	"by "+TPQCN+" and engulfs "+ob->query_cap_name()+"!"
    ,({TP,ob}));
    tell_object(TP,
	"%^BOLD%^%^WHITE%^You mutter the words and a cone of frost "
	"leaves the wand and heads towards "+ob->query_cap_name()+"!"
    );
    tell_object(ob,
	"%^WHITE%^%^BOLD%^You hear "+TPQCN+" mutter some words and "
	"point a wand at you. A cone of frost leaves the wand headed "
	"for you!%^RESET%^"
    );
    if("daemon/saving_d"->saving_throw(ob,"rod_staff_wand")) {
        dam="slight";
    } else {
        dam="heavy";
    }
    tell_object(ob,
        "%^BLUE%^%^BOLD%^The cone of frost strikes you doing "
	+dam+" to you!%^RESET%^"
    );
    tell_room(environment(ob),
	"%^WHITE%^%^BOLD%^The cone of frost strikes "
	+ob->query_cap_name()+" doing "+dam+" damage to them!%^RESET%^"
    ,ob);
    if(!ob->kill_ob(TP,0)) TP->kill_ob(ob,0);
    if(dam == "heavy") {
	ob->do_damage("torso",roll_dice(6,6));
    } else {
	ob->do_damage ( "torso", (( roll_dice ( 6,6 ) ) / 2 ));
    }
    if(charges<1) {
	set_short("A wand (broken)");
	set_long(
	    "What used to be a powerful wand is now just a nice trinket."
	);
    }
    return 1;
}
int storm() {
    object here,sucker,*players;
    object ob;
    string dam;
    int x,num_p;
    if(TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()){
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
    if(!query_wielded()) return notify_fail("Wield it first?\n");

    if((int)TP->query_level() < 15) {
	notify_fail("No your far to inexperienced to use this. ACME wand co. doubts you even got it on your own...perhaps give it back.");
	return 0;
    }
      if(!TP->is_class("mage") && !TP->is_class("bard")){
	notify_fail("You have no magical talent!");
	return 0;
    }
    if(TP->query_paralyzed() || TP->query_disable()) return 0;
    if(charges<1) {
	tell_object(TP,"The wand fizzles and sparks..but nothing happens.");
	return 1;
    }
    charges -= 1;
    tell_object(TP,
	"%^WHITE%^%^BOLD%^You call forth a terrible ice storm from "
	"the wand!%^RESET%^"
    );
    if(!(userp(environment(TO)))) {
        return 0;
    }
    here=environment(environment(TO));
    players=all_inventory(here);
    num_p=sizeof(players);
    for (x=0;x<num_p;x++) {
        sucker=players[x];
	ob=sucker;
	if(living(sucker) && sucker != TP && !wizardp(sucker)) {
            if ("daemon/saving_d"->saving_throw(ob,"rod_staff_wand")){
		dam="heavily damaging";
	    } else {
		dam="maiming massively";
	    }
	    if(!ob->kill_ob(TP,0)) TP->kill_ob(ob,0);
	    tell_object(TP,
		"%^BOLD%^%^WHITE%^The storm you summon grows in "
		"power and leaves the wand in an onslaught, "+dam+
		" "+ob->query_cap_name()+"!"
	    );
	    tell_object(ob,
	        "%^BOLD%^WHITE%^A great storm is summoned from "
		+TPQCN+"'s wand and fills the area "+dam+
		" you!/n%^RESET%^"
	    );
	    if(dam == "maiming massively") {
		ob->do_damage("torso",roll_dice(3,10));
	    } else {
	        ob->do_damage("torso",((roll_dice(3,10))/2));
	    }
	}
    }
    TP->set_paralyzed(8,"You are using the wand!\n");
    return 1;
}
