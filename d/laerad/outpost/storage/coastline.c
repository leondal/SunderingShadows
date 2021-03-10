//coastline Template  - Essyllis - 04-2015


#include <std.h>
#include "../outpost.h"


inherit CROOM;

object ob;
//void pick_critters();


void create() {

    //pick_critters();
    set_repop(45);
    ::create();
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_property("no teleport",0);
    set_name("coastline");
    set_short("%^ORANGE%^coastline road%^RESET%^");
    set_long("%^ORANGE%^This seem to be the 'main road' of this little %^MAGENTA%^outpost%^ORANGE%^, the "+
	"road itself is made from %^BOLD%^%^BLACK%^g%^RESET%^r%^BOLD%^%^BLACK%^o%^RESET%^u%^BOLD%^%^BLACK%^nd-d%^RESET%^o%^BOLD%^%^BLACK%^wn "+
	"r%^RESET%^o%^BOLD%^%^BLACK%^cks %^RESET%^%^ORANGE%^which has been %^BOLD%^%^BLACK%^hard-stomped %^RESET%^%^ORANGE%^into "+
	"the ground. It is build on the edge of the %^CYAN%^coastline %^ORANGE%^to the west. The %^CYAN%^coastline %^ORANGE%^is a "+
	"large %^BOLD%^%^BLACK%^cliff %^RESET%^%^ORANGE%^about 30 feet over %^BOLD%^%^CYAN%^sea level%^RESET%^%^ORANGE%^. Making it "+
	"quite a fall if anyone were to fall over the cliff, a wooden fence have been made to prevent that from happening. To the "+
	"right of the road is where the %^MAGENTA%^buildings %^ORANGE%^are being build. Many are still in the making. But a few "+
	"houses do stand completed.%^RESET%^\n");
	
    set_smell("default","%^BOLD%^%^CYAN%^The salty ocean %^RESET%^%^CYAN%^air almost washes away the %^GREEN%^eg%^MAGENTA%^g%^GREEN%^y sme%^MAGENTA%^l%^GREEN%^l %^CYAN%^of the %^ORANGE%^island.");
    set_listen("default","%^RESET%^You hear %^BOLD%^%^BLACK%^construction noises%^RESET%^ over the constant %^CYAN%^howling of the wind.%^RESET%^");

    set_items
    (([	
        ({"floor", "ground"}) : "The ground here is made from grounded rocks which provides good stability for heavy loaded carts.",
        ({"fence", "Fence"}) : "The fence is constructed by thick oaken beams dug deep into the ground. It would take some beating before giving away.",
        ({"building", "buildings", "houses", "house"}) : "Most of all the buildings here are half-finished. Some even just a skeletal frame. Only a few stands complete.",
		({"ocean","sea"}):"You have a impressive view over the ocean from up here. Powerful 9 feet waves crashes against the cliff below you.",
                ({"cliff","cliffs"}):"It is a steep drop from up here. At least 30 feet down into jagged rocks in the water and 9 feet waves crashing in constantly. None would survive that!",
	]));

	}

	
void reset(){
   ::reset();
   
   switch(random(6)){
      case 0..2:  tell_room(TO,"%^BOLD%^%^CYAN%^You hear waves crashing against the %^BLACK%^cliffs%^CYAN%^ below");
               break;
      case 3..4:  tell_room(TO,"%^ORANGE%^The constant sounds of construction work is almost soothing compared to the howling winds");
               break;
      case 5:  tell_room(TO,"%^BOLD%^%^BLACK%^A steady stream of %^YELLOW%^carts%^BLACK%^ with %^RESET%^%^ORANGE%^building materials%^BOLD%^%^BLACK%^ or %^RESET%^%^GREEN%^food %^BOLD%^%^BLACK%^and %^CYAN%^water%^BLACK%^ is going either to or from the docks.");
               break;
         }
}

/*
void pick_critters(){
   switch(random(5)){
        case 0:   set_monsters(
({MOBS"gnollwarrior",MOBS"gnollpriest"}),({random(2),1}) );
                   break;
         case 1:   set_monsters(
({MOBS"gnollwarrior",MOBS"gnollbarb"}),({random(2),1}) );
                   break;
         case 2:   set_monsters(
({MOBS"gnollpriest",MOBS"gnollbarb"}),({random(2)+1,random(2)}) );
                   break;
         case 3..4: break;
   }
}
*/
