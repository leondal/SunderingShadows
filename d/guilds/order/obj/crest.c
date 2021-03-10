// Order guild object

#include <std.h>
inherit ARMOUR;

void create(){
    ::create();
	set_name("crest");
        set_id(({"crest of the metallic dragons","crest","Crest","Crest of the Metallic Dragons"}));
   set_short("%^YELLOW%^Crest of the Metallic Dragons%^RESET%^");
	set_long(
@OLI
%^YELLOW%^The image of a majestic platinum dragon rests mystically on its
owner's chest.  As you gaze upon it, the eyes seem to glow brightly
as the nostrils flare.
OLI
	);
	set_weight(5);
	set_limbs(({"torso"}));
	set_value(1);
	set_type("ring");
}


