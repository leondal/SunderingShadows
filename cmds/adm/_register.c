//	/bin/adm/_register.c
//	from the Nightmare mudlib
//	for restricting access for certain sites
//	created by Shadowwolf@Nightmare?

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_register(string str) {
    string which, why, res;

    if(!str) return 0;
    if(!archp(this_player())) return 0;
    if(sscanf(str, "%s %s", which, why) != 2) {
	notify_fail("Syntax: <register [site] [reason]>\n\n");
	return 0;
    }
    write(which+" is now on register.\n");
    seteuid(UID_BANISH);
    if(res = catch(call_other(BANISH_D, "register_site", which))) 
      write("Error in registering site: "+res+"\n");
    seteuid(UID_LOG);
    log_file("watch/register", which+" by "+(string)this_player()->query_name()+"\n");
    log_file("watch/register", why+"\n");
    return 1;
}

void help() {
    write("Syntax: <register [site] [reason]>\n\n");
    write("Makes a given site needs to register their characters with\n");
    write("law before being able to play the mud.  A reason must be given\n");
    write("and it must be good.  In general, only law should be using\n");
    write("this command.  And if you are not law, you better mail law.\n");
    write("This command only works with numeric addresses, ie:\n");
    write("    register 134.181.*                ok\n");
    write("    register 134.181.1.12             ok\n");
    write("    register orlith.bates.edu         BAD\n");
    write("See also: sunbanish, whobanished, wholetin, whoregistered, whowatched\n");
}
