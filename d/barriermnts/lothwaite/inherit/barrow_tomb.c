//inherit for burial chambers in Lothwaite Barrow Downs.  Circe 5/4/04
#include <std.h>
#include <move.h>
#include "../lothwaite.h"

inherit CROOM;

void pick_critters();
int searched,open,available;

void create(){
   pick_critters();
   set_repop(40);
   ::create();
   set_name("A Grand Chamber");
   set_short("%^YELLOW%^A Grand Chamber%^RESET%^");
   set_indoors(1);
   set_property("light",2);
   set_property("no teleport",1);
   set_property("no sticks",1);
   set_long("%^BOLD%^%^BLUE%^Opening off from the already wide "+
      "passageways, this enormous %^RESET%^%^ORANGE%^chamber %^BOLD%^"+
      "%^BLUE%^is fashioned in a quiet splendor unlike any other.  The "+
      "%^BLACK%^ceilings %^BLUE%^arch high overhead into pointed, "+
      "%^YELLOW%^onion-shaped domes %^BLUE%^which are well-lit by "+
      "rows of %^RESET%^%^ORANGE%^torches %^BOLD%^%^BLUE%^climbing all "+
      "the way up the %^BLACK%^walls%^BLUE%^.  All around the %^RESET%^"+
      "%^ORANGE%^chamber%^BOLD%^%^BLUE%^, %^RESET%^alcoves %^BOLD%^"+
      "%^BLUE%^are set deep within the %^BLACK%^walls%^BLUE%^, with "+
      "the skeletal remains of firbolgs lying within.  The %^RESET%^"+
      "%^ORANGE%^floor %^BOLD%^"+
      "%^BLUE%^is smooth and free of dust, which seems strange given "+
      "the nature of this place.  All around the %^RESET%^%^ORANGE%^"+
      "cavern%^BOLD%^%^BLUE%^, standing %^RESET%^coffins %^BOLD%^"+
      "%^BLUE%^fitted with exquisitely carved lids are lined up in "+
      "rigid rows.  The %^RESET%^%^CYAN%^air %^BOLD%^%^BLUE%^here "+
      "is %^RESET%^%^CYAN%^cooler %^BOLD%^%^BLUE%^than in the "+
      "%^RESET%^%^ORANGE%^passageways%^BOLD%^%^BLUE%^, and the "+
      "ever-present %^RESET%^breeze %^BOLD%^%^BLUE%^seems fitful.\n");
   set_items(([
      ({"chamber","passageway","passageways","hallways","hallway"}) : "This "+
         "large chamber opens off of the winding passageways deep beneath "+
         "the mountain.  This seems to be a large burial chamber where "+
         "many different firbolgs have been laid to rest.  Those in the "+
         "alcoves are likely not as important as the ones in the standing "+
         "coffins in the center of the room.",
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
         "any of the torches.",
      ({"dome","ceiling","ceilings","onion dome","domes"}) : "The ceiling "+
         "high overhead is well-illuminated by the numerous rows of "+
         "torches climbing the walls here.  The ceiling is carved to give "+
         "the illusion of windows, but the cold dark stone in the 'windows' "+
         "only serves to remind you that you are far underground with no "+
         "ready way out.",
      ({"coffin","standing coffin","coffins","standing coffins"}) : "The "+
         "coffins standing in the center of the room are arranged in five "+
         "long rows.  Each coffin is unique, carved with the likeness of "+
         "the one laid to rest inside.  All of the coffins have "+
         "inscriptions as well, but they seem to have faded beyond "+
         "understanding.",
      ({"alcove","alcoves"}) : "Each recessed alcove looks identical to "+
         "all the others.  They have carved archways with onion-shaped "+
         "tops, and each has a shelf within supporting the remains of "+
         "firbolgs laid to peaceful rest over the years.  Strangely, "+
         "some now seem empty or disturbed.",
   ]));
   set_listen("default","Your footsteps echo loudly down the deserted "+
      "corridor.");
   set_smell("default","The cool breath of a tomb is the only smell "+
      "in the air.");
   set_search("default",(:TO,"search_here":));
   set_search("alcoves",(:TO,"search_alcoves":));
   set_search("alcove",(:TO,"search_alcoves":));
   set_search("coffin","Some of the lids look loose.  You might "+
      "be able to lift one.");
   set_search("coffins","Some of the lids look loose.  You might "+
      "be able to lift one.");
searched = 0;
open = 0;
}

