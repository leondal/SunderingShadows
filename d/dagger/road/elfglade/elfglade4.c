//little side path, elven ritual plot & permanent addition to retain lore. N, 3/15.
#include <std.h>
#include <daemons.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("Forest Path");
    set_short("%^RESET%^%^GREEN%^Forest Path%^RESET%^");
    set_long("%^BOLD%^%^GREEN%^The edge of the forest is not overly dense, but you see no discernible path ahead of you. Dancing beams of %^ORANGE%^sunlight %^GREEN%^flicker through the trees. "
"Birds chirp %^RESET%^%^CYAN%^c%^MAGENTA%^h%^CYAN%^e%^MAGENTA%^e%^CYAN%^rf%^MAGENTA%^u%^CYAN%^l%^MAGENTA%^l%^CYAN%^y %^BOLD%^%^GREEN%^around you and it is actually quite %^RESET%^%^MAGENTA%^"
"tranquil %^BOLD%^%^GREEN%^here, except for the discomforting feeling that you are being watched. The ground beneath your feet is thick with v%^RESET%^%^GREEN%^e%^BOLD%^rda%^RESET%^%^GREEN%^n"
"%^BOLD%^t f%^RESET%^%^GREEN%^o%^BOLD%^lia%^RESET%^%^GREEN%^g%^BOLD%^e.%^RESET%^\n");
    set("night long","%^BOLD%^%^GREEN%^The edge of the forest is not overly dense, but you see no discernible path ahead of you. Moon light %^GREEN%^shines through the trees, casting the "
"forest in a %^BOLD%^%^BLACK%^si%^RESET%^lve%^BOLD%^%^BLACK%^ry li%^RESET%^g%^BOLD%^%^BLACK%^ht%^RESET%^%^GREEN%^. It is actually quite %^RESET%^%^MAGENTA%^tranquil %^BOLD%^%^GREEN%^here, "
"except for the discomforting feeling that you are being watched. The ground beneath your feet is thick with v%^RESET%^%^GREEN%^e%^BOLD%^rda%^RESET%^%^GREEN%^n%^BOLD%^t f%^RESET%^%^GREEN%^o"
"%^BOLD%^lia%^RESET%^%^GREEN%^g%^BOLD%^e.%^RESET%^\n");
    set_smell("default","%^RESET%^%^CYAN%^You smell the fresh scent of %^RED%^w%^RESET%^%^RED%^i%^YELLOW%^l%^RESET%^%^ORANGE%^d%^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^l%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^w%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^BLUE%^s%^GREEN%^.");
    set_listen("default",(:TO,"listen_switch":));

    set_exits(([
      "out" : "/d/dagger/road/road81",
      "east" : "/d/dagger/road/elfglade/elfglade3",
    ]));
    set_invis_exits(({"east"}));

    set_items(([
      "trees" : "%^RESET%^%^GREEN%^The trees are thin enough here that you can still see the main road. Ahead, they quickly begin to thicken, blocking your view.%^RESET%^",
      "foliage" : "%^RESET%^%^GREEN%^Greenery and wild flowers cover the forest floor, muffling the sound of your footsteps.%^RESET%^",
      "stone" : ({"%^RESET%^%^GREEN%^There is a small flat stone stuck amongst a patch of wild flowers. It appears to have some writing on it.%^RESET%^","\n\n%^BOLD%^%^WHITE%^~ east ~%^BOLD%^%^WHITE%^","elven"}),
    ]));
   set_search("foliage","%^BOLD%^%^WHITE%^You notice a flat stone stuck amongst a patch of wild flowers. It appears to have some writing on it.%^RESET%^");
}

string listen_switch() {
   if ((string)EVENTS_D->query_time_of_day() == "night") 
     return "%^RESET%^%^GREEN%^You hear the occasional %^ORANGE%^horse %^GREEN%^passing on the road.%^RESET%^";
   return "%^RESET%^%^GREEN%^Birds chirp %^ORANGE%^c%^CYAN%^h%^MAGENTA%^e%^CYAN%^e%^ORANGE%^rf%^CYAN%^u%^MAGENTA%^l%^CYAN%^l%^ORANGE%^y%^GREEN%^, and you hear the occasional %^ORANGE%^horse %^GREEN%^passing on the road.%^RESET%^";
}
