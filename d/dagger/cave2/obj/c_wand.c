#include <std.h>
#include <daemons.h>

inherit OBJECT;
int uses;

void create() {
    ::create();
    set_name("wand of curses");
    set_id(({"wand", "curses", "wand of curses", "curser", "Wand of Curses"}));
    set_short("Blackened iron wand");
    set_long("This ancient iron wand has seen some abuse.  It has become blackened with a strange substance over time and resists all attempts at cleaning it.  Strange runes have been engraved on the side of the wand.");
    set_weight(1);
    set_value(400);
    uses = 2;
}

void init() {
    ::init();
    add_action("read_fcn", "read");
    add_action("curse_fcn", "curse");
}

void read_fcn(string str) {

    if(!str){
	return notify_fail("read what?");
    }
    if(str != "runes") return notify_fail("read what?");
    if (str == "runes") {
	write(
	  "You try to decipher the runes on the wand, and can make somthing out about cursing, but then again, the word 'warning' is quite evident.  You think it works by typing 'curse <target>'"
	);
	say(TPQCN+" reads the runes on the wand.");
	return 1;
    }
}

int curse_fcn(string str) {
    int value;
    int num;
    int i;
    int flag;
    object *inv;
    object item;
    object ob;
    if(TP->query_bound() || TP->query_unconscious()){
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!query_wielded()) return notify_fail("Wield it first?\n");
    uses--;

    if(!str) { return notify_fail("You've gotta use it on SOMTHING."); }

    if(!(ob = present(str,environment(TP)))) { return notify_fail("Point that somewhere useful, please."); }

    if(!TP->ok_to_kill(ob)){
      return notify_fail("Supernatural forces prevent your attack.\n");
    }

    if(!random(20)) {
	ob = TP;
	flag = 1;
    }

    if(!wizardp(TP)) {
	value = ((random((int)TP->query_level())/10)+1);
    } else {
	value = 5;
    }
    inv = all_inventory(ob);
    num = sizeof(inv);
    i = 0;

    if(!num) {
	write("There is nothing there to curse!");
	return 1;
    } else {
	item=inv[random(num)];
	while( !(item->query_wielded()) && !(item->query_worn()) && (i < 3) ) {
	    item=inv[random(num)];
	    i++;
	}
    }

    if( !(item->query_wielded()) && !(item->query_worn()) ) {
	write(
	  "The wand sputters and sends out kewl looking sparks, but doesn't do anything.\n"
	);
	say(
	  "The wand in "+TPQCN+"'s hand sends out a lot of sparks!"
	);
	return 1;
    }

    if (flag == 1) {
	message("my_action",
	  "The wand glows an eerie black color, and starts to shake.   The black from the wand flows from it and onto you, causing your "+item->query_short()+" to glow black!"
	  ,TP);
	message("other_action",
	  "The wand held by "+TPQCN+" glows black, and suddenly moves from the wand onto "+TP->query_possessive()+" "+item->query_short()+"!"
	  ,environment(ob),(({ob})));
	TP->set_paralyzed(4, "You are busy.");
	if( (ob->query_level() + random(20)) < (TP->query_level() + random(20))) {
	    item->set_property("enchantment", (-1*value));
	    uses--;
	    if((item->query_property("enchantment")) > 5) {
		item->remove_property("enchantment");
		item->set_property("enchantment", 5);
	    }
	    if((item->query_property("enchantment")) < -5) {
		item->remove_property("enchantment");
		item->set_property("enchantment", -5);
	    }
	    message("this_person",
	      "You are cursed!!"
	      ,TP);
	    message("other_p",
	      ""+ob->query_cap_name()+" is cursed!!!"
	      ,environment(TP), (({TP})));
	} else {
	    message("this_person",
	      "You resist the power of the wand!"
	      ,TP);
	    message("other_p",
	      ""+ob->query_cap_name()+" resists the power of the wand"
	      ,environment(TP), (({TP})));
	}
	if (uses <= 0) {
	    write("The wand disapears!!\n");
	    say("The wand disapears!!\n");
TP->kill_ob(ob, 1);
	    TO->remove();
	}
	return 1;

    } else {
	write(
	  "Your wand starts to glow black.  Suddenly a beam of pure blackness shoots from it and strikes "+ob->query_cap_name()+", turning  "+ob->query_possessive()+" "+item->query_short()+" black."
	);
	message("other_action",
	  "The wand in "+TPQCN+"'s hand glows black, then a beam of blackness shoots from it, striking "+ob->query_cap_name()+" and turning "+ob->query_possessive()+" "+item->query_short()+" black."
	  ,environment(ob),(({TP, ob})));
	message("his_action",
	  ""+TPQCN+" aims a strange wand at you.  The wand glows black, and a beam of pure blackness shoots from it turning your "+item->query_short()+" black."
	  ,ob);
	TP->set_paralyzed(4, "You are busy.");
	if( (ob->query_level() + random(20)) < (TP->query_level() + random(20))) {
	    item->set_property("enchantment", (-1*value));
	    uses--;
	    if((item->query_property("enchantment")) > 5) {
		item->remove_property("enchantment");
		item->set_property("enchantment", 5);
	    }
	    if((item->query_property("enchantment")) < -5) {
		item->remove_property("enchantment");
		item->set_property("enchantment", -5);
	    }
	    message("this_person",
	      "You are cursed!!"
	      ,ob);
	    message("other_p",
	      ""+ob->query_cap_name()+" is cursed!!!"
	      ,environment(ob), (({ob})));
	} else {
	    message("this_person",
	      "You resist the power of the wand!"
	      ,ob);
	    message("other_p",
	      ""+ob->query_cap_name()+" resists the curse."
	      ,environment(ob), (({ob})));
	}
	if (uses <= 0) {
TP->kill_ob(ob, 1);
	    write("The wand disapears!!\n");
	    say("The wand disapears!!\n");
	    TO->remove();
	}
	return 1;
    }
}
