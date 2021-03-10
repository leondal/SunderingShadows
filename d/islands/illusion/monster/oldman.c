#include <std.h>

inherit MONSTER;

void create() {
	::create();
	set_name("the old man");
	set_id(({ "man","old","old man","human" }));
	set_short("a wandering old man");
	set_long("You see an old man, clad in rags.");
	set_level(15);
	set("race","human");
	set_gender("male");
	set_body_type("human");
	set_size(2);
	set_alignment(2);
	set_hd(15,0);
	set_class("fighter");
	set_emotes(5,({
		"The old man mumbles,\"Illusions... it's all an ILLUSION!\"",
		"The old man mumbles something under his breath.",
		"The old man points a finger at you and cries out,\""
		"You're just an ILLUSION!!!\"",
		"The old man eyes you suspiciously.",
	}),0);
	new("/d/islands/illusion/misc/glasses")->move(this_object());
	command("wear glasses");
}
