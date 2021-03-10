#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no teleport", 1);
    set_terrain(BARREN);
    set_travel(DECAYED_FLOOR);
    set_name("A clearing in the forest");
    set_short("%^BOLD%^%^GREEN%^A clearing in the forest%^RESET%^");
    set_long("%^BOLD%^%^GREEN%^A clearing in the forest%^RESET%^\n"
"%^RESET%^You're standing at the northern end of a small clearing that extends back to the southeast, its perimeter encircled by tall %^GREEN%^t%^ORANGE%^re%^GREEN%^es %^RESET%^on all sides.  "
"Within the clearing itself, scattered about atop the %^ORANGE%^o%^RED%^c%^ORANGE%^h%^RED%^r%^ORANGE%^e %^RESET%^earth and the scrappy patches of %^BOLD%^%^GREEN%^g%^YELLOW%^r%^BOLD%^%^WHITE%^a"
"%^BOLD%^%^GREEN%^ss%^RESET%^, are a series of wooden huts.  Simple in design but sturdy nonetheless, they are showing a few telltale signs of their age and abandonment.  No sign remains to "
"hint at where those that might once have inhabited them, have gone.  A little further to the north, over the treetops, you can make out the uppermost reaches of a tall stone %^BLUE%^building"
"%^RESET%^, and you suspect the %^BOLD%^%^BLACK%^cr%^RESET%^a%^BOLD%^%^BLACK%^ck%^RESET%^e%^BOLD%^%^BLACK%^d %^RESET%^stone path leading away in that direction might take you to it.  It is very "
"%^MAGENTA%^quiet %^RESET%^here, though the silence is broken by an occasional rustle, or the eerie wailing call of some distant creature.\n");

    set_smell("default","The air is crisp and clear.");
    set_listen("default","Only the occasional rustle of leaf or the call of an unseen creature breaks the silence.");
    set_exits( ([
        "southeast" : "/d/hm_quest/rooms/quest11",
        "north" : "/d/hm_quest/rooms/quest13",
    ]) );
    set_items(([
      ({ "building", "stone building" }) : "%^RESET%^The uppermost reaches of an %^BLUE%^omin%^GREEN%^o%^BLUE%^us %^RESET%^building of stone loom over the treeline further to the north, its "
"walls cracked and darkened with age, while %^GREEN%^moss %^RESET%^and %^BOLD%^%^GREEN%^v%^YELLOW%^i%^BOLD%^%^GREEN%^nes %^RESET%^climb as they will upon its every surface.",
      ({ "trees", "forest", "bushland" }) : "%^RESET%^Ancient trees encircle the clearing all sides, their branches clawing towards the sky and their %^GREEN%^fo%^BOLD%^l%^YELLOW%^i%^RESET%^"
"%^GREEN%^a%^ORANGE%^g%^GREEN%^e %^RESET%^obscuring nearly any passage out of the clearing.  They seem of a kind not found elsewhere, their %^BOLD%^%^WHITE%^gh%^RESET%^o%^BOLD%^%^BLACK%^s"
"%^RESET%^t%^BOLD%^%^WHITE%^ly %^RESET%^trunks of white and gray and black standing in stark contrast to the vibrant hue of their leaves.",
      ({ "grass", "earth", "soil", "clearing" }) : "%^RESET%^Patches of straggling %^BOLD%^%^GREEN%^g%^WHITE%^r%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^s%^RESET%^ sprout in patches "
"across the clearing, breaking up the rich %^ORANGE%^o%^RED%^c%^ORANGE%^h%^RED%^r%^ORANGE%^e %^RESET%^coloration of the soil.",
      "huts" : "%^RESET%^Scattered across the clearing are a number of huts, all created of %^GREEN%^n%^CYAN%^at%^GREEN%^u%^ORANGE%^r%^RED%^a%^ORANGE%^l %^RESET%^materials.  Wooden branches "
"serve as a simple but sturdy frame for the twigs and grass thatching that make up the body of the constructions.  Some are spotted with patches of %^GREEN%^moss %^RESET%^and %^BLUE%^rot"
"%^RESET%^, or have holes or completely broken sections, leading you to wonder how long their inhabitants might have been gone.  Indeed, there seems no sign of where they might've gone, as "
"there are pieces of rough clothing and simplistic furniture still left in place inside each building.",
      (({ "path", "stone path", "cracked stone path", "cracked path" })) : "%^RESET%^A path paved in flat stones leads away through the trees to the north, towards the %^BLUE%^looming %^RESET%^"
"building beyond.  Patches of %^BOLD%^%^GREEN%^g%^YELLOW%^r%^BOLD%^%^WHITE%^a%^BOLD%^%^GREEN%^ss%^RESET%^ have grown up between the stones, cracking some and almost completely covering others, "
"making the path uneven to walk upon.",
    ]));
    add_pre_exit_function("north","GoThroughDoor");
}

int GoThroughDoor() {
    tell_object(TP,"%^BOLD%^%^WHITE%^You set out on the rough path to the north, approaching the looming stone building.%^RESET%^");
    return 1;
}