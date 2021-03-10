#include <std.h>
#include <move.h>
#include "../lothwaite.h"

inherit CROOM;

void pick_critters();
int torch,items;

void create(){
   pick_critters();
   set_repop(35);
   ::create();
   set_name("Ancient Barrows");
   set_short("%^BOLD%^%^BLACK%^Ancient Barrows%^RESET%^");
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_property("light",1);
   set_property("no teleport",1);
   set_property("no sticks",1);
   set_long("%^RESET%^%^BLUE%^This vast %^ORANGE%^chamber "+
      "%^BLUE%^has been chiseled out of the %^RESET%^mountain "+
      "%^BLUE%^itself.  The %^BOLD%^%^BLACK%^deep gray stone "+
      "%^RESET%^%^BLUE%^is shot through with %^BOLD%^%^BLACK%^v"+
      "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
      "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
      "%^YELLOW%^gold%^RESET%^%^BLUE%^, which %^RESET%^s%^BOLD%^h"+
      "%^RESET%^i%^BOLD%^m%^RESET%^m%^BOLD%^e%^RESET%^r %^BLUE%^"+
      "in the %^YELLOW%^light %^RESET%^%^BLUE%^of innumerable "+
      "%^ORANGE%^torches%^BLUE%^.  The %^BOLD%^%^BLACK%^walls "+
      "%^RESET%^%^BLUE%^are flawlessly sleek, making a passageway "+
      "that would rival the %^RESET%^stonework %^BLUE%^of the "+
      "most adept dwarves.  The %^BOLD%^%^BLACK%^ceilings %^RESET%^"+
      "%^BLUE%^arch to a point much like an onion dome, and "+
      "%^ORANGE%^columned supports %^BLUE%^have been carved in "+
      "relief, marching down the meandering hallways.  The "+
      "%^CYAN%^chill air %^BLUE%^of the barrows moves in an "+
      "endless breeze, making the %^ORANGE%^torchlight %^MAGENTA%^"+
      "fli%^BLUE%^ck%^MAGENTA%^er %^BLUE%^and %^MAGENTA%^d"+
      "%^BLUE%^a%^MAGENTA%^n%^BLUE%^c%^MAGENTA%^e%^BLUE%^.%^RESET%^\n");
   set_items(([
      ({"chamber","passageway","passageways","hallways","hallway"}) : "These "+
         "hallways seem to be endless, moving deeper into the mountains.  "+
         "The ground is exceedingly level, with never a rise or dip, and "+
         "the smooth stone walls twist and turn, limiting view.",
      ({"walls","stone walls","wall","stone"}) : "%^BLUE%^The walls of the "+
         "caverns are flawlessly smooth and seem to emit a coldness all "+
         "their own.  They are shot through with %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.",
      ({"veins","black","gold","veins of black and gold"}) : "%^BLUE%^"+
         "The %^BOLD%^%^BLACK%^dark gray stone %^RESET%^%^BLUE%^ of the "+
         "walls is shot through with web-like %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.  The %^YELLOW%^gold %^RESET%^"+
         "%^BLUE%^looks as though it were melted and poured along the "+
         "walls, while the %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^"+
         "almost looks to be a hidden force trying to break through the "+
         "stone.",
      ({"torch","torches","torchlight"}) : "%^YELLOW%^Unlike most torches, "+
         "these are not made of simple wood with fuel-soaked cloth.  Instead, "+
         "each torch has been formed from solid gold and set with %^BLUE%^"+
         "sapphires %^YELLOW%^and %^CYAN%^diamonds%^YELLOW%^.  Strangely, "+
         "you notice no source of fuel that would explain the burning of "+
         "any of the torches.  Perhaps if you took a closer look, you might "+
         "discover their secrets.",
      ({"dome","ceiling","ceilings","onion dome","domes"}) : "The ceilings "+
         "high overhead are hidden in the shadows, but an occasional leap "+
         "of the torchlight reveals onion-shaped domes overhead.  They are "+
         "carved to give the illusion of windows, but only serve to emphasize "+
         "the fact that you are indeed far underground with no way out.",
      ({"shadow","shadows"}) : "The flickering light of the torches sends "+
         "shadows dancing high up the walls, hiding the ceiling from view "+
         "except for brief moments.  They sometimes seem to be hiding something.",
   ]));
   set_listen("default","Your footsteps echo loudly down the deserted corridor.");
   set_smell("default","The cool breath of a tomb is the only smell in the air.");
   set_search("default","The %^BOLD%^%^BLACK%^shadows %^RESET%^flickering in "+
      "the light of the %^YELLOW%^torches %^RESET%^catch your attention.  Come "+
      "to think of it...the torches themselves look fairly interesting.");
   set_search("torches",(:TO,"search_torches":));
   set_search("torch",(:TO,"search_torches":));
   set_search("shadows",(:TO,"search_shadows":));
torch = 0;
items = 0;
 }


