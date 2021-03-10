//main.c

#include <std.h>
inherit VAULT;
//inherit "/d/guilds/inherit/g_defen.c";

void init(){
     ::init();
  //   defen::init();
}

void create(){
// object ob;   removing unused and old ooc boards from rooms
   ::create();
   set_terrain(RUINS);
   set_travel(RUTTED_TRACK);

   set_short("The ransacked main hall of the Order of metallic dragons.");
   set_long(
@OLI
   %^BOLD%^%^YELLOW%^The ransacked main hall%^RESET%^
   This was once the main hall of the Order. Once hung here banners
of the dragons and of the lords. The stone floor is worn with the steps
of those before you. That floor is now covered with ashes and blood stains.
You even see the remains of a few of the warriors that were left to rest
here. The floor above you is missing as is the ceiling above it. The
weather has already begun to effect the remaining interior of this room.
OLI
   );

    set_property("light",1);
    //set_property("no teleport", 1);
    set_property("indoors",0);
   set_smell("default","The smell of the decaying cloth and wood still lingers here.");
   set_listen("default","The creaking of the wind against some remaining wood.");

   set_items(([
      "floor":"The floor is stained by weather and the battle past. The litter of red splotches and brown marks scar the once bright marble",
      "remains":"This remains are little more then skeletons and rags. The room being opened to weather has allowed clean and fast decay."
      ]));
   set_exits(([
"southeast" : "/d/guilds/order/hall/memb",
    "south":"/d/guilds/order/hall/arena14",
   "north":"/d/guilds/order/hall/path4",
   "east":"/d/guilds/order/hall/bookie",
   "west":"/d/guilds/order/hall/crest"
   ]));
    set_door("stone doors","/d/guilds/order/hall/path4","north",0);
    set_door_description("stone doors","%^BOLD%^%^BLACK%^These huge stone "
"doors could only have been made by some of the greatest smiths around. "
"Almost 8 inches thick, and with no visible locks on or around the door. "
"Small words are engraved onto the door, which reads '%^YELLOW%^In Memory of "
"the Metallic Dragons%^BLACK%^'.%^RESET%^");
/*

   ob= new(BBOARD);
   ob->set_name("board");
   ob->set_id(({"board","guild board"}));
   ob->set_board_id("formerorderguild");
   ob->set_max_posts(0);
   ob->set_location("/d/guilds/order/hall/main.c");
   ob->set_short("Broken posting board.");
   ob->set_long("This broken board once held the thoughts on good and on the combination of all forces of good into one working defense against evil.");
*/

}
