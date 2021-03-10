#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_long(
@STYX
This is a series of posters, each with a name by topic for easy reference.  Browsing through here before you play should help, or come back here if you have a question to look for the answer.  You can read them according to their topic.  The topics are:
%^BOLD%^who            %^RESET%^Who list, editing, names, idle time
%^BOLD%^speaking       %^RESET%^Languages and speech related commands
%^BOLD%^questing       %^RESET%^Doing quests (also see "quests" in the rules room)
%^BOLD%^pkilling       %^RESET%^Player killing basics
%^BOLD%^pkcont         %^RESET%^Player killing continued
%^BOLD%^stats          %^RESET%^Stats, score, stamina, etc.
%^BOLD%^misc           %^RESET%^AC, alignment, ideas
%^BOLD%^abbrev         %^RESET%^Common abbreviations
%^BOLD%^healing        %^RESET%^HP, offer, offerall
%^BOLD%^advancing      %^RESET%^Advancing in levels
STYX
	);
   set_short("A series of posters");
   set_id(({"poster", "posters"}));
   set_name("posters");
   set_weight(10000);
   set_value(0);
}

void init(){
   	::init();
   	add_action("read_func","read");
}

int read_func(string str){
   if(!str) return notify_fail("Read what?\n");
   if (member_array(str, ({"who", "speaking", "questing", "pkilling", "stats", "misc", "abbrev", "healing", "advancing", "pkcont" }) ) != -1)  { 
   	TP->more("/d/newbie/ooc/"+str);
	  	return 1;
   }
   return notify_fail("Sorry, that topic isn't listed.\n");
}
