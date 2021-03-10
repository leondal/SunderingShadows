#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(MEADOWLANDS);
   set_short("%^BOLD%^%^BLUE%^River Bank%^RESET%^");
   set_long(
   "%^CYAN%^A %^BLUE%^%^BOLD%^river%^RESET%^%^CYAN%^ slowly winds its "+
   "way through the vale. You are standing on"+
   " the edge of the %^ORANGE%^sandy%^CYAN%^ bank. You can see the"+
   " %^BOLD%^water%^RESET%^%^CYAN%^ rushing before you,"+
   " flowing from a %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^ and disappearing"+
   " into the %^GREEN%^woods%^CYAN%^. The water looks"+
   " %^BOLD%^crystal%^RESET%^%^CYAN%^ clear and %^BOLD%^%^BLUE%^very cold"+
   "%^RESET%^%^CYAN%^. On the other side of the river you see"+
   " more %^GREEN%^grasslands%^CYAN%^ and a %^BOLD%^%^GREEN%^meadow"+
   "%^RESET%^%^CYAN%^, a few trees are also scattered about.\n"
   );
   set("night long",
   "%^CYAN%^A %^BOLD%^%^BLUE%^river%^RESET%^%^CYAN%^ winds its way through"+
   " this vale, occasionally crashing against"+
   " the bank when it makes a sharp turn. You can see the water raging"+
   " before you, spilling from the %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^"+
   " to follow its own path into the"+
   " %^GREEN%^woods%^CYAN%^. The water looks almost %^BOLD%^%^BLACK%^black"+
   "%^RESET%^%^CYAN%^ at night"+
   " and you get the feeling"+
   " that it's %^BOLD%^%^CYAN%^icy cold%^RESET%^%^CYAN%^. The bank you're "+
   "standing on is slightly damp, the"+
   " river must have climbed up a bit higher earlier to wash against the"+
   " %^ORANGE%^sand%^CYAN%^. On the opposite bank you can see more %^GREEN%^"+
   "grasslands %^CYAN%^and a %^BOLD%^%^GREEN%^meadow%^RESET%^%^CYAN%^,"+
   " a few trees are also scattered about over there.\n"
   );
   set_smell("default","You smell wet sand.");
   set_listen("default","The rushing river is all you can hear.");
   set_items(([
   "water" : "%^BOLD%^%^CYAN%^It looks very clear and cold.",
   "river" : "%^BOLD%^%^BLUE%^The river races past you.",
   "sand" : "%^ORANGE%^This is pale, fine-grained sand.",
   "bank" : "%^ORANGE%^The bank here is made of tightly packed"+
   " sand that is still a bit damp from the river.",
   ]));
}

void reset()
{
   ::reset();
   if(present("monster")) return;
   if(random(3)) return;
   switch(random(14)) {
      case 0..2:
         new(MONS+"sirine")->move(TO);
         break;
      case 3..4:
         new(MONS+"sandling")->move(TO);
         new(MONS+"sandling")->move(TO);
         break;
      case 5..6:
         new(MONS+"sandman")->move(TO);
         break;
      case 7:
         new(MONS+"sirine")->move(TO);
         new(MONS+"sirine")->move(TO);
         break;
      case 8:
         new(MONS+"sandling")->move(TO);
         new(MONS+"sandling")->move(TO);
         new(MONS+"sandling")->move(TO);
         break;
      case 9:
         new(MONS+"sandman")->move(TO);
         new(MONS+"sandman")->move(TO);
         break;
      case 10..12:
         new(MONS+"sea_sprite")->move(TO);
         new(MONS+"sea_sprite")->move(TO);
         break;
      case 13:
         new(MONS+"sea_sprite")->move(TO);
         new(MONS+"sea_sprite")->move(TO);
         new(MONS+"sea_sprite")->move(TO);
         break;
   }
}
