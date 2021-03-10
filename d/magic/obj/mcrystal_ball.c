//crystal ball for psions to scry through
//For use with Remote Viewing
//~Circe 7/31/05
#include <std.h>
inherit "/d/magic/obj/scry_control";
object spell;
void create() {
    ::create();
    set_alias("crystal ball");
}

int is_temporary() { return 1; }

int self_destruct() {
	object spell;
	
	spell = TO->query_parent();
	spell->remove_call_out("dest_effect");
	spell->dest_effect();
	::self_destruct();
}
