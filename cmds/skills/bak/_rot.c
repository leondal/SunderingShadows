#include <std.h>

inherit DAEMON;

void send_messages(object tp, object ob, string class, string limb);

int cmd_rot(string str) {
    string whom, limb, class;
    int amount, cost, healing, i, wisdom;
    object tp, ob;
    string *limbs, *weakness, *strengths;

    this_player()->set_magic_round();
    if(this_player()->query_ghost()) return 0;
    if(!str) {
	notify_fail("Rot whom?\n");
	return 0;
    }
    tp = this_player();
    if(tp->query_casting()) {
	notify_fail("You are in the middle of another spell!\n");
	return 0;
    }
    if(environment(tp)->query_property("no attack")) {
        notify_fail("A magic force prevents your power.\n");
        return 0;
    }
    if(!alignment_ok(this_player())) {
	notify_fail("You have betrayed the source of your powers.\n");
	return 0;
    }
    healing = (int)tp->query_skill("healing");
    class = (string)tp->query_class();
        if(sscanf(str, "%s %s", whom, limb) != 2) {
	    notify_fail("Correct syntax: <rot [who] [limb]>\n");
    	    return 0;
  	}
	if(whom == "me" || whom == "myself") ob = tp;
	else ob = present(whom, environment(tp));
    if(!ob) {
	notify_fail("Rot whom?\n");
	return 0;
    }
    if(!living(ob)) {
        notify_fail("What? Rot that?\n");
        return 0;
    }
    if(!ob->kill_ob(tp, 0)) return 1;
    strengths = (string *)ob->query_property("strengths");
    if(strengths && member_array("magic", strengths) != -1) {
        write(ob->query_cap_name()+" resists your magic!\n");
        return 1;
    }
    weakness = (string *)ob->query_property("weakness");
    if(!weakness) weakness = ({});
    if(limb == "all") cost = 200;
    else if(member_array(limb, (string *)ob->query_limbs()) == -1) {
	notify_fail("You do not have a "+limb+".\n");
	return 0;
    }
    else if(limb == "head" || limb == "torso") cost = 90;
    else cost = 35;
    cost = cost/2 + random(cost/2);
    if((int)tp->query_mp() < cost) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    tp->add_mp(-cost);
    if(healing < 15) {
	notify_fail("You are not skilled enough to do that!\n");
	return 0;
    }
    if(limb == "all") {
        amount = (healing - (int)ob->query_stats("wisdom"))/3;
    }
    else {
        amount = (healing-(int)ob->query_stats("wisdom"))/2;
    }
    if(member_array("magic", weakness) != -1) amount += random(20);
	tp->add_skill_points("healing", amount * 2);
    if((int)ob->query_alignment() < -140) tp->add_alignment(amount/10);
    else tp->add_alignment(-5);
    if(limb == "all") {
	limbs = (string *)ob->query_limbs();
	for(i=0; i<sizeof(limbs); i++) {
	    ob->heal_limb(limbs[i], -(amount / 2));
	}
	send_messages(tp, ob, class, limb);
    }
    else {
        if(limb == "head" || limb == "torso") ob->heal_limb(limb, -(random(amount)));
	else ob->heal_limb(limb, -amount);
	send_messages(tp, ob, class, limb);
    }
    return 1;
}

void send_messages(object tp, object ob, string class, string limb) {
    string what, thing;

    if(class == "monk" || class == "cleric") {
	thing = "prayer";
	what = "a prayer of deathly rot";
    }
    else if(class == "mage") {
	thing = "magic";
	what = "a spell of deathly rot";
    }
    else {
	thing = "nonsense";
 	what = "nonsense";
    }
    if(tp == ob) {
	tell_object(tp, "You rot your own limbs through "+thing+".\n");
	tell_room(environment(tp), tp->query_cap_name() + " mutters "+what+".\n", ({tp}));
    }
    else {
	tell_object(tp, "You rot "+ob->query_cap_name()+"'s "+limb+" through "+thing+".\n");
	tell_object(ob, tp->query_cap_name()+" rots your "+limb+" through "+thing+".\n");
	tell_room(environment(tp), tp->query_cap_name()+" mutters "+what+".\n", ({tp, ob}));
    }
}


void help() {
    write("Syntax: <rot [enemy] [limb]>\n\n"
      "Brings a plague of rotting wounds onto the named limb of your\n"
      "opponent.  Casters of this spell should be careful indeed!  For\n"
      "the casting of this spell against the wrong people also rots\n"
      "the moral fiber which forms the base of your powers!\n"
      "Note: <all> can be used in place of <limb>\n"
    );
}
