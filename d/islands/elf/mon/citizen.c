#include <std.h>
#include "../elf.h"
inherit NPC;

int head_home;

void create()
{
        ::create();
		set_property("knock unconscious",1);
        set_name("Ashta'Rathai elf");
        set_short("Elven Citizen");
        set_id(({"elf","citizen","elven citizen"}));
		set_gender(random(2)?"male":"female");
        set_long("This is a simple moon elf dressed "+
		"in plain green clothing. "+capitalize(TO->QS)+" carries"+
		" a satchel around as "+TO->QS+" tends the grove.  "+
		capitalize(TO->QS)+" has short black hair and bright green"+
		" eyes.  Like all of "+TO->QP+" kin "+TO->QS+" is very slender"+
		" with soft almost child-like features.");
        
        set_race("elf");
        set_body_type("humanoid");
        set_hd(1,60);
		set_hp(50);
        set_emotes(10,({
        "Elf tends to the grove.",
		"Elf walks around carelessly in the grove.",
		"Elf checks the satchel.",
		"Elf talks happily with some of the other elves in the area.",
		"Elf whistles a carefree tune.",
		"Elf spins around a few times, enjoying the outdoors.",
		"Elf smiles and looks at the sky.",
        }),0);
        command("message in walks with light steps.");
        command("message out walks out with light steps");
        command("speech say merrily");
        set_speed(9);
		set_base_damage_type("bludgeoning");
		
}
