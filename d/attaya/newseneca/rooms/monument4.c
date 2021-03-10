//monument4.c ~Circe~ 12/10/07
#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("A Grand Monument, Seneca");
   set_short("A Grand Monument, Seneca");
   set_property("light",3);
   set_long("%^BOLD%^%^WHITE%^A Grand Monument, Seneca%^RESET%^\n"+
      "%^GREEN%^This square garden is carpeted with lush, soft "+
      "%^BOLD%^grass%^RESET%^%^GREEN%^ that surrounds the magnificent "+
      "centerpiece, a %^BOLD%^%^WHITE%^marble statue%^RESET%^%^GREEN%^ "+
      "of a studious elf.  Rising high overhead is a breathtaking "+
      "%^ORANGE%^sun trellis %^GREEN%^fitted with lattic and laced "+
      "throughout with %^MAGENTA%^fragrant flowers%^GREEN%^.  The "+
      "wooden theme of the trellis has been continued in simple "+
      "%^ORANGE%^wooden benches %^GREEN%^with no backs that have "+
      "been spaced at angles around the %^BOLD%^garden%^RESET%^"+
      "%^GREEN%^.  The corners of the garden are filled with the "+
      "wide %^ORANGE%^posts %^GREEN%^of the trellis, covered with "+
      "%^BOLD%^vines %^RESET%^%^GREEN%^and %^MAGENTA%^flowers "+
      "%^GREEN%^that swirl around them.  The %^CYAN%^wind %^GREEN%^"+
      "seems ever-present here, sending delicate %^MAGENTA%^"+
      "trumpet blossoms %^GREEN%^floating to the ground.  The "+
      "southern and western edges of the trellis have been edged "+
      "with %^ORANGE%^lattice %^GREEN%^covered in vines, helping "+
      "to make this garden a little piece of solitude in the middle "+
      "of the big city of %^BOLD%^%^WHITE%^Seneca%^RESET%^%^GREEN%^.%^RESET%^\n");
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"street","boulevard","cobblestone","cobblestones","thoroughfare"}) : 
         "The %^ORANGE%^co%^RED%^b%^ORANGE%^"+
         "ble%^RESET%^s%^ORANGE%^to%^RED%^n%^ORANGE%^e streets%^RESET%^ "+
         "to the north and east and the town square to the northeast "+
         "are created from stones in shades of "+
         "%^ORANGE%^brown%^RESET%^, %^RED%^red%^RESET%^, and "+
         "white arranged in zig-zagging patterns.",
      "grass" : "%^BOLD%^%^GREEN%^The grass here is soft and well-"+
         "groomed, quite unlike most of the beach grass growing "+
         "thoughout Seneca.  It is kept relatively short, and it "+
         "would likely be a great place for a picnic.%^RESET%^",
      ({"trellis","sun trellis","posts","columns"}) : "%^ORANGE%^The %^YELLOW%^sun "+
         "trellis %^RESET%^%^ORANGE%^is built upon four thick "+
         "square columns roofed with lattice that rises high "+
         "overhead, creating a unique sense of freedom and "+
         "cover at once.  %^MAGENTA%^Trumpet blossoms %^ORANGE%^"+
         "in countless %^BOLD%^%^RED%^c%^RESET%^%^ORANGE%^o%^YELLOW%^l%^WHITE%^o"+
         "%^MAGENTA%^r%^RESET%^%^MAGENTA%^s %^ORANGE%^climb the "+
         "trellis, dancing within the lattice openings and swirling "+
         "around the columns.%^RESET%^",
      ({"flower","flowers","vines","blossoms","trumpet blossoms"}) : 
         "%^GREEN%^The flowers grow from "+
         "vines much like ivy and are formed into trumpet "+
         "blossoms in a mixed variety of %^RED%^reds%^GREEN%^, "+
         "%^MAGENTA%^purples%^GREEN%^, %^BOLD%^%^MAGENTA%^pinks"+
         "%^RESET%^%^GREEN%^, %^YELLOW%^yellows%^RESET%^%^GREEN%^"+
         ", and countless shades in between.%^RESET%^",
      ({"bench","benches"}) : "%^ORANGE%^Each of the benches is "+
         "crafted from slats of wood placed closely together to "+
         "form a simple place to sit.  They are scattered about "+
         "the garden in a natural way, with no regard to symmetry.%^RESET%^",

   ]));
   set_exits(([
      "east" : ROOMS"skyline44",
      "north" : ROOMS"viento53",
      "northeast" : ROOMS"square"
   ]));
}

void reset(){
   ::reset();
   if(!present("street lamp")) new(OBJ"street_lamp")->move(TO);
   if(!present("leloran statue")) new(OBJ"leloran_statue")->move(TO);
}