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
	set_short("A lovely little house");
	set_long(
   "Korath's home\n"+
	"This is a pretty little house. The walls are painted a glossy"+
	" %^BOLD%^white%^RESET%^ color, and the house appears quite clean."+
	" On the west is a living room with a long couch, a few chairs"+
	" and a love seat. A coffee table is set up in the middle of them"+
	" with a vase of %^YELLOW%^daisies%^RESET%^ on top of it. A pretty"+
	" %^BLUE%^blue%^RESET%^ throw rug is laid out on the living room"+
	" floor. On the east is a dining area with a long oak table. In"+
	" the center of the table is a silver candelabra that is quite"+
   " charming. In the southeastern corner is the kitchen with the"+
	" bedroom across from it." 
	);
	set_smell("default","You can still smell the clean mountain air.");
	set_listen("default","The house is quiet.");
	set_items(([
	({"chair","chairs"}) : "%^BOLD%^%^BLUE%^Two chairs sit next to the"+
	" couch in the living room. They are a beautiful sapphire and look"+
	" well cared for.",
	({"rug","throw rug"}) : "%^BLUE%^A pretty blue throw rug covers"+
	" the living room floor.",
	"kitchen" : "A small kitchen is tucked into the northwestern"+
	" corner of the house. There is a doorway that leads into that"+
	" area.",
	"dining room" : "The dining room is on the east side of the house."+
	" It has a lovely oak table with matching chairs. A silver"+
	" candelabra sits in the middle of the table, adding a little"+
	" elegance.",
	({"long couch","couch"}) : "%^BLUE%^A midnight blue couch rests"+
	" near a love seat and a few chairs, creating the living room. It"+
	" is quite pretty and very long, it could easily fit four people"+
	" on it.",
	"love seat" : "%^BLUE%^A matching midnight blue love seat sits"+
	" in the corner, next to the couch. It is quite charming and"+
	" could fit two people on it rather snuggly.",
	"bedroom" : "A little bedroom is tucked into the southwestern"+
	" corner of the house. It is closed off from the other rooms"+
	" for privacy.",
	"door" : "%^BOLD%^A white door leads out the front of the house.",
	"back door" : "%^BOLD%^At the southern end of the house a back"+
	" door leads out into the yard.",
	"floor" : "The floor is made of wood, it looks very clean. There"+
	" is a rug in the living room area that is quite pretty.",
	"ceiling" : "The ceiling is rather dull, simply plain wood.",
	({"wall","walls"}) : "%^BOLD%^The walls are a spotless white"+
	" and are kept very clean. Oil lamps are attached to them to give"+
	" off light.",
	({"lamps","lamp","oil lamp","oil lamps"}) : "Oil lamps are"+
	" attached to the walls to give light to the house.",
	({"dining table","table","oak table","long table","long oak table"}) : "A"+
	" long oak dining table is on the east side of the room. Matching"+
	" chairs are positioned around it, it can seat up to six people."+
	" A silver candelabra sits in the center of the table, making"+
	" it seem more elegant.",
	({"candelabra","silver candelabra"}) : "A silver candelabra sits"+
	" in the center of the oak dining room table. It has three"+
	" %^BOLD%^white%^RESET%^ candles in it that don't look to have"+
	" even been lit yet.",
	({"candles","white candles"}) : "%^BOLD%^Three white candles that"+
	" have never been lit are placed in the candelabra.",
	"coffee table" : "A cute little walnut coffee table sits in the"+
	" middle of the living room. In the center of it is a vase of"+
	" %^YELLOW%^daisies%^RESET%^ that are very pretty.",
	"vase" : "%^BOLD%^%^CYAN%^A pretty sky blue vase sits on top of"+
	" the coffee table. It holds about six lovely %^YELLOW%^daisies%^RESET%^"+
	" that seem to brighten up the room.",
	"daisies" : "%^YELLOW%^Beautiful daisies are sitting in a vase"+
	" on top of the coffee table.",
	]));
	set_exits(([
	"north" : ROOMS+"yard2",
	"south" : ROOMS+"backyard1",
	"kitchen" :  ROOMS+"kitchen1",
	"bedroom" : ROOMS+"bedroom1",
	]));
// I'd have sworn we made these like a bolt from inside so people couldn't get locked in by a reboot or forgetting and logging out there.  Either way, I'm removing the key "antioch house key" setting from this side for that reason now per bug reports.  *Styx*  10/31/04
	set_door("door",ROOMS+"yard2","north",0);
	set_door("back door",ROOMS+"backyard1","south",0);
   set_locked("door",1);
}

void init()
{
   ::init();
   add_action("snap","snap");
}

void snap(string str)
{
   if(str != "fingers") return 1;
   if((string)TP->query_name() != "korath" && (string)TP->query_name() != "tansy" && !avatarp(TP)) return 1;
   find_object_or_load("/d/antioch/antioch2/rooms/yard2");
   if(!query_locked("door")) {
      tell_object(TP,"You snap your fingers and hear a faint click as the door locks.");
      tell_room(ETP,""+TPQCN+" snaps "+TP->query_possessive()+" fingers together and you hear a faint click as the door locks itself.",TP);
      TO->set_open("door",0);
      TO->set_locked("door",1);
      "/d/antioch/antioch2/rooms/yard2"->set_locked("door",1);
      "/d/antioch/antioch2/rooms/yard2"->set_open("door",0);
      return 1;
   }
   tell_object(TP,"You snap your fingers and hear a gentle click as the door unlocks itself.");
   tell_room(ETP,""+TPQCN+" snaps "+TP->query_possessive()+" fingers.",TP);
   TO->set_locked("door",0);
    "/d/antioch/antioch2/rooms/yard2"->set_locked("door",0);
   return 1;
}
