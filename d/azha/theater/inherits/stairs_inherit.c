#include <std.h>
#include "../theater.h"
inherit CROOM;

	void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",2);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^Desert Sun - Stairway");
   	set_short("%^RED%^Desert Sun - Stairway");
   	set_long("%^RED%^A sweeping grand staircase connects the "+
		"foyer of the theater with the mezzanine level.  A %^YELLOW%^"+
		"golden chestnut %^RESET%^%^RED%^banister highlights the wide "+
		"spiral of the staircase.  Each step on the stair is made from warm"+
		" %^ORANGE%^toffee%^RED%^ colored granite.  A %^YELLOW%^sunny yellow"+
		"%^RESET%^%^RED%^ runner runs down the middle of the stairs, to muffle"+
		" the sounds as patrons come and go.  The %^YELLOW%^yellow%^RESET%^"+
		"%^RED%^ wool rug has a %^BOLD%^fiery red%^RESET%^%^RED%^ raguly "+
		"border, that complements the dark red walls.  \n");  
   	set_smell("default","A stale musty scent fills the air.");
   	set_listen("default","%^BOLD%^%^MAGENTA%^A bewitching melody floats in the air.");
  	set_items(([
      	({"rug","runner","carpet"}) : "%^YELLOW%^Woven from a lightweight"+
	" wool, the vibrant colors of the runner can still be made out in some"+
	" sections.  A faint %^RESET%^%^ORANGE%^orange%^BOLD%^ sunburst pattern"+
	" can be made out, though it seems time has eroded a majority of this"+
	" pattern. The yellow rug is threadbare in certain areas though, with"+
	" holes dotting its surface.  A %^RED%^fiery red%^YELLOW%^ raguly "+
	"border frames the yellow wool.",
      	({"banister"}) : "%^ORANGE%^The wide curved banister is crafted"+
	" from golden chestnut.  Spiraling slender spindles connects the "+
	"banister to the granite stairs.  Worn smooth from repetitive use,"+
	" the top of the banister has a glossy sheen to it still.",
		({"stairs","granite"}) : "%^ORANGE%^Toffee colored granite "+
	"that has flecks of caramel and golden beige is used to craft these"+
	" wide stairs.  The steps are narrow enough to allow ease in traveling"+
	" up and down the stairs.  A%^YELLOW%^ yellow%^RESET%^%^ORANGE%^ "+
	"runner with a %^BOLD%^%^RED%^fiery red%^RESET%^%^ORANGE%^ border"+
	" runs down the center of the stairs, to absorb the sound."]));
  }
