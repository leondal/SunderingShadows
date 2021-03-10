
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^BOLD%^%^WHITE%^An old oriental monastary.
");
set_long(
@SEETH

%^BOLD%^%^CYAN%^This appears to be the main chamber of the monastary. The room is lighted by the few torches along two opposite walls to the east and west, and what light that comes through the entrance. Lines of meditating monks sit on the ground on circular mats parallel to the torches. Directly infront of you is an old monk upon a platform also in meditation. Behind the old monk is a large statue of Buddha. You feel at peace in here.

SEETH
);

set_items(([
"statue" : "This is a large golden statue of Buddha.",
"floor" : "The floors are made of large grey tiles. It appears clean.",
"torches" : "normal torches along the walls.",

]));

set_exits(([
"south" : RPATH "monastary.c",
]));

set_smell("default", "The air is clean and comfortable.");
set_listen("default", "You hear the breathing of the monks.");

}
