//Octothorpe (1/14/17)
//Shadow, Mage Tower Courtyard

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("Courtyard of the Shadow Mage Tower");
   set_short("%^BOLD%^Courtyard of the %^BOLD%^%^BLACK%^Shadow "+
      "%^WHITE%^Mage Tower%^RESET%^");
   set_long("%^BOLD%^Courtyard of the %^BOLD%^%^BLACK%^Shadow "+
      "%^WHITE%^Mage Tower%^RESET%^\n"+
      "%^MAGENTA%^This large, semi-circular courtyard is cast in "+
      "the %^BOLD%^%^BLACK%^shadow %^RESET%^%^MAGENTA%^of an imposing "+
      "tower. The space is defined by a large, %^CYAN%^round pool"+
      "%^MAGENTA%^, in the middle of which floats a %^WHITE%^stone "+
      "gazebo%^MAGENTA%^. Dark %^BOLD%^%^BLACK%^c%^RESET%^o%^BOLD%^"+
      "%^BLACK%^b%^RESET%^b%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^"+
      "st%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^e%^BOLD%^%^BLACK%^s "+
      "%^RESET%^%^MAGENTA%^spiral outward from the pool's edges, "+
      "stretching to the edges of the courtyard. Each arm of the spiral "+
      "stretches into %^WHITE%^arched alcoves %^MAGENTA%^along the "+
      "tall wall that marks the courtyard's perimeter. A bench is "+
      "nestled into each stone alcove, providing a pleasant space to "+
      "sit. The biggest, grandest archway leads back to the street. "+
      "Stairs frame the %^CYAN%^pool%^MAGENTA%^, where it is possible "+
      "to sit and enjoy the splash of its %^CYAN%^fountains%^MAGENTA%^. "+
      "There does not appear to be any particularly dry access to the "+
      "gazebo.%^RESET%^\n");
   set_smell("default","%^GREEN%^The scent of cloves lingers in the "+
      "air.%^RESET%^");
   set_listen("default","%^CYAN%^The sound of splashing water is "+
      "relaxing.%^RESET%^");
   set_items(([
      ({"pool","stairs","fountains"}) : "%^RESET%^%^CYAN%^Eight stairs "+
         "lead up to this formidable pool. The water is impressively "+
         "clear, yet peering down you can see no end to it, only "+
         "%^BOLD%^%^BLACK%^darkness%^RESET%^%^CYAN%^. The water ripples "+
         "gently as %^WHITE%^petals %^CYAN%^from the overhanging "+
         "blossoms lightly land on its surface. Colorful %^BOLD%^"+
         "%^GREEN%^koi fish %^RESET%^%^CYAN%^swim gracefully through "+
         "the clean water. Marking the cardinal directions, four "+
         "%^BOLD%^%^BLUE%^spouts %^RESET%^%^CYAN%^of water rise and "+
         "fall, at times catching the light just right and casting off "+
         "%^BOLD%^%^RED%^r%^RESET%^%^RED%^a%^ORANGE%^i%^BOLD%^n"+
         "%^GREEN%^b%^RESET%^%^GREEN%^o%^BLUE%^w%^BOLD%^s%^RESET%^"+
         "%^CYAN%^.%^RESET%^",
      "koi" : "%^RESET%^%^CYAN%^These fish swim to and fro, and no "+
         "two seem to be the exact same color.%^RESET%^",
      "gazebo" : "%^RESET%^%^CYAN%^Eight %^BOLD%^%^WHITE%^white "+
         "%^RESET%^%^CYAN%^stone columns spiral upwards, seamlessly "+
         "blossoming into the eight panels that make up the roof. Each "+
         "panel is delicately carved in the image of the %^BOLD%^"+
         "%^MAGENTA%^school of magic %^RESET%^%^CYAN%^that it "+
         "represents. Vines of %^BOLD%^%^WHITE%^white roses %^RESET%^"+
         "%^CYAN%^tumble from the roof, some snaking around the columns, "+
         "while others swing freely like natural curtains, the flowery "+
         "lengths grazing the surface of the %^BOLD%^pool%^RESET%^"+
         "%^CYAN%^. %^BOLD%^%^WHITE%^White petals %^RESET%^%^CYAN%^"+
         "dance upon the %^BOLD%^breeze%^RESET%^%^CYAN%^... You could enter <gazebo> if you wish so.%^RESET%^",
      ({"vines","roses"}) : "%^RESET%^%^CYAN%^Oddly the %^BOLD%^"+
         "%^WHITE%^roses %^RESET%^%^CYAN%^seem to have sprouted from "+
         "the top of the gazebo and now tumble down along the %^BOLD%^"+
         "%^WHITE%^white panels %^RESET%^%^CYAN%^and creep along the "+
         "%^BOLD%^%^WHITE%^columns%^RESET%^%^CYAN%^, while some are "+
         "left to swing freely. Their %^BOLD%^%^WHITE%^white petals "+
         "%^RESET%^%^CYAN%^grace the surface of the pool and dance "+
         "endlessly upon the %^BOLD%^breeze%^RESET%^%^CYAN%^.%^RESET%^",
      ({"stones","spiral","ground","arches","alcoves"}) : "%^RESET%^%^CYAN%^A "+
         "%^BOLD%^%^BLACK%^black spiral %^RESET%^%^CYAN%^cuts through "+
         "the %^WHITE%^white stones %^CYAN%^of the courtyard. Each arm "+
         "reaches to a stone wall, in which alcoves provide shaded"+
         "%^BOLD%^%^BLACK%^seating %^RESET%^%^CYAN%^and a touch of "+
         "privacy. %^GREEN%^Green moss %^CYAN%^covers the inside of "+
         "the old alcoves and creeps along the %^WHITE%^ancient stones "+
         "%^CYAN%^of the tall wall.%^RESET%^",
   ]));
   set_exits(([
      "west" : ROOMS"magefoyer",
      "gazebo" : ROOMS"magegazebo",
      "east" : ROOMS"melistel3"
   ]));
   set_invis_exits(({"gazebo"}));
   set_pre_exit_functions(({"gazebo"}),({"GoThroughDoor"}));
} 

