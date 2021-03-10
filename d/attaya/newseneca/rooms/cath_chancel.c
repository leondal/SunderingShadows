//cath_chancel.c - "backstage" area of the cathedral
//for new Seneca ~Circe~ 1/17/08
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Chancel of the Cathedral, Seneca");
   set_short("Chancel of the Cathedral, Seneca");
   set_long("%^BOLD%^Chancel of the Cathedral, Seneca%^RESET%^\n"+
      "Unlike a typical sanctuary, this chancel is divided from "+
      "the nave completely by the %^ORANGE%^wooden altar screen "+
      "%^RESET%^to the west.  From this side, a door is clearly "+
      "visible in the middle of the screen, as there is no "+
      "ornamentation or gilding here.  Instead, a simple round "+
      "%^YELLOW%^table%^RESET%^ surrounded by five matching "+
      "%^YELLOW%^chairs%^RESET%^ rests in the center of the %^BOLD%^"+
      "stone floor%^RESET%^, and a %^BOLD%^%^BLACK%^lacquered cabinet "+
      "%^RESET%^stands in the northeast corner.  This room is "+
      "small and function, decorated with a simple %^ORANGE%^"+
      "copper %^RESET%^and %^BOLD%^cream %^RESET%^rug and lit "+
      "with several %^ORANGE%^brass sconces %^RESET%^"+
      "set into the walls.  Supplementing this light is the "+
      "brilliance of the tall %^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
      "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
      "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
      "%^BLUE%^w%^RESET%^%^CYAN%^s %^RESET%^rising along the "+
      "outer walls.\n");
   set_exits(([
      "west" : ROOMS"cath_nave"
   ]));
   set_pre_exit_functions(({"west"}),({"panel"}));
   set_smell("default","The clean scent of the ocean is heightened "+
      "by the pungent fragrance of incense.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"screen","altar screen","wooden altar screen"}) : "From "+
         "this side, the altar screen to the west is plain, though "+
         "finely made.  It has been sanded smooth and lightly "+
         "varnished, and a small door in the center leads back "+
         "into the nave.",
      "door" : "The door, unlike most, has no knob or handle.  It "+
         "looks as if it will simply open as you walk through, no "+
         "matter which way you are going.",
      ({"table","round table","chair","chairs"}) : "The table is "+
         "rather small for the five chairs that surround it, and "+
         "it has clearly seen much use.  Several spots around the "+
         "edges are worn, as if under the strain of many elbows, "+
         "and the chairs have a matching almost shabby quality "+
         "to them that suggests use.",
      ({"floor","stone floor"}) : "The floor here is smooth stone, "+
         "unlike the marble tiles that make up the rest of the "+
         "cathedral.",
      ({"rug","copper rug","cream rug","copper and cream rug"}) : 
         "The rug is wider than the table but the same circular "+
         "shape.  It is largely copper colored and has a wide "+
         "band of cream about three inches before the outer edge.  "+
         "Clearly it has been placed here to provide some measure "+
         "of comfort with the stone floor.",
      ({"cabinet","lacquered cabinet"}) : "%^BOLD%^%^BLACK%^The "+
         "small cabinet in the northeastern corner is lacquered "+
         "black and filled with parchment and quills.%^RESET%^",
      ({"sconce","sconces","brass sconces","candles"}) : "Aside "+
         "from the windows, the illumination of the room is "+
         "provided by the many candles that burn in simple "+
         "brass sconces fitted with glass lids.  They line "+
         "the eastern wall, each with a candle to help brighten "+
         "the room.",
      ({"windows","stained glass windows","stained glass","window"}) : "Each "+
         "of the %^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
         "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
         "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
         "%^BLUE%^w%^RESET%^%^CYAN%^s %^RESET%^is a veritable riot of color, "+
         "breaking the almost dull serenity of the rest of the cathedral.  "+
         "The windows are graceful arching curves ending in points at the "+
         "top.  Each window features countless small colored panels of different "+
         "shapes and sizes."
   ]));
}

int panel(){
   tell_object(TP,"You push the center panel of the altar screen, "+
      "and it opens, allowing you to go into the nave beyond.");
   tell_room(TO,""+TPQCN+" pushes the center panel of the altar "+
      "screen and moves through it as it opens.",TP);
   tell_room("/d/attaya/newseneca/rooms/cath_nave","A small "+
      "central panel in the altar screen opens and "+TPQCN+" "+
      "emerges.",TP);
   return 1;
}