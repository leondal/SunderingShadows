#include <std.h>
#include "../githyanki.h"

inherit STORAGE"1floor.c";

void create(){
   ::create();
  set_long(::query_long()+"%^RESET%^%^ORANGE%^The hall continues east and west%^RESET%^.\n");
   set_exits(([
      "east" : ROOMS"1_47",
      "west" : ROOMS"1_33",
   ]));

    set_door("ornate door",ROOMS"1_47","east",1);
    set_door_description("ornate door","%^RESET%^%^ORANGE%^Formed from stone, this door"+
" has been carved with a stunning array of glyphs and symbols, most of them obviously alien in origin.%^RESET%^");
    set_string("ornate door", "open", "%^RESET%^%^BOLD%^You push against the heavy door and it opens slowly.%^RESET%^");
    set_string("ornate door", "close", "%^RESET%^%^BOLD%^You close the heavy stone door slowly%^RESET%^%^BOLD%^.");



}