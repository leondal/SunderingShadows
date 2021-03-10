#include <std.h>

inherit MONSTER;

create()
{
    ::create();
    set("aggressive", 0);
    set_name("gnarw");
    set_id(({"gnarw", "rat", "giant rat"}));
    set_short("%^RESET%^%^ORANGE%^Gnarw, a giant pack rat");
    set_long("This type of a giant rat-morph serves as a pack animal. Numerous bags hang over its sides. Giant rat is docile at the moment, its nose and teeth are buried into a pile of filth it considers food.");
    set_hd(20, 2);
}
