#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",0);
   set_terrain(NAT_CAVE);
   set_travel(RUBBLE);
   set_name("Caverns");
   set_short("Cavern");
   set_long("%^BOLD%^A Cavern%^RESET%^\n"
"You seem to have reached the bottom of the cavern.  It's no small wonder you have found your way this far.  "
"You can see no way back through the maze, it seems the stalagmites are moving to make the path you made "
"vanish.  There are no obvious exits.\n");

//removed from long desc: but you feel some sort of dark presence on the north wall.
   set_smell("default","It smells dank and wet.");
   set_listen("default","You can hear water dripping.");

   set_items(([
//     "north wall":"You have reached the edge of the cavern, and upon closer inspection you can //see a darker "
//"piece of blackness in the furthest corner.",
//     "corner":"Staring into the darkness in the corner you make out the outline of a portal.",
     "stalagmites":"These are old and large although the smaller ones on the path have been bashed down.",
     "stalactites":"These hang menacingly from the ceiling.",
//     "portal":"This portal gives off a cold aura, and a feeling of utter darkness."
   ]));

   set_exits(([
//     "portal":CAVES"shadow",
     "southeast":CAVES"cave9"
   ]));
   set_invis_exits(({"southeast","portal"}));
//  Entry is now through squire's trial
//   set_pre_exit_functions(({"portal"}),({"GoThroughDoor"}));
}

void init(){
   ::init();
   do_random_encounters(({MON"piercer"}),60,4);
}

/*int GoThroughDoor() {
   object obj;
   if(obj=present("dark ring",TP)){
     if(obj->query_worn()){
       tell_object(TP,"You pass through the portal into the realm of darkness.");
       return 1;
     }
   }
   write("You can't seem to break the barrier shielding the portal.");
   return 0;
}*/
