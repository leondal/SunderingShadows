//worker3.c - workers to help advance the plot to open new Seneca
//They are being dropped in a few weeks before opening to give 
//players a hint.  They will disappear once the plot's done.
//~Circe~ 1/27/08
#include <std.h>
inherit MONSTER;

int head_home;

void create(){
   ::create();
   set_name("mason");
   set_short("A skilled dwarven mason");
   set_id(({"worker","dwarven mason","skilled mason","dwarf mason","skilled dwarven mason"}));
   set_long(
      "Dressed in a leather jerkin and carrying a thick pair of "+
      "gloves, this mason appears ready to begin work any second - "+
      "if only he can find his work location.  His thick curly "+
      "hair is pulled back and braided, while his beard is kept "+
      "relatively short for a dwarf.  He studies his surroundings "+
      "with a dazed expression, almost as if he is not sure where "+
      "he is.");
   set_gender("male");
   set_race("dwarf");
   set_body_type("humanoid");
   set_hd(10,3);
   set_exp(10);
   set_emotes(6,({
	"The mason taps his gloves against his palm and turns in a slow circle.",
	"%^MAGENTA%^The mason grumbles%^RESET%^: Can't tell I did a lick of work on it...",
	"The mason walks towards a building, stops suddenly, and then walks towards another.",	
   }),0);
   call_out("head_home",400+random(100));
}

int head_home(){
	tell_room(ETO,"%^BOLD%^%^GREEN%^The mason tugs on his gloves and heads home, grumbling to himself.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
