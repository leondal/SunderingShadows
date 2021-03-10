//   _mheal.c
//   Author:  Hanse (with original code from _heal.c made by Descartes)
//   Date: 8-Nov-92
//   Modified by Bohemund to restrict it for use only by clerics,
//   ansi was added as well.
//   Date: 10-Jan-94

#include <std.h>

inherit DAEMON;

void send_messages(object tp, object ob, string limb);

int cmd_mheal(string str) {
    string whom, limb;
    int amount, cost, healing, i, wisdom;
    object tp, ob;
    string * limbs;

    if(!str) {
        notify_fail("Heal whom?\n");
        return 0;
    }
    tp = this_player();
    if(tp->query_casting()) {
        notify_fail("You are in the middle of another spell!\n");
        return 0;
    }
    if((string)tp->query_class() != "cleric") {
      notify_fail("Only clerics may use such powerful curative magic.\n");
      return 0;
    }
    if((int)tp->query_alignment() < 750) {
        notify_fail("You have betrayed the source of your powers.\n");
        return 0;
    }
    healing = (int)tp->query_skill("healing");
    wisdom = (int)tp->query_stats("wisdom");
    ob = find_player(str);
    if(!ob) {
        if(sscanf(str, "%s %s", whom, limb) != 2) {
            notify_fail("Correct syntax: <heal [who] [(limb)]\n");
            return 0;
        }
        ob = find_player(whom);
    }
    if(!ob) {
        notify_fail("Heal whom?\n");
        return 0;
    }
    if(ob == tp)
    {
        notify_fail("This spell is only for healing over long distances.\n");
        return 0;
    }
    if(!limb) cost = 22;
    else if(limb == "all") cost = 44;
    else if(member_array(limb, (string *)ob->query_limbs()) == -1) {
        notify_fail("The target does not have a(n) "+limb+" limb.\n");
        return 0;
    }
    else cost = 14;
    if(ob != tp) cost = random(cost) + 10;
    if((int)tp->query_mp() < cost) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    tp->add_mp(-cost);
    if(healing < 5) amount = 0;
    else amount = random(wisdom + (healing/10));
    tp->add_skill_points("healing", amount * 2);
    tp->add_alignment(amount);
    this_player()->set_magic_round();
    tp->add_exp(random((amount/2)+2));
    if(!limb) {
        ob->add_hp(amount);
        send_messages(tp, ob, 0);
    }
    else if(limb == "all") {
        limbs = (string *)ob->query_limbs();
        for(i=0; i<sizeof(limbs); i++) {
            ob->heal_limb(limbs[i], (amount / 2));
        }
        ob->add_hp(amount / 2);
        send_messages(tp, ob, limb);
    }
    else {
        ob->heal_limb(limb, amount);
        send_messages(tp, ob, limb);
    }
    return 1;
}

void send_messages(object tp, object ob, string limb) {
    string what, thing;
    thing = "prayer";
    what = "a prayer of healing";
    tell_object(tp, "%^GREEN%^%^BOLD%^You heal "+ob->query_cap_name()+
		"'s wounds through "+thing+".");
    tell_object(ob, "%^GREEN%^%^BOLD%^"+tp->query_cap_name()+
		" heals your wounds through "+thing+".");
    tell_room(environment(tp), "%^GREEN%^%^BOLD%^"+tp->query_cap_name()+
	      " mutters "+what+".", ({tp, ob}));
}

void help() {
    write("Syntax: <heal [player] [(limb)]>\n\n"
"Heals the player named over a distance.  If no limb is given, then "
"it heals hp.  Otherwise it heals the limb named.  The argument \"all\" "
"is a valid argument for the limb.  This heal is very expensive sp "
"wise and is usable only by clerics who have proven their goodness.\n");
}
