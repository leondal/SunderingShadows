#include <std.h>
#include <magic.h>
inherit "/d/magic/obj/lockweapons/eldritch_scimitar";

void create() {
   ::create();
   set_id(({"eldritch scimitar","scimitar","energy scimitar","scimitar of energy","scimitar of malignant energy","eldritch_weapon_xxx"}));
}

void special_tier1(object wielder,object victim) {
    int duration;
    object secondary;
    tell_object(wielder,"%^RESET%^%^MAGENTA%^You lash out at "+victim->QCN+", and a horrified %^BLUE%^sh%^MAGENTA%^u%^BLUE%^dd%^MAGENTA%^e%^BLUE%^r %^MAGENTA%^runs through "+victim->QO+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+" lashes out at you with "+wielder->QP+" scimitar, and you can't suppress the sudden %^BLUE%^sh%^MAGENTA%^u%^BLUE%^dd%^MAGENTA%^e%^BLUE%^r %^MAGENTA%^of horror that runs through you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^"+wielder->QCN+" lashes out at "+victim->QCN+", and a horrified %^BLUE%^sh%^MAGENTA%^u%^BLUE%^dd%^MAGENTA%^e%^BLUE%^r %^MAGENTA%^runs through "+victim->QO+"!%^RESET%^",({wielder,victim}));
    duration = 60/ROUND_LENGTH; // shaken, 1min
    secondary = present("eldritch_frightful_xxx",victim);
    if(!objectp(secondary)) {
      secondary = new("/d/magic/obj/eldritch_effects/eldritch_frightful");
      secondary->move(victim);
    }
    secondary->activate(duration);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,4));
}

void special_tier3(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^You channel power through the scimitar and %^BLUE%^un%^MAGENTA%^e%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^rt%^RESET%^h%^MAGENTA%^l%^BLUE%^y %^MAGENTA%^energy arcs into "+victim->QCN+", shocking "+victim->QP+" body into momentary paralysis!%^RESET%^");
    tell_object(victim,"%^BLUE%^Un%^MAGENTA%^e%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^rt%^RESET%^h%^MAGENTA%^l%^BLUE%^y %^MAGENTA%^energy discharges from "+wielder->QCN+"'s scimitar and into you, shocking your body into momentary paralysis!%^RESET%^");
    tell_room(environment(wielder),"%^BLUE%^Un%^MAGENTA%^e%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^rt%^RESET%^h%^MAGENTA%^l%^BLUE%^y %^MAGENTA%^energy discharges from "+wielder->QCN+"'s scimitar into "+victim->QP+", shocking "+victim->QP+" body into momentary paralysis!%^RESET%^",({wielder,victim}));
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6));
    victim->set_paralyzed(random((tier*3))+10,"%^BLUE%^Your limbs fail to respond!%^RESET%^");
}

void special_tier2(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your eldritch scimitar %^BLUE%^f%^MAGENTA%^l%^BLUE%^a%^BOLD%^%^BLACK%^s%^RESET%^h%^MAGENTA%^e%^BLUE%^s %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s scimitar %^BLUE%^f%^MAGENTA%^l%^BLUE%^a%^BOLD%^%^BLACK%^s%^RESET%^h%^MAGENTA%^e%^BLUE%^s %^MAGENTA%^brightly as it slices into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^The scimitar %^BLUE%^f%^MAGENTA%^l%^BLUE%^a%^BOLD%^%^BLACK%^s%^RESET%^h%^MAGENTA%^e%^BLUE%^s %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6)+2);
    TO->remove_property("magic");
}

void special_tier4(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^BLUE%^Ma%^MAGENTA%^l%^BLUE%^ign%^BOLD%^%^BLACK%^an%^RESET%^%^BLUE%^t e%^MAGENTA%^n%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^r%^RESET%^g%^BLUE%^y%^MAGENTA%^ jolts through the eldritch scimitar as it rends flesh and bone!%^RESET%^");
    tell_object(victim,"%^RESET%^%^BLUE%^Ma%^MAGENTA%^l%^BLUE%^ign%^BOLD%^%^BLACK%^an%^RESET%^%^BLUE%^t e%^MAGENTA%^n%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^r%^RESET%^g%^BLUE%^y%^MAGENTA%^ jolts through "+wielder->QCN+"'s scimitar as it rends flesh and bone!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^BLUE%^Ma%^MAGENTA%^l%^BLUE%^ign%^BOLD%^%^BLACK%^an%^RESET%^%^BLUE%^t e%^MAGENTA%^n%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^r%^RESET%^g%^BLUE%^y%^MAGENTA%^ jolts through "+wielder->QCN+"'s scimitar as it rends "+victim->QCN+"'s flesh and bones!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,10)+2);
    TO->remove_property("magic");
}
