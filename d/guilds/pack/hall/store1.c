#include <std.h>
#include <daemons.h>
#include "/d/guilds/pack/short.h"
inherit "std/room";

void create() {
    ::create();
    set_property("light",1);
    set_property("no teleport",1);
    set_indoors(1);
    set_short("%^BOLD%^%^BLUE%^Guild Store%^RESET%^");
    set_long(
@SEETH
%^BOLD%^%^BLUE%^Welcome to Destiny Keep's store%^RESET%^
%^BOLD%^%^RED%^The store is quite large with many shelves and chests. The shelves and chests are filled with only items which you sell to Strife. He then takes the items to sell elsewhere to earn money for you and the family.
SEETH
);

   set_items(( [
]) );
    set_exits( ([
      "south" : HALL "bank.c",
             ]));
   set_smell("default","The smell of metal fills the room.");
    set_listen("default","You hear strife yelling at some people about cheap items.");
 }


void reset(){
      ::reset();
        if(!present("strife"))
       new(MON "strife")->move(TO);
}
