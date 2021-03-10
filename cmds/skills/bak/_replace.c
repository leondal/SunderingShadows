// 	_replace.c
//	Cleric ability for replacing lost limbs
//	created 02 November 1992 by Descartes of Borg

#include <std.h>

inherit DAEMON;

int check_alignment(object tp);
int add_limb(object ob, string limb);

int cmd_replace(string str) {
    string who, limb;
    string *missing;
    string *limbs;
    int healing;
    int cost;
    object tp, ob;

    if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in your immaterial state.\n");
        return 0;
    }
    if(!str) {
        notify_fail("Replace what?\n");
	return 0;
    }
    tp = this_player();
    if((string)tp->query_class() != "monk" && (string)tp->query_class() != "cleric") {
	notify_fail("You mutter words of nonsense.\n");
	return 0;
    }
    if(!check_alignment(tp)) {
    	notify_fail("You have betrayed the source of your powers!\n");
	return 0;
    }
    if(sscanf(str, "%s %s", who, limb) != 2) {
	notify_fail("Correct syntax: <replace [player] [limb]>\n");
	return 0;
    }
    ob = present(who, environment(tp));
    if(!ob) {
        notify_fail(capitalize(who) + " is not here.\n");
	return 0;
    }
    if(ob->query_ghost()) {
        notify_fail("You cannot help the dead in that way.\n");
	return 0;
    }
    if(!living(ob)) {
	notify_fail(ob->query_cap_name()+" is not a living thing!\n");
	return 0;
    }
    limbs = (string *)ob->query_limbs();
   missing = (string *)ob->query_severed_limbs();
    if(!missing) {
	if(ob==tp) notify_fail("You are not missing any limbs!\n");
	else notify_fail(ob->query_cap_name()+" is not missing any limbs.\n");
	return 0;
    }
    if(member_array(limb, missing) == -1) {
	if(tp==ob) notify_fail("You are not missing that limb!\n");
	else notify_fail(ob->query_cap_name()+" is not missing that limb!\n");
	return 0;
    }
    if(member_array(limb, limbs) != -1) {
	if(tp==ob) notify_fail("You are not missing that limb!\n");
	else notify_fail(ob->query_cap_name()+" is not missing that limb.\n");
	return 0;
    }
    this_player()->set_magic_round();
    healing = (int)tp->query_skill("healing");
    healing -= random(101);
    if(tp==ob) cost = 120;
    else cost = random(100) + 20;
    if((int)tp->query_mp() < cost) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    tp->add_mp(-cost);
    if(healing <1) {
	write("You concentration is simply too weak.\n");
	say(tp->query_cap_name()+" loses "+tp->query_possessive()+" concentration while in prayer.\n", tp);
	tp->add_skill_points("healing", 10);
	return 1;
    }
    if(!add_limb(ob, limb)) {
	notify_fail("A required limb is missing for that!\n");
	return 0;
    }
    if(tp==ob) {
	write("Your "+limb+" regenerates through prayer!\n");
	say(tp->query_cap_name()+"'s "+limb+" regenerates through prayer!\n", tp);
	tp->add_skill_points("healing", random(healing));
	tp->add_exp(random(healing));
    }
    else {
	write("You regenerate "+ob->query_cap_name()+"'s "+limb+" through prayer!\n");
	tell_object(ob, tp->query_cap_name()+" regenerates your "+limb+" through prayer!\n");
	tell_room(environment(tp), tp->query_cap_name()+" says a prayer that regenerates "+ob->query_cap_name()+"'s "+limb+".\n", ({ tp, ob }) );
	tp->add_skill_points("healing", healing);
	tp->add_exp(healing);
	tp->add_alignment(healing);
    }
    return 1;
}

int check_alignment(object tp) {
    int x;

    switch((string)tp->query_class()) {
	case "monk": if((int)tp->query_alignment() < 200) x=0; else x=1; break;
	case "cleric": if((int)tp->query_alignment()<0) x=0; else x=1; break;
	default: x=0; break;
    }
    return x;
}

int add_limb(object ob, string limb) {
    string *it;
    string correct;
    string *a;
    string *b;
  int x;

    a= ({ "right foot", "left foot", "right hand", "left hand" });
    b = ({ "right leg", "left leg", "right arm", "left arm" });
    if(member_array(limb, a) == -1 && member_array(limb, b) == -1) return 0;
    it = (string *)this_player()->query_limbs();
    switch(limb) {
	case "right hand": correct = "right arm"; break;
	case "right foot": correct = "right leg"; break;
	case "left hand": correct = "left arm"; break;
	case "left foot": correct = "left leg"; break;
	default:
	    correct = "ok";
	    x = member_array(limb, b);
	    break;
    }
    if(correct == "ok") {
	ob->add_limb(limb, a[x], (int)ob->query_max_hp()/3, 0, 0);
	return 1;
    }
    if(member_array(correct, it) == -1) return 0;
    ob->add_limb(limb, "", (int)ob->query_max_hp()/4, 0, 0);
    if(limb == "right hand" || limb == "left hand") ob->add_wielding_limb(limb);
    return 1;
}

void help() {
    write("Syntax: <replace [player] [limb]>\n\n"+
	"A prayer to regenerate the missing limb of a player.\n");
}
