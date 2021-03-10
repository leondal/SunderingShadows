#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(DIRT_ROAD);
  set_property("indoors",0);
  set_property("light",1);
  set_short("%^BOLD%^A Path Through The Forest%^RESET%^");
  set_long("All around you, tall pine and majestic oak trees "+
	"rise up and block out the majority of "+
	"the light from above, leaving you little question as to why "+
	"they call it the Darkwood Forest.  A carpet of pine needles "+
	"stretches out and away from the path.  Signs of wildlife are "+
	"everywhere...birds sing merrily from their perches, and the bushes "+
	"rustle all around you as small creatures scurry about.  "+
   "The path you are on seems to continue east and northwest from here, "+
	"hopefully providing you with safe passage through the forest.");
  set("night long","Very little of the moonlight manages to find its "+
	"way down to your level, leaving you in almost total darkness.  "+
	"Trees rise ominously around you, making you feel as if you're "+
	"in a closet instead of the open wilderness.  An owl hoots in "+
	"the distance, startling a small creature in the bushes a little "+
	"ways ahead of you.  As best you can tell, the path stretches "+
	"to the northwest and east of here.");
  set_smell("default","The crisp, fresh scent of pine fills the air.");
  set_listen("default","The trees creak as they sway in the wind.");
  set_items(
    ([
    ({"tree","trees","pine","oak"}):"Huge, sprawling oak trees fight "+
	"for space amongst the tall pine trees.",
    "path":"This small dirt path is rather easy to follow, given it is "+
	"the only part not covered in pine needles."
    ]) );
  set_exits(
    ([
    "northwest" : ROOMS+"path1",
    "east" : ROOMS+"path3"
    ]) );
//  call_out("wild",10);
}
/*
void wild()
{
  if(query_night() != 1)
  {
    switch(random(4))
    {
      case 0:
        tell_room(ETP,"A squirrel in the trees above picks apart a "+
	"pinecone, dropping pieces of it nearby.");
        break;
      case 1:
        tell_room(ETP,"Brightly colored lizards scurry away from you.");
        break;
      case 2:
        tell_room(ETP,"A raven watches you intently from a nearby "+
	"branch.  He caws loudly whenever you look near him.");
        break;
      case 3:
        tell_room(ETP,"Songbirds sing lovely tunes, each one attempting "+
	"to top the song before his.");
        break;
    }
  }
  else
  {
    switch(random(4))
    {
      case 0:
        tell_room(ETP,"You are startled as a large owl hoots loudly "+
	"overhead.");
        break;
      case 1:
        tell_room(ETP,"A raccoon dashes off into the bushes as you "+
	"approach.");
        break;
      case 2:
        tell_room(ETP,"Lightning bugs flicker around you.");
        break;
      case 3:
        tell_room(ETP,"The hair on the back of your neck stands up "+
	"at the sound of a wolf howling nearby.");
        break;
    }
  }
  call_out("wild",90);
}
*/
