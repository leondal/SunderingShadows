#include <std.h>
#include "/d/dagger/tonovi/short.h"

inherit VAULT;
object guard;
void create(){
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("%^BOLD%^%^WHITE%^Outside a large inn%^RESET%^");
    set_long("A towering %^BOLD%^%^BLACK%^cathedral%^RESET%^ has been built to the northwest "
             "on the very crest of a hill. Oddly enough, the sound of %^BOLD%^"
             "%^MAGENTA%^dr%^RESET%^%^MAGENTA%^u%^BOLD%^%^MAGENTA%^nk%^RESET%^" 
             "%^MAGENTA%^e%^BOLD%^%^MAGENTA%^n l%^RESET%^%^MAGENTA%^au%^BOLD%^"
             "%^MAGENTA%^ght%^RESET%^%^MAGENTA%^e%^BOLD%^%^MAGENTA%^r%^RESET%^ "
             "reaches your ears, and you realize this isnt a cathedral at all, but "
             "an inn. A %^BOLD%^%^BLACK%^sign%^RESET%^ hanging above the door "
             "proudly declares it to be %^BOLD%^%^WHITE%^The %^BOLD%^%^RED%^B"
             "%^RESET%^%^RED%^lo%^BOLD%^%^RED%^o%^RESET%^%^RED%^d%^BOLD%^%^RED%^y"
             "%^BOLD%^%^BLACK%^ Sc%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^ur%^RESET%^"
             "%^RED%^g%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^ Inn%^RESET%^.");
       set_smell("default", "%^RESET%^%^ORANGE%^There is a faint "+
                 "scent of liquor on the breeze.%^RESET%^");
      set_listen("default", "%^RESET%^%^CYAN%^Laughter and"+
                 " drunken conversations spill out over the hills.%^RESET%^");
    set_items( ([
        "hills" : "You are sorrounded by these great majestic green monsters.",
        "road" : "The new road here is just starting to get ruts in"+
		" it, as is burns an ominous scar across the plains.",
        "wall" : "The great wall around the plain is"+
		" supposed to keep invaders out, but it looks more "+
		"like it keeps the beauty in.",
        ({"lookout post", "post", "lookout"}) : "On the road "+
		"you can see a brick structure standing aside the road.",
      "cathedral" : "%^BOLD%^%^WHITE%^By the looks of it, this was "
"probably once a temple rather than the place of %^BOLD%^%^BLACK%^"
"debauchery%^BOLD%^%^WHITE%^ that it has become. Its massive walls "
"loom before you, and %^YELLOW%^inviting lights%^BOLD%^%^WHITE%^ shine "
"from behind %^BOLD%^%^RED%^s%^RESET%^%^RED%^t%^BOLD%^%^MAGENTA%^a"
"%^RESET%^%^MAGENTA%^i%^BOLD%^%^RED%^n%^RESET%^%^MAGENTA%^e%^BOLD%^"
"%^MAGENTA%^d %^RESET%^%^MAGENTA%^g%^BOLD%^%^RED%^l%^RESET%^%^RED%^a"
"%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^s%^BOLD%^%^WHITE%^ windows. A "
"sign hanging above the heavy wooden doors proclaims it to be %^BOLD%^"
"%^RED%^The %^RESET%^%^RED%^B%^BOLD%^%^RED%^lo%^RESET%^%^RED%^o%^BOLD%^"
"%^RED%^d%^RESET%^%^RED%^y S%^BOLD%^%^RED%^co%^RESET%^%^RED%^ur%^BOLD%^"
"%^RED%^g%^RESET%^%^RED%^e In%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^.%^RESET%^",
      "sign" : "%^RESET%^The sign is %^ORANGE%^wooden%^RESET%^ and "
"%^BOLD%^%^BLACK%^worn%^RESET%^. The lettering is written in %^BOLD%^"
"%^RED%^b%^RESET%^%^RED%^r%^BOLD%^%^RED%^ig%^RESET%^%^RED%^h%^BOLD%^"
"%^RED%^t r%^RESET%^%^RED%^e%^BOLD%^%^RED%^d%^RESET%^, and beneath it "
"is the image of a %^BOLD%^%^BLACK%^black%^RESET%^ and %^BOLD%^"
"%^WHITE%^coiled%^BOLD%^%^BLACK%^ nine-stranded scourge%^RESET%^.",
      ]) );
    set_exits( ([
        "north" : "/d/dagger/tonovi/1path2",
        "inn" : "/d/player_houses/innaeli/rooms/bsb1",
        "south" : "/d/dagger/road/road7",]));
	
   set_door("cathedral door","/d/player_houses/innaeli/rooms/bsb1","inn",0);
   set_locked("cathedral door", 0);
      lock_difficulty("cathedral door",-0, "lock");
   set_door_description("cathedral door",
   "%^BOLD%^%^BLACK%^The doors are made of thick"+
   " stone that looks quite heavy. They can be "+
   "swung open to create a grand entrance into the "+
   "establishment. Each gray stone door has a "+
   "centrally placed, large iron knocker, featuring "+
   "the image of a laughing face although upon "+
   "closer inspection it appears the mouth is "+
   "parted into an anguished scream. How inviting%^RESET%^! ");
}
