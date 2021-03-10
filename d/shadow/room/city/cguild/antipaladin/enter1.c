#include <std.h>
#define ANTI "/d/shadow/room/city/cguild/antipaladin/"

inherit VAULT;

void create(){
  :: create();
  set_terrain(WOOD_BUILDING);
  set_travel(PAVED_ROAD);

  set_property("light",1);
  set_property("indoors",1);
//   set_property("no teleport",1);
  set_short("%^BOLD%^%^RED%^Antipaladin Hall Entrance%^RESET%^");
  set_long("%^RED%^You have entered a foyer just inside the walls of the Duke's castle.  The antipaladins seem to have gained the Duke's favor enough to have this area at their disposal.  The entrance to the stables is to the north and the armory is to the southwest.  To the northeast, a set of%^RESET%^ %^ORANGE%^huge oak doors%^RED%^ are currently barred closed.  Two statues of %^BOLD%^%^BLACK%^somber knights%^RESET%^%^RED%^ stand at attention at these doors.  The floor is made of %^BOLD%^%^BLACK%^highly polished marble%^RESET%^%^RED%^ with %^YELLOW%^crests of nobilities%^RESET%^%^RED%^ embedded in sections throughout.  The furnishings in the area are quite formal.  There is a %^BOLD%^%^RED%^fireplace%^RESET%^%^RED%^ taking up one section of the western wall and a row of %^ORANGE%^stately chairs %^RED%^with %^MAGENTA%^soft velvet, magenta cushions%^RED%^ along the eastern wall.  %^GREEN%^Tapestries %^RED%^fill the walls featuring scenes from many different settings, many of keeps and grand battles.");

  set_items(([ "crests" : "%^YELLOW%^The crests are inlaid into some of the %^BLACK%^marble tiles%^YELLOW%^.  The Duke of Tonovi's crest dominates the center of the room.  Others are of local nobilities and the dark knights of the realm.",
	"chairs" : "%^ORANGE%^These are ornately carved arm chairs of dark oak, with %^MAGENTA%^thick velvet cushions.",
	({"floor", "marble floor"}) : "%^BOLD%^%^BLACK%^The dark marble floor is highly polished, showing rich %^RESET%^%^ORANGE%^bronze veins%^BOLD%^%^BLACK%^.",

  ]));

  set_exits(([
	"out" : "/d/dagger/tonovi/antipath2",
	"north" : ANTI+"stable",
	"southwest" : ANTI+"store",
	"northeast" : ANTI+"hall",
   ]));
   set_door("door","/d/dagger/tonovi/antipath2","out",0);
   set_smell("default", "It smells clean here with a slight scent of burning wood.");
   set_listen("default", "You can hear others speaking in whispers.");
}
/*  board & commands removed now that it is ooc & via bboard command
ob= new(BBOARD);
ob->set_name("board");
ob->set_id( ({ "board", "antipaladin board"}) );
ob->set_board_id("apboard");
ob->set_max_posts(30);
ob->set_location("/d/shadow/room/city/cguild/antipaladin/anti3.c");
ob->set("short", "Antipaladin Class Board");
ob->set("long", "On this board post things concerning %^BOLD%^%^RED%^Antipaladins%^RESET%^.\n");
}

void init(){
    ::init();
    add_action("test_anti", "remove");
    add_action("test_anti", "answer");
    add_action("test_anti", "post");
    add_action("test_anti", "edit");
}

int test_anti(){
    if(avatarp(TP)) return 0;
    if(TP->is_class("antipaladin")) return 0;
    tell_object(TP, "Only Antipaladins.");
    return 1;
}
*/
/* long was this, changing to fit the Tonovi location
set_long(
@ZERINA
%^BOLD%^%^RED%^Antipaladin Guild Hall.%^RESET%^
You are now within a hall built by the Antipaladins.  The sense of order and calm has been restored here after coming in from the rubble outside these walls. There is a stable and armoury are here for the use of the dark knights.
ZERINA
);
*/
