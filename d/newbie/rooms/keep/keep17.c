#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall2";

void create(){
   ::create();
   set_repop(60);
   set_long(::query_long() +"  West of here appears to be the remains of a "
"%^CYAN%^kitchen%^RESET%^, though you can see even from this distance that it "
"is in a terrible state.  The hallway leads off to the south.\n");
   set_exits(([
     "west" : ROOMS"keep16",
     "south" : ROOMS"keep18",
   ]));
   add_item("kitchen","%^CYAN%^The remains of a kitchen lies a few paces west "
"of here.  You can see even from this distance, that someone or something has "
"made a horrible mess of the place.");
}

void reset() {
   int active;
   active = has_mobs();
   if(!active) {
      if(mons) mons = ([]);
      set_monsters(({MONS"xvart"}),({random(2)+1}));
   }
   ::reset();
}
