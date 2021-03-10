#include <std.h>
#include "../keep.h"

inherit TUNNELUW;

void create() {
    ::create();
	set_long(TO->query_long() + "%^YELLOW%^  This tunnel continues here, to "+
	"the west.  To the east it meets a strange %^CYAN%^glowing door%^RESET%^"+
	"%^YELLOW%^.  What will you decide?%^RESET%^");

     set_exits(([
		"west": KEEPR + "tunnel_uw6", "east" : KEEPR + "tunnel_uw8"
    ] ));
	set_door("glowing door", KEEPR + "tunnel_uw8", "east", "", "");
	set_door_description("glowing door", "%^CYAN%^This strange door "+
	"is made from a rusted and aged metal.  It looks solid though, as "+
	"if a powerful magic was involved with its placement.  This is evidenced by the "+
	"continually pulsing faint glow that it gives off.");
}




