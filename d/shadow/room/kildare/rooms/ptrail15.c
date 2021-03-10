//ptrail15.c
#include <std.h>
#include "../kildare.h"

inherit "/std/controlroom.c";
void create(){
   switch(random(5)) {
      case 0: break;
      case 1: set_monsters( ({MON"peryton"}),({2}));
              break;
      case 2: set_monsters( ({MON"peryfem"}),({3}));
              break;
      case 3: set_monsters( ({MON"peryton",MON"peryfem"}),({1,2}));
              break;
      case 4..5: set_monsters( ({MON"peryton"}),({1}));
              break;
   }
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_repop(65);
   set_name("Mountain Trail");
   set_short("A twisting mountain trail");
   set_long(
      "The %^ORANGE%^rubble-strewn trail %^RESET%^snakes its way up the %^GREEN%^mountainside%^RESET%^, twisting "+
      "and slithering into the shadows of %^GREEN%^dying evergreens%^RESET%^.  Drying limbs "+
      "click and creak on the wind, creating eerie sounds and %^BOLD%^%^BLACK%^shadows%^RESET%^.  The "+
      "%^YELLOW%^debris %^RESET%^covering the %^ORANGE%^path %^RESET%^shifts with the wind, making footing treacherous. "+
      " Down the mountainside, faint signs of civilization are visible.  A %^BOLD%^%^BLACK%^wisp of "+
      "smoke %^RESET%^rises into the air, hinting at the comfort of indoors, though it only "+
      "serves to emphasize the desolation of the trails here higher up in the mountains."+
      "  The trail seems to end here, with the rock wall of the "+
      "%^GREEN%^mountainside %^RESET%^rising sharply to the south and blocking the path."+
      "\n"
   );
   set("night long",
      "%^BLUE%^The twisted shapes of the bare %^GREEN%^evergreens %^BLUE%^create disconcerting %^BOLD%^%^BLACK%^shadows "+
      "%^RESET%^%^BLUE%^against the night sky.  Skeletal limbs blacker than midnight wave in the air, adding a "+
      "strange sort of dance to the sorrowful dirge of their creaks and groans .  No %^YELLOW%^stars "+
      "%^RESET%^%^BLUE%^seem to shine here, leaving the mountainside bathed in abyssal darkness.  Footing is "+
      "uncertain, with the broken %^ORANGE%^rocks %^BLUE%^of the mountain breaking free and shifting almost "+
      "of their own accord.  No signs of civilization can be found in any direction, and "+
      "it is nearly impossible to tell where the %^WHITE%^trail %^BLUE%^may lead."+
      "The %^GREEN%^mountainside %^BLUE%^rises high to the south suddenly, blocking the way and forming a tall "+
      "black mound between the trees."+
      "\n"
   );
   set_smell("default","A strange scent of decay hangs in the air.");
   set_listen("default","Nearby screeches and roars fill the air.");
   add_item("mountainside","The mountain rises sharply to the "+
         "south, though perhaps not quite as sheer as it seems at first.  A "+
         "few cracks and tiny outcroppings suggest that you might be able to climb it.  "+
         "A few ominous shadows circle overhead here.");
   add_item("mountain","The mountain rises sharply to the "+
         "south, though perhaps not quite as sheer as it seems at first.  A "+
         "few cracks and tiny outcroppings suggest that you might be able to climb it.  "+
         "A few ominous shadows circle overhead here.");
   add_item("mound","The mountain rises sharply to the "+
         "south, though perhaps not quite as sheer as it seems at first.  A "+
         "few cracks and tiny outcroppings suggest that you might be able to climb it.  "+
         "A few ominous shadows circle overhead here.");
   add_item("mound","The mountain rises sharply to the "+
         "south, though perhaps not quite as sheer as it seems at first.  A "+
         "few cracks and tiny outcroppings suggest that you might be able to climb it.  "+
         "A few ominous shadows circle overhead here.");
   add_item("shadows","The shadows high in the air here "+
         "seem to be circling, perhaps waiting to pounce.  You get the feeling that if "+
         "you climb up the side of the mound, they will be on you instantly.");
   add_item("shadow","The shadows high in the air here "+
         "seem to be circling, perhaps waiting to pounce.  You get the feeling that if "+
         "you climb up the side of the mound, they will be on you instantly.");
   add_item("ominous shadows","The shadows high in the air here "+
         "seem to be circling, perhaps waiting to pounce.  You get the feeling that if "+
         "you climb up the side of the mound, they will be on you instantly.");
   set_exits(([
      "southwest" : ROOMS"ptrail16",
      "southeast" : ROOMS"ptrail14"
      ]));
   set_climb_exits(([
      "climb":({ROOMS"nest3",10,6,200}),
      ]));
   set_fall_desc("You lose your grip on the slippery rocks and fall back to rubble-strewn ground!");
set_trap_functions(({"climb","southwest","southeast"}),({"pery1","pery2","pery3"}),({"climb","southwest","southeast"}));
}