void init()
{
   ::init();
   add_action("jump_fun","jump");
   add_action("jump_fun","sneak");
}

int GoThroughDoor()
{
   if(!TP->is_class("mage") && !TP->is_class("sorcerer") && !avatarp(TP) && !TP->query_property("flying"))
   {
      tell_object(TP,"%^BOLD%^%^WHITE%^You can't seem to find a way "+
         "across the deep pool without getting wet. Perhaps you could "+
         "try %^BOLD%^%^BLACK%^jumping%^BOLD%^%^WHITE%^?%^RESET%^");
      tell_room(TO,"%^BOLD%^%^WHITE%^"+TPQCN+" hesitates at the edge "+
         "of the pool, not finding a way across.%^RESET%^",TP);
      return 0;
   }
   tell_object(TP,"%^BOLD%^You walk easily across the %^CYAN%^d%^RESET%^"+
      "%^CYAN%^e%^BOLD%^ep po%^RESET%^%^CYAN%^o%^BOLD%^l%^WHITE%^, "+
      "your feet never disturbing its %^RESET%^smooth %^BOLD%^"+
      "surface.%^RESET%^");
   tell_room(TO,"%^BOLD%^"+TPQCN+" walks easily across the %^CYAN%^"+
      "d%^RESET%^%^CYAN%^e%^BOLD%^ep po%^RESET%^%^CYAN%^o%^BOLD%^l"+
      "%^WHITE%^, never once disturbing the %^RESET%^smooth %^BOLD%^"+
      "surface.%^RESET%^",TP);
   TP->move_player(ROOMS"magegazebo");
   return 0;
}

int jump_fun(string str)
{
   if(!str)
   {
      tell_object(TP,"Jump what?");
      return 1;
   }
   if(str == "pool")
   {
      if(!"/daemon/saving_throw_d"->reflex_save(TP,-10))
      {
         tell_object(TP,"%^BOLD%^%^BLACK%^You land in the pool and "+
            "fell the %^BLUE%^icy water %^BLACK%^filling your lungs. "+
            "You feel the darkness below tugging at you, drawing you "+
            "into its endless depths!%^RESET%^");
         TP->do_damage("torso",50+random(25));
         tell_object(TP,"%^BOLD%^%^BLACK%^Flailing, you manage to grip "+
            "the side and pull yourself up.%^RESET%^");
         tell_room(TO,"%^BOLD%^%^WHITE%^"+TPQCN+" falls into the icy "+
            "water, arms flailing….  Before managing to pull themselves "+
            "out, dripping and shivering.%^RESET%^",TP);
         return 1;
      }
      tell_object(TP,"%^BOLD%^%^WHITE%^You leap into the air and "+
         "manage, barely, to gain your footing on the other side!%^RESET%^");
      tell_room(TO,"%^BOLD%^%^WHITE%^"+TPQCN+" sails across the pool after "+
         "a mighty leap, smoothly landing on the other side!%^RESET%^",TP);
      TP->move_player(ROOMS"magegazebo");
      return 1;
      }
}
void reset()
{
   ::reset();
   if(!present("agadan"))
   {
      new(MON"agadan")->move(TO);
   }
}