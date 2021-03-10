//~Circe~ 11/29/07 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit VAULT;

string COLOR, mycolor;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Entry Hall of the Spire of Serenity, Seneca");
   set_short("%^BOLD%^%^WHITE%^Entry Hall of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Entry Hall of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^\n"+
      "This wide %^BOLD%^entry hall %^RESET%^is circular and open "+
      "in design.  The smooth stone floor has been flawlessly fitted "+
      "with %^RED%^red %^RESET%^and %^ORANGE%^tan %^RESET%^stones in a "+
      "%^RED%^s%^ORANGE%^p%^RED%^i%^ORANGE%^r%^RED%^a%^ORANGE%^l"+
      "%^RESET%^ that ends in the center of the room beneath a "+
      "%^RED%^circular rug%^RESET%^.  Centered atop the rug is "+
      "unique %^BOLD%^%^BLACK%^wrought iron table %^RESET%^with a "+
      "%^CYAN%^glass top%^RESET%^.  It supports a %^BOLD%^s"+
      "%^RESET%^h%^BOLD%^i%^RESET%^m%^BOLD%^m%^RESET%^e%^BOLD%^r"+
      "%^RESET%^i%^BOLD%^n%^RESET%^g %^BOLD%^vase %^RESET%^with "+
      "a breathtaking arrangement of %^BOLD%^%^CYAN%^crystal "+
      "flowers%^RESET%^ that seem to dance on an unfelt "+
      "%^CYAN%^breeze%^RESET%^.  Twin %^ORANGE%^staircases "+
      "%^RESET%^curl up the northern and southern walls, leading "+
      "to a second floor.  Each staircase is bordered by "+
      "%^BOLD%^%^BLACK%^iron banisters %^RESET%^capped with "+
      "%^BOLD%^clear crystals%^RESET%^.  Suspended from the ceiling is an "+
      "elegant %^BOLD%^mithril chandelier %^RESET%^fitted with "+
      "%^BOLD%^white candles %^RESET%^and adorned with %^CYAN%^"+
      "teardrop crystals %^RESET%^that shine with %^CYAN%^s"+
      "%^YELLOW%^c%^RED%^i%^RESET%^%^MAGENTA%^n%^BOLD%^t"+
      "%^GREEN%^i%^BLUE%^l%^WHITE%^l%^RESET%^%^ORANGE%^a"+
      "%^GREEN%^t%^YELLOW%^i%^RED%^n%^CYAN%^g %^BLACK%^c"+
      "%^MAGENTA%^o%^GREEN%^l%^YELLOW%^o%^RED%^r%^WHITE%^s "+
      "%^RESET%^in the light.\n");
   set_smell("default","The clean scent of the ocean mingles with a light fragrance of ozone.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"floor","stones","spiral"}) : "Beginning at the doorway, "+
         "the %^ORANGE%^tan floor %^RESET%^is broken by a wide "+
         "band of %^RED%^red %^RESET%^that sprials around the "+
         "room, narrowing smoothly as it goes.  It disappears "+
         "beneath a woven rug in the center of the room.",
      ({"rug","circular rug","woven rug"}) : "This perfectly "+
         "circular rug has been woven primarily in %^RED%^"+
         "red%^RESET%^.  A wide %^ORANGE%^tan border %^RESET%^"+
         "edged in %^RED%^red %^RESET%^forms the outer "+
         "boundary of the rug, and a smooth band of %^YELLOW%^"+
         "golden scrollwork %^RESET%^and %^RED%^red flowers "+
         "%^RESET%^with %^GREEN%^green leaves%^RESET%^ "+
         "adds a decorative touch.  The center of the rug is "+
         "%^RED%^red %^RESET%^with blossoming %^ORANGE%^tan "+
         "%^RESET%^and %^BOLD%^white%^RESET%^ flowers arranged "+
         "amid more %^YELLOW%^scrollwork%^RESET%^.",
      ({"table","iron table","wrought iron table","glass top"}) : 
         "%^BOLD%^%^BLACK%^The center table is graceful in "+
         "design, featuring several rods one inch in diameter "+
         "that have been curved in an asymmetrical design "+
         "of flower stems.  Ends of the stems swoop into "+
         "graceful curlicues while some ends blossom into "+
         "beautiful calla lilies burnished to a b%^BLUE%^"+
         "l%^BLACK%^u%^BLUE%^e%^BLACK%^-%^BLUE%^b%^BLACK%^l"+
         "%^BLUE%^a%^BLACK%^c%^BLUE%^k %^BLACK%^shine.  "+
         "Several curves of the stems have been gathered at "+
         "the top to support the smooth %^CYAN%^glass "+
         "%^BLACK%^perched there.%^RESET%^",
      ({"vase","shimmering vase","flowers","crystal flowers"}) : 
         "Woven %^BOLD%^wire stems %^RESET%^arranged within "+
         "a wide vase support a dazzling display of crystal "+
         "flowers in vibrant colors.  You see delicate "+
         "%^BOLD%^%^BLUE%^bluebells%^RESET%^, %^BOLD%^%^RED%^"+
         "red lilies%^RESET%^, transparent %^BOLD%^calla "+
         "lilies%^RESET%^, gorgeous %^MAGENTA%^purple "+
         "orchids%^RESET%^, and countless other flowers, "+
         "all painstakingly recreated in flawless crystal.",
      ({"staircase","staircases","stairs"}) : "%^ORANGE%^The "+
         "staircases are made of fitted tan stone edged with "+
         "%^RED%^red%^ORANGE%^.  Each staircase curves up "+
         "the wall, joining the other on the landing above.%^RESET%^",
      ({"banister","banisters","clear crystals"}) : 
         "%^BOLD%^%^BLACK%^The banisters are made from wrought "+
         "iron and are slender, supported with narrow spiralling "+
         "rods.  Each banister is capped with a round %^RESET%^"+
         "clear crystal%^BOLD%^%^BLACK%^ that seems to gather "+
         "the light without reflecting it.%^RESET%^",
      ({"chandelier","mithril chandelier","candles","crystals","teardrop crystals"}) :
         "The chandelier in the center of the ceiling is high "+
         "overhead and has swooping arcs and curves from which "+
         "dangle dozens of small, teardrop shaped crystals.  "+
         "It seems as though the crystals are likely clear, "+
         "but the cut and shape of each refracts the light, "+
         "sending out %^BOLD%^i%^CYAN%^r%^GREEN%^i%^YELLOW%^d"+
         "%^RED%^e%^BLACK%^s%^BLUE%^c%^MAGENTA%^e%^RESET%^"+
         "%^ORANGE%^n%^MAGENTA%^t %^RESET%^beams in an "+
         "array of colors.  Spread about the chandelier are "+
         "many slender %^BOLD%^%^WHITE%^white candles %^RESET%^"+
         "that have been mystically enchanted to give off "+
         "light rather than being lit in a convential way."
   ]));
   set_exits(([
      "west" : ROOMS"wstreet34",
      "up" : ROOMS"psi_landing1"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/wstreet34","west",0,0);
   set_door_description("door","The door in the western wall has a unique shape - "+
      "instead of being simply rounded, it has an onion-shaped top that perfectly "+
      "matches the archway around it.  It is crafted of thick %^ORANGE%^pale "+
      "wood %^RESET%^that perfectly matches the %^ORANGE%^tan bands %^RESET%^"+
      "of the tower.  A thick %^ORANGE%^brass ring %^RESET%^serves as the "+
      "door handle.");
   set_pre_exit_functions(({"up"}),({"GoThroughDoor"}));
}

int GoThroughDoor(){
   if(TP->query_true_invis()) return 1;
   if(TP->is_class("psion") && TP->query_discipline()){
      switch((string)TP->query_discipline()){
         case "egoist": COLOR = "red"; mycolor = "%^BOLD%^%^RED%^"; break;
         case "seer": COLOR = "white"; mycolor = "%^BOLD%^%^WHITE%^"; break;
         case "shaper": COLOR = "purple"; mycolor = "%^RESET%^%^MAGENTA%^"; break;
         case "kineticist": COLOR = "golden"; mycolor = "%^YELLOW%^"; break;
         case "nomad": COLOR = "azure"; mycolor = "%^BOLD%^%^CYAN%^"; break;
         case "telepath": COLOR = "blue"; mycolor = "%^BOLD%^%^BLUE%^"; break;
         default: COLOR = "black"; mycolor = "%^BOLD%^%^BLACK%^"; break;
      }
   }else{
      COLOR = "black";
      mycolor = "%^BOLD%^%^BLACK%^";
   }
   tell_object(TP,""+mycolor+"The crystal in the banister flashes "+
      ""+COLOR+" as you climb the stairs.%^RESET%^");
   tell_room(TO,""+mycolor+"The crystal in the banister flashes "+
      ""+COLOR+" as "+TPQCN+" climbs the stairs.%^RESET%^",TP);
   return 1;
}