//Circe 4/23/04
#include <std.h>

inherit "/d/common/inherit/hitching_post";

void create()  {
  //::create();
  set_property("indoors",0);
//  set_property("light", 2);  it has light set in the inherit *Styx*  7/28/05
  set_terrain(LIGHT_FOREST);
  set_travel(FOOT_PATH);
  set_long("%^GREEN%^The dense trees of the forest have been thinned "+
     "here, allowing for a small open area.  The canopy still "+
     "rises overhead, effectively shading and cooling the area.  "+
     "Despite the shade, the ground is covered in thick, soft "+
     "grass, interspersed with dandelions.  Four hitching posts "+
     "have been set into the ground here, encircling a large, round "+
     "watering trough.\n"
  );
  set_smell("default", "The air smells of horses and the fresh scent of pine.");
  set_listen("default", "The neighs of horses are punctuated by laughter from the inn.");
  set_exits(([
	"southwest": "/d/darkwood/room/road7",
        "down":"/d/shadow/ratpaths/rooms/rp_p021_n006",
  ]));
  set_items( ([
      ({"post","posts","hitching post","hitching posts","tether","tethering post","tethering posts"}) : "There are several posts set up here to tether horses to. They are"+
	" basically long wooden bars that are supported on either end"+
	" that you loop the reins of a horse around to keep them there."+
	" There are four posts all together, circling a round, wooden trough.",
      ({"grass","dandelions","ground"}) : "%^BOLD%^%^GREEN%^The grass "+
         "covering the ground here is exceptionally thick, fertilized "+
         "naturally by the horses often in the area.  It is also quite "+
         "soft and cushions your feet.  %^YELLOW%^Dandelions %^GREEN%^"+
         "are scattered around, brightening the small glade.",
      ({"canopy","trees"}) : "The evergreens rise all around you, creating "+
         "a canopy overhead that blocks out the harshest rays of the sun.",
      ({"trough","round trough","wooden trough"}) : "%^CYAN%^The wooden "+
         "trough is not exactly circular, instead being a large octagon.  "+
         "Its wooden sides are slanted outward, and it is set low enough "+
         "to the ground so that the horses may drink their fill easily.",
   ]) );
      set_pre_exit_functions(({"southwest"}),({"GoThroughDoor"}));

}
