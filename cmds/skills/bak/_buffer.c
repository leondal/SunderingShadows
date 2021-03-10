//	/bin/user/_buffer.c
//	from the Nightmare mudlib
//	A powerful cleric/mage ability
//	created by Descartes of Borg 24 february 1993

#include <std.h>

inherit DAEMON;
 
int cmd_buffer(string str) {
    object ob;
    int defense;
    int cost;
 
    this_player()->set_magic_round();
    if(!str) {
        notify_fail("Cast a buffer on whom?\n");
        return 0;
    }
    ob = present(str, environment(this_player()));
    if(!ob) {
	if(str == "me" || str == "myself") ob = this_player();
    }
    if(!ob) {
        notify_fail(capitalize(str)+" is not here.\n");
        return 0;
    }
    if(!living(ob)) {
        notify_fail(capitalize(str)+" is not alive!\n");
        return 0;
    }
    if(environment(this_player())->query_property("no magic")) {
	notify_fail("Something is blocking your concentration.\n");
	return 0;
    }
    if(ob == this_player()) cost = 20 + random(150);
    else cost = 20 + random(75);
    if((int)this_player()->query_mp() < cost) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    defense = (int)this_player()->query_skill("magic defense");
    if(defense < 25) {
        write("You mutter words beyond your understanding.");
        say(this_player()->query_cap_name()+" mutters words beyond "+
          this_player()->query_possessive()+" understanding.", this_player());
        return 1;
    }
    if(!alignment_ok(this_player())) {
        write("You have betrayed the source of your powers.");
        return 1;
    }
    this_player()->add_mp(-cost);
    write("You look at "+ob->query_cap_name()+" and call on your powers of protection.");
    tell_object(ob, this_player()->query_cap_name()+
      " looks at you and calls on "+this_player()->query_possessive()+
      " powers of protection.");
    say(this_player()->query_cap_name()+" looks at "+ob->query_cap_name()+
      " and calls on "+this_player()->query_possessive()+" powers of protection.",
      ob);
    if(random(101) > defense) {
        this_player()->add_skill_points("magic defense", random(10));
        this_player()->add_alignment( random(5) );
        return 1;
    }
    ob->add_magic_protection( ({ 0, random(defense/2)+1, random(defense)+1 }) );
    this_player()->add_skill_points("magic defense", random(defense/2));
    this_player()->add_alignment(random(defense/3));
    this_player()->add_exp(random(defense));
    return 1;
}

void help() {
  write("Syntax: <buffer [player]>\n\nCreates a very powerful spell of protection for the mighty.");
}
