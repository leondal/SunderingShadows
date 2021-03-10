//	_sense.c
//	Monk/Kataan ability
//	created by Descartes 21 October 1992
//      slightly modified by Bohemund 14 January 1994

#include <std.h>

inherit DAEMON;

int cmd_sense(string str) {
    object ob;
    object *inv;
    int i, skip, which, faith;
    string what, class;
    mixed *arr;

    if(!str) {
	notify_fail("Sense what?\n");
	return 0;
    }
    class = (string)this_player()->query_class();
    if(class != "monk" && class != "kataan") {
	notify_fail("Your mind swirls in chaos.\n");
	return 0;
    }
    if(class == "monk") {
      if((int)this_player()->query_alignment() < 200) {
	notify_fail("You fail to sense anything special about it.\n");
	return 0;
      }
    }
    if(class == "kataan") {
      if((int)this_player()->query_alignment() > -200) {
	notify_fail("You fail to sense anything special about it.\n");
	return 0;
      }
    }
    ob = present(str, this_player());
    if(!ob) {
	inv = all_inventory(this_player());
	if(sscanf(str, "%s %d", what, which) != 2) {
	    notify_fail("You don't have that!\n");
	    return 0;
	}
	for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
	    if(inv[i]->id(what)) {
		skip ++;
		if(skip == which) ob = inv[i];
	    }
	}
	if(!ob) {
	    notify_fail("You don't have that!\n");
	    return 0;
	}
    }
    faith = (int)this_player()->query_skill("faith");
    if((int)this_player()->query_mp() < 13) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    say(this_player()->query_cap_name()+" mutters a prayer as "+this_player()->query_subjective()+" concentrates on the "+(string)ob->query_name()+".", this_player());
    this_player()->set_magic_round();
    if(faith < random(101)) {
	this_player()->add_mp(-13);
	this_player()->add_skill_points("faith", random(13));
	write("You fail to sense anything special about it.");
	return 1;
    }
    else {
	this_player()->add_mp(-13);
	this_player()->add_skill_points("faith", 13);
	arr = (string *)ob->query_property("magic item");
	if(!arr) write("You fail to sense anything special about it.");
	else if(arr == ({})) write("You fail to sense anything special about it.");
	else write("You sense magic about it...\nYou sense the "
		   "word \"%^BOLD%^"+arr[random(sizeof(arr))]+"%^RESET%^\".");
	return 1;
    }
}

void help() {
    write("Syntax: <sense [item]>\n\n"
	"Allows a monk or a kataan to sense any magic powers "
	"inherent in an object. "
	"There is no way to tell the difference between a failure to sense "
	"magic in the object and the lack of magic in an object.\n");
}
