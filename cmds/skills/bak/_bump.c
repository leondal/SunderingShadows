#include <std.h>

inherit DAEMON;

int cmd_bump(string str) {
    object ob;
    string *sorties;
    string former;
    int kplah;

    if(this_player()->query_ghost()) return 0;
    if(!str) {
        notify_fail("Bump whom?\n");
        return 0;
    }
    if(!(ob = present(lower_case(str), environment(this_player())))) {
        notify_fail("No "+capitalize(str)+" here.\n");
	return 0;
    }
    if(!living(ob)) {
        write("You bump the "+str+".\n");
    	say(this_player()->query_cap_name()+" bumps the "+str+".\n");
	return 1;
    }
    if(ob->query_property("no bump")) {
        write(ob->query_cap_name()+" growls at you.\n");
	say(ob->query_cap_name()+" growls at "+this_player()->query_cap_name()+" as "+this_player()->query_subjective()+" tries to push "+ob->query_objective()+".\n", ob);
	return 1;
    }
    if((int)this_player()->query_sp() < 20) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    kplah = (int)this_player()->query_stats("strength") -
      ((int)ob->query_stats("strength") + (int)ob->query_stats("dexterity"))/2;
    if(kplah < 1) {
        this_player()->add_hp(-(random(15)));
        this_player()->add_sp(-(random(20)));
	write(ob->query_cap_name()+" shoves you to the ground!\n");
	say(this_player()->query_cap_name()+" is shoved to the ground while trying to bump "+ob->query_cap_name()+".\n");
	tell_object(ob, this_player()->query_cap_name()+" is thrown to the ground while trying to bump you.\n");
	return 1;
    }
    kplah += random((int)ob->query_skill("melee"));
    if (kplah < random(101)) {
        write("The "+(string)ob->query_race()+" holds "+(string)ob->query_possessive()+" ground.\n");
	say(this_player()->query_cap_name()+" fails in an attempt to push "+ob->query_cap_name()+" aside.\n", ob);
	tell_object(ob, this_player()->query_cap_name()+" gives you a bit of a bruise trying to push you.\n");
	ob->add_hp(-(random(7)));
        this_player()->add_sp(-(random(10)));
	this_player()->add_hp(-(random(20)));
	return 1;
    }
    sorties = (string *)environment(ob)->query_destinations();
    write("You push the "+(string)ob->query_race()+" out of the way.\n");
    say(this_player()->query_cap_name()+" pushes "+ob->query_cap_name()+" out of the way.\n", ob);
    tell_object(ob, this_player()->query_cap_name()+" pushes you out of the way.\n");
    this_player()->add_hp(-(random(10)));
   this_player()->add_sp(-(random(10)));
    ob->add_hp(-(random(5)));
    former = file_name(environment(ob));
    ob->move(sorties[random(sizeof(sorties))]);
    if(!ob->is_player()) call_out("return_home", 14, ({ ob, former }) );
    return 1;
}

void return_home(mixed *borg) {
    borg[0]->move_player(borg[1], "angrily");
}

void help() {
    write("Syntax: <bump [enemy]>\n\n"
      "Allows you to push people out of the way, but you better be strong!\n");
}
