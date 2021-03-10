#include <std.h>
#include <magic.h>
inherit "/d/magic/obj/lockweapons/eldritch_claw";

void create() {
   ::create();
   set_id(({"eldritch claw","claw","energy claw","claw of energy","claw of searing energy","eldritch_weapon_xxx"}));
   set_short("%^RESET%^%^CYAN%^cl%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^w of %^RED%^s%^BOLD%^%^RED%^e%^YELLOW%^a%^RESET%^%^RED%^r%^MAGENTA%^i%^BOLD%^%^RED%^n%^RESET%^%^RED%^g e%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^r%^BOLD%^%^RED%^g%^RESET%^%^RED%^y%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This magical construct looks as though it would serve as a weapon of considerable %^RESET%^%^RED%^potency%^BOLD%^%^WHITE%^. "
"Instead of wood or metal, however, it is made purely of %^RESET%^%^RED%^s%^BOLD%^%^RED%^e%^YELLOW%^a%^RESET%^%^RED%^r%^MAGENTA%^i%^BOLD%^%^RED%^n%^RESET%^%^RED%^g "
"e%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^r%^BOLD%^%^RED%^g%^RESET%^%^RED%^y"
"%^BOLD%^%^WHITE%^. Shaped like a claw, it bears three six-inch tines that each taper to a %^YELLOW%^razor-sharp %^BOLD%^%^WHITE%^point. They spring from a "
"flattened brace that rests around and across the hand, secured in place by seemingly nothing more than sheer manifestation of %^RESET%^%^CYAN%^will"
"%^BOLD%^%^WHITE%^.%^RESET%^\n");
}

void special_tier1(object wielder,object victim) {
    int duration;
    object secondary;
    tell_object(wielder,"%^RESET%^%^RED%^F%^BOLD%^%^RED%^l%^YELLOW%^a%^BOLD%^%^WHITE%^m%^BOLD%^%^RED%^e%^RESET%^%^RED%^s %^RESET%^%^MAGENTA%^blaze up as your claw slashes "+victim->QCN+", catching "+victim->QO+" alight!%^RESET%^");
    tell_object(victim,"%^RESET%^%^RED%^F%^BOLD%^%^RED%^l%^YELLOW%^a%^BOLD%^%^WHITE%^m%^BOLD%^%^RED%^e%^RESET%^%^RED%^s %^RESET%^%^MAGENTA%^blaze up as "+wielder->QCN+"'s claw slashes you, and you catch alight!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^RED%^F%^BOLD%^%^RED%^l%^YELLOW%^a%^BOLD%^%^WHITE%^m%^BOLD%^%^RED%^e%^RESET%^%^RED%^s %^RESET%^%^MAGENTA%^blaze up as "+wielder->QCN+"'s claw slashes "+victim->QCN+", catching "+victim->QO+" alight!%^RESET%^",({wielder,victim}));
    duration = (powerlevel/5)+1; // 1 round per 5 lvls of warlock
    secondary = present("eldritch_brimstone_xxx",victim);
    if(!objectp(secondary)) {
      secondary = new("/d/magic/obj/eldritch_effects/eldritch_brimstone");
      secondary->move(victim);
    }
    secondary->activate(duration,(powerlevel/2)); // this activates at half the damage power of a spellcaster.
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,4));
}

void special_tier3(object wielder,object victim) {
    if((int)wielder->query_hp() < (int)wielder->query_max_hp()) {
      tell_object(wielder,"%^RESET%^%^MAGENTA%^A brief but %^BOLD%^%^RED%^i%^RESET%^%^RED%^n%^BOLD%^%^RED%^te%^RESET%^%^RED%^n%^BOLD%^%^RED%^s%^RESET%^%^RED%^e %^RESET%^%^MAGENTA%^heat radiates from the claw, and your wounds cauterise before your eyes!%^RESET%^");
      tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^The air around you ripples with %^BOLD%^%^RED%^i%^RESET%^%^RED%^n%^BOLD%^%^RED%^te%^RESET%^%^RED%^n%^BOLD%^%^RED%^s%^RESET%^%^RED%^e %^RESET%^%^MAGENTA%^heat, and "+wielder->QCN+"'s wounds cauterise before your eyes!%^RESET%^",wielder);
      TO->set_property("magic",1);
      wielder->do_damage("torso",(roll_dice(tier,6)+20)*(-1));
      TO->set_property("magic",-1);
    }
    else special_tier2(wielder,victim); // may as well still do something useful if they're not injured!
}

void special_tier2(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your eldritch claw %^RED%^f%^BOLD%^%^RED%^l%^RESET%^%^RED%^as%^BOLD%^%^YELLOW%^h%^BOLD%^%^RED%^e%^RESET%^%^RED%^s %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s claw %^RED%^f%^BOLD%^%^RED%^l%^RESET%^%^RED%^as%^BOLD%^%^YELLOW%^h%^BOLD%^%^RED%^e%^RESET%^%^RED%^s %^MAGENTA%^brightly as it slices into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^The claw %^RED%^f%^BOLD%^%^RED%^l%^RESET%^%^RED%^as%^BOLD%^%^YELLOW%^h%^BOLD%^%^RED%^e%^RESET%^%^RED%^s %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6)+2);
    TO->remove_property("magic");
}

void special_tier4(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^RED%^S%^BOLD%^%^RED%^e%^YELLOW%^a%^RESET%^%^RED%^r%^MAGENTA%^i%^BOLD%^%^RED%^n%^RESET%^%^RED%^g e%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^r%^BOLD%^%^RED%^g%^RESET%^%^RED%^y%^MAGENTA%^ jolts through the eldritch claw as it rends flesh and bone!%^RESET%^");
    tell_object(victim,"%^RESET%^%^RED%^S%^BOLD%^%^RED%^e%^YELLOW%^a%^RESET%^%^RED%^r%^MAGENTA%^i%^BOLD%^%^RED%^n%^RESET%^%^RED%^g e%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^r%^BOLD%^%^RED%^g%^RESET%^%^RED%^y%^MAGENTA%^ jolts through "+wielder->QCN+"'s claw as it rends flesh and bone!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^RED%^S%^BOLD%^%^RED%^e%^YELLOW%^a%^RESET%^%^RED%^r%^MAGENTA%^i%^BOLD%^%^RED%^n%^RESET%^%^RED%^g e%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^r%^BOLD%^%^RED%^g%^RESET%^%^RED%^y%^MAGENTA%^ jolts through "+wielder->QCN+"'s claw as it rends "+victim->QCN+"'s flesh and bones!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,10)+2);
    TO->remove_property("magic");
}