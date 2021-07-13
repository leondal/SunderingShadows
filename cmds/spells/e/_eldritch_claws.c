#include <priest.h>
#include <magic.h>
#include <spell.h>
inherit SPELL;

#define BASEDIR "/d/magic/obj/lockweapons/"

object myweapon, myweapon2;
int clawz;
string blasttype;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("eldritch claws");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS eldritch claws [on one hand]");
    set_description("%^RESET%^A variant on the core spell-like ability of the warlock, this invocation allows the caster to shape their eldritch blast into as many claws as they have free hands, all of which can be used as melee weapons. If the warlock has no free hands, the invocation will fail entirely; similarly, if a different shaped eldritch ability is invoked, the claw/s will disappear. Releasing grip upon a claw will cause it to disappear. As with eldritch blast, the claw/s can be imbued with various essences; however as the invocation is essentially a single shaping of the warlock's eldritch ability, so only one essence may be harnessed at a time even between two
claws.

See also: blasttype
");
    set_verbal_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell() {
    while(present("eldritch_weapon_xxx",caster))
    {
        if(present("eldritch_weapon_xxx", caster)->query_wielded()) caster->force_me("unwield eldritch_weapon_xxx");
        if(objectp(present("eldritch_weapon_xxx", caster)))
        {
            tell_room(place,"%^RESET%^%^CYAN%^The gleaming claw shimmers and disappears.%^RESET%^");
            present("eldritch_weapon_xxx", caster)->remove();
            continue;
        }
        continue;
    }
    if(sizeof(caster->query_wielded()) > 1) {
        tell_object(caster,"You don't have any free hands!");
        return 0;
    }
    if(sizeof(caster->query_wielded()) && (caster->is_wearing_type("shield") || caster->is_wearing_type("thiefshield"))) {
        tell_object(caster,"You don't have any free hands!");
        return 0;
    }
    return 1;
}

string query_cast_string() {
    blasttype = (string)caster->query("warlock_blast_type");
    if(sizeof(caster->query_wielded()) || (arg && arg == "one hand")) {
        tell_object(caster,"%^MAGENTA%^You extend your free hand and curl your fingers inwards.%^RESET%^");
        tell_room(place,"%^MAGENTA%^"+caster->QCN+" extends "+caster->QP+" free hand and curls "+caster->QP+" fingers inwards.%^RESET%^",caster);
        clawz = 1;
    }
    else {
        tell_object(caster,"%^MAGENTA%^You extend both hands and curl your fingers inwards.%^RESET%^");
        tell_room(place,"%^MAGENTA%^"+caster->QCN+" extends both hands and curls "+caster->QP+" fingers inwards.%^RESET%^",caster);
        clawz = 2;
    }
    return "display";
}

void spell_effect(int prof){
    string descriptor, filename;
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    if(sizeof(caster->query_wielded()) > 1) {
        tell_object(caster,"You don't have any free hands!");
        dest_effect();
        return;
    }
    if(sizeof(caster->query_wielded()) && (caster->is_wearing_type("shield") || caster->is_wearing_type("thiefshield"))) {
        tell_object(caster,"You don't have any free hands!");
        dest_effect();
        return;
    }
    if(clawz == 2 && sizeof(caster->query_wielded())) {
        tell_object(caster,"The invocation fails as you attempt to call a weapon into an otherwise occupied hand!");
        dest_effect();
        return;
    }

    filename = BASEDIR+"eldritch_claw"; // til we override with essence'd subtypes below!
    switch(blasttype) {
    case "frightful":
        descriptor = "%^BLUE%^ma%^MAGENTA%^l%^BLUE%^ign%^BOLD%^%^BLACK%^an%^RESET%^%^BLUE%^t e%^MAGENTA%^n%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^r%^RESET%^g%^BLUE%^y%^MAGENTA%^";
        filename = BASEDIR+"eldritch_claw_frightful";
        break;
    case "glacial":
        descriptor = "%^CYAN%^c%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^a%^RESET%^c%^BOLD%^%^WHITE%^k%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n%^RESET%^%^CYAN%^g e%^BOLD%^%^BLUE%^n%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^y%^MAGENTA%^";
        filename = BASEDIR+"eldritch_claw_glacial";
        break;
    case "brimstone":
        descriptor = "%^RED%^s%^BOLD%^%^RED%^e%^YELLOW%^a%^RESET%^%^RED%^r%^MAGENTA%^i%^BOLD%^%^RED%^n%^RESET%^%^RED%^g e%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^r%^BOLD%^%^RED%^g%^RESET%^%^RED%^y%^MAGENTA%^";
        filename = BASEDIR+"eldritch_claw_brimstone";
        break;
    case "lifedrinker":
        descriptor = "%^GREEN%^s%^BOLD%^%^GREEN%^ee%^RESET%^%^GREEN%^th%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng e%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^er%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^y%^MAGENTA%^";
        filename = BASEDIR+"eldritch_claw_lifedrinker";
        break;
    case "vitriolic":
        descriptor = "%^GREEN%^n%^BOLD%^%^WHITE%^o%^BOLD%^%^GREEN%^x%^RESET%^%^GREEN%^i%^CYAN%^o%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^s e%^YELLOW%^n%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^r%^CYAN%^g%^GREEN%^y%^RESET%^%^MAGENTA%^";
        filename = BASEDIR+"eldritch_claw_vitriolic";
        break;
    case "beshadowed":
        descriptor = "%^BOLD%^%^BLACK%^te%^RESET%^n%^BOLD%^%^BLACK%^ebr%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^us e%^RESET%^ne%^BOLD%^%^BLACK%^rgy%^RESET%^%^MAGENTA%^";
        filename = BASEDIR+"eldritch_claw_beshadowed";
        break;
    case "binding":
        descriptor = "%^BOLD%^%^BLUE%^s%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n%^BOLD%^%^GREEN%^g %^BOLD%^%^WHITE%^e%^BOLD%^%^BLUE%^n%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^g%^BOLD%^%^CYAN%^y%^RESET%^%^MAGENTA%^";
        filename = BASEDIR+"eldritch_claw_binding";
        break;
    case "utterdark":
        descriptor = "m%^BOLD%^%^BLACK%^al%^RESET%^%^MAGENTA%^ef%^RESET%^i%^MAGENTA%^c e%^BOLD%^%^BLACK%^n%^RESET%^e%^MAGENTA%^rgy";
        filename = BASEDIR+"eldritch_claw_utterdark";
        break;
    default:
        blasttype = "default";
        descriptor = "e%^BOLD%^%^MAGENTA%^n%^RESET%^%^MAGENTA%^e%^BOLD%^%^WHITE%^r%^BOLD%^%^MAGENTA%^g%^RESET%^%^MAGENTA%^y";
        break;
    }

    if(clawz == 1) {
        tell_object(caster,"%^MAGENTA%^Across the back of your hand appears a claw, formed of "+descriptor+"!%^RESET%^");
        tell_room(place,"%^MAGENTA%^Across the back of "+caster->QCN+"'s hand appears a claw, formed of "+descriptor+"!%^RESET%^",caster);
    }
    else {
        tell_object(caster,"%^MAGENTA%^Across the back of your hands appear a pair of claws, formed of "+descriptor+"!%^RESET%^");
        tell_room(place,"%^MAGENTA%^Across the back of "+caster->QCN+"'s hands appear a pair of claws, formed of "+descriptor+"!%^RESET%^",caster);
    }
    myweapon = new(filename);
    myweapon->weapon_setup(caster,clevel);
    myweapon->move(caster);
    caster->remove_paralyzed();
    caster->force_me("wield eldritch claw");
    if(clawz == 2) {
        myweapon2 = new(filename);
        myweapon2->weapon_setup(caster,clevel);
        myweapon2->move(caster);
        caster->force_me("wield eldritch claw");
    }
    spell_successful();
    spell_duration = (10 + clevel + roll_dice(1, 20)) * ROUND_LENGTH * 10;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    int trackflag;
    trackflag = 0;
    if (objectp(caster)) {
        if(objectp(myweapon) || objectp(myweapon2)) { caster->force_me("unwield eldritch_weapon_xxx"); trackflag++; }
        if(objectp(myweapon) || objectp(myweapon2)) { caster->force_me("unwield eldritch_weapon_xxx"); trackflag++; }
        if(trackflag == 1) {
            tell_object(caster,"%^MAGENTA%^The claw disappears from over your hand.%^RESET%^");
            tell_room(environment(caster),"%^MAGENTA%^The claw disappears from over "+caster->QCN+"'s hand.%^RESET%^",caster);
        }
        if(trackflag == 2) {
            tell_object(caster,"%^MAGENTA%^The claws disappear from over your hands.%^RESET%^");
            tell_room(environment(caster),"%^MAGENTA%^The claws disappear from over "+caster->QCN+"'s hands.%^RESET%^",caster);
        }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
