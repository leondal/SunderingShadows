//Coded by Bane//
//New desc, lore, added color to message and clarified the syntax 3/27/05 - Cythera
#include <std.h>
#include <daemons.h>
inherit OBJECT;
int flag;
int uses;
int maxuses = 20;
int count;
object who;
int counter;
void create()
{
    ::create();
    set_id(({ "chalice", "cup", "chalice of purity", "white gold chalice", "healingchalice" }));
    set_name("chalice of purity");
    set_short("%^BOLD%^%^WHITE%^Chalice of " +
              "%^GREEN%^P%^WHITE%^u%^CYAN%^r%^GREEN%^i%^WHITE%^t"
              "%^CYAN%^y%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^A white gold chalice%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Crafted from white gold, " +
             "this small chalice features detailed carvings around" +
             " its surface.  The carvings take shape of a graceful " +
             "unicorn standing in the middle of a tranquil %^GREEN%^" +
             "forest scene%^WHITE%^.  The lush forest around the " +
             "unicorn is highly detailed, from the texture of the" +
             " bark to the shape of the leaves.  The unicorn's long" +
             " flowing main has been depicted as floating in the " +
             "air.  With her head bent low, the unicorn is touching" +
             " the surface of a %^CYAN%^still pool%^WHITE%^ of water" +
             " with her %^YELLOW%^h%^WHITE%^o%^YELLOW%^r%^WHITE%^n." +
             "  The stem of the chalice tapers in before coming to " +
             "rest on a round base. Inlaid in the base of this chalice" +
             " are square cut %^GREEN%^emeralds%^WHITE%^, teardrop " +
             "shaped %^CYAN%^aquamarines%^WHITE%^, and triangles of" +
             " iv%^YELLOW%^o%^WHITE%^ry. The ripples of the pool " +
             "seem to spell out something.");
    set_lore("First created by the faiths of Lysara and Nim'navanon," +
             " the Chalice of Purity symbolized the main themes of both" +
             " goddesses.  The unicorn is used to symbolize purity and" +
             " cleansing, while the still pool is an icon of Lysara's" +
             " tranquility.");
    set_property("lore difficulty", 9);
    set_read("%^BOLD%^%^CYAN%^\nTo feel the blessings of purity " +
             "simply %^GREEN%^measure liquid%^CYAN%^.\nAnd %^GREEN%^drink" +
             " liquid%^CYAN%^ from this chalice.");
    set_language("common");
    set_weight(5);
    set_value(15000);
    set_heart_beat(1);
}

int query_value()
{
    return 25000 / (uses + 1);
}

void init()
{
    ::init();
    add_action("drink_me", "drink");
    add_action("measure_me", "measure");
}

int drink_me(string str)
{
    if (!str) {
        return notify_fail("Drink what?\n");
    }
    if ("liquid" != str) {
        return 0;
    }
    if (uses > maxuses) {
        write("%^BOLD%^The chalice's power has disappeared forever.");
        return 1;
    }
    if (flag == 0) {
        tell_object(TP, "%^BOLD%^%^CYAN%^You drink the liquid from the chalice.");
        tell_room(ETO, "%^BOLD%^%^CYAN%^" + TP->QCN + " drinks the liquid from the" +
                  " white gold chalice.", TP);
        call_out("heal_me", 5, TP);
        uses += 1;
        flag = 1;
        return 1;
    }
    write("%^GREEN%^There isn't enough liquid left in the chalice to drink yet.");
    return 1;
}

int measure_me(string str)
{
    if (!str) {
        return notify_fail("Measure what?\n");
    }
    if ("liquid" != str) {
        return 0;
    }
    if (uses > maxuses) {
        write("%^BOLD%^The chalice's power has disappeared forever.");
        return 1;
    }
    if (flag == 0) {
        write("%^BOLD%^%^CYAN%^The stones on the cup start to" +
              " glow as the chalice fills with crystal clear water. It appears that the chalice has been used " + uses + " of " + maxuses + " times.");
        return 1;
    }
    write("%^BOLD%^%^GREEN%^The cup is still replenishing itself. It appears that the chalice has been used " + uses + " of " + maxuses + " times.");
    return 1;
}

int heal_me(object targ)
{
    write("%^BOLD%^%^CYAN%^You feel your wounds heal and the impurities" +
          " from your body disappear.");
    targ->add_hp(targ->query_max_hp() / 2);
    targ->add_poisoning(-100);
    targ->add_intox(-targ->query_intox());
    POISON_D->clear_poisons_by_dc(targ, 50, 0);
    return 1;
}

int isMagic()
{
    int x;
    x = ::isMagic();
    x = x + 1;
    return x;
}

int is_healingchalice()
{
    return 1;
}

