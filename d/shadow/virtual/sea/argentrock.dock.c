#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
    ::create();
   set_terrain(BOATS);
   set_travel(DECAYED_FLOOR);
    set("indoors",1);
    set("light",3);
    set("short","Argentrock Dock");
    set("long","%^CYAN%^Argentrock Dock\n"+
"%^ORANGE%^You are standing on an old dock. The wood"+
" the dock is made from is already starting to rot. "+
"You want to step off the dockyard as soon as possible"+
" so that you will not fall through the rotten boards."+
"  Under the boards one can see a rocky %^CYAN%^shore"+
"%^RESET%^.%^ORANGE%^ The ocean is borderless. A few seabirds "+
"occasionally fly over your head. To the south "+
"you see a dense forest.\n\n%^RESET%^  If someone was "+
"crazy they could <descend> down onto the cliff of a shore.");
    set_exits( (["south":PATH+"argpath4"]) );
    set_smell("default","You smell the ocean and the fresh breathes from "+
        "the forest.");
    set_listen("default","You heard waves splashing against the wooden dock.");
    set_climb_exits((["descend":({"/d/islands/argentrock/shore/shore1",20,roll_dice(10,8),100})]));
	
	/*  apparently set_items doesn't work in a dock room
	set_items( ([ 
        ({"rocks","shore"}):"If someone was crazy, they could _descend_ down onto the cliff of a shore.",
        ({"sea"}):"The sea looks dark and mysterious.",
       ({"forest"}):"The thick forest looms to the south.",

        ]) );
  */
}
