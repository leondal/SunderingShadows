//sstreet26 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VERDE;

void create(){
   ::create();
/*
   set_long(::query_long()+"A humble, two story building with %^YELLOW%^"+
      "pale yellow stucco %^RESET%^stands to the north.  A %^ORANGE%^"+
      "sign %^RESET%^has been placed at the base of its stairs.  "+
      "The south seems oddly open, as the %^BOLD%^"+
      "town walls %^RESET%^do not cover this stretch of the street, "+
      "and you can see the %^YELLOW%^beach %^RESET%^far below the "+
      "edge of the cliff on which %^BOLD%^Seneca %^RESET%^stands.\n");
Return this description when the orphanage goes live
*/
   set_long(::query_long()+"A humble, two story building with %^YELLOW%^"+
      "pale yellow stucco %^RESET%^stands to the north.  A %^ORANGE%^"+
      "sign %^RESET%^has been placed at the base of its stairs, though "+
      "the building is closed to the public.  "+
      "The south seems oddly open, as the %^BOLD%^"+
      "town walls %^RESET%^do not cover this stretch of the street, "+
      "and you can see the %^YELLOW%^beach %^RESET%^far below the "+
      "edge of the cliff on which %^BOLD%^Seneca %^RESET%^stands.\n");
   set_exits(([
      "east" : ROOMS"sstreet25",
      "west" : ROOMS"sstreet27",
//      "north" : ROOMS"orphanage_entry"
   ]));
/*
   set_door("door","/d/attaya/newseneca/rooms/orphanage_entry","north",0,0);
   set_door_description("door","The building to the north is accessible "+
      "by a thick %^ORANGE%^wooden door %^RESET%^at the top of a short "+
      "flight of stairs.");
*/
   add_item("building","The building to the north is two stories and "+
      "covered with %^YELLOW%^pale yellow stucco%^RESET%^.  Three stairs "+
      "carved from stone lead from the street to its covered doorway.  A "+
      "sign has been placed at the bottom of the stairs.");
   add_item("sign","The wooden sign is painted white with a bright "+
      "%^YELLOW%^yellow border%^RESET%^.  It has %^GREEN%^green "+
      "lettering %^RESET%^you could read.");
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
   remove_item("wall");
   remove_item("walls");
   remove_item("coquina");
   remove_item("coquina walls");
}

void init(){
   ::init();
   add_action("read_em","read");
}

int read_em(string str){
   if(!str) return 0;
   if(str != "sign" && str != "lettering") return 0;
   tell_object(TP,"\n"+
"%^YELLOW%^====================\n"+
"%^GREEN%^      Orphanage\n"+
"         of\n"+
"       Seneca\n"+
"%^YELLOW%^====================%^RESET%^\n");
   if(!TP->query_invis()){
      tell_room(TO,""+TPQCN+" reads the sign.",TP);
   }
   return 1;
}