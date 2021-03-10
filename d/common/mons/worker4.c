//worker4.c - Generic workers to be introduced when making additions
//or changes to temples and other places.  Circe 12/31/03
#include <std.h>
inherit MONSTER;

int head_home;

void create()
{
	::create();
	set_name("human worker");
	set_short("A human craftsman");
	set_id(({"worker","human worker","human craftsman","craftsman"}));
	set_long(
         "This stout human has clearly been brought in to help with the "+
         "carpentry here.  He wears a leather toolbelt filled with blocks for "+
         "sanding, planes, hammers, and other tools of his trade.  He is "+
         "dressed in a simple cotton tunic and leather pants, and his "+
         "brown hair is cut short to keep it out of his eyes."
	);
	set_gender("male");
	set_race("human");
	set_body_type("humanoid");
	set_hd(5,3);
	set_exp(15);
	set_emotes(2,({
	"The human works hard, planing a length of wood so that it fits better.",
	"The human craftsmen uses a small chisel to carefully carve an intricate pattern.",
	"The human runs his fingers through his hair as he thinks.",
	"The human craftsman hums as he sands a plank.",	
	}),0);
	call_out("head_home",400+random(100));
}

int head_home()
{
	tell_room(ETO,"%^BOLD%^%^GREEN%^The human worker finishes for the day and walks away.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
