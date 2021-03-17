#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_long(
@STYX
This is a series of posters, each with a name by topic for easy reference.  They have been designed to help guide new Sundering Shadows players through learning commands and how to make a memorable character to have the most fun while here.  You can read them according to their topic (type '%^BOLD%^read basics%^RESET%^' etc.).  The topics are:

%^BOLD%^basics         %^RESET%^Survival - eat/drink, movement, finding your way
%^BOLD%^communication  %^RESET%^Languages, lines, parties
%^BOLD%^equipping      %^RESET%^Using stores, banks, etc.
%^BOLD%^adventure      %^RESET%^Beginning to adventure
%^BOLD%^combat         %^RESET%^Combat-related info. and helpful hints
%^BOLD%^skills         %^RESET%^Non-combat skills you can train
%^BOLD%^feats          %^RESET%^Major abilities you can learn
%^BOLD%^features       %^RESET%^Other handy features to learn
%^BOLD%^roleplay       %^RESET%^Roleplaying
%^BOLD%^calendar       %^RESET%^Calendar, date command, and weather command
STYX
	);
// note - topics have to be added to the array in init to work

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

int read_func(string str) {
   if(!str) return notify_fail("Read what?\n");
   if(str == "skills")  TP->force_me("help skills");
   if(str == "feats") TP->force_me("help feats");
   if (member_array(str, ({"basics", "communication", "equipping", "adventure", "features", "roleplay", "combat", "calendar" }) ) != -1)  { 
   	TP->more("/d/newbie/ooc/"+str);
   	return 1;
   	}
	   else return notify_fail("Sorry, that topic isn't listed.\n");
}
