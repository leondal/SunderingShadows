#include <std.h>
inherit "/std/weapon";
string owner;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TPQN;
}
create() {
    ::create();
    set_name("hand of blood");
    set_id(({"hand","hand of blood"}));
    set_short("%^RESET%^%^RED%^Hand of blood%^RESET%^");
    set_long("%^RED%^"
	"This petrified hand oozes blood from the fingers. It is very evil "
	"looking and gives off a magical aura. Long bony claws extend from the hand. "
	"The inside of the hand is hollowed out so it may be wielded by allowing it to cover ones own "
	"hand."
	"%^RESET%^"
    );
    set_weight(5);
    set_value(1000);
    set_wc(1,6);
    set_large_wc(2,4);
    set_type("bludgeoning");
    set_property("enchantment",3);
    set_size(1);
    set_prof_type("demongate hand");
    set_wield((: TO,"extra_wield" :));
    set_unwield((: TO,"extra_unwield" :));
    set_hit((: TO,"extra_hit" :));
}
int extra_wield() {
    if((int)ETO->query_level() < 30) {    
        write("You cannot control the inner power of the hand and it vanishes!");
	TO->remove();
        return 0;
    }
    if((string)ETO->query_name() != owner) {
	write("The hand fails to bond with you and vanishes!");
        TO->remove();
        return 0;
    }
    if((int)ETO->query_alignment() != 9 &&
       (int)ETO->query_alignment() != 6 &&
       (int)ETO->query_alignment() != 3) {
	write("You lack the inner evil to utilize this item!");
	return 0;
    }
    write("%^RED%^"
	"Visions of death and hellfire fill your mind!"
	"%^RESET%^"
    );
    say("%^RED%^"
	+ETO->query_cap_name()+
	"'s face transforms into the visage of the hellspawn!"
	"%^RESET%^"
    ,ETO);
    return 1;
}
int extra_unwield() {
    write("%^RED%^"
	"You slowly peel the hand of blood off of your own apendage."
	"%^RESET%^"
    );
    return 1;
}
int extra_hit(object ob) {
    object vic;
    int dam;
    vic = ETO->query_current_attacker();
    if(random(10) > 1) return 1;
    if((int)vic->query_alignment() == 1 ||
       (int)vic->query_alignment() == 4 ||
       (int)vic->query_alignment() == 7) {    
            message("my_action","%^RED%^"
	        "The hellfire of the hand of blood is delivered into "
	        +vic->query_cap_name()+
                "!\n"
	        +vic->query_cap_name()+" screams as the good within "
	        +vic->query_possessive()+" soul is invaded by hellfire!%^RESET%^"
            ,ETO);
            message("other_action","%^RED%^"
                +ETO->query_cap_name()+
                " delivers the hellfire into "
	        +vic->query_cap_name()+
	        "'s soul!\n"
	        +vic->query_cap_name()+" screams as the good within "
	        +vic->query_possessive()+" soul is invaded by hellfire!%^RESET%^"
            ,environment(vic),(({ETO, vic})));
            message("my_action","%^RED%^"
               +ETO->query_cap_name()+
                " delivers the hellfire into your soul!\n"
	        "You scream as the good within your "
	        " soul is invaded by hellfire!%^RESET%^"
            ,vic);
            dam = (int)ETO->query_stats("strength") +
		  (int)ETO->query_stats("wisdom") +
		  (int)ETO->query_stats("constitution") +
		  (int)ETO->query_level();
            dam = random(dam) + (dam/2);	
            write("After delivering the hellfire, the hand of blood vanishes!");
	    TO->remove();        
    } else {
	dam = 0;
    }
    return dam;
}
