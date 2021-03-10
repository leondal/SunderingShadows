
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
This is the spell store. On the walls you see hanging all the different scrolls you can buy here. They are stored in a variety of coloured bundles. You see %^BLUE%^blue%^RESET%^ ones, %^ORANGE%^brown%^RESET%^ ones, %^YELLOW%^yellow%^RESET%^ ones, %^MAGENTA%^purple%^RESET%^ ones, and many others. Shea is always ready to lend a hand. This room is spotless.

ZERINA
);

set_items(([

]));

set_exits(([
"west" : "/d/attaya/seneca/town/cguilds/mage/mage2.c",

]));

set_smell("default", "It smells of magic here.");
set_listen("default", "You hear Shea moving about his store.");

}
void reset(){
    ::reset();
    if(!present("shea")){
    new("/d/attaya/seneca/town/cguilds/mage/shea.c")->move(this_object());
    }
}
