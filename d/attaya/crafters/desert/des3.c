
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
Looking in a southerly direction you see a vast desert before you. It is dry and desolate. You can vaguely see bits of green foliage growing from the sand. Various forms of cactus grow also. You begin to consider your chances of survival here.
The thought of going back to Seneca plagues your mind.

ZERINA
);

set_items(([

]));

set_exits(([
"northwest" : "/d/attaya/crafters/desert/des1.c",
"southwest" : "/d/attaya/crafters/desert/des5.c",
"southeast" : "/d/attaya/crafters/desert/des6.c",

]));

set_smell("default", "It smells of desolation here.");
set_listen("default", "You can only hear your own breathing.");

}
