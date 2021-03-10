
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
The heat is starting to make you feel a bit dizzy. There are small dunes forming from the sand being blown by the wind. Cactus grows sparsely here. From time to time you think you see something moving in the sand. The sun beats down upon your head.

ZERINA
);

set_items(([
"cactus" : "The cactus growing throughout this area, is graced with flowers of %^RED%^red%^RESET%^, %^YELLOW%^yellow%^RESET%^, and %^MAGENTA%^purple%^RESET%^.",

]));

set_exits(([
"northwest" : "/d/attaya/crafters/desert/des115.c",
"northeast" : "/d/attaya/crafters/desert/des116",
"southwest" : "/d/attaya/crafters/desert/des147.c",
"southeast" : "/d/attaya/crafters/desert/des148.c",

]));

set_smell("default", "It smells of dryness, sand, and faintly of cactus flowers.");
set_listen("default", "You can hear the wind as it blows the sand.");

}
