#include <std.h>
#include "../cleric.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("no teleport",1);
	set_property("indoors",1);
	set_property("light",3);
	set_short("%^BOLD%^Library of Antioch");
	set_long(
	"%^YELLOW%^You are awe-struck as you enter the room. The library is magnificent,"+
	" definetly not what you were expecting here. It is almost like walking"+
	" into another world. The walls and floor are made of solid %^WHITE%^marble%^YELLOW%^ instead"+
	" of stone bricks. Your footsteps echo off the walls and the room seems"+
	" somehow larger. %^WHITE%^Marble pillars%^YELLOW%^ are placed about the room, giving this"+
	" place the feel of a god's pantheon. There are hundreds of books around"+
	" the room, each in every known language. They are all religious books"+
	" from around the world, telling of the different faiths. There are a"+
	" few chairs and desks to your right if you wish to sit down and read"+
	" something. Although there doesn't appear to be any light source the"+
	" room is lit with a warm golden glow."
	);
	set_smell("default","The light fragarance of gardenias drifts about the"+
	" room.");
	set_listen("default","There is a silent reverence to the room.");
	set_items(([
	"floor" : "%^BOLD%^The floor is made out of white marble that is swirled"+
	" with %^RED%^red%^WHITE%^ and seems to have specks of %^YELLOW%^gold%^WHITE%^"+
	" in it. It is kept very clean and your footsteps echo as you walk across"+
	" it.",
	"ceiling" : "%^BOLD%^The ceiling is made out of white marble with %^RED%^red%^WHITE%^"+
	" swirls and specks of %^YELLOW%^gold%^WHITE%^ in it. The odd thing is"+
	" that the %^RED%^red%^WHITE%^ swirls are in constant motion. They form a"+
	" sunrise, mid-day, and sunset, then repeat the process over, though never"+
	" quiet in the same pattern. It is beautiful to watch.",
	({"wall","walls"}) : "%^BOLD%^The walls are made out of white marble with"+
	" swirls of %^RED%^red%^WHITE%^ and specks of %^YELLOW%^gold%^WHITE%^ in"+
	" it. They are slanted outwards, giving the room a feeling that it's"+
	" larger than it really is.",
	({"pillar","pillars","marble pillar","marble pillars"}) : "%^BOLD%^There"+
	" are several marble pillars around the room. They are round in shape"+
	" with spiral grooves travelling around their length and rectangular"+
	" bases and tops. It is an older style of pillar, but quite appropriate."+
	" There are eight total pillars, two are in the middle of the room supporting"+
	" a book shelf, there are two on each side of the remaining three book"+
	" shelves that are against the walls of the room.",
	({"book shelf","book shelves","bookshelf","bookshelves"}) : "There are"+
	" four large book shelves about the room. One is in the center of the"+
	" room, two are on the north and south walls respectively, and one is"+
	" against the far east wall. Each has two marble pillars on the ends to"+
	" help support it.",
	"books" : "There are hundreds of books around the room in every known"+
	" language, and even some that have been long forgotten. The books are"+
	" about the gods and goddesses of the realms, along with demi-gods and"+
	" powerful spirits. You can %^BOLD%^read about%^RESET%^ the different"+
	" gods and goddesses if you like.",
	({"desk","desks"}) : "A few large hickory desks are placed in the"+
	" southwestern corner of the room. Matching chairs are situated around"+
	" them. They can be used for studying or researching.",
	({"chair","chairs"}) : "A couple large padded chairs that are more like"+
	" small couches are placed near the desks. You can curl up there and read"+
	" about whatever god you choose undisturbed.",
	"door" : "How strange, from this side of the room the door looks as though"+
	" it is made out of marble and it has a golden door knob.",
	]));
	set_exits(([
	"west" : ROOMS+"cleric3",
	]));
	set_door("door",ROOMS+"cleric3","west",0);
	set_string("door","open","%^YELLOW%^The marble door swings smoothly open.");
}
