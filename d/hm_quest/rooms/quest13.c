#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no teleport", 1);
    set_terrain(BARREN);
    set_travel(DECAYED_FLOOR);
    set_name("A path approaching the stone building");
    set_short("%^RESET%^%^CYAN%^A path approaching the stone building%^RESET%^");
    set_long("%^RESET%^%^CYAN%^A path approaching the stone building%^RESET%^\n"
"%^RESET%^You stand upon a cracked and overgrown path, leading away from the clearing towards the uppermost %^BOLD%^%^BLACK%^r%^RESET%^oc%^BOLD%^%^BLACK%^k%^RESET%^y c%^ORANGE%^l%^RESET%^if"
"%^BOLD%^%^BLACK%^f%^RESET%^s of this island.  The %^RED%^ri%^ORANGE%^c%^RED%^h %^RESET%^earth that had been underfoot previously has given way to hard, unyielding stone, with even the dense "
"%^GREEN%^f%^ORANGE%^o%^GREEN%^r%^ORANGE%^es%^GREEN%^t %^RESET%^thinning before the stark outcropping ahead.  The path itself ends at the foot of the looming building before you, which has "
"finally come into full view from behind the trees you've now passed.  The building itself, despite its crumbling and moss-covered exterior, still bears an air of %^MAGENTA%^importance "
"%^RESET%^and %^CYAN%^majesty %^RESET%^as though you'd stepped upon hallowed grounds, setting it apart from anything else you've yet seen since landing upon the shore below.  The quiet serenity "
"of the rest of the island has given way to a deathly %^BLUE%^silence %^RESET%^here, so that even your own breathing seems loud in your ears.\n");

    set_smell("default","The air is crisp and clear.");
    set_listen("default","It is perfectly silent here.");
    set_exits( ([
        "south" : "/d/hm_quest/rooms/quest12",
        "temple" : "/d/hm_quest/rooms/quest14",
    ]) );
    set_items(([
      ({ "building", "stone building" }) : "%^RESET%^An %^BLUE%^ominous %^RESET%^building looms before you, finally revealed from amidst the receding tree-line at either side.  Its walls are "
"cracked and darkened with age, while %^GREEN%^moss %^RESET%^and %^BOLD%^%^GREEN%^v%^YELLOW%^i%^BOLD%^%^GREEN%^nes %^RESET%^climb as they will upon its every surface.  Still, despite this, it "
"bears an aura of %^CYAN%^my%^MAGENTA%^s%^CYAN%^ti%^MAGENTA%^qu%^CYAN%^e %^RESET%^unlike anything else you've seen on this island, as though you stand before hallowed ground.",
      ({ "trees", "forest" }) : "%^RESET%^Ancient %^GREEN%^t%^ORANGE%^re%^GREEN%^es %^RESET%^frame the path at either side, though they lag back away from the stark stone that rears up at the "
"path's end, as though keeping their distance from the %^BLUE%^looming %^RESET%^building that stands there.",
      ({ "grass", "earth", "stone", "outcropping", "cliffs", "rocky cliffs" }) : "%^RESET%^The patches of straggling %^BOLD%^%^GREEN%^g%^WHITE%^r%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^s%^BOLD%^"
"%^GREEN%^s%^RESET%^ that once spotted the ground and sprouted from amidst the flagstones finally fade out, nothing able to grow upon the rugged stone of the ground before the building.",
      (({ "path", "stone path", "cracked stone path", "cracked path" })) : "%^RESET%^A path paved in flat stones leads away from the clearing behind you, through the trees towards the %^BLUE%^"
"looming %^RESET%^building ahead.  Further back, patches of %^BOLD%^%^GREEN%^g%^YELLOW%^r%^BOLD%^%^WHITE%^a%^BOLD%^%^GREEN%^ss%^RESET%^ have grown up between the stones, cracking some and "
"almost completely covering others, though the earth hardens to solid rock ahead and nothing seems able to grow there.",
    ]));
    add_pre_exit_function("south","GoThroughDoor");
    add_pre_exit_function("temple","GoThroughDoor");
    set_post_exit_functions(({"temple"}),({"doorshut"}));
}

void doorshut() {
    tell_object(TP,"%^BLUE%^A soft thud echoes around the room as the heavy doors to the temple swing closed behind you.");
}

void init() {
    ::init();
    if(!interactive(TP) || avatarp(TP)) return;
    if(!present("monster999")) { new("/d/hm_quest/mon/quest_monster.c")->move(TO); }
}

int GoThroughDoor() {
    if(!present("hm_quest_mon",TO)) return 1;
    tell_object(TP,"The shadow shifts with ease to block your passage!");
    return 0;
}