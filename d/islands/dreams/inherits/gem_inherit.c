#include <std.h>
#include "../defs.h"
inherit CROOM;
void pick_critters();

void create()
{	
	
	pick_critters();
   	set_repop(15);
   	::create();
	set_terrain(BARREN);
   	set_travel(PAVED_ROAD);
   	set_property("no scry",1);
   	set_property("no teleport",1);
   	set_property("no sticks",1);
   	set_property("indoors",1);
   	set_property("light",3);
   	set_short("%^BOLD%^Within the Gem%^RESET%^");
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
   		" beyond them. This is a rather eerie place, and you can't help but"+
   		" feel small in here.\n"
   	);
   	set_listen("default","%^BOLD%^%^CYAN%^Your footsteps echo throughout the area.");
   	set_items(([
   		"floor" : "%^BOLD%^%^CYAN%^The floor is a perfectly flat and entirely"+
   			" reflective surface."+
   			" You can see your own image looking back at you, and it has"+
			" a tendency to make your footsteps echo.",
   		"walls" : "%^BOLD%^The walls are multi-faceted crystal, slowly "+
			"curving inwards.  Some light source shines from outside,"+
			" sprinkling a rainbow of colors"+
   			" about the room.",
   		"ceiling" : "%^WHITE%^There isn't exactly a ceiling, merely a"+
			" point at which the multi-faceted walls meet, which"+
			" is easily sixty feet above the floor.",
   	]));
   }
void pick_critters() {
      switch(random(15)){
case 0..2:  set_monsters(({MON"githyanki"}),({random(2)+1}));
break;
case 3..5:  set_monsters(({MON"githyanki"}),({random(2)+2}));
break;
case 6..9:  set_monsters(({MON"githyanki"}),({2,2}));
break;
case 10..14: 
break;
      }
}
