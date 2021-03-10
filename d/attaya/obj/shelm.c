#include <std.h>
inherit "/std/armour";

void create() {
    ::create();
    set_name("visored helm");
    set_id(({ "visored helm", "helmet", "helm"}));
    set_short("%^BOLD%^%^BLACK%^dark v%^RESET%^i%^BOLD%^%^BLACK%^sored helm%^RESET%^");
    set_long(
    " This %^BOLD%^%^BLACK%^dark helm%^RESET%^ features tiny fins, covering the entire surface of protective steel, flaring backward"+
    " away from the face of the helm. The fins are highlighted whenever they catch the light"+
    " giving a unqiue, multi-dimensional, %^BOLD%^%^WHITE%^shine%^RESET%^ to the helm. The face of the helm is"+
    " dominated by a visor set at the forehead of the widow peaked helm."+
    " The %^BOLD%^%^BLACK%^dark tinted%^RESET%^ visor runs down the length of the helm and stops"+
    " just above the nose."
    );
    set_weight(4);
    set_value(4000);
    set_type("helm");
    set_limbs(({ "head" }));
    set_ac(1);
    set_property("enchantment", 3);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
}
int wearme(){
   tell_object(ETO,"%^BOLD%^%^BLACK%^You wear the helmet and everything seems darker.%^RESET%^");
   return 1;
}
int removeme(){
   tell_object(ETO,"%^BOLD%^%^WHITE%^You remove the helm and everything seems clearer.%^RESET%^");
   return 1; 
}

int query_size(){ 
    if(living(ETO)) 
        return ETO->query_size();
    else return 3;
}

int is_metal() { return 1; }