//inn1.c - Common room for Golden Perch Inn.  Circe 6/25/04
#include <std.h>
#include "../lothwaite.h"
inherit VAULT;
int uses;

void create(){
   ::create();
   set_indoors(1); 
   set_property("light",2);
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_name("Golden Perch Common Room");
   set_short("Golden Perch Common Room");
   set_long("%^ORANGE%^This large common room is dominated by the "+
      "round %^RESET%^stone %^RED%^hearth %^ORANGE%^in the center "+
      "of the room.  Large oblong %^GREEN%^rugs %^ORANGE%^the same "+
      "%^GREEN%^deep green %^ORANGE%^as the pennants outside "+
      "lie around the %^RED%^fire%^ORANGE%^, providing guests "+
      "with a place to lounge and share stories.  There are a few "+
      "massive %^WHITE%^wicker chairs %^ORANGE%^that stand near "+
      "the northwestern corner of the room, though these seem to "+
      "be constantly in use by townsmen.  No ornamentation adorns "+
      "the simple wattle walls, which seem to be always in %^BOLD%^"+
      "%^BLACK%^shadows %^RESET%^%^ORANGE%^cast by the %^RED%^fire"+
      "%^ORANGE%^.  A large %^BOLD%^%^WHITE%^pine door %^RESET%^"+
      "%^ORANGE%^more finely made than the outer door leads deeper "+
      "into the inn.%^RESET%^\n");
   set_items(([
      ({"rug","rugs","floor"}) : "Unlike most of the other buildings, "+
         "this one has a floor made of well-fitted cobblestones.  "+
         "They are worn smooth and dry-fitted, keeping the floor level "+
         "for the most part.  Covering nearly every inch of the floor "+
         "are various oblong rugs, each about the size of a firbolg "+
         "lying down.  They are all made of %^GREEN%^deep green "+
         "fabric %^RESET%^the same color as that used on the pennants "+
         "outside.  Edging each of the rugs is a border of %^YELLOW%^"+
         "bees %^RESET%^in flight.  They are thick and provide a good "+
         "bit of cushioning for you to <sit> or <lie> on.",
      ({"hearth","stone hearth","fire"}) : "%^BOLD%^The stone hearth "+
         "rises about a foot and a half over the floor.  Recessed "+
         "within is a brightly burning %^RED%^f%^YELLOW%^i%^RED%^r"+
         "%^YELLOW%^e %^WHITE%^that lights the room as well as "+
         "providing warmth.  A stone chimney is situated above it, "+
         "tall archways on each side to allow the fire through as "+
         "as giving patrons a glimpse at the others across the way.",
      ({"chair","chairs","wicker chairs"}) : "These massive, high-"+
         "backed chairs are made from the thick reeds that grow "+
         "in the nearby lake.  The chairs are left their natural "+
         "shade, which is something of a silver beige.  They "+
         "look rather comfortable, and you might be able to <sit> "+
         "in one if it is not taken.",
   ]));
   set_smell("default","The comforting fragrance of the fire fills the room.");
   set_listen("default","The crackling of the fire seems soothing.");
   set_exits(([
      "south" : PATHEXIT"pathway23",
      "north" : PATHEXIT"inn2"
   ]));
   set_door("door",PATHEXIT"pathway23","south",0);
   set_door_description("door","A sturdy wooden door made of hewn pine planks "+
      "lashed together with thick rope and packed with mud to keep out the wind.");
   set_door("pine door",PATHEXIT"inn2","north",0);
   set_door_description("pine door","This door is made from a large pine "+
      "plank sanded smooth.  In the center of the door is the carved "+
      "image of five %^YELLOW%^bees %^RESET%^flying in a diamond pattern.");
   uses = 0;
   set_pre_exit_functions(({"south","north"}),({"GoThroughDoor","GoThroughDoor"}));
}

void reset(){
   ::reset();
   if(!present("firbolg citizen")){
      switch(random(3)){
         case 0:  new(MON"firbolg_citizen")->move(TO);
         case 1:  new(MON"firbolg_citizen")->move(TO);
         case 2:  new(MON"firbolg_citizen")->move(TO);
                  break;
      }
   }
}

void init(){
   ::init();
   add_action("sitem","sit");
   add_action("lie","lie");
   add_action("stand","stand");
}

int sitem(string str){
   if(!str){
      tell_object(TP,"Where would you like to sit - a rug or a chair?");
      return 1;
   }
   if(str == "rug" || str == "down on rug" || str == "on rug" || str == "on a rug"){
      tell_object(TP,"You settle down on one of the plush "+
         "green rugs facing the fire.");
      tell_room(ETP,""+TPQCN+" settles on a rug before the fire.",TP);
      TP->force_me("pose %^RESET%^sitting on a %^GREEN%^green rug%^RESET%^");
      return 1;
   }
   if(str == "chair" || str == "wicker chair" || str == "on chair" || str == "in chair"){
      if(uses > 3){
         tell_object(TP,"You'll have to wait for someone to stand or "+
            "perhaps sit in their lap.");
         tell_room(ETP,""+TPQCN+" glances at the chairs for a moment.",TP);
         return 1;
      }
      if((int)TP->query_size() < 3){
         tell_object(TP,"%^BOLD%^You scramble up into the seat of the "+
            "massive chair and sit with your legs dangling above the "+
            "floor.");
         tell_room(ETP,"%^BOLD%^"+TPQCN+" scrambles up into the chair.",TP);
         TP->force_me("pose sitting in a massive chair");
         TP->set_property("sitting in chair",1);
         uses++;
         return 1;
      }
      tell_object(TP,"%^BOLD%^You settle comfortably in the chair that "+
         "feels like it was made for you.");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" settles comfortably into the chair.",TP);
      TP->force_me("pose sitting comfortably in a chair");
      TP->set_property("sitting in chair",1);
      uses++;
      return 1;
   }
   return 0;
}

int lie(string str){
   if(!str){
      tell_object(TP,"You may lie on a rug if you like.");
      return 1;
   }
   if(str == "rug" || str == "on rug" || str == "down on rug"){
      tell_object(TP,"%^GREEN%^You stretch out on the plush rug and "+
         "feel the %^RED%^fire %^GREEN%^warm you as you realize you "+
         "cannot even feel the stone beneath you.");
      tell_room(ETP,"%^GREEN%^"+TPQCN+" stretches out on a rug before "+
         "the %^RED%^fire%^GREEN%^.",TP);
      TP->force_me("pose lying comfortably on a %^GREEN%^green rug%^RESET%^");
      return 1;
   }
   return 0;
}

int stand(string str){
   if(!str){
      if(TP->query_property("sitting in chair")){
         tell_object(TP,"You stand up, leaving the chair free for "+
            "someone else.");
         tell_room(ETP,""+TPQCN+" stands up from the chair.",TP);
         TP->remove_property("sitting in chair");
         TP->force_me("pose clear");
         uses = uses-1;
         return 1;
      }
      tell_object(TP,"You stand up.");
      tell_room(ETP,""+TPQCN+" stands up.",TP);
      TP->force_me("pose clear");
      return 1;
   }
   return 0;
}

int GoThroughDoor(){
   if((int)TP->query_property("sitting in chair") == 1){
      tell_object(TP,"You'll need to <stand> first so someone else "+
         "can have the chair if they'd like.");
      return 0;
   }
   return ::GoThroughDoor();
}