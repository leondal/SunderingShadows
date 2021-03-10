//skyline41
#include <std.h>
#include "../seneca.h"

inherit SKYLINE;

void create(){
   ::create();
/*
   set_long(::query_long()+"To the east is a small shop with a "+
      "%^BOLD%^tiled roof %^RESET%^while an entryway to the "+
      "west seems to lead to a busy inn.  Both buildings feature "+
      "signs you could read.\n");
Return this description when the in goes live
*/
   set_long(::query_long()+"To the east is a small shop with a "+
      "%^BOLD%^tiled roof %^RESET%^while an entryway to the "+
      "west seems to lead to an inn, which seems to still be "+
      "under construction.  Both buildings feature "+
      "signs you could read.\n");
   set_exits(([
      "west" : ROOMS"inn_entrance",
      "east" : ROOMS"scribe",
      "north" : ROOMS"street7",
      "south" : ROOMS"skyline42"
   ]));
   add_item("signs","You could try to look at the western sign "+
      "or the eastern sign.");
   add_item("west sign","%^RESET%^%^ORANGE%^A vibrant wooden "+
      "painted in %^BOLD%^%^BLUE%^blues%^RESET%^%^ORANGE%^, %^BOLD%^"+
      "%^GREEN%^greens%^RESET%^%^ORANGE%^, and %^MAGENTA%^purples "+
      "%^RESET%^%^ORANGE%^is attached to the wall of the building "+
      "to the west.  It has bold script proclaiming a message you "+
      "could read.");
   add_item("western sign","%^RESET%^%^ORANGE%^A vibrant wooden "+
      "painted in %^BOLD%^%^BLUE%^blues%^RESET%^%^ORANGE%^, %^BOLD%^"+
      "%^GREEN%^greens%^RESET%^%^ORANGE%^, and %^MAGENTA%^purples "+
      "%^RESET%^%^ORANGE%^is attached to the wall of the building "+
      "to the west.  It has bold script proclaiming a message you "+
      "could read.");
   add_item("inn sign","%^RESET%^%^ORANGE%^A vibrant wooden "+
      "painted in %^BOLD%^%^BLUE%^blues%^RESET%^%^ORANGE%^, %^BOLD%^"+
      "%^GREEN%^greens%^RESET%^%^ORANGE%^, and %^MAGENTA%^purples "+
      "%^RESET%^%^ORANGE%^is attached to the wall of the building "+
      "to the west.  It has bold script proclaiming a message you "+
      "could read.");
   add_item("east sign","%^RESET%^%^ORANGE%^A small oval wooden "+
      "sign hanging from a post on the eastern building has a "+
      "neatly lettered message you could read.");
   add_item("eastern sign","%^RESET%^%^ORANGE%^A small oval wooden "+
      "sign hanging from a post on the eastern building has a "+
      "neatly lettered message you could read.");
   add_item("scribe sign","%^RESET%^%^ORANGE%^A small oval wooden "+
      "sign hanging from a post on the eastern building has a "+
      "neatly lettered message you could read.");
   set_door("door","/d/attaya/newseneca/rooms/inn_entrance","west",0);
}

void init(){
   ::init();
   add_action("read_em","read");
}

