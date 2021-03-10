// hooded cloak by *Styx* to shade eyes for light sensitivity

#include <std.h>

inherit "/std/armour";

void create() {
    ::create();
    set_name("hooded cloak");
    set_id( ({ "cloak", "hooded cloak" }) );
    set_short("A hooded cloak");
    set_long("This is a hooded cloak woven from a dark, dense, soft cloth "	
	"that does not reflect much light.  The cloth is tightly woven "
	"and is heavy enough that the hood can help shade sensitive eyes "
	"from sunlight or bright room lighting."
    );
    set_weight(10);
    set_value(30);
    set_type("clothing");
    set_limbs( ({ "neck" }) );
    set_ac(0);
    set_size(2);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}

int wearme() {
   tell_object(ETO,"As you pull on the cloak, the hood helps shade your eyes "
	"from bright lights.");
   ETO->add_sight_bonus(-2);
   return 1;
}

int removeme() {
   tell_object(ETO,"Your eyes adjust to no longer being shaded from light as you "
	"remove the cloak.");
   ETO->add_sight_bonus(2);
   return 1;
}

int is_metal() { return 0; }