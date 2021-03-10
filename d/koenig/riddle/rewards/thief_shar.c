#include <std.h>
#include "../../nereid.h"
inherit NHAT;

void create(){
	::create();
	set_name("hood of the black night");
	set_id(({ "hood", "hood of the black night" }));
	set_short("%^RESET%^%^MAGENTA%^Hood of the%^BOLD%^%^BLACK%^ Black%^RESET%^%^MAGENTA%^ Night%^RESET%^");
	set_obvious_short("An inky black hood");
	set_long("%^BOLD%^%^BLACK%^Made of some unknown light weight substance, this"+
		" hood seems as if it carries with it a double boon.  The pitch black"+
		" hood it shaped where one slips their head up under it and a mantle of"+
		" fabric covers their shoulders.  The hood itself is cut full, though "+
		"not to full, allowing the hood itself to cast a deep shadow on the "+
		"wearer's face.  As you feel the hood it almost seem as if the material"+
		" is as strong as leather, but thinner, offering some decent protection."+
		"  It almost seems at times if faint diminutive motes of light can be "+
		"seen in the fabric itself, but they very faint light fades out quickly.%^RESET%^");
	set_lore(
@AVATAR
Rumors of the Hood of the Black Night seem to attribute this piece of clothing to followers of Mask, who use the hood to help hide their face as they prowl the night.  There are rumors of bands of thieves wearing these hoods who make bold attackes against followers of Selune during the night.  The hood seems to offer the wearer some aid in hiding in the blackness of the night, for those few who have survived such an attack speak of how it seems so many people just appeared out of the darkness, their faces shrouded in the inky black darkness.

AVATAR
	);
      set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" pulls the inky black hood from their face, revealing themselves to the world.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You pull off the hood, revealing yourself to the world.  You know though that your skills as a Sharran will come to be needed again soon.");
	return 1;
}
