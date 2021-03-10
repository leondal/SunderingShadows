//updated from Shadow's forge for use in Lothwaite.  Circe 9/18/04
#include <std.h>
#include "../lothwaite.h"

inherit ROOM;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DIRT_ROAD);
  set_property("smithy",1); 
  set_name("The Warrior's Crown Forge");
  set_short("The Warrior's Crown Forge");
  set_long("This %^BOLD%^%^RED%^heat %^RESET%^from the three large "+
     "%^BOLD%^%^RED%^f%^YELLOW%^i%^RED%^res %^RESET%^in this stone "+
     "room is almost unbearable.  Scattered around the room are "+
     "massive %^BOLD%^%^BLACK%^iron anvils %^RESET%^and %^BOLD%^"+
     "stone worktables %^RESET%^supporting various %^RED%^tools "+
     "%^RESET%^and scrap %^BOLD%^metals%^RESET%^.  Several pairs "+
     "of %^ORANGE%^leather gloves %^RESET%^and %^ORANGE%^aprons "+
     "%^RESET%^are lying about as well.  At any one time, you "+
     "can usually find a couple of firbolgs filling this room and "+
     "working on their latest pieces.\n"
  );
  set_smell("default", "Smoke from the fire irritates your nostrils.");
  set_listen("default", "The coals in the fire pop and crackle.");
  set_exits(([
      "east" : PATHEXIT"smithy"
  ]));
  set_items( ([
	({"anvil", "anvils"}): "They are large blocks of metal or stone "+
         "in various shapes to form the metal and leather over.",
	({"tools", "stones"}): "Small and large hammers, piercing tools, "+
         "vises to clamp the metal in for bending, as well as rivets "+
         "and other types of hardware.",
	"coals" : "%^BOLD%^%^RED%^It seems to be fueled from both wood "+
         "and coal, with baffles used to pump extra air in at the base "+
         "to make it even hotter when needed.",
      ({"fire","fires"}) : "Three large fires burn at all times of "+
         "the day and night to heat the metal for shaping.  Stone "+
         "chimneys have been built over them to keep smoke to a "+
         "minimum.",
      ({"worktables","tables","stone worktables"}) : "The stone "+
         "tables are clearly built for firbolgs, rising well over "+
         "eight feet in the air.",
      ({"gloves","leather gloves","aprons"}) : "These leather gloves "+
         "and aprons - like most things in this village - are "+
         "sized for firbolgs.  You could borrow one, but you would "+
         "have to be rather large for it to not simply fall off."
  ]) );
}
