#include <std.h> 
#include "../defs.h" 
inherit VAULT; 

void create(){ 
    ::create(); 
    set_property("light",-1); 
    set_property("indoors",1); 
    set_terrain(NAT_CAVE);
    set_travel(PAVED_ROAD); 
    set_name("A forgotten crypt"); 
    set_short("%^RESET%^%^BLUE%^A forgotten crypt%^RESET%^");
    set_long("%^RESET%^%^BLUE%^A forgotten crypt%^RESET%^\n"
"%^BOLD%^%^BLACK%^Dust and %^RESET%^cobwebs %^BOLD%^%^BLACK%^lay heavily in this room, "
"clinging to the ancient stones in stringy gray shrouds.  Older then the passages beyond, the "
"stone here is uncut and poorly formed, with jutting edges and uneven surfaces.  At least a few "
"spots show signs of decay and immanent collapse given a few more decades.  Here and there, "
"twisted %^RESET%^%^ORANGE%^roots%^BOLD%^%^BLACK%^ poke from between the uneven stones and run "
"along ceiling and walls like the jagged cracks of some long forgotten trauma. Rising from the "
"floor are ancient stone %^YELLOW%^sarcophagi %^BLACK%^slowly deteriorating into the "
"clogging %^RESET%^%^ORANGE%^dust%^BOLD%^%^BLACK%^ that fills this chamber.  Several are little "
"more then jutting slabs, long broken and ruined, attesting once again to the incredible age of "
"this place.%^RESET%^"); 
    set_smell("default","Earth, musk and dust fill the air, clogging your lungs."); 
    set_listen("default","Silence hangs in the air, still as a held breath."); 
    set_items(([ 
      ({"dust","cobwebs","shrouds"}):"%^BOLD%^%^WHITE%^Hanging like shrouds from the ceiling, walls and "
"stone remains of the sarcophagi, these dust covered cobwebs stir and move as you pass by.%^RESET%^", 
      ({"stone","floor","walls","ceiling"}):"%^BOLD%^%^BLACK%^The old stones here appear to have been "
"gathered haphazardly and stuck together even more so.  Here and there the shifting of the earth "
"has cracked of expelled these stones allowing the dirt and plant roots to invade these "
"ancient tomes.%^RESET%^",
      ({"roots","vines","cracks"}):"%^BOLD%^%^BLACK%^Roots from trees and plants in the surface have "
"made their way into this ancient burial place, snaking their way over the stones.  In some "
"cases they look like nothing more then fine cracks racing over the walls, ceiling and floors, "
"bringing an illusion of this place being ready to collapse at any moment.%^RESET%^",
      ({"sarcophagi","slabs"}):"%^BOLD%^%^BLACK%^Most of the tombs that lay within this burial chamber "
"have long since collapsed to time and decay.  A sense of sadness hangs about their once ornate "
"forms, but the glyphs, sigils and carvings have worn to nearly smooth, just as the remains "
"inside have turned to dust once more.%^RESET%^",
    ])); 
}

// So these chambers should have a percent chance that every time someone enters the room a wraith
// rises from one of the ancient tombs.  These wraiths, upset as they are, instantly attack everyone
// in the room in an effort to kill them. The wraiths will be similar to what is found on the Dark
// Trail, just a little meaner and with magic cold specials that will freeze/stun someone in place. 