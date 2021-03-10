#include <std.h>
#include "../antioch.h"
inherit CVAULT;

void create()
{
    set_monsters( ({ "/d/antioch/antioch2/mons/royal_guard", }), ({ 12, }));
	::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("%^BOLD%^%^RED%^Royal Throne Room");
	set_long(
	"You have entered the royal throne room of Antioch's palace. The carpet"+
	" here is %^YELLOW%^golden%^RESET%^ with a %^BOLD%^%^RED%^red%^RESET%^"+
	" rug that runs from the double doors straight to the throne. The throne"+
	" is set on a dias that is slightly raised, with three steps leading up"+
	" to it. The throne itself is quite impressive. It seems to be made"+
	" entirely of %^YELLOW%^gold%^RESET%^ with various precious gems set into"+
	" it. It is padded with %^RED%^%^BOLD%^red cushions%^RESET%^ for comfort."+
	" Behind the throne stands the large banner of Antioch, framed by two"+
	" %^BOLD%^%^RED%^red curtains%^RESET%^ that are pulled back against the"+
	" wall. There are ornate chairs and benches all around the room for"+
	" guests and visiting diplomats to sit in while the king holds audience."+
	" A great chandelier hangs down in the center of the room, lighting"+
	" everything. On the east is a heavy door that probably leads to the"+
	" king's chambers."
	);
	set_smell("default","The soothing scent of vanilla floats in the air.");
	set_listen("default","A respectful silence cloaks the room.");
	set_items(([
	({"carpet","floor"}) : "%^YELLOW%^The floor is covered by a lovely golden"+
	" carpet.",
	({"rug","red rug"}) : "%^BOLD%^%^RED%^A red rug is rolled out from the"+
	" double doors up to the king's throne.",
	({"throne","royal throne","gold throne"}) : "%^YELLOW%^The throne is"+
	" very impressive, being made from pure gold. Various precious gems are"+
	" set in the arms and back of the chair. It is padded with %^RED%^red"+
	" cushions%^YELLOW%^ for comfort.",
	({"gems","precious gems"}) : "You recognize %^BOLD%^diamonds,"+
	" %^GREEN%^emeralds, %^BLUE%^sapphires%^RESET%^ and %^BOLD%^%^RED%^rubies%^RESET%^"+
	" as just a few of the precious gems set into the throne.",
	({"red cushions","cushions"}) : "%^BOLD%^%^RED%^Red cushions are used"+
	" to pad the throne, making it comfortable.",
	({"bench","benches","chair","chairs","ornate chairs","ornate benches"}) : "Ornate"+
	" chairs and benches line the room. They are for guests and diplomats to"+
	" sit in while the king holds audience. The benches have intricate designs"+
	" carved into their backs and arms. The chairs are padded with %^RED%^crimson%^RESET%^"+
	" cushions to give more comfort.",
	({"banner","crest"}) : "Behind the throne hangs the royal banner of"+
	" Antioch. A beautiful %^BOLD%^white pegasus%^RESET%^ stands sideways on"+
	" a field of royal %^MAGENTA%^purple%^RESET%^.",
	({"curtain","curtains","red curtains"}) : "%^BOLD%^%^RED%^Two red"+
	" curtains frame Antioch's large banner. They are pulled back against the"+
	" wall.",
	"chandelier" : "Hanging down from the center of the ceiling is a sparkling"+
	" crystal chandelier. Instead of candles, however, enchanted light"+
	" stones are set into it. They will never go out and can be dimmed or"+
	" brightened on command. They glow a warm %^YELLOW%^yellow%^RESET%^"+
	" color and shine light upon the room.",
	"ceiling" : "The light from the chandelier dances across the ceiling.",
	({"double doors","doors","steel doors"}) : "The double doors to"+
	" the north are made out of solid steel and are at least an inch thick."+
	" Platinum, electrum, gold, and silver are overlaid into patterns on the"+
	" door. Multi-hued stones have also been gilded into the door in"+
	" spectacular style. Although the patterns are quite beautiful, they are"+
	" also undoubtedly enchanted with magic to keep intruders out of the"+
	" throne room.",
	({"door","heavy door","east door"}) : "On the eastern wall is a very"+
	" heavy door that probably leads to the king's chamber.",
	({"dias","steps","stairs"}) : "Three steps lead up to the platform that"+
	" the throne is on. Being elevated gives the court a better view of their"+
	" king and the proceedings taking place on the throne.",
	({"wall","walls"}) : "The walls have been painted a neutral beige color"+
	" that matches with the rest of the room.",
	]));
	set_exits(([
	"south" : ROOMS+"pal8",
	"east" : ROOMS+"pal11",
	]));
	set_door("double doors",ROOMS+"pal8","south","antioch palace key");
	set_door("door",ROOMS+"pal11","east","antioch king's key");
	set_string("door","open","You carefully open the door to the king's chambers.");
	set_string("double doors","open","The double doors open slowly, leading"+
	" back out to the hallway.");
	if(query_night() == 1) {
		set_open("double doors",0);
		set_locked("double doors",1);
		set_open("door",0);
		set_locked("door",1);
		find_object_or_load("/d/antioch/antioch2/rooms/pal11");
		"/d/antioch/antioch2/rooms/pal11"->set_open("door",0);
		"/d/antioch/antioch2/rooms/pal11"->set_locked("door",1);
	}
}

// Removing the NPC from spawning; kids think it's appropriate to waltz in, kill him, and claim to have taken over Antioch.
// Seems an easier solution if they want to play it through that they can avmail and do it appropriately. N, 11/14.
/* void reset()
{
   if(query_night() != 1) {
      if(!present("onaleron")) {
         new(MONS+"advisor1.c")->move(TO);
      }
      if(!present("sedrin")) {
         new(MONS+"advisor2.c")->move(TO);
      }
      if(!present("mudric")) {
         new(MONS+"advisor3.c")->move(TO);
         }
      if(!present("king")) {
         new(MONS+"king")->move(TO);
      }
      return 1;
   }
} */
