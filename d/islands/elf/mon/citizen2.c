#include <std.h>
#include "../elf.h"
inherit NPC;

void create()
{
        ::create();
        set_name("wild elf");
        set_short("wild elf");
        set_id(({"elf","citizen","elven citizen"}));
		set_gender(random(2)?"male":"female");
        set_long("This is a simple wild elf dressed "+
		"in rugged green clothing. "+capitalize(TO->QS)+" carries"+
		" a bag around as "+TO->QS+" wanders the grove.  "+
		capitalize(TO->QS)+" has wild brown hair and bright blue"+
		" eyes.  Like all of "+TO->QP+" kin "+TO->QS+" is very slender"+
		" with a slightly stocky build.");       
        set_race("elf");
        set_hd(1,60);
		set_hp(50);
        set_emotes(10,({
        "Elf checks the plants.",
		"Elf sneaks about.",
		"Elf plants some seeds.",
		"Elf stops to enjoy nature.",
		"Elf sings about a lost forest.",
		"Elf hops from tree to tree.",
		"Elf vanishes into the mist.",
        }),0);
        command("message in walks with light steps.");
        command("message out walks out with light steps");
        command("speech say merrily");
        set_speed(9);
		set_base_damage_type("bludgeoning");
		
}
