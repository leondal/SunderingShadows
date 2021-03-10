//	_pick.c
//	Rogue ability
//	created 04 November 1992 by Descartes of Borg

#include <std.h>

inherit DAEMON;

int cmd_pick(string str) {
    object ob, tp;
    int steal, resist;
    int platinum, gold, electrum, silver, copper;

    tp = this_player();
    if(tp->query_ghost()) {
	notify_fail("You cannot do that in your immaterial state.\n");
	return 0;
    }
    if(environment(this_player())->query_property("no steal")) {
	notify_fail("A magic force prevents you from doing that.\n");
	return 0;
    }
    if(!str) {
	notify_fail("Pick whom?\n");
	return 0;
    }
    if(tp->query_current_attacker()) {
	notify_fail("You can't do that while in combat!\n");
	return 0;
    }
    ob = present(str, environment(tp));
    if(!ob) ob = parse_objects(environment(tp), str);
    if(!ob) {
	notify_fail("No "+str+" here!\n");
	return 0;
    }
    if(!living(ob)) {
	notify_fail(capitalize(str)+" is not a living thing!\n");
	return 0;
    }
    if(wizardp(ob)) {
	notify_fail("That is not adviseable.\n");
	return 0;
    }
    if(ob->is_player() && !interactive(ob)) return 0;
    if(ob==tp) {
	notify_fail("You cannot pick your own purse!\n");
	return 0;
    }
    if(tp->query_disable()) return 1;
    tp->set_disable();
    steal = (int)tp->query_skill("stealing");
    resist = (int)ob->query_skill("stealing");
    resist += (int)ob->query_stats("dexterity");
    steal -= random(resist);
    if(steal <10) {
	write("You utterly fail in your attempt to pick from "+ob->query_cap_name()+".");
	tell_object(ob, "You catch "+tp->query_cap_name()+" trying to pick your purse!");
	tell_room(environment(tp), "You notice "+tp->query_cap_name()+" trying to pick "+ob->query_cap_name()+"'s purse!", ({ ob, tp }));
	if((string)ob->query_class() != "rogue") {
	    ob->add_skill_points("stealing", random(10));
	    ob->add_alignment(-2);
	}
	if(!ob->is_player()) ob->kill_ob(tp, 0);
	return 1;
    }
    steal = random(steal);
    if(steal < 10) {
	write("You fail in your attempt to pick from "+ob->query_cap_name()+".");
	tell_room(environment(tp), "You notice "+tp->query_cap_name()+" attempt to pick "+ob->query_cap_name()+"'s purse.", ({tp, ob}) );
	if((string)ob->query_class() != "rogue") {
	    ob->add_skill_points("stealing", 10);
	    ob->add_alignment(-5);
	}
	return 1;
    }
    if(steal < 20) {
	write("You fail in your attempt to pick from "+ob->query_cap_name()+".");
	if((string)ob->query_class() != "rogue") {
	    ob->add_skill_points("stealing", 15);
	    ob->add_alignment(-10);
	}
	return 1;
    }
    platinum = (int)ob->query_money("platinum");
    gold = (int)ob->query_money("gold");
    electrum = (int)ob->query_money("electrum");
    silver = (int)ob->query_money("silver");
    copper = (int)ob->query_money("copper");
    if(!platinum && !gold && !electrum && !silver && !copper) {
        tp->add_skill_points("stealing",20);
        tp->add_alignment(-15);
	notify_fail(ob->query_cap_name()+" is flat broke!\n");
	return 0;
    }
    platinum = (steal*(platinum/10))/100;
    gold = (steal*(gold/10))/100;
    electrum = (steal*(electrum/10))/100;
    silver = (steal*(silver/10))/100;
    copper = (steal*(copper/10))/100;
    if(!platinum && !gold && !silver && !electrum && !copper) {
	write("You fail to get anything from "+ob->query_cap_name()+"'s purse.");
	if((string)ob->query_class() != "rogue") {
	    tp->add_skill_points("stealing", 20);
	    tp->add_alignment(-15);
	}
	return 1;
    }
    ob->add_money("platinum", -platinum);
    ob->add_money("gold", -gold);
    ob->add_money("electrum", -electrum);
    ob->add_money("silver", -silver);
    ob->add_money("copper", -copper);
    tp->add_money("platinum", platinum);
    tp->add_money("gold", gold);
    tp->add_money("electrum", electrum);
    tp->add_money("silver", silver);
    tp->add_money("copper", copper);
    write("You pick some money from "+ob->query_cap_name()+"'s purse.");
    gold = gold + platinum*10 + electrum/10 + silver/50 + copper/100;
    if((int)tp->query_skill("stealing") > random(101)) {
	if((string)ob->query_class() == "rogue") return 1;
	tp->add_skill_points("stealing", 20+gold);
	tp->add_exp(20);
	tp->add_alignment(-20);
	return 1;
    }
    tell_object(ob, "You feel someone brush up against you.");
    if((string)ob->query_class() == "rogue") return 1;
    tp->add_skill_points("stealing", random(gold+20));
    tp->add_exp(20);
    tp->add_alignment(-20);
    return 1;
}

void help() {
    write("Syntax: <pick [living]>\n\n"+
	"Picks the pocket of the living being named as a target.\n");
}
