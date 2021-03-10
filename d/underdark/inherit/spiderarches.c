#include <std.h> 
#include "../defs.h" 
inherit VAULT; 

void create(){ 
    ::create(); 
    set_property("light",-1); 
    set_property("indoors",1); 
    set_terrain(NAT_CAVE);  //Not a natural cave, but rather a dwarven-slave crafted drow place
    set_travel(PAVED_ROAD); 
    set_name("An ancient underground passage"); 
    set_short("%^BOLD%^%^BLUE%^An ancient underground passage%^RESET%^"); 
    set_long("%^RESET%^%^BLUE%^An ancient underground passage%^RESET%^\n"
"%^BOLD%^%^BLUE%^Sculpted archways dominate this circular junction, providing a repast from "
"the endless white masses of %^WHITE%^spider web %^BLUE%^and %^RESET%^%^ORANGE%^dust %^BOLD%^%^BLUE%^that "
"clog the passages between.  Cut and mortared stone bricks of %^BLACK%^dark gray granite %^BLUE%^are "
"made all the darker by the %^WHITE%^white marble arches %^BLUE%^that lead from this sepulchered chamber.  "
"Each brick appears to have been carefully selected, fitted and carved to match all the others in shape "
"and size.  A stunning reminder of the builder's skill and dedication to their craft.  Though plain and "
"unadorned, each marbled arch lifts up into a sharp point at the top, creating a %^WHITE%^bell shape "
"%^BLUE%^out of the passage entrance.  Statuesque %^BLACK%^dark angels %^BLUE%^stand guard to either "
"side of the arches, their %^BLACK%^black marble%^BLUE%^ wings lifting up behind them, while their "
"dark skin gleams in the pale "
"%^YELLOW%^f%^RESET%^%^ORANGE%^l%^RED%^i%^ORANGE%^c%^YELLOW%^k%^RESET%^%^RED%^e%^YELLOW%^r%^BLUE%^ of "
"any light.%^RESET%^"); 
    set_smell("default","Dust and age assail your senses."); 
    set_listen("default","All is silent but for the beating of your heart."); 
    set_items(([ 
      ({"archway","archways","arches","arch"}):"%^BOLD%^%^WHITE%^Made from white marble, these arches stand in "
"bold contrast to the dark stone that makes up the walls.  Each arch is made from two slabs of marble that "
"arch up and meet at a sharp point, causing the arch's form to appear bellshaped.%^RESET%^", 
      ({"walls","wall","brick","bricks","granite"}):"%^BOLD%^%^BLACK%^The dark granite of these bricks gives "
"the room a dreary appearance that makes you think of catacombs and haunted chambers.  Each brick looks to "
"have been hand carved by master stone masons for each is symmetrical to the next.  Even their color appears "
"to be matched, going from a lighter gray toward the ceiling down to nearly black on the floor.%^RESET%^",
      ({"angel","angels","wing","wings"}):"%^BOLD%^%^BLACK%^These dark figures seem like something out of a "
"dream with their sculpted arching wings and eloquent, noble features.  Yet it is the obsidian stone that they "
"are made of and the cold gaze of their onyx eyes that send a shiver down your spine and make you wonder "
"if these dark beings are in fact watching you, or if it is just a trick of the light.%^RESET%^",
      (("passage","passages")):"%^BOLD%^%^WHITE%^The passages are clotted and filled with sticky cobweb, "
"blocking any chance of your being able to see where they lead.%^RESET%^",
      ({"cobweb","cobwebs","web","spider web"}):"%^BOLD%^%^WHITE%^All around you are an exorbitant amount of "
"cobwebs.  Their sticky masses cling to every surface and hang between the walls making it difficult to "
"see more then a few feet ahead of you.  Whatever made that webbing must either be plentiful or very "
"large.%^RESET%^",
    ])); 
}

//No <peer>ing allowed in this place. Returns: "The passage is too clogged with cobwebs to tell where it leads."

//Anytime someone walks down a hall an on-exit message should appear: "You push through the tangled cobwebs 
//and become lost in their sticky depths before finding yourself in another part of these underground chambers."  
//Or something along those lines. 
