#include <std.h>
#include "../githyanki.h"

inherit STORAGE"3floor.c";

void create(){
    ::create();
    set_long(::query_long()+"%^RESET%^%^RED%^There is a shifting red"+
" portal here.%^RESET%^.\n");
    set_exits(([
      "portal" : ROOMS"2_56",
      "west" : ROOMS"3_71",
    ]));
    add_item("portal","%^RESET%^%^RED%^There is a portal here hanging"+
" in the air, like a tear in space. You can see what looks like stables"+
" on the other side.");


}