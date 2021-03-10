
#include <std.h>
inherit ROOM;


void create(){
object ob;
:: create();

set_property("light",1);
   set_property("no teleport",1);
set_property("indoors",1);
set_short("
%^RED%^The Pack Bitching Room.%^RESET%^
");
set_long(
@ZERINA

%^RED%^This is the Pack Bitching Room%^RESET%^
In this room you can post anyone you want to see killed, to report who you have killed or to just generally bitch. 
ZERINA
);

set_items(([

]));

set_exits(([
"up" : "/d/shadow/guilds/pack/hall/pack2.c",

]));

set_smell("default", "It smells of desolation here.");
set_listen("default", "You can only hear your own breathing.");

ob= new(BBOARD);
ob->set_name("board");
ob->set_id( ({ "board", "guild board"}) );
ob->set_board_id("pboard");
ob->set_max_posts(30);
ob->set_location("/d/shadow/guilds/pack/hall/pack6");
ob->set("short", "Pack Bitching Board");
ob->set("long", "On this board post things concerning enemies of the pack.\n");
}
