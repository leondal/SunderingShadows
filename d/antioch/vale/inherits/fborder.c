#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",3);
   set_travel(FOOT_PATH);
   set_terrain(GRASSLANDS);
   set_name("Grasslands");
   set_short("%^GREEN%^Grasslands%^RESET%^");
   set_long(
      "%^GREEN%^The %^BOLD%^grass %^RESET%^%^GREEN%^is taller "+
      "here and some %^ORANGE%^scrub brushes %^GREEN%^have "+
      "grown along the edges of the %^CYAN%^vale %^GREEN%^and "+
      "the %^BOLD%^forest%^RESET%^%^GREEN%^.  The forest rings "+
      "this little vale and almost seems to be protecting it "+
      "and keeping it safe from the rest of the world."+
      "  The %^BOLD%^trees %^RESET%^%^GREEN%^are growing tall "+
      "into the %^CYAN%^sky %^GREEN%^and the %^YELLOW%^sun "+
      "%^RESET%^%^GREEN%^makes the %^BOLD%^leaves %^RESET%^%^GREEN%^look"+
      " like brilliant %^BOLD%^em%^RESET%^%^GREEN%^e%^BOLD%^ra"+
      "%^WHITE%^l%^GREEN%^ds %^RESET%^%^GREEN%^as the light "+
      "passes through them.  The branches sway gently in the "+
      "slight breeze.  The entire %^BOLD%^forest %^RESET%^%^GREEN%^"+
      "seems to be filled with a sense of new life.  You can't "+
      "see too deeply into it, however, because the %^BOLD%^"+
      "trees %^RESET%^%^GREEN%^are growing so close together.\n"
   );
   set("night long",
      "%^BLUE%^You've come to the edge of the %^CYAN%^vale%^BLUE%^, "+
      "which is marked by the %^GREEN%^forest %^BLUE%^that rings "+
      "it.  You hear strange rustling sounds coming from within "+
      "it as the animals move through the brushes.  You notice "+
      "that the %^GREEN%^grass %^BLUE%^is taller here and some"+
      " %^ORANGE%^scrub brushes %^BLUE%^are growing up along the "+
      "border.  The %^GREEN%^trees %^BLUE%^are dark and almost"+
      " forboding, but you don't sense any evil coming from them.\n"
   );
   set_smell("default","You can smell the grass beneath your feet.");
   set_listen("default","The forest is alive with rustling sounds and birdsong.");
   set_items(([
      "grass" : "The grass is lush and green and taller here than in the rest of the"+
         " vale.",
      ({"bushes","scrub brush","brush"}) : "Scrub brush has started growing along the"+
         " edges of the vale and the forest.",
      ({"forest","trees"}) : "The forest is right next to you. You can see the tall"+
         " green trees reaching into the sky and hear the scurrying of little animals"+
         " that are busily rushing about. It is not like the Dark Forest at all, and"+
         " you almost wonder if this is what the Dark Forest was like long ago.",
   ]));
}

void reset()
{
   ::reset();
   if(present("monster")) return;
   if(random(3)) return;
   if(query_night() == 1) {
      switch(random(11)) {
         case 0:
            new(MONS+"dragonet")->move(TO);
            break;
         case 1..3:
            new(MONS+"wdog")->move(TO);
            break;
         case 4:
            new(MONS+"sylph")->move(TO);
            break;
         case 5..7:
            new(MONS+"wstag")->move(TO);
            break;
         case 8..10:
            new(MONS+"gsnake")->move(TO);
            break;
      }
   }
   else {
      switch(random(12)) {
         case 0..4:
            new(MONS+"doe")->move(TO);
            break;
         case 5..6:
            new(MONS+"wstag")->move(TO);
            break;
         case 7:
            new(MONS+"sylph")->move(TO);
            break;
         case 8..9:
            new(MONS+"fox")->move(TO);
            break;
         case 10..11:
            new(MONS+"raccoon")->move(TO);
            break;
      }
   }
}
