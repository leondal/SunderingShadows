//Octothorpe (1/14/10)
//Attaya, Crystal Platform Room 20
//Original by Thundercracker

#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no teleport",1);
   set_property("no sticks",1);
   set_travel(SLICK_FLOOR);
   set_terrain(STONE_BUILDING);
   set_climate("mountain");
   set_name("Quartz Platform");
   set_short("%^BOLD%^A floating quartz platform%^RESET%^");
   set_long("%^BOLD%^A floating quartz platform\n "+
      "This platform is completely tr%^CYAN%^a%^WHITE%^nsp%^CYAN%^a"+
      "%^WHITE%^rent and is composed of a large slab of quartz that is "+
      "approximately a foot thick.  The platform floats within the vast "+
      "interior of the Crystalline Tower of the Black Dawn.  The tower "+
      "itself continues to rise above the platform for thousands of "+
      "feet, until reaching its apex.  Incredibly large panes of "+
      "%^CYAN%^g%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^a%^CYAN%^ss %^WHITE%^"+
      "serve as the tower's ersatz masonry, offering an unobstructed "+
      "view of the whole island and the Saakrune Sea on the horizon.  "+
      "The %^YELLOW%^sun %^WHITE%^beats down relentlessly, yet the "+
      "temperature is remarkably comfortable, complete with even a "+
      "slight breeze.  Suspended in the center of the center of the "+
      "chamber, at some distance from this platform, is an enormous "+
      "%^BOLD%^%^BLACK%^obsid%^RESET%^i%^BOLD%^%^BLACK%^an cube"+
      "%^WHITE%^.\n "+
	  "%^BOLD%^A %^RESET%^%^CYAN%^aquamarine %^WHITE%^crystal hovers here.%^RESET%^\n");
   set("night long","%^BOLD%^A floating quartz platform%^RESET%^\n "+
      "%^BLUE%^This platform is completely tr%^CYAN%^a%^BLUE%^nsp"+
      "%^CYAN%^a%^BLUE%^rent and is composed of a large slab of "+
      "quartz that is approximately a foot thick.  The platform floats "+
      "within the vast interior of the Crystalline Tower of the Black "+
      "Dawn.  The tower itself continues to rise above the platform for "+
      "thousands of feet, until reaching its apex.  Incredibly large "+
      "panes of %^CYAN%^g%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^a%^CYAN%^ss "+
      "%^RESET%^%^BLUE%^serve as the tower's ersatz masonry, offering "+
      "an unobstructed view of the whole island and the Saakrune Sea "+
      "on the horizon.  The %^WHITE%^m%^YELLOW%^oo%^WHITE%^n %^RESET%^"+
      "%^BLUE%^provides a subdued illumination to the interior of the "+
      "tower.  Suspended in the center of the center of the chamber, "+
      "at some distance from this platform, is an enormous %^BOLD%^"+
      "%^BLACK%^obsid%^RESET%^i%^BOLD%^%^BLACK%^an cube%^RESET%^"+
      "%^BLUE%^.\n "+
	  "%^BLUE%^A %^CYAN%^aquamarine %^RESET%^%^BLUE%^crystal "+
	  "hovers here.%^RESET%^\n");
   set_items(([
      "crystal" : "%^BOLD%^The crystal glistens and adds a spark of "+
	     "color to this otherwise transparent scene.  It shines a "+
		 "brilliant %^RESET%^%^CYAN%^aquamarine%^BOLD%^%^WHITE%^.%^RESET%^",
      "cube" : "%^BOLD%^%^BLACK%^From this distance, probably over a "+
         "mile at least, the cube's size is staggering.  Due to the "+
         "oversized dimensions of the Crystalline Tower of the Black "+
         "Dawn, it is difficult to come up with a close estimation "+
         "of how far across one side of the cube is, but it would "+
         "have to be at least half a mile.  The obsid%^RESET%^i%^BOLD%^"+
         "%^BLACK%^an is extremely smooth and polished to a gl%^RESET%^"+
         "e%^BOLD%^a%^BOLD%^%^BLACK%^m%^WHITE%^i%^BOLD%^%^BLACK%^ng "+
         "patina.%^RESET%^",
      "tower" : "%^BOLD%^The Crystalline Tower of the Black Dawn "+
         "consists of the enormous %^CYAN%^g%^RESET%^%^CYAN%^l%^BOLD%^"+
         "%^WHITE%^a%^CYAN%^ss %^WHITE%^spire which juts out of the "+
         "Attayan jungle.  Its form is highly irregular, only serving "+
         "as a cocoon of sorts, shielding the quartz platforms and the "+
         "alien %^BOLD%^%^BLACK%^obsid%^RESET%^i%^BOLD%^%^BLACK%^an "+
         "cube %^WHITE%^from the outside world.%^RESET%^",
      ({"panes","glass"}):"%^BOLD%^%^CYAN%^The tower is constructed "+
         "entirely of thousands of interlocked panes of g%^RESET%^"+
         "%^CYAN%^l%^BOLD%^%^WHITE%^a%^CYAN%^ss.  The panes seem to "+
         "be magically bound to one another, suggesting the "+
         "craftsmanship of a being not of this plane.%^RESET%^",
      ({"island","jungle"}):"%^GREEN%^From this height the palm trees "+
         "and other foliage of the jungle melt into a sea of green "+
         "around the tower.%^RESET%^",
      ({"ocean","sea","Saakrune Sea","horizon"}):"%^CYAN%^On the distant "+
         "horizon the Saakrune Sea glistens in the light.%^RESET%^",
      ({"quartz platforms","platforms"}):"%^RESET%^Beveled, rectangular "+
         "quartz platforms float at differing heights throughout "+
         "interior of the tower.   They are roughly one foot thick, and "+
         "are suspended in the air most likely using the same means as "+
         "the %^BOLD%^%^BLACK%^obsid%^RESET%^i%^BOLD%^%^BLACK%^an "+
         "cube%^RESET%^.",
   ]));
   set_smell("default","A bouquet of tropical odors somehow manages to "+
      "reach this height.");
   set_listen("default","The slight rustling of the breeze can be heard.");
   set_exits(([
      "southwest":TWR"tower19",
   ]));
}

void init(){
   string tod;
   ::init();
   add_action("touch_me","touch");
   add_action("take_me","take");
}

int take_me(string str){
   if(str == "crystal"){
      tell_room(ETP,"%^BOLD%^"+TPQCN+" tries to take the crystal, but "+
	     "gets %^YELLOW%^sh%^WHITE%^o%^YELLOW%^cked %^WHITE%^and "+
		 "disappears!%^RESET%^",TP);
      tell_object(TP,"%^BOLD%^As you try to take the crystal, it "+
         "%^YELLOW%^sh%^WHITE%^o%^YELLOW%^cks %^WHITE%^you and "+
         "teleports you elsewhere.%^RESET%^");
      TP->do_damage("torso",random(100)+75);
      TP->move_player(TWR"dungeon");
      return 1;
   }
}

int touch_me(string str){
   if(str == "crystal"){
      tell_room(ETP,"%^BOLD%^"+TPQCN+" touches the crystal and "+
	     "disappears!%^RESET%^",TP);
      tell_object(TP,"%^BOLD%^You reach out and touch the crystal, "+
	     "and are suddenly transported elsewhere!%^RESET%^");
	  TP->move_player(TWR"tower24");
	  return 1;
   }
}