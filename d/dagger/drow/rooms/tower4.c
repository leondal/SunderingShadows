#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(STAIRWAY);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Room of flames");
    set_long(
      	"%^BOLD%^%^RED%^All around this tower room fires are burning. "
	"The walls and ceilings seem to be made of flames. The floor "
	"is made of %^YELLOW%^hot coals%^RED%^. A %^YELLOW%^staircase%^RED%^ "
	"of flames leads up. Somehow you are unharmed by "
	"the tremendous heat in the room...for now.%^RESET%^"
    );
    set_listen("default",
	"The flames crackle and roar all about you."
    );
    set_smell("default",
     	"It smells of singed hair."
    );
    set_items(([
    	"fire":"%^BOLD%^%^RED%^The fire rages all about you.%^RESET%^",    
	"coals":"%^RED%^%^BOLD%^The hot coals beneath your feet should "
	"be burning you...but don't for now.",
	"walls":"The walls are made of %^RED%^%^BOLD%^flames%^RESET%^.",
	"floor":"The floor is covered in burning %^BOLD%^%^YELLOW%^coals"
	"%^RESET%^."
    ]));
    set_exits(([
	"out":"/d/dagger/drow/rooms/city41",
	"up":"/d/dagger/drow/rooms/tower5"
    ]));
    set_pre_exit_functions(({"up"}),({"heated"}));
}

int heated() {
    if (!TP || TP->query_npc()) return 0;
        write("%^BOLD%^%^RED%^You decide to escape from the heat and head up "
	"the stairs. Your body cools down.%^RESET%^");
    return 1;
}

void reset() {
    ::reset();
    if(!present("witch")) {
	new("/d/dagger/drow/mon/fwitch")->move(TO);
/* was bugging with bad argument to env. (TP wouldn't be valid)  *Styx* 11/1/03
last change was 2/02 (probably terrains going in)
	message("environment",
	  "%^RED%^%^BOLD%^Out of the flames the Fire witch appears!%^RESET%^"
	,environment(TP));
*/
	tell_room(TO,"%^RED%^%^BOLD%^Out of the flames the Fire witch appears!%^RESET%^");
    }
}
