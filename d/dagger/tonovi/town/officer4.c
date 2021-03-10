#include "/d/dagger/tonovi/town/short.h"

inherit MAIN;

void create(){
    ::create();
   set_property("indoors",1);
    set_property("light", 2);
    set_short("Officer's quarters");
    set_room_type("obarracks");
    set_long(
   "Here inside the officers' barracks you can see the signs of a comfortable life for the commanders of the military force.  The bunks here, though numerous, are spacious and comfortable.  Curtains that can be moved hang from the ceiling to provide privacy when necessary.  Personal possessions are everywhere, and these quarters are luxurious compared to those of the enlisted men."
    );
    set_smell("default", "You smell tobacco smoke on the air.");
    set_listen("default", "You can hear the laughter in the area.");
    set_items( ([
	"path" : "This path is well worn and well kept.  It looks to be travelled quite often.",
	"curtains" : "These curtains hang from the ceiling able to be pulled into position to provide privacy.",
	"beds" : "These beds, though for one person, are comparatively large and comfortable.",
      ]) );
    set_exits( ([
	"south" : RPATH "officer2",
	"west" : RPATH "officer5",
	"north" : RPATH "officer6",
      ]) );

}

void reset() {
  ::reset();
}