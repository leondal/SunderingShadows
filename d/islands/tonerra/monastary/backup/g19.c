
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
%^CYAN%^You are walking upon a dirt path road. South of here you can see a well. To your east, there appears to be a large clearing.
SEETH
);

set_items(([
"road" : "A dirt path leading to a well or clearing.",
"path" : "A dirt path leading to a well or clearing.",
]));

set_exits(([
"south" : RPATH "g13.c",
"east" : RPATH "g20.c",
"northwest" : RPATH "g25.c",
]));

set_smell("default", "The air is wonderfully clean and refreshing.");

}
