#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;


void create()
{
    ::create();
    set_spell_name("typhoon");
    set_spell_level(([ "druid" : 9, "mage" :9, "cleric" : 9 ]));
    set_domains("air");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS typhoon");
    set_damage_desc("bludgeoning, tripped");
    set_description("This spell creates a powerfull typhoon in the area. Flying and big creatures might find it easier to move around in it, but all may be send flying in the winds.");
    set_verbal_comp();
    set_somatic_comp();
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^BLACK%^(%^RESET%^%^CYAN%^in a ty%^BOLD%^p%^WHITE%^h%^CYAN%^o%^RESET%^%^CYAN%^on%^BOLD%^%^BLACK%^)%^RESET%^");
}

void spell_effect(int prof)
{
    tell_object(caster, "%^CYAN%^You raise your hand to the a%^BOLD%^i%^RESET%^%^CYAN%^r and clench your fist. A %^BOLD%^%^BLACK%^h%^RESET%^%^CYAN%^e%^BOLD%^l%^RESET%^%^CYAN%^ix of %^BOLD%^%^BLACK%^w%^RESET%^%^CYAN%^in%^BOLD%^d %^RESET%^%^CYAN%^and %^BOLD%^w%^RESET%^%^CYAN%^a%^BOLD%^t%^RESET%^%^CYAN%^er forms around it, quckly grows to cover the area.%^WHITE%^");
    tell_room(place, "%^CYAN%^" +caster->QCN+" raises " +caster->QP+" hand to the a%^BOLD%^i%^RESET%^%^CYAN%^r and clenches " +caster->QP+" fist. A %^BOLD%^%^BLACK%^h%^RESET%^%^CYAN%^e%^BOLD%^l%^RESET%^%^CYAN%^ix of %^BOLD%^%^BLACK%^w%^RESET%^%^CYAN%^in%^BOLD%^d %^RESET%^%^CYAN%^and %^BOLD%^w%^RESET%^%^CYAN%^a%^BOLD%^t%^RESET%^%^CYAN%^er forms around it, quckly grows to cover the area.%^WHITE%^", caster);
    counter = clevel * 3;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}

void execute_attack()
{
    object *foes=({}),targ;
    int i;
    string limb;
    int dam, slipped;

    if (!flag) {
        flag = 1;
        ::execute_attack();
        return;
    }

    if (!objectp(caster) || !objectp(place) || !present(caster, place) || counter < 0) {
        dest_effect();
        return;
    }

    message("info", "%^RESET%^%^CYAN%^Howling tornado and the pelting of heavy streams of water threaten to drown out all other sounds!", nearbyRoom(place,2));

    foes = target_selector();
    foes -= ({ caster });

    define_base_damage(0); // lazy re-roll
    for (i = 0; i < sizeof(foes); i++) {
        if (!objectp(targ = foes[i])) {
            continue;
        }

        limb = targ->return_target_limb();

        dam = sdamage;
        slipped = 0;

        if (targ->query_property("flying")) {
            if (targ->query_stats("strength") + roll_dice(1, 25) > roll_dice(1, clevel)) {
                dam /= 2;
                slipped = 1;
            }
        }    else if (targ->query_size() > 2) {
            if (targ->query_stats("strength") + roll_dice(1, 20) > roll_dice(1, clevel)) {
                dam /= 2;
                slipped = 1;
            }
        } else {
            if (targ->query_stats("strength") + roll_dice(1, 15) > roll_dice(1, clevel)) {
                dam /= 2;
                slipped = 1;
            }
        }

        if (slipped) {
            tell_object(targ, "%^BOLD%^%^CYAN%^Unable to hold your balance, you are send flying into the typhoon!%^RESET%^");
            tell_room(place, "%^CYAN%^%^BOLD%^Unable to hold balance, " + targ->QCN + " is send flying into the typhoon!", ({ targ }));
            targ->set_tripped(roll_dice(1, 2), "%^BOLD%^You are send flying by the typhoon!%^RESET%^", 4);
        }

        tell_object(targ,"%^BOLD%^%^CYAN%^You are crushed by the strong wings of the typhoon!");
        damage_targ(targ, targ->return_target_limb(), dam, "bludgeoning");
    }

    counter--;
    place->addObjectToCombatCycle(TO,1);
}

void dest_effect()
{
    if (objectp(place)) {
        tell_object(place, "%^RESET%^%^B_CYAN%^The typhoon ends.");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
