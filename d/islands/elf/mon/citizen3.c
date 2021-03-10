#include <std.h>
#include "../elf.h"
inherit NPC;

void create()
{
        ::create();
        set_property("knock unconscious",1);
        set_name("wild elf");
        set_short("wild elf");
        set_id(({"elf","citizen","wild elf"}));
                set_gender(random(2)?"male":"female");
        set_long("This is a simple wild elf dressed "+
                "in plain green clothing. "+capitalize(TO->QS)+" carries"+
                " a bow around as "+TO->QS+" stalks the grove.  "+
                capitalize(TO->QS)+" has short brown hair and hazel"+
                " eyes.  Like all of "+TO->QP+" kin "+TO->QS+" is very slender"+
                " with soft almost child-like features.");
        
        set_race("elf");
        set_body_type("humanoid");
        set_hd(1,60);
                set_hp(50);
        set_emotes(10,({
        "Elf watches the grove.",
                "Elf walks cautiously peeks out from behind a tree.",
                "Elf inspects the bow.",
                "Elf quietly nods in greeting to the other elves in the area.",
                "Elf munches on some nuts and berries.",
                "Elf inspects the plants.",
                "Elf smiles as a bird flies by.",
        }),0);
        command("message in walks with light steps.");
        command("message out walks out with light steps");
        command("speech say merrily");
        set_speed(9);
                set_base_damage_type("bludgeoning");
                
}
