#include <std.h>
inherit ROOM;

void create(){
  object ob;

    ::create();
set_short("The Great Hall of the Iron Fist");
	set_long(
@FIST
%^MAGENTA%^This is the High Command Room of the %^RED%^Iron Fist%^MAGENTA%^.
Here is where the High Commanders of the guild can meet to discuss
events and strategy, and to discuss potential members.
The ceiling is shrouded in shadow, the light of the torches flickering on the wall doing little to disperse the heavy darkness.
FIST
	);
set_property("no teleport",1);
set_light(2);
set_property("no attack",1);
set_property("no steal",1);
set_property("indoors",1);
	set_exits(([
          "out":"/d/shadow/guilds/fist/guild3"
	]));
set_smell("default","You catch a faint scent of stale wine and roast boar underlying the dank smell of aged stone.");
set_listen("default","You hear the scurrying of tiny feet, and faint conversation coming from the door to your west.");

ob= new(BBOARD);
ob->set_name("board");
  ob->set_id(({"board","guild board","hc board"}));
  ob->set_board_id("fisthc");
ob->set_max_posts(20);
  ob->set_location("/d/shadow/guilds/fist/hc_room.c");
  ob->set_short("Iron Fist High Command Board");
  ob->set_long("%^MAGENTA%^The %^BLUE%^Iron Fist %^MAGENTA%^HC Board, for the High Commanders to discuss and leave messages for each other.\n%^MAGENTA%^");

}

init() {
::init();
add_action("armband","pull");
}
int armband() {
    tell_object(this_player(),"You pull on the rope.");
    tell_room(environment(this_player()),
(string)this_player()->query_cap_name()+" pulls on the rope.",

           ({ this_player() }) );
call_out("restore_armband",5);
    return 1;
}

int restore_armband() {
object armband;
    tell_object(this_player(),
"The smith hurries in, and clamps a new armband around your left bicep.");
    tell_room(environment(this_player()),"The smith enters the room, and fits "+(string)this_player()->query_cap_name()+" with a new armband.",        ({ this_player() }) );
armband = new("/d/shadow/guilds/fist/hctatoo.c");
armband->move(this_player());
    return 1; 
}
