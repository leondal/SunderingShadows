#include <std.h>
inherit "/d/attaya/base/spec/oubliette";

void create() {
     ::create();
     set_light(3);
     set_indoors(1);
     set_short("Atop a pillar in the crystalline tower");
     set_long("
    You are standing atop one of the large marble pillars in the reflection pool.  There is quite a view from up here and you take a moment to look over your surroundings.  At your back is the northern wall of the crystalline tower and the reflection pool stretches out before you.  To the southeast, hundreds of wyverns scurry around the central platform.
    %^BLUE%^A dazzling black crystal floats here, surrounded by a deep purple aura of magic.  The crystal is secured in one spot by chains that rise from the floor!  You cannot take it.
    %^RESET%^
    Your boat bobs in the water beneath you.
");
set_listen("default", "It is quiet and serene up here.\n");
set_items( ([
        "pool" : "The reflection pool is remarkable and reflects the entire room.",
        "platform" : "The grand central platform is not too far away to the southeast.  Wyverns move about upon it.",
        "fortress" : "The southern wall fortress stands to a height of about 15 stories.  Archers watch you from it's openings.",
        "crystal" : "The mysterious dark crystal has tremendous power.  You cannot take it, but you could touch it.  You wonder about how good an idea that would be, however...",
        "chains" : "The chains are tremendous, like the ones that secure anchors on large sailing ships.",
        "floor" : "The floor beneath you is the top of the massive pillar.  It is quite smooth.",
        "archers" : "The archers watch you carefully from the distant fortress wall.",
        "ladder" : "The ladder is a fairly new steel runged ladder with no rust."
]) );
}
void init() {
     ::init();
add_action("climb_boat", "climb");
add_action("touch", "touch");
}
int climb_boat(string str) {
write("%^BOLD%^You climb down the ladder into the small boat.\n");
say((string)this_player()->query_cap_name()+" climbs down the ladder to the small boat.\n");
this_player()->move_player("/d/attaya/base/pool6");
write("%^CYAN%^The small boat rocks wildly.");
return 1;
}
int touch(string str) {
           object ob;
write("You reluctantly touch the dark crystal.\n");
write("%^BOLD%^%^CYAN%^You feel a sudden shock of electricity sting you!\n"
      "%^BOLD%^%^RED%^A shadowy presence tells you: %^RESET%^Do not be afraid.\n"
      "%^MAGENTA%^Your body shatters into a billion tiny spheres of purple light!\n"
);
say((string)this_player()->query_cap_name()+" is suddenly magically transformed into a cloud of purple spheres of light and carried up to one of the platforms above you.
.\n");
write("%^BOLD%^%^CYAN%^You begin to float upwards, and the reflection pool beneath you grows cloudy and faint until it is only a blueish smudge far below.  You speed past hundreds of small crystalline platforms.\n");
this_player()->move_player("/d/attaya/tower/tower12",);
write("%^BOLD%^%^MAGENTA%^Your body reconstructs itself and you feel a tad disoriented.");
return 1;
}

