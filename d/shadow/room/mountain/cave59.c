//cave59.c - used as inherit for ogre mines portion of Echoes
#include <std.h>
#include "echoes.h"
#define RANDSTUFF "/d/common/daemon/randstuff_d"

inherit CROOM;

void pick_critters();
int item;

void create(){
    pick_critters();
    set_repop(35);
    ::create();
    set_indoors(1);
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("light",1);
    set_name("Inside Echoes Mountains");
    set_short("%^YELLOW%^Inside Echoes Mountains%^RESET%^");
    set_long(
      "This volumnous cavern appears to have been the major working "+
      "%^BOLD%^mine %^RESET%^of the dwarves back when they still "+
      "controlled more than the uppermost tunnels of %^YELLOW%^"+
      "Echoes Mountains%^RESET%^.  Now, it seems the %^RED%^ogres "+
      "%^RESET%^use it for nothing more than their own squallor.  "+
      "%^ORANGE%^Filthy mats%^RESET%^, %^RED%^rotting carcasses"+
      "%^RESET%^, and %^BOLD%^broken bones %^RESET%^litter the "+
      "floor here, seeming quite at odds with the %^BOLD%^sparkling "+
      "%^RED%^g%^YELLOW%^e%^GREEN%^m%^CYAN%^s%^RESET%^ still "+
      "%^BOLD%^g%^RESET%^l%^BOLD%^i%^RESET%^t%^BOLD%^t%^RESET%^e%^BOLD%^r"+
      "%^RESET%^i%^BOLD%^n%^RESET%^g in the walls.  It seems, however, "+
      "that even those have been marred by the random attempts to "+
      "mine by the ogres.  Little of value seems to remain here, "+
      "but piles of %^RED%^rubble %^RESET%^lie scattered all along "+
      "the floor.\n"
    );

    set_items(([
      ({"mold","moss"}) : "Patches of mold and moss ranging from "+
         "dull green to deep brown grow "+
         "along the walls and floor of the tunnels.",
      ({"stone","stones","rubble"}) : "Trails of rubble litter "+
         "the cavern, most of it broken stone "+
         "from the feeble mining attempts of the ogres.  There "+
         "seems to be a fair "+
         "amount of dust and quite a few "+
         "broken bones and bits of fur mixed in.",
      ({"bone","bones","fur"}) : "Mixed in with the broken stone "+
         "are several bones with deep gnaw "+
         "marks and mangled bits of fur.",
      ({"mat","mats"}) : "Mats crusted with filth lie scattered "+
         "along the floor.  It is hard to tell what they were "+
         "once made of, though dirt alone seems to hold them "+
         "together now.  It seems some might be hiding something, "+
         "but...who would want to search under there?",
      ({"carcas","carcases","bodies","corpses"}) : "Thankfully, "+
         "the bodies lying on the floor seem to be mostly rodent "+
         "and amphibian.  It does look, though, like the ogres "+
         "will eat anything slower than they are, and you catch "+
         "a glimpse here and there of some suspiciously dwarf-"+
         "sized bones.",
      ({"gem","gems"}) : "Sadly, the ogres seem to have ruined "+
         "any chance of mining here with their destruction.  It "+
         "is possible the dwarves will be able to repair the mine, "+
         "should they ever be able to reclaim it.  For now, all "+
         "that remains of the gems are the faint glimmers that "+
         "the light reveals.",
	]));
   set_listen("default","Grunts and thuds echo through the cave.");
   set_smell("default","The stench of ogres and other vile "+
      "creatures is unmistakable.");

    set_exits(([
        "northwest" : ROOMS"cave62",
        "north" : ROOMS"cave63",
        "northeast" : ROOMS"cave64",
        "east" : ROOMS"cave60",
        "southeast" : ROOMS"cave56",
        "south" : ROOMS"cave55",
        "southwest" : ROOMS"cave54",
        "west" : ROOMS"cave58"
   	]));
    set_search("default","Although they are disgusting, it's "+
       "possible the ogres have hidden some treasure or another "+
       "beneath their mats.  But...do you really want what an "+
       "ogre would consider a treasure?");
    set_search("mat",(:TO,"search_mats":));
    set_search("mats",(:TO,"search_mats":));
item = 1;
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
   if(!item){
      if(!random(3)){
         item = 1;
      }
   }
}

void pick_critters(){
      switch(random(10)) {     
        case 0..2:  break;
        case 3..4:  set_monsters( ({MOBS"ogre2"}),({random(2)+1}));
                 break;
        case 5:  set_monsters( ({MOBS"ogre", MOBS"ogre2"}),({random(2), 1}));
                 break;
        case 6:  set_monsters( ({MOBS"ogre",MOBS"deep"}),({1,random(2)}));
                 break;
        case 7:  set_monsters( ({MOBS"ogre2",MOBS"deep"}),({2,random(2)}));
                 break;
        case 8:  set_monsters( ({MOBS"deep",MOBS"ogre"}),({1,random(2)}));
                 break;
        case 9:  set_monsters( ({MOBS"half-ogre"}),({random(2)}));
                 break;
      }
}

void search_mats(){
   if(!item){
      tell_object(TP,"It looks like some other brave soul "+
         "already searched the mat - or perhaps one of the ogres "+
         "stole what was there.");
      tell_room(ETP,""+TPQCN+" lifts the mat but finds nothing "+
         "underneath.",TP);
      return;
   }
   if(present("cave_ogre")){
      tell_object(TP,"The ogre seems to be standing right in the way!");
      return 1;
   }
   switch(random(6)){
      case 0..1:  tell_object(TP,"%^RED%^Bugs scurry out and climb up your arm, "+
                     "but you find nothing else beneath the mat.");
                  tell_room(ETP,"%^RED%^"+TPQCN+" lifts the mat but finds nothing "+
                     "but wriggling bugs underneath.",TP);
                  break;
      case 2:  tell_object(TP,"%^BOLD%^You find a wadded piece of paper the "+
                  "ogre was using for a pillow.");
               tell_room(ETP,"%^BOLD%^"+TPQCN+" finds a piece of paper "+
                  "the ogre was using for a pillow.",TP);
               RANDSTUFF->find_stuff(TO,"scroll");
               break;
      case 3:  tell_object(TP,"%^YELLOW%^You find something hidden "+
                  "beneath the filthy mat.");
               tell_room(ETP,"%^YELLOW%^"+TPQCN+" finds something "+
                  "beneath the infested mat.",TP);
               RANDSTUFF->find_stuff(TO,"component",random(5)+4);
               break;
      case 4:  tell_object(TP,"%^YELLOW%^You find something hidden "+
                  "beneath the filthy mat.");
               tell_room(ETP,"%^YELLOW%^"+TPQCN+" finds something "+
                  "beneath the infested mat.",TP);
               RANDSTUFF->find_stuff(TO,"kit",random(5)+4);
               break;
      case 5:  tell_object(TP,"%^YELLOW%^You find something hidden "+
                  "beneath the filthy mat.");
               tell_room(ETP,"%^YELLOW%^"+TPQCN+" finds something "+
                  "beneath the infested mat.",TP);
               RANDSTUFF->find_stuff(TO,"stuff");
               break;
   }
   item = 0;
   return;
}
