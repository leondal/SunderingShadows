#include <std.h>
#include "../defs.h" 
inherit ROOM; 

void create() {
        ::create();
        set_property("indoors",0);  
        set_property("light",2); 
        set_terrain(NEW_MOUNTS); 
        set_travel(SLICK_FLOOR);
        set_name("Upon a large flat stone.");    
        set_short("%^BOLD%^%^WHITE%^Upon a large flat stone%^RESET%^");
        set_long("%^BOLD%^%^WHITE%^Upon a large flat stone%^RESET%^\n"
"%^BOLD%^%^CYAN%^From your perch upon a large flat stone in "
"the middle of the %^WHITE%^Clarkril River %^CYAN%^you can see that several "
"mountain %^RESET%^%^CYAN%^streams %^BOLD%^feed into this lake like headwater "
"then quickly tumble over a ledge just a few feet from where you stand forming "
"the distant %^BLUE%^river %^CYAN%^that winds its way across the Yniam Plains "
"all the way to the Dagger Straights.  Though the stone is wet with moisture "
"and slippery, you somehow feel secure and safe as though the stone holds you "
"there and wont let you be swept away.\n%^RESET%^");

        set_smell("default","The clean scent of fresh water fills the air.");
        set_listen("default","The roar of the waterfall is deafening.");

        set_items(([
           ({"mountain","mountains" }) : "%^BOLD%^%^WHITE%^All around you "
"stretch the peaks of the Charu Mountains.  Their towering forms casting a "
"shadow upon the narrow path.  Snow capped most of the year, the run off "
"feeds several small streams that work their way down toward a the headwaters "
"that form the Clarkril River.%^RESET%^",

	   ({"stream","headwater","streams"}) : "%^BOLD%^%^CYAN%^The swiftly "
"flowing headwaters of the Clarkril River start here.  Formed by several "
"mountain streams, the wide pool of water collects here and then flows "
"over a cliff and down into the Yniam Plains below.%^RESET%^",

           ({"ledge","waterfall" }) : "%^BOLD%^%^CYAN%^The waterfall is a "
"massive structure created by a long ago shifting of the mountains.  A landslide "
"that once tumbled down from the highest peaks has made a tiered pile of stones "
"that form the various troughs of the waterfall creating a cascade of smaller "
"falls that tumble down into the plains below.%^RESET%^",

           ({"stone","stones" }) : "%^BOLD%^%^WHITE%^Stepping stones cross the "
"swiftly flowing headwaters, forming a bridge of sorts to cross from one shore "
"to the other.  Each stone sticks up out of the water far enough to avoid being "
"completely engulfed in the water.  Their tops oddly smooth and marked with "
"some kind of sigil.",

           ({"sigil","marking"}) : "%^BOLD%^%^BLUE%^Peer as you might, the sigils "
"upon the stepping stones make no sense what so ever.  Though you're certain that "
"they must be some sort of magic since you feel so safe standing on these stones "
"in the middle of such a swiftly flowing river.%^RESET%^",

           ({"river"}) : "%^BOLD%^%^CYAN%^A large flat %^WHITE%^stone %^CYAN%^"
"provides a safe perch in the middle of a swiftly flowing river. Formed by the many "
"streams and snowmelts from the %^WHITE%^Charu Mountains%^CYAN%^, the headwaters are "
"swiftly flowing as they reach this point, pouring over the nearby %^BLUE%^waterfall "
"%^CYAN%^before forming into the wide %^WHITE%^Clarkril River %^CYAN%^you see in the "
"distance. From here you can see all the way across the Yniam Plains to the distant "
"headwaters of the Dagger Straights.%^RESET%^",

        ]));

        set_exits(([
	"north":ROOMS"beast08",
	"south":ROOMS"beast06",
        ]));
}