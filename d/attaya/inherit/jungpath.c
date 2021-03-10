//Octothorpe (5/24/09)
//Attaya Torch Path Inherit
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit CROOM;

void create()
{
   if(!random(4))
   {
      switch(random(14))
      {
	     case 0..1: set_monsters(({MON"solstice"}),({1+random(3)})); break;
		 case 2..3: set_monsters(({MON"poltergeist"}),({1+random(3)})); break;
		 case 4..5: set_monsters(({MON"entity"}),({1+random(3)})); break;
		 case 6..7: set_monsters(({MON"necrophidius"}),({1})); break;
		 case 8..9: set_monsters(({MON"phalanx"}),({1+random(3)})); break;
		 case 10..11: set_monsters(({MON"warlock"}),({1})); break;
		 case 12..13: set_monsters(({MON"uwarrior"}),({1+random(3)})); break;
      }
   }
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(JUNGLE);
   set_climate("tropical");
   set_repop(60);
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_name("Path through the Attayan jungle");
   set_short("%^GREEN%^A p%^YELLOW%^a%^RESET%^%^GREEN%^th c%^BOLD%^"+
      "%^GREEN%^a%^RESET%^%^GREEN%^rv%^BOLD%^%^GREEN%^e%^RESET%^"+
      "%^GREEN%^d t%^ORANGE%^hr%^GREEN%^o%^BOLD%^%^GREEN%^u%^YELLOW%^"+
      "g%^RESET%^%^GREEN%^h the %^BOLD%^%^GREEN%^A%^RESET%^%^GREEN%^tt"+
      "%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^y%^BOLD%^%^GREEN%^a%^RESET%^"+
      "%^GREEN%^n j%^ORANGE%^u%^GREEN%^ngl%^ORANGE%^e%^RESET%^");
   set_smell("default","A curious mixture of tropical flora and rotting "+
      "flesh flows into your nostrils.");
   set_listen("default","The jungle is eerily silent except for the "+
      "occassional warm breeze and pitter patter of dew.");
   set_items(([
      ({"jungle","bush","foliage"}):"%^GREEN%^The jungle is little more "+
	     "than a nearly impenetrable wall of trees and foliage. Luckily "+
		 "the narrow path offers relatively easy passage through the "+
		 "bush.%^RESET%^",   
      ({"trees","canopy"}):"%^GREEN%^The thick arboreal canopy mostly "+
         "obscures the sky. Numerous types of trees can be found, "+
         "ranging from fruit-bearing fig trees, to giant palm "+
		 "trees.%^RESET%^",
      ({"floor","jungle floor","ground"}):"%^ORANGE%^The floor of the "+
	     "jungle is as cluttered as the canopy above. ",
      "haze" : "%^BOLD%^The perpetual haze obscures much of the "+
	     "surrounding jungle, and surely gives the advantage to your "+
		 "adversaries.%^RESET%^",
   ]));
}

string long_desc(){
   return("%^GREEN%^A p%^YELLOW%^a%^RESET%^%^GREEN%^th c%^BOLD%^"+
      "%^GREEN%^a%^RESET%^%^GREEN%^rv%^BOLD%^%^GREEN%^e%^RESET%^"+
      "%^GREEN%^d t%^ORANGE%^hr%^GREEN%^o%^BOLD%^%^GREEN%^u%^YELLOW%^"+
      "g%^RESET%^%^GREEN%^h the %^BOLD%^%^GREEN%^A%^RESET%^%^GREEN%^tt"+
      "%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^y%^BOLD%^%^GREEN%^a%^RESET%^"+
      "%^GREEN%^n j%^ORANGE%^u%^GREEN%^ngl%^ORANGE%^e%^RESET%^\n "+
      "%^GREEN%^The jungle foliage looms clausterphobically over this "+
      "narrow path that winds deep into the interior of Attaya. A "+
      "variety of trees, including %^MAGENTA%^fig%^GREEN%^-bearing "+
      "trees, palms, and %^YELLOW%^bamboo %^RESET%^%^GREEN%^rises high "+
      "to form a canopy. The canopy is not all encompassing, which "+
      "allows slivers of sunlight to penetrate down to the jungle floor. "+
      "A perpetual %^RESET%^h%^BOLD%^a%^RESET%^ze %^GREEN%^hovers "+
      "beneath the trees, obscuring visibility past twenty yards. "+
      "A mess of tree %^ORANGE%^roots%^GREEN%^, shrubs, and "+
	  "%^YELLOW%^d%^GREEN%^e%^YELLOW%^c%^GREEN%^a%^YELLOW%^y%^GREEN%^"+
	  "i%^YELLOW%^ng %^RESET%^%^GREEN%^plant matter litter the jungle "+
	  "floor. A narrow, well worn path meanders deeper into the "+
	  "jungle...%^RESET%^\n"); 
}

