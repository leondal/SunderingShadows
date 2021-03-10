#include <std.h>
#include "../tharis.h"
inherit CROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("light",1);
    set_name("City slums");
    set_short("%^BOLD%^%^BLACK%^City slums%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Drawing the eye before anything else here is the vast, looming bulk of "
"the hovering %^RESET%^%^BLUE%^Shadovar %^BOLD%^%^BLACK%^fortress, far in the sky above. It casts the "
"entire city under a pall of unrelenting %^RESET%^darkness%^BOLD%^%^BLACK%^. Draped in its shadows, "
"the broken cobbles of the streets have given way here to a m%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^dd"
"%^RESET%^%^ORANGE%^y%^BOLD%^%^BLACK%^, churned-up series of %^RESET%^%^ORANGE%^dirt roads "
"%^BOLD%^%^BLACK%^and alleys that snake their way between a hodgepodge of old buildings and dilapidated "
"shacks. Once the grand streets of old Tharis, the expansion of industry and the city itself has "
"condemned this aged portion of the city to poverty and disrepair. The old %^RESET%^%^WHITE%^stone "
"buildings %^BOLD%^%^BLACK%^are chi%^RESET%^%^WHITE%^p%^BOLD%^%^BLACK%^ped and c%^RESET%^%^WHITE%^r"
"%^BOLD%^%^BLACK%^umbli%^RESET%^%^WHITE%^n%^BOLD%^%^BLACK%^g. Patches of %^RESET%^%^ORANGE%^wood"
"%^BOLD%^%^BLACK%^, %^RESET%^%^WHITE%^ca%^ORANGE%^n%^WHITE%^vas%^BOLD%^%^BLACK%^, %^RESET%^%^ORANGE%^w"
"%^RED%^a%^ORANGE%^dd%^RED%^l%^ORANGE%^e %^BOLD%^%^BLACK%^and other such low quality materials can be "
"seen shoring up the broken walls and covering the empty windows. Extending from these out into the "
"already narrow streets are piecemeal shacks constructed of whatever the builder could get a hold of. "
"Their shoddy, temporary nature might suggest they'd be washed away with the next rain, but some appear "
"to have endured for a considerable length of time.");
    set_smell("default","%^RESET%^%^ORANGE%^You smell refuse, and grime.%^RESET%^");
    set_listen("default","%^BLACK%^%^BOLD%^You hear whispers from everywhere.%^RESET%^");
    set_items (([
      "fortress" : "%^BLUE%^Above the city looms the ever-present Shadovar fortress, casting the entire "
"area into a state of perpetual twilight.%^RESET%^",
      ({"cobbles","street","muddy street","roads","alleys"}) : "%^ORANGE%^The streets are muddy and uneven, "
"cutting through the buildings and shanties with troughs of sticky sludge. Trash and rubble pile up in the "
"corners, pushed out of the way by wind and traffic. Here and there, small patches of cobblestones can be "
"seen, suggesting that at one time these roadways were paved.",
      ({"buildings","building"}) : "%^CYAN%^These buildings are old and every one of them shows the signs of "
"abandonment at one time or another. Despite this, at one time they might have been grand structures, complete "
"with beautiful facades. Their old grandeur can sometimes be seen in the entry ways and gables, where the "
"carvings, marble and other structural decoration has withstood the test of time.",
      ({"shacks","shack"}) : "%^ORANGE%^The shacks look like mostly temporary buildings formed out of fabric "
"sheets, beams of wood and an occasional pile of rocks. Most are little more then lean-tos that butt up "
"against the wall of one of the dilapidated buildings.",
      ({"canvas","waddle","wood","patches"}) : "%^RESET%^%^ORANGE%^A mixture of mediums has been used to shore "
"up the crumbling walls of old Tharis. The ancient buildings have seen their share of damage and wreckage, but "
"these temporary methods to keep them from crumbling completely seem to be working for the most part. Wooden "
"beams, squares of hardened waddle and dab, stretches of fabric shoved into cracks and crannies and, of course, "
"mud, to fill in what the other methods can't cover.%^RESET%^",
      ({"windows","window"}) : "%^BOLD%^%^BLACK%^Most of the windows are dark, covered with whatever the "
"occupant could find to block out both light and cold. Most have some sort of fabric stretched across them, "
"though a few are more permanently boarded up with wooden slats.",
    ]));
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}