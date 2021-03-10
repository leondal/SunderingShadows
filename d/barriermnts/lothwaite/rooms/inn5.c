//inn5.c - Men's common room for Golden Perch Inn.  Circe 8/16/04
#include <std.h>
#include "../lothwaite.h"
inherit VAULT;

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",1);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Men's Communal Room");
   set_short("Men's Communal Room");
   set_long("%^ORANGE%^This large room is dominated by a round "+
      "%^RESET%^stone hearth %^ORANGE%^in the center of the floor.  "+
      "There, a %^RED%^fire %^ORANGE%^burns low, providing a small "+
      "amount of light and warming the room.  It is a little more "+
      "difficult to see in here than the rest of the inn, which seems "+
      "to be because several men are often sleeping on %^GREEN%^thick "+
      "mattresses %^ORANGE%^arranged on the %^GREEN%^rush-covered "+
      "%^ORANGE%^floor.  Near the northwestern corner of the room, a few "+
      "%^RESET%^wicker chairs %^ORANGE%^have been gathered around a "+
      "%^YELLOW%^round table%^RESET%^%^ORANGE%^ that supports a "+
      "%^YELLOW%^hooded brass lantern%^RESET%^%^ORANGE%^.  Here, a few "+
      "men can often be found playing a quiet game of dice while "+
      "the others sleep.%^RESET%^\n");
   set_items(([
      ({"floor","rush-covered floor","rushes"}) : "%^GREEN%^The "+
         "rushes have been taken from the river and are swept up "+
         "each morning, with those who have outlived their purpose "+
         "being tossed out and the good ones returned.  The floor "+
         "here is made of stone, and the rushes help provide a "+
         "softer footing as well as keeping the stone clean.",
      ({"walls","wall","wattle","wattle walls"}) : "%^ORANGE%^"+
         "The walls are made of wattle - woven panels of osier, or "+
         "willow, that have been packed with mud to seal the cracks "+
         "and keep out the wind.  The thin panels to the east and "+
         "west merely provide separation for the two rooms on "+
         "either side, while the northern wall is reinforced to "+
         "keep out the wind.",
      ({"mattress","mattresses"}) : "%^GREEN%^Fancy by no means, "+
         "the mattresses spread around the floor are made of thick "+
         "green burlap that seems to have softened over time.  Each "+
         "mattress is filled with rushes to make it softer, if not "+
         "necessarily smoother.  Folded at the foot of each mattress "+
         "not in use is a thick %^RESET%^white blanket %^GREEN%^that "+
         "seems to have been woven of wool.",
      ({"fire","hearth","round hearth","stone hearth"}) : "The center of "+
         "the room is taken up by a low-ledged stone hearth that encloses "+
         "a low-burning %^RED%^fire%^RESET%^.  The mattresses are arranged "+
         "in a ring around the %^RED%^fire%^RESET%^, allowing each man "+
         "warmth.",
      ({"chair","chairs","wicker chairs","wicker chair"}) : "Four wicker "+
         "chairs have been provided in the northwestern corner of the "+
         "room.  Here, men can relax away from all the commotion in "+
         "the common room without sleeping.  The chairs are wide-bottomed "+
         "and high-backed, and they seem to have been worn over time into "+
         "comfortable resting places.  Each chair has a plain, thin "+
         "%^CYAN%^cushion%^RESET%^.",
      ({"table","round table"}) : "%^YELLOW%^The round table in the "+
         "northwestern part of the room has been made from pine but "+
         "polished with a golden wax to make it shine like oak.  "+
         "A brass lantern sits atop the table, and there are typically "+
         "dice or cards scattered across its surface.",
      ({"lantern","brass lantern"}) : "%^ORANGE%^This simple lantern "+
         "has a frosted glass hood that helps it create a warm glow "+
         "around the table without disturbing those who are trying "+
         "to sleep.",
      ({"men","sleeping men"}) : "Several men are sleeping "+
         "on the mattresses scattered around the room.  A few are "+
         "clearly firbolgs, but various other races are also "+
         "resting here."
   ]));
   set_smell("default","The pleasant scent of wood smoke fills the air.");
   set_listen("default","Muted conversation and occasional rough laughter can be heard.");
   set_exits(([
      "west" : PATHEXIT"inn4"
   ]));
   set_door("east door",PATHEXIT"inn4","west",0);
   set_door_description("east door","This door is made from a large pine "+
      "plank sanded smooth.  There is no decoration on this side of the door.");
}