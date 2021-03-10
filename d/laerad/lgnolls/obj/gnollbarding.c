//Essyllis: Feb 2015
#include <std.h>
#include "../lgnoll.h"
inherit "/d/common/obj/armour/pcleatherbarding";

void create() {
     ::create();
     set_name("%^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ll-h%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^de %^MAGENTA%^h%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^lf-b%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^rd%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^ng%^RESET%^");
     set_id(({ "barding", "leather barding", "half-barding", "gnollhide", "gnoll-hide" }));
     set_short("%^ORANGE%^gn%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^ll-h%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^de %^MAGENTA%^h%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^lf-b%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^rd%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^ng%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^A black %^RESET%^%^ORANGE%^thick leather %^BOLD%^%^BLACK%^half-barding%^RESET%^"); 
    set_long("%^ORANGE%^This half-barding is clearly made of Gn%^RED%^o%^ORANGE%^ll-h%^RED%^i%^ORANGE%^d%^RED%^e%^ORANGE%^! "+
	"Even though the h%^RED%^i%^ORANGE%^de is not boiled as normal hide would be, this "+
	"r%^RED%^a%^ORANGE%^w-h%^RED%^i%^ORANGE%^de is so thick that it is sure to give ample "+
	"protection, both against blows in combat as well as wind and weather. The half-barding "+
	"extends half-way down all four legs, leaving only ankles and %^RED%^paws%^ORANGE%^"+
	"/%^BOLD%^%^BLACK%^h%^RESET%^oo%^BOLD%^%^BLACK%^ves %^RESET%^%^ORANGE%^free. It is "+
	"laced up on the stomach to provide cover to the side of the lower-torso.%^RESET%^\n");
    set_value(15);
    set_size(3);
	set_property("enchantment",3);
	set_item_bonus("armor bonus",1);
	set_wear((:TO,"wear_it":));
    set_remove((:TO,"remove_it":));
    set_struck((:TO,"bump":));
}

int wear_it(){
	if(ETO->query_level() < 15){
		tell_object(ETO,"%^GREEN%^This armor is still too cumbersome for you to wear.");
		tell_room(EETO,"%^GREEN%^"+ETO->QCN+"%^RESET%^%^GREEN%^ doesn't seem to be able to don the half-barding.",ETO);
	return 0;}
	
	tell_object(ETO,"%^BOLD%^%^BLACK%^You don the %^RESET%^%^ORANGE%^Gn%^RED%^o%^ORANGE%^ll%^BOLD%^%^BLACK%^-%^RESET%^%^ORANGE%^h%^RED%^i%^ORANGE%^de h%^RED%^a%^ORANGE%^lf%^BOLD%^%^BLACK%^-%^RESET%^%^ORANGE%^b%^RED%^a%^ORANGE%^rd%^RED%^i%^ORANGE%^ng %^BOLD%^%^BLACK%^on your lower-torso and feel more %^RESET%^%^MAGENTA%^protected.");
	tell_room(EETO,""+ETO->QCN+" %^BOLD%^%^BLACK%^dons the thick %^RESET%^%^ORANGE%^gn%^RED%^o%^ORANGE%^ll-h%^RED%^i%^ORANGE%^d%^RED%^e %^ORANGE%^h%^RED%^a%^ORANGE%^lf%^BOLD%^%^BLACK%^-%^RESET%^%^ORANGE%^b%^RED%^a%^ORANGE%^rd%^RED%^i%^ORANGE%^ng %^BOLD%^%^BLACK%^over %^RESET%^"+ETO->QCN+"'s %^BOLD%^%^BLACK%^lower torso%^RESET%^.",ETO);
return 1;}

int remove_it(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the %^RESET%^%^ORANGE%^Gn%^RED%^o%^ORANGE%^ll-h%^RED%^i%^ORANGE%^d%^RED%^e %^ORANGE%^h%^RED%^a%^ORANGE%^lf-b%^RED%^a%^ORANGE%^rd%^RED%^i%^ORANGE%^ng %^BOLD%^%^BLACK%^and feel much more %^RESET%^%^MAGENTA%^vulnerable.%^RESET%^");
	tell_room(EETO,""+ETO->QCN+" %^ORANGE%^removes "+ETO->QP+" gn%^RED%^o%^ORANGE%^ll-h%^RED%^i%^ORANGE%^d%^RED%^e %^ORANGE%^h%^RED%^a%^ORANGE%^lf-b%^RED%^a%^ORANGE%^rd%^RED%^i%^ORANGE%^ng, exposing %^WHITE%^"+ETO->QP+" %^ORANGE%^lower-torso.%^RESET%^",ETO);
	return 1;
}

