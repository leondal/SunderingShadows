#include <std.h>
inherit "/std/weapon";
string owner;
int uses;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TPQN;
}
create() {
    ::create();
    set_name("hand of chaos");
    set_id(({"hand","hand of chaos"}));
    set_short("%^RESET%^%^MAGENTA%^Hand of chaos%^RESET%^");
    set_long("%^MAGENTA%^"
	"This petrified hand is surrounded by a chaotic swirl of multi-colored light. The pattern is very chaotic "
	"looking and the hand gives off a magical aura. Long bony spikes extend from the hand. "
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
    uses = 4;
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
       (int)ETO->query_alignment() != 8 &&
       (int)ETO->query_alignment() != 7) {
	write("You lack the inner chaos to utilize this item!");
	return 0;
    }
    write("%^MAGENTA%^"
	"Visions of chaos and insanity fill your mind!"
	"%^RESET%^"
    );
    say("%^MAGENTA%^"
	+ETO->query_cap_name()+
	"'s face transforms into the visage of chaos!"
	"%^RESET%^"
    ,ETO);
    return 1;
}
int extra_unwield() {
    write("%^MAGENTA%^"
	"You slowly peel the hand of chaos off of your own apendage."
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
       (int)vic->query_alignment() == 2 ||
       (int)vic->query_alignment() == 3) {    
            message("my_action","%^MAGENTA%^"
	        "The chaotic energy of the hand of chaos is delivered into "
	        +vic->query_cap_name()+
                "!\n"
	        +vic->query_cap_name()+" screams as the law within "
	        +vic->query_possessive()+" soul is invaded by the choatic energy!%^RESET%^"
            ,ETO);
            message("other_action","%^MAGENTA%^"
                +ETO->query_cap_name()+
                " delivers the chaotic energy of the hand of chaos into "
	        +vic->query_cap_name()+
	        "'s soul!\n"
	        +vic->query_cap_name()+" screams as the law within "
	        +vic->query_possessive()+" soul is invaded by chaotic energy!%^RESET%^"
            ,environment(vic),(({ETO, vic})));
            message("my_action","%^MAGENTA%^"
               +ETO->query_cap_name()+
                " delivers the chaotic energy of the hand of chaos into your soul!\n"
	        "You scream as the law within your "
	        " soul is invaded by chaotic energy!%^RESET%^"
            ,vic);
            dam = (int)ETO->query_level();
            dam = random(dam) + (dam/2);
            uses--;
	    if(uses < 1) {
                write("After delivering the chaotic energy, the hand of chaos vanishes!");
                TO->remove();        
	    }
    } else {
	dam = 0;
    }
    return dam;
}
