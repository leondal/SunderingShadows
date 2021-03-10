#include <std.h>
#include "../witchlair.h"
inherit ROOM;
inherit VAULT;

void create() {
  ::create();
  set_property("light",2);
  set_property("no sticks",0);
  set_property("no teleport",0);
  set_property("no starve",0);
  set_property("no magic",0);
  set_property("no steal",0);
  set_short("%^RESET%^%^GREEN%^Outside of a large "
"%^ORANGE%^hut%^RESET%^");
  set_long("%^RESET%^%^GREEN%^Outside of a large "
"%^ORANGE%^hut%^RESET%^\n\n"
"%^RESET%^%^GREEN%^You're currently standing in what appears "
"to be a campground, just outside of a large %^ORANGE%^wooden "
"hut%^GREEN%^. Small, ramshackle tents line the outside of an "
"area of bare ground some fifteen meters wide, a smoldering "
"%^ORANGE%^c%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^m"
"%^BOLD%^%^RED%^p%^YELLOW%^f%^RESET%^%^RED%^i%^ORANGE%^re "
"%^GREEN%^in its center. A large %^BOLD%^%^BLACK%^pot "
"%^RESET%^%^GREEN%^is suspended over the fire by a wood frame. "
"%^BOLD%^%^WHITE%^Bones %^RESET%^%^GREEN%^and %^RESET%^h"
"%^ORANGE%^a%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^f%^GREEN%^-"
"%^RED%^ea%^BOLD%^%^RED%^t%^RESET%^%^ORANGE%^e%^RED%^n "
"%^ORANGE%^animal %^RED%^ca%^MAGENTA%^r%^BOLD%^%^RED%^ca"
"%^RESET%^%^RED%^ss%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^s "
"%^GREEN%^litter the ground here - something unpleasant lives "
"in this place.");
  set_smell("default","The smell of decay is overwhelming.");
  set_listen("default","You hear nothing but flies swarming "
"over the rotting corpses.");
  set_items(([
    "tents" : "No less than two dozen of them. It sounds as "
"though some may be occupied...better not wake the sleepers!",
    "hut" : "%^GREEN%^The size of a small inn, it's made "
"mostly of darkened logs from the trees nearby. Dead grass is "
"woven into a thick mass to serve as the roof. You can see a "
"small window in the wall, but it appears covered by something.",
    ({"bodies","corpses","carcasses"}) : "%^RED%^Absolutely "
"disgusting. It seems anything that passes through, from "
"rabbits and deer to even a bear or two, falls victim to "
"whatever fell beasts make camp here.",
    "bones" : "%^BOLD%^%^WHITE%^Every one of them has been "
"picked perfectly chalk-white clean and covered in tiny "
"teeth-marks.",
    ({"fire","campfire"}) : "It's quite big. Somewhere between"
" four and five feet wide; you can't get close enough to "
"determine precisely - it's still too %^BOLD%^%^RED%^hot"
"%^RESET%^! A large %^BOLD%^%^BLACK%^pot %^RESET%^hangs over "
"it.",
    "pot" : "%^BOLD%^%^BLACK%^A fairly big cast-iron pot. "
"The smell emerging from it is quite foul, and you'd rather "
"not find out what's inside.",
  ]));
  set_exits(([
    "southwest":"/d/dagger/marsh/witchlair/rooms/clearing8",
    "west":"/d/dagger/marsh/witchlair/rooms/clearing6",
    "northwest":"/d/dagger/marsh/witchlair/rooms/clearing3",
    "north":"/d/dagger/marsh/witchlair/rooms/clearing4",
    "south":"/d/dagger/marsh/witchlair/rooms/clearing9",
    "hut":"/d/dagger/marsh/witchlair/rooms/hut",
  ]));
  set_door("oaken door","/realms/aurgloroasa/apparea/rooms/hut","hut",0);
  set_door_description("oaken door","%^RESET%^%^ORANGE%^Heavy "
"oaken planks run horizontally rather than vertical. A fist-"
"sized %^BOLD%^%^BLACK%^knocker %^RESET%^%^ORANGE%^of some "
"dark stone rests in the center of the door, shaped like a "
"bat-winged skull, with the ring clamped in the skull's "
"teeth. Small %^CYAN%^r%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^n"
"%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^ORANGE%^are carved "
"into the frame, perhaps as some form of warding.");
}
