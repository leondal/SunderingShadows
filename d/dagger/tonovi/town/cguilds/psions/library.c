#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_light(2);
   set_property("no teleport",1);
   set_indoors(1);
   set_name("A peaceful library");
   set_short("%^RESET%^%^GREEN%^A peaceful library%^RESET%^");
   set_long("%^RESET%^%^GREEN%^A peaceful library%^RESET%^\n"+
      "Scattered around this large library are several %^RED%^couches "+
      "%^RESET%^designed for lounging.  Between them stand simple "+
      "%^ORANGE%^wooden tables %^RESET%^that have seen much use, "+
      "judging from their highly polished tops that have been worn "+
      "smooth.  The table's chairs are fitted with %^RED%^maroon "+
      "cushions %^RESET%^that match the %^RED%^couches%^RESET%^, "+
      "and they feature embroidery of different sorts - from "+
      "%^BOLD%^%^BLACK%^birds %^RESET%^to %^BLUE%^animals%^RESET%^ to "+
      "%^YELLOW%^scenery%^RESET%^.  Free-standing %^ORANGE%^"+
      "bookshelves %^RESET%^have been placed to provide hidden "+
      "nooks where one might study in relative privacy.  The "+
      "floor is covered with scattered %^CYAN%^throw rugs %^RESET%^"+
      "in dark colors, and this is the only room in the enclave "+
      "with windows to allow a clear view of the strange, %^BOLD%^"+
      "%^GREEN%^co%^CYAN%^lo%^RESET%^%^MAGENTA%^r-%^YELLOW%^st"+
      "%^GREEN%^re%^CYAN%^ak%^RESET%^%^MAGENTA%^ed %^BOLD%^%^BLUE%^sky%^RESET%^ "+
      "outside.\n");
   set_listen("default","The low moan of the wind breaks the silence.");
   set_smell("default","A light fragrance of ozone resides in the air here.");
   set_items(([
      ({"wall","walls","floor","here"}) : "%^RESET%^%^GREEN%^"+
         "The smooth walls and floor of this building are carved from "+
         "smooth crystal, translucent and pure.  They are almost "+
         "soft to the touch, and the floor seems to muffle the sound "+
         "of footsteps, almost as if absorbing them.  In a few places, "+
         "the walls have been broken by narrow windows, allowing a clear "+
         "view of the strange, %^BOLD%^%^GREEN%^co%^CYAN%^lo%^RESET%^"+
         "%^MAGENTA%^r-%^YELLOW%^st%^GREEN%^re%^CYAN%^ak%^RESET%^"+
         "%^MAGENTA%^ed %^BOLD%^%^BLUE%^sky%^RESET%^%^MAGENTA%^.%^RESET%^",
      ({"couch","couches"}) : "%^RED%^Each of the couches is a "+
         "deep maroon that picks out hues in the crystal of the "+
         "walls.  The couches are designed for lounging, having "+
         "sloping arms and wide seats.%^RESET%^",
      ({"table","tables","chairs","chair"}) : "The tables here are "+
         "made of wood, lending a nice break from the otherwise "+
         "crystalline enclave.  Each chair's cushion is a work "+
         "of art - stretching from the top of the back to cover "+
         "the seat and bearing fanciful embroidery of very ordinary "+
         "creatures and scenes, made unusual by their fantastic "+
         "surroundings.",
      ({"shelves","bookshelves"}) : "The bookshelves reach floor-"+
         "to-ceiling are are fitted with wooden ladders to allow "+
         "readers to reach the top shelves.  They are not against "+
         "the wall - they are instead spaced around the room to create "+
         "quiet nooks filled with couches and tables.",
      ({"window","windows"}) : "The narrow windows in the walls "+
         "allow a view of the eerie sky."
   ]));
   set_exits(([
      "west" : "/d/dagger/tonovi/town/cguilds/psions/fountain"
   ]));
}