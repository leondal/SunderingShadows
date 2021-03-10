//	_protect.c
//	Monk and Cleric ability
//	written by Descartes 081192

#include <std.h>

inherit DAEMON;

int check_alignment(object tp);

int cmd_protect(string str) {
    object ob;
    int cost;
    int defense;
    string limb, who;

     if(!str) {
	notify_fail("Protect whom?\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 25) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(sscanf(str, "%s %s", who, limb) != 2) {
        limb = str;
        who = 0;
    }
    if(environment(this_player())->query_property("no magic")) {
	notify_fail("Something is blocking your concentration.\n");
	return 0;
    }
    if((string)this_player()->query_class() == "monk" || (string)this_player()->query_class() == "cleric") {
	if(!check_alignment(this_player())) {
	    notify_fail("You have betrayed the source of your powers.\n");
	    return 0;
	}
    }
    if(!who) ob = this_player();
    else ob = present(who, environment(this_player()));
    if(!ob) {
	notify_fail("No "+str+" here!\n");
	return 0;
    }
    if(!living(ob)) {
	notify_fail(ob->query_cap_name()+" is not a living thing.\n");
	return 0;
    }
    defense = (int)this_player()->query_skill("magic defense");
    if(member_array(limb, (string *)ob->query_limbs()) == -1) {
	if(ob == this_player()) write("You have no such limb!\n");
        else write(ob->query_cap_name()+" has no such limb!\n");
        return 1;
    }
    this_player()->set_magic_round();
    ob->add_magic_protection( ({ limb, (1+defense/10), random(defense*10) }));
    if(ob == this_player()) {
        this_player()->add_mp(-20);
        this_player()->add_skill_points("magic defense", random(30));
    }
    else {
        this_player()->add_mp(-10);
        this_player()->add_skill_points("magic defense", 30);
        this_player()->add_exp(30);
        this_player()->add_alignment(10);
    }
    write("You mutter a prayer of protection.\n");
    say(this_player()->query_cap_name()+" mutters a prayer of protection.\n", this_player());
    return 1;
}

void remove_spell(mixed *arr) {
    if(!arr[0]) return;
    arr[0]->add_magic_protection(arr[1], -arr[2]);
    tell_object(arr[0], "The magical protection had faded.\n");
}

int check_alignment(object ob) {
    if((int)ob->query_alignment() > 200) return 1;
    if((string)ob->query_class() == "cleric" && (int)ob->query_alignment() >0) return 1;
    return 0;
}

void help() {
    write("Syntax: <protect [(who)] [limb]>\n\n"+
        "A prayer to add magical protection to a specified limb.\n"+
        "When no player or monster is specified, the caster is considered\n"+
        "the benificiary.  Recipient must be specified with a limb that has\n"+
        "a name greater than one word.\n");
}
