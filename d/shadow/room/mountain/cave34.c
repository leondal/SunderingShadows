//cave34.c - used as inherit for ogre portion of Echoes
#include <std.h>
#include "echoes.h"

inherit CROOM;

void pick_critters();

void create(){
    pick_critters();
    set_repop(35);
    ::create();
    set_indoors(1);
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("light",1);
    set_name("Inside Echoes Mountains");
    set_short("Inside Echoes Mountains");
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "The subtle grandeur of these tunnels has been lost somewhere "+
      "in the %^RED%^decayed state %^RESET%^of the %^BOLD%^%^BLACK%^"+
      "caverns%^RESET%^.  What was once the fantastic "+
      "stonework of the dwarves has given way to the squallor of the "+
      "ogres who have taken over "+
      "this lower level of %^YELLOW%^Echoes Mountains%^RESET%^.  The "+
      "carved "+
      "%^YELLOW%^archways%^RESET%^ and %^BOLD%^%^BLUE%^columns%^RESET%^ "+
      "are now cracked "+
      "and covered in %^GREEN%^mold %^RESET%^and %^GREEN%^moss"+
      "%^RESET%^.  Crude, broken "+
      "%^BOLD%^%^BLACK%^iron sconces %^RESET%^are pounded haphazardly "+
      "into the walls at strange "+
      "intervals, most of them hanging by a single peg and perched at "+
      "an angle.  Few %^ORANGE%^torches "+
      "%^RESET%^are actually in the sconces, however, giving only a "+
      "minimal amount of light.  Broken "+
      "bits of %^BOLD%^%^BLACK%^stone %^RESET%^and small piles of "+
      "rubble line the hall, strewn with %^BOLD%^gnawed bones "+
      "%^RESET%^and %^ORANGE%^rancid furs%^RESET%^.\n"
    );

    set_items(([
      (({"cavern","caverns","tunnel"})) : "These tunnels with vaulted "+
         "ceilings were once grand, created "+
         "by the fantastic dwarven craftsmen.  The ogres here have "+
         "made themselves at home now, turning "+
         "the caves into places of filth.  The floors are still "+
         "smooth but bear cracks now with the "+
         "lack of dwarven attention.",
      (({"archway","archways"})) : "The archways carved into the "+
         "walls curve up to support the vaulted "+
         "ceiling.  Small portions of the arches have fallen away, "+
         "leaving their rubble scattered "+
         "along the floor of the tunnels.",
      (({"column","columns"})) : "Like the vaulted archways, the "+
         "once-stately columns have crumbled "+
         "and fallen into disrepair, adding their rubble to the "+
         "piles on the floor.",
      (({"mold","moss"})) : "Patches of mold and moss ranging from "+
         "dull green to deep brown grow "+
         "along the walls and floor of the tunnels.",
      (({"sconce","iron sconce","sconces","iron sconces","torch","torches"})) : 
         "The black iron sconces "+
         "lining the wall are crudely made and mismatched.  They are "+
         "pounded in the walls at strange "+
         "places, and most of them do not look very sturdy.  The "+
         "torches in them provide the only light "+
         "this deep in the caverns, and it seems not nearly enough "+
         "to penetrate the deep darkness.",
      (({"stone","stones","rubble"})) : "Trails of rubble litter "+
         "the hallway, most of it broken stone "+
         "from the columns and archways.  There seems to be a fair "+
         "amount of dust and quite a few "+
         "broken bones and bits of fur mixed in.",
      (({"bone","bones","fur"})) : "Mixed in with the broken stone "+
         "are several bones with deep gnaw "+
         "marks and mangled bits of fur."
	]));
   set_listen("default","Grunts and thuds echo through the cave.");
   set_smell("default","The stench of ogres and other vile "+
      "creatures is unmistakable.");

    set_exits(([
        "east" : ROOMS"cave35",
        "west" : ROOMS"cave28"
   	]));
}

void reset(){
/*
   int active;
   active = has_mobs();  
   if(!active) { 
      if(mons)  mons = ([]);  
      pick_critters();
   }
*/
   ::reset();
   switch(random(5)){
      case 0:  tell_room(TO,"%^RED%^A disgusting noise issues from "+
                  "further down the passageway, followed by a foul "+
                  "smell.");
               break;
      case 1:  tell_room(TO,"%^BLUE%^You suddenly hear raucous "+
                  "laughter echoing off the cave walls.");
               break;
      case 2:  tell_room(TO,"%^BOLD%^A loud --CLUNK-- sounds as "+
                  "another piece of the archway falls from overhead.");
               break;
      case 3:  tell_room(TO,"%^CYAN%^A cool breeze brings a "+
                  "sickening stench, stirred somehow within the "+
                  "caves.");
               break;
      case 4:  tell_room(TO,"%^ORANGE%^Several large insects "+
                  "crawl over the moldy cracks in the floor, "+
                  "then scurry out of sight.");
               break;
   }
}

void pick_critters(){
      switch(random(6)) {     
        case 0:  break;
        case 1..2:  set_monsters( ({MOBS"ogre2"}),({random(2)+1}));
                 break;
        case 3:  set_monsters( ({MOBS"ogre", MOBS"ogre2"}),({random(2), 1}));
                 break;
        case 4:  set_monsters( ({MOBS"ogre",MOBS"deep"}),({1,random(2)}));
                 break;
        case 5:  set_monsters( ({MOBS"ogre2",MOBS"deep"}),({2,random(2)}));
                 break;
      }
}
