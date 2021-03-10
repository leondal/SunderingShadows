//Octothorpe (4/12/09)
//Attaya, Dark Pylon Room
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
   set_property("no pocket space",1);
   set_travel(SLICK_FLOOR);
   set_terrain(STONE_BUILDING);

   set_name("Dark Pylon");
   set_short("%^BOLD%^%^BLACK%^Atop the obsid%^RESET%^i%^BOLD%^%^BLACK%^"+
      "an cube%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Atop the obsid%^RESET%^i%^BOLD%^%^BLACK%^"+
      "an cube%^RESET%^\n "+
      "%^BOLD%^You are on top of the enormous %^BOLD%^%^BLACK%^"+
      "obsid%^RESET%^i%^BOLD%^%^BLACK%^an cube %^WHITE%^at the center "+
      "of the Crystalline Tower of the Black Dawn.  The tower itself "+
      "continues to rise above the %^BOLD%^%^BLACK%^cube %^WHITE%^"+
      "for thousands of feet, until reaching its apex.  Incredibly "+
      "large panes of %^CYAN%^g%^RESET%^%^CYAN%^l%^BOLD%^%^WHITE%^a"+
      "%^CYAN%^ss %^WHITE%^serve as the tower's ersatz masonry, "+
      "offering an unobstructed view of the whole island and the "+
      "Saakrune Sea on the horizon.  The %^YELLOW%^sun %^WHITE%^"+
      "beats down relentlessly, yet the temperature is remarkably "+
      "comfortable, complete with even a slight breeze.  Suspended "+
      "in the air all around the interior of the tower are numerous "+
      "quartz platforms that slowly orbit about.\n "+
      "A smooth %^BOLD%^%^BLACK%^obsid%^RESET%^i%^BOLD%^%^BLACK%^an "+
      "%^WHITE%^slab stands here, as well as a hovering, %^BOLD%^"+
      "%^BLACK%^dark %^WHITE%^crystal. %^RESET%^");
   set("night long","%^BOLD%^%^BLACK%^Atop the obsid%^RESET%^i%^BOLD%^"+
      "%^BLACK%^an cube%^RESET%^\n "+
      "%^BLUE%^You are on top of the enormous %^BOLD%^%^BLACK%^"+
      "obsid%^RESET%^i%^BOLD%^%^BLACK%^an cube %^RESET%^%^BLUE%^at the center of "+
      "the Crystalline Tower of the Black Dawn.  The tower itself "+
      "continues to rise above the %^BOLD%^%^BLACK%^cube %^RESET%^"+
      "%^BLUE%^for thousands of feet, until reaching its apex.  "+
      "Incredibly large panes of %^CYAN%^g%^RESET%^%^CYAN%^l%^BOLD%^"+
      "%^WHITE%^a%^CYAN%^ss %^RESET%^%^BLUE%^serve as the tower's "+
      "ersatz masonry, offering an unobstructed view of the whole "+
      "island and the g%^WHITE%^li%^RESET%^%^BLUE%^tte%^WHITE%^ri"+
      "%^RESET%^%^BLUE%^ng Saakrune Sea on the horizon.  The %^WHITE%^"+
      "m%^YELLOW%^oo%^WHITE%^n %^RESET%^%^BLUE%^provides a subdued "+
      "illumination to the interior of the tower.  A slight breeze "+
      "brushes past, yet it is uncertain from where it is originating.  "+
      "Suspended in the air all around the interior of the tower are "+
      "numerous quartz platforms that slowly orbit about.\n "+
      "%^BLUE%^A smooth %^BOLD%^%^BLACK%^obsid%^RESET%^i%^BOLD%^"+
      "%^BLACK%^an slab %^RESET%^%^BLUE%^stands here, as well as "+
      "a hovering, %^BOLD%^%^BLACK%^dark %^RESET%^%^BLUE%^"+
      "crystal. %^RESET%^");
   set_items(([
      "cube" : "%^BOLD%^%^BLACK%^From this vantage point the cube is "+
         "quite two-dimensional, yet its size is impressive.  Your "+
         "location appears to be in the exact center of its top side.  "+
         "Due to the oversized dimensions of the Crystalline Tower of "+
         "the Black Dawn, it is difficult to come up with a close "+
         "estimation of how far across this area is, but it would "+
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
      ({"slab","pylon"}):"%^BOLD%^%^BLACK%^This slab is the only blemish "+
         "that can be found on the surface of the cube.  It is formed "+
         "out of the same obsid%^RESET%^i%^BOLD%^%^BLACK%^an as the "+
         "cube, and is roughly the size of an adult human.  Halfway "+
         "up on one side is a %^YELLOW%^brass %^BOLD%^%^BLACK%^lever "+
         "that rests in the up position.  Below the lever a smattering "+
         "of words have been scrawled in dried %^RESET%^%^RED%^"+
         "blood%^BOLD%^%^BLACK%^.%^RESET%^",
      ({"crystal","dark crystal"}):"%^BOLD%^%^BLACK%^Left in its "+
         "natural uncut state this dark crystal contrasts with the "+
         "clean lines of the glass tower, and the simple geometry of "+
         "the obsid%^RESET%^i%^BOLD%^%^BLACK%^an cube.  The crystal "+
         "gl%^RESET%^o%^BOLD%^%^BLACK%^ws slightly, and beckons you "+
         "to reach out and touch it.%^RESET%^",
   ]));
   set_smell("default","A bouquet of tropical odors somehow manages to "+
      "reach this height.");
   set_listen("default","The slight rustling of the breeze can be heard.");
}

