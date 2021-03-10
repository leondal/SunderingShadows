//~Circe~ 12/1/07 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Foyer of the Spire of Serenity, Seneca");
   set_short("%^BOLD%^%^WHITE%^Foyer of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Foyer of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^\n"+
      "This open foyer has a vaulted ceiling and is lit by countless "+
      "%^BOLD%^%^BLACK%^wrought iron sconces %^RESET%^placed at different "+
      "levels along the curved %^ORANGE%^tan walls%^RESET%^.  %^BOLD%^"+
      "%^BLACK%^Couches %^RESET%^and %^ORANGE%^chairs %^RESET%^have "+
      "been arranged around %^RED%^rugs %^RESET%^and %^ORANGE%^"+
      "small tables%^RESET%^, creating a few separate sitting areas "+
      "for relaxation.  Amazingly, the western wall has a %^RED%^"+
      "fireplace %^RESET%^set between two of the %^RED%^arched "+
      "windows%^RESET%^, combining with the natural %^YELLOW%^"+
      "candlelight %^RESET%^to make this a cozy room.\n");
   set_smell("default","The clean scent of the ocean mingles with a light fragrance of ozone.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"floor","rug","rugs"}) : "%^ORANGE%^"+
         "The floor here is crafted of tan stone like the majority "+
         "of the tower, and small rugs in varying shades of %^RED%^"+
         "red %^RESET%^%^ORANGE%^and %^YELLOW%^gold %^RESET%^%^ORANGE%^"+
         "have been scattered around to help divide the room into "+
         "sitting areas for comfort.",
      ({"window","windows","archways","archway"}) : "The archways "+
         "have been edged with %^RED%^red stone%^RESET%^.  They are "+
         "narrow rectangles with onion-shaped tops, and they have "+
         "been fitted with thin transparent %^CYAN%^glass%^RESET%^.",
      ({"sconces","wrought iron sconces","candles"}) : "%^BOLD%^"+
         "%^BLACK%^The sconces are worked in many different designs, "+
         "from swirling spirals to delicate flowers to geometric "+
         "patterns.  Each is made of wrought iron and seems to have "+
         "been hand-crafted with no two having the same pattern.  "+
         "They are placed at different intervals and heights along "+
         "the wall, creating a web of diamonds in between them.  "+
         "Each has been fitted with a pillar %^WHITE%^candle "+
         "%^BLACK%^that burns brightly with natural %^YELLOW%^"+
         "light%^BLACK%^.%^RESET%^",
      ({"wall","walls","ceiling"}) : "%^ORANGE%^The walls "+
         "and vaulted ceiling are made of tan stone edged "+
         "at the top and bottom with %^RED%^red%^ORANGE%^.  "+
         "The walls are curved and set with many windows "+
         "between the %^BOLD%^%^BLACK%^iron sconces%^RESET%^"+
         "%^ORANGE%^.%^RESET%^",
      ({"couch","couches","chair","chairs"}) : "The couches and "+
         "chairs are upholstered in various shades of black "+
         "and red, creating a coordinated appearance.  They "+
         "look very comfortable and are spread out around the "+
         "room, giving you ample space to <lie> or <sit>.",
      ({"tables","small tables"}) : "Small tables of different "+
         "sizes and shapes are spread around the room, giving "+
         "the occupants a place for drinks or materials.  You "+
         "notice one table is furnished with a chessboard.",
      ({"fireplace","fire"}) : "The fireplace in the western wall "+
         "is bricked in %^RED%^red%^RESET%^ and must have been "+
         "enchanted in some way, for you don't recall seeing a "+
         "chimney.  On the hearth is a small collection of "+
         "%^ORANGE%^split wood %^RESET%^ready for the fire as well "+
         "as a collection of %^BOLD%^%^BLACK%^iron tools%^RESET%^ "+
         "for tending it."
   ]));
   set_exits(([
      "east" : ROOMS"psi_landing2"
   ]));
}

void reset(){
   ::reset();
   if(!present("delia"))
      find_object_or_load(MON"gemcutter")->move(TO);
    if(!present("chessboard")) new(OBJ"chess_enclave")->move(TO);
}

void init(){
   ::init();
   add_action("sit_em","sit");
   add_action("lie_em","lie");
}

int sit_em(string str){
   if(!str) return 0;
   if(str == "chair" || str == "in chair"){
      tell_object(TP,"%^BOLD%^You settle into one of the comforable chairs in "+
         "the room.%^RESET%^");
      if(!TP->query_invis()){
         tell_room(TO,"%^BOLD%^"+TPQCN+" settles into one of the "+
            "comfortable chairs.%^RESET%^",TP);
      }
      return 1;
   }
   if(str == "couch" || str == "on couch"){
      tell_object(TP,"%^BOLD%^%^BLACK%^You sit on one of the couches "+
         "and feel yourself relaxing after a long day.%^RESET%^");
      if(!TP->query_invis()){
         tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" sits on one of the "+
            "luxurious couches and looks relaxed.%^RESET%^",TP);
      }
      return 1;
   }
   return 0;
}

int lie_em(string str){
   if(!str) return 0;
   if(str != "couch" && str != "on couch") return 0;
   tell_object(TP,"%^RED%^You stretch out on one of the soft couches, "+
      "sinking into the cushions.  What a great place for a nap...%^RESET%^");
   if(!TP->query_invis()){
      tell_room(TO,"%^RED%^"+TPQCN+" stretches out on one of the "+
         "couches, sinking into the cushions.%^RESET%^",TP);
   }
   return 1;
}