#include <std.h>
inherit "/std/room";

void create() {
     ::create();
     set_terrain(STONE_BUILDING);
     set_travel(PAVED_ROAD);
   set_light(3);
   set_property("no teleport",1);
     set_indoors(1);
     set_short("Atop the black structure...  The heart of the Kinnesaruda");
     set_long("
    You are shocked to find yourself on top of the enormous black structure at the very center of the Crystalline Tower of the Black Dawn.  Once again, you can hardly believe the size of the place.  Crystal platforms glimmer around you and a thin mist hangs in the air here.
    The floor beneath you is marked with a series of symbols and a large black pylon beside you holds a brass lever and a warning.  Your heart is pounding within your chest.

%^BOLD%^%^BLUE%^A great battle looms ahead.
%^RESET%^
    Through the glass windows, you can see the entire island of Attaya and the surrounding ocean.  You feel so very tiny in here.
");
set_listen("default", "%^BLUE%^A remarkable dark crystal floats here");
   set_items(([
         "crystal" : "The crystal glistens and adds a spark of color to this otherwise transparent scene.  It shines a brilliant %^BLUE%^ebony hue",
         "cube" : "It is enormous and black.  It is suspended by four massive cables that attach to the four corners of the ceiling.  It is enormous and could easily contain a small city.",
         "walls" : "They are made of hundreds of glass panels.  You can look outside to see the entire island of Attaya and the surrounding ocean!",
         "platforms" : "They are transparent and appear to be made of quartz.  On some of them, you can see knights walking around.",
         "platform" : "The platform is transparent and appears to be made of quartz.",
          "floor" : "The floor beneath you is dark, and made of metal that you don't recognize.  Hundreds of symbols are printed in it's surface.",
          "symbols" : "You cannot read the language, but it is the same two phrases repeated over and over again!",
          "warning" : "The sign has been haphazardly carved into the face of the pylon.",
    ] ));
}
void reset() {
  ::reset();
    if(!present("pylon"))
      new("d/attaya/tower/obj/pylon")->move(this_object());
}
void init() {
     ::init();
add_action("pull", "pull");
add_action("touch", "touch");
}
int pull(string str) {
write("You pull the lever on the pylon");
say((string)this_player()->query_cap_name()+" pulls the lever on the pylon.\n");
this_player()->move_player("/d/attaya/tower/hall2.c");
write("%^BOLD%^%^BLUE%^The floor beneath you lowers.\n");
say((string)this_player()->query_cap_name()+"vanishes as the floor beneath them lowers to the level below.\n");
this_player()->add_hp(random(500));
write("%^BOLD%^%^CYAN%^You pass through a field of glimmering light that sooths and heals your tired body.");
return 1;
}
int touch(string str) {
write("You touch the crystal and feel an electric shock.\n");
say((string)this_player()->query_cap_name()+" touches the crystal.\n");
this_player()->move_player("/d/attaya/tower/tower61",);
return 1;
}