void init(){
   ::init();
   add_action("lift_em","lift");
}

int search_here(){
   if(!random(2)){
      tell_object(TP,"The alcoves seem to catch your attention.");
   }else{
      tell_object(TP,"Some of the coffins look to have loose "+
                  "lids.");
   }
   tell_room(ETP,""+TPQCN+" searches around the room.",TP);
   return 1;
}

int search_alcoves(){
   if(present("firbolg warrior")){
     tell_object(TP,"The firbolg warrior will not let you "+
       "desecrate more coffins!");
     return 1;
   }
   if(!searched){
      switch(random(10)){
         case 0..3:  tell_object(TP,"You search the alcoves and find "+
                        "something inside.");
                     tell_room(ETP,""+TPQCN+" pulls something out of "+
                        "an alcove.",TP);
                     "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"component",random(8)+3);
                     break;
         case 4:  tell_object(TP,"%^ORANGE%^You search the alcove "+
                        "and pull out an aged length of parchment.");
                     tell_room(ETP,"%^ORANGE%^"+TPQCN+" pulls an aged "+
                        "parchment from the alcove.",TP);
                     "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"highscroll");
                     break;
         case 5..6:  tell_object(TP,"%^RED%^You disturb a firbolg at rest "+
                     "as you search the alcove!");
                  tell_room(ETP,"%^RED%^"+TPQCN+" searches the alcove "+
                     "and seems to disturb something!",TP);
                  tell_room(ETP,"%^BOLD%^%^RED%^A firbolg skeleton "+
                     "rises from the alcove!");
                  new(MON"firbolgskeleton")->move(TO);
                  break;
         case 7..9:  tell_object(TP,"You find only spider webs and dust "+
                     "among the bones.");
                  tell_room(ETP,""+TPQCN+" searches the alcove and "+
                     "comes out covered in spider webs and dust.",TP);
                  break;
         default: break;
      }
      searched = 1;
      return 1;
   }
   tell_object(TP,"You find only spider webs and dust "+
      "among the bones.");
   tell_room(ETP,""+TPQCN+" searches the alcove and "+
      "comes out covered in spider webs and dust.",TP);
   return 1;
}

int lift_em(string str){
available = random(3)+1;
   if(!str){
      tell_object(TP,"What are you trying to lift?  Try the lid.");
      return 1;
   }
   if(str == "lid" || str == "lids"){
      if(open < available){
         if(present("firbolg warrior")){
            tell_object(TP,"The firbolg warrior will not let you "+
               "desecrate more coffins!");
            return 1;
         }
         if((int)TP->query_stats("strength") > random(22)){
            tell_object(TP,"%^GREEN%^You strain and lift with all "+
               "your might, finally moving the stone lid aside.");
            tell_room(ETP,"%^GREEN%^"+TPQCN+" strains, finally "+
               "moving the lid aside.",TP);
            switch(random(7)){
               case 0..2:  tell_room(ETP,"%^BOLD%^A firbolg "+
                              "warrior rises from the coffin!");
                           new(MON"firbolgwarrior")->move(TO);
                           break;
               case 3:  tell_object(TP,"You find a nice trinket "+
                           "within the coffin.");
                        new(OBJ"health_amulet")->move(TO);
                        break;
               case 4:  tell_object(TP,"You find a gleaming torc "+ 
                           "within the coffin.");
                        new(OBJ"torc")->move(TO);
                        break;
               case 5..6:  tell_object(TP,"You find a nice trinket "+ 
                           "within the coffin.");
                        new("/d/antioch/antioch2/obj/r_necklace")->move(TO); 
                        break;
            }
         open++;
         return 1;
         }
         tell_object(TP,"You strain and pull, but you cannot lift the lid!");
         tell_room(ETP,""+TPQCN+" strains but cannot lift the lid!",TP);
         return 1;
      }
      tell_object(TP,"None of the remaining coffins look like "+
         "they can be opened.");
      return 1;
   }
   tell_object(TP,"What are you trying to lift?  Try the lid.");
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
      open = 0;
   }
   if(!random(8)){
      searched = 0;
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
