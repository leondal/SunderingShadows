//	/bin/adm/_allow.c
//	from the Nightmare mudlib
//	lets in selected players from sites on register
//	created by Shadowwolf@Nightmare?

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_allow(string str) {
    string who, email;
    mixed res;

    if(!archp(previous_object())) return 0;
    if(!member_group(geteuid(previous_object()), "superuser")) {
    if(!member_group(geteuid(previous_object()), "law")) {
	notify_fail("Only law may allow new players in the game.\n");
	return 0;
    }
    }
    if(!str) return 0;
    if(sscanf(lower_case(str), "%s %s", who, email) != 2) {
	notify_fail("Syntax: <allow [who] [email]>\n");
	return 0;
    }
/*
    if(user_exists(who)) {
	notify_fail("A character by that name already exists.\n");
	return 0;
    }
*/
// write(capitalize(who)+" is now allowed to create a character.\n");
    write(capitalize(who)+" is now allowed to connect from a banished site or make a new charachter.");
    seteuid(UID_BANISH);
    if(res = catch(call_other(BANISH_D, "allow_name", who)))
      write("Error in letting in "+who+": "+res+"\n");
    seteuid(getuid());
    seteuid(UID_LOG);
    seteuid(getuid());
    return 1;
}

void help() {
    write("Syntax: <allow [who] [email] >\n\n");
    write("Members of law may allow people from sites on register to create\n");
    write("new characters with this command.  [who] is the character name,\n");
    write("[email] is the player's real life email address.\n");
    write("See also: noallow, wholetin, whobanished, whoregistered, whowatched\n");
}
