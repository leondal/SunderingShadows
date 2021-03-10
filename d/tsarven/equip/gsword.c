//  A Two-Handed sword made for the Imperial Guard of Tsarven
//  Thorn@ShadowGate
//  11/24/95
//  Tsarven Area
//  gsword2.c

#include <std.h>

inherit WEAPON;

create() {
    ::create();
   set_id(({ "sword", "two handed sword", "tsarvani sword", "two handed" }));
   set_name("two handed sword");
   set_short("A Tsarvani two-handed sword");
   set_long(
@TSARVEN
	This is a long straight bladed sword.  Looking at either the workmanship
or the style of the sword instantly gives away its place of origin as Tsarven.
This sword is of particularly excellent quality, its hilt is shiny and wrapped
in crimson.  The blade is very sharp.
   );
   set_weight(15);
   set_size(3);
   set("value", 75);
   set_wc(1,11);
   set_large_wc(4,5);
   set_type("slash");
}

