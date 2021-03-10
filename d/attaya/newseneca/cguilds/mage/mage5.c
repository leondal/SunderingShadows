
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
This is a store where mages can sell unwanted items for other mages to buy. There is a long counter made of dark oak and Carina is always here to serve you.
ZERINA
);

set_items(([

]));

set_exits(([
"south" : "/d/attaya/seneca/town/cguilds/mage/mage2.c",

]));

set_smell("default", "You can smell Carina's perfume.");
set_listen("default", "You can hear Carina moving about her store.");

}
void reset(){
  ::reset();

if(!present("carina"))
  new("/d/attaya/seneca/town/cguilds/mage/carina")->move(TO);
  }
