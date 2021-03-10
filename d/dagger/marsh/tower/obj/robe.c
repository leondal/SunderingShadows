#include <std.h>
inherit "/std/armour";
object owner;
int FLAG;
void init() {
    ::init();
    if(interactive(TP) && !owner) owner = TPQN;
    FLAG = 0;
}

create() {
    ::create();
    set_name("robe");
    set_id(({"robe","robe of death","death robe","reaver robe"}));
    set_obvious_short("%^RESET%^%^BLUE%^Dark blue robe%^RESET%^");
    set_short("%^RESET%^%^BLUE%^Robe of death%^RESET%^");
    set_long(
        "%^BLUE%^This blood stained robe is made of an unknown blue "
   "fabric which seems to suck light into it. Its clasp is formed "
	"into the likeness of a cackling skull.%^RESET%^"
    );
//    set_weight(20);
    set_weight(6);
//20 seemed a bit much.  Circe 3/28/05
    set_value(500);
    set_type("clothing");
    set_limbs(({"torso"}));
  set_ac(0);
  set_property("enchantment",4);
    set_wear((:TO,"wearit":));
    set_remove((:TO,"removeit":));
    set_heart_beat(1);
}
int wearit() {
          if((int)ETO->query_highest_level() < 28) {
        write("The magic of the robe rejects you!");
	TO->remove();
        return 0;
    }
    if((string)ETOQN != owner && (string)ETOQN != "reaver") {
	write("The robe fails to bond with you and vanishes!");
        TO->remove();
        return 0;
    }
    if((int)ETO->query_alignment() != 9 &&
	(int)ETO->query_alignment() != 6 &&
	(int)ETO->query_alignment() != 3) {
	write("The robe refuses your body!");
	return 0;
    }
    write(
        "%^BLUE%^A cold deathly chill fills your soul!%^RESET%^"
    );
    tell_room(environment(ETO),
	"%^BLUE%^"+ETOQCN+"'s true evil heart is suddenly revealed!%^RESET%^"
        ,ETO);
   ETO->set_property("evil item",1);
    return 1;
}
int removeit() {
    write("%^BLUE%^The cold deathly chill slowly leaves your soul.%^RESET%^");
    say("%^BLUE%^"+ETOQCN+" suddenly looks less evil.%^RESET%^",ETO);
   ETO->set_property("evil item",-1);
    return 1;
}
void heart_beat() {
    object owned,env,obj,*inv;
    env = ETO;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!TO->query_worn()) return;
    if(objectp(env) && living(env)) {
        owned = env;
        env = environment(owned);
    } else {
        return;
    }
    if(!objectp(env)) return;
    if(owned->query_hp()<owned->query_max_hp())
        if( obj = present("corpse",env)) {
            tell_object(owned,"%^BLUE%^The %^BOLD%^Grim Reaper%^RESET%^%^BLUE%^ suddenly appears before the corpse present and collects it's soul.\n
%^RED%^As he leaves he touches your forehead and a cold chill of passes through you!%^RESET%^"
                );
            owned->heal(owned->query_max_hp()/15+1);
            obj->remove();
            return;
        }
}
