#include <std.h>
#include "../defs.h"
inherit ROOM;
void create()
{
  ::create();
   set_terrain(BEACH);
   set_travel(FOOT_PATH);
  set_property("indoors",0);
  set_property("light",1);
  set_climate("tropical");
  set_short("%^BOLD%^Along the Shore of Ovadexel%^RESET%^");
  set_long("%^CYAN%^You stand upon a sandy beach of a small island.  "+
	"The island doesn't appear to be larger than a few hundred "+
	"yards across, and looks relatively bare.  Between the %^GREEN%^"+
        "palm trees%^CYAN%^ to the east you spot a small, shabby "+
	"looking %^RESET%^hut%^CYAN%^.  This "+
	"section of the shore seems to be the only smooth spot.  %^BOLD%^"+
	"Waves%^RESET%^%^CYAN%^ "+
	"crash against rocks and oyster shells everywhere else you "+
	"can see. \n");
  set("night long","%^CYAN%^The %^BOLD%^%^WHITE%^moonlight%^RESET%^"+
	"%^CYAN%^ seems to cause the entire island "+
	"and the waters around it to glow in a %^BOLD%^pale light"+
	"%^RESET%^%^CYAN%^.%^BOLD%^  Waves%^RESET%^%^CYAN%^ lap "+
	"gently along this sandy section of the shore.  The "+
	"island doesn't seem to be very large, as you think you can hear "+
	"the waves crashing against the beach to the far east.  The area "+
	"you have beached your boat seems to be the only safe spot to harbor "+
	"your craft.  Rocks and clumps of oyster shells line the shore as "+
	"far as you can see in the moonlight.\n");       
  set_smell("default","%^BOLD%^%^BLUE%^Steady breezes from the sea fills your nostrils "+
	"with salty tasting air.");
  set_listen("default","%^CYAN%^Small waves gently lap against the shore.");
  set_items(
    ([
    "hut" : "%^ORANGE%^A small hut seems to stand in the center of this island.",
    ({"tree","trees","palm tree","palm trees"}) : "%^GREEN%^Tall palm trees are "+
	"scattered about this small island.  Coconuts are bunched up "+
	"at the top of a few of the taller ones.",
    ({"rocks","shells","oyster shells"}) : "%^BOLD%^Along the shore, and "+
	"breaking the water just off shore, are large clumps of rocks and "+
	"oyster shells.  They look as if they could quickly rip through "+
	"the hull of most boats."   
    ]) );
}
