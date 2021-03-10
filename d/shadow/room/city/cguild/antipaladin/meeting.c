#include <std.h>
#define ANTI "/d/shadow/room/city/cguild/antipaladin/"
inherit VAULT;

void create(){
  :: create();
  set_terrain(WOOD_BUILDING);
  set_travel(PAVED_ROAD);
  set_property("light",2);
  set_property("indoors",1);
  set_name("meeting room");
  set_short("%^CYAN%^A meeting room%^RESET%^");
  set_long("%^CYAN%^This room is huge by most standards, even for a meeting room."
"  It is in immaculate condition with nothing seeming to be out of place.  "
"A beautiful %^ORANGE%^oak table %^CYAN%^is centered in the room and dominates "
"it.  Ten exquisitely crafted %^ORANGE%^oak chairs %^CYAN%^line each "
"side of the table, their %^YELLOW%^soft silk cushions %^RESET%^%^CYAN%^shining "
"under the light from the chandeliers.  The chair at the head of the table is "
"similarly carved but %^RESET%^white in color %^RESET%^with a %^RED%^dark red "
"cushion %^CYAN%^that looks well-used.  The table has slots cut into it at "
"each chair location.  The walls are sparsely decorated with only a few "
"paintings hanging at the moment.");

  set_items(([ 
	"table" : "%^ORANGE%^The oak table is stained very dark but the grain is still quite apparent through the high polish.  The legs have been intricately carved into the shape of a lower leg on a horse.  Slots have been cut into the table at each chair position.",
	"chandeliers" : "Three %^BOLD%^%^CYAN%^crystal chandeliers %^RESET%^hang motionless from the ceiling.  The light is more than enough illumination for the room.",
	"chair" : "This wood of the chair at the head of the table is a dull white, having been carved from the wood of an ash tree and stained.  Attached to the top of the chair is a headrest in the shape of a crown.",
	"chairs" : "%^ORANGE%^Exquisitely carved from a heavy grained oak, they each have high backs and arms.  They are clearly sized for humans but large enough to accomodate even a large human in full plate armor.",
	({ "slot", "slots" }) : "There are 13 slots carved into the table.  The slot at the head of the table is filled with a holy symbol from the temple of Kossuth.  You assume the other slots are for similar symbols.",
	({"floor", "carpet"}) : "%^BOLD%^%^BLACK%^The dark marble floor is highly polished, showing rich %^RESET%^%^ORANGE%^bronze veins%^BOLD%^%^BLACK%^.",
	"paintings" : "Vibrant oil paintings clearly done by master painters, mostly of knights in dark armour in glorious battles."

  ]));

  set_exits(([
	"hall" : ANTI+"hall",
   ]));
   set_door("black door",ANTI+"hall","hall",0);
   set_smell("default", "It smells clean here with a slight scent of burning wood.");
   set_listen("default", "You hear muffled sounds of activity from the other rooms.");
}
