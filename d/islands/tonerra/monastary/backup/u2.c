
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^BOLD%^%^CYAN%^Upper floor of the monastary.
");
set_long(
@SEETH
%^CYAN%^You are traveling through the hallways of the upper floor of the
monastary. The torches along the walls light the room as you walk.
You notice that east of here leads you to a hallway of doors.
SEETH
);

set_items(([
"torches" : "normal torches along the walls.",
"floor" : "The floors are made of large grey tiles. It appears clean.",
]));

set_exits(([
"southwest" : RPATH "u1.c",
"east" : RPATH "u3.c",
]));

set_smell("default", "The air is clean and confortable.");

}
