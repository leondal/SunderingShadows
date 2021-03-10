//added set_door_description per bug report/suggestion - Styx 1/5/01

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
   "You are in the middle of a hallway in a ruined keep. There are two doors here,"+
   " one on the west and the other on the east. The door to the west appears quite"+
   " rotted and barely hanging from its hinges. A hard shoulder to it would probably"+
   " cave the door in. The door on the east is in much better shape. There is a bit"+
   " of %^GREEN%^moss%^RESET%^ growing in sections and some of the iron braces are a bit rusty, but"+
   " it is still fairly sturdy. To the north the hallway continues further into"+
   " the keep. You can see the entrance straight south of here."
   );
   set_smell("default","The pungent odor of rotted wood fills the hallway.");
   set_listen("default","The scrabbling of tiny claws on stone echoes faintly.");
   set_items(([
   ({"walls","stone walls"}) : "The stone walls that make up the keep are"+
   " in better shape here and there are rarely any missing blocks. A rotted door"+
   " is on the west wall and another door is on the east wall.",
   "floor" : "The floor is made of stone bricks and is quite dirty. Mud has"+
   " been tracked through the hallway by something, but you can't tell what.",
   "ceiling" : "The ceiling is made of carefully squared stone blocks that have"+
   " been fitted together and are supported by beams in some places. The"+
   " beams seem a bit more sturdy here than on the outer edges of the keep.",
   "moss" : "%^GREEN%^Moss grows along sections of the eastern door, but not"+
   " in many other places here.",
   "mud" : "The mud almost totally covers the floor. The ceiling is in much"+
   " better shape here, so it must have been tracked in by something. There"+
   " is so much mud that you can't really make out any clear tracks, or"+
   " even tell how long ago something was here. It could've been months or"+
   " just a few hours.",
   "door" : "This door is in fairly good shape. There is a bit of %^GREEN%^moss%^RESET%^ growing in"+
   " sections and some of the iron braces are a bit rusty, but it is still fairly"+
   " sturdy.",
   "rotted door" : "The door appears quite rotted and barely hanging from its hinges."+
   " A hard shoulder to it would probably cave the door in.",
   ]));
   set_exits(([
   "south" : ROOMS+"keep9",
   "north" : ROOMS+"keep12",
   "west" : ROOMS+"keep11",
   "east" : ROOMS+"keep39",
   ]));
   set_door("door",ROOMS+"keep39","east","keep master_key");
   set_door("rotted door",ROOMS+"keep11","west","keep master_key");
   set_string("rotted door", "open", "The rotted door almost falls off its hinges as it swings open.");
   set_string("rotted door", "close", "The rotted door shudders to a close.");
   set_door_description("rotted door","The door appears quite rotted and "
       "barely hanging from its hinges.");
   set_locked("door",1,"lock");
   lock_difficulty("door",20,"lock");
}
