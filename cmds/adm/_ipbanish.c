//	/bin/adm/_register.c
//	from the Nightmare mudlib
//	for restricting access for certain sites
//	created by Shadowwolf@Nightmare?

#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_ipbanish(string str) {
    string which, why, res;

    if(!str) return 0;
    if(!archp(this_player())) return 0;
    if(sscanf(str, "%s %s", which, why) != 2) {
	notify_fail("Syntax: <ipbanish [site] [reason]>\n\n");
	return 0;
    }
    write(which+" is now on ipbanish.\n");
    seteuid(UID_BANISH);
    if(res = catch(call_other(BANISH_D, "block_site", which))) 
      write("Error in registering site: "+res+"\n");
    seteuid(UID_LOG);
    log_file("watch/set-ipbanish", which+" by "+(string)this_player()->query_name()+"\n");
    log_file("watch/set-ipbanish", "	"+why+"\n");
    return 1;
}

void help() {
    write("Syntax: <ipbanish [site] [reason]>\n\n");
    write("Makes a certain IP unable to play at all... Very dangerous.\n");
    write("This command only works with numeric addresses, ie:\n");
    write("    ipbanish 134.181.*                ok\n");
    write("    ipbanish 134.181.1.12             ok\n");
    write("    ipbanish orlith.bates.edu         BAD\n");
    write("See also: sunbanish, whobanished, wholetin, whoregistered, whowatched\n");
    write("Related: whoipbanished, unipbanish\n");
}
