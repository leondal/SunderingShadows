#include <std.h>
inherit ROOM;

void create()
{
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("%^GREEN%^The Women's Green Room%^RESET%^");
   set_property("indoors",1);
   set_property("light",3);
   set_long(
   "You have entered the dressing room that is primarily used for the female"+
   " performers here in Torm's amphitheatre. There is a closet brimming full"+
   " with all sorts of costumes for various types of shows on the far wall."+
   " Most of the rest of the room is bare, with a few small stools for actors"+
   " to perch on while awaiting their part. There is a wood table covered in"+
   " different types of makeups and hair accessories, with a large mirror in"+
   " front of it. The edges of the mirror have been ringed with several small"+
   " enchanted stones to always keep the image lit. You notice a few small"+
   " slits in the walls that better allow the sounds from the stage to be"+
   " heard in here so that the actors don't miss their cues, but it also means"+
   " that you must keep fairly quiet during a performance lest the audience"+
   " hear your conversation!"
   );
   set_smell("default","The scent of various perfumes wafts through the room.");
   set_listen("default","The waves pound rhythmically against the sea walls.");
   set_exits(([
      "stage" : "/d/dagger/Torm/city/ampitheatre",
   ]));
}
