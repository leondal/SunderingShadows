//grass1.c - Path through Lothwaite.  Circe 6/15/04
#include <std.h>
#include "../lothwaite.h"
inherit VAULT;

void create(){
   ::create();
   set_property("indoors",0); 
   set_property("light",2);
   set_terrain(OLD_MOUNTS);
   set_travel(RUTTED_TRACK);
   set_name("a small grassy knoll");
   set_short("%^GREEN%^A small grassy knoll%^RESET%^");
   set_long("%^GREEN%^This small open area seems to be atop a low "+
      "hill.  While most of the valley seems to be rocky, this small "+
      "portion is covered with %^BOLD%^lush green grass%^RESET%^%^GREEN%^."+
      "  Just north of here is a tall %^ORANGE%^wooden tower %^GREEN%^"+
      "perched upon a %^RESET%^stone base%^GREEN%^.  To the west is a "+
      "small, squat %^ORANGE%^building %^GREEN%^that looks strangely "+
      "like a shop of sorts.  A %^ORANGE%^wooden sign %^GREEN%^hanging "+
      "above the %^BLUE%^blue door%^GREEN%^ that bears the emblem of "+
      "a %^YELLOW%^candle%^RESET%^%^GREEN%^.  The %^ORANGE%^pathway "+
      "%^GREEN%^leading through the village is back to the south and "+
      "west.%^RESET%^\n");
   set_items(([
      ({"path","pathway"}) : "The pathway to the village is to "+
         "both the south and west.  It seems to wind its way "+
         "deeper into the valley or lead westward through the "+
         "gate.",
      ({"knoll","hill","grass","grassy knoll"}) : "%^BOLD%^%^GREEN%^"+
         "This low hill is covered in soft, vibrant green grass.  "+
         "It seems to be a quiet, out of the way place, despite "+
         "the candle-maker's shop and the guard tower overshadowing "+
         "it.  Several small %^YELLOW%^daffodils %^GREEN%^are "+
         "growing, dotting the hillside and adding a touch of color.",
      ({"shop","candle-maker","candle-maker's shop"}) : "%^ORANGE%^"+
         "This is a squat building and looks extremely small to the "+
         "others in the village.  It seems to be a normal, human-sized "+
         "dwelling, though the sign over the door hints that candles "+
         "are probably made and sold inside as well.",
      ({"tower","wooden tower","guard tower"}) : "This tall tower is "+
         "made mostly of wood reinforced with iron.  It sits upon a "+
         "tall base of smooth stone packed with mud.  Several narrow "+
         "arrowslits peer out, though it seems unlikely anyone could "+
         "make it through the rampart.",
      ({"sign","wooden sign"}) : (:TO,"signdesc":)
   ]));
   set_smell("default","Clean, fresh mountain air wafts on the breeze.");
   set_listen("default","The sound of the wind muffles most other noises in the valley.");
   set_exits(([
      "west" : PATHEXIT"candle",
      "north" : PATHEXIT"guard",
      "south" : PATHEXIT"pathway14",
      "east" : PATHEXIT"pathway15"
   ]));
   set_door("door",PATHEXIT"candle","west",0);
   set_door_description("door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.  "+
      "It has been painted what was probably once a bright blue but has now "+
      "faded.");
   set_door("guard door",PATHEXIT"guard","north",0);
   set_door_description("guard door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
}

void signdesc(){
   TP->more(OBJ"candle_sign");
}