#include <std.h>
#include "../tormdefs.h"
inherit ROOM;

void create()
{
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light",2);
    set_short("Torm's marketplace");
    set_long(
    "Torm's marketplace.\n"
    "  Torm's marketplace bustles with activity. It is set up along a cobbled"+
    " square in the center of town with vendors selling their wares from"+
    " where ever they can find enough room to setup shop. Many people and"+
    " creatures walk through the booths and mats laid out with goods, not"+
    " minding the mixed company at all. Most of the vendors sell mundane"+
    " items, there are only a few with things of interest for you here."
    );
    set("night long",
    "%^BLUE%^"
    "Torm's great marketplace lies empty of even refuse it is kept so"+
    " very clean.  Your foot steps tend to echo faintly on the paved"+
    " stones, the sound slightly muffled by the fog that blankets the"+
    " area.  It is hard to believe this empty place holds a bustling"+
    " market in the daytime."
    );
    set_smell("default","You smell salt in the air from the Dagger Sea.");
   if(query_night() == 1) {
     set_listen("default","The waves of the sea wash against the docks.");
   }
   else {
      set_listen("default","Many people hustle and bustle about you, trying"+
      " to get the best deals.");
   }
    set_items(([
    ({"mats","booths","vendors",}) : "Throngs of people surround you here,"+
    " all clamoring for something or the other.  The mats and vendors show"+
    " their various wares, but really you have no need for pottery or a"+
    " fishhook sharpener so you turn your attention to finding more"+
    " interesting people.",
    ({"street","cobble stones"}) : "The street you are walking along is"+
    " paved with cobble stones.",
    "fog" : "The fog covers the marketplace, keeping low to the ground"+
    " and avoiding the edges of the buildings. It makes the stones that"+
    " pave the area a little slick.",
    ]));
}
void reset(){
   int i,j;
   ::reset();
   j=(random(2)+1);
   if(query_night()) return;
   if(!present("dayperson")) {
      for(i=0;i<j;i++){
		   switch(random(15)){
            case 0:
               new(MON+"vnative.c")->move(TO);
               break;
            case 1:
               new(MON+"begger.c")->move(TO);
               break;
            case 2..4:
               new(MON+"citizen.c")->move(TO);
               break;
            case 5:
               new(MON+"pickpocket.c")->move(TO);
               break;
            case 6:
               new(MON+"fisherman.c")->move(TO);
               break;
            case 7..8:
               new(MON+"guard2.c")->move(TO);
               break;
            case 9:
               new(MON+"vbarbarian.c")->move(TO);
               break;
            case 10:
               new(MON+"vdwarf.c")->move(TO);
               break;
            case 11:
               new(MON+"velf.c")->move(TO);
               break;
            case 12:
               new(MON+"vmage.c")->move(TO);
               break;
            case 13:
               new(MON+"dockworker.c")->move(TO);
               break;
            case 14:
               new(MON+"piratec.c")->move(TO);
               break;
         }
      }
   }
}
