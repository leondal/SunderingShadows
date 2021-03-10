#include <std.h>
inherit "/std/weapon";
create() {
    ::create();
    set_name("destroyer");
    set_id(({"destroyer","sword","sword of destruction"}));
    set_short("%^RESET%^%^BLUE%^Sword of Destruction%^RESET%^");
    set_long(
            "This dark blade is used by the dark knights of the realm.  The legendary sword was supposed to be destroyer of all that is good and pure.  None could stand up to such an awesome blade created by an evil goddess.  This sword radiates pure evil."
            );
    set_weight(12);
    set_size(2);
    set_value(2000);
    set_wc(1,8);
    set_large_wc(1,12);
    set_type("slashing");
    set_property("enchantment",4);
    set_prof_type("destroyer");
    set_wield ( (: TO, "checks" :) );
    set_hit ( (: TO, "extra_hit" :) );
}
int checks() {
      if((int)TP->query_level() < 29) {
         write("You are to inexperienced too wield this weapon!");
        return 0;
    }
     write(
        "%^RESET%^%^BLUE%^An intense feeling of evil flows into you."
    );
     say(
        "%^RESET%^%^BLUE%^"+TPQCN+"'s mouth forms an evil grimace."
    ,TP);
    return 1;
}  
int extra_hit() {
    object ob;
    int dam,FLAG;
    FLAG = 0;
   ob=ETO->query_current_attacker();
    if(!objectp(ob)) return random(5);
    if(random(6) > 3) return 1;
    if( random(100) > 40) {
        if((int)ob->query_alignment() == 1 ||
           (int)ob->query_alignment() == 4 ||
           (int)ob->query_alignment() == 7) {
            FLAG = 1;
            dam = dam + random(5) + 1;
        } else {
              dam = dam;
        }
    }
    if(random(100) > 50) {
        dam = dam + random(6) + 2;
    } else {
        dam = dam + random(3) + 1;
    }
    tell_object(TP,
             "%^RESET%^%^BLUE%^The sword shimmers as it slices through "+ob->query_cap_name()+"!"
    );    
    if (FLAG == 1) {
        tell_object(TP,
        "%^RESET%^%^BLUE%^"+ob->query_cap_name()+" drops to "+ob->query_possessive()+" knees as pure evil cuts through "+ob->query_objective()+"."
        );
        FLAG = 0;
    }
     tell_room(environment(query_wielded()),
      "%^RESET%^%^BLUE%^"+ETO->query_cap_name()+"'s sword shimmers as it slices through "+ob->query_cap_name()+"!" ,({ETO,ob}));
    tell_object(ob,
     "%^RESET%^%^BLUE%^"+ETO->query_cap_name()+"'s sword shimmers as it slices through you."
    );
    return dam;
}
