#include <std.h>
#include "../theater.h"
inherit ROOM;

	void create(){
   	::create();
   	set_property("indoors",0);
   	set_property("light",2);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
   	set_name("%^ORANGE%^Calimpur Street");
   	set_short("%^ORANGE%^Calimpur Street");
   	set_long("%^ORANGE%^Winding through the older section of Azha,"+
		" Calimpur street is a lesser used road.  The %^BOLD%^sandstone "+
		"%^RESET%^%^ORANGE%^road is broken and battered, with many sections"+
		" missing.  Many residents of Azha avoid this part of the city, "+
		"believing it to be haunted.  Once majestic buildings made from wood "+
		"and sandstone rise up on either side of the street.  The buildings"+
		" now are in disrepair, many of them looking as if they might crumble"+
		" at a moment's notice.  Cresting over the buildings, the top of a "+
		"large ornate theater can be seen towards the center.  Rising high"+
		" into the sky, the tops of newer %^WHITE%^limestone%^ORANGE%^ "+
		"obelisks can be seen.\n");
	set("night long","%^BLUE%^A stale breeze blows through the older "+
		"section of Azha.  Rising up on either side of the battered and "+
		"broken cobblestone road, the decrepit remains of once majestic"+
		" buildings lay.  At this hour of the night, the buildings almost "+
		"look frightening, their %^BOLD%^%^BLACK%^dark silhouettes%^RESET%^"+
		"%^BLUE%^ against the night sky.  Circling around a dark building "+
		"towards the center of this area of Azha,%^BOLD%^%^WHITE%^ glowing"+
		"%^RESET%^ limestone %^BLUE%^obelisks provide light to this area.\n");  
   	set_smell("default","A stale scent hangs in the air.");
   	set_listen("default","The sounds of bustling Ahza filters in.");
  	set_items(([
      	({"street","cobblestone road","cobblestone"}) : "%^YELLOW%^The sandstone "+
	"cobblestone road looks quite old and at one time well traveled.  "+
	"Now the road is in such a state of disrepair with large potholes "+
	"and sections of stone missing.",
      	({"buildings","building"}) : "%^ORANGE%^Once regal and majestic buildings"+
	" rise along the street.  The detailed architecture and adornments to"+
	" the buildings, one could surmise that this must have been a wealthy "+
	"section of Azha at one time.  Now many of the buildings are in such a "+
	"state of disrepair that they look ready to crumble and fall.  The street"+
	" is lined with the rubble that has fallen from these sad buildings.  "+
	"Only one desperate for housing would ever dream of living in one of these"+
	" buildings.",
	({"obelisks","obelisk"}) : "%^BOLD%^%^WHITE%^The tops of weathered "+
	"limestone obelisks rise around the city, looking as if they circle "+
	"around the theater structure that you can almost make out.  Perhaps "+
	"if you get closer you can gain a better look at the obelisks.",
	({"theater"}) : "%^ORANGE%^A proud theater stands in the middle"+
	" of this area of "+
	"town.  The sandstone building is gilded with gold leaf, causing it "+
	"to catch the light and shine.  Ornate mosaics cover the walls of "+
	"this performance hall, though you will have to get closer to make "+
	"them out better.  The bushes and a garden around the theater is "+
	"overgrown and wild, showing what little care has been given to this"+
	" building."]));
  }
