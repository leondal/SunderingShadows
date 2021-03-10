#include <std.h>
#include "../inherit/keep.h"
inherit CVAULT;

int FOUND;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_name("Bedroom in a ruined keep");
   set_short("%^CYAN%^Bedroom in a ruined keep%^RESET%^");
   set_long("%^CYAN%^Bedroom in a ruined keep%^RESET%^\n"
"You suspect this large room was once a bedroom.  The %^BLUE%^walls "
"%^RESET%^are crumbling, full of holes and cracks that let in the weather, "
"and on the south side of the room the roof has fallen in entirely.  The "
"remains of several small %^MAGENTA%^beds %^RESET%^lie broken upon the "
"floor, with tattered sheets strewn about.  What might once have been "
"%^RED%^furniture %^RESET%^are now simply piles of wooden splinters upon "
"the ground, rotted from age.  Mud and dirt are streaked all around, while "
"overgrown tendrils from the %^GREEN%^garden %^RESET%^beyond creep slowly "
"into the building.\n");
   set_smell("default","The smell of fresh air reaches you in this half-open room.");
   set_listen("default","You can hear the trill of birds from the forest beyond.");
   set_items(([
     ({"walls","holes","cracks","roof"}) : "%^BLUE%^The stone walls that "
"border the room are in poor shape, filled with holes and cracks.  There "
"might once have been a door leading to the enclosed %^GREEN%^garden "
"%^BLUE%^to the south, but the entire roof has fallen in on that part of "
"the room, leaving it open to the air.%^RESET%^",
     ({"floor","dust","dirt","mud"}) : "%^ORANGE%^The floor is made of "
"stone bricks and is streaked in several places by mud and grime.  The remnants of shattered furniture lie strewn about.",
     ({"beds","sheets"}) : ((:TO,"beds_desc":)),
     ({"furniture","splinters"}) : "%^ORANGE%^The splintered remains of "
"broken furniture lie scattered along the floor, most decayed with age and "
"weather.%^RESET%^",
     "garden" : "%^GREEN%^Vibrant tendrils from the garden to the south "
"creep in through the ruined half of the room, slowly but surely "
"encroaching upon the building.%^RESET%^",
   ]));
   set_exits(([
     "east" : ROOMS"keep9",
     "south" : ROOMS"halfogre2",
   ]));
   set_door("door",ROOMS"keep9","east",0);
   set_door_description("door","%^ORANGE%^This door is aged and loose on "
"its hinges.  It has what may once have been carved patterns on it, but "
"these are long worn away and impossible to make out.%^RESET%^");
}

void init() {
   ::init();
   add_action("search_fun","search");
}

void reset() {
   ::reset();
   FOUND = 0;
}

int search_fun(string str) {
   object ob;
   if(!str) {
     tell_object(TP,"%^ORANGE%^You take a careful look around the room.  "
"The damage to the room doesn't leave a lot of interest to search through, "
"but perhaps there could be something in amongst the damaged "
"%^MAGENTA%^beds%^ORANGE%^.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" takes a look around the room"
".%^RESET%^",TP);
     return 1;
   }
   if(FOUND) {
     tell_object(TP,"%^ORANGE%^It looks as though someone has searched "
"through the remains recently, and taken anything of interest.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches around but doesn't find "
"anything.%^RESET%^",TP);
     return 1;
   }
   if(str == "sheets" || str == "beds") {
     tell_object(TP,"%^ORANGE%^Most of the scraps of cloth are tattered and "
"stained beyond any value.  But you do find something of worth amongst "
"them.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" searches around and seems to find "
"something.%^RESET%^",TP);
     switch(random(7)) {
       case 0: ob = new(CLOTHING"c_hat"); break;
       case 1: ob = new(CLOTHING"c_tunic"); break;
       case 2: ob = new(CLOTHING"c_dress"); break;
       case 3: ob = new(CLOTHING"c_leggings"); break;
       case 4: ob = new(CLOTHING"c_shirt"); break;
       case 5: ob = new(CLOTHING"c_gloves"); break;
       case 6: ob = new(CLOTHING"c_skirt"); break;
     }
     ob->move(TO);
     ob->set_size(1);
     FOUND = 1;
     return 1;
   }
   return 0;
}

string beds_desc() {
   if(FOUND) return("%^MAGENTA%^Several small beds have been destroyed by "
"age or violence, their remains lying on the floor amidst scraps of sheets "
"and clothing.  Judging by their size, they likely belonged to children.  "
"It seems they have recently been rummaged through by something.%^RESET%^");
   else return("%^MAGENTA%^Several small beds have been destroyed by age or "
"violence, their remains lying on the floor amidst scraps of sheets and "
"clothing.  Judging by their size, they likely belonged to children.  Most "
"look ruined beyond value, but perhaps you could %^YELLOW%^search %^RESET%^"
"%^MAGENTA%^to see if there is anything left of value.%^RESET%^");
}