void init(){
   ::init();
   add_action("touch_me","touch");
   add_action("read_me","read");
   add_action("take_me","take");
   add_action("pull_me","pull");
}

int touch_me(string str){
   if(str == "crystal"){
      tell_room(ETP,"%^BOLD%^"+TPQCN+" reaches out and touches the "+
         "crystal, then disappears.%^RESET%^",TP);
      tell_object(TP,"%^BOLD%^You feel an electric shock as you touch "+
          "the crystal.%^RESET%^");
      TP->move_player(TWR"tower61");
      return 1;
   }
}

int read_me(string str){
   if(str == "blood" || str == "warning" || str == "words" || str == "message"){
      tell_room(ETP,"%^BOLD%^"+TPQCN+" reads the %^RESET%^%^RED%^bloody "+
         "%^BOLD%^message.%^RESET%^",TP);
      tell_object(TP,"%^BOLD%^You make out the following from the dried "+
         "%^RESET%^%^RED%^blood%^BOLD%^%^WHITE%^: \n "+
         "%^RED%^FLEE FROM HERE!  Take one of the crystals to escape..."+
         "%^RESET%^");
      return 1;
   }
}

int take_me(string str){
   if(str == "crystal"){
      tell_room(ETP,"%^"+TPQCN+" tries to take the crystal, but gets "+
         "%^YELLOW%^sh%^WHITE%^o%^YELLOW%^cked%^WHITE%^and disappears!"+
         "%^RESET%^",TP);
      tell_object(TP,"%^BOLD%^As you try to take the crystal, it "+
         "%^YELLOW%^sh%^WHITE%^o%^YELLOW%^cks %^WHITE%^you and "+
         "teleports you elsewhere.%^RESET%^");
      TP->do_damage("torso",random(100)+75);
      TP->move_player(TWR"dungeon");
      return 1;
   }
}

int pull_me(string str){
   int i;
   object *inven;
   object *live;
   inven = all_living(ETP);
   live = filter_array(inven, "is_non_immortal_player", FILTERS_D);
   if(str == "lever"){
      tell_room(ETP,"%^BOLD%^"+TP->QCN+" reaches out and pulls down "+
         "the %^YELLOW%^brass %^WHITE%^lever, and the floor begins "+
         "to lower slowly.%^RESET%^",TP);
      tell_object(TP,"%^BOLD%^You pull down on the %^YELLOW%^brass "+
         "%^WHITE%^lever, and the floor begins to lower slowly."+
         "%^RESET%^");
      for(i=0;i<sizeof(live);i++){
         if(!objectp(live[i])) continue;
         if(live[i] == TP) continue;
         tell_object(live[i],"%^BOLD%^%^CYAN%^As the floor lowers, "+
            "you pass through a field of gl%^WHITE%^i%^CYAN%^mm%^WHITE%^"+
            "e%^CYAN%^r%^WHITE%^i%^CYAN%^ng light that soothes and "+
            "heals your body.%^RESET%^");
         live[i]->do_damage("torso",(int)live[i]->query_hp() - ((int)live[i]->query_max_hp()));
         live[i]->move_player(TWR"hall2");
      }
      tell_object(TP,"%^BOLD%^%^CYAN%^As the floor lowers, "+
         "you pass through a field of gl%^WHITE%^i%^CYAN%^mm%^WHITE%^"+
         "e%^CYAN%^r%^WHITE%^i%^CYAN%^ng light that soothes and "+
         "heals your body.%^RESET%^");
      TP->do_damage("torso",(int)TP->query_hp() - ((int)TP->query_max_hp()));
      TP->move_player(TWR"hall2");
      return 1;
   }
}