#include <std.h>
#include <magic.h>
inherit "/d/magic/obj/lockweapons/eldritch_claw";

void create() {
   ::create();
   set_id(({"eldritch claw","claw","energy claw","claw of energy","claw of noxious energy","eldritch_weapon_xxx"}));
   set_short("%^RESET%^%^CYAN%^cl%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^w of %^GREEN%^n%^BOLD%^%^WHITE%^o%^BOLD%^%^GREEN%^x%^RESET%^%^GREEN%^i%^CYAN%^o%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^s e%^YELLOW%^n%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^r%^CYAN%^g%^GREEN%^y%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This magical construct looks as though it would serve as a weapon of considerable %^RESET%^%^RED%^potency%^BOLD%^%^WHITE%^. "
"Instead of wood or metal, however, it is made purely of %^RESET%^%^GREEN%^n%^BOLD%^%^WHITE%^o%^BOLD%^%^GREEN%^x%^RESET%^%^GREEN%^i%^CYAN%^o%^BOLD%^%^GREEN%^u"
"%^RESET%^%^GREEN%^s e%^YELLOW%^n%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^r%^CYAN%^g%^GREEN%^y"
"%^BOLD%^%^WHITE%^. Shaped like a claw, it bears three six-inch tines that each taper to a %^YELLOW%^razor-sharp %^BOLD%^%^WHITE%^point. They spring from a "
"flattened brace that rests around and across the hand, secured in place by seemingly nothing more than sheer manifestation of %^RESET%^%^CYAN%^will"
"%^BOLD%^%^WHITE%^.%^RESET%^\n");
}

void special_tier1(object wielder,object victim) {
    int duration;
    object secondary;
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your claw seems to melt away as it makes contact with "+victim->QCN+", leaving a patch of c%^GREEN%^au%^MAGENTA%^st%^CYAN%^i%^MAGENTA%^c liquid upon "+victim->QP+" skin that continues to burn! An instant later the claw reforms, gleaming across the back of your hand!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s claw seems to melt away as it makes contact with you, leaving a patch of c%^GREEN%^au%^MAGENTA%^st%^CYAN%^i%^MAGENTA%^c liquid upon your skin that continues to burn! An instant later the claw reforms, gleaming across the back of "+wielder->QCN+"'s hand!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s claw seems to melt away as it makes contact with "+victim->QCN+", leaving a patch of c%^GREEN%^au%^MAGENTA%^st%^CYAN%^i%^MAGENTA%^c liquid upon "+victim->QP+" skin that continues to burn! An instant later the claw reforms, gleaming across the back of "+wielder->QCN+"'s hand!%^RESET%^",({wielder,victim}));
    duration = (powerlevel/5)+1; // 1 round per 5 lvls of warlock
    secondary = present("eldritch_vitriolic_xxx",victim);
    if(!objectp(secondary)) {
      secondary = new("/d/magic/obj/eldritch_effects/eldritch_vitriolic");
      secondary->move(victim);
    }
    secondary->activate(duration,(powerlevel/2)); // this activates at half the damage power of a spellcaster.
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,4));
}

void special_tier3(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^An %^GREEN%^a%^BOLD%^%^GREEN%^cr%^RESET%^%^GREEN%^i%^CYAN%^d %^GREEN%^h%^YELLOW%^i%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^s %^MAGENTA%^goes up from "+victim->QCN+"'s skin as your claw draws blood!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^An %^GREEN%^a%^BOLD%^%^GREEN%^cr%^RESET%^%^GREEN%^i%^CYAN%^d %^GREEN%^h%^YELLOW%^i%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^s %^MAGENTA%^goes up from your skin as "+wielder->QCN+"'s claw draws blood!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^An %^GREEN%^a%^BOLD%^%^GREEN%^cr%^RESET%^%^GREEN%^i%^CYAN%^d %^GREEN%^h%^YELLOW%^i%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^s %^MAGENTA%^goes up from "+victim->QCN+"'s skin as "+wielder->QCN+"'s claw draws blood!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,8)+2);
    TO->remove_property("magic");
}

void special_tier2(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your eldritch claw %^GREEN%^f%^BOLD%^%^GREEN%^l%^RESET%^a%^GREEN%^s%^YELLOW%^h%^RESET%^%^CYAN%^e%^GREEN%^s %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s claw %^GREEN%^f%^BOLD%^%^GREEN%^l%^RESET%^a%^GREEN%^s%^YELLOW%^h%^RESET%^%^CYAN%^e%^GREEN%^s %^MAGENTA%^brightly as it slices into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^The claw %^GREEN%^f%^BOLD%^%^GREEN%^l%^RESET%^a%^GREEN%^s%^YELLOW%^h%^RESET%^%^CYAN%^e%^GREEN%^s %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6)+2);
    TO->remove_property("magic");
}

void special_tier4(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^GREEN%^N%^BOLD%^%^WHITE%^o%^BOLD%^%^GREEN%^x%^RESET%^%^GREEN%^i%^CYAN%^o%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^s e%^YELLOW%^n%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^r%^CYAN%^g%^GREEN%^y%^RESET%^%^MAGENTA%^ jolts through the eldritch claw as it rends flesh and bone!%^RESET%^");
    tell_object(victim,"%^RESET%^%^GREEN%^N%^BOLD%^%^WHITE%^o%^BOLD%^%^GREEN%^x%^RESET%^%^GREEN%^i%^CYAN%^o%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^s e%^YELLOW%^n%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^r%^CYAN%^g%^GREEN%^y%^RESET%^%^MAGENTA%^ jolts through "+wielder->QCN+"'s claw as it rends flesh and bone!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^GREEN%^N%^BOLD%^%^WHITE%^o%^BOLD%^%^GREEN%^x%^RESET%^%^GREEN%^i%^CYAN%^o%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^s e%^YELLOW%^n%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^r%^CYAN%^g%^GREEN%^y%^RESET%^%^MAGENTA%^ jolts through "+wielder->QCN+"'s claw as it rends "+victim->QCN+"'s flesh and bones!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,10)+2);
    TO->remove_property("magic");
}