#include <std.h>
#include "../defs.h"
inherit "/std/rquestroom.c";

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_name("A dark cavern");
   set_short("A dark cavern");
   set_smell("default","An odd aroma fills the air, that smells almost like something edible.  Almost.");
   set_listen("default","A constant stream of chatter, screeching, grumbling and general rabble surrounds you.");
   set_long("%^BOLD%^A partly enclosed hovel%^RESET%^\n"
"Various %^ORANGE%^wooden planks%^RESET%^, stacks of trash, dirty skins and old cloths have been stacked and "
"tied together to form this little hovel.  It looks like quite a precarious construction, but that doesn't "
"seem to bother the constant customers to the place.  There are no tables or chairs to be had, so most of "
"them are just wandering around, or sitting on either the %^BLUE%^floor %^RESET%^or the %^RED%^trash "
"%^RESET%^around.  Near the back of the room is a partitioned section, from whence you can hear hisses, "
"smashes, squishes and shrieks, and all the other sounds that probably make up a kobold's cooking.  Near the "
"front of the hovel, a rather large piece of %^ORANGE%^wood %^RESET%^has been affixed to the wall to serve "
"as a %^YELLOW%^menu%^RESET%^, painted with scratchy symbols and pictures of what might pass as food.  Off "
"to the side, across the entire western wall, are more runes scrawled by various hands, perhaps a "
"%^WHITE%^%^BOLD%^list %^RESET%^of sorts.\n");

   set_items(([
     ({"cave","cavern","ground"}):"The cavern walls and floor are formed of dull stone, still jagged in many "
"places and probably not shaped by mortal hands.  The floor is cold and hard beneath your feet.",
     ({"skins","hides","roof","wood","planks","walls"}):"Rough skins, old cloth, trash and planks of wood "
"form the roof and unsteady walls of this little hovel.  Near the front, a large piece of wood has been "
"affixed to the wall, to serve as a menu which you could probably try to read.",
     ({"piece of wood","menu"}):"A thick piece of wood has been stuck to the wall.  It is painted with "
"scratchy symbols and pictures of what might possibly be food.  You could probably try to read the menu.",
     "list":"Across the entire western wall are countless runes and symbols scrawled by different hands.  "
"They form a list of sorts, that you could probably try to %^YELLOW%^read%^RESET%^.",
   ]));
   set_exits(([
     "north":ROOMS"cavern10",
   ]));
   set_quest_daemon("/daemon/quests_low");
}

void init(){
   ::init();
   if(interactive(TP) && !random(10) && TP->query_level() < 10)
     write("The %^YELLOW%^list %^RESET%^scrawled across the west wall draws your attention.");
   add_action("read", "read");
}

int read(string str) {
   object ob;
   int i;

   if(str!="menu") return notify_fail("Read what?");
   ob=present("ilihen");
   if (!ob){
     write("The kobold that cooks the food isn't here.");
     return 1;
   }
   else{
     write("%^ORANGE%^The menu is terribly difficult to read, but you can make out a few words:%^RESET%^\n");
     write("%^RED%^\t ------------------- FOODS! -------------------");
     write("%^WHITE%^\tgruel\t\t\t\t\t %^BOLD%^%^BLACK%^"+ (int)ob->get_price("gruel") + " silver");
     write("%^WHITE%^\tstuffed worms\t\t\t\t %^BOLD%^%^BLACK%^"+ (int)ob->get_price("stuffed worms") + " silver");
     write("%^WHITE%^\trat skewer\t\t\t\t %^BOLD%^%^BLACK%^"+ (int)ob->get_price("rat skewer")+" silver");
     write("%^WHITE%^\tfried batwings\t\t\t\t %^BOLD%^%^BLACK%^"+ (int)ob->get_price("fried batwings")+" silver\n");

     write("%^RED%^\n\t ------------------- DRINKS! -------------------");
     write("%^WHITE%^\twater\t\t\t\t\t %^BOLD%^%^BLACK%^"+(int)ob->get_price("water")+" silver");
     write("%^WHITE%^\tdark brew\t\t\t\t %^BOLD%^%^BLACK%^"+(int)ob->get_price("dark brew")+" silver\n\n");

     return 1;
   }
}

void reset(){
   ::reset();
   if(!present("llefi")) find_object_or_load(MON"llefi")->move(TO);
   if(!present("ilihen")) find_object_or_load(MON"ilihen")->move(TO);
   if(!present("fyvir")) find_object_or_load(MON"fyvir")->move(TO);

   switch(random(10)) {
     case 0:
     tell_room(TO,"%^ORANGE%^The walls of the hovel shift slightly, and a precarious creak comes from "
"them.%^RESET%^");
     break;
     case 1:
     tell_room(TO,"%^RED%^A small, grubby goblin passes you at a run, taking a swipe at your purse as he "
"goes.  He disappears into the crowd before you can even react.%^RESET%^");
     break;
     case 2:
     tell_room(TO,"%^BLACK%^%^BOLD%^A horrid smell emanates from a pile of trash supporting part of the "
"wall.  It almost smells like something died in there.  Ugh.%^RESET%^");
     break;
     case 3:
     tell_room(TO,"%^CYAN%^A strong scent reaches your nose, wafting from the partitioned section at the "
"back of the hovel.  It smells maybe half-edible?%^RESET%^");
     break;
     case 4..5:
     tell_room(TO,"%^BLUE%^A group of goblins shriek and bicker over a large bowl of food between them, "
"snatching whatever pieces they can get.%^RESET%^");
     break;
     case 6:
     tell_room(TO,"%^YELLOW%^Llefi carries a bowl across the room to a customer, picking at the food in it "
"as he goes.%^RESET%^");
     break;
     case 7:
     tell_room(TO,"%^GREEN%^Fyvir searches through the trash and comes up with a handful of rather "
"disgusting looking remains, which he carries out to the partitioned section of the hovel.%^RESET%^");
     break;
     case 8..9:
     tell_room(TO,"%^WHITE%^%^BOLD%^A scrawny little goblin slinks in and scrawls a few more words in "
"charcoal, onto the list on the western wall.%^RESET%^");
     break;
   }
}