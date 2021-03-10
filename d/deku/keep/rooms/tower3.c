#include <std.h>
#include "../keep.h"
inherit HTOWER;

void create() {
    ::create();
	set_long(TO->query_long() + "  The chamber is dominated by a spiral, %^BOLD%^%^WHITE%^stone "+
	"staircase%^RESET%^ that leads to the level above or back to the level below.%^RESET%^");
 set_exits(([
 "up" : KEEPR + "tower4",
 "down" : KEEPR + "tower2"
 ] ));
 set_peer_message("Something, perhaps magic, prevents you from peering in that direction");
	set_property("no peer",1);

}

void reset() {
  ::reset();
  if(!present("ingmar") && random(12) >= 10) {
    new(KEEPM + "ingmar")->move(this_object());
  }
}


