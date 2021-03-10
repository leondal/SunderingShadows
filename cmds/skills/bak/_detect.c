//	_detect.c
//	Monk ability
//	created 04 November 1992 by Descartes of Borg

#include <std.h>

inherit DAEMON;

int check_alignment(object tp, string class);

int cmd_detect(string str) {
    object tp, ob;
    string prop, thing;
    int which, faith;

    tp = this_player();
    if(tp->query_ghost()) {
	notify_fail("You howl sadly.\n");
	return 0;
    }
    if(!str) {
	notify_fail("Detect what in what?\n");
	return 0;
    }
    if(sscanf(str, "%s in %s", prop, thing) != 2) {
	notify_fail("Correct syntax: <detect [property] in [object]>\n\n");
	return 0;
    }
    ob = present(thing, environment(tp));
    if(!ob) ob = present(thing, tp);
    if(!ob) ob = parse_objects(environment(tp), thing);
    if(!ob) ob = parse_objects(tp, thing);
    if(!ob) {
	notify_fail("No "+thing+" here!\n");
	return 0;
    }
    if((string)tp->query_class() != "monk" && (string)tp->query_class() != "cleric") {
	notify_fail("You mumble in confusion.\n");
	return 0;
    }
    if(!check_alignment(tp, (string)tp->query_class())) {
	notify_fail("You have betrayed the source of your powers.\n");
	return 0;
    }
    if((int)tp->query_mp() <10) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    write("You concentrate upon the "+ob->query_name()+".\n");
    say(tp->query_cap_name()+" concentrates upon the "+ob->query_name()+".\n", tp);
    tp->add_mp(-10);
    faith = (int)tp->query_skill("faith");
    this_player()->set_magic_round();
    if(faith < random(101)) {
	write("You fail to notice any "+prop+" in its aura.\n");
	tp->add_skill_points("faith", random(5));
    }
    else {
	if(!ob->query_property(prop)) {
	    write("You fail to notice any "+prop+" in its aura.\n");
	    tp->add_skill_points("faith", 10);
	    tp->add_exp(2);
	}
	else {
	    write("You definitely detect "+prop+" in its aura.\n");
	    tp->add_skill_points("faith", 15);
	    tp->add_exp(4);
	}
    }
    return 1;
}

int check_alignment(object tp, string class) {
   if(class == "monk" && (int)tp->query_alignment() < 200) return 0;
   else if(class == "cleric" && (int)tp->query_alignment() <0) return 0;
    return 1;
}

void help() {
    write("Syntax: <detect [property] in [item]>\n\n"+
	"Detects the presence of a hidden or magical property specified in an\n"+
	"object.  There is no way to tell the difference between failure\n"+
	"of the prayer or the absence of the property in the item.\n");
}
