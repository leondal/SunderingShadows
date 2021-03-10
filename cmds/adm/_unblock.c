// Intermud communications unblocking command
//	Thorn@Shadowgate
//	12/16/94
//	Admin Commands
// _unblock.c

#include <security.h>
#include <daemons.h>
#include <std.h>

void bad_user(string str) {
	string who, where;
if(sscanf(str, "%s@%s", who, where) != 2 || !str) {
		notify_fail("'"+str+"' is not a correct argument.  Correct: unblock user <user@mudname>.\n");
		return 0;
	}
	seteuid(UID_ROOT);
	SCREEN_D->redeem_user(lower_case(str));
	seteuid(getuid());
	write("ScreenDaemon reports iblock DISABLED on USER "+capitalize(str)+" successfully.\nUse iblock [user/mud] <name of mud or user> to reenable.\n");
	return 1;
}

void bad_mud(string str) {
	string where;
	if(sscanf(str, "@%s", where) != 1 || !str) {
		notify_fail("'"+str+"' is not a correct argument.  Correct: unblock mud <@mudname>.\n");
		return 0;
	}
	seteuid(UID_ROOT);
	SCREEN_D->redeem_mud(lower_case(where));
	seteuid(getuid());
	write("ScreenDaemon reports iblock DISABLED on MUD "+capitalize(where)+" successfully.\nUse iblock [user/mud] <name of mud or user> to reenable.\n");
	return 1;
}

int cmd_unblock(string str) {
	string what, who;
	seteuid(getuid());
	if(!str) return 0;
	if(!archp(this_player())) return 0;
	if(str == "all") {
		seteuid(UID_ROOT);
		SCREEN_D->clear_all();
		seteuid(getuid());
		write("ScreenDaemon reports that ALL blocking is cleared!\nUse iblock [user/mud] <name of user or mud> to block via intermud.\n");
		return 1;
	}
	if(sscanf(str, "%s %s", what, who) != 2) {
		notify_fail("unblock [user/mud] <name of user or mud>.\n");
		return 0;
	}
	if(what == "user") {
		bad_user(who);
		return 1;
	}
	if(what == "mud") {
		bad_mud(who);
		return 1;
	}
	notify_fail("unblock [user/mud] <name of user or mud>.\n");
	return 0;
}


help() {
	write(
@HELP

Usage: unblock all
       unblock user user@mudname
       unblock mud @mudname

	        This command sets the intermud screening daemon to unblock intermud services previously blocked by an iblock command.  
	        In all cases the name of the MUD needs to be proceeded by a "@" in orderfor the command to work correctly.  For instance, "unblock mud @BigMUD" willwork, but "unblock mud DeathMUD" will not.

See also: whoiblocked, iblock

HELP
	);
}
	
	
