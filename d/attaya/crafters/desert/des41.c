
#include <std.h>
inherit ROOM;


void create(){
object ob;
:: create();

set_light(3);
set_property("indoors", 0);
set_climate("desert");
set_short("
%^ORANGE%^You are wandering in a desert.%^RESET%^
");
set_long(
@ZERINA
%^ORANGE%^You are wandering in a desert.%^RESET%^
It is hot and dry here. You are becoming slightly fatigued already and your journey has only just begun. There is a faint wind but it only blows hot air on your face. Sweat trickles down your back and covers your brow.

ZERINA
);

set_items(([

]));

set_exits(([
"northwest" : "/d/attaya/crafters/desert/des32",
"northeast" : "/d/attaya/crafters/desert/des33.c",
"southwest" : "/d/attaya/crafters/desert/des50.c",
"southeast" : "/d/attaya/crafters/desert/des51.c",

]));

set_smell("default", "It smells of desolation here.");
set_listen("default", "You can only hear your own breathing and a faint wind blowing.");

}
