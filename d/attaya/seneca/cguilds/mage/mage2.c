
#include <std.h>
inherit ROOM;


void create(){
object ob;
:: create();

set_property("indoors",1);
set_property("light",2);
set_short("
%^ORANGE%^This is within the inner walls of the Seneca Mage Guild.%^RESET%^
");
set_long(
@ZERINA
%^ORANGE%^This is within the inner walls of the Seneca Mage Guild.%^RESET%^
This room is the first within the mage guild. There is a board for you to post concerns and comments particular to your class on. 
Within your guild you have a components store, a store where you can buy spells, and a shop where you can sell any unwanted items.

ZERINA
);

set_items(([

]));

set_exits(([
"out" : "/d/attaya/seneca/town/cguilds/mage/mage1.c",
"west" : "/d/attaya/seneca/town/cguilds/mage/mage3.c",
"east" : "/d/attaya/seneca/town/cguilds/mage/mage4.c",
"north" : "/d/attaya/seneca/town/cguilds/mage/mage5.c",

]));

set_smell("default", "It smells of magic and wood smoke here.");
set_listen("default", "You hear the soft chanting of voices here.");
ob= new(BBOARD);
ob->set_name("board");
ob->set_id(({"board","guild board"}));
ob->set_board_id("mageguild");
ob->set_max_posts(30);
ob->set_location("/d/attaya/seneca/town/cguilds/mage/mage2.c");
ob->set_short("Mage Guild Hall Board");
ob->set_long("Mage Guild Hall Board of communication and things of interest.");

}
