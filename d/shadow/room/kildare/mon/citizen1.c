//citizen1.c - new mobs to liven up Kildare Glen.  Adapted from 
//the Antioch citizens.  Circe 12/30/03
#include <std.h>
#include "../kildare.h"
inherit MONSTER;

int head_home;

void create()
{
	::create();
	set_name("young girl");
	set_short("A young girl");
	set_id(({"child","young child","citizen","kid","girl","young girl"}));
	set_long(
         "This girl looks to be about nine years of age.  Her hair is "+
         "covered in a dark green woolen scarf that has been pulled "+
         "tightly under her chin to fight the cold.  She wears a heavily "+
         "padded coat with a fur lining, and her cheeks and tiny nose are "+
         "tinged bright pink.  She moves quickly, her eyes constantly "+
         "scanning the sky as she makes her way down the path."
	);
	set_gender("female");
	set_race("human");
	set_body_type("humanoid");
	set_hd(1,5);
	set_exp(1);
	set_emotes(10,({
	"The girl's frightened blue eyes look quickly to the sky.",
	"The girl tightens her scarf and ducks her head, walking quickly.",
	"The girl looks at you with wide eyes before hurrying away.",
	"The young girl whimpers and hunkers down as a large shape wheels in the sky.",	
	}),0);
	command("message in walks in quickly with her head down");
      command("message out skitters away to the");
	command("speech speak with a frightened whimper");
	set_speed(9);
      set_nogo(({TROOMS"path2",ROOMS"ptrail1",TROOMS"pad1"}));
	call_out("head_home",400+random(100));
}

int head_home()
{
	tell_room(ETO,"%^BOLD%^%^GREEN%^The young girl sprints away down the path.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
