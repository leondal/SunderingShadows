

#include <std.h>
#include <objects.h>
inherit ROOM;
void create() {
room::create();
set_light(4);
set_indoors(1);
set_short("War Museum");
set_long(
"%^CYAN%^%^BOLD%^"
"%^CYAN%^This is the War Museum of Shadow. On display here are armor and weaponry"
" %^CYAN%^from a thousand lands. From the exquisite ceremonial plate armor of
%^YELLOW%^Tharis,%^CYAN%^"
" %^CYAN%^to the smelly wolfskins worn by the %^RED%^Orc%^CYAN%^ tribes. "
"%^CYAN%^Katana's crafted by the elder smiths of the east lay next to primitive "
"%^CYAN%^yet wickedly serrated and spiked weapons of the %^RED%^Goblins.%^CYAN%^ Even, "
"%^CYAN%^in a specially %^BLUE%^darkened%^CYAN%^ display, are the exotic and horrible weapons "
"%^CYAN%^of the mysterious and evil %^RED%^Drow.%^CYAN%^ "
"%^CYAN%^Toward the back of the massive hall, is a pedestal with an iron sculpture of an immense gauntleted %^RED%^Fist%^CYAN%^ atop it."
);
set_smell("default","Your nostrils detect a faint odor of long dried
blood.");
set_listen("default","The hall is silent, but somehow your ears pick up the
ghostly sounds of distant battle.");
set_items((["sculpture":"This as a detailed sculpture of an immense, gauntleted fist, atop a pedestal of the purest clear crystal. You have the urge to touch it.",
"fist":"This as a detailed sculpture of an immense, gauntleted fist, atop a pedestal of the purest clear crystal. You have the urge to touch it."
]));
set_exits(([
"west":"/d/shadow/room/city/smroad.c"
 ]) );
}
void init() {
    ::init();
add_action("touch_fist","touch");
}
int touch_fist(string str){
    if(str !="fist") {
        notify_fail("Touch what?");
    return 0;
    }
if(member_array(TP->query_guild(),({"Iron Fist"})) < 0)
{
tell_object(TP,"You touch the Iron Fist, and you feel a tingling, but nothing happens.");
tell_room(TO,TP->query_cap_name()+" touches the Iron Fist.",TP);
return 0;
}
tell_object(TP,"You touch the Iron Fist, and the
armband on your bicep glows, as you find yourself in another place.");
tell_room(TO,TP->query_cap_name()+" touches the Iron Fist, and as "+TP->query_possessive()+" armband glows, "
+TP->query_cap_name()+" disappears",TP);
TP->move_player("/d/shadow/guilds/fist/guild2.c");
return 1;
}
