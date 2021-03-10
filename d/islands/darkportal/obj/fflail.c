#include <std.h>
inherit "/std/weapon";
create(){
    ::create();
    set_id(({"flaming flail","flail","flaming"}));
    set_name("flaming flail");
      set_short("%^RESET%^a %^BOLD%^%^RED%^Flaming%^RESET%^ Flail");
    set_long("The black iron handle is cold to the touch yet it's heads "+
      "%^BOLD%^%^WHITE%^glow%^RESET%^ with a %^BOLD%^%^RED%^mystical flame%^RESET%^."); 
    set_wc(2,3);
    set_large_wc(1,7);
    set_weight(4);
    set_size(1);
    set("value",200);
set_type("bludgeoning");
    set_prof_type("flail");
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
"%^Your %^BOLD%^%^RED%^Flaming%^RESET%^ flail burns "+targ->query_cap_name()+"");

tell_object(targ,
"You are burned by "+ETO->query_cap_name()+"'s"+
" %^BOLD%^%^RED%^Flaming%^RESET%^ flail");

message("other_action","The %^BOLD%^%^RED%^flaming %^RESET%^flail wielded by "+
""+ETO->query_cap_name()+" burns "+targ->query_cap_name()+""+
"",environment(targ),(({ETO,targ})));
return (roll_dice(2,4));
}
