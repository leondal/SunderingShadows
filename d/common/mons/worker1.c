//worker1.c - Generic workers to be introduced when making additions
//or changes to temples and other places.  Circe 12/31/03
#include <std.h>
inherit MONSTER;

int head_home;

void create()
{
	::create();
	set_name("dwarven worker");
	set_short("A dwarven craftsman");
	set_id(({"worker","dwarven worker","dwarven craftsman","craftsman"}));
	set_long(
         "This dwarf looks to be middle-aged, with a craggy and weathered "+
         "face covered largely by his deep black beard.  His beard is braided "+
         "simply to keep it out of his way, and he wears a practical leather "+
         "apron.  His hands are rough and calloused, and his blue eyes are "+
         "cool and calculating.  He seems focused on the task at hand and not "+
         "inclined to waste time in idle chat."
	);
	set_gender("male");
	set_race("dwarf");
	set_body_type("humanoid");
      set_size(1);
	set_hd(3,5);
	set_exp(15);
	set_emotes(2,({
	"The dwarf runs his hand along his beard as he studies the the layout of the building.",
	"The dwarven craftsman mutters quietly to himself as he looks over a length of parchment.",
	"The dwarf nods quietly and looks up, clearly seeing the building as it will soon be.",
	"The dwarf scribbles on a length of parchment, filling it with drawings and calculations.",	
	}),0);
	call_out("head_home",400+random(100));
}

int head_home()
{
	tell_room(ETO,"%^BOLD%^%^GREEN%^The dwarven craftsman gathers his belongings and leaves.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
