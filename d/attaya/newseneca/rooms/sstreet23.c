//sstreet23 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VERDE;

void create(){
   ::create();
   set_long(::query_long()+"The entrance to a %^ORANGE%^wooden "+
      "stable %^RESET%^is just to the north through a wide "+
      "sliding door.  The south seems oddly open, as the %^BOLD%^"+
      "town walls %^RESET%^do not cover this stretch of the street, "+
      "and you can see the %^YELLOW%^beach %^RESET%^far below the "+
      "edge of the cliff on which %^BOLD%^Seneca %^RESET%^stands.\n");
   set_exits(([
      "east" : ROOMS"estreet22",
      "west" : ROOMS"sstreet24",
      "north" : ROOMS"main_stable"
   ]));
   set_door("sliding door","/d/attaya/newseneca/rooms/main_stable","north",0,0);
   set_door_description("sliding door","%^ORANGE%^This wide door "+
      "slides back, leaving a large opening through which to bring "+
      "in mounts.  The door is reinforced with iron bands and has "+
      "an even stronger outer door that can be let down in storms.%^RESET%^");
   add_item("stable","%^ORANGE%^The wooden building to the north "+
      "must be a stable.  It features a wide sliding door that stands "+
      "open most of the time, and you can see the individual stalls "+
      "closest to the door just inside.%^RESET%^");
   add_item("beach","Seneca stands on the edge of a cliff overlooking "+
      "a portion of the beach below.  From here, you can see a small "+
      "stretch of %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
      "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand and %^CYAN%^waves %^RESET%^"+
      "pounding the shore far below you.");
   add_item("cliff","Seneca stands on the edge of a cliff overlooking "+
      "a portion of the beach below.  From here, you can see a small "+
      "stretch of %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
      "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand and %^CYAN%^waves %^RESET%^"+
      "pounding the shore far below you.");
   if(query_night()==1){
      set_open("sliding door",0);
      "/d/attaya/newseneca/rooms/main_stable"->set_open("sliding door",0);
   }else{
      set_open("sliding door",1);
      "/d/attaya/newseneca/rooms/main_stable"->set_open("sliding door",1);
   }
   remove_item("wall");
   remove_item("walls");
   remove_item("coquina");
   remove_item("coquina walls");
}