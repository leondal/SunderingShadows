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
	set_short("%^BOLD%^Room of the novice acolytes");
	set_long(
	"This room is decorated rather simplisticly. There are two sets"+
	" of bunk beds tucked into the far right corner of the room."+
	" There are some chests stacked at the foot of each bed, they"+
	" are probably filled with the belongings of the novice acolytes."+
	" On the left side there is a book shelf against the far wall and"+
	" two desks are placed side by side on the north wall. There are"+
	" candles on the desks that have been melted down to stubs from"+
	" the acolytes studying for long hours. A square rug covers the"+
	" center of the room. It is designed with a scene of the start of"+
	" spring. Buds of flowers and grass are pushing themselves above"+
	" the melting snow on a hill. On the back wall is a small picture"+
	" of a Knight of Jarmila. The Knight is boldly standing in protection"+
	" of several small children while attempting to keep back several"+
	" bandits who are attacking from horse-back. The rug and the"+
	" picture are the only decorations in the room."
	);
	set_smell("default","The scent of spiced apples drifts in from"+
	" beneath the door.");
	set_listen("default","The room is completely silent.");
	set_items(([
	({"floor","rug"}) : "%^BOLD%^%^GREEN%^The square rug covers the"+
	" center of the floor. It depicts the beginning of spring. Trees"+
	" are beginning to sprout new leaves and grass and %^YELLOW%^flowers%^GREEN%^"+
	" are pushing themselves up through the melting %^WHITE%^snow.",
	({"desk","desks"}) : "Two plain wooden desks are on the northern"+
	" wall. Apparently the acolytes spend a lot of their time studying"+
	" for there are several candle stubs that have been burned for"+
	" hours. Ink stains dot the tops of the desks. Wooden chairs"+
	" that don't look very comfortable are next to each desk.",
	({"candle","candles","candle stubs","candle stub"}) : "Several"+
	" candles have been burned down to stubs on top of the desks. The"+
	" wax has melted over a section of the desk and will have to be"+
	" scraped off eventually.",
	({"chair","chairs"}) : "Two rather uncomfortable looking wooden"+
	" chairs match the desks.",
	"book shelf" : "A tall and sturdy book shelf is positioned in the"+
	" back left corner of the room. It is filled with volumes of rather"+
	" dull text books that the novice acolytes are required to read.",
	"books" : "These books look like they would bore anyone to death.",
	({"ink","ink stains","ink spots"}) : "Ink stains are spattered"+
	" across the top of the desks.",
	({"picture","painting","small picture"}) : "%^BOLD%^The picture"+
	" shows a scene of a Knight of Jarmila defending several small children"+
	" from bandits who are attacking from horse-back. The Knight is"+
	" calm and sure in his duty and would clearly give his last breath"+
	" to save the children. Such a person is what the acolytes aspire"+
	" to be.",
	({"bed","beds","bunk bed","bunk beds"}) : "There are two sets of"+
	" bunk beds in the right hand corner. The blankets are all a plain"+
	" gray color and each bed is neatly made.",
	({"chest","chests"}) : "There are four chests, two at the foot of"+
	" each bunk bed. They probably hold the acolytes' clothes and"+
	" belongings.",
	({"blanket","blankets"}) : "The blankets appear to be made of"+
	" wool, though they don't look very soft. They have been dyed a"+
	" drab gray color and aren't very appealing.",
	"door" : "This is a plain wooden door that leads out into the"+
	" hallway."
	]));
	set_exits(([
	"west" : ROOMS+"church7"
	]));
	set_door("door",ROOMS+"church7","west",0);
}

void reset()
{
	::reset();
	if(!present("acolyte")) {
		switch(random(3)) {
			case 0:
				new(MONS+"novice")->move(TO);
				break;
			case 1:
				new(MONS+"novice")->move(TO);
				new(MONS+"novice")->move(TO);
				break;
			case 2:
				new(MONS+"novice")->move(TO);
				new(MONS+"novice")->move(TO);
				new(MONS+"novice")->move(TO);
				break;
		}
	}
}
