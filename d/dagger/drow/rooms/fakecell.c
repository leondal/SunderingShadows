#include "/d/dagger/drow/short.h"
#include <std.h>
inherit "/std/room";
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_property ("light",-2);
    set_property ("indoors",1);
    set_property("no teleport",1);
    set_short ("a bare cell");
    set_long (
      "This is a bare cell made of stone walls covered in "
      "%^RED%^%^BOLD%^blood%^RESET%^. A pair of "
      "%^BLUE%^shackles%^RESET%^ hang on the wall. There is also a straw "
      "mat laid in one of the corners."
    );
    set_listen ("default","You hear the cries of the long since dead.");
    set_smell ("default","The odor of chaos drifts in through the open "
	"cell door.");
    set_items(([
	"shackles":"The shackles hang empty on the wall and are long "
	"since broken.",
	"straw":"The bed of straw does not look comfortable and you feel "
	"sorrow for those who have laid there in the past.",
	"walls":"The walls are covered in %^BOLD%^%^RED%^dried "
	"blood%^RESET%^."
    ]));
    set_exits(([
	"out": RPATH "fakeroom"]));
}
