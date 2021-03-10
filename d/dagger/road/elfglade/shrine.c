//little side path, elven ritual plot & permanent addition to retain lore. N, 3/15.
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("Shrine of the Seldarine");
    set_short("%^BOLD%^%^WHITE%^Shrine of the Seldarine%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Eleven columns encircle this clearing, each bearing a %^RESET%^symbol %^BOLD%^%^WHITE%^of an elven deity. Offerings to the %^ORANGE%^Seldarine %^WHITE%^have been "
"carefully arranged in the grass at the base of each of them. The %^RESET%^white walkway %^BOLD%^rings the clearing as well, and stretches into the surrounding %^GREEN%^t%^RESET%^%^GREEN%^r"
"%^BOLD%^e%^RESET%^%^GREEN%^e%^BOLD%^s %^WHITE%^in various directions. There is a profound feeling of power and solemn reverence here beneath the %^RESET%^%^CYAN%^open skies%^BOLD%^%^WHITE%^. "
"%^RESET%^White benches %^BOLD%^rest between each of the pillars for any who wish to sit and pay their respects or simply to enjoy the simplistic beauty of this shrine to the %^ORANGE%^Seldarine"
"%^WHITE%^.%^RESET%^\n");
    set_smell("default","%^BOLD%^%^GREEN%^It smells wonderfully fresh here.%^RESET%^");
    set_listen("default","%^BOLD%^%^CYAN%^A %^RESET%^%^CYAN%^fountain%^BOLD%^ splashes in the distance.%^RESET%^%^RESET%^");

    set_exits(([
      "west" : "/d/dagger/road/elfglade/elfglade1",
    ]));

    set_items(([
      "forest" : "%^RESET%^%^GREEN%^The ancient trees that surround this clearing are massive, easily reaching a hundred feet high.%^RESET%^",
      "benches" : "%^BOLD%^%^WHITE%^The benches are made from the same white stone as the walkway. An intricate pattern of ivy and roses has been beautifully carved into the surface, care taken "
"to accentuate every tiny detail.%^RESET%^",
      "walkway" : "%^BOLD%^%^WHITE%^The pathway is entirely seamless and it is difficult to discern exactly what type of stone this is. Its flawless, gleaming surface appears almost magical in "
"nature.%^RESET%^",
      "offerings" : "%^MAGENTA%^Flowers, gemstones, metals, all things sacred to each individual God have been carefully placed around the base of the columns. Heavy parchments with poems and "
"songs, paints and sculptures, pieces of jewelry and musical instruments have all been lovingly placed in an attempt to garner the attention and favor of the Seldarine.%^RESET%^",
    ]));
}