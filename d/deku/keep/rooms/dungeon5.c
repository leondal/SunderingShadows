#include <std.h>
#include "../keep.h"

inherit DUNGEON;

void create() 
{
    ::create();
    set_short("%^BOLD%^%^WHITE%^Marble Chamber%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This massive marble chamber boasts many "+
    "corridors, with tunnels sloping upward in every direction except "+
    "southward.  In the center of the room is a stairwell that allows for "+
    "either descension or ascension.  A very thick and "+
    "%^BLUE%^cold%^BOLD%^%^BLACK%^ darkness%^BOLD%^%^WHITE%^ lingers "+
    "here, permeating your very %^RED%^being%^BOLD%^%^WHITE%^.  The floor "+
    "of this chamber is littered with the %^BOLD%^%^BLACK%^bones%^BOLD%^%^WHITE%^ "+
    "of various creatures, some which still "+
    "have bits and pieces of %^RED%^flesh %^BOLD%^%^WHITE%^attached.  "+
    "Etched into the northern, eastern, and western walls are numerous "+
    "%^CYAN%^hieroglyphic symbols%^BOLD%^%^WHITE%^.  Inset directly into the "+
    "center of the southern wall is a "+
    "massive %^BOLD%^%^BLACK%^marble door%^BOLD%^%^WHITE%^.%^RESET%^\n");

    set_exits(([
    "northwest" : KEEPR + "dungeon6", 
    "north": KEEPR + "dungeon12", "northeast" : KEEPR + "dungeon18", 
    "east" : KEEPR + "dungeon24", "southeast" : KEEPR + "dungeon30", 
    "southwest" : KEEPR + "dungeon36", "west" : KEEPR + "dungeon42",
    "stairs" : KEEPR + "dungeon4","south" : KEEPR + "spectre1",
    ] ));
    set_door("marble door",KEEPR + "spectre1","south","shaltul key","lock");
    set_string("marble door", "open", "%^RED%^The door opens easily and you "+
    "are assaulted by a strong odor of decay.%^RESET%^");
    set_locked("marble door",1,"lock");
    set_lock_description("marble door","lock","This is a complex lock with "+
    "odd engravings on it.");
    add_lock("marble door","siere key","lock2","This is a complex lock with "+
    "odd engravings on it.");
    add_lock("marble door","telair key","lock3","This is a complex lock with "+
    "odd engravings on it.");
    lock_difficulty("marble door",-101,"lock");
    lock_difficulty("marble door",-101,"lock2");
    lock_difficulty("marble door",-101,"lock3");
    set_door_description("marble door","%^BOLD%^%^BLACK%^This heavy marble "+
    "door is inset directly in the center of the southern wall.  The only "+
    "obvious way to open it is to push on it.  There are three keyholes "+
    "inset into one side of it.  Its impossible to determine how thick "+
    "it is.%^RESET%^");
	
    set_property("no phase", 1);
    
    set_items(([
        ({"hieroglyphics","symbols","hieroglyphic symbols"}) : "%^BOLD%^"+
        "%^BLACK%^Hieroglyphics are "+
        "carved into the northern, eastern, and western walls.  "+
        "Which do you want to look at?%^RESET%^",
        "bones" : "%^BOLD%^%^WHITE%^These bones are obviously the remains of "+
        "the meal or several meals of some type of beast.  Some of them still "+
        "have pieces of flesh attached, causing you to believe that "+
        "the meals were rather recent.%^RESET%^",
        "floor" : "%^BOLD%^%^BLACK%^The marble floor of this room is "+
        "littered with the %^BOLD%^%^WHITE%^bones%^BOLD%^%^BLACK%^ of "+
        "various creatures.%^RESET%^",
        ({"east","eastern hieroglyphics","eastern symbols","east symbol",
        "east symbols","east hieroglyphics","east hieroglyphic"}) : "%^BOLD%^"+
        "%^BLACK%^The symbols engraved into this wall depict a rather gruesome "+
        "battle between wolf-like creatures and what appears to be an "+
        "elven settlement.  Its obvious that the elves did not prevail.%^RESET%^",
        ({"west","western hieroglyphics","western symbols",
        "west hieroglyphic","west hieroglyphics","west symbol",
        "west symbols"}) : "%^BOLD%^%^BLACK%^The symbols engraved "+
        "into this wall depict a haphazard throne room.  Sitting on "+
        "the golden throne is a very massive wolf-like creature garbed "+
        "in an obsidian robe and donning the typical gem-encrusted crown.%^RESET%^",
        ({"south","south wall","south walls"}) : "%^BOLD%^%^BLACK%^There is "+
        "a massive marble door inset directly into the center of this "+
        "wall.  There are three keyholes inset into one side of the door.%^RESET%^",
        ({"north","northern hieroglyphics","northern symbols",
        "north hieroglyphics","north hieroglyphic",
        "north symbols","north symbol"}) : "%^BOLD%^%^BLACK%^The symbols "+
        "engraved into this wall depict a young woman holding a book "+
        "open before her, as if reading from it.  These hieroglyphics "+
        "seem strangely out of place.  An uneasy feeling stirs "+
        "within you.%^RESET%^",
        "flesh" : "%^RED%^There are still bits and pieces of flesh "+
        "on some of the bones that lay here.%^RESET%^",
        "darkness" : "%^BOLD%^%^BLACK%^This darkness is thick and "+
        "very cold.  It permeates your being, soaking into you, and "+
        "sending chills through your body.  You fear what may be "+
        "concealed by it as growls echo from deep within.%^RESET%^",
        "walls" : "%^BOLD%^%^BLACK%^The walls of this corridor are "+
        "covered with numerous %^CYAN%^hieroglyphic symbols%^BOLD%^"+
        "%^BLACK%^.  The symbols are in strikingly vivid detail.%^RESET%^",
        "being" : "%^RED%^Your very being is assaulted by this "+
        "%^RESET%^%^BLUE%^cold%^RED%^, thick, darkness.%^RESET%^",
    ] ));
}

