//citizen2.c - new mobs to liven up Kildare Glen.  Adapted from 
//the Antioch citizens.  Circe 12/30/03
#include <std.h>
#include "../kildare.h"
inherit MONSTER;

int head_home;

void create()
{
	::create();
	set_name("young boy");
	set_short("A young boy");
	set_id(({"child","young child","citizen","kid","boy","young boy"}));
	set_long(
         "This young boy could be no older than twelve.  He studies "+
         "the sky silently as he walks, seeming intent on the clouds "+
         "above him.  He wears leather breeches after the fashion of the "+
         "men of Kildare Glen, but he carries no weapon.  His hair is a "+
         "deep dusky brown, and his eyes are clear blue.  From the way "+
         "he carries himself, he is clearly frightened, though he has "+
         "long since learned to control his fear."
	);
	set_gender("male");
	set_race("human");
	set_body_type("humanoid");
	set_hd(1,5);
	set_exp(1);
	set_emotes(10,({
	"The young boy shades his eyes with his hand as he studies the sky.",
	"The boy walks slowly and deliberately down the path.",
	"The boy studies you quietly but says nothing before turning away.",
	"The boy shouts out a warning as he sees a dark shape in the sky, then takes off at a sprint.",	
	}),0);
	command("message in strides in studying the sky");
      command("message out turns his gaze and walks");
	command("speech speak calmly");
	set_speed(9);
      set_nogo(({TROOMS"path2.c",ROOMS"ptrail1",TROOMS"pad1"}));
	call_out("head_home",400+random(100));
}

int head_home()
{
	tell_room(ETO,"%^BOLD%^%^GREEN%^The young boy takes off at a run, heading home.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
