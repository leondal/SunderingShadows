#include <std.h>
inherit "/d/common/obj/weapon/claw";

void create(){
   ::create();
   set_name("hook");
   set_id(({"hook","vicious hook","bloodstained hook"}));
   set_short("%^RESET%^%^RED%^bloodstained %^WHITE%^%^BOLD%^hook%^RESET%^");
   set_long("This is a vicious looking hook, curved back over itself to a sharp point.  There are engravings "
"around its %^BLACK%^%^BOLD%^steel base%^RESET%^, though you can't decipher any meaning from them, and "
"beneath the base are a few straps obviously used to secure the weapon for a fight.  A dark stain of %^RED%^"
"blood%^RESET%^ remains around the tip of the weapon, that seems impossible to remove despite any amount of "
"cleaning.  All and all, this is definitely a nasty looking weapon.");
//   set_wc(1,5);
//   set_large_wc(1,5);
//   set_weight(5);
//   set_size(1);
   set_value(200);
   set_type("piercing");
//   set_prof_type("tool");
   set_property("enchantment",2);
   set_wield("%^RED%^You secure the bloodstained hook with the straps.%^RESET%^");
   set_hit((:TO,"extra_hit":));
   set_lore("%^WHITE%^%^BOLD%^This rather nasty-looking hook is known to be the possession of the old pirate "
"Captain Rust.  He lost his hand many years ago, and was fitted with this hook instead, both to aid him in "
"day-to-day doings, and in combat.  It's rumoured that he doesn't take kindly to jokes about his missing "
"limb.%^RESET%^\n");
   set_property("lore difficulty",12);
}

int extra_hit(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(random(20)<2){
     switch(random(2)) {
       case 0:
       tell_object(ETO,"%^RED%^You catch "+targ->QCN+" with a vicious stab, impaling your hook through their "
"flesh!%^RESET%^");
       tell_object(targ,"%^RED%^"+ETOQCN+"'s bloodstained hook impales itself through your flesh!%^RESET%^");
       tell_room(EETO,"%^RED%^"+ETOQCN+"'s bloodstained hook impales itself through "+targ->QCN+"'s flesh!"
"%^RESET%^",({ETO,targ}));
       return 2;
       break;

       case 1:
       tell_object(ETO,"%^BLUE%^You slash at "+targ->QCN+" with the hook, leaving a horrible puncture wound!"
"%^RESET%^");
       tell_object(targ,"%^BLUE%^"+ETOQCN+" slashes at you with the hook, leaving a horrible puncture wound!"
"%^RESET%^");
       tell_room(EETO,"%^BLUE%^"+ETOQCN+" slashes at "+targ->QCN+" with the hook, leaving a horrible puncture"
" wound!%^RESET%^",({ETO,targ}));
       targ->do_damage(targ->return_target_limb(),roll_dice(2,4)+2);
       break;
     }
   }
}
