#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("no sticks",1);
	set_property("light",2);
	set_short("A beautiful house");
	set_long(
	"You are on the second floor of a large house. In the northeastern corner"+
   " is a room that looks like it will one day be a nursery. The walls there"+
	" are painted a %^BOLD%^%^CYAN%^powder blue%^RESET%^ color, and there is"+
	" a crib as well. But the room is obviously unused. The south part of"+
	" the floor is taken up by a large bedroom. The walls of the bedroom"+
	" are painted %^BOLD%^white%^RESET%^ with a %^GREEN%^green%^RESET%^ trim."+
	" A thick %^GREEN%^green%^RESET%^ carpet covers the floor. A four poster"+
	" bed takes up the southwestern corner. A large closet and dresser are"+
	" against the eastern wall. Two large windows overlook the front yard."+
	" One of them is open, allowing the scent of roses to fill the room."
	);
	set_smell("default","The scent of roses drifts in from outside.");
	set_listen("default","The house is quiet.");
	set_items(([
	({"floor","carpet","rug","green carpet"}) : "%^GREEN%^The bedroom floor"+
	" is covered in a thick green carpet.",
	"nursery floor" : "%^BOLD%^%^CYAN%^The floor to the nursery is carpeted"+
	" in a powder blue color that matches the walls.",
	"ceiling" : "The ceiling is plain and rather boring to stare at.",
	"crib" : "There is a large walnut crib in the nursery, but it is obviously"+
	" new and un-used.",
	({"white walls","walls","bedroom walls"}) : "%^BOLD%^The walls of the"+
	" bedroom are painted white with %^RESET%^%^GREEN%^green%^RESET%^%^BOLD%^"+
	" trimming.",
	({"nursery walls","powder blue walls","blue walls"}) : "%^BOLD%^%^CYAN%^The"+
	" walls of the nursery have been painted a powder blue color, which would"+
	" be fine for having either a boy or a girl.",
	({"bed","four poster bed"}) : "There is a large four poster bed that"+
	" takes up most of the southwestern side of the room. The frame is made"+
	" of walnut and it is covered in a %^GREEN%^dark green%^RESET%^ bedspread"+
	" that closely matches the carpet.",
	({"bed spread","bedspread","green bedspread"}) : "%^GREEN%^A forest"+
	" green bedspread covers the bed. It appears to be made out of wool and"+
	" looks very warm and cozy.",
	"closet" : "There is a large walnut closet on the eastern side of the"+
	" room that looks like it could hold a fair amount of clothes.",
	"dresser" : "A matching walnut dresser has been positioned near the closet."+
	" It is approximately four and a half feet in height with several large"+
	" drawers. A couple things have been scattered across the top of it, like"+
	" a hair brush and a hand held mirror.",
	({"brush","hair brush"}) : "A simple hair brush is on top of the dresser,"+
	" probably used by the owner of this house and his wife.",
	({"mirror","hand mirror","hand held mirror"}) : "A small oval mirror"+
	" with an ivory handle has been left on top of the dresser.",
	"window" : "The far window has been left slightly cracked open, allowing"+
	" the fresh air in along with the lovely scent of the roses that are"+
	" growing along the side of the house.",
	"windows" : "There are two large windows on the southern side of the"+
	" house that overlook the front yard. Nothing too exciting there.",
	]));
	set_exits(([
	"down" : ROOMS+"house4",
	]));
}
