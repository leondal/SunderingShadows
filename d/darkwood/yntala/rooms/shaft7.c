//shaft7
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit CROOM;
int searched;
object ob;

void create(){
   switch(random(13)){
      case 0..2:
      break;
      case 3..10:
         set_monsters(({TMONDIR +"yuan-tip.c"}),({3}));
      break;
      case 11..12:
         set_monsters(({TMONDIR +"yuan-tih.c"}),({2}));
   }
   set_repop(70);

::create();
   set_property("indoors",1);
   set_property("light",-3);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Within a small shaft");
   set_short("%^RESET%^The inside of a pyramid%^RESET%^");
   set_listen("default","Whispers and soft hisses seem to float upon the stale air.");
   set_long((:TO,"ldesc":));
   set_items(([
   "walls":"The walls are smooth and glossy.  Chains hang from them at regular intervals.",
   "chains":"Rusted, open cuffs end the chains that hang from the walls.  They appear to have not been used in quite some time, if ever.",
   "portal":"%^BOLD%^%^CYAN%^Peering through the portal you can see what looks to be another plane.  Snake-like creatures roam freely and you realize this must be the place that they come from.  The portal is too high to reach and there is no way to close it that you can tell.",
   ({"candles","wax","mounds","mounds of wax"}):"Mounds of wax from burnt out candles litter the floor here.  They must have been used in whatever ritual it took to open the portal.",
   "bones":"These bones are clearly very old.  They have been swept uncaringly towards the edge of the room and now lay in a heap.  They appear to be human and you get the feeling that they must belong to whatever adventurers thought it would be a good idea to open the portal.",
   "symbols":"These are clearly arcane symbols writting on the floor, but they are to old and worn out to read.",
]));
   set_exits((["east":INRMS+"shaft6"]));
   set_search("pile",(:TO,"search_pile":));
   set_search("bones",(:TO,"search_pile":));
   searched = 1;
}
void reset() {
   ::reset();
   searched = 1 ;
}
void search_pile() {
   if(searched <= 0) {               
	tell_object(TP,"It would appear that there is nothing in the bones this time.");
      return ;
   }
   if (searched == 1) {  
      switch(random(99)){
         case 0..15:
            write("You found some armor buried in the pile of bones!\n");
            tell_room(TO,""+TPQCN+" digs through the pile of bones and pulls out some armor!", TP);
            new(OBJD+"Carmor.c")->move(TO);
            new(OBJD+"old_key.c")->move(TO);
            searched = 0;
            break;
         case 16..30:
            write("You found a hammer buried in the pile of bones!\n");
            tell_room(TO,""+TPQCN+" digs through the pile of bones and pulls out a small hammer!", TP);
            new(OBJD+"shammer.c")->move(TO);
            new(OBJD+"old_key.c")->move(TO);
            searched = 0;
            break;
         case 31..98:
            write("You dig through the pile of bones but don't seem to find anything but an old, rusting key.");
            tell_room(TO, ""+TPQCN+" digs through the pile of bones but doesn't seem to find anything but an old, rusting key.",TP);
            new(OBJD+"old_key.c")->move(TO);
            searched = 0;
            break;
      }
   }
}
string ldesc(string str){
   return("%^BOLD%^%^BLACK%^The tunnel opens up into a very large circular room here and is what appears to"
" be the end of the tunnel.  %^RESET%^Chains %^BOLD%^%^BLACK%^line the walls and a %^CYAN%^glowing portal"
" %^WHITE%^sh%^CYAN%^i%^WHITE%^mm%^CYAN%^e%^WHITE%^rs %^BLACK%^in the center of the room above you.  A circular"
" area has been carved into the floor just beneath the %^CYAN%^portal %^BLACK%^and has many ancient symbols"
" surrounding it.  Mounds of wax from long lost burnt out candles lay strewn out on the floor and a pile of"
" %^RESET%^bones %^BOLD%^%^BLACK%^have been swept away into a far corner.   Whatever happened here was not"
" pretty.%^RESET%^");
} 



