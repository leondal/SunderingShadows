#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("A little cottage");
	set_long(
	"This is a cozy little cottage. The hardwood floor looks well swept and"+
	" there is a little mat to wipe your feet on as you enter. On the east"+
	" is the living room and a large brick fireplace. A %^BOLD%^%^RED%^red%^RESET%^"+
	" throw rug has been placed on the living room floor. There is a comfortable"+
	" wooden rocking chair next to the fireplace, along with a %^BOLD%^%^MAGENTA%^mauve%^RESET%^"+
	" couch. In the northeastern corner is a bedroom. You can see a fair sized"+
	" bed with a nightstand next to it and a long dresser. On the western side"+
	" of the house is the dining room and kitchen. The dining table is made"+
	" of oak and it has a vase of %^BOLD%^gardenias%^RESET%^ sitting on top"+
	" of it. Four matching chairs surround the table. The kitchen occupies"+
	" the northwestern corner. It has a small stove and a couple of cabinets"+
   " and drawers for keeping dishes and silver ware. An assortment of herbs"+
	" is kept neatly aligned in jars. The kitchen doesn't seem to get much"+
	" use, though, it seems like most of the cooking is done over the fireplace."
	);
	set_smell("default","The sweet fragrance of gardenias fills the room.");
	set_listen("default","The house is quiet.");
	set_items(([
	"floor" : "The floor has been swept and mopped recently and is very clean.",
	({"rug","throw rug","red rug","red throw rug"}) : "%^BOLD%^%^RED%^A thick"+
	" red throw rug has been placed on the floor of the living room. You"+
	" can imagine the couple that owns this house stretched out on it next"+
	" to the fireplace on a cold winter's night.",
	"mat" : "There is a little woven straw mat at the entrance to the house"+
	" for people to wipe their feet on as they come inside.",
	({"fireplace","fire place"}) : "A large brick fireplace is on the eastern"+
	" wall of the house. Some logs are still smoldering in it from the last"+
	" time it was used. There is a spit set up across it that can be used"+
	" to roast things, or hang a kettle of stew across.",
	({"chair","rocking chair"}) : "An old rocking chair rests near the fire."+
	" It is close enough to keep someone warm if the fire were going, but not"+
	" uncomfortably so.",
	({"couch","mauve couch"}) : "%^BOLD%^%^MAGENTA%^A mauve pink couch is"+
	" set at an angle near the fireplace, facing it. It could hold at least"+
	" three people, letting them warm themselves near the fire.",
	({"table","dining table","oak table"}) : "The dining table is made of oak."+
	" It is rather small, only seating four people at the moment, but there"+
	" appears to be a section taken out of the center that can be put back in"+
	" to expand the table if needed. A clay vase sits on top of it with a small"+
	" boquet of %^BOLD%^gardenias%^RESET%^ in it.",
	({"vase","clay vase"}) : "%^YELLOW%^A yellow clay vase has been stamped"+
	" with images of a smiling sun. A boquet of %^WHITE%^gardenias%^YELLOW%^"+
	" are inside it.",
	"gardenias" : "%^BOLD%^Several large and wonderfully fragrant gardenias"+
	" are inside a vase on the dining room table.",
	({"chairs","oak chairs"}) : "Four matching oak chairs surround the dining"+
	" table.",
	"stove" : "A rather small stone stove is in the kitchen. It doesn't appear"+
	" to get much use, though.",
	({"drawers","cabinets"}) : "There are several drawers and cabinets in the"+
   " kitchen that store the dishes and silver ware.",
	({"herbs","jars"}) : "Jars of both fresh and dried herbs are placed in"+
	" neat rows along one wall of the kitchen.",
	"logs" : "Some smoldering logs are still smoking a little bit from last"+
	" night's fire.",
	"bed" : "There is a fair sized bed in the bedroom. It has a %^MAGENTA%^purple%^RESET%^"+
	" quilt with a pattern of violets on it. The quilt exactly matches the"+
	" carpeting of the bedroom floor.",
	({"quilt","purple quilt"}) : "%^MAGENTA%^A hand woven purple quilt"+
	" has a pretty pattern of violets sewn onto it.",
	"carpet" : "%^MAGENTA%^A thick purple carpet covers the bedroom floor.",
	({"night stand","nightstand"}) : "A cherry wood nightstand sits next to"+
	" the bed. A worn book and a glass of water sit on top of it.",
	({"book","worn book"}) : "This book is one of those cheap romance novels"+
	" that some bards try to sell for outrageous prices. It looks like it has"+
	" been read a lot.",
	({"glass","glass of water"}) : "A half-empty glass of water sits on the"+
	" nightstand.",
	({"dresser","long dresser"}) : "A long cherry wood dresser is against the"+
	" western wall of the bedroom. It is about four feet high and two feet"+
	" deep, able to hold a lot of clothing.",
	"ceiling" : "The ceiling is plain and boring.",
	({"wall","walls"}) : "The walls of the house have been painted %^MAGENTA%^%^BOLD%^pink%^RESET%^"+
	" with a %^BOLD%^%^RED%^rose%^RESET%^ trim. The wife most definitely"+
	" did the color scheme for this house.",
	"door" : "%^BOLD%^%^MAGENTA%^A pink door leads out the front of the house.",
	]));
	set_exits(([
	"south" : ROOMS+"yard5",
	]));
// I'd have sworn we made these like a bolt from inside so people couldn't get locked in by a reboot or forgetting and logging out there.  Either way, I'm removing the key "antioch house key" setting from this side for that reason now per bug reports.  *Styx*  10/31/04
	set_door("door",ROOMS+"yard5","south",0);
	if(query_night() == 1) {
		set_locked("door",1);
	}
	new(MONS+"citizeng")->move(TO);
}
