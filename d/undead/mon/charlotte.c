#include "../undead.h"
inherit "/std/comp_vend.c";

void create(){
   ::create();
   set_name("charlotte");
   set_id(({"charlotte","shop keeper","mage","girl","half-elf girl"}) );
   set_short("Charlotte, a scruffy half-elf girl");
   set_long("%^RESET%^%^CYAN%^Charlotte is only young, barely ten years of age "
"by the look of her.  It seems, though, that she fends for herself here, "
"selling all kinds of %^MAGENTA%^strange substances %^CYAN%^to the town's "
"visitors.  Despite the undesirable look of her wares, she gets regular "
"customers, each of which she greets with a %^YELLOW%^bright smile %^RESET%^"
"%^CYAN%^that lights up her otherwise grubby face.%^RESET%^\nTo get a list of "
"shop commands, type help shop.");
   set_gender("female");
   set_alignment(8);
   set_race("half-elf");
   set_body_type("human");
   set_class("mage");
   set_hd(30,1);
   set_max_hp(300);
   set_hp(300);
   set_property("no bump", 1);
   set_components(100);
   set_spell_chance(80);
   set_spells(({"lightning bolt","lightning orb","lightning orb","lightning bolt","sonic shield","magic missile","magic missile","magic missile"}));
}
