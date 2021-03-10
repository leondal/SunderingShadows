// 1/12/10 added terrian, Hades
#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_travel(FOOT_PATH);
   set_terrain(GRASSLANDS);
   set_property("indoors",0);
   set_property("light",2);
   set_short("%^BOLD%^%^GREEN%^Grasslands%^RESET%^");
   set_long(
   "%^GREEN%^You are in the northern half of Moonstone Vale. There is a feeling"+
   " of %^CYAN%^peace%^GREEN%^ here and everything seems to be full of life. "+
   "%^BOLD%^Lush grass%^RESET%^%^GREEN%^"+
   " reaches up at least six inches, and seems to flourish at the edges"+
   " of the forest. A few small animals are scampering about and"+
   " looking for food in this area. %^BOLD%^%^MAGENTA%^C%^YELLOW%^o%^WHITE%^"+
   "l%^RESET%^%^MAGENTA%^o%^WHITE%^%^BOLD%^r%^YELLOW%^f%^MAGENTA%^u%^YELLOW%^l"+
   " %^RESET%^%^GREEN%^butterflies float"+
   " on the breeze, occasionally stopping at one of the few %^BOLD%^%^MAGENTA%^f"+
   "%^YELLOW%^l%^RED%^o%^WHITE%^w%^BLUE%^e%^RESET%^%^MAGENTA%^r%^CYAN%^%^BOLD%^s"+
   " %^RESET%^%^GREEN%^that've managed to push their way above the grass. It is much"+
   " calmer here than on the other side of the vale.\n"
   );
   set("night long",
   "%^GREEN%^You are in the northern half of Moonstone Vale. %^BOLD%^%^WHITE%^"+
   "Starlight %^RESET%^%^GREEN%^ bathes"+
   " everything in a %^RESET%^pale silver%^GREEN%^, making it seem as though you've"+
   " passed into a mystical plane. The grass is ruffled by a gentle"+
   " breeze and everything seems calm and peaceful. You can hear a few"+
   " %^MAGENTA%^nightingales%^GREEN%^ singing a beautiful melody from somewhere in the"+
   " distance. The forest is not too far away, but unlike the Dark"+
   " Forest on the other side, this one seems fairly normal and serene.\n"
   );
   set_smell("default","You can smell the grass beneath your feet.");
   set_listen("default","Bird song echoes throughout the vale.");
   set_items(([
   "grass" : "%^BOLD%^%^GREEN%^The grass is lush and green.",
   ({"flower","flowers"}) : "%^MAGENTA%^Occasionally a brave flower has managed"+
   " to emerge from the carpet of grass and gather enough sunlight to survive.",
   "butterflies" : "%^BOLD%^%^MAGENTA%^Brightly colored butterflies float on the wind,"+
   " sometimes landing on one of the few flowers.",
   ({"forest","trees"}) : "%^GREEN%^The forest is not too far away, but you do"+
   " not sense the menacing evil like the Dark Forest on the other"+
   " side. It seems as though this side as been cleansed.",
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
