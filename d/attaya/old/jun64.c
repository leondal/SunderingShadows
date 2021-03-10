#include <std.h>
inherit "/std/room";

void create() {
     ::create();
      set_terrain(RUINS);
      set_travel(FOOT_PATH);
     set_light(2);
     set_indoors(0);
     set_short("Ancient Tomb");
     set_long("
    You stand before a massive stone tomb.  It is partially covered in vines and has been hidden for centuries in the depths of the jungle, appearantly unopened.  The massive iron door creaks slightly as the ground beneath you trembles.  Above you, the treetop canopy allows tiny slivers of light through that give this scene a picturesque ambiance.  
    A horrible stone gargoyle peers down at you from the sloping roof of the ancient structure.  It is quite lifelike.
");
    set_exits((["north":"/d/attaya/jun68"]));
set_listen("default", "You think you can hear a heartbeat within the crumbling tomb\n");
    set_items(([
    "tomb" : "The massive tomb is crumbling in the jungle humidity with help from vines that seem to strangle it.  It seems almost like an entity itself.  Perhaps you should search it more carefully before you enter.",
    "vines" : "They have a stranglehold over this entire area!",
    "door" : "It is unlocked, and can be easilly pushed aside if you wish to 'enter'.",
    "canopy" : "The sunlight slips through the canopy only in a few select areas, making a pentagram of light and shadow on the side of the tomb.",
    "gargoyle" : "The stone gargoyle has crumbled and weathered."
]));
}
void init() {
     ::init();
add_action("search", "search");
add_action("enter", "enter");
}
int search(string str) {
write("You search the ground around the ancient tomb.\n");
say((string)this_player()->query_cap_name()+" searches the ground around the ancient tomb.\n");
write("%^CYAN%^You hear a loud snap!\n"
"%^BOLD%^You feel your body propelled into the air as you set off a hidden catapult!\n"
"%^BOLD%^%^CYAN%^You smash through the canopy of leaves and look down upon the jungle from above briefly!\n"
"%^RED%^You see a giant skull floating towards you!  Perhaps you are delusional\n"
"\n"
"%^BOLD%^%^RED%^You smash back through the canopy which breaks your fall slightly and slam painfully into the ground!\n"
);
say((string)this_player()->query_cap_name()+" is launched into the sky by a hidden catapult in the jungle floor!\n");
this_player()->move_player("/d/attaya/jun43.c");
say((string)this_player()->query_cap_name()+" lands nearby with a horrible crack.\n");
this_player()->do_damage((random(150)));
return 1;
}
int enter(string str) {
write("You open the door to the ancient tomb and step inside.\n");
write("%^RED%^You are suddenly grabbed by a spiritual force and sucked in deeper.\n");
say((string)this_player()->query_cap_name()+" Pulls open the massive door to the tomb and vanishes inside
.\n");
this_player()->set_invis(0);
this_player()->move_player("/d/attaya/tomb1",);
write("%^BOLD%^%^BLUE%^The door slams shut behind you and the seams around it magically vanish!");
return 1;
}

