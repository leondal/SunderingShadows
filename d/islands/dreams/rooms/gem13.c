#include <std.h>
#include "../defs.h"
inherit GEM;
int FLAG;
void create()
{
   ::create();
	set_long(
   		"%^BOLD%^%^WHITE%^You are standing within what appears to be an"+
   		" incredibly large gem. The walls around you are multi-faceted, angling"+
   		" upwards to meet about 60 feet above. The floor that you're standing on"+
   		" is flat, smooth, and completely reflective. Light is coming from"+
   		" somewhere outside the gem, refracting as it enters. A "+
   		"%^RESET%^%^RED%^r%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^BLUE%^"+
   		"o%^RESET%^%^MAGENTA%^w%^BOLD%^%^WHITE%^ of colors"+
   		" is scattered everywhere, although predominantly they are shades of"+
  		 " %^MAGENTA%^pink%^WHITE%^, %^RESET%^%^MAGENTA%^purple%^BOLD%^%^WHITE%^"+
   		", and %^RED%^red%^WHITE%^.  You also see %^YELLOW%^yellows%^WHITE%^"+
   		",%^RESET%^%^ORANGE%^ oranges%^BOLD%^%^WHITE%^, "+
   		"%^BLUE%^b%^CYAN%^l%^BLUE%^u%^CYAN%^e%^BLUE%^s%^WHITE%^, and "+
  		"%^GREEN%^greens%^WHITE%^."+
   		" Although the walls of the gem appear clear, you cannot see anything"+
   		" beyond them. A crack in the northern wall looks strangely out of place."
		"  This is a rather eerie place, and you can't help but"+
   		" feel small in here.\n");
	add_item(({"crack","north wall","north""+
		","north walls"}),"%^BOLD%^%^CYAN%^A crack can be seen in one of the "+
		"facets of the gem you are within.  Though you still can't see what"+
		" it on the other side, the crack still seems oddly out of place.  "+
		"Almost as if someone or thing was trying to shatter it.",);
	set_exits(([
   		"southwest" : ROOMS+"gem10",
   		"south" : ROOMS+"gem11",
   		"southeast" : ROOMS+"gem12",
   ]));
}
void init(){
::init();
    	add_action("shatter","shatter");
}
int shatter(string str){
        if(str != "crack" && str != "gem" && str != "wall" && str != "north wall") 
      return notify_fail("What do you wish to break?\n");

      tell_object(TP,"%^CYAN%^%^BOLD%^You focus on the crack and with all your"+
		" might manage to shatter it.  Shards of crystal float about you.");
	tell_room(ETP,"%^BOLD%^%^CYAN%^%^"+TPQCN+" manages to shatter the gem "+
		"open. Shards of crystals float about you.",TP);
        tell_room(ETP,"%^BOLD%^%^With the breaking of a gem a vacuum is created.  "+
		"The rushing wind whips around you, drawing you out of the gem!");
			all_inventory(ETP)->move(ROOMDIR"dream");
	tell_room(ETP,"%^BOLD%^%^BLUE%^You find yourself in a strange void.");
			all_inventory(ETP)->force_me("look");
			FLAG = 1;
                	return 1;
}
void reset() { 
	::reset(); 
		FLAG=0;
 	return; 
}
