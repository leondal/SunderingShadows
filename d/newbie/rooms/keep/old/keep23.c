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
   set_short("The captain's room");
   set_long(
   "You are standing in what was once most likely the guard captain's room. It"+
   " is now in rather bad shape. The bookshelf in the corner has been smashed"+
   " and overturned, the footboard of the bed has been kicked off, and the"+
   " bedding and sheets are very moldy. The desk on the north side of the room"+
   " is still mostly intact, but has the remains of a half-eaten (and not very"+
   " well cooked) dinner on it that have begun to mold. The floor is littered"+
   " with various forms of debris, several of which you notice are %^BOLD%^bones%^RESET%^."
   );
   set_smell("default","There is a disgusting stench that permeats this room.");
   set_listen("default","The wind whistles faintly outside.");
   set_items(([
   "floor" : "The floor is littered with various forms of debris, the most"+
   " striking of which are carefully picked %^BOLD%^bones%^RESET%^.",
   "ceiling" : "The ceiling is rather unremarkable, except for the %^RED%^blood%^RESET%^ that"+
   " has been splattered against it in places.",
   ({"wall","walls"}) : "The walls seem very sturdy here, although even they"+
   " are quite dirty. You can see greasy and muddy hand prints in sections, and"+
   " %^RED%^blood%^RESET%^ splattered in other areas, most likely from fights"+
   " that have taken places in this room.",
   "desk" : "The desk is on the north side of the room and is made of sturdy"+
   " oak wood. Despite being covered in various forms of filth that you don't"+
   " even want to think about, it is in decent shape. There is even a chair on"+
   " which to sit next to it.",
   "chair" : "The chair is very large and appears to be sturdy. Someone has"+
   " decorated it in a rather macabre fashion with the skulls of various small"+
   " creatures, almost as if it were some sort of throne or something.",
   "bed" : "The bed is still usable you suppose, although you might actually"+
   " prefer the floor. The footboard has been kicked off of it, and the bedding"+
   " and sheets are all very moldy, but it would support your weight.",
   ({"bedding","sheets","pillow","blanket"}) : "The bedding, sheets, pillow, and"+
   " blanket that are on the bed are all rather moldy and stink something awful.",
   "bookshelf" : "The bookshelf on the south side of the room has been smashed"+
   " into tiny pieces. There is not much actual wood left, you think parts of it"+
   " have perhaps been used to try and repair the door. The books that it once"+
   " held are mostly ripped and all of them are completely covered in mildew.",
   "books" : "Books are scattered about the broken bookshelf. Some have been"+
   " ripped and torn, and all are covered in mildew.",
   "bones" : "%^WHITE%^%^BOLD%^You hope the bones aren't human, but several must have come from"+
   " a larger animal. They have all been picked clean, and some have been cracked"+
   " open and the marrow cleaned out.%^RESET%^",
   "debris" : "Debris of various sorts covers the floor, the most horrifying of"+
   " which are %^BOLD%^bones%^RESET%^.",
   "door" : "The door leading back out into the hallway is still in fairly good"+
   " shape. From this side you can see that it has obviously been repaired, but"+
   " not very well and with wood that is also rather rotted.",
   ]));
   set_exits(([
   "west" : ROOMS+"keep22",
   ]));
   set_door("door",ROOMS+"keep22","west",0);
   set_string("door","open","The door creaks open rather loudly.");
}

void reset()
{
   ::reset();
   if(!present("half-ogre")) {
      new(MONS+"halfogre")->move(TO);
   }
}
