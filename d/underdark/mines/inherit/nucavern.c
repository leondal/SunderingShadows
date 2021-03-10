//Octothorpe (8/6/08)
//Underdark Mining Caverns, Neutral Cavern Master Room Inherit

#include <std.h>
#include "../defs.h"
inherit CROOM;

int pools;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_travel(DECAYED_FLOOR);
   set_terrain(NAT_CAVE);
   set_property("no teleport",1);

   set_name("%^BOLD%^%^BLACK%^An eerily %^GREEN%^g%^BOLD%^l%^RESET%^"+
      "%^GREEN%^o%^BOLD%^%^BLUE%^w%^RESET%^%^MAGENTA%^i%^BOLD%^ng "+
      "%^BOLD%^%^BLACK%^cavern");
   set_short("%^BOLD%^%^BLACK%^An eerily %^GREEN%^g%^BOLD%^l%^RESET%^"+
      "%^GREEN%^o%^BOLD%^%^BLUE%^w%^RESET%^%^MAGENTA%^i%^BOLD%^ng "+
      "%^BOLD%^%^BLACK%^cavern");
   set_long("%^BOLD%^%^BLACK%^An eerily %^GREEN%^g%^BOLD%^l%^RESET%^"+
      "%^GREEN%^o%^BOLD%^%^BLUE%^w%^RESET%^%^MAGENTA%^i%^BOLD%^ng "+
      "%^BOLD%^%^BLACK%^cavern\n "+
      "This cavern opens up into a large, beehive-shaped void. The "+
      "center of this cavern is dominated by a massive column that "+
      "reaches up to the ceiling of the chamber. Veins of an unusual "+
      "crystal spread over the surface of the rock formation. The "+
      "%^GREEN%^gr%^RESET%^%^GREEN%^ee%^BOLD%^%^GREEN%^n %^BLACK%^and "+
      "%^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^rpl%^RESET%^"+
      "%^MAGENTA%^e %^BOLD%^%^BLACK%^crystals glow eerily on the "+
      "column, providing a bizarre source of illumination to the "+
      "cavern. %^CYAN%^Po%^RESET%^o%^CYAN%^ls %^BOLD%^%^BLACK%^of "+
      "water collect on the cavern floor under the overhanging "+
      "stalactites. Curious looking calcite deposits, known as "+
      "flowstones, form along the walls and the floor of the cavern. "+
      "Although there is a significant amount of moisture present, "+
      "there is a complete lack of any identifiable flora in this "+
      "cavern.%^RESET%^\n");
   set_items(([
      ({"cavern","cave","void","ceiling","chamber","walls"}):"%^BOLD%^"+
         "%^BLACK%^This cave has been formed out of %^RESET%^limestone"+
         "%^BOLD%^%^BLACK%^, and has the general shape of a beehive. "+
         "The %^GREEN%^g%^RESET%^%^MAGENTA%^l%^BOLD%^o%^RESET%^%^GREEN%^"+
         "w %^BOLD%^%^BLACK%^from the crystals cannot adequately light "+
         "the ceiling, thus allowing it to dissolve into a shadowed "+
         "mess of stalactites.  Flowstone deposits have formed along "+
         "the walls and down onto the floor. What basically amounts to "+
         "a conjoined stalagmite and stalactite, has formed into a "+
         "speleothemic column at the center of the cavern.",
      ({"column","formation"}): "%^BOLD%^%^BLACK%^This craggy formation "+
         "reaches from floor to ceiling, and is so massive that it "+
         "almost appears to support the ceiling of the cavern. Veins "+
         "of crystals, known as faerzress, run along the surface of the "+
         "rock. The crystals are either a dull %^GREEN%^g%^BOLD%^re"+
         "%^RESET%^%^GREEN%^e%^BOLD%^n %^BLACK%^or %^MAGENTA%^p%^RESET%^"+
         "%^MAGENTA%^u%^BOLD%^rp%^RESET%^%^MAGENTA%^l%^BOLD%^e%^BLACK%^, "+
         "and give off a glow that slightly illuminates the cavern in "+
         "an eerie cast.",
      ({"faerzress","crystals","crystal","veins"}):"%^BOLD%^%^BLACK%^These "+
         "unusual crystals run along the surface of the rock column in "+
         "rivulet-like veins.  The veins glow in either a dull "+
         "%^GREEN%^g%^BOLD%^re%^RESET%^%^GREEN%^e%^BOLD%^n %^BLACK%^"+
         "or %^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^rp%^RESET%^"+
         "%^MAGENTA%^l%^BOLD%^e%^BLACK%^, which eerily illuminates the "+
         "cavern.",
      ({"pools","pool","water"}):"%^BOLD%^%^BLACK%^Stagnant %^CYAN%^po"+
         "%^RESET%^o%^CYAN%^ls %^BOLD%^%^BLACK%^of water dot the floor "+
         "of the cavern.  They seem to collect under the overhanging "+
         "stalactites. They appear to be unremarkable except for the "+
         "fact that you could probably %^RESET%^splash %^BOLD%^%^BLACK%^"+
         "in them, if you felt so inclined.",
      "floor" : "%^BOLD%^%^BLACK%^The floor of the cavern is rough "+
         "%^RESET%^limestone %^BOLD%^%^BLACK%^dotted with %^CYAN%^po"+
         "%^RESET%^o%^CYAN%^ls %^BOLD%^%^BLACK%^of water. Along the "+
         "walls of the cavern flowstone deposits have formed from the "+
         "moisture that has seeped through the %^RESET%^limestone%^BOLD%^"+
         "%^BLACK%^.",
      "limestone" : "%^BOLD%^%^BLACK%^The %^RESET%^limestone %^BOLD%^"+
         "%^BLACK%^bears some ripple indentations, and periodically "+
         "displays an unusual assortment of fossils. The %^RESET%^"+
         "limestone %^BOLD%^%^BLACK%^cavern tapers towards the top of "+
         "the chamber into a beehive shape.",
      ({"flowstones","calcite","deposits","flowstone"}):"%^BOLD%^"+
         "%^BLACK%^These formations are the result of seeping water "+
         "carrying dissolved minerals. The deposits take on a bulbous "+
         "shape along the cavern walls down to the floor. You almost "+
         "think that one of the deposits shifted slightly out of the "+
         "corner of your eye. Perhaps it was only the glowing from the "+
         "faerzress playing tricks on your eyes.%^RESET%^",
   ]));
   set_smell("default","The smell of wet limestone is particularly "+
      "strong here.");
   set_listen("default","You can hear the pitter-patter of dripping "+
      "water, and a slight buzzing noise that seems to be originating "+
      "from the back of your head.");
   pools = 3; 
}

void reset(){
   ::reset();
   if(!pools) pools = 3;
   if(TO->query_property("no magic"))
      { if(!random(3))TO->remove_property("no magic"); }
   else
      { if (!random(3))TO->set_property("nomagic",1); }
}

void init(){
   ::init();
   add_action("splash_fun", "splash");
}

int splash_fun(string str){
   if(!str){
      tell_object(TP,"Splash what?");
      return 1;
   }
   if(str == "pool" || str == "pools" || str == "water"){
      if(pools <1){
         tell_object(TP,"It appears as though someone has already "+
            "splashed all the pools of water in the surrounding area "+
            "into oblivion.");
         tell_room(ETP,""+TPQCN+" looks around for a pool of water to "+
            "splash in, but cannot find one.",TP);
         return 1;
      }
      tell_object(TP,"You splash in one of the pools with the "+
         "enthusiasm of a young child.");
      tell_room(ETP,""+TPQCN+" splashes around in one of the pools of "+
         "water in a sophomoric manner.",TP);
      if(!random(5)) new(MON"floele")->move(TO);
      pools--;
      return 1;
   }
   return 0;
}