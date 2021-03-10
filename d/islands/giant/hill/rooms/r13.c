#include "/d/islands/giant/giant.h"

inherit ROOM;

int mace = 0;
int club = 0;
int hammer = 0;

void create(){
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set_short("%^ORANGE%^Weapons Room%^RESET%^");
   set_long(
@TERRATO
%^BOLD%^This is where all of the small arms of the hill giants are kept.
Naturally it is the best kept room in the fortress.  It has %^RESET%^polished
stone%^BOLD%^ walls and a clean swept floor.  The weapons are in clyindrical
containers sorted by size and type.  The three largest groups of weapons
are %^RESET%^spears%^BOLD%^, %^RESET%^maces%^BOLD%^ and %^RESET%^clubs%^BOLD%^.  There are also several large %^RESET%^shields%^BOLD%^
covering the back wall of the room.
TERRATO
   );
   set_smell("default","You smell the oil smeared on the weapons to keep them from rusting.");
   set_listen("default","You hear the carousing of giants in the distance.");

   set_items(([
      "spears":"%^BOLD%^This is a pile of spears too large to be used by anything smaller than a hill giant%^RESET%^",
      "clubs":"%^BOLD%^These clubs are of many varieties, some spiked, some smooth, but all are very large%^RESET%^",
      "shields":"%^BOLD%^These shields are giant size, and could not be worn by anyone smaller, some of them do have some intreaging patterns on thier faces though.%^RESET%^",
      "maces":"%^BOLD%^There are only 2 of these, but they are VERY impressive.  One has large boulbous head covered with spikes and the %^RED%^dried blood%^RESET%^%^BOLD%^ of some poor fool who apparently fell to it's wielder.  The other is thinner and has 4 slim prongs on it's end, each looks as if it was crafted to tell an ancient giant story of glory and battle!%^RESET%^",
   ]));

   set_exits(([
      "east":HROOM+"h11.c",
   ]));
}

void init(){
   ::init();
   add_action("take","take");
   add_action("search","search");
}

void reset()
{
   ::reset();
   mace = 0;
   club = 0;
   if(time == "dawn" && !present("giant")){
      new(HMON+"guard.c")->move(TO);
   }
}
int take(string str){
   if(!str){
      write("Take what?");
      return 1;
   }
   if((str == "spear") || (str == "shield")){
      write("Yes, these are fascinating, but are too large to be of any use to you, unless you studied Hill Giants for a living, but you don't, so forget it.");
      return 1;
   }
   if((str == "club") && (club != 1)){
      write("%^BOLD%^You take one of the viscous looking clubs");
      say("%^BOLD%^"+TPQCN+" takes one of the clubs.");
      if(random(2) ==1){
         new(HOBJ+"club1.c")->move(TP);
      } else {
         new(HOBJ+"club2.c")->move(TP);
      }
      club = 1;
      return 1;
   }
   if((str == "mace") && (mace != 1)){
      write("%^BOLD%^You grab one of the impressive looking maces.%^RESET%^");
      say("%^BOLD%^"+TPQCN+" grabs one of the impressive looking maces.%^RESET%^");
      if(random(2) ==1){
         new(HOBJ+"mace1.c")->move(TP);
      } else {
         new(HOBJ+"mace2.c")->move(TP);
      }
      mace = 1;
      return 1;
   } else {
      write("You cannot take that.");
      return 1;
   }
}

int search(string str){
   if(!str){
      write("Search what?");
      return 1;
   }
   if(str == "shield" || "shields"){
      write("%^BOLD%^Behind one of the shields you find a %^RED%^HUGE Hammer%^RESET%^");
      new(HOBJ+"hammer.c")->move(ETP);
      return 1;
   } else {
      write("%^BOLD%^You find nothing of value.");
   }
}
