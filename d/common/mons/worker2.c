//worker2.c - Generic workers to be introduced when making additions
//or changes to temples and other places.  Circe 12/31/03
#include <std.h>
inherit MONSTER;

int head_home;

void create()
{
	::create();
	set_name("elven worker");
	set_short("An elven craftsman");
	set_id(({"worker","elven worker","elven craftsman","craftsman"}));
	set_long(
         "This ageless elf has long golden hair pulled back in narrow "+
         "braids around the crown.   The rest of the hair flows freely "+
         "down her back to her slim waist.  She wears a vibrant green "+
         "robe trimmed in white that is belted at her waist with a "+
         "length of silken rope.  In her hands is a leather case filled "+
         "with sheets of paper.  At her waist is a simple leather pouch "+
         "full of writing implements and ink."
	);
	set_gender("female");
	set_race("elf");
	set_body_type("humanoid");
	set_hd(2,3);
	set_exp(10);
	set_emotes(2,({
	"The elf perches lightly on the ground and draws awhile, humming quietly as she studies the area.",
	"The elven craftsman steps lightly around, nodding to herself.",
	"The elf tilts her head and studies the land, drawing swiftly on a sheet of paper.",
	"The elven craftsman runs her fingers lightly along the stone, singing softly.",	
	}),0);
	call_out("head_home",400+random(100));
}

int head_home()
{
	tell_room(ETO,"%^BOLD%^%^GREEN%^The elven worker closes her case and steps lightly out.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
