//citizen3.c - new mobs to liven up Kildare Glen.  Adapted from 
//the Antioch citizens.  Circe 12/30/03
#include <std.h>
#include "../kildare.h"
inherit MONSTER;

int head_home;

void create()
{
	::create();
	set_name("shepherd");
	set_short("A shepherd");
	set_id(({"man","shepherd","citizen","young shepherd","young man"}));
	set_long(
         "Dressed in a plain cotton tunic over leather breeches, this "+
         "young man seems accustomed to the cold of Kildare Glen.  He "+
         "carries with him a shepherd's crook, and he keeps a careful eye "+
         "on the pastures of the Glen.  His face seems unusually tanned "+
         "and weathered for his young age, and the wisdom in his blue eyes "+
         "reveals the horrors he has seen.  His long black hair is kept "+
         "tied at the base of his neck with a simple leather cording, and "+
         "he wears a headband decorated with owls upon his brow."
	);
	set_gender("male");
	set_race("human");
	set_body_type("humanoid");
	set_hd(1,5);
	set_exp(1);
	set_emotes(10,({
	"The shepherd whistles, and the call is answered from farther out in the pasture.",
	"The shepherd reclines against a rock, watching the sky intently.",
	"The young shepherd gently nudges a few sheep closer to the hut.",
	}),0);
	command("message in walks in calmly");
      command("message out leans upon his crook and walks");
	set_speed(9);
      set_nogo(({TROOMS"path14",TROOMS"shephut"}));
	call_out("head_home",400+random(100));
}

int head_home()
{
	tell_room(ETO,"%^BOLD%^%^GREEN%^The shepherd gathers the sheep and heads for his hut.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
