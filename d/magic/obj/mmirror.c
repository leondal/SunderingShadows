// A Magic Scrying Mirror (for the Magic Mirror spell)
// Thorn@Shadowgate
// 010103
// Wizard spell items
// mmirror.c

#include <std.h>
inherit "/d/magic/obj/scry_control";
object spell;
create() {
    ::create();
    set_property("no offer",1);
    set_alias("mirror");
}

int is_temporary() { return 1; }

int self_destruct() {
	object spell;
	
	spell = TO->query_parent();
	spell->remove_call_out("dest_effect");
	spell->dest_effect();
	::self_destruct();
}
