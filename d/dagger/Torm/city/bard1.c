#include <std.h>
inherit ROOM;

void create()
{
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("%^GREEN%^The Men's Green Room%^RESET%^");
   set_property("indoors",1);
   set_property("light",3);
   set_long(
   "You have entered the dressing room that is primarily used for the male"+
   " performers here in Torm's amphitheatre. There is a small and well"+
   " organized closet on the far well, with a full sized mirror on the door."+
   " Most of the rest of the room is bare, with a few small stools for actors"+
   " to perch on while awaiting their part. There is a wood table covered in"+
   " different types of makeups, hair gels, and even a shaving set with a"+ 
   " small mirror in front of it. The room is lit with a simple yet large"+
   " magically enchanted stone that continually gives light to the room and"+
   " hangs from the center of the ceiling. There are a few small slits in the"+
   " walls that better allow the sounds from the stage to be heard in here so"+
   " that the actors don't miss their cues, but it also means that you must"+
   " keep fairly quiet during a performance lest the audience hear your"+
   " conversation!"
   );
   set_smell("default","The room smells of shaving soap and hair gels.");
   set_listen("default","The waves pound rhythmically against the sea walls.");
   set_exits(([
      "stage" : "/d/dagger/Torm/city/ampitheatre",
   ]));
}
