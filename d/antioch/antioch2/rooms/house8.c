#include <std.h>
#include "/d/antioch/antioch2/antioch.h"
//#include "../antioch.h"
#define BUTTERFLY "%^GREEN%^b%^YELLOW%^u%^BLUE%^t%^CYAN%^t%^MAGENTA%^e%^RESET%^%^BLUE%^r%^RED%^f%^YELLOW%^l%^CYAN%^y%^RESET%^"
inherit VAULT;

void create() {
	::create();
        set_terrain(WOOD_BUILDING);
	set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
   //set_property("no teleport",1);
	set_short("Lliira's House");
	set_long(
	"A %^BOLD%^RED%^red%^RESET%^ and %^MAGENTA%^violet%^RESET%^ carpet covers"+
   " the floor of the house. The walls are a \n%^MAGENTA%^deep plum%^RESET%^"+
   " shade with a %^BOLD%^white%^RESET%^ trim. A few oil lamps are hung on"+
   " the walls. The living room is on the east side of the house. There is a"+
   " large couch, its back facing the south wall. In front of it is a red"+
   " wood coffee table with a vase of %^YELLOW%^yellow roses%^RESET%^ on top"+
   " of it. There is a smaller couch on the other side of the coffee table,"+
   " with chairs on either end of it that face inwards. There is a fireplace"+
   " along the eastern wall that keeps the living room warm.  On the west side of"+
   " the house is the dining room. The dining table and matching chairs are"+
   " made out of polished red wood. A crystal vase sits in the center of the"+
   " dining table with a boquet of %^BOLD%^%^RED%^red roses%^RESET%^ in it."+
   " The kitchen is in the northwestern corner of the room. There is a stove"+
   " in the far corner and a sink in the center of the north wall. Several"+
   " jars of dried herbs have been carefully arranged against one wall."+
   " There are several drawers and counters for dishes and silver ware to be"+
   " stored in. In the center of the north wall is a screen door that leads"+
   " out to the backyard. In the northeastern corner is the bedroom. You can"+
   " see an extravagent red wood bed in the far corner. A matching dresser"+
   " is along the back wall, next to it is a lamp on a tall stand. There is"+
   " a mirror with a red wood frame as well next to the lamp stand.  As you"
   " glance around the room again, a %^BOLD%^vivid oil painting%^RESET%^"
   " in a %^BLUE%^blue marble frame%^RESET%^ over the fireplace"
   " catches your eye."
	);
	set_smell("default","The pleasant scent of roses fills the room.");
	set_listen("default","The house is quiet.");
	set_items(([
	"painting" : "The painting is encased in a %^BLUE%^blue marble "
"frame%^RESET%^.  The painting itself is of a %^GREEN%^forest landscape "
"with numerous trees %^RESET%^in the far distance.  There are larger trees "
"near the focal point, which are a male and female figure.  The two "
"figures seem to be %^BOLD%^%^CYAN%^quite happy %^RESET%^and look as if "
"they are moving toward you.  In the near background, there is a quaint "
"little house with %^YELLOW%^lights %^RESET%^on inside and "
"%^BOLD%^%^BLACK%^smoke %^RESET%^coming from the %^RED%^chimney%^RESET%^.  "
"There is a %^BOLD%^silver wolf %^RESET%^chasing a very colorful "+BUTTERFLY+"."
"  The %^BOLD%^silver wolf %^RESET%^appears old in the eyes, but still looks "
"strong and able to run.  The "+BUTTERFLY+" looks to be ever young and "
"vibrant with color and life.  A %^YELLOW%^full moon %^RESET%^is "
"%^BOLD%^shining %^RESET%^upon the dark %^GREEN%^forest landscape%^RESET%^.",
	({"floor","carpet"}) : "%^BOLD%^%^RED%^The"+
	" carpet is very thick and soft. It is done in rich shades of red and"+
   " %^RESET%^%^MAGENTA%^violet%^BOLD%^%^RED%^ in a pattern of interlocking"+
   " circles.%^RESET%^",
	"ceiling" : "The ceiling is boring and dull.",
	"yellow roses" : "%^YELLOW%^Some lovely yellow roses sit in a vase on the"+
	" coffee table, sending off a wonderful smell.%^RESET%^",
	"vase" : "%^BOLD%^A little porcelain vase sits on the coffee table, it is"+
	" full of %^YELLOW%^yellow roses%^WHITE%^ that are quite beautiful.",
	({"coffee table","red wood coffee table"}) : "%^RED%^A large red wood"+
	" coffee table sits in the center of the living room. It is quite lovely."+
	" and has a vase of %^YELLOW%^yellow roses%^RESET%^%^RED%^ sitting on"+
	" top of it.%^RESET%^",
	({"wall","walls"}) : "The walls have been painted a %^MAGENTA%^deep plum."+
	" shade and have a %^BOLD%^white%^RESET%^ trim. Oil lamps are hung from"+
	" them at intervals.%^RESET%^",
	({"lamps","oil lamps","oil lamp"}) : "Oil lamps are hung at intervals"+
	" along the walls. They shed light on the room.",
	({"couch","large couch"}) : "%^BOLD%^A large white couch is on the east side"+
	" of the room, it sits with its back facing the south wall. It could hold"+
	" four people comfortably.%^RESET%^",
	({"small couch","smaller couch"}) : "%^BOLD%^A smaller couch sits across"+
	" from the large one. It is a matching white and could seat about three"+
	" people comfortably.%^RESET%^",
	"chairs" : "Some red wood chairs sit on either end of the coffee table,"+
	" facing eachother. They have been padded with %^MAGENTA%^violet%^RESET%^"+
	" cushions to make them more comfortable.",
	({"dining table","table","red wood table"}) : "%^RED%^An oval shaped red"+
	" wood dining table sits on the west side of the room. Six matching red"+
	" wood chairs surround it. On the center of the dining table several %^BOLD%^red"+
	" roses%^RESET%^%^RED%^ are held in a crystal vase.%^RESET%^",
	({"red wood chairs","dining chairs"}) : "%^RED%^Six matching red wood"+
	" chairs have been placed around the oval shaped dining table.%^RESET%^",
	"crystal vase" : "%^BOLD%^A beautiful crystal vase sits in the center of"+
	" the dining table. It has a star pattern cut into it and holds several"+
	" %^RED%^red roses%^WHITE%^ that give off a lovely fragrance.%^RESET%^",
	"red roses" : "%^BOLD%^%^RED%^Several lovely red roses are in a crystal"+
	" vase on the dining room table. They are very large and their sweet"+
	" fragrance fills the room.%^RESET%^",
	({"cabinets","drawers"}) : "There are several cabinets and counters in"+
	" the kitchen that hold the dishes and silverware.",
	"sink" : "A metal sink with a spicket pump is in the center of the far"+
	" wall of the kitchen.",
	({"counter","counters"}) : "The counters that stretch out along the kitchen"+
	" are kept very clean. Some jars of dried herbs are arranged on top of"+
	" them.",
	"stove" : "A clean stove is tucked into the far corner of the kitchen.",
	({"jars","herbs","dried herbs"}) : "Several jars of dried herbs are arranged"+
	" in order on top of the counters.",
	({"bed","red wood bed","extravagent bed"}) : "%^RED%^An extravagent red"+
	" wood bed is in the far corner of the bedroom. A %^MAGENTA%^violet%^RED%^"+
	" bedspread covers it, contrasting nicely with the wood.%^RESET%^",
	"bedspread" : "%^MAGENTA%^A violet bedspread made out of thick cotton"+
	" is laid across the %^RED%^red wood%^MAGENTA%^ bed.%^RESET%^",
	({"dresser","red wood dresser"}) : "%^RED%^A beautiful red wood dresser"+
	" has been placed along the length of one of the bedroom walls. It is"+
	" almost six feet long and is about four and a half feet tall, able to"+
	" hold a lot of clothes. Next to it is a tall lamp that lights the room.",
	({"lamp","standing lamp","tall lamp"}) : "A standing lamp is in the bedroom"+
	" next to the dresser. It has a %^MAGENTA%^violet%^RESET%^ lamp shade"+
	" over it and it lights the little bedroom rather well.",
   ({"mirror","red wood mirror"}) : "%^WHITE%^%^BOLD%^Next to the lamp stand"+
   " against the east wall of the house is a large standing mirror with a"+
   " lovely %^RESET%^%^RED%^red wood%^BOLD%^%^WHITE%^ frame.%^RESET%^",
	"back door" : "A screen door leads out to the back yard.",
	"door" : "%^MAGENTA%^A deep plum door leads out the front of the house.%^RESET%^",
   "fireplace" : "There is a red brick fireplace along the eastern wall. Several"+
   " cedar logs have been stacked inside and it looks as though it has been used"+
   " recently. It probably keeps this house quite warm during the cold winters.",
	]));
	set_exits(([
	"south" : ROOMS+"yard8",
	"north" : ROOMS+"backyard2",
	]));
	set_door("door",ROOMS+"yard8","south",0);
   set_locked("door",1);
	set_door("back door",ROOMS+"backyard2","north","lliira house key");
}

void init()
{
   ::init();
   add_action("whistle","whistle");
}

void whistle(string str)
{
   if(str != "melody") return 0;
   if((string)TP->query_name() != "lliira" && (string)TP->query_name() != "singer" && !avatarp(TP)) return 0;
   find_object_or_load("/d/antioch/antioch2/rooms/yard8");
   if(!query_locked("door")) {
      tell_object(TP,"You whistle a catchy melody and hear the door click as it locks.");
      tell_room(ETP,""+TPQCN+" whistles a catchy melody and you hear the"+
      " door click as it locks.",TP);
      TO->set_open("door",0);
      TO->set_locked("door",1);
      "/d/antioch/antioch2/rooms/yard8"->set_locked("door",1);
      "/d/antioch/antioch2/rooms/yard8"->set_open("door",0);
      return 1;
   }
   tell_object(TP,"You whistle a catchy melody and the door unlocks itself.");
   tell_room(ETP,""+TPQCN+" whistles a catchy melody.",TP);
   TO->set_locked("door",0);
   "/d/antioch/antioch2/rooms/yard8"->set_locked("door",0);
   return 1;
}

