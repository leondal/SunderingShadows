// rank 3 beastie
#include <std.h>
inherit "/d/magic/mon/naturesally/natureally.c";

void create(){
    ::create();
    set_id(({"wolf","dire wolf","ragged wolf","ragged dire wolf","natures ally"}));
    set_short("%^BOLD%^%^BLACK%^rag%^RESET%^ge%^BOLD%^%^BLACK%^d dire wolf%^RESET%^");
    set_long("The lupine before you is of considerable size, with a smoky black coat that fades to off-white on its chest "
"and paws.  A brush tail follows the wolf as it stalks along, paws silent upon the ground.  Ears lift at the slightest "
"noise, the creature ever alert to its surroundings.  This particular specimen seems even more vicious than most, with a "
"feral, almost demonic gleam in its dark eyes.");
    set_race("wolf");
    set_body_type("quadruped");
    add_limb("teeth","head",0,0,0);
    set_attack_limbs(({"teeth"}));
    set_base_damage_type("slashing");
}

void my_special(object target) {
    if(!objectp(target)) return;
    tell_object(target,"%^BOLD%^%^CYAN%^The wolf darts back and forth, harrying your movements and snapping at your heels!%^RESET%^");
    tell_room(ETO,"%^BOLD%^%^CYAN%^The wolf darts back and forth, harrying "+target->QCN+"'s movements and snapping at "+target->QP+" heels!%^RESET%^",target);
    TO->set_property("magic",1);
    target->do_damage("torso",random(30)+mylevel);
    TO->remove_property("magic");
}