#include <std.h>

inherit DAEMON;

int cmd_boost(string str) {
    string whom, limb, class;
    int amount, cost, healing, i, wisdom;
    object ob;
    string * limbs, thing, what;

    if(!str) {
	notify_fail("Boost whom?\n");
	return 0;
    }
    if(this_player()->query_casting()) {
	notify_fail("You are in the middle of another spell!\n");
	return 0;
    }
    if(!alignment_ok(this_player())) {
        notify_fail("You have betrayed the source of your powers.\n");
        return 0;
    }
    if((string)this_player()->query_name() == "guest" ||
        this_player()->query_ghost()) {
        notify_fail("You cannot do that.\m");
        return 0;
    }
    healing = (int)this_player()->query_skill("healing");
    wisdom = (int)this_player()->query_stats("wisdom");
    class = (string)this_player()->query_class();
    if(str == "me" || str == "myself") ob = this_player();
    else ob = present(str, environment(this_player()));
    if(!ob) {
	notify_fail("Boost whom?\n");
	return 0;
    }
    cost = 10;
    if(ob != this_player()) cost = random(cost);
    if((int)this_player()->query_mp() < cost) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    this_player()->set_magic_round();
    this_player()->add_mp(-cost);
    amount = random(wisdom/2 + 2) + healing/10;
    if(this_player() == ob) this_player()->add_skill_points("healing", amount);
	else this_player()->add_skill_points("healing", amount * 2);
	this_player()->add_alignment(amount);
	ob->add_sp(amount / 2);
    if(class == "monk" || class == "cleric") {
	thing = "prayer";
	what = "a prayer of healing";
    }
    else if(class == "mage" || class == "kataan") {
	thing = "magic";
	what = "a spell of healing";
    }
    else {
	thing = "nonsense";
 	what = "nonsense";
    }
    if(this_player() == ob) {
	tell_object(this_player(), "You boost your own power through "+thing+".");
	tell_room(environment(this_player()), this_player()->query_cap_name() + " mutters "+what+".", ({this_player()}));
    }
    else {
	tell_object(this_player(), "You boost "+ob->query_cap_name()+"'s power through "+thing+".");
	tell_object(ob, this_player()->query_cap_name()+" boosts your power through "+thing+".");
	tell_room(environment(this_player()), this_player()->query_cap_name()+" mutters "+what+".", ({this_player(), ob}));
    }
    return 1;
}

void help() {
    write("Syntax: <boost [friend]>\n\n"
      "Allows you to boost the power of those feeling kinda weak.\n"
    );
}
