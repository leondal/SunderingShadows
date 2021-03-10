//Cevahir
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create(){
   ::create();
   set_name("%^RESET%^%^MAGENTA%^St%^RESET%^a%^MAGENTA%^lw%^BOLD%^a%^RESET%^%^MAGENTA%^rt D%^BOLD%^e%^RESET%^%^MAGENTA%^fe%^RESET%^n%^MAGENTA%^der%^RESET%^");
   set_short("%^RESET%^%^MAGENTA%^a utilitarian %^RESET%^steel %^MAGENTA%^shield%^RESET%^");
   set_id(({"steel shield","utilitarian shield","shield","utilitarian steel shield","stalwart defender"}));
   set_long("Crafted from %^BOLD%^flawless steel%^RESET%^, this kite shield is spartan in design save for the exquisite depiction of a %^RESET%^%^MAGENTA%^battered crested helm %^RESET%^at its center. The helm's plume is made of glittering %^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^t%^RESET%^h%^BOLD%^y%^MAGENTA%^s%^RESET%^%^MAGENTA%^t%^RESET%^, providing the only real adornment on a shield that is clearly meant for battle. The %^ORANGE%^leather straps %^RESET%^are padded, providing comfort and maneuverability to the shield bearer.");
   set_value(0);
   set_struck((:TO,"strikeme":));
}

int strikeme(int damage, object what, object who){
   if(!random(10)) {
      tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^A pulse of energy from "+ETOQCN+"'s shield envelops "+ETO->QO+" in a faintly %^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple %^BOLD%^glow%^RESET%^%^BOLD%^, absorbing "+who->QCN+"'s attack.%^RESET%^",({ETO,who}));
      tell_object(ETO,"%^BOLD%^%^WHITE%^A pulse of energy from your shield envelops you in a faintly %^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple %^BOLD%^glow%^RESET%^%^BOLD%^, absorbing "+who->QCN+"'s attack.%^RESET%^");
      tell_object(who,"%^BOLD%^%^WHITE%^A pulse of energy from "+ETOQCN+"'s shield envelops "+ETO->QO+" in a faintly %^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple %^BOLD%^glow%^RESET%^%^BOLD%^, absorbing your attack.%^RESET%^");
      return (-1)*damage;
      return 1;
   }
}
