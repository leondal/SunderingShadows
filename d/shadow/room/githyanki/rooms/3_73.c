#include <std.h>
#include "../githyanki.h"

inherit STORAGE"3floor.c";



void create(){
    ::create();
    set_long(::query_long()+"%^RESET%^%^RED%^%^RESET%^%^BOLD%^%^BLACK%^"+
"In the centre of the room stands a giant iron throne at least ten feet "+
"tall. At its base are %^RESET%^%^WHITE%^piles of skulls%^RESET%^%^BOLD%^"+
"%^BLACK%^, some you recognize as humanoid, others strange and bulbous. "+
"There are even a few small dragon skulls.%^RESET%^\n\n");
    set_exits(([
      "south" : ROOMS"3_71",
    ]));
    add_item("throne","%^RESET%^%^BOLD%^%^BLACK%^Formed out of solid iron,"+
" this throne stands over ten feet tall. The back of the throne is carved "+
"with a depiction of Tiamat and an impressively large githyanki. The armrests"+
" are carved in the shape of dragon paws and each claw is a different precious"+
" gem, showing the five colours of chromatic dragons. %^RESET%^");
    add_item("skulls","%^RESET%^%^WHITE%^sitting at the base of the throne "+
"are a pile of %^RESET%^%^BOLD%^%^WHITE%^bones%^RESET%^%^WHITE%^. Most of "+
"them are alien to you, but you can pick out some %^RESET%^%^BOLD%^%^WHITE%^"+
"humanoid skulls%^RESET%^%^WHITE%^, and even what looks like %^RESET%^%^BOLD%^"+
"%^BLACK%^small dragon skulls%^RESET%^%^WHITE%^. They all have been semi melted"+
" into one mass, so it would be impossible to take one without lifting the "+
"entire thing.%^RESET%^");

}

void reset(){
   ::reset();
   if(!present("githyanki"))
      new(MOBS"gith_command.c")->move(TO);
}

