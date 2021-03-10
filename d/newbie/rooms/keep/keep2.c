#include <std.h>
#include "../inherit/keep.h"
inherit INH+"keephall2";

void create(){ 
   ::create();
   set_long("%^CYAN%^Hallway of a ruined keep%^RESET%^\n"
"You are standing just inside the entrance of a ruined keep.  The %^BLUE%^walls "
"%^RESET%^seem in fairly poor shape here, with holes and cracks that let the "
"weather in.  Some bricks are missing, and the ceiling looks a little unsteady"
".  The %^ORANGE%^floor %^RESET%^is covered in dust and dirt, and streaks of "
"mud have been tracked across it.  Patches of %^GREEN%^moss %^RESET%^have crept "
"over the walls and floor, making travel treacherous in some places.  At one "
"point it seems a pair of sturdy %^RED%^doors %^RESET%^stood here, but they "
"have long since been shattered, leaving only their rotted remains lying upon "
"the ground.  Corridors lead in several directions deeper into the keep.  "
"The hallways are dark, but you're sure you could %^YELLOW%^peer %^RESET%^"
"at any point to see what lies ahead.\n");
   set_exits(([
     "north" : ROOMS"keep6",
     "west" : ROOMS"keep1",
     "east" : ROOMS"keep3",
     "south" : ROOMS"path4",
   ]));
   add_item("doors","%^RED%^It seems many years ago that a pair of vast doors "
"stood across the entry to the keep here.  However now only their rotted "
"remains are left, shattered and strewn across the ground.%^RESET%^");
   add_item("remains","%^RED%^It seems many years ago that a pair of vast doors "
"stood across the entry to the keep here.  However now only their rotted "
"remains are left, shattered and strewn across the ground.%^RESET%^");
}

void reset() {
   object ob;
   ::reset();
   if(!present("sign")) {
     ob = new(OBJ"misc/1sign.c");
     ob->set_file("/d/newbie/obj/misc/sign7.txt");
     ob->move(TO);
   }
}
