#include <std.h>
#include <objects.h>

inherit "/std/room";

void create() {
    room::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(1);
    set_short("%^BOLD%^%^CYAN%^S%^RESET%^%^CYAN%^h%^BOLD%^ea%^RESET%^%^CYAN%^s%^BOLD%^'s %^WHITE%^S%^RESET%^i%^BO"
			  "LD%^l%^RESET%^v%^BOLD%^er%^RESET%^e%^BOLD%^d %^RESET%^A%^BOLD%^x%^RESET%^e ");
    set_long("You find yourself in %^ORANGE%^Kinaro's %^BOLD%^%^BLACK%^weaponshop%^RESET%^. A large %^ORANGE%^oak"
	     	 "en counter %^WHITE%^dominates the room, with the %^BOLD%^%^BLACK%^shop keeper %^RESET%^standing beh"
			 "ind it, %^BOLD%^%^CYAN%^welcoming %^RESET%^you to her shop. The right wall, have %^ORANGE%^large wo"
			 "oden %^BOLD%^%^BLACK%^weapon %^RESET%^racks to show off %^BOLD%^%^CYAN%^halberds%^RESET%^, %^CYAN%^"
			 "spears%^WHITE%^, %^RED%^voulges %^WHITE%^and other %^BOLD%^%^CYAN%^polearms%^RESET%^, while another"
			 " rack holds long %^BOLD%^%^RED%^axes %^RESET%^and %^BOLD%^master crafted %^RED%^two handed swords %"
			 "^RESET%^of different designs. Large %^BOLD%^glass di%^RESET%^splays are lining the left wall, and "
			 " on display; you can see %^BOLD%^%^BLACK%^daggers%^RESET%^, %^ORANGE%^short swords%^WHITE%^, %^BOLD"
			 "%^%^RED%^axes%^RESET%^, %^BOLD%^rapiers %^RESET%^and the like. The wares are presented in their %^B"
			 "OLD%^best possible way%^RESET%^, and every piece of %^BOLD%^m%^BLACK%^e%^WHITE%^t%^BLACK%^a%^WHITE%"
			 "^l %^RESET%^and %^ORANGE%^wood %^WHITE%^have been %^BOLD%^po%^RESET%^l%^BOLD%^is%^RESET%^h%^BOLD%^e"
			 "d %^RESET%^to a shine. The shop is %^CYAN%^clean %^WHITE%^and %^BOLD%^%^CYAN%^inviting %^RESET%^wit"
			 "h a %^MAGENTA%^friendly %^WHITE%^atmosphere. Behind %^BOLD%^%^BLACK%^Sheas%^RESET%^, on the farthest"
			 " wall, the %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^e%^BOLD%^%^BLACK%^l d%^RESET%^o%^BOL"
			 "D%^%^BLACK%^o%^RESET%^r of a %^YELLOW%^vault %^RESET%^catches your eye. The small %^YELLOW%^vault %^R"
			 "ESET%^have several %^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^tr%^RESET%^%^CYAN%^i%^BOLD%^ca%^RESET%^"
			 "%^CYAN%^t%^BOLD%^e %^BLACK%^l%^WHITE%^o%^BLACK%^cks %^RESET%^and you wonder what %^BOLD%^%^BLACK%^Shea"
			 "s %^RESET%^keeps in there.");
	set_smell("default" "The smell of soot, ash and tempered steel is heavy in the air.");
    set_listen("default","The clang of metal reverberates through the store.");
    set_exits((["west":"/d/dagger/kinaro/street3"]));
}
void reset(){
    ::reset();
    if(!present("sheas"))
	new("/d/dagger/kinaro/mon/sheas")->move(TO);
}