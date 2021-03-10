//removed restricted access to the clerics guild now that boards are ooc/remote *Styx* 10/02

#include "../defs.h"
inherit "/std/church";

void create() {
::create();
	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
    	set_short("%^RESET%^%^MAGENTA%^Cathedral of Shadow%^RESET%^");
  //  set("long",
//@MELNMARN
//%^BOLD%^You are in the dark church of Shadow.%^RESET%^
//In this huge open monastery originally built by a monk, the
//dead can come to pray for resurrection.  West Road is outside
//the monastery to the west.
//MELNMARN
//);
	set_long("%^BOLD%^%^BLUE%^Inside the monastic cathedral, "+
		"%^BOLD%^%^BLACK%^dark shadows%^BLUE%^ seem to shroud"+
		" the %^RESET%^deep gray %^BOLD%^%^BLUE%^slate stones "+
		"used to construct the framework of the church.  The "+
		"narthex, or foyer, of the church is supported by "+
		"%^RESET%^fluted columns%^BOLD%^%^BLUE%^ made from "+
		"granite.  A large round %^RED%^s%^RESET%^%^ORANGE%^t"+
		"%^MAGENTA%^a%^BOLD%^i%^YELLOW%^n%^RESET%^%^RED%^e"+
		"%^BOLD%^%^BLACK%^d %^BLUE%^glass window in the "+
		"narthex casts ribbons of %^WHITE%^c%^RED%^o%^WHITE%^"+
		"l%^YELLOW%^o%^WHITE%^r%^BLUE%^ inside the church.  "+
		"Candles hang from %^RESET%^%^ORANGE%^bronze "+
		"%^BOLD%^%^BLUE%^chandeliers, providing a %^YELLOW%^"+
		"w%^RESET%^%^ORANGE%^a%^YELLOW%^rm glow%^BLUE%^ in "+
		"the church, though ever seeming to dispel the "+
		"%^BOLD%^%^BLACK%^shadows%^BLUE%^.  The apse of the "+
		"church is decorated with huge panels of %^RED%^s%^RESET%^%^ORANGE%^t"+
		"%^MAGENTA%^a%^BOLD%^i%^YELLOW%^n%^RESET%^%^RED%^e"+
		"%^BOLD%^%^BLACK%^d %^BLUE%^glass - showing icons of "+
		"city life in Shadow.  Towering three stories high, "+
		"each level of glass is separated with %^WHITE%^s%^RESET%^"+
		"t%^BOLD%^%^BLACK%^a%^WHITE%^t%^RESET%^u%^BOLD%^%^BLACK%^e"+
		"%^WHITE%^s%^BLUE%^ carved in the likenesses of the gods.  Stone"+
		" benches with linen cushions face the apse of the cathedral.");
    	set_exits( ([
//"portals":"/d/magic/temples/main",
	"southeast" : ROOMS"plaza",
	]) );
    set_pre_exit_functions( ({"down"}), ({"GoThroughDoor"}) );
    set_property("light",2);
    set_property("indoors",1);
    set_items(([
      	({"window","windows","stained glass"}) : "%^BOLD%^%^BLUE%^Colorful"+
	" bits of glass have been fused together to create these awe-inspiring"+
	" windows.  Thick lead lines in the windows only adds to the majestic "+
	"quality of the windows. The large circular window in the narthex is also"+
	" known as the Rose Window - though the famous flower doesn't show up "+
	"anywhere in the window.  The windows in the apse tower three stories "+
	"tall.  Each slender pane of stained glass shows an image of life in "+
	"Shadow.  A blacksmith, scribe, merchant, inn keeper, and apothecary "+
	"are just some of the trades represented in the windows.",
		({"statues"}) : "%^RESET%^Carved from gray slate, white marble"+
	" and black basalt, a total of 27 seven statues help to create the "+
	"support structure for the large panes on stained glass in the apse"+
	" of the cathedral.  The top row of statues are all carved from "+
	"marble.",
      	({"candles","chandelier"}) : "%^ORANGE%^Round bronze circles"+
	" serve as the base for candles of beeswax.  The candle chandeliers"+
	" provide warm illumination to the cathedral.",
		({"columns"}) : "%^RESET%^Fluted columns of granite support "+
	"the high arched ceiling of the cathedral.  With the use of numerous"+
	" columns, the cathedral is able to tower high into the skyline of "+
	"Shadow, while having an open feeling inside of it.  Because of the"+
	" great height of the cathedral though, pockets of shadow tend to "+
	"linger about in the church."
	]));
    set_listen("default", "You hear the faint sounds of "
	      "chanting from the downstairs of the church.");
    set_smell("default","You smell the odor of a sweet incense.");
}

/*
void init(){
    ::init();
    add_action("sneak","sneak");
    add_action("peer","peer");
}
void sneak(string str){
    if(!str) return 0;
     if(str != "down" && str != "d") return 0;
    write("Only clerics can go down there!");
    return 1;
}
void peer(string str){
    if(!str) return 0;
    if(str != "down" && str != "d") return 0;
   write("You can't see down there.");
    return 1;
}
*/

int GoThroughDoor() {
/*    if(avatarp(TP)) return 1;
    if(!TP->is_class("cleric")){
	write("Only clerics can go down there!");
	return 0;
    }
*/
    write("Warning, these downstairs rooms may be removed soon, so do NOT quit or make teleport spots there.");
    return 1;
}


void reset(){
   ::reset();
   if(!present("anita kolito")) find_object_or_load("/d/npc/kolito")->move(TO);
}