int pery1(){
	object ob;
   	if(TP->query_true_invis())
	{
   		return 0;
	}
    	if(interactive(TP))
	{
    		tell_object(TP,"%^BOLD%^%^MAGENTA%^As you start to climb the "+
		"mound, you hear a wrenching screech!%^RESET%^");
		tell_room(ETP,"%^BOLD%^%^MAGENTA%^"+TPQCN+" starts to climb the mound, "+
		"and you hear a wrenching screech!%^RESET%^",TP);
		tell_room(TO,"%^MAGENTA%^Perytons swoop down from above to intercept you!");
    		ob = new(MON"peryton");
        	ob->move(TO);
        	ob->force_me("block climb");
    		ob = new(MON"peryton");
        	ob->move(TO);
        	ob->force_me("block climb");
    		ob = new(MON"peryton");
        	ob->move(TO);
        	ob->force_me("block climb");
    		toggle_trap("climb");
    		return 1;
    	}
}

int pery2(){
   object ob;
   if(TP->query_true_invis())
   return 0;
    if(interactive(TP)){
    tell_object(TP,"%^BOLD%^%^MAGENTA%^As you try to run down the trail, you hear a wrenching screech!%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^MAGENTA%^"+TPQCN+" starts to run down the trail, and you hear a wrenching screech!%^RESET%^",TP);
    tell_room(TO,"%^MAGENTA%^A peryton swoops down from above to intercept you!");
    ob = new(MON"peryton");
        ob->move(TO);
        ob->force_me("block southwest");
    toggle_trap("southwest");
    return 1;
    }
}

int pery3(){
   object ob;
   if(TP->query_true_invis())
   return 0;
    if(interactive(TP)){
    tell_object(TP,"%^BOLD%^%^MAGENTA%^As you try to run down the trail, you hear a wrenching screech!%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^MAGENTA%^"+TPQCN+" starts to run down the trail, and you hear a wrenching screech!%^RESET%^",TP);
    tell_room(TO,"%^MAGENTA%^A peryton swoops down from above to intercept you!");
    ob = new(MON"peryton");
        ob->move(TO);
        ob->force_me("block southeast");
    toggle_trap("southeast");
    return 1;
    }
}


void reset() {
   int active;
   active = has_mobs();
   if(!active) {
      if(mons)  mons = ([]);
      switch(random(4)) {
         case 0..1: break;
         case 2: set_monsters( ({MON"peryton"}),({1}));
                 break;
         case 3: set_monsters( ({MON"peryfem",MON"peryton"}),({2,1}));
                 break;
      }
   }
   ::reset();
        if(!trapped("southwest"))
                toggle_trap("southwest");
        if(!trapped("southeast"))
                toggle_trap("southeast");
        if(!trapped("climb"))
                toggle_trap("climb");
}
void init()

{
        ::init();
        add_action("climb","climb");
}
int climb(string str){
object pery;
        pery = present("peryton", TO);
        if(objectp(pery) && !pery->id("summoned monster")) {
//the above check should stop animated perytons from blocking the way ~Circe~ 4/27/08
                tell_object(TP,"%^BOLD%^%^MAGENTA%^The peryton swoops down and "+
                   "blocks your way!");
        return 1;
        }
        else return 0;
}
