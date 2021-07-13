#include <std.h>
inherit ROOM;

void create()
{
    ::create();

    set_property("indoors", 0);
    set_property("light", 1);

    set_climate("temperate");
    set_short("%^ORANGE%^large mound ");
    set_long("%^ORANGE%^A " + query_short() + "\n" + "%^CYAN%^The %^BOLD%^%^GREEN%^an%^RESET%^%^GREEN%^c%^BOLD%^ie%^RESET%^%^GREEN%^n%^BOLD%^t oa%^RESET%^%^GREEN%^k %^CYAN%^towers to the west. To the east a large %^BOLD%^%^GREEN%^gra%^RESET%^%^GREEN%^s%^BOLD%^s-c%^RESET%^%^GREEN%^ov%^BOLD%^ered mou%^RESET%^%^GREEN%^n%^BOLD%^d %^RESET%^%^CYAN%^create%^BOLD%^%^GREEN%^s %^RESET%^%^CYAN%^another steep %^BOLD%^%^GREEN%^c%^RESET%^%^GREEN%^l%^BOLD%^ear%^RESET%^%^GREEN%^i%^BOLD%^ng %^RESET%^%^CYAN%^in %^GREEN%^t%^CYAN%^he fo%^BOLD%^%^GREEN%^r%^RESET%^%^CYAN%^est. On closer ins%^BOLD%^%^GREEN%^p%^RESET%^%^CYAN%^ection, pale %^BOLD%^%^WHITE%^s%^RESET%^mo%^BOLD%^k%^RESET%^e %^CYAN%^clouds bil%^GREEN%^l%^CYAN%^ows up from the top of the mound, a%^GREEN%^n%^CYAN%^d the dirt path that leads from the s%^GREEN%^a%^CYAN%^cre%^BOLD%^%^GREEN%^d %^RESET%^%^CYAN%^oak reveals a %^ORANGE%^do%^BOLD%^o%^RESET%^%^ORANGE%^r %^CYAN%^in the side of the mound. In %^BOLD%^%^GREEN%^t%^RESET%^%^CYAN%^he %^BOLD%^%^GREEN%^su%^RESET%^%^GREEN%^r%^BOLD%^roun%^RESET%^%^GREEN%^d%^BOLD%^ing fo%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^s%^BOLD%^t%^RESET%^%^CYAN%^, she%^GREEN%^l%^CYAN%^tered by %^GREEN%^firs %^CYAN%^and %^BOLD%^%^GREEN%^oaks%^RESET%^%^CYAN%^, you spot a few t%^GREEN%^e%^CYAN%^nts made of hide and lodges made of bran%^GREEN%^c%^CYAN%^hes. Looking up into the ca%^BOLD%^%^GREEN%^n%^RESET%^%^CYAN%^opy you not%^GREEN%^ic%^CYAN%^e a %^GREEN%^f%^CYAN%^ew hammocks and nest-like structures in the branche%^BOLD%^%^GREEN%^s %^RESET%^%^CYAN%^above. Piles of wood a%^BOLD%^%^GREEN%^r%^RESET%^%^CYAN%^e stacked u%^GREEN%^n%^CYAN%^de%^GREEN%^rn%^CYAN%^eath %^GREEN%^c%^BOLD%^am%^RESET%^%^GREEN%^ouf%^BOLD%^l%^RESET%^%^GREEN%^a%^BOLD%^g%^RESET%^%^GREEN%^ed %^CYAN%^sheds.\n");
    set_smell("default", "%^ORANGE%^You smell the fresh air of the forest, as well as a lingering scent of smoke and cooked meat.%^ORANGE%^");
    set_listen("default", "%^CYAN%^You hear faint voices from inside the mound.");
    set_exits(([
                   "west" : "/d/magic/temples/nimnavanon/nimnavanon",
                   "hall" : "/d/magic/temples/nimnavanon/hall",
                   ]));

    set_items(([
                   "mound" : "%^GREEN%^The mound is steep and covered in grass. A path leads from the side of the mound back to the sacred grove to the west.",
                   "forest" : "%^GREEN%^The forest around the mound is lush and shady with tall oaks, firs and wild undergrowth. It shelters a few scattered %^ORANGE%^tents %^GREEN%^and %^ORANGE%^lodges.",
                   "path" : "%^GREEN%^The dirt path leads west to Nimnavanon's %^BOLD%^%^GREEN%^sa%^RESET%^%^GREEN%^c%^BOLD%^re%^RESET%^%^GREEN%^d%^BOLD% oa%^RESET%^%^GREEN%^k.",
                   "tents" : "%^GREEN%^A few tents made of animal hides are consealed behind bushes and tree trunks.",
                   "lodges" : "%^GREEN%^The lodges are built from branches and barely visible in the thick forest.",
                   "hammocks" : "%^GREEN%^Hammocks are neatly tied to the branches in the canopy above, for resting or sleeping in.",
                   "nests" : "%^GREEN%^Nests of different sizes provide shelter to small and large birds, and whoever else lives in those trees.",
                   "door" : "%^ORANGE%^The mound slopes down a bit in front of the dark wooden door, causing it to appear like a shadow in a crevasse.",
                   "smoke" : "%^WHITE%^There must be a fireplace inside the steep mound, and holes on top of it to let the smoke through.",
               ]));


}
