
#include <std.h>
#include "/d/islands/tonerra/monastary/short.h"
inherit ROOM;


void create(){
object ob;
:: create();

set_light(2);
set_indoors(1);
set_short("
%^BOLD%^%^RED%^Monastary Arena.
");
set_long(
@SEETH
%^RED%^A large stone platform is infront of you. There are steps leading on the platform. The four pillars are places around the circular platform. Each pillar seems to be shaped into different animals. Everything appears to be well kept and clean.
SEETH
);

set_items(([
"road" : "A dirt path leading to a well or clearing.",
"path" : "A dirt path leading to a well or clearing.",
"steps" : "These are steps leading on to the platform.",
"pillars" : "The pillars are in the shape of different animals. The animals that are portrayed are the Dragon, Phoenix, Tiger, and Snake.",
]));

set_exits(([
"west" : RPATH "g20.c",
]));

set_smell("default", "%^BOLD%^%^RED%^You breath in the air and it refreshes you.");

}
