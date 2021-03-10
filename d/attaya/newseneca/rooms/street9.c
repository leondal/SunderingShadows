//street9 - Circe 11/22/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit AZUL;

void create(){
   ::create();
   set_long(::query_long()+"To the south, you see a wooden building painted "+
      "%^BOLD%^%^GREEN%^pale green%^RESET%^.  There is a %^MAGENTA%^violet "+
      "sign %^RESET%^in the window.\n");
   set_exits(([
      "west" : ROOMS"street8",
      "east" : ROOMS"street10",
//      "south" : ROOMS"seneca_ms"
   ]));
   add_item("building","The wooden building to the south is painted %^BOLD%^"+
      "%^GREEN%^pale green%^RESET%^ with %^MAGENTA%^violet trim%^RESET%^.  It "+
      "has slender, square %^MAGENTA%^purple columns%^RESET%^ with a matching "+
      "oval %^MAGENTA%^sign %^RESET%^in the single window.  %^BOLD%^"+
      "Upon closer inspection, you notice that the building is still "+
      "showing obvious signs of construction.%^RESET%^");
   add_item("sign","The sign is oval-shaped and bears a message you could read.");
}

void init(){
   ::init();
   add_action("read_em","read");
}

int read_em(string str){
   if(!str || str != "sign") return 0;
   tell_object(TP,"\n"+
" %^MAGENTA%^         ---------------\n"+
"     /////               \\\\\\\\\\\n"+
"   //  _   _   _   _   _   _  \\\\\n"+
" ||   / \\ / \\ / \\ / \\ / \\ / \\   ||\n"+
" |   ( %^BOLD%^S %^RESET%^%^MAGENTA%^| %^BOLD%^e %^RESET%^%^MAGENTA%^| %^BOLD%^n %^RESET%^%^MAGENTA%^| %^BOLD%^e %^RESET%^%^MAGENTA%^| %^BOLD%^c %^RESET%^%^MAGENTA%^| %^BOLD%^a %^RESET%^%^MAGENTA%^)   |\n"+
"|     \\_/ \\_/ \\_/ \\_/ \\_/ \\_/     |\n"+
" |                               |\n"+
" ||       %^BOLD%^Message Service       %^RESET%^%^MAGENTA%^||\n"+
"   \\\\                         //\n"+
"     \\\\\\\\\\               /////\n"+
"          ---------------%^RESET%^\n");
   if(!TP->query_invis() && !TP->query_hidden()){
      tell_room(TO,""+TPQCN+" seems to be studying the sign.",TP);
   }
   return 1;
}