int bump(int damage, object what, object bumptarg){
        object rakey;
//tell_room(EETO,"ETO is "+base_name(ETO)+" and bumptarg is "+base_name(bumptarg)+".");
        if(!objectp(ETO)) return 0;
        if(!objectp(bumptarg)) return 0;
	if((string)ETO->query_race() == "wemic"){
                tell_object(ETO,"%^MAGENTA%^As %^WHITE%^"+bumptarg->QCN+" %^MAGENTA%^tries to hit your lower-torso, you rise up on your hind-legs and %^BOLD%^%^RED%^rake %^RESET%^"+bumptarg->QO+" %^RED%^t%^BOLD%^e%^RESET%^%^RED%^rr%^BOLD%^i%^RESET%^%^RED%^bl%^BOLD%^y%^RESET%^%^RED%^!%^RESET%^");
                tell_room(EETO,"%^MAGENTA%^As "+bumptarg->QCN+" tries to hit "+ETO->QCN+"'s lower-torso, "+ETO->QCN+" rises to "+ETO->QP+" hindlegs and %^BOLD%^%^RED%^rakes %^RESET%^%^MAGENTA%^"+bumptarg->QCN+" %^RED%^t%^BOLD%^e%^RESET%^%^RED%^rr%^BOLD%^i%^RESET%^%^RED%^bl%^BOLD%^y!%^RESET%^",ETO);
                tell_object(bumptarg,"%^MAGENTA%^As you try to hit %^WHITE%^"+ETO->QCN+"%^MAGENTA%^'s lower-torso, %^WHITE%^"+ETO->QS+" %^MAGENTA%^rises on "+ETO->QP+" hind-legs and %^BOLD%^%^RED%^rakes %^RESET%^%^MAGENTA%^you %^RED%^t%^BOLD%^e%^RESET%^%^RED%^rr%^BOLD%^i%^RESET%^%^RED%^bl%^BOLD%^y%^RESET%^%^MAGENTA%^!%^RESET%^");
		rakey = new(OBJ"rake");
        rakey->move(bumptarg);
        rakey->hurt(bumptarg);
	return (damage*(1/2));}
	
	if((string)ETO->query_race() == "centaur"){
                tell_object(ETO,"%^MAGENTA%^As %^WHITE%^"+bumptarg->QCN+" %^MAGENTA%^tries to hit your lower-torso, you rise up on your hind-legs and send %^WHITE%^"+bumptarg->QO+" %^BOLD%^%^BLACK%^spawling %^RESET%^%^MAGENTA%^with a %^ORANGE%^knock %^MAGENTA%^from your %^ORANGE%^fr%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^nt h%^BOLD%^%^BLACK%^oo%^RESET%^%^ORANGE%^ves!%^RESET%^");
                tell_room(EETO,"%^MAGENTA%^As %^WHITE%^"+bumptarg->QCN+" %^MAGENTA%^tries to hit %^WHITE%^"+ETO->QCN+"%^MAGENTA%^'s lower-torso, %^WHITE%^"+ETO->QCN+" %^MAGENTA%^rises to %^WHITE%^"+ETO->QP+" %^MAGENTA%^hind-legs and sends %^WHITE%^"+bumptarg->QCN+" %^MAGENTA%^to the %^BOLD%^%^BLACK%^ground %^RESET%^%^MAGENTA%^with a %^BOLD%^%^BLACK%^knock %^RESET%^%^MAGENTA%^of %^WHITE%^"+ETO->QCN+" %^ORANGE%^fr%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^nt h%^BOLD%^%^BLACK%^oo%^RESET%^%^ORANGE%^ves%^MAGENTA%^!%^RESET%^");
                tell_object(bumptarg,"%^MAGENTA%^As you try to hit %^WHITE%^"+ETO->QCN+"%^MAGENTA%^'s lower-torso, %^WHITE%^"+ETO->QS+" %^MAGENTA%^rises on "+ETO->QP+" hind-legs and %^BOLD%^%^BLACK%^knocks %^RESET%^%^MAGENTA%^you to the %^BOLD%^%^BLACK%^ground %^RESET%^%^MAGENTA%^with "+ETO->QP+" %^ORANGE%^fr%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^nt h%^BOLD%^%^BLACK%^oo%^RESET%^%^ORANGE%^ves%^MAGENTA%^!%^RESET%^");
                bumptarg->do_damage(bumptarg->return_target_limb(),roll_dice(4,4)+4);
                bumptarg->set_tripped(1,"Get back on your feet first!");
	return (damage*(1/2));}
}
