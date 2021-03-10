//~Circe~ 1/9/08 for new Seneca
//"Safe" duelling area for the mage guild
//Players here can summon target dummies and battle one 
//another, though death is possible, and they need to 
//submit to each other to avoid alignment hits.  This is 
//really more for roleplay than any sense of a working arena

#include <std.h>
#include <move.h>
#include "../seneca.h"

#define SCRY_D "/daemon/ic_scry_locate_d"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Training Hall of the Esoteric Haven, Seneca");
   set_short("%^BOLD%^%^WHITE%^Training Hall of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Training Hall of the %^BLACK%^E%^CYAN%^s"+
      "%^BLACK%^o%^CYAN%^t%^BLACK%^e%^CYAN%^r%^BLACK%^i%^CYAN%^c "+
      "%^BLACK%^H%^CYAN%^a%^BLACK%^v%^CYAN%^e%^BLACK%^n%^WHITE%^"+
      ", Seneca%^RESET%^\n"+
      "%^BOLD%^%^BLACK%^This huge chamber features a domed ceiling "+
      "rising high overhead, and the sheer size reveals that the "+
      "hall must be magically enhanced.  The floor, walls, ceiling"+
      ", and the inner side of the doors have been lined with a "+
      "layer of %^RESET%^lead %^BOLD%^%^BLACK%^topped by a thick "+
      "coating of %^BLUE%^void steel%^BLACK%^.  The central "+
      "portion of the room has a sunken floor much like a reverse "+
      "dais that is protected by a shimmering %^CYAN%^magical "+
      "dome%^BLACK%^.  Four %^BLUE%^void steel pillars %^BLACK%^"+
      "intricately carved with a decorative design are stationed "+
      "around the recess, seeming to have some connection to the "+
      "%^CYAN%^glowing dome%^BLACK%^.  The floor within the "+
      "pillars has four slender steps leading downward onto "+
      "an exquisite carving of a multitude of %^WHITE%^m%^BLACK%^"+
      "a%^CYAN%^g%^BLACK%^i%^WHITE%^c%^CYAN%^a%^WHITE%^l %^BLACK%^"+
      "s%^CYAN%^y%^BLACK%^m%^WHITE%^b%^CYAN%^o%^WHITE%^l%^BLACK%^s "+
      "that shift and glow with their own %^WHITE%^light%^BLACK%^.  "+
      "Just to the right of the %^RESET%^double doors %^BOLD%^"+
      "%^BLACK%^is a smaller %^BLUE%^pillar %^BLACK%^that has a "+
      "single %^YELLOW%^golden circle %^BLACK%^carved upon its "+
      "slanted top.%^RESET%^\n\n"+
      "%^BOLD%^%^CYAN%^<help here> will give you information on "+
      "what you may do here%^RESET%^\n");
   set_smell("default","The crystal clean fragrance of water and "+
      "a light fragrance of sweat lingers here.");
   set_listen("default","The protective measures of this room "+
      "ensure complete silence except the sounds of combat practice.");
   set_items(([
      ({"walls","wall","stone walls","gray stone walls","floor"}) : "%^BOLD%^"+
         "%^BLACK%^The walls here are rounded and likely made of "+
         "the same black stone as the rest of the tower.  They "+
         "have been covered, however, with a layer of %^RESET%^"+
         "lead%^BOLD%^%^BLACK%^ and then topped with a coating of "+
         "%^BLUE%^void steel%^BLACK%^ to make them impervious "+
         "to magical attacks.  The floor has been treated in a "+
         "similar manner, and it is unbroken save for the "+
         "reverse dais in the center of the room.%^RESET%^",
      "ceiling" : "The ceiling rises in a dome high overhead, "+
         "nearly disappearing from sight.",
      ({"lead","layer of lead","lead layer"}) : "Visible only "+
         "around certain edges, the layer of lead offers "+
         "protection against the types of magic used here "+
         "escaping this protected area.",
      ({"void steel","layer of void steel","void steel coating"}) :
         "%^BOLD%^%^BLUE%^The layer of void steel that covers "+
         "every surface in the room is so deeply black as to "+
         "have an almost bluish appearance.  It is matte and seems "+
         "to absorb light rather than reflect it.  It is smooth "+
         "and somewhat spongy to the touch, though it doesn't "+
         "give at all.%^RESET%^",
      ({"sunken floor","dais","reverse dais","stairs"}) : "%^BOLD%^"+
         "%^BLACK%^The center of the floor is taken up by the "+
         "four slender steps that curve flawlessly, leading down "+
         "into a depression, much like a dais in reverse.  A "+
         "mystical %^CYAN%^carving %^BLACK%^lies in the center of "+
         "the floor, giving off a soft glow, and the entire area "+
         "is covered by a magical dome.%^RESET%^",
      ({"dome","magic dome","magical dome"}) : "%^BOLD%^%^CYAN%^"+
         "A transluscent %^WHITE%^dome%^CYAN%^ that shimmers with "+
         "coruscating %^RED%^c%^YELLOW%^o%^BLUE%^l%^GREEN%^o"+
         "%^MAGENTA%^r%^CYAN%^s protects the reverse dais in "+
         "the middle of the room.  It looks as though you might "+
         "%^WHITE%^<%^BLACK%^enter%^WHITE%^> %^CYAN%^the dome "+
         "to duel with someone else in a "+
         "protective environment.%^RESET%^",
      ({"symbols","magic symbols","magical symbols","carving","magical carving"}) :
         "The intricate carving of %^BOLD%^%^WHITE%^m%^BLACK%^"+
         "a%^CYAN%^g%^BLACK%^i%^WHITE%^c%^CYAN%^a%^WHITE%^l %^BLACK%^"+
         "s%^CYAN%^y%^BLACK%^m%^WHITE%^b%^CYAN%^o%^WHITE%^l%^BLACK%^s "+
         "%^RESET%^in the center of the room is dizzying to study.  "+
         "Runes of all different types have been arranged in a "+
         "complicated web design, all intended to help generate "+
         "the dome that hovers protectively in the room's center.",
      ({"pillars","void steel pillars"}) : "The pillars surrounding "+
         "the sunken dais are cylindrical and covered with designs "+
         "that echo those in the carving on the floor, hinting at "+
         "their connection with the dome.",
      ({"pillar","small pillar","circle","golden circle"}) : "Near "+
         "the doorway is a miniature version of the four huge "+
         "pillars.  This one has a slanted top just at the height "+
         "of a human's waist.  It is carved with a single %^YELLOW%^"+
         "golden circle%^RESET%^ that may be traced to %^YELLOW%^"+
         "<%^WHITE%^retrieve%^YELLOW%^> %^RESET%^a dummy upon "+
         "which to practice."
   ]));
   set_exits(([
      "west" : ROOMS"mage_landing6"
   ]));
   set_door("double doors","/d/attaya/newseneca/rooms/mage_landing6","west",0,0);
   set_door_description("double doors","The double doors to the west "+
      "join to form one single, pointed arch.  They look quite "+
      "featureless from this side, having been covered with a "+
      "layer of %^BOLD%^%^BLACK%^lead %^RESET%^topped by "+
      "%^BOLD%^%^BLUE%^void steel%^RESET%^.");
}

