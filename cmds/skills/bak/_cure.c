#include <std.h>

inherit DAEMON;

void send_messages(object tp, object ob, string class, string limb);

int cmd_cure(string str) {
    string whom, limb, class;
    int amount, cost, healing, i, wisdom;
    object tp, ob;
    string * limbs;

    if(!str) {
	notify_fail("Cure whom?\n");
	return 0;
    }
    tp = this_player();
    if(tp->query_casting()) {
	notify_fail("You are in the middle of another spell!\n");
	return 0;
    }
    if(!alignment_ok(this_player())) {
	notify_fail("You have betrayed the source of your powers.\n");
	return 0;
    }
    healing = (int)tp->query_skill("healing");
    class = (string)tp->query_class();
    if(str == "me" || str == "myself") ob = tp;
    else ob = present(str, environment(tp));
    if(!ob) {
        if(sscanf(str, "%s %s", whom, limb) != 2) {
	    notify_fail("Correct syntax: <cure [who] [(limb)]\n");
    	    return 0;
  	}
	if(whom == "me" || whom == "myself") ob = tp;
	else ob = present(whom, environment(tp));
    }
    if(!ob) {
	notify_fail("Cure whom?\n");
	return 0;
    }
    if(!ob->is_player()) {
	notify_fail("Nah... it does not need healing.\n");
	return 0;
    }
    if(!limb) cost = 90;
    else if(limb == "all") cost = 180;
    else if(member_array(limb, (string *)ob->query_limbs()) == -1) {
        notify_fail("That limb is missing!\n");
	return 0;
    }
    else cost = 50;
    if(ob != tp) cost = random(cost);
    if((int)tp->query_mp() < cost) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    tp->add_mp(-cost);
    if(healing < 15) {
	notify_fail("You are not skilled enough to do that!\n");
	return 0;
    }
    if(!limb) {
	amount = (healing*((int)ob->query_max_hp()))/100;
    }
    else if(limb == "all") {
	amount = ((healing*((int)ob->query_max_hp()))/100)/2;
    }
    else {
	amount = (healing*((int)ob->query_dam(limb)))/100;
    }
    this_player()->set_magic_round();
    if(amount > (int)ob->query_max_hp() - (int)ob->query_hp())
      amount = (int)ob->query_max_hp() - (int)ob->query_hp();
    if(tp == ob) tp->add_skill_points("healing", amount);
    else {
	tp->add_skill_points("healing", amount * 2);
        if(amount <200) tp->add_alignment(amount/10);
        else tp->add_alignment(random(50));
	if(amount > 200) {
    log_file("hmmm", this_player()->query_name()+" healing "+ob->query_short()+" "+amount+"\n");
	    amount = 200;
   	}
        if(amount > 200) tp->add_exp(random(200));
        else tp->add_exp(random(amount));
    }
    if(!limb) {
	ob->add_hp(amount);
	send_messages(tp, ob, class, 0);
    }
    else if(limb == "all") {
	limbs = (string *)ob->query_limbs();
	for(i=0; i<sizeof(limbs); i++) {
	    ob->heal_limb(limbs[i], (amount / 2));
	}
	ob->add_hp(amount / 2);
	send_messages(tp, ob, class, limb);
    }
    else {
	ob->heal_limb(limb, amount);
	send_messages(tp, ob, class, limb);
    }
    return 1;
}

void send_messages(object tp, object ob, string class, string limb) {
    string what, thing;

    if(class == "monk" || class == "cleric") {
	thing = "prayer";
	what = "a prayer of healing";
    }
    else if(class == "mage") {
	thing = "magic";
	what = "a spell of healing";
    }
    else {
	thing = "nonsense";
 	what = "nonsense";
    }
    if(tp == ob) {
	tell_object(tp, "You cure your own wounds through "+thing+".");
	tell_room(environment(tp), tp->query_cap_name() + " mutters "+what+".", ({tp}));
    }
    else {
	tell_object(tp, "You cure "+ob->query_cap_name()+"'s wounds through "+thing+".");
	tell_object(ob, tp->query_cap_name()+" cures your wounds through "+thing+".");
	tell_room(environment(tp), tp->query_cap_name()+" mutters "+what+".", ({tp, ob}));
    }
}

void help() {
    write("Syntax: <cure [player] [(limb)]>\n\n"+
	"Cures the player named to a degree depending on your skill level.  If no\n"+
	"limb is given, it heals hp.  Otherwise it heals the limb named.  The arg \"all\"\n"+
	"is a valid arg for the limb.\n");
}