int read_em(string str){
   if(!str) return 0;
   if(str == "sign"){
      tell_object(TP,"Try reading either the west sign or the east sign.");
      return 1;
   }
   if(str == "east sign" || str == "eastern sign" || str == "scribe sign"){
      tell_object(TP,"\n"+
"%^ORANGE%^      ========\n"+
"    ============\n"+
"   === %^BOLD%^Scribe %^RESET%^%^ORANGE%^===\n"+
"   ==============\n"+
"   ===== %^BOLD%^of %^RESET%^%^ORANGE%^=====\n"+
"   ==============\n"+
"   === %^BOLD%^Seneca %^RESET%^%^ORANGE%^===\n"+
"    ============\n"+
"      ========\n\n"
      );
      if(!TP->query_invis() && !TP->query_hidden()){
         tell_room(TO,""+TPQCN+" seems to be studying the eastern sign.",TP);
      }
      return 1;
   }
   if(str == "west sign" || str == "western sign" || str == "inn sign"){
      tell_object(TP,"\n"+
"%^BOLD%^%^BLUE%^______________%^GREEN%^$$$$$%^BLUE%^_____________\n"+
"__%^GREEN%^$$$$%^BLUE%^_______%^GREEN%^$$$%^BLUE%^___%^GREEN%^$$$$$%^BLUE%^________\n"+
"_%^GREEN%^$$$$$$%^BLUE%^_____%^GREEN%^$$$%^BLUE%^___%^GREEN%^$$$$$$$%^BLUE%^_______\n"+
"%^GREEN%^$$$%^BLUE%^_%^GREEN%^$$$$%^BLUE%^___%^GREEN%^$$$%^BLUE%^__%^GREEN%^$$$$%^BLUE%^____%^GREEN%^$%^BLUE%^_______\n"+
"%^GREEN%^$%^BLUE%^____%^GREEN%^$$$$%^BLUE%^_%^GREEN%^$$$$%^BLUE%^_%^GREEN%^$$$%^BLUE%^______________  %^MAGENTA%^_____                _           _\n"+
"%^BLUE%^_______%^GREEN%^$$$$$$$$$$%^BLUE%^___%^GREEN%^$$$$$%^BLUE%^_______ %^MAGENTA%^|_   _| __ ___  _ __ (_) ___ __ _| |\n"+
"%^BLUE%^____%^GREEN%^$$$$$$$$$$$$%^BLUE%^_%^GREEN%^$$$$%^BLUE%^_%^GREEN%^$$$$$%^BLUE%^_____   %^MAGENTA%^| || '__/ _ \\| '_ \\| |/ __/ _` | |\n"+
"%^BLUE%^___%^GREEN%^$$$$$$$$$$$$$$$$$%^BLUE%^_____%^GREEN%^$$$%^BLUE%^____%^MAGENTA%^   | || | | (_) | |_) | | (_| (_| | |\n"+
"%^BLUE%^__%^GREEN%^$$$%^BLUE%^__%^GREEN%^$$$$$$$$$$$$%^BLUE%^________%^GREEN%^$%^BLUE%^____   %^MAGENTA%^|_||_|  \\___/| .__/|_|\\___\\__,_|_|\n"+
"%^BLUE%^_%^GREEN%^$$%^BLUE%^___%^GREEN%^$$$$$$$$$$$$$$$$$%^BLUE%^_________%^MAGENTA%^                |_|\n"+
"%^GREEN%^$$%^BLUE%^___%^GREEN%^$$$$%^BLUE%^_%^RESET%^%^ORANGE%^$$$%^BOLD%^%^BLUE%^_%^GREEN%^$$$%^BLUE%^__%^GREEN%^$$$$$%^BLUE%^________\n"+
"%^GREEN%^$%^BLUE%^___%^GREEN%^$$$$%^BLUE%^___%^RESET%^%^ORANGE%^$$%^BOLD%^%^BLUE%^__%^GREEN%^$$$$%^BLUE%^___%^GREEN%^$$$%^BLUE%^_______%^MAGENTA%^      ____\n"+
"%^BLUE%^____%^GREEN%^$$$%^BLUE%^_____%^RESET%^%^ORANGE%^$$%^BOLD%^%^BLUE%^___%^GREEN%^$$$%^BLUE%^____%^GREEN%^$$%^BLUE%^______%^MAGENTA%^     | __ ) _ __ ___  ___ _______\n"+
"%^BLUE%^____%^GREEN%^$$%^BLUE%^______%^RESET%^%^ORANGE%^$$$%^BOLD%^%^BLUE%^___%^GREEN%^$$$%^BLUE%^____%^GREEN%^$%^BLUE%^______%^MAGENTA%^     |  _ \\| '__/ _ \\/ _ \\_  / _ \\\n"+
"%^BLUE%^____%^GREEN%^$$%^BLUE%^_______%^RESET%^%^ORANGE%^$$%^BOLD%^%^BLUE%^____%^GREEN%^$$$%^BLUE%^__________%^MAGENTA%^     | |_) | | |  __/  __// /  __/\n"+
"%^BLUE%^____%^GREEN%^$%^BLUE%^________%^RESET%^%^ORANGE%^$$$%^BOLD%^%^BLUE%^____%^GREEN%^$$%^BLUE%^__________%^MAGENTA%^     |____/|_|  \\___|\\___/___\\___|\n"+
"%^BLUE%^_____________%^RESET%^%^ORANGE%^$$$%^BOLD%^%^BLUE%^____%^GREEN%^$%^BLUE%^___________\n"+
"_____________%^RESET%^%^ORANGE%^$$$%^BOLD%^%^BLUE%^________________\n"+
"_____________%^RESET%^%^ORANGE%^$$$%^BOLD%^%^BLUE%^________________\n"+
"_____________%^RESET%^%^ORANGE%^$$$%^BOLD%^%^BLUE%^________________\n"+
"_____________%^RESET%^%^ORANGE%^$$$%^BOLD%^%^BLUE%^________________\n"+
"____________%^RESET%^%^ORANGE%^$$$%^BOLD%^%^BLUE%^_________________\n"+
"___________%^RESET%^%^ORANGE%^$$$$%^BOLD%^%^BLUE%^_________________\n"+
"_________%^RESET%^%^ORANGE%^$$$$$%^BOLD%^%^BLUE%^__________________\n"+
"______%^RESET%^%^ORANGE%^$$$$$$%^BOLD%^%^BLUE%^____________________\n");
      if(!TP->query_invis() && !TP->query_hidden()){
         tell_room(TO,""+TPQCN+" seems to be studying the western sign.",TP);
      }
      return 1;
   }
   return 0;
}