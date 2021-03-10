#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no teleport", 1);
    set_terrain(BARREN);
    set_travel(DECAYED_FLOOR);
    set_name("A desolate shoreline");
    set_short("%^YELLOW%^A desolate shoreline%^RESET%^");
    set_long("%^YELLOW%^A desolate shoreline%^RESET%^\n"
"%^RESET%^You stand midway along a %^YELLOW%^g%^BOLD%^%^WHITE%^o%^RESET%^l%^ORANGE%^d%^YELLOW%^e%^BOLD%^%^WHITE%^n %^RESET%^beach that stretches around the eastern side of the island.  It seems "
"more of an effort to walk here, as the grains of sand shift beneath your feet with every movement.  The crash of the %^CYAN%^t%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^d%^BOLD%^%^CYAN%^e %^RESET%^"
"serves as a constant backdrop of sound to the otherwise quiet surrounds, waves chasing in eagerly towards the shore only to surrender and slink back again seconds later.  Towards the upper "
"reaches of the beach, where sand gives way to patches of scraggly grass, several %^ORANGE%^bo%^BOLD%^%^BLACK%^at%^RESET%^%^ORANGE%^s %^RESET%^have been dragged above the high-tide mark.  Away "
"to the west, the upper reaches of a tall %^BLUE%^building %^RESET%^are only barely visible above the treeline.  The beach winds away in both directions, serving as a pale border to the "
"%^GREEN%^fo%^BOLD%^r%^YELLOW%^e%^RESET%^%^GREEN%^st%^ORANGE%^e%^GREEN%^d %^RESET%^reaches further inland.  Occasionally %^BOLD%^%^WHITE%^birds %^RESET%^can be seen passing overhead, one of the "
"few signs of life on this apparently desolate island.\n");

    set_smell("default","The fresh air carries the salty tang of the sea.");
    set_listen("default","Relentless waves pound the shoreline.");
    set_exits( ([
        "west" : "/d/hm_quest/rooms/quest4",
        "southeast" : "/d/hm_quest/rooms/quest6",
    ]) );
    set_items(([
      "building" : "%^RESET%^An %^BLUE%^omin%^GREEN%^o%^BLUE%^us %^RESET%^building of stone is barely visible over the treeline far above you, its walls cracked and darkened with age, while "
"%^GREEN%^moss %^RESET%^and %^BOLD%^%^GREEN%^v%^YELLOW%^i%^BOLD%^%^GREEN%^nes %^RESET%^climb as they will upon its every surface.",
      ({ "beach", "sand", "ocean", "waves", "tide" }) : "%^RESET%^Shifting beneath your feet and stretching away in either direction is a beach of %^YELLOW%^g%^BOLD%^%^WHITE%^o%^RESET%^l"
"%^ORANGE%^d%^YELLOW%^e%^BOLD%^%^WHITE%^n %^RESET%^sand.  Sparkling %^BLUE%^w%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^v%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^s %^RESET%^constantly crash and break at its "
"edge, adding a constant dull roar of sound.  Patches of straggling %^BOLD%^%^GREEN%^g%^WHITE%^r%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^s%^RESET%^ dot the inner edges of the beach"
", before it is lost entirely to the line of trees and foliage further inland.",
      ({ "forest", "treeline", "trees", "grass" }) : "%^RESET%^Straggling patches of %^BOLD%^%^GREEN%^g%^WHITE%^r%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^s%^RESET%^ border the "
"inner edge of the beach, giving way to thickly forested %^GREEN%^b%^ORANGE%^u%^GREEN%^sh%^BOLD%^%^GREEN%^la%^RESET%^%^GREEN%^nd %^RESET%^beyond.",
      "birds" : "%^RESET%^A %^BOLD%^%^WHITE%^wh%^RESET%^it%^BOLD%^%^WHITE%^e-w%^RESET%^i%^BOLD%^%^WHITE%^nged %^RESET%^bird occasionally wheels overhead, its scream almost lost beneath the "
"constant pounding of the %^BLUE%^w%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^v%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^s%^RESET%^.  There doesn't seem to be any other sign of habitation here.",
      "boats" : "%^RESET%^Several flat-bottomed %^ORANGE%^wo%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^den %^RESET%^boats have been dragged above the high-tide line here.  Save for a few buckets and "
"tangled fishing nets, they are all empty, and no drag line or footprints in the sand hint at recent handling.  Indeed, despite their %^RED%^sturdy %^RESET%^hardwood make, some of them are "
"looking a little worse for age and weather, as though they had been abandoned quite some time ago, and one has a sizeable hole in the stern.",
    ]));
}