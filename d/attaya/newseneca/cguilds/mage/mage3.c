
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
This room contains the components store. Noma, the proprietor is always ready to serve you. As you gaze around you see a multitude of shelves on which many sizes of boxes sit. Hanging from the ceiling you see herbs drying in the cool air. In a glass case in front of you, you see the most precious of the components sold here.

ZERINA
);

set_items(([
"herb" : "As you look above you you see sage hanging above you. A small bunch of yarrow hangs there too.",
"case" : "This glass case is sparkly clean. You can see %^GREEN%^emerald%^RESET%^ dust, %^ORANGE%^licorice%^RESET%^ root, and something you think is eyelashes (of what race you arn't too sure). There is also another small container in which many types of spiders are spinning webs. ",

]));

set_exits(([
"east" : "/d/attaya/seneca/town/cguilds/mage/mage2.c",

]));

set_smell("default", "It smells of magic and herbs here.");
set_listen("default", "You can hear Noma moving about the store.");

}
void reset(){
   ::reset();
   if(!present("noma")){
   new("/d/attaya/seneca/town/cguilds/mage/noma")->move(this_object());
}
}
