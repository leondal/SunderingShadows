#include <std.h>
#include <objects.h>
inherit ROOM;
void create() {
room::create();
set_light(2);
set_indoors(1);
set_short("Before the gates of Death Itself");
set_name("Before the gates of Death Itself");
   set_long("
    Before you rise the massive gates to the Shades of Death stronghold.  The original builder of this underground fortress has been lost to time.
    Water shoots from the rocks to the left and right of you across this vast cavern.  You are thourougly soaked at this point and water drips down upon you from above.
    Something about the gates seems magical, as if they are held closed by a magical ancient force.
   ");
set_smell("default","You detect a hint of sulfur.");
set_listen("default","The thunder of the cascading water is drowned out in your head by the silence that surrounds the gates.");
set_items( ([
    "gates" : "The massive iron gates have rusted in the years in this humid cave.  They, however, seem to posess a quality of eternity and a presence of invincibility.",
    "bridge" : "The bridge is made of granite and stretches about 200 feet to the south, spanning the great chasm.",

   ]) );
set_exits(([
"enter":"/d/shadow/guilds/pack/hall/pack2",
"south":"/d/shadow/guilds/pack/bridge1.c"
 ]) );
set_property("no sneak",1);
set_pre_exit_functions( ({"enter"}),({"go_enter"}) );
}
int go_enter()
{
if(member_array(TP->query_guild(),({"Shadows of Fate"})) < 0)
{
tell_object(TP,"%^BOLD%^%^CYAN%^A shadowy presence whispers to you: %^RESET%^You are not ready for what lies beyond these gates...  RUN AWAY NOW or you will DIE HERE TODAY.");
tell_room(TO,TP->query_cap_name()+" is suddenly frozen in "+TP->query_possessive()+" tracks.",TP);
return 0;
}
tell_object(TP,"You stand before the massive gates and they open before you.");
tell_object(TP,"%^BOLD%^%^CYAN%^A shadowy presence whispers to you: %^RESET%^Greetings, "+TPQCN+", Welcome back...");
tell_room(TO,TP->query_cap_name()+" stands before the gates and they are cast open!",TP);
return 1;
}

void init() {
::init();
add_action("sneak","sneak");
}
int sneak() {
write("%^BOLD%^%^BLUE%^You fucking loser!  You can't sneak here.");
return 1;
}
