#include <std.h>

inherit OBJECT;

void create(){
   ::create();
   set_long(
@STYX
This is a series of posters, each with a name by topic for easy reference.  They have been designed to help guide new Sundering Shadows players through learning commands and how to make a memorable character.  A little time spent now will help you have the most fun while here.  You can read them according to their topic (type '%^BOLD%^read overview%^RESET%^' etc.).  The topics are:

%^BOLD%^overview     %^RESET%^Overview for how you look to others (describe, adjective)
%^BOLD%^speech       %^RESET%^Customize your speech & using colors (speech, color, alias)
%^BOLD%^actions      %^RESET%^Actions, enter/leave rooms (message in/out, souls, emote)
%^BOLD%^descriptions %^RESET%^Guidelines/elaboration for descriptions and adjective use
%^BOLD%^deities      %^RESET%^The gods you can choose to follow (help deities).
STYX
	);
   set_short("A series of posters");
   set_id(({"poster", "posters"}));
   set_name("posters");
   set_property("no animate", 1);
   set_weight(10000);
   set_value(0);
}

void init(){
   	::init();
   	add_action("read_func","read");
}


int read_func(string str){
   if(!str) return notify_fail("Read what?\n");
   if(str == "overview" || str == "speech" || str == "actions" || str == "descriptions", "deities") { 
   	TP->more("/d/newbie/ooc/"+str);
	  	return 1;
   }
   return notify_fail("Sorry, that topic isn't listed.\n");
}
