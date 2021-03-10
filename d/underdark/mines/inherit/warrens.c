//Octothorpe (8/13/08)
//Underdark Mining Caverns, Hook Horror Hideaway Master Inherit

#include <std.h>
#include "../defs.h"
inherit CROOM;

object ob;
int item;
int active;

void create(){
   item = 1;
   set_monsters(({MON"hookgrunt"}),({1+random(2)}));
   :: create();
   set_property("indoors",1);
   set_property("light",1);
   set_property("no teleport",1);
   set_property("no magic",1);
   set_travel(DECAYED_FLOOR);
   set_terrain(NAT_CAVE);
   set_repop(40);

   set_name("%^BOLD%^%^BLACK%^A %^RESET%^limestone %^BOLD%^%^BLACK%^"+
      "warren");
   set_short("%^BOLD%^%^BLACK%^A %^RESET%^limestone %^BOLD%^%^BLACK%^"+
      "warren");
   set_long("%^BOLD%^%^BLACK%^A %^RESET%^limestone %^BOLD%^%^BLACK%^"+
      "warren\n "+
      "This cave is recessed into the ceiling of the larger %^RESET%^"+
      "limestone %^BOLD%^%^BLACK%^cavern below. The floor of the "+
      "warren bears jagged channels of %^GREEN%^gr%^RESET%^%^GREEN%^"+
      "ee%^BOLD%^%^GREEN%^n %^BLACK%^and %^MAGENTA%^p%^RESET%^%^MAGENTA%^"+
      "u%^BOLD%^%^MAGENTA%^rpl%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLACK%^"+
      "crystals that cover the rock colmun in the chamber below. The "+
      "faerzress crystals give off a pulsating %^GREEN%^g%^RESET%^"+
      "%^MAGENTA%^l%^BOLD%^o%^RESET%^%^GREEN%^w%^BOLD%^%^BLACK%^, "+
      "drowning the area in a sickly color. Small chunks of %^RESET%^"+
      "limestone %^BOLD%^%^BLACK%^collect around the handful of "+
      "stalagmites found in the warren.  Some finely picked at, and "+
      "some otherwise, remains are piled in one corner behind a "+
      "stalagmite.\n");
   set_items(([
      ({"cave","warren","area","chamber"}):"%^BOLD%^%^BLACK%^This area "+
         "is a void between the top of the rock column from the cavern "+
         "below and the cave ceiling.  The ceiling in here is lower "+
         "slung than most of the other caves in the surrounding area, "+
         "reaching only a couple dozen of feet high.  The walls are of "+
         "the same rough %^RESET%^limestone %^BOLD%^%^BLACK%^found in "+
         "the cavern below.",
      "ceiling" : "%^BOLD%^%^BLACK%^The whole of the %^RESET%^limestone "+
         "%^BOLD%^%^BLACK%^ceiling is within sight because of the "+
         "%^GREEN%^g%^RESET%^%^MAGENTA%^l%^BOLD%^o%^RESET%^%^GREEN%^w "+
         "%^BOLD%^%^BLACK%^of the faerzress.  The ceiling reaches up to "+
         "a height over twenty feet or so, almost making this cave "+
         "feel clausterphobic compared to the larger cavern below.",
      ({"floor","stalagmites"}):"%^BOLD%^%^BLACK%^Long cracks of "+
         "%^GREEN%^gr%^RESET%^%^GREEN%^ee%^BOLD%^%^GREEN%^n %^BLACK%^"+
         "and %^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^rpl"+
         "%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLACK%^peek through the "+
         "floor.  Some faerzress rises above the %^RESET%^limestone"+
         "%^BOLD%^%^BLACK%^, but mostly the crystals seem worn down "+
         "by regular traffic.  Some stalagmites reach up from the "+
         "floor, around which some chunks of %^RESET%^limestone %^BOLD%^"+
         "%^BLACK%^and other types of rocks collect.",
      ({"faerzress","crystals","crystal","channels"}):"%^BOLD%^"+
         "%^BLACK%^These unusual crystals run along the surface of "+
         "the floor in large channels.  They pulsate in either a dull "+
         "%^GREEN%^g%^BOLD%^re%^RESET%^%^GREEN%^e%^BOLD%^n %^BLACK%^or "+
         "%^MAGENTA%^p%^RESET%^%^MAGENTA%^u%^BOLD%^rp%^RESET%^"+
         "%^MAGENTA%^l%^BOLD%^e%^BLACK%^, which eerily illuminate the "+
         "cavern in a sickly cast.  Some faerzress rises above the "+
         "%^RESET%^limestone %^BOLD%^%^BLACK%^, but mostly the crystals "+
         "seem worn down by regular traffic.",
      ({"chunks","chunk","limestone","rock","rocks"}):"%^BOLD%^"+
         "%^BLACK%^Chunks of %^RESET%^limestone %^BOLD%^%^BLACK%^are "+
         "found strewn around the floor, with some situated around the "+
         "stalagmites.  The %^RESET%^limestone %^BOLD%^%^BLACK%^is "+
         "interspersed with small, bl%^RESET%^%^ac%^BOLD%^%^BLACK%^kish "+
         "rocks that contrast against the lighter color of the %^RESET%^"+
         "limestone%^BOLD%^%^BLACK%^.  The appearance of these smaller "+
         "rocks is conspicuous since there is a lack of dark colored "+
         "rocks within this cavern complex.",
   ]));
   set_fall_desc("You land with a good thud on the limestone floor "+
      "below...");
   set_search("deafult","Perhaps you can search through the piled "+
      "remains.");
   set_search("remains",(:TO,"search_remains":));
   set_search("pile",(:TO,"search_remains":));
   set_smell("default","The stench of decaying flesh assaults your "+
      "nostrils.");
   set_listen("default","A steady hum originates from the crystals "+
      "in the floor.");
}

void reset(){
   active = has_mobs();
   if(!active){
      if(mons) mons = ([]);
      set_monsters(({MON"hookgrunt"}),({1+random(2)}));
   }
   ::reset();
   item = 1;
}

int search_remains(string str){
   if(!item){
      tell_object(TP,"It looks like the remains have already been rifled "+
         "through.");
      return 1;
   }
   new(OBJ"remains")->move(TO);
   tell_object(TP,"You search through the pile of remains and find "+
      "with some useful gear on it.");

   item = 0;
   return 1;
}