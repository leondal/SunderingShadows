#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Town of Sandy, gold road");
    set_long(""
"%^BOLD%^WHITE%^You are on a gold road.\n%^RESET%^"
"The gold road is lined with large palm trees, and a few have fallem, causing "
"the gold in a few spots to get scratched a little.  This road is very clean, and "
"has not been traveled a lot from what you can tell.  There are many strange things "
"that catch your eyes in the bushes, but you do not bother to check them out.  "
""
"");


     set_smell("default","You the palm trees.");
    set_exits(([

       "north" : "/d/mine2/sandy/room/sandy7",

       "south" : "/d/mine2/sandy/room/sandy9",
    ] ));
    set_items(([
         "scratches" : "They are nothing big...",
         "road" : "The road is made of fine gold.",
         "gold" : "The gold is way to much for you to carry.",
         "strange things" : "They are different things hidden in the bushes.",
    ] ));
}