int add_counter(int num)
{
    if (!counter || counter < 0) {
        counter = 0;
    }
    counter += num;
}

void deep_chalice_check()
{
    object* inv, * deep_inv, * chalices = ({}), * sacks = ({});
    int i, j, damage;

    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    if (!living(ETO)) {
        return;
    }

    inv = all_inventory(ETO);

    if (!sizeof(inv)) {
        return;
    }

    for (i = 0; i < sizeof(inv); i++) {
        if (!objectp(inv[i])) {
            continue;
        }
        if (!inv[i]->is_container()) {
            continue;
        }
        deep_inv = all_inventory(inv[i]);
        if (!sizeof(deep_inv)) {
            continue;
        }
        for (j = 0; j < sizeof(deep_inv); j++) {
            if (!objectp(deep_inv[j])) {
                continue;
            }
            if (deep_inv[j]->is_healingchalice()) {
                chalices += ({ deep_inv[j] });
                TO->add_counter(1);
                deep_inv[j]->add_counter(1);
                sacks += ({ inv[i] });
            }
        }
    }

    sacks = distinct_array(sacks);

    if (!sizeof(chalices)) {
        TO->add_counter(-1);
        return;
    }

    switch (counter) {
    case 0..19: break;

    case 20:
        if (objectp(ETO) && living(ETO)) {
            tell_object(ETO, "%^RESET%^%^GREEN%^Your " + TO->query_short() + " begins to get warm to the touch.%^RESET%^");
            tell_object(ETO, "You can feel something in your sacks start to vibrate.");
        }
        break;

    case 21..99: break;

    case 100:
        if (objectp(ETO) && living(ETO)) {
            tell_object(ETO, "%^RESET%^%^YELLOW%^Your " + TO->query_short() + " is painfully hot to the touch now!%^RESET%^");
            tell_object(ETO, "%^RESET%^%^BOLD%^The vibration in your sacks increases to a dull hum!");
        }
        break;

    case 101..199: break;

    default:
        if (objectp(ETO) && living(ETO) && objectp(EETO)) {
            tell_object(ETO, "%^RED%^Your " + TO->query_short() + " suddenly explodes in a violent shower of fragments!");
            tell_room(EETO, "%^RED%^" + ETO->QCN + "'s " + TO->query_short() + " suddenly explodes in a violent shower of fragments!", ETO);
            damage = roll_dice(10, 10);
            if (sizeof(sacks)) {
                for (i = 0; i < sizeof(sacks); i++) {
                    if (!objectp(sacks[i])) {
                        continue;
                    }
                    tell_object(ETO, "%^RED%^Your " + sacks[i]->query_short() + " rips apart in a violent "
                                "explosion sending debris everywhere!");
                    tell_room(EETO, "%^RED%^" + ETO->QCN + "'s " + sacks[i]->query_short() + " rips apart in "
                              "a violent explosion sending debris everywhere!", ETO);
                    deep_inv = all_inventory(sacks[i]);
                    if (!sizeof(deep_inv)) {
                        continue;
                    }
                    for (j = 0; j < sizeof(deep_inv); j++) {
                        if (!objectp(deep_inv[j])) {
                            continue;
                        }
                        if (deep_inv[j]->is_healingchalice()) {
                            damage += roll_dice(10, 10);
                            deep_inv[j]->remove();
                            continue;
                        }
                        deep_inv[j]->repairMe(-1 * (roll_dice(10, 10)));
                        if (objectp(deep_inv[j])) {
                            deep_inv[j]->move(environment(ETO));
                        }
                    }
                    sacks[i]->remove();
                }
            }
        }
        ETO->set_property("magic", 1);
        ETO->do_damage("torso", damage);
        ETO->set_property("magic", -1);
        TO->remove();
        return;
    }

    return;
}

void heart_beat()
{
    object ob;

    if (!objectp(ETO)) {
        return;
    }
    if ((ob = present("healingchalice", ETO)) && living(ETO) && ob != TO) {
        tell_object(ETO, "The white gold chalices start to interact and shake and quiver.");
        tell_room(environment(ETO), "The chalices held by " + ETO->query_cap_name() + " quiver and shake.", ETO);
        tell_room(environment(ETO), "%^BOLD%^%^CYAN%^They explode in a blilliant burst of light and fire.%^RESET%^");
        ETO->do_damage("torso", roll_dice(3, 50));
        ETO->add_attacker(TO);
        ETO->continue_attack();
        ob->remove();
        TO->remove();
    }else {
        deep_chalice_check(); // added so people don't carry an extra around in a sack to use as a weapon -Ares
    }

    if (uses <= maxuses) {
        if (count > 2) {
            flag = 0;
            count = 0;
        }
    }else {
        set_heart_beat(0);
    }
    count++;
}
