//little side path, elven ritual plot & permanent addition to retain lore. N, 3/15.
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("Before the Gates");
    set_short("%^RESET%^%^GREEN%^Before the Gates%^RESET%^");
    set_long("%^GREEN%^The %^ORANGE%^branches %^GREEN%^of the trees close in around you, and soon they are twined so tightly together that your passage would be blocked were it not for the "
"large %^BOLD%^%^BLACK%^wrought iron gates %^RESET%^%^GREEN%^before you. The cold iron is %^ORANGE%^c%^GREEN%^a%^ORANGE%^mo%^GREEN%^u%^ORANGE%^f%^GREEN%^l%^ORANGE%^ag%^GREEN%^e%^ORANGE%^d "
"%^GREEN%^beneath encroaching %^BOLD%^ivy %^RESET%^%^GREEN%^and untamed %^BOLD%^%^RED%^r%^RESET%^%^RED%^e%^BOLD%^d r%^RESET%^%^RED%^o%^BOLD%^s%^RESET%^%^RED%^e%^BOLD%^s%^RESET%^%^GREEN%^. "
"Beyond the gate you can see %^BOLD%^%^WHITE%^a white stone walkway %^RESET%^%^GREEN%^leading through %^BOLD%^lush gardens%^RESET%^%^GREEN%^, and you can hear the unmistakable splash of a "
"%^CYAN%^fountain%^GREEN%^. You sense this place of beauty before you is one of great power and reverence%^GREEN%^, and you must ask yourself if you belong here... The weight of the unseen eyes "
"upon you is %^BOLD%^palpable %^RESET%^%^GREEN%^now.%^RESET%^\n");
    set_smell("default","%^BOLD%^%^GREEN%^You smell the fresh scent of %^RED%^r%^RESET%^%^RED%^o%^BOLD%^s%^RESET%^%^RED%^e%^BOLD%^s%^GREEN%^.%^RESET%^");
    set_listen("default","%^RESET%^%^CYAN%^A %^BOLD%^fountain %^RESET%^%^CYAN%^splashes somewhere in the distance.%^RESET%^");

    set_exits(([
      "southwest" : "/d/dagger/road/elfglade/elfglade3",
      "gate" : "/d/dagger/road/elfglade/elfglade1",
    ]));
    set_invis_exits(({"southwest"}));

    set_items(([
      "branches" : ({"%^GREEN%^Branches close in around you on all sides, leaving you to wonder if you should go back. A single word scratched into one of them catches your eye.%^RESET%^","\n\n%^BOLD%^%^WHITE%^~ southwest ~%^BOLD%^%^WHITE%^","elven"}),
      "gate" : "%^BOLD%^%^BLACK%^The gate is cast from black iron but seems to have dulled over time. The dark metal would seem foreign in this place of nature were it not for the delicate ivy "
"and red roses obfuscating it.%^RESET%^",
      "ivy" : "%^BOLD%^%^GREEN%^The ivy is green and healthy.%^RESET%^",
      "roses" : "%^BOLD%^%^GREEN%^The red roses grow wild and large here, giving off a wonderfully perfumed scent.%^RESET%^",
      ({ "garden", "walkway" }) : "%^BOLD%^%^GREEN%^Many varieties of flowers grow wild within the garden beyond the gates, painting the grove in a rainbow of colors and giving off a "
"wonderfully fresh scent. A walkway made of gleaming white stone meanders its way through the grove.%^RESET%^",
    ]));
}
