#include <std.h>
#define ANTI "/d/shadow/room/city/cguild/antipaladin/"

inherit VAULT;

void create(){
  :: create();
  set_terrain(WOOD_BUILDING);
  set_travel(PAVED_ROAD);
  set_property("light",2);
  set_property("indoors",1);
  set_property("no sticks", 1);
  set_name("lavish hallway");
  set_short("%^CYAN%^A lavish hallway%^RESET%^");
  set_long("%^CYAN%^You have entered a long, lavishly decorated hallway with "
"four doors, two on each side.  Wall space is taken up by %^GREEN%^tapestries "
"%^CYAN%^and %^ORANGE%^small bronze plaques%^CYAN%^.  Two %^YELLOW%^chandeliers "
"%^RESET%^%^CYAN%^dangle from the ceiling, the light illuminating the area "
"reasonably well.  The floor is covered with a %^RED%^deep red carpet %^CYAN%^"
"which muffles any sound one's feet might make on it.  Slight smells of incense "
"and wax drift to your nose.");

/*   The northeast door is closed and has a %^YELLOW%^" "gold sign %^RESET%^%^CYAN%^on the door."  Not sure where this is supposed to lead unless it's Lusell's office *Styx*
*/

  set_items(([ 
	"carpet" : "%^RED%^The carpet is very plush and a deep red that is often described as blood red.",
	"tapestries" : "%^GREEN%^Richly woven tapestries with scenes of nobility hunting game, knights dueling in tournaments, and various other noble endeavours.",
	"plaques" : "The plaques are blank at present, but you might guess they are meant to be inscribed at some point.",

  ]));

  set_exits(([
	"west" : ANTI+"anti1",
	"northwest" : ANTI+"anti2",
	"east" : ANTI+"anti3",
	"northeast" : ANTI+"meeting",
	"southwest" : ANTI+"enter1",
   ]));
   set_door("red door", ANTI+"anti1","west",0);
   set_door("oak door", ANTI+"anti2","northwest",0);
   set_door("brown door", ANTI+"anti3","east",0);
   set_door("black door", ANTI+"meeting","northeast",0);
   set_smell("default", "It smells clean here with a scent of candle wax.");
   set_listen("default", "The carpet muffles most sound.");
}
