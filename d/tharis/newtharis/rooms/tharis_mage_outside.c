#include <std.h>
#include "../tharis.h"
inherit ROOM;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Mage Tower - Coded in October 2005 by Circe
// Player Designed Area - Originally Player "shop" 
// Never installed into game prior to Tharis City Remodle
// Design work by Sevotharte & Nightfall, finished by Azalon
// Incorporated into the Tharis City Remodle in February 2009 by Ari


void create() {
   ::create();
   set_property("indoors",0);  
   set_property("light",2);    
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Mage Hub - The Courtyard");
   set_short("%^BOLD%^%^MAGENTA%^Mage Hub - The Courtyard%^RESET%^");
   set_long("As you walk down the narrow cobblestone street, you "+
      "find that it widens quite abruptly into what looks almost "+
      "like a small square.  A %^ORANGE%^simple%^WHITE%^, yet "+
      "%^YELLOW%^impressive%^RESET%^ building stands here.  It has "+
      "a rather %^BOLD%^%^WHITE%^unusual shape%^RESET%^, formed "+
      "like a %^ORANGE%^semi-circle%^WHITE%^, or more accurately, "+
      "like a %^ORANGE%^horseshoe%^WHITE%^.  It is not a tall "+
      "structure, obviously only housing a ground floor, but it "+
      "is quite large and likely has a number of rooms inside.  The "+
      "walls are smooth and plastered, %^CYAN%^p%^BOLD%^%^CYAN%^a"+
      "%^RESET%^i%^BOLD%^%^WHITE%^n%^RESET%^t%^BOLD%^%^CYAN%^e%^RESET%^"+
      "%^CYAN%^d %^WHITE%^in a strange %^CYAN%^i%^BOLD%^%^CYAN%^ri"+
      "%^RESET%^d%^BOLD%^%^WHITE%^es%^RESET%^c%^BOLD%^%^CYAN%^en"+
      "%^RESET%^%^CYAN%^t %^WHITE%^shade that %^BOLD%^%^WHITE%^shines"+
      "%^RESET%^ and changes colors like the %^CYAN%^i%^BOLD%^%^CYAN%^"+
      "n%^RESET%^s%^BOLD%^%^WHITE%^i%^RESET%^d%^CYAN%^e of a s%^BOLD%^"+
      "%^CYAN%^e%^RESET%^a%^BOLD%^%^WHITE%^sh%^RESET%^e%^BOLD%^%^CYAN%^"+
      "l%^RESET%^%^CYAN%^l%^WHITE%^.  The small windows are set deep "+
      "inside the thick walls and have a %^MAGENTA%^strange shape"+
      "%^WHITE%^, their tops %^BOLD%^%^BLACK%^curved and pointy, like "+
      "a spade symbol%^RESET%^.  The double door is right in the "+
      "middle of the horseshoe building and it tapers up in the same "+
      "%^BOLD%^%^BLACK%^pointed spade-shape%^RESET%^ as the windows.  "+
      "On the flat roof above the entryway, a %^ORANGE%^co%^YELLOW%^ppe"+
      "%^RESET%^%^ORANGE%^r %^WHITE%^onion-bulb dome rises towards the "+
      "sky, %^YELLOW%^gle%^WHITE%^am%^YELLOW%^ing%^RESET%^ in the light"+
      ".  In the center of the cobblestone %^BOLD%^%^MAGENTA%^courtyard"+
      "%^RESET%^ of the building there is a small fountain, spewing a "+
      "%^BOLD%^%^MAGENTA%^frothy%^RESET%^ liquid that albeit sweet-"+
      "smelling, like some %^BOLD%^%^MAGENTA%^exotic flower%^RESET%^, "+
      "looks quite menacing - perhaps %^BOLD%^%^GREEN%^acidic%^RESET%^.\n");
   set_smell("default","%^BOLD%^%^MAGENTA%^The courtyard has a "+
      "pleasant, flowery smell, largely due to the fountain.%^RESET%^");
   set_listen("default","%^CYAN%^Your ears catch the spirited tune of "+
      "a cord instrument playing an exotic melody.%^RESET%^");
   set_exits(([
      "enter":ROOMS"tharis_mage_entrance",
      "east":ROOMS"north5"
   ]));
//set_pre_exit_functions(({"enter"}),({"GoThroughDoor"}));
}

void init(){
   ::init();
   add_action("drink_em","drink");
   if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}

int drink_em(string str){
   if(!str){
      tell_object(TP,"What are you trying to drink?");
      return 1;
   }
   if(str != "fountain" && str != "water from fountain" && str != "from fountain") return 0;
   tell_object(TP,"%^GREEN%^You lean over to take a drink from "+
      "the sweet-smelling fountain.");
   tell_room(TO,"%^GREEN%^"+TPQCN+" takes a drink from the fountain.",TP);
   tell_object(TP,"%^RED%^Suddenly, you feel your throat constrict "+
      "from the acidic poison of the fountain's liquid!");
   TP->add_poisoning(20);
   set_property("magic",1);
   TP->do_damage("torso",random(20)+1);
   set_property("magic",-1);
   return 1;
}

int GoThroughDoor(){
   if(TP->is_class("mage") || TP->is_class("sorcerer") || avatarp(TP)){
      tell_object(TP,"%^BOLD%^%^CYAN%^The door recognizes your arcane "+
         "powers, and you feel sucked in effortlessly, your feet "+
         "not quite touching the ground for a fleeting moment.");
      if(!TP->query_invis()){
         tell_room(TO,"%^BOLD%^%^CYAN%^"+TPQCN+" approaches the door and seems "+
            "to be sucked inside, "+TP->QP+" feet leaving the "+
            "ground for a moment.",TP);
      }
      return 1;
   }
   tell_object(TP,"%^BOLD%^%^CYAN%^You are jolted as you pass through the door!");
   tell_room(TO,"%^BOLD%^%^CYAN%^"+TPQCN+" passes through the doorway and winces in pain.",TP);
   TP->do_damage("torso",random(10)+10);
   return 1;
}