void reset(){
   ::reset();
   if(!present("dome")) new(OBJ"dome")->move(TO);
}

void init(){
   ::init();
   add_action("retrieve_em","retrieve");
   add_action("retrieve_em","trace");
   add_action("return_em","return");
   add_action("enter_em","enter");
}

int retrieve_em(string str){
   if(!str) return 0;
   if(str == "dummy" || str == "testdummy" || str == "test dummy" || str == "practice dummy" || str == "rune"){
      if(present("testdummy")){
         tell_object(TP,"There is already a testdummy present!");
         return 1;
      }
      tell_object(TP,"You trace the rune upon the short pillar, "+
         "and a practice dummy shimmers into being.");
      tell_room(TO,""+TPQCN+" traces the rune upon the short "+
         "pillar, and a practice dummy shimmers into being.",TP);
      new(MON"testdummy")->move(TO);
      return 1;
   }
   return 0;
}

int return_em(string str){
   if(!str) return 0;
   if(str == "dummy" || str == "testdummy" || str == "test dummy" || str == "practice dummy"){
      if(!present("test dummy")){
         tell_object(TP,"There is no practice dummy to return!");
         return 1;
      }
      tell_object(TP,"You touch the rune in the dummy's chest, "+
         "and it fades out of existence.");
      tell_room(TO,""+TPQCN+" touches the rune on the dummy's "+
         "chest, and it fades out of existence.",TP);
      present("test dummy")->remove();
      return 1;
   }
   return 0;
}

int enter_em(string str){
   if(!str) return 0;
   if(str != "dome" && str != "the dome" && str != "dais") return 0;
   tell_object(TP,"%^BOLD%^%^BLACK%^You approach the "+
      "coruscating %^RED%^c%^YELLOW%^o%^BLUE%^l%^GREEN%^o"+
      "%^MAGENTA%^r%^CYAN%^s %^BLACK%^of the dome, feeling them "+
      "part with a crackle of %^YELLOW%^electricity %^BLACK%^"+
      "as you pass through easily.%^RESET%^");
   tell_object(TP,"%^BOLD%^%^RED%^The dome is a roleplay tool only"+
      ", meant to simulate an anti-magic dome through which the "+
      "magic used cannot escape.  "+
      "Deaths CAN happen here, so be careful.  To avoid alignment "+
      "hits, all parties involved must %^WHITE%^<%^CYAN%^submit"+
      "%^WHITE%^> %^RED%^to each other.%^RESET%^");
   tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+"%^BOLD%^%^BLACK%^ approaches the "+
      "coruscating %^RED%^c%^YELLOW%^o%^BLUE%^l%^GREEN%^o"+
      "%^MAGENTA%^r%^CYAN%^s %^BLACK%^of the dome, and the dome "+
      "parts with a crackle of %^YELLOW%^electricity %^BLACK%^"+
      "as "+TP->QS+"%^BOLD%^%^BLACK%^ passes through easily.%^RESET%^",TP);
   tell_room(find_object_or_load("/d/attaya/newseneca/rooms/mage_combat2.c"),"%^BOLD%^"+
      "%^BLACK%^The shimmering dome parts briefly, and "+
      ""+TPQCN+" walks through.%^RESET%^",TP);
      TP->move_player("/d/attaya/newseneca/rooms/mage_combat2");
   return 1;
}