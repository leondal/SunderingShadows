#include <std.h>
#include <magic.h>
inherit "/d/magic/obj/lockweapons/eldritch_scimitar";

void create() {
   ::create();
   set_id(({"eldritch scimitar","scimitar","energy scimitar","scimitar of energy","scimitar of crackling energy","eldritch_weapon_xxx"}));
}

void special_tier1(object wielder,object victim) {
    int duration;
    object secondary;
    tell_object(wielder,"%^RESET%^%^MAGENTA%^You unleash a pulse of ch%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^l%^RESET%^%^MAGENTA%^li%^BOLD%^%^CYAN%^n%^RESET%^%^MAGENTA%^g power through the scimitar as it makes contact with "+victim->QCN+", and "+victim->QP+" movements seem slowed!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^A pulse of ch%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^l%^RESET%^%^MAGENTA%^li%^BOLD%^%^CYAN%^n%^RESET%^%^MAGENTA%^g power surges through you as "+wielder->QCN+"'s scimitar makes contact with your body! Your movements grow sluggish!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^You can feel a sudden ch%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^l%^RESET%^%^MAGENTA%^l in the air as "+wielder->QCN+"'s scimitar makes contact with "+victim->QP+" body!%^RESET%^",({wielder,victim}));
    duration = 600/ROUND_LENGTH; // -4 dex, 10min
    secondary = present("eldritch_glacial_xxx",victim);
    if(!objectp(secondary)) {
      secondary = new("/d/magic/obj/eldritch_effects/eldritch_glacial");
      secondary->move(victim);
    }
    secondary->activate(duration);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,4));
}

void special_tier3(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Drawn blood %^BOLD%^%^WHITE%^f%^BOLD%^%^CYAN%^re%^BOLD%^%^WHITE%^ez%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^s %^RESET%^%^MAGENTA%^before it has a chance to fall, as the frigid scimitar cuts "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^Your blood seems to %^BOLD%^%^WHITE%^f%^BOLD%^%^CYAN%^re%^BOLD%^%^WHITE%^e%^BOLD%^%^CYAN%^z%^BOLD%^%^WHITE%^e %^RESET%^%^MAGENTA%^in your veins as "+wielder->QCN+"'s frigid scimitar cuts into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^Drawn blood %^BOLD%^%^WHITE%^f%^BOLD%^%^CYAN%^re%^BOLD%^%^WHITE%^ez%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^s %^RESET%^%^MAGENTA%^before it has a chance to fall, as "+wielder->QCN+"'s frigid scimitar cuts into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6));
    victim->set_paralyzed(random((tier*3))+10,"%^BOLD%^%^CYAN%^A bone-deep chill seems to hold you in place!%^RESET%^");
}

void special_tier2(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your eldritch scimitar %^CYAN%^f%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^as%^BOLD%^%^WHITE%^h%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s scimitar %^CYAN%^f%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^as%^BOLD%^%^WHITE%^h%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^MAGENTA%^brightly as it slices into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^The scimitar %^CYAN%^f%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^as%^BOLD%^%^WHITE%^h%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6)+2);
    TO->remove_property("magic");
}

void special_tier4(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^CYAN%^C%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^a%^RESET%^c%^BOLD%^%^WHITE%^k%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^g e%^BOLD%^%^BLUE%^n%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^y%^MAGENTA%^ jolts through the eldritch scimitar as it rends flesh and bone!%^RESET%^");
    tell_object(victim,"%^RESET%^%^CYAN%^C%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^a%^RESET%^c%^BOLD%^%^WHITE%^k%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^g e%^BOLD%^%^BLUE%^n%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^y%^MAGENTA%^ jolts through "+wielder->QCN+"'s scimitar as it rends flesh and bone!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^CYAN%^C%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^a%^RESET%^c%^BOLD%^%^WHITE%^k%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^g e%^BOLD%^%^BLUE%^n%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^y%^MAGENTA%^ jolts through "+wielder->QCN+"'s scimitar as it rends "+victim->QCN+"'s flesh and bones!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,10)+2);
    TO->remove_property("magic");
}
