#include <std.h>
inherit ROOM;

void create(){
    ::create();
   set_terrain(RUINS);
   set_travel(RUTTED_TRACK);
    set_property("light", 1);
    //set_property("no teleport", 0);
    set_property("indoors", 0);
    set_short("%^BOLD%^Listing of Members");
    set_long(
  "   This room looks as if it had held much of the fighting. Many more signs"+
   " of the dead are here. The remains of a body, a pile of minor equipment, all"+
   " indicate that this room was where the defenders of good came together for their last stand. A broken list lies on the floor in the middle of the room."+
   " Around the walls sit broken pictures and torn paintings. You can even make out some names still carved into the walls.");
    set_listen("default", "The silence is deafening.");
    set_smell("default", "You smell nothing.");
    set_exits( ([
	"northwest" : "/d/guilds/order/hall/main.c",
      ]) );
    set_items( ([
	"list" : "It is no longer readable. The names are gone and lost.",
    "pictures":
      "There are pictures of dragons mainly. You see silver, gold and bronze and a \n"+
      "myriad of others. These paintings look as if they have been preserved \n"+
      "unnaturally. Also are are pictures of elves and humans and other races. You\n"+
      "see soiled pictures of people like Tylorune, Link, Kiri, Mordred, Violet, \n"+
      "Reiki, Cromack and many others.\n"
      
         ,
      "paintings":"These are more pictures that have some how survived the weather and the battle. You see here names like Fyndlorn, Theledith, Odin, Lenni, Baldwin and many other.",
     "names":"Here you read more names that haunt this room: Isaac, Rohan, Vassago, Gannaldar and Tyu."
       
       ]) );
}

