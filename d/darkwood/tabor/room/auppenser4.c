#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(RUTTED_TRACK);
  set_terrain(OLD_MOUNTS);
  set_light(2);
  set_indoors(0);
  set_name("A faint footpath");
  set_short("A faint footpath");
  set_long(
     "This path can barely be distinguished as one at a "+
     "quick glance.  Boulders and rubble impede your step, "+
     "making it clear that this path has fallen into disrepair.  "+
     "The travel up the mountainside is steep, and you are suddenly "+
     "faced with a narrow slit of an opening in the side of the "+
     "mountain.  It looks just wide enough for one person to "+
     "squeeze through at a time.\n"
    );
  set_exits(([
    "shrine" : "/d/magic/temples/auppenser",
    "south" : ROOMDIR+"auppenser3"
  ]));
  set_listen("default","The wind whistles through the mountainside.");
  set_smell("default","A faint scent of incense is in the air.");
  set_items(([
     ({"boulder","boulders","rubble","rocks"}) : "Rubble strewn "+
        "along the path hints at its lack of use.  Large boulders "+
        "force the trail to skirt around in a few places, though "+
        "passage is still not treacherous.",
     ({"mountain","mountainside","goal"}) : "It is unclear what "+
        "the trail is leading to.  The mountainside here is rather "+
        "steep, making travel difficult.",
     ({"opening","slit"}) : "As you peer at the opening, you think "+
        "you see a faint glimmering, as if from a gem.  Strange..."
  ]));
}
