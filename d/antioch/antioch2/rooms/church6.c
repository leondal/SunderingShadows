#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Meditation Room");
	set_long(
	"This meditation room is meant for the followers of Jarmila, Lady of"+
	" Light. It is a place for them to clear their minds and"+
	" commune with their goddess, seeking inner peace. Here they can ask"+
	" for forgiveness for any wrongs they have committed, and guidance"+
	" if they are in need of it. There is no guarantee that the deity will"+
	" answer, but all the followers say they can feel the presence"+
	" of their goddess strongly in this room. The room itself is decorated"+
	" rather simply. There are white cushions covering the northern"+
	" part of the room for followers to kneel or lay on. On the north"+
	" wall is a stained glass image of the holy symbol of Jarmila. A wide"
      " %^YELLOW%^yellow pane %^RESET%^makes up the %^YELLOW%^shield %^RESET%^while"
      " smaller %^BOLD%^%^RED%^red %^RESET%^and %^GREEN%^green %^RESET%^pieces"
      " form the rose and its leaves. It is angled in such a way that"+
	" the symbol shines directly down onto the center pillow. That"+
	" is the favored place for followers to meditate. There are two"+
	" sticks of incense in holders, one on either side of the room."+
	" They smell of soothing vanilla. Although there aren't any lamps"+
	" or candles in the room, it is still somehow brightened with"+
	" some light. This room gives you a very peaceful feeling."
	);
	set_smell("default","The soothing scent of vanilla incense calms"+
	" you.");
	set_listen("default","Everything is peacefully quiet.");
	set_items(([
	({"cushions","cushion","pillow","pillows","white cushions","white pillows"}) : "%^BOLD%^Soft white cushions cover the floor of half"+
	" the room. Followers of Jarmila can kneel or lay down on them for"+
	" meditation and communion with their god.",
	"incense" : "%^YELLOW%^There are two sticks of incense, one on either side"+
	" of the room. They are a light cream color and smell of vanilla.",
	({"holder","holders","incense holder"}) : "The incense holders"+
	" are slender pewter tubes that are fixed to the wall. As the"+
	" incense burns down into them, they collect the ashes.",
	"floor" : "The floor is covered with a white woolen rug that is"+
	" incredibly soft to the touch. It is kept immaculately clean.",
	"ceiling" : "The ceiling is high up and completely flat, made of"+
	" the stone blocks that the rest of the building is built from."
	]));
	set_exits(([
	"south" : ROOMS+"church4"
	]));
}
