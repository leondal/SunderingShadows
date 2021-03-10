//	_dispell.c
//	Monk and Cleric ability
//	written 151092 by Descartes of Borg

#include <std.h>

inherit DAEMON;

int dispell_all(object tp);

int cmd_dispell(string str) {
    int which, skip, i, faith, wisdom, cost;
    string whom, cl;
    object tp, ob;
    object *inv;

    this_player()->set_magic_round();
    if(!str) {
        if(!(ob=(object)this_player()->query_current_attacker())) {
            notify_fail("Dispell whom?\n");
            return 0;
        }
    }
    tp = this_player();
    if((cl = (string)this_player()->query_class()) != "monk" &&
      cl != "cleric" && cl != "kataan") {
	notify_fail("You feel confused.\n");
	return 0;
    }
    if(!alignment_ok(this_player())) {
	notify_fail("You have betrayed the source of your powers.\n");
	return 0;
    }
    if(tp->query_casting()) return 1;
    if(environment(tp)->query_property("no magic")) {
	notify_fail("Something is blocking your concentration.\n");
	return 0;
    }
    if(str == "all") return dispell_all(tp);
    if(!ob) ob = present(str, environment(tp));
    if(!ob) {
    	inv = all_inventory(environment(tp));
	sscanf(str, "%s %d", whom, which);
	for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
	    if(inv[i]->id(whom)) {
		skip ++;
		if(skip == which) ob = inv[i];
	    }
	}
	if(!ob) {
	    notify_fail("Dispell whom?\n");
	    return 0;
	}
    }
    if(!living(ob)) {
	notify_fail(ob->query_cap_name()+" is not a living thing!\n");
	return 0;
    }
    if(cl == "kataan" && (int)ob->query_alignment() < 0) {
	write(ob->query_cap_name()+" is not good!\n");
	tp->add_alignment(10);
	tp->add_mp(-5);
	return 1;
    }
    else if(cl != "kataan" && (int)ob->query_alignment() > 0) {
      write(ob->query_cap_name()+" is not evil!\n");
      this_player()->add_alignment(-10);
      this_player()->add_mp(-5);
      return 1;
    }
    if(!ob->kill_ob(tp, 0)) return 1; /* hack by Val to keep out PK */
    faith = (int)tp->query_skill("faith");
    wisdom = (int)ob->query_stats("wisdom");
    faith -= wisdom;
    if(faith < 2) faith = 2;
    faith = random(faith);
    cost = faith/2 + faith/7;
    if((int)tp->query_mp() < cost) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    tp->add_mp(-cost);
    tp->set_casting(faith);
    say(tp->query_cap_name()+" mutters a prayer against enemies of the faith.\n");
    write("You mutter a prayer against enemies of the faith.\n");
    tell_room(environment(tp), ob->query_cap_name()+" is struck by the force of "+tp->query_cap_name()+"'s faith!\n", ({tp, ob }) );
    tell_object(ob, "You are struck by the force of "+tp->query_cap_name()+"'s faith.\n");
    write(ob->query_cap_name()+" is struck by the force of your faith.\n");
    tp->add_skill_points("faith", faith);
    return 1;
}

int dispell_all(object tp) {
    object *inv;
    mixed *who;
    int faith, wisdom, i, cost, tot;

    who = ({});
    faith = (int)tp->query_skill("faith");
    tot = faith;
    if(faith < 20) {
	notify_fail("Your faith is not strong enough.\n");
	return 0;
    }
    inv = all_inventory(environment(tp));
    if((string)this_player()->query_class() == "kataan") {
      for(i=0; i<sizeof(inv); i++)
        if(living(inv[i]) && (int)inv[i]->query_alignment()>0) who+=({inv[i]});
    }
    else {
      for(i=0; i<sizeof(inv); i++) {
	  if(living(inv[i]) && (int)inv[i]->query_alignment() < 0) who += ({ inv[i] });
      }
    }
    if(who == ({})) {
        if((string)this_player()->query_class() == "kataan")
          write("Nothing good around here!\n");
        else write("Nothing evil around here!\n");
	tp->add_mp(-5);
	return 1;
    }
    for(i=0; i<sizeof(who); i++) {
	wisdom = (int)who[i]->query_skills("wisdom");
	faith = tot - wisdom;
	if(faith < 2) faith = 2;
	faith = random(faith);
	cost = faith/3 + faith/7;
	if((int)tp->query_mp() < cost) {
		notify_fail("Too low on magic power.\n");
		return 0;
	}
	if(!who[i]->kill_ob(tp, 0)) continue; /* hack by Val to keep out PK */
	tp->add_mp(-cost);
	who[i]->add_hp(-faith);
	write(who[i]->query_cap_name()+" is struck by the force of your faith.\n");
	tell_room(environment(tp), who[i]->query_cap_name()+" is struck by the force of "+tp->query_cap_name()+"'s faith.\n", ({ who[i], tp }));
  	tell_object(who[i], "You are struck by the force of "+tp->query_cap_name()+"'s faith.\n");
	tp->add_skill_points("faith", faith);
    }
    tp->set_casting(faith/5+1);
    return 1;
}
void help() {
    write("Syntax: <dispell [enemy]> or <dispell all>\n\n"
      "This prayer of faith does damage to the enemies of your faith.\n"
      "It naturally taxes you more to cast upon on all enemies in a room\n"
    );
}
