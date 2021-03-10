#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Tiamats Lair");
   set_short("%^RESET%^%^ORANGE%^Tiamats Lair%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^You are standing within a cavern of immense proportions, deep underground in "
"an unknown plane of the multiverse.  Scarce light is provided by torches and small bonfires.  Their glow "
"bounces off a trinket here or there and softly illuminates an impossibly large %^BOLD%^hoa%^RED%^r%^ORANGE%^"
"d%^RESET%^%^ORANGE%^ of treasure.  As your vision slowly adjusts you begin to pick out smaller details: "
"%^WHITE%^bones %^RESET%^%^ORANGE%^litter the ground.  Stalactites and stalagmites form a natural %^BOLD%^"
"prison%^RESET%^%^ORANGE%^ used to house unknown horrors.  Legendary treasures are scattered thoughtlessly "
"around.  Off to the corner, light trickles off the surface of a large %^GREEN%^acidic %^BOLD%^pool%^RESET%^"
"%^ORANGE%^.  Statues and artwork are strewn about, jealously hoarded but rarely appreciated.  Armaments lay "
"broken and rusting, testament of failed attempts to separate a dragon from her belongings.\n%^RESET%^");
   set_smell("default","%^BOLD%^%^BLACK%^Your senses are stifled by smoke and a heavy, acidic smell.%^RESET%^");
   set_listen("default","%^MAGENTA%^You hear the crunch of bone and coinage under your movements.%^RESET%^");

   set_items(([
     ({"hoard"}) : "%^ORANGE%^The hoard of treasure rises impossibly large, amounting to a pile about the size "
"of a large mansion.  It is composed primarily of mixed coinage from throughout the ages.  Besides coins, the "
"hoard also contains gems, and precious metalwork of all kinds.  A huge depression is formed in the center of "
"the hoard, providing enough room for a full grown dragon to rest.%^RESET%^",
     ({"bones", "bone" }) : "%^BOLD%^%^BLACK%^The remains of many creatures are strewn about the lair, giving "
"the whole place a menacing feel.  Most of the bones are from humanoids.  Some are charred with fire or "
"electricity, others burned by acid.  Still more are seem that have been stripped completely, others that "
"have flesh frozen to the bone forever.%^RESET%^",
      ({"prison", "stalactites" }) : "%^ORANGE%^The stalactites and stalagmites here form a natural network of "
"rocky bars.  The master of this lair keeps a variety of beasts here in the shadows.  Perhaps they are for "
"eating, or experimenting.%^RESET%^",
      ({"pool", "acid" }) : "%^GREEN%^This is a deep, seemingly natural pool of thick, green ooze.  It burns "
"the nostrils with acidic vapors as you investigate.  Judging by the many shed, platter-sized dragon scales "
"found around the pool, it is probably used for gruesome grooming.%^RESET%^",
   ]));
   set_exits(([
   "keep" : "/d/av_rooms/tiamat/tiamatbasement1",
   "complex" : "/d/av_rooms/tiamat/complex",
   ]));
}
