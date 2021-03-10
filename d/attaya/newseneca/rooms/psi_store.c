//~Circe~ 12/2/07 for new Seneca

#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Sublime Psicrystals of the Spire of Serenity, Seneca");
   set_short("%^BOLD%^%^WHITE%^Sublime Psicrystals of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Sublime Psicrystals of the %^RESET%^%^ORANGE%^"+
      "S%^RED%^p%^ORANGE%^i%^RED%^r%^ORANGE%^e %^RED%^o%^ORANGE%^f "+
      "%^RESET%^%^RED%^S%^ORANGE%^e%^RED%^r%^ORANGE%^e%^RED%^n"+
      "%^ORANGE%^i%^RED%^t%^ORANGE%^y%^BOLD%^%^WHITE%^, Seneca%^RESET%^\n"+
      "At first glance, it is difficult to tell that this round "+
      "room is a shop.  Arranged as a cozy %^MAGENTA%^tea parlor"+
      "%^RESET%^, the room is filled with %^GREEN%^potted plants "+
      "%^RESET%^that line the %^ORANGE%^curved walls%^RESET%^.  "+
      "%^BOLD%^Woven tapestries %^RESET%^are hung between the "+
      "%^RED%^arched windows%^RESET%^, all depicting scenes of "+
      "%^GREEN%^nature%^RESET%^.  A round hooked and braided "+
      "rug in %^GREEN%^s%^MAGENTA%^h%^CYAN%^a%^GREEN%^d%^MAGENTA%^"+
      "e%^CYAN%^s %^RESET%^of %^GREEN%^green%^RESET%^, %^MAGENTA%^"+
      "purple%^RESET%^, and %^CYAN%^blue%^RESET%^ is centered "+
      "on the floor and surrounded by three overstuffed %^BOLD%^"+
      "%^MAGENTA%^armchairs%^RESET%^.  A small %^ORANGE%^end table "+
      "%^RESET%^to the left of the largest chair holds a %^BOLD%^silver "+
      "stand %^RESET%^displaying %^BOLD%^%^CYAN%^psicrystals "+
      "%^RESET%^on silken strands.  A round %^ORANGE%^wooden tea "+
      "stand %^RESET%^holding a %^BOLD%^silver tea service "+
      "%^RESET%^stands ready at the right hand of the same chair.  "+
      "A discreet %^BOLD%^%^BLACK%^chest %^RESET%^rests near the wall, "+
      "likely the place where money is stored.\n");
   set_smell("default","The clean scent of the ocean mingles with a light fragrance of ozone.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"plant","plants","potted plants"}) : "%^ORANGE%^Wicker "+
         "baskets %^RESET%^surround the ceramic pots lining the "+
         "wall, giving them a more appealing appearance.  Growing "+
         "inside are lush, healthy %^GREEN%^plants%^RESET%^ of "+
         "many types.  A few show flowers, but most seem to have "+
         "been chosen for their simple greenery.",
      ({"tapestries","woven tapestries"}) : "The tapestries are "+
         "expertly woven on a base of %^BOLD%^white%^RESET%^.  "+
         "Each depicts a quiet scene from nature, though none "+
         "seem to be from Attaya.  You see snowcapped mountains "+
         "with a prowling winter wolf off to the side, a tall "+
         "cedar forest with an owl slumbering in the branches, "+
         "and shimmering golden grasslands with the eyes of a "+
         "prowling lynx peeking from the stalks.",
      ({"window","windows","archways","archway"}) : "The archways "+
         "have been edged with %^RED%^red stone%^RESET%^.  They are "+
         "narrow rectangles with onion-shaped tops, and they have "+
         "been fitted with thin transparent %^CYAN%^glass%^RESET%^.",
      "rug" : "The rug is perfectly round and soft, featuring "+
         "thickly woven fabric in %^GREEN%^s%^MAGENTA%^h%^CYAN%^"+
         "a%^GREEN%^d%^MAGENTA%^e%^CYAN%^s %^RESET%^of %^GREEN%^"+
         "green%^RESET%^, %^MAGENTA%^purple%^RESET%^, and "+
         "%^CYAN%^blue%^RESET%^.  The colors spiral inward, "+
         "with the central portion solid %^CYAN%^blue%^RESET%^.",
      ({"chair","armchair","armchairs"}) : "%^BOLD%^%^MAGENTA%^"+
         "Each of the armchairs is a light shade of purple "+
         "and has a tall back with padded arms.  Woven into the "+
         "fabric are tiny %^RESET%^%^MAGENTA%^purple flowers "+
         "%^BOLD%^%^MAGENTA%^to give added decoration.  The "+
         "chair to the west seems slightly larger and more worn "+
         "than the others, and it is here that Adelaide is often "+
         "perched.%^RESET%^",
      ({"end table","stand","silver stand","psicrystals"}) : "The "+
         "end table is crafted of %^ORANGE%^oak %^RESET%^and rises "+
         "from a single pedestal.  A %^BOLD%^round doily %^RESET%^"+
         "is centered on it, with a %^BOLD%^silver stand%^RESET%^ "+
         "atop it supporting psicrystals hanging from silken strands.",
      ({"tea stand","wooden tea stand","silver service","tea service","silver tea service"}) : 
         "The wooden tea stand looks much like the end table, though "+
         "it is somewhat taller.  It has a single drawer in its "+
         "front, likely a place to store sugar cubes and various "+
         "utensils needed for use with serving tea.  Standing "+
         "atop it is a beautiful %^BOLD%^silver tea service "+
         "%^RESET%^with an oval tray, coffee pot, teapot, cream "+
         "jug, sugar bowl, and a collection of cups.",
      "chest" : "The chest near the western wall is hard to see "+
         "at first.  It is nestled among the potted plants and "+
         "has a simple iron lock."
   ]));
   set_exits(([
      "east" : ROOMS"psi_landing3"
   ]));
}

void reset(){
   ::reset();
   if(!present("adelaide"))
      find_object_or_load(MON"adelaide")->move(TO);
}