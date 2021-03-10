#include <std.h>
#include "keep.h"
inherit VAULT;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("Hallway of a Ruined Keep");
   set_long(
   "You are traveling down the hallway of a ruined keep. Straight east are the"+
   " shattered double doors that lead to the mess hall. You can see a few tables"+
   " and chairs in there still, some smashed, but some appear intact. There is a door"+
   " on the south here. The mud tracks appear to lead to the south as well as to the"+
   " east. You notice the %^BOLD%^bones%^RESET%^ of a few small animals on the edges of the hallway"+
   " here, and realize that you'd best be on your guard."
   );
   set_smell("default","The keep is filled with mud.");
   set_listen("default","The ceiling beams creak and moan with the wind.");
   set_items(([
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in a bit worse shape. There are several large cracks running through blocks,"+
   " and a few missing ones that let the chill wind cut right through.",
   "floor" : "The floor is made of stone bricks and is covered in dirt and mud. The"+
   " mud almost completely covers the floor, but there is so much you can't make out"+
   " any clear tracks.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams creak a bit and don't seem completely sturdy.",
   ({"beam","beams"}) : "The beams that support the ceiling above you tend"+
   " to creak and don't seem totally stable.",
   "mud" : "The mud completely covers the floor, almost as though a small army marched"+
   " through here recently. The tracks lead to both the south and the east.",
   "cobwebs" : "There are a few cobwebs in places along the walls.",
   "door" : "There is a door leading to the south here, it appears fairly sturdy.",
   ({"door","double doors"}) : "The remains of the double doors that used to lead"+
   " into the mess hall are on the floor to the east. They appear to have been"+
   " shattered or blasted open by something and have been pushed off to the side"+
   " to clear the doorway.",
   "bones" : "%^BOLD%^%^WHITE%^There are several small bones scattered about the edges of"+
   " the hallway here, as though they have been discarded. At first they all appear"+
   " to be the bones of small animals, but then you realize that some of them are"+
   " merely fragments of larger bones that have been shattered in their collision"+
   " with the wall. It would probably be best to stay alert for danger.%^RESET%^",
   ]));
   set_exits(([
   "west" : ROOMS+"keep24",
   "east" : ROOMS+"keep26",
   "south" : ROOMS+"keep27",
   ]));
   set_door("door",ROOMS+"keep27","south","keep master_key");
   set_string("door","open","The door squeaks open.");
   set_string("door","close","The door squeaks shut.");
}
