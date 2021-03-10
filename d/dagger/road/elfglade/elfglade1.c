//little side path, elven ritual plot & permanent addition to retain lore. N, 3/15.
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("Within the Garden");
    set_short("%^BOLD%^%^GREEN%^Within the Garden%^RESET%^");
    set_long("%^BOLD%^%^GREEN%^Wild %^MAGENTA%^f%^RESET%^%^MAGENTA%^l%^BOLD%^%^RED%^o%^RESET%^%^RED%^w%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^r%^BOLD%^%^BLUE%^s %^RESET%^%^CYAN%^grow rampant on "
"either side of you, encroaching upon the %^RESET%^white path %^RESET%^%^CYAN%^that cuts its way through the grove. Here and there you can see smaller paths divert deeper into the gardens. "
"%^BOLD%^%^GREEN%^Verdant ivy %^RESET%^%^CYAN%^and pretty %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d r%^RESET%^%^RED%^o%^BOLD%^s%^RESET%^%^RED%^e%^BOLD%^s %^RESET%^%^CYAN%^snake around tall "
"%^RESET%^white columns %^RESET%^%^CYAN%^that flank the walkway. %^RESET%^White benches %^RESET%^%^CYAN%^also line the path for any who wish to rest their feet. The entire grove is surrounded "
"by massive trees on all sides, their branches twined so thickly that it is impossible to see within the forest from here.%^RESET%^\n");
    set_smell("default","%^BOLD%^%^GREEN%^It smells wonderfully fresh here.%^RESET%^");
    set_listen("default","%^BOLD%^%^CYAN%^A %^RESET%^%^CYAN%^fountain%^BOLD%^ splashes in the distance.%^RESET%^%^RESET%^");

    set_exits(([
      "gate" : "/d/dagger/road/elfglade/elfglade2",
      "east" : "/d/dagger/road/elfglade/shrine",
    ]));

    set_items(([
      "walkway" : "%^BOLD%^%^WHITE%^The pathway is entirely seamless and it is difficult to discern exactly what type of stone this is. The flawless, gleaming surface appears almost magical in "
"nature.%^RESET%^",
      "trails" : "%^RESET%^%^ORANGE%^Small trails branch out into the gardens for those who wish more privacy than the main path affords.%^RESET%^",
      "benches" : "%^BOLD%^%^WHITE%^The benches are made from the same white stone as the walkway. An intricate pattern of ivy and roses has been beautifully carved into the surface, care taken "
"to accentuate every tiny detail.%^RESET%^",
      "columns" : "%^BOLD%^%^WHITE%^Flanking the walkway, these columns appear to be for decorative purposes only. They are quite large, reaching about ten feet high, and they are about a foot "
"in diameter.%^RESET%^",
      "forest" : "%^RESET%^%^GREEN%^The ancient trees that surround this clearing are massive, easily reaching a hundred feet high.%^RESET%^",
    ]));
}