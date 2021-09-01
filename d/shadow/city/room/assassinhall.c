#include "../defs.h"

inherit INH+"assassin";
inherit "/std/bounty.c";

void create()
{
    set_short("%^BOLD%^%^BLACK%^A Dark Hall%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^A Dark Hall%^RESET%^
%^RESET%^%^ORANGE%^This dingy, dark hall is held together by %^GREEN%^d%^ORANGE%^e%^BOLD%^%^BLACK%^c%^RESET%^%^GREEN%^ayi%^ORANGE%^n%^GREEN%^g, w%^ORANGE%^e%^GREEN%^t s%^ORANGE%^t%^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^n%^ORANGE%^e%^GREEN%^s %^ORANGE%^overrun by %^GREEN%^c%^ORANGE%^r%^GREEN%^e%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^p%^GREEN%^in%^BOLD%^%^BLACK%^g%^RESET%^%^GREEN%^, %^BOLD%^%^BLACK%^s%^RESET%^%^ORANGE%^u%^GREEN%^bte%^ORANGE%^r%^GREEN%^ran%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^a%^GREEN%^n m%^ORANGE%^o%^BOLD%^%^BLACK%^s%^RESET%^%^GREEN%^s%^ORANGE%^, and a prayer. Water seeps in through its cracks, pooling in the corners and coating the floor in a thin coating of slick sludge. Below, the staircase ends in a pool of cold, %^BOLD%^%^BLACK%^fetid wat%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^r %^RESET%^%^ORANGE%^rising up from the sunken lower levels of the structure. Moldy, %^MAGENTA%^old %^GREEN%^f%^MAGENTA%^in%^RED%^e%^GREEN%^r%^MAGENTA%^y %^ORANGE%^clings to the walls in damp threads, a testament to both the former grandeur of this tower, and its current state of disrepair. The room is very dim, with only a few %^BOLD%^%^BLACK%^low-burning torches %^RESET%^%^ORANGE%^to brighten it. \n%^BOLD%^There is a board here, accompanied by a small sign.\n%^RESET%^
");
    set_smell("default","%^BOLD%^%^GREEN%^The air is thick with the scent of d%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^m%^GREEN%^p de%^BLACK%^c%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^y.%^RESET%^");
    set_listen("default","%^BOLD%^%^BLACK%^Water trickles.%^RESET%^");
    set_items(([
                   ({"floor","wall","ceiling"}) : "%^RESET%^%^ORANGE%^Dark stones, resilient but old, hold together this sunken tower. The persistent dampness from the flowing river outside of the crumbling walls allows for %^BOLD%^%^GREEN%^gr%^RESET%^%^ORANGE%^e%^GREEN%^e%^BOLD%^n m%^RESET%^%^GREEN%^o%^ORANGE%^s%^BOLD%^%^GREEN%^s %^RESET%^%^ORANGE%^to flourish between the cracks. %^CYAN%^Water %^ORANGE%^trickles in and pools in the corners of the uneven floors, making every slippery step seem perilous.%^WHITE%^",
                   "finery" : "%^RESET%^%^MAGENTA%^What was probably once fine tapestries have long ago unraveled and been forgotten by those who dwell here.%^WHITE%^",
                   ({"sign","board"}) : "%^RESET%^%^ORANGE%^The board is a list of bounties, and the sign details its use. You can read either for more details.%^RESET%^",
                   "torches" : "%^YELLOW%^The torches burn low, giving off neither much light or warmth.%^RESET%^",
                   ({"staircase","stairs","water"}) : "%^RESET%^%^CYAN%^The stairs come to an abrupt end where the river is constantly eroding away at their collapsed remains. The water is cold, dark and full of shifting shadows from the deep. There is no way to proceed from here, and no good reason to want to try.%^WHITE%^",
                   ]));
    set_property("no teleport",1);
    set_exits(([
                   "up":ROOMS+"/assassinentr",
                   "north":ROOMS+"/assassintrader",
                   "west":ROOMS+"/assassinportals",
                   "south":ROOMS+"/assassinalchemist",
                   "east":ROOMS+"/assassinscrolls",
                   ]));
}
