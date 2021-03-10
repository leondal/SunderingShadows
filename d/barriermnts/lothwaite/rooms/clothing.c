#include <std.h>
#include "../lothwaite.h"
inherit VAULT;

void create()
{
	::create();
      set_terrain(WOOD_BUILDING);
      set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_name("Clothier of Lothwaite");
	set_short("Clothier of Lothwaite");
	set_long(
         "%^ORANGE%^This shop is cluttered with all manner of "+
         "clothes in all states of production from mere piles of "+
         "%^RESET%^cloth %^ORANGE%^to finished products hanging "+
         "neatly from %^YELLOW%^wooden racks%^RESET%^%^ORANGE%^.  "+
         "The southern end of the shop features a large %^RED%^"+
         "fireplace %^ORANGE%^in front of which stand several "+
         "%^YELLOW%^racks %^RESET%^%^ORANGE%^with stretched "+
         "leather in the process of curing.  The %^RESET%^floor "+
         "%^ORANGE%^is covered with clean %^GREEN%^rushes "+
         "%^ORANGE%^taken from the nearby river.  Along the "+
         "eastern wall is a long %^YELLOW%^table %^RESET%^"+
         "%^ORANGE%^spread with fabrics in all shades.  "+
         "%^CYAN%^Patterns %^ORANGE%^are scattered neatly "+
         "about as well, protected from the wind of the valley "+
         "by the wattle walls.\n"
	);
	set_smell("default","The clean fragrance of rushes mixes "+
         "with the heady scent of smoke.");
      set_listen("default","The wind in the valley can be heard "+
         "through the walls.");
	set_items(([
      ({"walls","wall","wattle","wattle walls","panels"}) : "%^ORANGE%^"+
         "The walls are made of wattle - woven panels of osier, or "+
         "willow, that have been packed with mud to seal the cracks "+
         "and keep out the wind.  The very bottom of the walls are "+
         "made of %^RESET%^stones %^ORANGE%^shaped to fit without "+
         "mortar.  The wall facing the road is set with two large "+
         "open windows, which may be closed with shutters during "+
         "inclement weather.",
      ({"floor","dirt floor","rushes"}) : "The dirt floor is covered "+
         "with a layer of rushes taken from the lake nearby.  The "+
         "rushes look to be changed ever so often to keep them "+
         "clean.  They add a slight grassy fragrance to the shop.",
      ({"fireplace","fire","fire place"}) : "The small fireplace in "+
         "the southern end of the room provides ample lighting as well "+
         "as heat at all times of the year.",
      ({"racks","wooden racks","finished products","clothes","products"}) : 
         "All around the room stand wooden racks.  The ones closest "+
         "to the fire support drying leather to be used later, while "+
         "the ones in the center of the room hold clothing Gwanaelle "+
         "has finished."
	]));
	set_exits(([
   	   "north" : PATHEXIT"pathway23"
	]));
   set_door("pine door",PATHEXIT"pathway23","north",0);
   set_door_description("pine door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
}

void reset()
{
	::reset();
	if(!present("gwanaelle")) {
		new(MON"gwanaelle")->move(TO);
	}
}