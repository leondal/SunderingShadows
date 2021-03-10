#include <std.h>

inherit POTION;
//code stolen from Lujke
void create()
{
    ::create();
    set_short("%^BOLD%^%^ORANGE%^Potion of Youth%^RESET%^");
    set_id(({ "potion", "vial", "yellow potion", "glowing yellow potion", "potion of youth" }));
    set_obvious_short("A vial containing a %^BOLD%^%^ORANGE%^glowing yellow %^RESET%^potion");
    set_long("The %^BOLD%^%^YELLOW%^glowing golden yellow %^RESET%^liquid in this vial steams the side of it's container with a glowing white smoke.  It is of a thick consistency, like cold honey, even though the vial itself is warm to the touch.  There can be little doubt that whatever substance is inside of this vial is dangerous at best.");
    set_lore("This is the famed potion of youth.");
    set_property("lore difficulty", 35);
    set("color", "%^BOLD%^%^ORANGE%^glowing yellow%^RESET%^");
}

int calculate_target_age(object ob)
{
    string age;
    int i;
    if (!objectp(ob)) {
        return -1;
    }
    for (i = 10; i < 200; i++) {
        age = "/cmds/mortal/_stats"->get_age(ob, i);
        if (age == "average") {
            return i - 1;
        }
    }
}

int calculate_modifier(object ob)
{
    int age_now, current_modifier, unmodified_age, target_age;
    if (!objectp(ob)) {
        return 0;
    }
    current_modifier = ob->query("age_modifier");
    age_now = ob->query_real_age();
    unmodified_age = age_now - current_modifier;
    target_age = calculate_target_age(ob);
    return target_age - unmodified_age;
}

int set_age_modifier(object ob)
{
    string age;
    int i, j, orig;
    if (!objectp(ob)) {
        return -1;
    }
    orig = ob->query("age_modifier");
    for (i = 1; i < 2000; i++) {
        ob->set("age_modifier", (i * -1));
        if (ob->query_real_age_cat() == "child") {
            while (ob->query_real_age_cat() == "child" && j < 500) {
                j++;
                ob->set("age_modifier", (i * -1) + j);
            }

            break;
        }
    }
}

void rejuvenate(object ob)
{
    int mod;
    if (!objectp(ob) || !objectp(environment(ob))) {
        return;
    }
    set_age_modifier(ob);
//  mod = calculate_modifier(ob);
//  tell_room(TO, "Rejuvenating " + ob->QCN);
//  ob->set("age_modifier", mod);
}

void invigorate(object ob)
{
    int mod;
    if (!objectp(ob) || !objectp(environment(ob))) {
        return;
    }

    // Small adition, hope Lujke won't mind... Illy.
    if (ob->is_vampire()) {
        tell_object(ob, "%^BOLD%^%^GREEN%^You sense your unlife ends here as you drink... You are living again.");
        ob->delete("vampire");
        ob->delete("undead");
    }
    tell_object(ob, "%^BOLD%^%^YELLOW%^The %^BOLD%^%^BLUE%^cool potion %^BOLD%^%^YELLOW%^"
                + "washes down your throat, bringing an %^BOLD%^%^MAGENTA%^overwhelming"
                + " %^BOLD%^%^YELLOW%^sense of %^BOLD%^%^GREEN%^renewal%^BOLD%^"
                + "%^YELLOW%^ and %^BOLD%^%^CYAN%^invigoration%^BOLD%^%^YELLOW%^. The"
                + " %^BOLD%^%^MAGENTA%^euphoria %^BOLD%^%^YELLOW%^builds to an almost"
                + " unbearable level, and you collapse into %^RESET%^%^BLUE%^unconsciousness");
    tell_room(environment(ob), (string)ob->QCN + " trembles for a moment, then collapses to "
              + (string)ob->QP + " knees before toppling over sideways, unconscious. As "
              + (string)ob->QS + " sleeps, you can see " + (string)ob->QP + " features"
              + " changing and shifting as " + (string)ob->QS
              + " miraculously becomes young again.", ob);
    ob->set_hp(-10);
    rejuvenate(ob);
}

int do_effect()
{
    call_out("invigorate", 2, drinker);
    return 1;
}

int do_wear_off()
{
    tell_object(drinker, "You feel the effects of the potion set into your system.\n");
    return 1;
}
