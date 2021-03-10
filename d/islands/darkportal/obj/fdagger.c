#include <std.h>
inherit "/std/weapon";
create(){
    ::create();
    set_id(({"flaming dagger","dagger","flaming"}));
    set_name("flaming dagger");
      set_short("%^RESET%^a %^BOLD%^%^BLUE%^Flaming%^RESET%^ Dagger");
    set_long("The black iron handle is cold to the touch yet it's heads "+
      "%^BOLD%^%^WHITE%^glow%^RESET%^ with a %^BOLD%^%^RED%^mystical flame%^RESET%^."); 
    set_wc(1,4);
    set_large_wc(1,3);
    set_weight(4);
    set_size(1);
    set("value",200);
set_type("slashing");
    set_prof_type("small blades");
set_wield((:TO,"wield_func":));
set_hit((:TO,"extra_hit":));
}

int wield_func(string str){
tell_object(TP,"%^CYAN%^You wrap your hand around the"+
" %^BOLD%^%^BLACK%^cold iron handle%^RESET%^");

return 1;
}

int extra_hit(object targ){
tell_object(ETO,
"%^Your %^BOLD%^%^BLUE%^Flaming%^RESET%^ dagger burns "+targ->query_cap_name()+"");

tell_object(targ,
"You are burned by "+ETO->query_cap_name()+"'s"+
" %^BOLD%^%^BLUE%^Flaming%^RESET%^ dagger");

message("other_action","The %^BOLD%^%^BLUE%^flaming %^RESET%^dagger wielded by "+
""+ETO->query_cap_name()+" burns "+targ->query_cap_name()+""+
"",environment(targ),(({ETO,targ})));
return (roll_dice(2,4));
}
