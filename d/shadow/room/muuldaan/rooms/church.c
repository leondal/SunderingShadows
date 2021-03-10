#include <std.h>
#include "../defs.h"
inherit "/std/church";

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_name("A dark cavern");
   set_short("A dark cavern");
   set_smell("default","The biting scent of something burning fills the area with a dreadful smell.");
   set_listen("default","A constant stream of chatter, screeching, grumbling and general rabble surrounds you.");
   set_long("%^BOLD%^A lopsided little shanty%^RESET%^\n"
"This little roughly-made building is barely standing, supported on two sides by the cavern walls.  Various "
"%^RED%^skins%^RESET%^ and planks of %^ORANGE%^wood%^RESET%^ form the roof and the remaining walls.  The "
"floor is of the same stone as the rest of the cavern, cold and hard underfoot.  At the far end of the "
"shanty is a %^BLACK%^%^BOLD%^large boulder %^RESET%^that probably serves as an altar of sorts.  Upon it are "
"all sorts of trinkets, %^WHITE%^%^BOLD%^skulls%^RESET%^, and little bowls containing something burning, "
"that fills the area with a rather dreadful smell.  A flap of hide is pinned back, allowing passage to the "
"cavern outside, and a messily scrawled sign is tacked to the opposite wall.\n");

   set_items(([
     ({"cave","cavern","ground"}):"The cavern walls and floor are formed of dull stone, still jagged in many "
"places and probably not shaped by mortal hands.  The floor is cold and hard beneath your feet.",
     ({"skins","hides","roof","wood","planks"}):"Rough skins and planks of wood form the roof and remaining "
"walls of this little shanty.  One flap of hide has been pinned back, allowing entrance to the enclosed "
"room.",
     "walls":"The two rear walls of the room are part of the cavern walls, and the rest are made of various "
"wooden planks and strips of hide, secured together to form this rough shanty.",
     ({"altar","boulder","stone"}):"At the end of the little room is a large boulder, scattered with various "
"trinkets, bones and bowls.  It probably serves as a makeshift altar for the beasts that come here.",
     ({"trinkets","bones","skulls","bowls"}):"Scattered across the makeshift altar are various trinkets, "
"bones and skulls, as well as several bowls containing something burning.  They smell quite awful.",
     "sign":"A messy sign has been tacked to the wall.  You should read it.",
   ]));
   set_exits(([
     "southeast":ROOMS"cavern4",
   ]));
}

void reset(){
   ::reset();
   if(!present("dhac"))
   find_object_or_load(MON"dhac")->move(TO);

   switch(random(10)) {
     case 0..1:
     tell_room(TO,"%^ORANGE%^The walls of the shanty shift slightly, and a precarious creak comes from "
"them.%^RESET%^");
     break;
     case 2:
     tell_room(TO,"%^RED%^Dhac cackles to herself as she fiddles with the severed hand tied around her "
"neck.%^RESET%^");
     break;
     case 3..4:
     tell_room(TO,"%^BLACK%^%^BOLD%^Dhac waves her arms around wildly and circles the altar, chanting in "
"some sort of gibberish.%^RESET%^");
     break;
     case 5:
     tell_room(TO,"%^CYAN%^A wafting scent reaches your nose from the burning substances in the bowls, "
"making your stomach lurch.%^RESET%^");
     break;
     case 6..7:
     tell_room(TO,"%^BLUE%^Dhac screeches a prayer to the gods and dances around, the tattered robes "
"flapping around her scrawny form.%^RESET%^");
     break;
     case 8..9:
     tell_room(TO,"%^YELLOW%^Dhac gives a wicked grin, showing her many sharp yellow teeth.%^RESET%^");
     break;
   }
}
