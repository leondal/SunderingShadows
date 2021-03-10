#include <std.h>
inherit "/std/room";

void create() {
     ::create();
     set_terrain(STONE_BUILDING);
     set_travel(PAVED_ROAD);
     set_light(3);
     set_indoors(1);
     set_short("You stand within the crystal tower of the Kinnesaruda");
     set_long("
    You stand atop a clear crystal platform that is floating high above the ground in an incredibly vast chamber with glass walls.  All around you are similar such platforms hovering in this chamber, but they are too far away to jump to.  All the platforms are clear like ice and you can see all the way to the ceiling and the floor through them.  
    Through the glass windows, you can see the entire island of Attaya and the surrounding ocean.  You feel so very tiny in here.
    Looking up, you can see where another platform overlaps this one above where you are standing.
    In the very center of the gigantic chamber is a large black cube the size of a multi-story building!  It is quite far away, though.
");
set_listen("default", "%^BOLD%^%^GREEN%^A remarkable green crystal floats here");
    set_exits(([
      "southwest" : "/d/attaya/tower/tower2",
   ] ));
   set_items(([
         "crystal" : "The crystal glistens and adds a spark of color to this otherwise transparent scene.  It shines a brilliant %^BOLD%^%^GREEN%^green%^RESET%^.",
         "cube" : "It is enormous and black.  It is suspended by four massive cables that attach to the four corners of the ceiling.  It is enormous and could easily contain a small city.",
         "walls" : "They are made of hundreds of glass panels.  You can look outside to see the entire island of Attaya and the surrounding ocean!",
         "platforms" : "They are transparent and appear to be made of quartz.  On some of them, you can see knights walking around.",
         "platform" : "The platform is transparent and appears to be made of quartz.",
    ] ));
}
void init() {
     ::init();
add_action("get_crystal", "take");
add_action("touch", "touch");
}
int get_crystal(string str) {
write("You take a crystal");
say((string)this_player()->query_cap_name()+" picks up the crystal.\n");
this_player()->move_player("/d/attaya/tower/dungeon.c");
write("%^BOLD%^%^BLUE%^You Are forced to drop the crystal as it transforms into a towering creature and smashes your head in.\n");
say((string)this_player()->query_cap_name()+" is suddenly pounded into the ground by a huge towering creature.  It then vanishes with the limp corpse.\n");
this_player()->add_hp(-(random(100)));
return 1;
}
int touch(string str) {
write("You touch the crystal and feel an electric shock.\n");
say((string)this_player()->query_cap_name()+" touches the crystal
.\n");
this_player()->move_player("/d/attaya/tower/tower69",);
return 1;
}

