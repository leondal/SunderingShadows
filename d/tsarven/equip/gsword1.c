//  A scimitar made for the Imperial Guard of Tsarven
//  Thorn@ShadowGate
//  11/24/95
//  Tsarven Area
//  gsword1.c

#include <std.h>

inherit WEAPON;

create() {
    ::create();
   set_id(({ "sword", "tsarvani scimitar", "scimitar" }));
   set_name("scimitar");
   set_short("A Tsarvani scimitar");
   set_long(
@TSARVEN
	This is a scimitar, a distinctive weapon of the Southern Realms.
Looking at either the workmanship or the style of the sword instantly
gives away its place of origin as Tsarven. This scimitar is of
particularly excellent quality, its hilt is shiny and wrapped in
crimson.  The blade is very sharp.
TSARVEN
	);
   set_weight(4);
   set_size(2);
   set("value", 15);
   set_wc(1,9);
   set_large_wc(1,9);
   set_type("slash");
}

