
#include <std.h>
#include <objects.h>

#include <std.h>
#include <objects.h>


inherit DOCK;

int is_virtual() { return 1; }

int is_water() { return 1; }

int is_dock() { return 1; }

void create() {
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_property("indoors",0);
  set_terrain(BARREN);
  set_travel(DECAYED_FLOOR);

  set_short("%^BOLD%^%^WHITE%^An ivory dock on a pristine beach.%^RESET%^");

  set_long("%^BOLD%^%^WHITE%^A %^CYAN%^spa%^RESET%^%^CYAN%^rkl%^BOLD%^ing %^WHITE%^and"
" %^RESET%^%^CYAN%^calm sou%^BOLD%^thea%^RESET%^%^CYAN%^stern %^BOLD%^sea %^WHITE%^meets the"
" pristine %^RESET%^w%^BOLD%^hit%^RESET%^e %^BOLD%^sands of the beach here, from which a"
" long ivory dock juts out.  The sprawling dock seems to be large enough to accomodate most any size"
" ship and has %^RESET%^%^CYAN%^lanterns %^BOLD%^%^WHITE%^evenly spaced along"
" its length, casting a"
" %^RESET%^%^CYAN%^s%^BOLD%^o%^RESET%^%^CYAN%^ft gl%^BOLD%^o%^RESET%^%^CYAN%^w"
" %^BOLD%^%^WHITE%^whether it is day or night.  To the east, the %^RESET%^%^CYAN%^sea"
" %^BOLD%^%^WHITE%^disappears into the horizon in a broad expanse of"
" %^CYAN%^tu%^RESET%^%^CYAN%^rq%^BOLD%^oise wa%^RESET%^%^CYAN%^t%^BOLD%^ers%^WHITE%^, while to"
" the west, the edges of a %^RESET%^%^GREEN%^magestic forest %^BOLD%^%^WHITE%^springs high into"
" into the air, with each %^RESET%^%^GREEN%^tree %^BOLD%^%^WHITE%^seeming to raise its"
" %^GREEN%^bows %^WHITE%^towards the heavens above.  The northern end of this cove is blocked off by"
" an imposing %^BLACK%^cliff face %^WHITE%^that casts a long %^BLACK%^shadow %^WHITE%^over the beach. \n");

   set_items(([
  "sea":"%^BOLD%^%^CYAN%^The vast expanse of sparkling blue waters disappears into the horizon%^RESET%^.",
  "forest":"%^RESET%^%^GREEN%^To the west, a %^BOLD%^magestic forest"
" %^RESET%^%^GREEN%^rises towards the %^CYAN%^heavens%^GREEN%^.  Multitudes of colors"
" ranging from the %^BOLD%^light green %^RESET%^%^GREEN%^of new %^BOLD%^forest growth"
" %^RESET%^%^GREEN%^to the %^BOLD%^da%^RESET%^%^GREEN%^rke%^BOLD%^r"
" g%^RESET%^%^GREEN%^ree%^BOLD%^n %^RESET%^%^GREEN%^of more mature trees form patterns"
" of %^CYAN%^health %^GREEN%^and %^CYAN%^radiance %^GREEN%^against the western horizon.",
  ({"dock", "ivory dock"}):"%^BOLD%^%^WHITE%^Sprouting from the %^CYAN%^crystalline sea %^WHITE%^itself, the spiralling supports"
" of this %^RESET%^ivory dock %^BOLD%^twist and turn around one another in their ascent before spreading fingerlike tips to support "
"the pier itself; a flat piece of %^RESET%^uncarved ivory %^BOLD%^that juts well over ninety meters out from the pristine sands of the"
" beach.  Regular intervals are marked with ivory posts covered in %^RESET%^%^GREEN%^vines %^BOLD%^%^WHITE%^grown from ivory pots at their base.  Each"
" post splits at the top, curling outward in opposite direction to support two lanterns that %^RESET%^%^CYAN%^illuminate %^BOLD%^%^WHITE%^the dock"
" in a %^RESET%^%^CYAN%^soft gl%^BOLD%^o%^RESET%^%^CYAN%^w %^BOLD%^%^WHITE%^whether it is day or night.%^RESET%^",
  "cliff":"%^BOLD%^%^BLACK%^A long shadow from this large cliff looms over the beach here, seeming to cast it in a perpetual twilight.  Twisted"
" %^RESET%^%^ORANGE%^roots %^BOLD%^%^BLACK%^and %^RESET%^%^GREEN%^thick vine %^BOLD%^%^BLACK%^completely cover the face of the cliff.",
  ({"vines", "roots"}):"%^RESET%^%^GREEN%^Thick vines %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^twisted roots %^BOLD%^%^BLACK%^cover the entire face"
" of the cliff.",
   ]));

set_exits(([
      "south":"/d/player_houses/silesse/beach1.c",
]));

  set_smell("default","You smell the salty air of the ocean.");
  set_listen("default","%^RESET%^%^CYAN%^The soothing serenity of small waves rhythmically rolling onto this calm %^RESET%^beach %^CYAN%^is broken only by the occasional docking of a %^ORANGE%^ship %^CYAN%^and the sounds of busy %^BOLD%^%^BLUE%^sailors %^RESET%^%^CYAN%^unloading %^ORANGE%^cargo%^CYAN%^.");
}


void reset(){
   ::reset();
   if((string)TO->query_exit("cave") == "/d/player_houses/silesse/cave"){
      tell_room(TO,"%^RESET%^%^GREEN%^The vines fall back into place on the %^BOLD%^%^BLACK%^cliff face%^RESET%^%^GREEN%^,"
" concealing the %^BOLD%^%^BLACK%^dark entrance %^RESET%^%^GREEN%^to the %^BOLD%^%^BLACK%^cave %^RESET%^%^GREEN%^once again.");
      remove_exit("cave");
   }
}


void init(){
   ::init();
      add_action("part","part");
}

int part(string str){
   if(!objectp(TP)) return 1;
   tell_object(TP,"%^RESET%^%^ORANGE%^Spreading your arms wide, you command the %^GREEN%^vines %^ORANGE%^covering the"
" %^BOLD%^%^BLACK%^hidden entrance %^RESET%^%^ORANGE%^to part.");
   TP->force_me("say Amin naia lle a' kirma!");
   tell_object(TP,"%^RESET%^%^GREEN%^In response to the power of your command, the vines pull back on either side,"
" revealing the %^BOLD%^%^BLACK%^dark entrance %^RESET%^%^GREEN%^to a %^BOLD%^%^BLACK%^hidden cave %^RESET%^%^GREEN%^behind them.");
   tell_room(TO,"%^RESET%^%^GREEN%^In response to the power of "+TPQCN+"'s command, the vines covering the cliff face part to"
" reveal a %^BOLD%^%^BLACK%^dark entrance %^RESET%^%^GREEN%^to the %^BOLD%^%^BLACK%^cave %^RESET%^%^GREEN%^concealed behind them.",TP);
   add_exit("d/player_houses/silesse/cave","cave");
   call_out("set_vine_closed",10);
   return 1;
}

void set_vine_closed(){
   tell_room(TO,"%^RESET%^%^GREEN%^The vines fall back into place on the %^BOLD%^%^BLACK%^cliff face%^RESET%^%^GREEN%^,"
" concealing the %^BOLD%^%^BLACK%^dark entrance %^RESET%^%^GREEN%^to the %^BOLD%^%^BLACK%^cave %^RESET%^%^GREEN%^once again.");
   remove_exit("cave");
   return;
}
