#include <std.h>
#include "../antioch.h"
inherit "/std/church";

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Altar of Antioch's Grand Church");
	set_long(
	"This is the altar of Antioch's church. A few stone steps lead"+
	" up to it from the west. Engraved on the eastern wall is the"+
	" %^BOLD%^symbol of Jarmila%^RESET%^. It is a large %^YELLOW%^golden"
      " shield %^RESET%^emblazoned with a %^BOLD%^%^RED%^crimson rose%^RESET%^."
      " In front of you is a large stone table that is"+
	" the altar of Jarmila. People can kneel before the altar to pray"+
	" or give offerings to the church. The church here seems to"+
	" be doing fairly well. There is a thick silk cushion on the"+
	" floor in front of the altar on which to kneel. Thick beeswax"+
	" candles are held in sconces on the walls, giving light to the"+
	" room. Incense is burning as well, giving the entire room a"+
   " sweet honeysuckle smell. To the north and south are meditation"+
   " rooms that are closed off by thick white curtains.\n"
	);
   set_smell("default","The incense here smells like honeysuckle.");
	set_listen("default","Soft prayers surround you.");
	set_items(([
	({"altar","stone altar"}) : "The large altar is made out of"+
	" polished marble. It is rectangular in shape with the legs"+
	" carved in spirals. The top of it is mostly %^BOLD%^white%^RESET%^"+
	" but %^BOLD%^%^YELLOW%^gold%^RESET%^ is swirled within it.",
	({"cushion","pillow","silk pillow","silk cushion"}) : "%^RED%^A"+
	" wine colored cushion rests on the ground in front of the altar"+
	" for people to comfortably kneel upon.%^RESET%^",
	({"candle","candles","beeswax candles","beeswax candle","white candle","white candles"}) : "%^BOLD%^Delicious"+
	" smelling thick beeswax candles line the room. They are hung"+
	" in sconces and give off gentle light.",
	({"sconce","sconces"}) : "Silver sconces are attached to the"+
	" walls. They are shaped in the symbol of a rose, and each"+
	" one holds a thick white candle.",
	"ceiling" : "The ceiling here is made out of stones. It is level"+
	" and fairly high, probably fifteen or so feet up at least.",
	"floor" : "The floor is made out of stones that are smoothly"+
	" fitted together. It looks to be well swept, you can't find a"+
	" spot of dirt anywhere.",
	"stones" : "Large stones are fitted perfectly together to create"+
	" this room.",
	"incense" : "There are a few sticks of incense in holders on the"+
	" walls around the room. They are all burning slowly, bringing"+
   " a scent of honeysuckles to the room.",
	({"curtain","curtains","white curtains","thick curtains","thick white curtains"}) : "%^BOLD%^Thick"+
	" and heavy felt curtains hang from the doorways of the rooms"+
	" to the north and south, closing them off from the altar so the"+
	" occupants can meditate in peace."
	]));
	set_exits(([
	"west" : ROOMS+"church1",
	"south" : ROOMS+"church5",
	"north" : ROOMS+"church6",
	]));
}
