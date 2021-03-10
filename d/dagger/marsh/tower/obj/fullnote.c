#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("fullnote");
    set_short("Piece of parchment");
    set_id( ({"parchment", "paper", "note", "fullnote"}) );
    set_long(
      "scrawled across this ancient parchment is one word...\n\t%^BOLD%^%^RED%^VERTISDUN%^RESET%^"
    );
    set_weight(1);
    set("value", 1);
}
