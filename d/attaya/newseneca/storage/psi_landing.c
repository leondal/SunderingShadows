//~Circe~ 12/1/07 for new Seneca
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
   set_name("Landing of the Spire of Serenity, Seneca");
   set_short("%^BOLD%^%^WHITE%^Landing of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Landing of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^\n"+
      "A narrow hallway forms this landing of the enclave.  A "+
      "%^RED%^rectangular rug %^RESET%^has been placed on the "+
      "floor here, muffling the echoes the stone would otherwise "+
      "generate.  On the eastern wall is a %^ORANGE%^framed "+
      "painting%^RESET%^ while an %^RED%^archway %^RESET%^"+
      "leads to the west.  A %^ORANGE%^staircase %^RESET%^with "+
      "a %^BOLD%^%^BLACK%^wrought iron banister %^RESET%^capped "+
      "with a %^BOLD%^round crystal %^RESET%^spirals up "+
      "to the north, while another leads down to the south.\n");
   set_smell("default","The clean scent of the ocean mingles with a light fragrance of ozone.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"rug","rectangular rug","woven rug"}) : "This rug "+
         "is a narrow rectangle of %^RED%^woven red fabric "+
         "%^RESET%^highlighted with a band of %^ORANGE%^tan "+
         "%^RESET%^a few inches in.  It has no further adornment "+
         "but the thickness suggests that it is quite well-made.",
      ({"staircase","stairs","staircases"}) : "%^ORANGE%^The "+
         "staircases are made of fitted tan stone edged with "+
         "%^RED%^red%^ORANGE%^.  One curves up "+
         "the wall, leading to a floor above, while another "+
         "leads back down to the floor below.%^RESET%^",
      ({"banister","banisters","clear crystals"}) : 
         "%^BOLD%^%^BLACK%^The banisters are made from wrought "+
         "iron and are slender, supported with narrow spiralling "+
         "rods.  Each banister is capped with a round %^RESET%^"+
         "clear crystal%^BOLD%^%^BLACK%^ that seems to gather "+
         "the light without reflecting it.%^RESET%^"
   ]));
}

int do_banister(){
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