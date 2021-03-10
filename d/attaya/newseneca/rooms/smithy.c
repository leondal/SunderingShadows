//~Circe~ for new Seneca 12/4/07
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create() {
  ::create();
  set_indoors(1);
  set_light(3);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_name("Seneca Smithy");
  set_short("%^BOLD%^%^WHITE%^Seneca Smithy%^RESET%^");
  set_long("%^BOLD%^%^WHITE%^Seneca Smithy%^RESET%^\n"+
     "Dominated by a %^BOLD%^%^RED%^fi%^YELLOW%^r%^RED%^ep%^YELLOW%^i"+
     "%^RED%^t %^RESET%^in the center, this huge room is bounded "+
     "by thick %^BOLD%^stone walls%^RESET%^.  A large vent in "+
     "the middle of the ceiling lets smoke from the pit escape "+
     "into the air above Seneca, and long, narrow windows near "+
     "the ceiling allow additional fresh air to enter.  "+
     "Surrounding the firepit are "+
     "treated %^BOLD%^stones%^RESET%^ that withstand the heat "+
     "and keep the %^BOLD%^%^RED%^fi%^YELLOW%^r%^RED%^e %^RESET%^"+
     "contained.  Along the northern wall are %^ORANGE%^wooden "+
     "barrels %^RESET%^containing different materials for tempering.  "+
     "A quick survey of the barrels reveals %^YELLOW%^oil%^RESET%^, "+
     "%^CYAN%^water%^RESET%^, and %^GREEN%^brine%^RESET%^, all of "+
     "which are used to quench different %^BOLD%^metals%^RESET%^.  "+
     "Several %^ORANGE%^worktables %^RESET%^lined with %^RED%^"+
     "brick%^RESET%^ are spread around the room, giving smiths "+
     "ample space to craft.  Atop the tables are %^BOLD%^%^BLACK%^"+
     "anvils%^RESET%^, %^BOLD%^tongs%^RESET%^, %^ORANGE%^hammers"+
     "%^RESET%^, and other tools needed for working metal along with "+
     "bits of %^BOLD%^scrap metal %^RESET%^that can be used for repairs.\n");
  set_smell("default", "The acrid odor of burning metal fills the air.");
  set_listen("default", "The ringing of hammers rises over the crackling of the fire.");
  set_exits(([
	"west" : ROOMS"weapon",
      "east" : ROOMS"armor"
  ]));
  set_items( ([
	({"anvil", "anvils"}): "They are large blocks of metal or stone "+
         "in various shapes to form the metal and leather over.",
	({"tools", "tongs","hammers"}): "You see small and large "+
         "hammers, piercing tools, vises to clamp the metal in "+
         "for bending, long-handled tongs to safely maneuver in the fire, "+
         "as well as rivets and other types of hardware.",
	({"fire","firepit","coals"}) : "%^BOLD%^%^RED%^It seems to be fueled from both wood "+
         "and coal, with baffles used to pump extra air in at the base "+
         "to make it even hotter when needed.  A low construction "+
         "of stone encircles the firepit, containing the flames.",
      ({"barrels","barrel"}) : "The bound %^ORANGE%^wooden barrels %^RESET%^"+
         "have lids which may be fitted on them when not in use, but "+
         "they are usually left open, revealing oil, water, and brine.",
      ({"table","tables","worktables"}) : "Each of the work tables is "+
         "long and about three feet wide, giving a smith room to work.  "+
         "They are wooden but lined with brick in areas to allow them "+
         "to withstand extreme heat.",
      "scrap metal" : "The metal laid upon the tables is scrap, "+
         "open for anyone to use for repairs.  You would need "+
         "to provide your own billets for creation though."
  ]) );
  set_property("smithy",1); 
}
