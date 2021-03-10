#include <std.h>
#include "../dojo.h"
inherit VAULT;

void create() {
    ::create();
    set_terrain(NEW_MOUNTS);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("Outside a wooden dojo hall");
    set_short("%^RESET%^%^ORANGE%^Outside a wooden dojo hall%^RESET%^");
    set_long("%^CYAN%^A small clearing lies here, encircled by %^GREEN%^for%^ORANGE%^e%^GREEN%^st %^CYAN%^and rocky "
"outcroppings on all sides.  A beautiful, surprisingly ordered garden lies within, split by straight %^BOLD%^%^BLACK%^p"
"%^RESET%^eb%^BOLD%^%^BLACK%^bl%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^%^CYAN%^paths that weave amongst carefully trimmed "
"hedges and spreading %^MAGENTA%^c%^BOLD%^h%^WHITE%^er%^MAGENTA%^r%^RESET%^%^MAGENTA%^y bl%^BOLD%^o%^WHITE%^ss"
"%^MAGENTA%^o%^RESET%^%^MAGENTA%^m %^CYAN%^trees.  The manicured foliage encircles a two-level %^ORANGE%^wooden "
"%^CYAN%^building, with polished panels for walls, and a raised verandah running the length of each side.  Lines of "
"curved %^BLUE%^stone %^CYAN%^tiles form two levels of roofing, the lowest jutting out to an overhang that shades the "
"walkway around, while the upper rises to a ridged centre that runs down to the tip of each corner.  At the very front, "
"a broad door has been fitted on sturdy tracks, so that it might be slid aside to allow for a broad entryway.  A few "
"small %^BOLD%^win%^WHITE%^d%^CYAN%^ows %^RESET%^%^CYAN%^can be seen at intervals, each broken up by narrow slats and "
"sheeted with %^RESET%^ricepaper%^CYAN%^.%^RESET%^\n");
    set_smell("default","%^ORANGE%^The soft, sweet smell of %^MAGENTA%^c%^BOLD%^h%^WHITE%^er%^MAGENTA%^r%^RESET%^%^MAGENTA%^y bl%^BOLD%^o%^WHITE%^ss%^MAGENTA%^o%^RESET%^%^MAGENTA%^ms %^ORANGE%^wafts through the air.%^RESET%^");
    set_listen("default","%^GREEN%^There is a comfortable %^CYAN%^si%^GREEN%^l%^CYAN%^en%^BOLD%^c%^RESET%^%^CYAN%^e %^GREEN%^to this place.%^RESET%^");

    set_items(([
      ({"forest","rocky outcroppings","outcroppings","clearing"}) : "%^GREEN%^Sheltered by forest and stone is this small "
"clearing, easily missed from a short distance away.  Within lies a two-level wooden building, surrounded by an unusually "
"ordered garden on all sides.  Clearly someone tends to it regularly, as the forest hasn't been allowed to encroach upon "
"its limits.%^RESET%^",
      ({"dojo","hall","building","wooden building","walls","panels","verandah","roofing","tiles"}) : "%^ORANGE%^A two-level "
"building stands here, in the middle of the garden.  Its walls are all of wooden panels, as is the verandah that encircles "
"it on all sides.  Stone tiles line both levels of roofing, curved so that they line the roof like little waves.  A raised "
"ridge runs along the very top, and splits to touch each corner.%^RESET%^",
      ({"window","windows"}) : "%^CYAN%^At the upper middle of each wall lies a single short, broad window.  Narrow slats "
"form a frame to support ricepaper sheeting over each.%^RESET%^",
      ({"garden","paths","hedges","trees","cherry blossom trees"}) : "%^GREEN%^An orderly garden surrounds the building, "
"surely maintained regularly to be kept to such a pristine standard.  The hedges are neatly trimmed, spacing out other small "
"shrubs in small patches that are split by the pebbled pathways that weave between.  Most striking are the cherry blossom "
"trees, spreading their broad foliage overhead with beautiful flowers of white and pink.%^RESET%^",
    ]));
    set_exits(([
      "northeast" : ROOMS"centre",
      "south" : ROOMS"path1",
    ]));
    set_door("sliding door",ROOMS+"centre","northeast",0);
    set_door_description("sliding door","%^ORANGE%^A foot beyond the depression in the floorboards to the southwest lies "
"a sliding door, usually closed against the outside world.  From its sturdy frame extend a multitude of slats that criss-"
"cross their way to the opposite side, forming a support for the ricepaper that lies in a sheet across its surface.  A "
"small indentation near its closing point allows one to slide it open or shut at will.%^RESET%^");
    set_string("sliding door","open","%^ORANGE%^The door slides silently open upon well-oiled tracks.%^RESET%^");
    set_string("sliding door","close","%^ORANGE%^The door slides shut without a sound.%^RESET%^");
}