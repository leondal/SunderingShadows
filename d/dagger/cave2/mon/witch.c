#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("Ogress shaman");
    set_short("Ogress shaman");
    set_id( ({"ogress", "shaman", "ogre", "ogress shaman", "witch", "cavemon"}) );
    set_property("always interact", 1);
    set_long(
      "This ancient ogress harnessed the powers of nature long ago.  Before the incursion of the Demons, she traveled to a far and unknown corner of the caves, and has set up shop here, to try to help those that are trying to free her brethren."
    );
    set_body_type("human");
    set_race("ogre-mage");
    set_gender("female");
    set_size(3);
    set_alignment(5);
    set_hd(3,0);
    set_max_hp(20);
    set_hp(20);
    set_exp(100);
}


void init() {
    ::init();
    add_action("remove_curse", "retract");
    add_action("identify_curse", "identify");
}

int remove_curse(string str){
    string item;
    object ob;
    int amount;

    if(!str) return notify_fail("Remove curse on what?");
    if(sscanf(str, "curse from %s",item) != 1) {
	tell_player(TP, "Syntax: remove curse from <item>");
	return 1;
    }
    if(!ob = present(item,TP)){
	tell_player(TP, "You do not have any "+item+".");
	return 1;
    } else {
	if(!ob->query_property("enchantment") || ob->query_property("enchantment") >= 0) {
	    return notify_fail("The "+item+" is not cursed.");
	}

amount = (((int)ob->query_property("enchantment")) * ((int)TP->query_lowest_level()) * -3000);
	if(TP->query_money("gold") < amount) {
	    return notify_fail("You will need "+amount+" gold to have the curse lifted.");
	}
	else {
	    TP->add_money("gold",-amount);
	    while((int)ob->query_property("enchantment") < 0) {
		ob->set_property("enchantment", 1);
	    }
	    tell_object(TP, "%^BOLD%^The "+item+" has had all of its curse removed.");
	}
    }
    return 1;
}

int identify_curse(string str){
    string item;
    object ob;

    if(!str) return notify_fail("Identify curse on what?");

    if(sscanf(str, "curse on %s",item) != 1) return notify_fail("Syntax: identify curse on <item>");

    if(!ob = present(item, TP))
	return notify_fail("You do not have any "+item+".");
    if(TP->query_money("gold") < 500)
	return notify_fail("You need 500 gold to pay for the identification.");
    else{
	TP->add_money("gold", -500);
	if(ob->query_property("enchantment") || ob->query_property("enchantment") >= 0)
	    tell_object(TP,"%^BOLD%^%^BLUE%^The "+item+" is not cursed!");
	else{
	    tell_object(TP,"%^BOLD%^%^BLUE%^The "+item+" is cursed!");
	}
    }
    return 1;
}
