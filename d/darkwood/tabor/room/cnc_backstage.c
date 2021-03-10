#include <std.h>
#include "../include/tabor.h"
inherit ROOM;

	void create(){
   	::create();
	set_property("indoors",1);
   	set_property("light",1);
   	set_terrain(CITY);
   	set_travel(PAVED_ROAD);
      set_name("%^CYAN%^Crown and Castle Theater - Backstage");
   	set_short("%^CYAN%^Crown and Castle Theater - Backstage");
   	set_long("%^CYAN%^The backstage of Tabor's popular"+
		" %^YELLOW%^Crown and Castle Theater%^RESET%^%^CYAN%^ "+
		"houses everything a bard or acting troupe might need "+
		"for a performance.  Thick %^MAGENTA%^ma%^RED%^r%^MAGENTA%^oon"+
		" %^CYAN%^curtains block the stage off, offering a feeling of"+
		" privacy for a performer, before they head out on stage.  "+
		"The worn %^ORANGE%^wooden floors%^CYAN%^ are covered with"+
		" numerous scratches, but kept clean.  Ropes and pulleys "+
		"suspend overhead, allowing for adjustment in the lighting"+
		" and placement of backdrops.  A rack filled with %^GREEN%^"+
		"costumes%^CYAN%^ is attached to the brick wall, sorted out"+
		" for quick changes.  A large %^BOLD%^%^BLACK%^ebony wood%^RESET%^"+
		"%^CYAN%^ piano takes up most of the northern wall, an instrument"+
		" from the far north that has gained in popularity in recent years."+
		"  Neatly assorted into a series of %^ORANGE%^wooden crates%^CYAN%^"+
		" are various props one might use for a theatrical or musical "+
		"production, housed on the eastern wall shelves.  Though the "+
                "backstage of the theater looks well used, you can tell it's "+
		"well cared for by the staff and performers.\n");
   	set_smell("default","A fresh citrus scent fills the air.");
   	set_listen("default","The curtains muffle most of the noise from the theater.");
  	set_items(([
      	({"crates","wooden crates","props"}) : "%^BOLD%^%^CYAN%^Wooden crates"+
			" are housed on the shelves that fill the eastern wall.  Neatly"+
			" sorted into each crate are props used for performances.  "+
			"From feather boas to stage weapons, and nearly anything that"+
			" a performer would need can be found inside.",
      	({"rack","costumes"}) : "%^BOLD%^%^BLUE%^A mix of costumes for "+
			"both genders fills the rack.  The costumes are carefully"+
			" arranged in order, more than likely to help speed up quick"+
			" changes.  An assortment of costumes to play anything from a"+
			" peasant serf to a noble prince or queen is housed on the racks.",
		({"piano","ebony piano"}) : "%^BOLD%^%^BLACK%^A large ebony wood piano is housed back"+
			" there.  The elegant piano first became popular in Daggerdale, "+
			"Torm, and Tonovi and soon spread like a wildfire through the lands."+
			"  Considered a nobleman's instrument the piano kept here is "+
			"graciously available for any performer to use.",
		({"ropes","pulleys"}) : "%^YELLOW%^Ropes and pulleys hang from the "+
			"high ceiling, keeping various stage items out of the way till"+
			" they are needed.  The ropes as well control the lighting on "+
			"the stage and the curtain, allowing for each performer to "+
			"arrange things to their needs.",
		({"curtain","curtains"}) : "%^MAGENTA%^Thick maroon velvet curtains "+
			"block the stage off from the backstage area and muffle any sound."+
			"  The curtains offer a feeling of privacy back here, allowing for"+
			" a performer to get ready in peace; before greeting their adoring fans.",
		({"wooden floor","floor"}) : "%^ORANGE%^The polished wooden floor is "+
			"covered with numerous scratches, showing how well used this "+
			"backstage area is.  Even with these flaws, the floor is kept"+
			" well polished and always cleaned.",]));
set_exits(([ "stage" : ROOMDIR+"cncstage" ]));
}
void reset()
{
    	::reset();
    		if(!present("fflewdur")) 
{
	new("/d/dagger/tonovi/town/cguilds/fflewdur.c")->move(TO) ;
    		return;
}
}
