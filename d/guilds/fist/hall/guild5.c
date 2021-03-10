//Mechanics by Bane, Atmosphere by Vis
#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_name("%^BLUE%^Sparring Chamber of the %^RED%^%^BOLD%^Iron Fist.");
   set_short("Sparring Chamber");
   set_long(
@FIST
%^CYAN%^%^BOLD%^The Sparring Chamber of the %^RED%^Iron Fist%^BOLD%^%^CYAN%^.
%^BLUE%^This domed chamber is where members of the %^RED%^Iron Fist%^BLUE%^ tested 
each other's skills, and were judged for advancement by their leaders. 
The floor, like the curved walls, is made of a white marble, but it 
has been mottled and stained with the dark brown of long dried blood.
FIST
   );
   set_property("indoors",1);
   set_property("light",2);
   set_light(2);
   set_listen("default","You hear the ghostly whispering of long dead warriors of the %^RED%^Iron Fist.");
   set_smell("default","You smell the odor of the old blood that has long since dried into the fine brown patina on the floor.");
   set_exits( ([
      "west":"/d/guilds/fist/hall/guild4",
      "north":"/d/guilds/fist/hall/guild6"
   ]) );
}