int search_torches(string str){
object ob;
   if(torch == 1){
      tell_object(TP,"You search the torches and burn yourself in the process!  Ouch!");
      tell_room(ETP,""+TPQCN+" searches the torches and burns "+TP->QO+"self!",TP);
      TP->do_damage("torso",roll_dice(2,4));
      return 1;
   }
   if(!random(6)){
      tell_object(TP,"You search the torches and realize they seem to be burning "+
         "by magic!  What's more, one of them is loose and you pull it free!");
      tell_room(ETP,""+TPQCN+" searches around and takes one of the torches.",TP);
      ob = new(OBJ"evertorch");
      if(ob->move(TP) != MOVE_OK){ ob->move(ETP);}
      torch = 1;
      return 1;
   }
   if(!random(4)){
      tell_object(TP,"As you search the torches, a small gem falls off into your hand!");
      tell_room(ETP,""+TPQCN+" searches the torches.",TP);
      ob = new("/d/islands/tonerra/obj/gem");
      if(ob->move(TP) != MOVE_OK){ ob->move(ETP);}
      torch = 1;
      return 1;
   }else{
      tell_object(TP,"You search the torches but don't find anything of interest.");
      tell_room(ETP,""+TPQCN+" searches the torches.",TP);
      torch = 1;
      return 1;
   }
}

int search_shadows(){
object ob;
int i,shad;
   if(items == 1){
      tell_object(TP,"You search around in the shadows and find nothing.");
      tell_room(ETP,""+TPQCN+" searches the shadows.",TP);
      return 1;
   }
   if(!random(6)){
      tell_object(TP,"You search the shadows and find something hidden within!");
      tell_room(ETP,""+TPQCN+" searches the shadows and seems to find something!",TP);
      switch(random(5)){
         case 0:  ob = new(OBJ"shadow_amulet");
                  if(ob->move(TP) != MOVE_OK){ ob->move(ETP);}
                  break;
         case 1:  ob = new(OBJ"shadow_circlet");
                  if(ob->move(TP) != MOVE_OK){ ob->move(ETP);}
                  break;
         case 2..4:  ob = new(OBJ"shadow_ring");
                  if(ob->move(TP) != MOVE_OK){ ob->move(ETP);}
                  break;
      }
      items = 1;
      return 1;
   }
   if(!random(4)){
      tell_object(TP,"%^BOLD%^%^BLACK%^The shadows come to life...and attack!!");
      tell_room(ETP,"%^BOLD%^%^BLACK%^As "+TPQCN+" searches the shadows, they "+
         "come to life...and attack!!",TP);
      shad = random(3)+1;
      for(i=0;i<shad;i++){
         new("/d/antioch/ruins/mons/shadow")->move(TO);
      }
      items = 1;
      return 1;
   }
   tell_object(TP,"You search around in the shadows and find nothing.");
   tell_room(ETP,""+TPQCN+" searches the shadows.",TP);
   items = 1;
   return 1;
}

void reset(){
/*
   int active;
   active = has_mobs();
   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
*/
   ::reset();
   if(!random(6)){
      torch = 0;
   }
   if(!random(8)){
      items = 0;
   }
   switch(random(7)){
      case 0:  tell_room(TO,"%^YELLOW%^The light of the torches "+
                  "flickers wildly in a powerful breeze.%^RESET%^");
               break;
      case 1:  tell_room(TO,"%^CYAN%^A ghostly wail can be heard "+
                  "from somewhere deeper in the chamber.%^RESET%^");
               break;
      case 2:  tell_room(TO,"%^BOLD%^%^WHITE%^You feel a cold "+
                  "breath against your cheek and turn!  But...there's "+
                  "nothing there.%^RESET%^");
               break;
      case 3:  tell_room(TO,"%^MAGENTA%^You suddenly hear voices "+
                  "murmuring but it dies out as quickly as it "+
                  "came.%^RESET%^");
               break;
      case 4:  tell_room(TO,"%^ORANGE%^The loud noise of footsteps "+
                  "echoes down the passageway.%^RESET%^");
               break;
      case 5:  tell_room(TO,"%^BOLD%^%^BLACK%^You suddenly feel as "+
                  "if you are being watched!%^RESET%^");
               break;
      case 6:  tell_room(TO,"%^BOLD%^%^WHITE%^A ghostly shape "+
                  "glides across the passage ahead, merging right "+
                  "into the wall!%^RESET%^");
               break;
   }
}

void pick_critters() {
      switch(random(9)){
         case 0:   set_monsters(({MON"firbolgchild"}),({random(3)+1}));
                   break;
         case 1:   set_monsters(({MON"firbolgwarrior"}),({random(2)+1}));
                   break;
         case 2:   set_monsters(({MON"ghostfirbolg"}),({random(3)+2}));
                   break;
         case 3:   set_monsters(({MON"firbolgwarrior",MON"ghostfirbolg"}),({random(2),random(3)+1}));
                   break;
         case 4:   set_monsters(({MON"firbolgchild",MON"firbolgwarrior"}),({1,1}));
                   break;
         case 5:   set_monsters(({MON"ghostfirbolg",MON"firbolgchild"}),({1,random(2)}));
                   break;
         case 6..8: break;
      }
}