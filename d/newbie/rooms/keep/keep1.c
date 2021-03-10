#include <std.h>
#include "/d/common/common.h"
#include "../inherit/keep.h"
inherit INH+"keephall2";

int FLAG;

void create(){ 
   ::create();
   set_name("Dead end of a ruined keep");
   set_short("%^CYAN%^Dead end of a ruined keep%^RESET%^");
   set_long("%^CYAN%^Dead end of a ruined keep%^RESET%^\n"
"This dead end is a few steps away from the crumbled entrance to the keep.  The "
"%^BLUE%^walls %^RESET%^seem in fairly poor shape here, with holes and cracks "
"that let the weather in.  Some bricks are missing, and the ceiling looks a "
"little unsteady.  Patches of %^GREEN%^moss %^RESET%^have crept over the walls "
"and floor, making travel treacherous in some places.  The %^ORANGE%^floor "
"%^RESET%^is covered in dust and dirt, and in the corner lies what appears to "
"be a %^BOLD%^%^WHITE%^nest %^RESET%^of some kind.\n");
   set_exits(([
     "east" : ROOMS"keep2",
   ]));
   add_item("nest",(:TO,"nest_desc":));
   set_search("default","There doesn't seem to be much of interest here except "
"the %^BOLD%^%^WHITE%^nest%^RESET%^.");
   set_search("nest",(:TO,"search_em":));
   FLAG = 0;
}

string nest_desc() {
   if(FLAG) return("%^BOLD%^%^WHITE%^The remains of a nest are here, though "
"something seems to have searched through them recently.  The bundle of straw, "
"debris and other discarded rubbish has been strewn about the area.%^RESET%^");
   else return("%^BOLD%^%^WHITE%^A bulky pile of straw, debris and other "
"unnameable substances has been built up in a corner of this room.  You're not "
"sure what might lie within it, but if you dared you might %^YELLOW%^search "
"%^WHITE%^it.%^RESET%^");
}

int search_em() {
   if(present("rat")) {
     tell_object(TP,"%^YELLOW%^There is a rat in the way!%^RESET%^");
     return 1;
   }
   if(FLAG) {
     tell_object(TP,"%^YELLOW%^It looks as though someone has already searched "
"through the nest, and taken anything of interest.%^RESET%^");
     tell_room(ETP,"%^YELLOW%^"+TPQCN+" searches around but doesn't find "
"anything.%^RESET%^",TP);
     return 1;
   }
   tell_object(TP,"%^YELLOW%^As you start to poke around at the nest, you "
"disturb its inhabitants.  Several rats leap out at you!");
   tell_room(ETP,"%^YELLOW%^"+TPQCN+" moves to search the nest, and disturbs "
"several rats.",TP);
   tell_room(ETP,"%^BOLD%^%^CYAN%^Luckily there also seems to be something "
"useful among the remains of the nest.");
   new(MONS"rat")->move(TO);
   new(MONS"rat")->move(TO);
   new(MONS"rat")->move(TO);
   if(random(2)) RANDSTUFF->find_stuff(TO, "food");
   else RANDSTUFF->find_stuff(TO, "drink");
   FLAG = 1;
   return 1;
}

void reset() {
   ::reset();
   FLAG = 0;
}
