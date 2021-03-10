//  The Watcher Medallion (guild object)
//  Thorn@ShadowGate
//  970216
//  Watcher's Guild
//  medallion.c

#include <std.h>
#pragma save_binary

#define RULES_HELP "tba"
#define COMMMAND_HELP "tba"
#define GUILD_INFO "tba"

object watcher, watched;

inherit "/std/guild";

void create(){
    ::create();
    set_id(({"medallion","watcher medallion","silver medallion", "watcherx" }));
    set_name("silver medallion");
    set_short("A silver medallion");
    set_long(
@WATCHERS
%^BOLD%^MAGENTA%^Medallion of the Watchers%^RESET%^
  This medallion marks membership in the secret Society of Watchers,
an ancient group dedicated to observing and recording events, but
not participating directly in the wars and conflicts of the world.
The wearer of this medallion is pledged to observe, record, but
not judge the deeds of the great heroes and villians of this world.  
%^BOLD%^  For a list of guild abilities and information type <whelp>.%^RESET%^
WATCHERS
    );
    set_type("clothing");
    set_ac(1);
    set_weight(1);
    set_value(0);
    set_limbs(({ "neck" }));
set_leader("dakkon");
    set_guild_items(({"/d/shadow/guilds/watchers/medallion"}));
    set_secret_guild(1);
    set_guild_hc(({ "thorn" }));
    set_guild_home("/d/shadow/guilds/watchers/");
    set_welcome("The search for knowledge is never ending. Welcome.");
    set_guild_name("Watcher");
    set_type("clothing");
    set_limbs(({"neck"}));
}

init() 
{
	guild::init();
	add_action("whelp", "whelp");
	add_action("locate", "locate");
	add_action("track", "track");
	add_action("observe", "observe");
	if(ETO==TP) TP->force_me("wear medallion");
}

int whelp(string str) {
	switch(str) {
		case "rules":
		case "rule":
			TP->more(RULES_HELP);
			break;
		case "commands":
		case "cmds":
		case "command":
			TP->more(COMMMAND_HELP);
			break;
		case "info":
		case "information":
		case "inf":
			TP->more(GUILD_INFO);
			break;
		case "topics":
		default:
			write(
@WHELP
%^MAGENTA%^
			      *  *  *
			  * OOOOOOOOOOO *
			  OOO         OOO
		       * OO   WATCHER   OO *
			OO     GUILD     OO
		      * OO @@@@     @@@@ OO *
			OO@@@@@@@ @@@@@@@OO
		      * OO     @@@@@     OO *
			OO H E  @@@  L P OO
		       * OO     @@@     OO *
			  OOO   @@@   OOO
			  * OOOOOOOOOOO *
			      *  *  *

%^RESET%^
%^BOLD%^whelp %^RED%^rules%^RESET%^.........guild rules
      %^GREEN%^commands%^RESET%^......commands for guild members
      %^BLUE%^info%^RESET%^..........information on the guild

	Use whelp <topic> to get more info on a particular facet
of your guild powers, duties and other stuff.

WHELP
			);
			break;
	}
	return 1;
}


int track() { return 1; }

int observe()
{
	mapping temp;
	string *items;
	int x;

	if((string)TP->query_guild() != "Watcher") return 0;
	if(!(temp = ETP->query_items())) {
		return notify_fail("There is nothing worth looking at here.\n");
	}
	items = keys(temp);
	tell_player(TP, "You can look at the following in the room, "+
	"which may be of interest:\n");
	for(x=0;x<sizeof(items);x++) {
		tell_player(TP, items[x]+"\n");
	}
	return 1;
}

int locate(string str) 
{ 
	string spd, targ;
	int rel, cost, time;
	object target;

	if(sscanf(str, "%s %d %s", targ, rel, spd) < 2) {
		return notify_fail("locate <player> <10,20..90,95,99> <imm,faster,fast,normal,slow>\n");
	}
	if(sscanf(str, "%s %d %s", targ, rel, spd) == 2) {
		sscanf(str, "%s %d", targ, rel);
		spd = "normal";
	}
	cost = rel * 100;
	switch(spd) {
	  case "imm":
	    cost *= 15;
	    time = 2;
	    break;
	  case "faster":
	    cost *= 10;
	    time = 10;
	    break;
	  case "fast":
	    cost *= 2;
	    time = 20;
	    break;
	  case "normal":
	    time = 30;
	    break;
	  case "slow":
	    cost = to_int((cost *= 3)/ 4);
	    time = 60;
	    break;
	  default:
	    time = 30;
	    break;	  
	}
	if(!(target=find_player(targ))) return notify_fail("No player by that name on.");
	watched=find_player(targ);
	watcher=TP;
	if(random(101) > rel) call_out("mislead_watcher",time);
	else call_out("locate_target",time);
	tell_player(TP, "Your informants will be getting your information shortly.\n"+
	"Remember, this might be inaccurate depending on the level of reliability you "+
	"entered.  You only get what you pay for!");
	return 1;
}

int locate_target()
{
	object room;
	if(!watcher) return 0;
	if(!watched) return 0;
	room=environment(watched);
       tell_object(watcher, "%^BOLD%^MAGENTA%^\nMessage from the Network...RE: location of "+
	watched->query_cap_name()+":\n");
	if(wizardp(watched)) {
		tell_object(watcher, "You WISH you could locate immortals.  "+
		"Thanks for the money, however.\n");
		return 1;
	}
	tell_object(watcher, room->query_long());
	return 1;
}

int mislead_watcher()
{
	object room;
	int index;

	if(!watcher) return 0;
	if(!watched) return 0;
	tell_object(watcher, "\n%^BOLD%^MAGENTA%^\nMessage from the Network...RE:location of "+
	watched->query_cap_name()+":\n");
	if(wizardp(watched)) {
		tell_object(watcher, "You WISH you could locate immortals.  "+
		"Thanks for the money, however.\n");
		return 1;
	}
	index = random(sizeof(users()))+1;
	room=environment(users()[index]);
	tell_object(watcher, room->query_long());
	return 1;
}






