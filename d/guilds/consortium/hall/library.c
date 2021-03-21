//

#include <std.h>

inherit VAULT;

void create(){
   ::create();

   set_name("Consortium Library");
   set_short("Library of the Consortium");

   set_property("indoors",1);
   set_property("light",2);
   set_long(
   "   %^ORANGE%^Library of the Consortium%^RESET%^\n"+
   "This library is one of great knowledge.  As you enter you can sense the"+
   " history of days past seem to leap out of the books that bind them.  There are"+
    " many study areas set up around the room as well as tables and chairs for more"+
   " leisurely reading.  Off to your north is the documentation of the history of"+
   " the realms and how the times have changed. To the south is the museum of warfare.\n"
   );

   set_smell("default","You can smell the chemicals used to preserve the paperbound books.");
   set_listen("default","It is very quiet in here.");
   set_exits(([
              "south":"/d/guilds/fist/hall/guild1",
              "north":"/d/guilds/consortium/hall/doc",
              "northeast":"/d/guilds/consortium/hall/help",
              "east":"/d/guilds/consortium/hall/geo",
              "west":"/d/shadow/city/room/melistelf",
              "up":"/d/guilds/consortium/hall/storeroom",
   ]));

   set_items(([
              "door":"This door leads out to Mead road.",
              "museum door":"This door leads south to the War museum.",
      ]));


   set_door("door","/d/shadow/city/room/melistelf","west","library key");
   set_door("museum door","/d/guilds/fist/hall/guild1","south","library key");
   set_open("museum door",0);
   set_locked("museum door",0);
   set_open("door",0);
   set_locked("door",0);
   "/d/shadow/city/room/melistelf"->set_open("door",0);
   "/d/guilds/fist/hall/guild1"->set_open("museum door",0);
}

void reset(){
   ::reset();
/* moving her to Solaren's old mage tower /d/player_houses/mons to work for the new mage guild  *Styx*  6/17/03
   if (!present("Thazorus")) {
      new("/d/guilds/consortium/hall/thazorus")->move(TO);
   }
*/
}
