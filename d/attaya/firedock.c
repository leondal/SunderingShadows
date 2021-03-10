#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",0);
    set_terrain(SHORE);
    set_travel(PAVED_ROAD);
    set_short("Granite pier on the River of Flame.");
    set_long("%^BOLD%^%^BLACK%^You stand upon a granite slab above a fast "+
	"moving %^RED%^ri%^BLACK%^v%^RESET%^%^RED%^e%^BOLD%^r %^BLACK%^of "+ 
	"%^RED%^mol%^BLACK%^t%^RESET%^%^RED%^e%^BOLD%^n "+ 
	"me%^BLACK%^t%^RESET%^%^RED%^a%^BOLD%^ls%^BLACK%^! Clouds of "+ 
	"%^RED%^gl%^RESET%^%^RED%^o%^BOLD%^wi%^BLACK%^n%^RESET%^%^RED%^g "+ 
	"%^BOLD%^re%^BLACK%^d "+ 
	"%^RESET%^%^RED%^s%^BOLD%^pa%^BLACK%^r%^RESET%^%^RED%^k%^BOLD%^s "+ 
	"%^BLACK%^and smoke pour past you making you cough and obstructing "+ 
	"any view of what lies at the other side of the river. "+
	"\n\nA %^RESET%^%^ORANGE%^mooring pole %^BOLD%^%^BLACK%^sways under the "+ 
	"weight of an %^RESET%^invisible ship%^BOLD%^%^BLACK%^!\n%^RESET%^");

     set_listen("default","The churning river of fire is deafening.");
     set_smell("default","You are forced to cover your nose and mouth as the smoke burns them..");
 
    set_exits(([

//       "west" : "/d/attaya/jun33",
      "west": "/d/attaya/jungle/rift20"
//changed by ~Circe~ 6/6/11

    ] ));
    set_items(([
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "pier" : "Standing and enduring the oceans torture has seriously compromised the structural integrity of the pier...  In other words...  %^RED%^It would be wise to get off as soon as possible.",
    ] ));
find_object_or_load("/d/attaya/cliff20.c");
}
void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/riptide.c"}),75,1);
}
