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
	"This meditation room is for followers of deities other than Jarmila. The people"+
	" of the town often use both meditation rooms, first in thanks"+
	" to the Lady of Light and then they come to this one and pray to Ignatius."+
	" On the southern wall is a stained glass image of a large cross"+
	" which is the sign of all churches. The image is quite large"+
	" and there are small symbols for each of the gods and demi-gods"+
	" that are known to the realms, including Jarmila's sign. The"+
	" predominant color of the glass is %^BOLD%^%^RED%^ruby red%^RESET%^"+
	" and the cross is done in a %^YELLOW%^golden%^RESET%^ color. The"+
	" other images are specific to the colors of their gods. It is"+
	" quite a beautiful piece of artwork. There are two sticks of"+
	" incense, one in a holder on either side of the room. They give"+
	" off a lovely rose fragarance. The floor is covered with a"+
	" thick %^YELLOW%^cream rug%^RESET%^. In the center of the room"+
	" is a large %^BOLD%^%^RED%^crimson%^RESET%^ cushion for people"+
	" to kneel on while they meditate. The room is lit by the light"+
	" that is shed through the stained glass window."
	);
	set_smell("default","The sweet scent of fresh roses is in the air.");
	set_listen("default","Everything is peacefully quiet here.");
	set_items(([
	"incense" : "There are two sticks of incense, one on either side"+
	" of the room. They're giving off a lovely rose fragrance.",
	({"holder","holders","incense holder","incense holders"}) : "The"+
	" incense is held in a slender pewter tube that is attached to"+
	" the wall. As the incense burns down the ashes fall into the"+
	" tube instead of falling all over the room.",
	({"cushion","crimson cushion"}) : "%^BOLD%^%^RED%^There is a large"+
	" and plush crimson cushion in the center of the room.",
	({"floor","rug","cream rug"}) : "%^YELLOW%^The floor is covered by a thick"+
	" cream rug that is kept very clean.",
	"ceiling" : "The ceiling is high and flat.",
	({"glass","stained glass","window","stained glass window","south wall","southern wall"}) : "On the southern wall is a rectangular"+
	" window of stained glass. The background color is a bright"+
	" %^BOLD%^%^RED%^ruby red%^RESET%^ and there is a large ornate"+
	" %^YELLOW%^golden cross%^RESET%^ in the center of the picture."+
	" Around the edges are the symbols of all the different gods"+
	" and demi-gods of the realms, each image in the colors appropriate"+
	" to that god. It is a very impressive piece of art work."
	]));
	set_exits(([
	"north" : ROOMS+"church4"
	]));
}
