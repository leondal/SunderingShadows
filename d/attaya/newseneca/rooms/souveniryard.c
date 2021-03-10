//coded by ~Circe~ 10/24/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VAULT;

int uses, stooluses;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(0);
   set_property("light",2);
   set_name("Front Porch of Driftwood");
   set_short("%^RESET%^%^GREEN%^Front Porch of %^ORANGE%^Driftwood%^RESET%^");
   set_long("%^RESET%^%^GREEN%^Front Porch of %^ORANGE%^Driftwood%^GREEN%^,Seneca%^RESET%^\n"+
      "This narrow porch is attached to a small shop with a %^BOLD%^%^BLUE%^"+
      "sign %^RESET%^hanging above its door.  The porch is covered with "+
      "a %^GREEN%^green wooden roof %^RESET%^supported by %^BOLD%^white "+
      "beams %^RESET%^that match the exterior of the building.  A "+
      "simple %^BOLD%^white railing %^RESET%^surrounds the porch, hardly "+
      "needed as it is level with the ground.  Resting on the porch "+
      "floor are three mismatched %^ORANGE%^rocking chairs %^RESET%^and a "+
      "%^BOLD%^%^RED%^brilliant red stool%^RESET%^, all placed her for use "+
      "by anyone stopping in.  A simple sandy trail through the %^GREEN%^"+
      "prickly beach grass%^RESET%^ leads to the %^ORANGE%^co%^RED%^b%^ORANGE%^"+
      "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e street %^RESET%^to the "+
      "west.\n");
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"porch","here","floor","railing"}) : "The porch is a simple affair, a "+
         "narrow resting place with a wooden floor contained by a simple "+
         "wooden railing.  All has been whitewashed, though the sand seems "+
         "to have scoured much of it away.",
      ({"roof","wooden roof","green roof"}) : "%^GREEN%^The wooden roof "+
         "of the porch has been painted a vibrant green, both above and "+
         "below.  It mostly protects visitors to %^ORANGE%^Driftwood "+
         "%^GREEN%^from the elements, though it does leak in a few places.%^RESET%^",
      ({"chair","chairs","rocking chair","rocking chairs"}) : "%^ORANGE%^"+
         "The rocking chairs are similar only in that they are all made of "+
         "pine.  Each seems to have been purchased in a different "+
         "place on the mainland, lending them a mismatched appearance.  "+
         "They are all in good repair, though, and look rather comfortable "+
         "to <sit> in.%^RESET%^",
      ({"stool","red stool"}) : "%^BOLD%^%^RED%^This simple four-legged "+
         "stool is rather low to the ground.  Other than its brilliant "+
         "paint, it is nondescript.  Still, it does provide a nice place "+
         "to <sit> for awhile.%^RESET%^",
      ({"trail","path","grass","beach grass"}) : "A simple sandy trail "+
         "leads a very short distance to the %^ORANGE%^co%^RED%^b%^ORANGE%^"+
         "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e street%^RESET%^.  "+
         "The rest of the small yard is filled with short, prickly "+
         "%^GREEN%^beach grasses%^RESET%^, not good for much but "+
         "cutting bare feet.",
      ({"street","cobblestone"}) : "The %^ORANGE%^co%^RED%^b%^ORANGE%^"+
         "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e street%^RESET%^ "+
         "leads north and south.  It is a broad thoroughfare running "+
         "through the center of Seneca.  The stones in shades of "+
         "%^ORANGE%^brown%^RESET%^, %^RED%^red%^RESET%^, and "+
         "white are arranged to form a pattern of zig-zagging lines.",
      "sign" : ({"%^BOLD%^%^BLUE%^A small %^WHITE%^white sign "+
         "%^BLUE%^with a blue border hangs from the "+
         "edge of the porch roof above the door.  It bears "+
         "the image of a %^RESET%^%^ORANGE%^shore %^BOLD%^%^BLUE%^"+
         "with %^GREEN%^palm trees %^BLUE%^hanging over the "+
         "%^CYAN%^serene water %^BLUE%^and has a message painted "+
         "in neat blue script you could read.%^RESET%^","%^ORANGE%^"+
         "Driftwood - A Souvenir Shop%^RESET%^","wizish"})
   ]));
   set_exits(([
      "west" : ROOMS"skyline42",
      "east" : ROOMS"souvenir"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/souvenir","east",0);
   set_door_description("door","%^GREEN%^The door to the shop is "+
      "fashioned from several planks placed vertically and "+
      "reinforced with two horizontal boards.  It has been painted "+
      "a subdued green and seems rather worn from the sand.%^RESET%^");
   set_door("gate","/d/attaya/newseneca/rooms/skyline42","west",0);
   set_door_description("gate","%^ORANGE%^This small gate separates "+
      "the small pathway leading to a shop "+
      "in the east from the main thoroughfare of Sol Boulevard.%^RESET%^");
   set_pre_exit_functions(({"west","east"}),({"GoThroughDoor","GoThroughDoor"}));
   uses = 0;
   stooluses = 0;
}

void init(){
   ::init();
   add_action("sit_em","sit");
   add_action("stand_em","stand");
   add_action("rock_em","rock");
}

int sit_em(string str){
   if(!str){
      tell_object(TP,"You sit down on the sandy floor of the porch.  "+
         "A rocking chair or the stool might have been more comfortable.");
      tell_room(TO,""+TPQCN+" sits down on the plank floor of the porch.",TP);
      return 1;
   }
   if(str == "chair" || str == "rocking chair" || str == "on chair" || str == "in chair" ||
      str == "on rocking chair" || str == "in rocking chair"){
      if(uses > 2){
         tell_object(TP,"You'll have to wait for someone to stand or "+
            "perhaps sit in their lap.");
         tell_room(ETP,""+TPQCN+" glances at the rocking chairs for a moment.",TP);
         return 1;
      }
      if(TP->query_property("sitting in chair") || TP->query_property("sitting on stool")){
         tell_object(TP,"You are already seated comfortably!");
         return 1;
      }
      tell_object(TP,"%^BOLD%^You settle comfortably into one of the "+
         "wooden rocking chairs and feel the urge to <rock>.");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" settles comfortably into a rocking chair.",TP);
      TP->force_me("pose relaxing in a rocking chair");
      TP->set_property("sitting in chair",1);
      uses++;
      return 1;
   }
   if(str == "stool" || str == "red stool" || str == "on stool" || str == "on red stool"){
      if(stooluses > 0){
         tell_object(TP,"The stool is already in use.");
         tell_room(ETP,""+TPQCN+" glances at the red stool for a moment.",TP);
         return 1;
      }
      if(TP->query_property("sitting in chair") || TP->query_property("sitting on stool")){
         tell_object(TP,"You are already seated comfortably!");
         return 1;
      }
      if((int)TP->query_size() > 1){
         tell_object(TP,"%^BOLD%^%^RED%^You feel massive as you "+
            "sit on the tiny red stool.%^RESET%^");
         tell_room(TO,"%^BOLD%^%^RED%^"+TPQCN+" looks a little "+
            "silly as "+TP->QS+" sits on the tiny stool.%^RESET%^",TP);
         TP->force_me("pose perched precariously on a tiny stool");
         TP->set_property("sitting on stool",1);
         stooluses++;
         return 1;
      }
      tell_object(TP,"%^BOLD%^%^RED%^You settle comfortably on the "+
         "red stool that is just your size.%^RESET%^");
      tell_room(TO,"%^BOLD%^%^RED%^"+TPQCN+" settles comfortably "+
         "onto the stool.%^RESET%^",TP);
      TP->force_me("pose perched comfortably on a stool");
      TP->set_property("sitting on stool",1);
      stooluses++;
      return 1;
   }
   return 0;
}

int stand_em(string str){
   if(!str){
      if(TP->query_property("sitting in chair")){
         tell_object(TP,"You stand up, leaving the rocking chair free for "+
            "someone else.");
         tell_room(TO,""+TPQCN+" stands up from the rocking chair.",TP);
         TP->remove_property("sitting in chair");
         TP->force_me("pose clear");
         uses = uses-1;
         return 1;
      }
      if(TP->query_property("sitting on stool")){
         tell_object(TP,"You stand up, leaving the stool free for "+
            "someone else.");
         tell_room(TO,""+TPQCN+" stands up from the red stool.",TP);
         TP->remove_property("sitting on stool");
         TP->force_me("pose clear");
         stooluses = stooluses-1;
         return 1;
      }
      tell_object(TP,"You stand up.");
      tell_room(TO,""+TPQCN+" stands up.",TP);
      TP->force_me("pose clear");
      return 1;
   }
   return 0;
}

int rock_em(string str){
   if(!str || str == "in chair" || str == "chair"){
      if(!TP->query_property("sitting in chair")){
         tell_object(TP,"You must be sitting in a rocking chair to rock!");
         return 1;
      }
      tell_object(TP,"You rock lazily in the rocking chair.");
      tell_room(TO,""+TPQCN+" lazily rocks in the rocking chair.",TP);
      return 1;
   }
}

int GoThroughDoor(){
   if((int)TP->query_property("sitting in chair") == 1 || (int)TP->query_property("sitting on stool") == 1){
      tell_object(TP,"You'll need to <stand> first so someone else "+
         "can have your seat if they'd like.");
      return 0;
   }
   return ::GoThroughDoor();
}