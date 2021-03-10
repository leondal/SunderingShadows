#include <std.h>
#include "../elf.h"
inherit NPC;

void create()
{
        ::create();
		set_property("knock unconscious",1);
        set_name("elven child");
        set_short("Elven child");
        set_id(({"elf","child","elven child"}));
		set_gender(random(2)?"male":"female");
        set_long("This is a simple moon elf dressed "+
		"in plain cyan clothing. "+capitalize(TO->QS)+" carries"+
		" a toy around as "+TO->QS+" plays in the grove.  "+
		capitalize(TO->QS)+" has short black hair and bright green"+
		" eyes.  Like all of "+TO->QP+" kin "+TO->QS+" is very slender.");
        
        set_race("elf");
        set_body_type("humanoid");
        set_hd(1,60);
		set_hp(50);
        set_emotes(10,({
        "Child plays in the grove.",
		"Child hops around carelessly following a frog.",
		"Child spots a rabbit and laughs happily.",
		"Child shouts at some other children in the area.",
		"Child sings happily.",
		"Child pokes at some bugs.",
		"Child runs circles around a tree.",
        }),0);
        command("message darts in.");
        command("message out skips off ");
        command("speech say merrily");
        set_speed(9);
		set_base_damage_type("bludgeoning");
		
}
