
#include <std.h>
inherit ROOM;


void create(){
object ob;
:: create();

set_short("%^RED%^The Inner Haven of the Shades of Death.%^RESET%^");
    set_property("light",1);
    set_property("no teleport",1);
    set_property("indoors",1);
set_long(
@PACK
%^RED%^This is the Inner Haven of the Shades of Death.%^RESET%^
This room contains a chest in which members can leave items for other members to take and use. You see a bit of clutter and dust has settled on the floor. There is a draft that you can feel on your skin and you wonder where it is coming from. 
%^ORANGE%^Welcome and enjoy the companionship you will find here. 
You're family embraces you.%^RESET%^
PACK
);

set_property("no attack",1);
set_property("no steal",1);
set_items(([
"floor" : "The floor is covered in a layer of thick dust, but you can vaguely see light shining from the bottom of the chest.",
"clutter" : "There is various bits of paper, metal fragments, and tufts of hair on the floor.",

]));

set_exits(([
"west" : "/d/shadow/guilds/pack/hall/pack2.c",
"down" : "/d/shadow/guilds/pack/hall/pack5.c",
"north" : "/d/shadow/guilds/pack/hall/throne.c",

]));
  set_invis_exits( ({"down"}) );

set_smell("default", "It smells of old things.");
set_listen("default", "You hear the gentle voices of your fellow evil types and a soft wind blowing.");

}
void reset(){
::reset();
if(!present("chest")){
new("/d/shadow/guilds/pack/hall/packchest.c")->move(this_object());
}
}
void init() {
::init();
add_action("move_chest", "push");
}
int move_chest(string str){
if((!str) || (str!="chest"))
return 0;
else{
tell_room(environment(this_player()),this_player()->query_cap_name()+"moves the chest out of the way.",this_player());
tell_object(this_player(),"You find a stairway leading down.");
TO->add_exit("/d/shadow/guilds/pack/hall/pack5.c");
return 1;
}
}
void clean_up(){return 1;}
