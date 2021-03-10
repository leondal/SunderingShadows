// Order guild object

#include <std.h>
inherit "/std/guild";

void create(){
	guild::create();
	set_name("crest");
	set_id(({"crest","Crest","crest of the metallic dragons","Crest of the Metallic Dragons"}));
	set_short("%^YELLOW%^Crest of the Metallic Dragons");
	set_long(
@OLI
%^YELLOW%^The image of a majestic platinum dragon rests mysticaly on its
owners chest.  As you gaze upon it, the eyes seem to glow brightly
as the nostrils flare.
OLI
	);
        set_ac(0);
	set_weight(5);
	set_limbs(({"torso"}));
	set_value(1);
	set_guild_name("Order of the Metallic Dragon");
  set_guild_items(({base_name(TO)}));
    set_leader("mordred");
    set_guild_hc(({"fyndlorn","cromack","stilgar"}));
	set_type("ring");
}

void init(){
    ::init();
    if(ETO == TP){
        TP->force_me("wear crest");
    }
}

int drop(){
	return 1;
}
