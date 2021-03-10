#include <std.h>
#include "../inherit/ruins.h"
inherit VAULT;

void create() {
    ::create();
    set_terrain(OLD_MOUNTS);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
    set_property("light",2);
    set_name("Before an old building");
    set_short("%^ORANGE%^Before an old building%^RESET%^");
    set_smell("default","Clean, fresh mountain air wafts on the breeze.");
    set_listen("default","Occasional gusts of wind whistle through the stones.");
    set_long("%^GREEN%^Within this opening between the mountain peaks stands a grand building, of a very "
"old and archaic design.   The %^ORANGE%^dirt path%^GREEN%^ at your feet meets with the building's "
"entrance, barred by a pair of great %^BLACK%^%^BOLD%^ashen doors%^RESET%^%^GREEN%^.  A few tendrils of "
"%^WHITE%^ivy%^GREEN%^ creep across its stone walls, in which "
"%^MAGENTA%^mu%^BLUE%^lt%^GREEN%^ic%^ORANGE%^ol%^RED%^ou%^MAGENTA%^re%^BLUE%^d%^GREEN%^ glass windows "
"are set at regular intervals, though they are %^BLACK%^%^BOLD%^blackened%^RESET%^%^GREEN%^ with age.  "
"It looks as though it has been abandoned for a long time.%^RESET%^\n");
   set("night long","%^BLUE%^Within this opening between the shadow-swept mountain peaks stands a grand "
"building, of a very old and archaic design.   The %^ORANGE%^dirt path%^BLUE%^ at your feet meets with "
"the building's entrance, barred by a pair of great %^BLACK%^%^BOLD%^ashen doors%^RESET%^%^BLUE%^.  A "
"few tendrils of %^WHITE%^ivy%^BLUE%^ creep across its stone walls, in which "
"%^MAGENTA%^mu%^BLUE%^lt%^GREEN%^ic%^ORANGE%^ol%^RED%^ou%^MAGENTA%^re%^BLUE%^d%^BLUE%^ glass windows "
"are set at regular intervals, though they are %^BLACK%^%^BOLD%^blackened%^RESET%^%^BLUE%^ with age.  "
"It looks as though it has been abandoned for a long time.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"path1",
      "south" : ROOMS+"entry"
    ]));
    set_items(([
      ({"path","trail","pathway"}) : "%^GREEN%^The path is very narrow here, and only vaguely defined.  "
"It is little more than a trail of %^ORANGE%^dirt%^GREEN%^, leading up to the building's tall "
"%^BLACK%^%^BOLD%^ashen doors%^RESET%^%^GREEN%^.%^RESET%^.",
      ({"tree","trees","pines","pinetrees"}) : "%^GREEN%^The %^BOLD%^trees%^RESET%^%^GREEN%^ have parted "
"here, no longer lining the edges of the pathway.  Several groups cluster together upon the rocky "
"slopes, thinning to only a few sparse pines upon the mountainsides.",
      ({"brush","undergrowth","bushes"}) : "%^GREEN%^Thinned brush still covers the mountain slopes, "
"though it seems to be struggling to grow here.  Only scattered patches of %^RED%^holly%^GREEN%^ bushes "
"dot the rocky incline, mingled with a few vines of twisting %^WHITE%^ivy%^GREEN%^ that have begun to "
"grow over the building's walls.%^RESET%^",
      ({"rocks","stones","rock","stone","boulder","boulders"}) : "%^BLACK%^%^BOLD%^Boulders "
"%^RESET%^%^GREEN%^of all sizes are strewn haphazardly across the mountain slopes, making any travel "
"away from the path very difficult.  A few small rocks have fallen onto the %^ORANGE%^path%^GREEN%^, "
"which has probably not been tended in quite some time.%^RESET%^",
      "doors" : "%^GREEN%^Two great %^BLACK%^%^BOLD%^ash doors%^RESET%^%^GREEN%^ tower almost to "
"the roof, set in the northern wall.  An ornate %^ORANGE%^brass handle%^GREEN%^ is affixed to "
"each.%^RESET%^",
     ({"building","cathedral"}) : "%^GREEN%^Before you stands a grand building, that looks as though it "
"were abandoned long ago.  It is of an old archaic design, with great stone walls and "
"%^MAGENTA%^mu%^BLUE%^lt%^GREEN%^ic%^ORANGE%^ol%^RED%^ou%^MAGENTA%^re%^BLUE%^d%^GREEN%^ glass windows.  "
"Trailing vines of %^WHITE%^ivy%^GREEN%^ have grown up over many of the walls.%^RESET%^"
    ]));
    set_door("great doors",ROOMS+"entry","south",0);
    set_door_description("great doors","%^GREEN%^Two great %^BLACK%^%^BOLD%^ash doors%^RESET%^%^GREEN%^ "
"tower almost to the roof, set in the northern wall.  An ornate %^ORANGE%^brass handle%^GREEN%^ is "
"affixed to each.%^RESET%^");
    set_string("great doors","open","The doors swing open silently.");
    set_string("great doors","close","The doors click shut without a sound.");
}

void reset() {
    ::reset();
    if(!present("sionne")) {
      tell_room(TO,"%^WHITE%^%^BOLD%^Pale mists coalesc in the air, forming the translucent outline of a "
"spirit.%^RESET%^");
      new(MON+"sionne")->move(TO);
    }
}
