#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, metal bridge.");
    set_long(""
"%^BOLD%^WHITE%^You are on a large metal brige.\n%^RESET%^"
"The bridge is made of fine metals like what great swords are made out of.  "
"There are many large statured people walking over it, and west into a large "
"fort or castle.  There is a great deal of building that made this bridge what "
"it is, and must have required a lot of power and strength to do so.  There are "
"many broken swords and other weapons that have been thrown over the bridge when "
"people have been to tough on them.");

     set_listen("default","You feet march over the bridge.");
     set_smell("default","You smell nothing strane.");
    set_exits(([

       "south" : "/d/mine2/sandy/room/sandy22",

       "west" : "/d/mine2/sandy/room/sandyac_fighter",
    ] ));
    set_items(([
         "bridge" : "The bridge is made out of metal, and is very large and sturdy.",
         "people" : "The people are very large and powerfull.",
         "swords" : "The pieces are scattered all over the ground below the bridge.",
         "below" : "Below the bridge is just an empty patch of land.",
    ] ));
}
