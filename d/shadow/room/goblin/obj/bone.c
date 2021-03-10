//updated by Circe 6/1/04 with new lore, etc by Shar
#include <std.h>
inherit "/d/common/obj/armour/hide.c";
int FLAG;
void init() {
    ::init();
    add_action("look","look");
}
void create() {
    ::create();
    set_name("bone");
    set_id(({"bone","bone armor","armor","Armor"}));
    set_short("%^BOLD%^%^WHITE%^Bone Armor of the Goblins%^RESET%^");
    set_long(
        "This armor is made of leather encased with various bones taken from slain "
	"humans and elves. The spine taken from a fallen warrior has been fused to the skull "
        "of a large human and attached to the armor in such a manner as to allow the wearing "
	"of the skull upon one's head. The bone portions have a soft glow and the leather is as "
	"black as the night. Overall, this armor seems as though it would provide a Goblin "
	"with formidable protection."
       );
    set_lore("Another feat of Goblin sorcery and mysticism is the "+
       "ability to create this magical suit of armor by using the "+
       "bones of enemies.  In a ritual that none have been able to "+
       "discover or manage to recreate successfully the goblins are "+
       "able to use the bones of elves, humans, gnomes and dwarves "+
       "to protect themselves.  By wearing the bones of their foes, "+
       "the goblins believe that they will be protected from any "+
       "attack.  It is considered a great honor in goblinoid society "+
       "to receive such a suit.");
    set_property("lore difficulty",8);
   set_size(1);
   set_value(30);
    set_property("enchantment",1);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
}
int wearit() {
    if((string)TP->query_race() != "goblin") {
	tell_object(ETO,"%^BOLD%^%^WHITE%^"
	    "You are not a Goblin. The armor refuses your body in hatred."
	    "%^RESET%^"
	);
	return 0;
    }
    tell_object(ETO,
        "%^BOLD%^%^WHITE%^You drape the bony armor upon your torso and slowly slip "
	"your head inside the skull. You see the world in a new shade of darkness and cackle "
	"with Goblin pride."
	"%^RESET%^"
    );
    tell_room(EETO,
	"%^BOLD%^%^WHITE%^"+ETOQCN+" wears the bones with pride.",ETO);
    FLAG = 1;
    return 1;
}
int removeit() {
    tell_object(ETO,
	"%^BOLD%^%^WHITE%^You feel a cold shiver pass through you.%^RESET%^"
    );
    tell_room(EETO,
	"%^BOLD%^%^WHITE%^"
	"A cold shiver passes through your body and you feel sick."
	"%^RESET%^"
    ,ETO);
    FLAG = 0;
    return 1;
}
int look(string str) {
    if(!TO->query_worn()) {
        return 0;
   }
    if(TP->query_invis()) return 0;
        tell_object(ETO,"%^BOLD%^%^WHITE%^"
            "You boldly cast your Goblin gaze upon your surroundings."
        );
        if (!str || str == "$*") {
            tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" stares "+
               "coldly at you.",ETO);
        }
        return 0;
}