string night_desc(){
   return("%^GREEN%^A p%^YELLOW%^a%^RESET%^%^GREEN%^th c%^BOLD%^"+
      "%^GREEN%^a%^RESET%^%^GREEN%^rv%^BOLD%^%^GREEN%^e%^RESET%^"+
      "%^GREEN%^d t%^ORANGE%^hr%^GREEN%^o%^BOLD%^%^GREEN%^u%^YELLOW%^"+
      "g%^RESET%^%^GREEN%^h the %^BOLD%^%^GREEN%^A%^RESET%^%^GREEN%^tt"+
      "%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^y%^BOLD%^%^GREEN%^a%^RESET%^"+
      "%^GREEN%^n j%^ORANGE%^u%^GREEN%^ngl%^ORANGE%^e%^RESET%^\n "+
      "%^BLUE%^The jungle foliage looms clausterphobically over this "+
      "narrow path that winds deep into the interior of Attaya. A "+
      "variety of trees, including %^MAGENTA%^fig%^BLUE%^-bearing "+
      "trees, palms, and %^YELLOW%^bamboo %^RESET%^%^BLUE%^rises high "+
      "to form a canopy. The canopy is not all encompassing, which "+
      "allows slivers of %^BOLD%^%^WHITE%^m%^YELLOW%^oo%^WHITE%^nlight "+
	  "%^RESET%^%^BLUE%^to penetrate down to the jungle floor. "+
      "A perpetual %^RESET%^h%^BOLD%^a%^RESET%^ze %^BLUE%^hovers "+
      "beneath the trees, obscuring visibility past twenty yards. "+
      "A mess of tree %^ORANGE%^roots%^RESET%^%^BLUE%^, %^GREEN%^"+
	  "shrubs%^BLUE%^, and %^YELLOW%^d%^GREEN%^e%^YELLOW%^c%^GREEN%^"+
	  "a%^YELLOW%^y%^GREEN%^i%^YELLOW%^ng %^RESET%^%^GREEN%^plant "+
	  "matter %^BLUE%^litter the jungle floor. A narrow, well worn path "+
      "meanders deeper into the jungle...%^RESET%^\n"); 
}

void reset()
{
   if(!random(4))
   {
      switch(random(14))
      {
	     case 0..1: set_monsters(({MON"solstice"}),({1+random(3)})); break;
		 case 2..3: set_monsters(({MON"poltergeist"}),({1+random(3)})); break;
		 case 4..5: set_monsters(({MON"entity"}),({1+random(3)})); break;
		 case 6..7: set_monsters(({MON"necrophidius"}),({1})); break;
		 case 8..9: set_monsters(({MON"phalanx"}),({1+random(3)})); break;
		 case 10..11: set_monsters(({MON"warlock"}),({1})); break;
		 case 12..13: set_monsters(({MON"uwarrior"}),({1+random(3)})); break;
      }
   }  
   ::reset();
   if(!present("torch")) new(OBJ"path_torches")->move(TO);
}