//clothing2.c - clothing store for new Seneca
//sells uniforms that only authorized jailers
//can buy.  ~Circe~ 11/24/07
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(2);
   set_name("The Eagle's Feathers, Seneca");
   set_short("The Eagle's Feathers, Seneca");
   set_long("%^BOLD%^The Eagle's Feathers, Seneca%^RESET%^\n"+
      "Named for the symbol of %^BOLD%^%^BLUE%^Seneca's Guard"+
      "%^RESET%^, this small shop primarily sells clothing to the "+
      "soldiers of Seneca.  The shop is spotless, with bolts of "+
      "cloth, mostly in %^RESET%^%^BLUE%^blues %^RESET%^and "+
      "%^RED%^reds%^RESET%^, folded neatly on %^ORANGE%^shelves"+
      "%^RESET%^.  A few tailor's %^BOLD%^forms %^RESET%^stand "+
      "near the western side of the room, and you see several "+
      "partially completed %^BOLD%^%^BLUE%^uniforms %^RESET%^"+
      "hanging from a %^BOLD%^rod %^RESET%^in the northwestern "+
      "corner - likely orders that Esteban is in the process of "+
      "finishing.  Near the front of the room in a %^CYAN%^glass "+
      "display case %^RESET%^is Esteban's own guard uniform, a "+
      "symbol of pride for him and the guard.  On the eastern side "+
      "of the room, %^ORANGE%^wooden racks %^RESET%^support "+
      "finished clothing of all types, mostly in comfortable "+
      "styles.\n");
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"bolts","cloth","reds","blues","shelves"}) : "%^ORANGE%^"+
         "Shelves on the northern wall hold folded bolts of fabric, "+
         "thread, and other materials necessary for tailoring.  "+
         "Most of the fabric seems to be of high quality, and many of "+
         "it is in the chosen colors of Seneca's Guard - %^BLUE%^"+
         "deep blue %^RESET%^%^ORANGE%^and %^BOLD%^%^RED%^bold red%^RESET%^"+
         "%^ORANGE%^.%^RESET%^",
      ({"forms","tailor's forms","tailor forms"}) : "The forms are "+
         "shaped like human torsos and are made of wood.  They are "+
         "meant to give Esteban a general idea of the shape of "+
         "the human figure to aid him in his creations.  You notice "+
         "that one or two seem to be shaped oddly - perhaps that one "+
         "is for a dwarf?  And that...an elf?",
      ({"uniforms","rod"}) : "The metal rod in the northwestern part "+
         "of the shop hold partially completed uniforms.  Most of these "+
         "have the major work finished and are lacking only a final "+
         "fitting for hems and the like.",
      ({"case","display case","glass display case","uniform"}) : "The "+
         "%^CYAN%^glass display case %^RESET%^in the front of the room "+
         "is tall and rectangular - it must have cost a fortune!  Inside, "+
         "Esteban has put his guard uniform on display - complete with "+
         "hat, gloves, and boots.  The uniform - like everything Esteban "+
         "touches - has been well-tended and seems to be in almost "+
         "the same condition as when he first got it over thirty years "+
         "ago.",
      ({"racks","wooden racks","clothing"}) : "The clothing in the eastern "+
         "part of the store seems to be available for anyone to purchase.  "+
         "Free-standing wooden racks have been arranged to allow for "+
         "walking room between them while displaying as many clothing "+
         "items as possible.  You see cloaks, pants, shirts, jackets - "+
         "pretty much anything you could want."
   ]));
   set_exits(([
      "south" : ROOMS"viento55"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/viento55","south",0,0);
   set_door_description("door","The door to the south is made of "+
      "%^ORANGE%^solid oak%^RESET%^ and is varnished to a high shine.");
}

void reset(){
   ::reset();
   if(!present("esteban")) {
      find_object_or_load(MON"esteban")->move(TO);
   }
}