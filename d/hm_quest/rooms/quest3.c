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
"%^RESET%^You stand near the far end of a %^YELLOW%^g%^BOLD%^%^WHITE%^o%^RESET%^l%^ORANGE%^d%^YELLOW%^e%^BOLD%^%^WHITE%^n %^RESET%^beach that stretches around the eastern side of "
"the island.  It seems more of an effort to walk here, as the grains of sand shift beneath your feet with every movement.  The crash of the %^CYAN%^t%^BOLD%^%^BLUE%^i%^RESET%^%^BLUE%^d%^BOLD%^"
"%^CYAN%^e %^RESET%^serves as a constant backdrop of sound to the otherwise quiet surrounds, waves chasing in eagerly towards the shore only to surrender and slink back again seconds later.  A "
"mighty %^BOLD%^%^BLACK%^rock%^RESET%^, bigger than a house, lies embedded in the sand here, a crack sundering its immensity in two.  Away to the west, above the %^BOLD%^%^BLACK%^r%^RESET%^oc"
"%^BOLD%^%^BLACK%^k%^RESET%^y c%^ORANGE%^l%^RESET%^if%^BOLD%^%^BLACK%^f%^RESET%^s upon the highest point of this tiny island, the upper reaches of a tall %^BLUE%^building %^RESET%^loom above "
"the treeline.  The beach winds away to the south, serving as a pale border to the %^GREEN%^fo%^BOLD%^r%^YELLOW%^e%^RESET%^%^GREEN%^st%^ORANGE%^e%^GREEN%^d %^RESET%^reaches further inland.  "
"Further off to the northwest, a rocky outcropping supports the remains of a decayed %^ORANGE%^pi%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^r%^RESET%^.  Occasionally %^BOLD%^%^WHITE%^birds %^RESET%^"
"can be seen passing overhead, one of the few signs of life on this apparently desolate island.\n");

    set_smell("default","The fresh air carries the salty tang of the sea.");
    set_listen("default","Relentless waves pound the shoreline.");
    set_exits( ([
        "east" : "/d/hm_quest/rooms/quest2",
        "southwest" : "/d/hm_quest/rooms/quest4",
    ]) );
    set_items(([
      ({ "cliffs", "building", "stairs", "crumbled stairs", "rocky cliffs" }) : "%^RESET%^An %^BLUE%^omin%^GREEN%^o%^BLUE%^us %^RESET%^building of stone looms over the treeline far above you, "
"its walls cracked and darkened with age, while %^GREEN%^moss %^RESET%^and %^BOLD%^%^GREEN%^v%^YELLOW%^i%^BOLD%^%^GREEN%^nes %^RESET%^climb as they will upon its every surface.  Further "
"northwest, a series of crumbling stairs leads up the %^BOLD%^%^BLACK%^r%^RESET%^oc%^BOLD%^%^BLACK%^k%^RESET%^y c%^ORANGE%^l%^RESET%^iff%^BOLD%^%^BLACK%^s%^RESET%^ide towards it.",
      ({ "beach", "sand", "ocean", "waves", "tide" }) : "%^RESET%^Shifting beneath your feet and stretching away to the south is a beach of %^YELLOW%^g%^BOLD%^%^WHITE%^o%^RESET%^l%^ORANGE%^d"
"%^YELLOW%^e%^BOLD%^%^WHITE%^n %^RESET%^sand.  Sparkling %^BLUE%^w%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^v%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^s %^RESET%^constantly crash and break at its edge, adding "
"a constant dull roar of sound.  Patches of straggling %^BOLD%^%^GREEN%^g%^WHITE%^r%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^s%^RESET%^ dot the inner edges of the beach, before it "
"is lost entirely to the line of trees and foliage further inland.",
      ({ "pier", "outcropping", "rocky outcropping" }) : "%^RESET%^The beach ends only a few steps to the northwest, where the base of the cliff juts out into the ocean.  Supported precariously "
"upon this outcropping is a decayed %^ORANGE%^woo%^BOLD%^%^BLACK%^de%^RESET%^%^ORANGE%^n %^RESET%^pier.  It looks decidedly unsteady.",
      ({ "forest", "treeline", "trees", "grass" }) : "%^RESET%^Straggling patches of %^BOLD%^%^GREEN%^g%^WHITE%^r%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^s%^RESET%^ border the "
"inner edge of the beach, giving way to thickly forested %^GREEN%^b%^ORANGE%^u%^GREEN%^sh%^BOLD%^%^GREEN%^la%^RESET%^%^GREEN%^nd %^RESET%^beyond.",
      "birds" : "%^RESET%^A %^BOLD%^%^WHITE%^wh%^RESET%^it%^BOLD%^%^WHITE%^e-w%^RESET%^i%^BOLD%^%^WHITE%^nged %^RESET%^bird occasionally wheels overhead, its scream almost lost beneath the "
"constant pounding of the %^BLUE%^w%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^v%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^s%^RESET%^.  There doesn't seem to be any other sign of habitation here.",
      ({ "rock", "mighty rock", "crack" }) : "%^RESET%^A large %^BOLD%^%^BLACK%^rock %^RESET%^the size of a small house sits here, half-embedded in the sand.  It is gray in colour, with flecks "
"of s%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^l%^RESET%^v%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^r%^RESET%^ veining its surface and catching the sun's rays.  Great %^BLUE%^cracks %^RESET%^appear in the "
"rock, as if some mighty hand had tried to break it.  One such crack, far greater than the others, sunders the rock vertically from top to bottom, leaving it to look as though it had been "
"broken in half at one time, and placed back together again.",
    ]));
}