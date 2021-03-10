//~Circe~ 11/29/07 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Meeting Room of the Spire of Serenity, Seneca");
   set_short("%^BOLD%^%^WHITE%^Meeting Room of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Meeting Room of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^\n"+
      "Placed on the lowest level of the tower, this large room "+
      "is a place for psions to meet with others - both their "+
      "kind and not.  The %^ORANGE%^stone floor %^RESET%^has "+
      "been covered with a large, %^ORANGE%^bronze-colored "+
      "rug %^RESET%^that reaches almost to the walls.  "+
      "A series of narrow %^CYAN%^windows %^RESET%^set within "+
      "%^RED%^archways %^RESET%^with onion-shaped tops line the "+
      "curved walls.  Set between them are %^BOLD%^%^BLACK%^"+
      "cabinets %^RESET%^and %^BOLD%^%^BLACK%^small bookshelves"+
      "%^RESET%^ made from mahogany that hold supplies those "+
      "meeting here might need at hand.  Dominating the room is "+
      "the large, round %^BOLD%^%^BLACK%^mahogany table %^RESET%^"+
      "edged with %^ORANGE%^bronze %^RESET%^that stands proudly "+
      "in the center of the room.  Surrounding it are matching armed "+
      "chairs with %^RED%^cushions%^RESET%^ that provide ample "+
      "seating for all those involved in a meeting.  The door to "+
      "the east may be closed, allowing for privacy.\n");
   set_smell("default","The clean scent of the ocean mingles with a light fragrance of ozone.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"floor","rug","bronze rug","bronze-colored rug"}) : "%^ORANGE%^"+
         "The floor here is crafted of tan stone like the majority "+
         "of the tower, but it has been covered with a round "+
         "%^YELLOW%^bronze rug%^RESET%^%^ORANGE%^.%^RESET%^",
      ({"window","windows","archways","archway"}) : "The archways "+
         "have been edged with %^RED%^red stone%^RESET%^.  They are "+
         "narrow rectangles with onion-shaped tops, and they have "+
         "been fitted with thin transparent %^CYAN%^glass%^RESET%^.",
      ({"cabinets","bookshelves","cabinet","bookshelf"}) : "%^BOLD%^"+
         "%^BLACK%^Small cabinets with screen doors are filled with "+
         "ink, parchment, quills, and various other supplies needed "+
         "often at meetings.  The bookshelves hold tomes on small "+
         "matters of law, the history of Attaya, and various other "+
         "subjects that the denizens of the tower have felt important "+
         "to add over the years.%^RESET%^",
      ({"table","mahogany table"}) : "%^BOLD%^%^BLACK%^The table in the "+
         "center of the room is perfectly circular and perched atop a "+
         "single, massive base.  A thin band of %^RESET%^%^ORANGE%^"+
         "bronze leaf %^BOLD%^%^BLACK%^provides a decorative edge "+
         "to the table.%^RESET%^",
      ({"chair","chairs"}) : "Each chair has a tall slatted back "+
         "and has been fashioned with arms and a %^RED%^cushion "+
         "%^RESET%^to help keep one comfortable during those long "+
         "meetings.  If you like, you can <sit> in one."
   ]));
   set_exits(([
      "east" : ROOMS"psi_landing1"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/psi_landing1","east",0,0);
   set_door_description("door","The door in the western wall has a unique shape - "+
      "instead of being simply rounded, it has an onion-shaped top that perfectly "+
      "matches the archway around it.  It is crafted of thick %^ORANGE%^pale "+
      "wood %^RESET%^that perfectly matches the %^ORANGE%^tan bands %^RESET%^"+
      "of the tower.  A thick %^ORANGE%^brass ring %^RESET%^serves as the "+
      "door handle.");
}

void init(){
   ::init();
   add_action("sit_em","sit");
}

int sit_em(string str){
   if(!str) return 0;
   if(str != "chair" && str != "in chair") return 0;
   tell_object(TP,"You take a seat in one of the comfortable chairs "+
      "and pull yourself toward the table, readying your mind for "+
      "the meeting at hand.");
   if(!TP->query_invis()){
      tell_room(TO,""+TPQCN+" settles into one of the chairs and pulls "+
         ""+TP->QO+"self up to the table.",TP);
   }
   return 1;
}