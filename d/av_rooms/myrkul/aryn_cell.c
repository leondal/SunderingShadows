// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("aryn_cell");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^P%^RESET%^a%^BOLD%^%^WHITE%^dd%^RESET%^e%^BOLD%^%^WHITE%^d R%^RESET%^o%^BOLD%^%^WHITE%^om%^RESET%^");

    set_long("You stand in a padded white room illuminated by a %^YELLOW%^magical orb%^RESET%^ "+
    "near the center of the ceiling which gives off a soft yellow glow. No windows line the walls of this square room, and e"+
        "ach wall looks exactly the same as the others. In the center of the room is a %^RESET%^%^ORANGE%^square"+
	" table%^RESET%^ around which are four %^ORANGE%^chairs%^RESET%^. The floor looks solid but has a "+
        "certain amount of %^CYAN%^spongy%^RESET%^ give when pressed upon, much like a mat yet is "+
        "entirely seamless. There is a faint %^BOLD%^%^CYAN%^a%^WHITE%^u%^CYAN%^r%^WHITE%^a%^RESET%^"+
	" of magical or psion"
        "ic %^YELLOW%^e%^RESET%^%^ORANGE%^n%^YELLOW%^e%^RESET%^%^ORANGE%^r%^YELLOW%^g%^RESET%^%^ORANGE%^y%^RESET%^"+
	" that permeates the room which doubtless controls access to this room.");

    set_smell("default","You smell nothing.");
    set_listen("default","You can only hear the sounds of yourself breathing.");

    set_search("outline","Perhaps this could be an illusion even a <portal>?");
    set_search("floor","You don't find anything on the floor.");
    set_search("ceiling","Even if you could reach the ceiling theres nothing of interest up there.");
    set_search("walls","There looks like some kind of an outline on the wall.");
    
set_items(([ 
        "table" : "The table is solid oak and has a nice finish.",
        "floor" : "The spongy floor is firm but you still feel your foot slightly sink into the surface.",
        "globe" : "The globe looks rather like a permanent light spell. ",
        "ceiling" : "The globe sheds a soft glow over the room and the ceiling is plain and unadorned.",
        "chairs" : "The chairs look like sturdy wooden chairs with a fresh finish.",
        "padding" : "The padding on the walls looks to be seamless and quite thick. ",
        "walls" : "These walls are plain and unadorned. However they do seem to be thickly padded.",
        ]));

    set_exits(([ 
                "portal" : "/d/av_rooms/myrkul/aryn_obs",
        ]));



    set_invis_exits(({ "portal" }));
    set_door("energy barrier","","");
    set_string("energy barrier","knock","");
    set_string("energy barrier","open","");
    set_string("energy barrier","close","");
    set_door_description("energy barrier","");
    set_door("energy barrier","/d/av_rooms/myrkul/aryn_obs","portal","skeleton key","lock");
    add_lock("energy barrier","skeleton key","lock","This lock is made out "+
    "of %^YELLOW%^pure energy%^RESET%^, something a locksmith could only d"+
    "ream of making. It appears however, that some quite ordinary key should be able to  unlock it.");
    set_locked("energy barrier",1,"lock");
    lock_difficulty("energy barrier",-65,"lock");
    set_open("energy barrier",0);
    set_string("energy barrier","knock","pounds on the");
    set_string("energy barrier","open","%^BOLD%^%^CYAN%^The %^YELLOW%^energy barrier%^CYAN%^ snaps open with a %^RESET%^%^CYAN%^hiss.%^RESET%^");
    set_string("energy barrier","close","%^BOLD%^%^CYAN%^The %^YELLOW%^energy barrier%^CYAN%^ snaps shut with a %^RESET%^%^CYAN%^hiss.%^RESET%^");
    set_door_description("bnergy barrier","%^BOLD%^%^CYAN%^This appears to be some kind"+
    " of magical or psionic %^YELLOW%^energy barrier%^CYAN%^. It seems harder than diamond and"+
    "stronger than steel. There does appear to be some kind of lock assembly in the center.%^RESET%^");
 }
