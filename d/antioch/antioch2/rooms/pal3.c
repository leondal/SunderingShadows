#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^BOLD%^Dining Room");
	set_long(
	"This is the dining room of Antioch's palace. It is here that visiting"+
	" dignitaries are served and large gallas are held. The room is quite"+
	" large and could hold several hundred people. Nearest the door fine"+
	" walnut tables have been placed with matching chairs. Delicate %^BOLD%^white lace%^RESET%^"+
	" tablecloths are spread over the tables. Silver candelabras are placed"+
	" at intervals along the tables, each one holds three %^YELLOW%^yellow%^RESET%^"+
	" candles. In the center of each table is a crystal vase filled with"+
	" lovely wildflowers that have been arranged in a beautiful boquet."+
	" The floor here is covered with polished squares of wood that fit"+
	" perfectly together. Each large square is designed with light to dark"+
	" patterns of triangles that form a sunburst. The wood is perfect for"+
	" dancing on. The walls of the room are decorated with thick %^GREEN%^pine"+
	" curtains%^RESET%^ that are looped in intricate patterns. Extravegant"+
	" tapestries of men and women dancing are framed within the looping"+
	" curtains. The room is lit by sparkling chandeliers that hang from the"+
	" ceiling. On the northern wall, hidden discreetly among the curtains,"+
	" is the door to the kitchen. From there the servants and chefs come"+
	" through to serve the guests."
	);
	set_smell("default","The light scent of honeysuckle fills the air.");
	set_listen("default","You can almost hear the lovely music that would"+
	" be playing during a ball.");
	set_items(([
	({"floor","wood square","wood panel","squares of wood"}) : "The floor is"+
	" covered with large squares of wood that fit together perfectly and"+
	" create a good surface for dancing. Each square has triangles of light"+
	" and dark shades that form a beautiful sunburst pattern. It is kept"+
	" remarkably free from dirt and scuffs.",
	"ceiling" : "From the ceiling hang five large crystal chandeliers that"+
	" light the room. There is one near each corner of the room, and one in"+
	" the very center.",
	({"chandelier","chandeliers","crystal chandeliers"}) : "Five spectacular"+
	" crystal chandeliers hang down from the ceiling. They sparkle magnificently,"+
	" like glittering diamonds.",
	({"candelabra","candelabras","silver candelabras"}) : "Highly polished"+
	" silver candelabras are spaced out on each table. Each one holds three"+
	" %^YELLOW%^yellow%^RESET%^ candles that are honeysuckle scented.",
	({"candle","candles","honeysuckle candles","yellow candles"}) : "%^YELLOW%^Three"+
	" honeysuckle candles are in each candelabra. Their fragrance pleasantly"+
	" fills the room.",
	({"table","tables","walnut tables","dining tables","walnut table","dining table"}) : "Four"+
	" large walnut tables are set up along the western length of the room."+
	" Each is covered in a %^BOLD%^white lace%^RESET%^ tablecloth. Silver"+
	" candelabras are spaced at intervals along their length and in the"+
	" center of each table is a crystal vase with a boquet of fresh wildflowers.",
	({"flowers","wildflowers"}) : "Boquets of beautiful fresh wildflowers"+
	" are found in each crystal vase on the dining tables. They are made"+
	" mostly of %^MAGENTA%^violets%^RESET%^ and %^BOLD%^%^RED%^wild roses%^RESET%^"+
	" along with %^BOLD%^daisies%^RESET%^ and other such flowers. They've"+
	" been artistically arranged to be shown off to best advantage.",
	({"vase","crystal vase","vases","crystal vases"}) : "In the center of"+
	" each dining room table is a crystal vase that is filled with beautiful"+
	" wildflowers. The vases themselves are engraved with delicate designs"+
	" of miniature flowers.",
	({"lace","white lace","tablecloths","lace tablecloths","white lace tablecloths"}) : "%^BOLD%^Delicate white lace tablecloths cover each dining"+
	" room table in a simple but beautiful pattern.",
	({"walls","wall"}) : "All the walls are covered in %^GREEN%^pine green%^RESET%^"+
	" curtains that are fashioned in intricate loops and designs. Some of the"+
	" loops frame extravegant tapestries.",
	({"curtain","curtains","pine curtains","pine green curtains"}) : "%^GREEN%^Thick"+
	" pine curtains cover the walls. Intricate loops and twists are created"+
	" from extra curtain at the top of the walls. Some of loops are designed"+
	" to frame extravagent tapestries which can be found around the room.",
	({"tapestry","tapestries","extravagent tapestries"}) : "Extravegant"+
	" tapestries of men and women dancing are framed within the looping"+
	" curtains. On the far side of the room are tapestries of fairies, nymphs"+
	" and satyrs, dryads, sprites, and other such creatures dancing and"+
	" frolicking through meadows and forests.",
	({"door","mahogany door"}) : "A thick door made from a solid piece of"+
	" mahogany wood is on the southwestern wall. The edges are engraved with"+
	" holly leaves, a lovely design. The door leads to the hallway and entrance"+
	" of the palace.",
	({"kitchen door","north door","northern door"}) : "On the northwestern"+
	" corner of the room is a small door that has been discreetly placed"+
	" between loops of curtain. It is painted a matching %^GREEN%^pine green%^RESET%^"+
	" to blend in with the other walls. It is the entrance through which the"+
	" chefs and servants come to serve the guests.",
	"chairs" : "Matching walnut chairs are seated around the dining room"+
	" tables.",
	]));
	set_exits(([
	"west" : ROOMS+"pal2",
	"north" : ROOMS+"kitchen",
	]));
	set_door("door",ROOMS+"pal2","west",0);
	set_string("door","open","The mahogany door swings open easily.");
	set_door("kitchen door",ROOMS+"kitchen","north",0);
}
