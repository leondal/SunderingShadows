
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^GREEN%^Monastary Garden.
");
set_long(
@SEETH
%^BOLD%^%^CYAN%^Before you is a watering well. It is made of stone and beautifully crafted. A carving of a dragon and a phoenix chase each other around the stone well. Water can be drawn from the bucket.
SEETH
);

set_items(([
"road" : "A dirt path leading to a well or clearing.",
"path" : "A dirt path leading to a well or clearing.",
"well" : "%^RED%^The well is a work of art, and it works too. ;)",
]));

set_exits(([
"north" : RPATH "g19.c",
]));

set_smell("default", "%^BOLD%^%^CYAN%^The air is refreshing and comfortable.");

}
