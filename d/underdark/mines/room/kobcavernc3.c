//Octothorpe (1/24/09)
//Underdark Mining Caverns, Kobold Boss Room

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",0);
   set_property("no teleport",1);
   set_travel(SLICK_FLOOR);
   set_terrain(NAT_CAVE);

   set_name("%^BOLD%^%^BLACK%^Overlooking a massive chasm%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Overlooking a massive chasm%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Overlooking a massive chasm"+
      "%^RESET%^\n "+
      "%^BOLD%^%^BLACK%^The curving tunnel leads at last to the edge of "+
      "a gaping chasm. The tiny stream flows off the edge, down into "+
      "the black void below. Along the eastern edge of the chasm, "+
      "closest to this outcropping, a large %^RESET%^%^CYAN%^wa%^RESET%^"+
      "t%^BOLD%^%^CYAN%^er%^WHITE%^f%^RESET%^%^BLUE%^a%^BOLD%^%^WHITE%^"+
      "ll %^BOLD%^%^BLACK%^splashes down, into the chasm from above. The "+
      "%^WHITE%^limestone %^BOLD%^%^BLACK%^outcropping extends out "+
      "over 100 feet, and provides a breathtaking view of the chasm. "+
      "Neither the ceiling of the cavern, nor the bottom of the chasm "+
      "can be discerned, both are completely obscured by the deepest "+
      "darkness imaginable.%^RESET%^\n");
   set_items(([
      ({"chasm","void"}):"%^BOLD%^%^BLACK%^It is impossible to discern "+
         "the size of this chasm. Based upon your best guess, it would "+
         "appear to extend at least a quarter of a mile, which appears "+
         "to be the distance at which your eyes cannot see any farther. "+
         "The %^RESET%^%^CYAN%^wa%^RESET%^t%^BOLD%^%^CYAN%^er%^WHITE%^f"+
         "%^RESET%^%^BLUE%^a%^BOLD%^%^WHITE%^ll %^BOLD%^%^BLACK%^"+
         "descends down into the darkness of the chasm, likely falling "+
         "to the very center of the world.",
      "limestone" : "%^BOLD%^%^BLACK%^The %^WHITE%^limestone %^BOLD%^"+
         "%^BLACK%^has been worn smooth by the passage of water. Most "+
         "likely the work of an underground river that flowed through "+
         "the tunnel system in the past. The %^WHITE%^limestone %^BOLD%^"+
         "%^BLACK%^is fairly slick from the spray of the %^RESET%^"+
         "%^CYAN%^wa%^RESET%^t%^BOLD%^%^CYAN%^er%^WHITE%^f%^RESET%^"+
         "%^BLUE%^a%^BOLD%^%^WHITE%^ll %^BOLD%^%^BLACK%^.",
      "outcropping" : "%^BOLD%^%^BLACK%^This outcropping of %^WHITE%^"+
         "limestone %^BOLD%^%^BLACK%^extends out over the chasm for "+
         "about 100 feet. The footing is made difficult between the "+
         "smoothness of the %^WHITE%^limestone%^BOLD%^%^BLACK%^, and "+
         "the spray from the %^RESET%^%^CYAN%^wa%^RESET%^t%^BOLD%^"+
         "%^CYAN%^er%^WHITE%^f%^RESET%^%^BLUE%^a%^BOLD%^%^WHITE%^ll "+
         "%^BOLD%^%^BLACK%^along the eastern edge of the outcropping.",
      "waterfall" : "%^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^wa%^RESET%^"+
         "t%^BOLD%^%^CYAN%^er%^WHITE%^f%^RESET%^%^BLUE%^a%^BOLD%^"+
         "%^WHITE%^ll %^BOLD%^%^BLACK%^originates at some distance "+
         "above this outcropping. Most likely it is the end of an "+
         "underground river which now flows into the very center of "+
         "the earth.",
   ]));
   set_exits(([
      "southeast":RMS"kobcavernd4",
   ]));
   set_smell("default","The smell of wet limestone and damp dogs fills "+
      "the area.");
   set_listen("default","The cacophonous echo of rushing water assaults "+
      "your ears.");
}

void reset(){
   ::reset();
   if(!present("kobold")){
      new(MON+"kobchamp2")->move(TO);
      new(MON+"kobchamp2")->move(TO);
   }
   if(!present("sistnak")){
      new(MON+"kobsorc")->move(TO);
   }
}
