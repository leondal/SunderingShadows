
#include <std.h>
inherit ROOM;
void create(){
object ob;
:: create();
set_light(2);
set_property("indoors", 0);
set_climate("desert");
set_short("
%^ORANGE%^You are wandering in a desert.%^RESET%^
");
set_long(
@ZERINA
%^ORANGE%^You are wandering in a desert.%^RESET%^
The wind feels not as warm. The sand is still drifting and the dunes seem to be getting bigger the father south you go. Wildlife runs across your path from time to time but yet the feeling of desolation is still upon you. All of a sudden you hear the faint sound of voices.

ZERINA
);

set_items(([

]));

set_exits(([
"northwest" : "/d/attaya/crafters/desert/des185.c",
"northeast" : "/d/attaya/crafters/desert/des186",
"southwest" : "/d/attaya/crafters/desert/des226.c",
"southeast" : "/d/attaya/crafters/desert/Odes227.c",

]));

set_smell("default", "You can smell nothing.");
set_listen("default", "You can hear faint noises to the southeast.");

}
