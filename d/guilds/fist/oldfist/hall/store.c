#include <std.h>
inherit ROOM;

void create(){
    object ob;
    ::create();
	set_short("The Storage Room of the Iron Fist");
        set_long(
@FIST
%^BLUE%^This is the entrance to the storage room where the
%^RED%^Iron Fist%^BLUE%^ members store items to be sold at a later
time. There is a clerk sitting behind a small counter 
who appears to be in charge of keeping things in order
here. There is a small sign on the counter explaining 
just how everything works. 
FIST
        );
	set_light(2);
    set_property("no teleport",1);
	set_property("no steal",1);
	set_property("indoors",1);
    set_exits(([
		"north":"/d/guilds/fist/hall/store1"
	]));
	set_items(([
		"sign":"Read it to get a list of commands"
	]));
    ob = new(BBOARD);
    ob->set_name("board");
    ob->set_id(({"board","store board"}));
    ob->set_board_id("fiststore");
    ob->set_max_posts(60);
    ob->set_location("/d/guilds/fist/hall/store.c");
    ob->set_short("Iron Fist Storage Room Board");
    ob->set_long("%^MAGENTA%^This board is for the %^RED%^Iron Fist %^MAGENTA%^members to post details and suggestions about items left in the storage room.");
}

void reset(){
	::reset();
	if(!present("Tulmak"))
		new("/d/guilds/fist/hall/tulmak.c")->move(TO);
}

void init(){
	::init();
	add_action("read_sign","read");
}

int read_sign(string str){
	if(str!="sign") return 0;
	write(
@SIGN
%^BOLD%^Here is how things work in the %^RED%^Iron Fist %^WHITE%^Storage Room:%^RESET%^
  %^BOLD%^list            %^RESET%^%^MAGENTA%^shows you a list of what is in the storage room now%^RESET%^
  %^BOLD%^bin <number>    %^RESET%^%^MAGENTA%^will show you the item in that bin%^RESET%^
  %^BOLD%^deposit <item>  %^RESET%^%^MAGENTA%^puts an item you are carrying into storage%^RESET%^
  %^BOLD%^retrieve <item> %^RESET%^%^MAGENTA%^allows you to get an item from the storage room by
	                     contributing its value to the guild%^RESET%^
SIGN
	);
	return 1;
}
