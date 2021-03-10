#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit GRAVEYARD2;

void create() {
  int x;
  ::create();
 	set_long(TO->query_long() + "%^BOLD%^%^WHITE%^  A large above ground %^RESET%^tomb%^BOLD%^"+
			"%^WHITE%^ stands among the ruin of the headstones and statues.  It has resisted "+
			"the erosion of time quite well with only the color of it fading to a dull white.  "+
			"A %^RESET%^stone wall%^BOLD%^%^WHITE%^ runs along the outside of the graveyard here."+
			"%^RESET%^");
 	for(x = 0;x < sizeof(SW_ITEM);x++) {
		add_item(SW_ITEM[x],"%^BOLD%^%^WHITE%^This pathetic stone wall is only around two feet "+
			"high and is mostly in a state of ruin.  It runs toward the east and the west here, "+
			"serving as a marker for the territory of the graveyard.%^RESET%^");
	 }

	add_item("tomb","%^BOLD%^%^WHITE%^This large tomb stands in contrast against the ruined "+
	 "headstones and statues here.  The outside of it has faded to a dull white over the "+
		"course of time, yet there is no visible structural damage.  A massive ornate door "+
		"seals the entrance of it.%^RESET%^");

 set_exits(([
   "west":GY_ROOMS +"grave8-5",
			"south" : GY_ROOMS +"grave7-4",
   "tomb":GY_ROOMS +"crypt",
   "east" : GY_ROOMS +"grave8-3"
  ] ));

	set_door("ornate door",GY_ROOMS +"crypt","tomb");// add some keys for this place? Saide
	//,"graveyard key","lock");

 set_string("ornate door", "open", "%^RED%^The massive door swings open with a loud grating "+
		"noise and stale air mixed with a heavy scent of decay pours out.%^RESET%^");

 set_door_description("ornate door","%^BOLD%^%^WHITE%^This massive ornate door is made from "+
		"a slab of stone that has faded to a dull white over the course of time.  Painted on the "+
		"front of it, in a blood red, is an empty throne, the crown of the one who once sat on it "+
		"laying lazily in the seat.%^RESET%^");
}
