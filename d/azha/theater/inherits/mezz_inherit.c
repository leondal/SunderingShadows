#include <std.h>
#include "../theater.h"
inherit CROOM;

	void create(){
   	::create();
   	set_property("indoors",1);
   	set_property("light",1);
	set_property("no sticks",1);
	set_property("no teleport",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^RED%^Desert Sun - Mezzanine Level");
   	set_short("%^RED%^Desert Sun - Mezzanine Level");
   	set_long("%^RED%^A long narrow hallway connects "+
		"the box seats with the stairs.  The mezzanine "+
		"level is reserved for only those privileged enough to "+
		"afford to lease a box seat.  Velvet drapes block off each "+
		"box seat, helping to filter any sounds that might be made "+
		"in the hallway.  Dotting the dark red walls is a %^YELLOW%^"+
		"gold leaf%^RESET%^%^RED%^ sunburst pattern, carrying the theme"+
		" of The Desert Sun throughout.  The %^ORANGE%^golden%^RED%^ "+
		"wood parquet floor is covered with a red velvet runner, aiding"+
		" in softening the traffic.  %^YELLOW%^Sunburst%^RESET%^%^RED%^"+
		" shaped lights hang from thin %^YELLOW%^golden chains%^RESET%^%^RED%^"+
		", bathing the hallway in a soft glow.  \n");  
   	set_smell("default","A stale musty scent fills the air.");
   	set_listen("default","%^BOLD%^%^MAGENTA%^A bewitching melody floats in the air.");
  	set_items(([
      	({"rug","runner","floor","parquet floor"}) : "%^ORANGE%^The "+
	"golden parquet flooring is a tribute to wealth and excess.  "+
	"Instead of lining the floor with planks, as it is usually done,"+
	" the parquet tiles run horizontally and vertically.  Each tile "+
	"has to be hand crafted and set in place.  Covering this expensive"+
	" floor treatment is a plush %^RED%^red velvet%^ORANGE%^ runner.  "+
	"Most of the velvet has been crushed, creating a shorter pile and"+
	" creating a slight %^BOLD%^%^RED%^sheen%^RESET%^%^ORANGE%^ on its surface.",
		({"lights","lamps"}) : "%^YELLOW%^Golden lamps in the shape of three"+
	" dimensional sunbursts add a pleasant amount of light to the hallway."+
	"  The lighting hovers towards the dim side, but is bright enough that"+
	" one could travel the hallway without fear of tripping.  The lamps hang"+
	" from the ceilings on thin golden chains.",
      	({"curtains","drapes","curtain"}) : "%^RED%^Thick double sided crimson velvet "+
	"curtains block off the box seats, keeping any noise out here from"+
	" disturbing the patrons within and the performance.  The velvet "+
	"curtains are trimmed with %^YELLOW%^golden braid%^RESET%^%^RED%^ trim"+
	".  A pair of %^YELLOW%^gold%^RESET%^%^RED%^ and %^BOLD%^ruby%^RESET%^"+
	"%^RED%^ hooks are fastened to either side of the box seat, allowing "+
	"the curtains to be parted and held in check.",
		({"walls","wall","gold leaf","pattern"}) : "%^RED%^The dark red"+
	" walls feature a repeating pattern of %^YELLOW%^gold leaf%^RESET%^%^RED%^"+
	" sunbursts.  Sculpted crown molding connects the ceiling and the walls "+
	"together.  The %^YELLOW%^gold leaf%^RESET%^%^RED%^ molding is carved to "+
	"look like a troupe of actors and actresses dancing around the hallway."+
	"  The gold leafing adds a lavish excess to this part of the theater, "+
	"further illustrating what sorts of people leased these box seats.",
	]));
	}