//estreet20 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LILA;

void create(){
   ::create();
   set_long(::query_long()+"The entrance to a grand building "+
      "made of %^CYAN%^pale blue marble %^RESET%^stands "+
      "to the west up a short flight of stairs.\n");
   set_exits(([
      "north" : ROOMS"estreet19",
      "south" : ROOMS"estreet21",
//      "west" : ROOMS"legends_entry"
   ]));
   add_item("building","%^CYAN%^The building to the west is made of rare "+
      "%^BOLD%^pale blue marble %^RESET%^%^CYAN%^veined with %^BOLD%^"+
      "%^BLUE%^darker %^RESET%^%^CYAN%^and %^RESET%^lighter %^CYAN%^"+
      "tones.  The building has a series of four thick columns that "+
      "support the roof, and the doorway is recessed behind them.  "+
      "A %^RESET%^frieze %^CYAN%^above the door has been carved bas-relief "+
      "with the name of the building.  %^BOLD%^Studying the building, "+
      "you notice that no one seems to enter or leave, indicating that "+
      "this structure is still under construction.%^RESET%^");
   add_item("frieze","The frieze is quite simple in design and features "+
      "a message you could read.");
}

void init(){
   ::init();
   add_action("read_em","read");
}

void reset(){
   ::reset();
   if(!present("verity")){
      new(MON"verity")->move(TO);
   }
}

int read_em(string str){
   if(!str) return 0;
   if(str != "frieze" && str != "building") return 0;
   tell_object(TP,"\n"+
"%^BOLD%^%^CYAN%^   ,\n"+
"  /|  |  _,  |\\ |\\     _  |\\\n"+
"   |--| / |  |/ |/    / \\_|/\n"+
"   |  |)\\/|_/|_/|_/   \\_/ |_/\n"+
"                          |)\n"+
"\n"+
"\\_|)   _  _,  _        _|   ,\n"+
"  |   |/ / | |/ /|/|  / |  / \\_\n"+
" (\\__/|_/\\/|/|_/ | |_/\\/|_/ \\/\n"+
"          (|%^RESET%^\n");
   if(!TP->query_invis()){
      tell_room(TO,""+TPQCN+" reads the frieze.",TP);
   }
   return 1;
}
