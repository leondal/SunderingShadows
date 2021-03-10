#include <std.h>
#include "../witchlair.h"
inherit ROOM;

void create() {
  ::create();
  set_property("light",2);
  set_property("no sticks",0);
  set_property("no teleport",0);
  set_property("no starve",0);
  set_property("no magic",0);
  set_property("no steal",0);
  set_short("%^BOLD%^%^BLACK%^D%^RESET%^%^ORANGE%^e"
"%^BOLD%^%^BLACK%^cr%^WHITE%^e%^RESET%^%^ORANGE%^p"
"%^BOLD%^%^BLACK%^it %^RESET%^%^ORANGE%^ca%^YELLOW%^n%^WHITE%^d"
"%^RESET%^%^ORANGE%^le%^WHITE%^l%^ORANGE%^it "
"%^BOLD%^%^BLACK%^cave%^RESET%^");
  set_long((: TO, "long_desc" :));
  set_smell("default","The cave smells of freshly-spilled "
"blood...");
  set_listen("default","Someone, or some-thing- can be heard "
"chanting with fervor.");
  set_items(([
     ({"torches","candles"}):"%^RESET%^%^ORANGE%^The room is"
" rather well-lit by several t%^YELLOW%^o%^RED%^r"
"%^YELLOW%^c%^RESET%^%^RED%^h%^ORANGE%^es in brackets on the "
"walls, a half-dozen of them atop iron %^BOLD%^%^BLACK%^spikes"
" %^RESET%^%^ORANGE%^in the ground, and countless clusters of "
"skull-mounted candles arranged on and around the altar.",
     "bones":"Only something as large as a whale could have "
"been the owner of these massive things. Thin "
"%^ORANGE%^hides %^WHITE%^are stretched tautly"
" between them, and only upon pausing to take in the strange"
" spectacle can you see that they are arranged to look like "
"outstretched wings, the %^ORANGE%^g%^YELLOW%^l%^WHITE%^o"
"%^RESET%^%^ORANGE%^w %^WHITE%^from scattered candles"
" casting a glow through the veiny, near-translucent material.",
     "skull":"Your first impression is that it was taken from"
" an ogre, perhaps a troll, but the thin curve of those wicked"
" canines suggest something more...fiendish. You shudder to "
"think of what.",
   "altar":"%^BOLD%^%^BLACK%^Black rock makes up the basis "
"of this crude altar, carved from the cave itself. The face "
"of the altar has been chipped away to form a (roughly) flat "
"surface for sacrifices, et cetera. It seems some poor "
"wretch has had the misfortune of partaking in one such ritual"
", and not willingly. A small, %^RESET%^%^ORANGE%^withered "
"%^RED%^corpse %^BOLD%^%^BLACK%^lies on the stone's surface, "
"still desperately clutching an amulet bearing the holy "
"symbol of %^WHITE%^Tymora%^BLACK%^.%^RESET%^",
   ]));
  set_exits(([
    "west":ROOMS"path2.c",
  ]));
}

string long_desc(){
  string desc = "%^BOLD%^%^BLACK%^You've entered a relatively large cave "
"as you leave the cramped tunnel, your vision granted mercy by a "
"plethora of %^RESET%^%^ORANGE%^t%^YELLOW%^o%^RED%^r"
"%^RESET%^%^ORANGE%^ch%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^s "
"%^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^ca%^YELLOW%^n"
"%^WHITE%^d%^YELLOW%^l%^RESET%^%^ORANGE%^es%^BOLD%^%^BLACK%^. The "
"walls to your sides extend outward to a cavern perhaps ten meters "
"wide. A handful of goblins are seen scurrying back and forth, "
"perhaps to escape your attention, perhaps carrying out the orders "
"of some master. At the opposite end of the cave is what appears to "
"be an altar, formed from the same dark stone that makes up the floor "
"and walls. Shattered spikes of %^RESET%^%^WHITE%^b%^BOLD%^o%^RESET%^ne"
" %^BOLD%^%^BLACK%^rise from the ground in a crescent beside and behind"
" the altar, the remnants of some great beast's ribcage. Some two meters"
" above the altar is the %^RESET%^%^WHITE%^b%^BOLD%^l%^RESET%^ea"
"%^BOLD%^ch%^RESET%^ed%^BOLD%^-%^RESET%^wh%^BOLD%^i%^RESET%^te skull "
"%^BOLD%^%^BLACK%^of some large, fanged humanoid. This is obviously "
"some sort of ritual site.";
  if(present("neshkir", TO)){
     desc += "..and the bone-clad, staff-waving, babbling thing at the"
" foot of the altar confirms this suspicion.%^RESET%^";
   }
   return desc;
}

void reset(){
   ::reset();
   if(!present("neshkir")){
     new(MON"shaman.c")->move(TO);
   }
}
