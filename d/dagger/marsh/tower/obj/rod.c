//'consume' command added  by Lujke March 2017, because 'feed' was conflicting with the command from vials.
#include <std.h>
inherit "/d/common/obj/weapon/club";

nosave int dynbonus;
object owner;
int uses;
int BLAST;
void init()
{
    ::init();
    if (interactive(TP) && !owner) {
        owner = TPQN;
    }
    add_action("charge_fun", "charge");
    add_action("blast_fun", "blast");
    add_action("expend_fun", "expend");
    add_action("feed_fun", "feed");
    add_action("feed_fun", "consume");
    add_action("absorb_fun", "absorb");
    add_action("entangle_fun", "entangle");
    add_action("escape_fun", "escape");
}

create()
{
    ::create();
    set_name("rod");
    set_id(({ "rod", "rod of the magus" }));
    set_obvious_short("%^BOLD%^%^BLACK%^A long black rod%^RESET%^");
    set_short("%^RESET%^%^RED%^Rod of the Magus%^RESET%^");
    set_long("%^ORANGE%^This long %^BOLD%^%^BLACK%^black rod %^RESET%^%^ORANGE%^is warm to the touch and made of an ancient and unknown %^RESET%^metal%^ORANGE%^. It is covered with various %^CYAN%^arcane runes %^ORANGE%^and %^MAGENTA%^symbols%^ORANGE%^. There are two %^BOLD%^%^BLACK%^black opal g%^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^ms %^RESET%^%^ORANGE%^set into both ends of the %^BOLD%^%^BLACK%^rod%^RESET%^%^ORANGE%^. Every so often, in a bizarre random pattern, a %^CYAN%^faint %^BOLD%^%^BLUE%^bl%^RESET%^%^CYAN%^u%^BOLD%^%^BLUE%^e %^RESET%^%^CYAN%^tr%^BOLD%^%^BLUE%^a%^RESET%^%^CYAN%^ce %^ORANGE%^of %^CYAN%^electrical en%^BOLD%^%^BLUE%^er%^RESET%^%^CYAN%^gy %^ORANGE%^exits from the one %^BOLD%^%^BLACK%^opal %^RESET%^%^ORANGE%^and streaks down the rod's surface and enters the second %^BOLD%^%^BLACK%^opal%^RESET%^%^ORANGE%^. It's purpose is a complete mystery.%^RESET%^");
    set_value(2000);
    set_property("enchantment", 5);
    uses = 100;
    BLAST = 1;
    set_wield((: TO, "extra_wield" :));
    set_unwield((: TO, "extra_unwield" :));
    set_hit((: TO, "extra_hit" :));
    set_property("able to cast", 1);
}
int extra_wield()
{
// objectp check added by Lujke 17 October 2005
    if (!objectp(ETO)) {
        return 0;
    }
// multiple uses of TP replaced by ETO, Lujke 17 October 2005
    if ((string)ETO->query_name() != owner && (string)ETO->query_name() != "nicodemus") {
        write("The rod fails to bond with you!");
        TO->remove();
        return 0;
    }
    if ((int)ETO->query_prestige_level("mage") < 25 &&
        (int)ETO->query_prestige_level("sorcerer") < 25) {
        write("You are not able to utilize this item!\nA surge of energy fills your "
              "head!");
        ETO->do_damage("head", 50);
        ETO->add_attacker(TO);
        ETO->continue_attack();
        ETO->remove_attacker(TO);
        return 0;
    }
    write("%^RED%^"
          "The rod glows with a bright %^BOLD%^red%^RESET%^%^RED%^ aura!"
          "%^RESET%^"
          );
    say("%^RED%^"
        "The rod in "
        + TPQCN +
        "'s hand glows with a bright %^BOLD%^red%^RESET%^%^RED%^ aura!"
        "%^RESET%^"
        , ETO);
    dynbonus = max(({ ETO->query_prestige_level("mage"),
                      ETO->query_prestige_level("sorcerer") })) / 32 + 1;
    ETO->set_property("spell penetration", 1);
    ETO->set_property("bonus_spell_slots", 1);
    ETO->set_property("empowered", dynbonus);
    return 1;
}

void set_owner(object o)
{
    owner = o;
}

int extra_unwield()
{
// objectp check added by Lujke 17 October 2005
    if (!objectp(ETO)) {
        return 0;
    }

    tell_object(ETO, "%^RED%^"
                "The rod's %^BLUE%^aura%^RED%^ slowly dims."
                );
    ETO->set_property("spell penetration", -1);
    ETO->set_property("bonus_spell_slots", -1);
    ETO->set_property("empowered", -dynbonus);
    return 1;
}

int charge_fun()
{
// objectp check added by Lujke 17 October 2005
    if (!objectp(ETO)) {
        return 0;
    }

    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->set_paralyzed_message("info", ETO);
        return 1;
    }
    if (BLAST == 1) {
        write("%^RED%^You set the rod to charge.%^RESET%^");
        say("%^RED%^The rod in " + TPQCN + "'s hand flashes.%^RESET%^");
        BLAST = 0;
        return 1;
    } else {
        write("%^RED%^The rod is already set to charge!%^RESET%^");
        return 1;
    }
}

int blast_fun()
{
// objectp check added by Lujke 17 October 2005
    if (!objectp(ETO)) {
        return 0;
    }
    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->set_paralyzed_message("info", ETO);
        return 1;
    }
    if (BLAST == 0) {
        write("%^RED%^You set the rod to blast.%^RESET%^");
        say("%^RED%^The rod in " + TPQCN + "'s hand flashes.%^RESET%^");
        BLAST = 1;
        return 1;
    } else {
        write("%^RED%^The rod is already set to blast!%^RESET%^");
        return 1;
    }
}

int extra_hit(object ob)
{
    object vic;
    int dam, i, x;
    string BALL;
// objectp check added by Lujke 17 October 2005
    if (!objectp(ETO)) {
        return 0;
    }
    vic = ETO->query_current_attacker();
    if (random(10) > 5 && (int)vic->query_level() > 6) {
        message("my_action", "%^ORANGE%^"
                "You smite "
                + vic->query_cap_name() +
                " with the rod!%^RESET%^"
                , ETO);
        message("other_action", "%^ORANGE%^"
                + ETO->query_cap_name() +
                " smites "
                + vic->query_cap_name() +
                " with the rod!"
                "%^RESET%^"
                , environment(vic), (({ ETO, vic })));
        message("my_action", "%^ORANGE%^"
                + ETO->query_cap_name() +
                " smites "
                "you with the rod in "
                + ETO->query_possessive() +
                " hand!%^RESET%^"
                , vic);
        dam = random(3) + 1;
        return dam;
    } else {
        if (BLAST == 0) {
            message("my_action", "%^CYAN%^"
                    "The rod glows as you strike "
                    + vic->query_cap_name() +
                    "!"
                    "%^RESET%^"
                    , ETO);
            message("other_action", "%^CYAN%^"
                    "The rod wielded by "
                    + ETO->query_cap_name() +
                    " glows as it strikes "
                    + vic->query_cap_name() +
                    "!"
                    "%^RESET%^"
                    , environment(vic), (({ ETO, vic })));
            message("my_action", "%^CYAN%^"
                    "The rod wielded by "
                    + ETO->query_cap_name() +
                    " glows as it strikes "
                    "you!"
                    "%^RESET%^"
                    , vic);
            uses = uses + random(1) + 1;
            if (uses > 100) {
                uses = 100;
            }
            return 1;
        } else {
            i = random(5) + 1;
            if (uses < 1) {
                i = 1;
            } else {
                uses = uses - i;
            }
            if (i == 1) {
                BALL = "ball";
            } else {
                BALL = "balls";
            }
            message("my_action", "%^YELLOW%^"
                    "The rod releases " + i + " " + BALL + " of %^RED%^fiery energy%^YELLOW%^ as it strikes "
                    + vic->query_cap_name() +
                    "!"
                    "\n%^RESET%^%^RED%^"
                    + vic->query_cap_name() +
                    " is burned badly by the fiery " + BALL + "!"
                    "%^RESET%^"
                    , ETO);
            message("other_action", "%^YELLOW%^"
                    "The rod wielded by "
                    + ETO->query_cap_name() +
                    " releases " + i + " " + BALL + " of %^RED%^fiery energy%^YELLOW%^ as it strikes "
                    + vic->query_cap_name() +
                    "!"
                    "\n%^RESET%^%^RED%^"
                    + vic->query_cap_name() +
                    " is burned badly by the fiery " + BALL + "!"
                    "%^RESET%^"
                    , environment(vic), (({ ETO, vic })));
            message("my_action", "%^YELLOW%^"
                    "The rod wielded by "
                    + ETO->query_cap_name() +
                    " releases " + i + " " + BALL + " of %^RED%^fiery energy%^YELLOW%^ as it strikes "
                    "you!"
                    "%^RESET%^"
                    , vic);
            for (x = 0; x < i; x++) {
                message("my_action", "%^RED%^"
                        "A fiery ball burns your body!"
                        "%^RESET%^"
                        , vic);
                vic->do_damage(vic->return_target_limb(), roll_dice(1, 6));
            }
            return 1;
        }
    }
}

int absorb_fun()
{
    if (!(TO->query_wielded())) {
        notify_fail("You must wield the rod to use that power!\n");
        return 0;
    }
// objectp check added by Lujke 17 Oct 2005
    if (!objectp(ETO) || !objectp(EETO)) {
        return 0;
    }
    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->set_paralyzed_message("info", ETO);
        return 1;
    }
    if (uses < 1) {
        notify_fail("The rod is currently empty of power!");
        return 0;
    }
//  several uses of TP replaced by ETO Lujke 17 Oct 2005
    if (ETO->query_paralyzed() || ETO->query_disable()) {
        return 0;
    }
    write("%^CYAN%^"
          "You concentrate on the rod and absorb it's inner force "
          "into your body!"
          "%^RESET%^"
          );
    say("%^CYAN%^"
        "The rod in " + TPQCN + " glows with a %^RESET%^white%^CYAN%^ "
        "light!"
        "%^RESET%^"
        , ETO);
    ETO->add_hp(uses);
    ETO->set_paralyzed(4, "%^CYAN%^You are absorbing the energy from the rod.%^RESET%^");
    uses = 0;
    return 1;
}

int expend_fun(string str)
{
    object ob;
    string dam;
    if (!(TO->query_wielded())) {
        notify_fail("You must wield the rod to use that power!\n");
        return 0;
    }
//objectp check added by Lujke 17 October 2005
    if (!objectp(ETO) || !objectp(EETO)) {
        return 0;
    }
    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->set_paralyzed_message("info", ETO);
        return 1;
    }
    if (uses < 1) {
        notify_fail("The rod is currently empty of power!");
        return 0;
    }
//  environment(TP) replaced by EETO Lujke 17 Oct 2005
    if (EETO->query_property("no attack")) {
        notify_fail("You cannot attack in this place.\n");
        return 0;
    }
    if (!str) {
//  TP replaced by ETO Lujke 17 Oct 2005
        ob = (object)ETO->query_current_attacker();
        if (!ob) {
            notify_fail("Expend who?\n");
            return 0;
        }
    } else {
        ob = present(str, environment(TP));
        if (!ob) {
            notify_fail("No " + str + " here!\n");
            return 0;
        }
    }
    if (!living(ob)) {
        notify_fail(ob->query_cap_name() + " is not a living thing!\n");
        return 0;
    }
//  TP replaced by ETO Lujke 17 Oct 2005
    if (ob == ETO) {
        notify_fail("That would be utterly stupid!\n");
        return 0;
    }
    if (ob->query_ghost()) {
        notify_fail("To a ghost???\n");
        return 0;
    }
    if (ob->is_player() && !interactive(ob)) {
        notify_fail("You cannot attack link-dead players.\n");
        return 0;
    }
//  TP replaced by ETO &  ETP replaced by EETO Lujke 17 Oct 2005
    tell_room(EETO,
              "%^BOLD%^%^BLUE%^A pure black beam surges forth from the rod wielded "
              "by " + ETOQCN + " and engulfs " + ob->QCN + "!"
              "%^RESET%^"
              , ({ EETO, ob }));
//  TP replaced by ETO Lujke 17 Oct 2005
    tell_object(ETO,
                "%^BOLD%^%^BLUE%^You concentrate on the rod and a pure black beam surges out of the rod "
                "and engulfs " + ob->QCN + "!"
                "%^RESET%^"
                );
    tell_object(ob,
                "%^BOLD%^%^BLUE%^A pure black beam surges forth from the rod wielded by "
                + TPQCN +
                "and engulfs you!"
                "%^RESET%^"
                );
    if ("daemon/saving_d"->saving_throw(ob, "rod_staff_wand")) {
        dam = "half";
    } else {
        dam = "all";
    }
    tell_object(ob,
                "%^BLUE%^Your body is gripped with immense pain as " + dam + " of the beam surrounds you!"
                "%^RESET%^"
                );
    tell_room(environment(ob),
              "%^BLUE%^" + ob->query_cap_name() + "'s body is gripped with immense pain as " + dam + " of the beam surrounds "
              + ob->QO + "!"
              "%^RESET%^"
              , ob);
    if (!ob->kill_ob(TP, 0)) {
        TP->kill_ob(ob, 0);
    }
    if (dam == "half") {
        ob->do_damage(ob->return_target_limb(), uses / 2);
        uses = uses - (uses / 2);
    } else {
        ob->do_damage(ob->return_target_limb(), uses);
        uses = 0;
    }
//  TP replaced by ETO Lujke 17 Oct 2005
    ETO->set_paralyzed(8, "%^BLUE%^You are busy expending the rod's energy!%^RESET%^");
    return 1;
}

int entangle_fun(string str)
{
    object ob;
    string dam;
    if (!(TO->query_wielded())) {
        notify_fail("You must wield the rod to use that power!\n");
        return 0;
    }
///////// objectp check added by Lujke 17 October 2005
    if (!objectp(ETO) || !objectp(EETO)) {
        return 0;
    }
    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->set_paralyzed_message("info", ETO);
        return 1;
    }
    if (uses < 24) {
        notify_fail("The rod is currently too low of power to do that!");
        return 0;
    }
//  environment(TP) replaced by EETO Lujke 17 Oct 2005
    if (EETO->query_property("no attack")) {
        notify_fail("You cannot attack in this place.\n");
        return 0;
    }
    if (!str) {
        ob = (object)TP->query_current_attacker();
//        if(!ob) {          This line replaced by an objectp check by Lujke 17 Oct 2005
        if (!objectp(ob)) {
            notify_fail("Entangle who?\n");
            return 0;
        }
    } else {
        ob = present(str, environment(TP));
//          if(!ob) {          This line replaced by an objectp check by Lujke 17 Oct 2005
        if (!objectp(ob)) {
            notify_fail("No " + str + " here!\n");
            return 0;
        }
    }
    if (!living(ob)) {
        notify_fail(ob->query_cap_name() + " is not a living thing!\n");
        return 0;
    }
    // TP replaced by ETO Lujke 17 Oct 2005
    if (ob == ETO) {
        notify_fail("That would be utterly stupid!\n");
        return 0;
    }
    if (ob->query_ghost()) {
        notify_fail("To a ghost???\n");
        return 0;
    }
    if (ob->is_player() && !interactive(ob)) {
        notify_fail("You cannot attack link-dead players.\n");
        return 0;
    }
    //added to recognize no stun creatures
    if (ob->query_property("no hold") || ob->query_property("no paralyze")) {
        notify_fail("That power is useless against this creature.");
        return 0;
    }
    // TP replaced by ETO and ETP replaced by EETO Lujke 17 Oct 2005
    tell_room(EETO,
              "%^BOLD%^%^GREEN%^The rod wielded "
              "by " + TPQCN + " transforms into a large %^RED%^python%^GREEN%^ and quickly "
              "entangles " + ob->query_cap_name() + "'s body!"
              "%^RESET%^"
              , ({ ETO, ob }));
    // TP replaced by ETO Lujke 17 Oct 2005
    tell_object(ETO,
                "%^BOLD%^%^GREEN%^You concentrate on the rod and it transforms into a large "
                "%^RED%^python%^GREEN%^ and quickly entangles " + ob->query_cap_name() + "'s body!"
                "%^RESET%^"
                );
    tell_object(ob,
                "%^BOLD%^%^GREEN%^The rod wielded by "
                + TPQCN +
                " transforms into a large %^RED%^python%^GREEN%^ and quickly entangles "
                "your body!"
                "%^RESET%^"
                );
    if ("daemon/saving_d"->saving_throw(ob, "rod_staff_wand")) {
        dam = "half";
    } else {
        dam = "all";
    }
    // TP replaced by ETO Lujke 17 Oct 2005  x2
    if (!ob->kill_ob(ETO, 0)) {
        ETO->kill_ob(ob, 0);
    }
    call_out("squeeze", 1, ob);
    call_out("squeeze", 4, ob);
    call_out("squeeze", 8, ob);
    if (dam == "half") {
        ob->set_paralyzed(12, "%^GREEN%^You are entangled by the python!%^RESET%^");
        // TP replaced by ETO Lujke 17 Oct 2005
        ETO->set_paralyzed(12, "%^GREEN%^You are busy controlling the python!%^RESET%^");
        uses = uses - 12;
    } else {
        ob->set_paralyzed(24, "%^GREEN%^You are entangled by the python!%^RESET%^");
        // TP replaced by ETO Lujke 17 Oct 2005
        ETO->set_paralyzed(24, "%^GREEN%^You are busy controlling the python!%^RESET%^");
        uses = uses - 24;
    }
    return 1;
}

void squeeze(object ob)
{
    /////////objectp test added by Lujke 17 October 2005
    if (!objectp(ob) || !objectp(environment(ob))) {
        return;
    }
    tell_room(environment(ob),
              "%^GREEN%^The python squeezes!%^RESET%^"
              );
    ob->do_damage(ob->return_target_limb(), random(8) + 5);
}

int escape_fun()
{
    if (!(TO->query_wielded())) {
        notify_fail("You must wield the rod to use that power!\n");
        return 0;
    }
//objectp check added by Lujke 17 October 2005
    if (!objectp(ETO)) {
        return 0;
    }
    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->set_paralyzed_message("info", ETO);
        return 1;
    }
    if (uses < 50) {
        notify_fail("The rod is currently too low of power!");
        return 0;
    }
// TP replaced by ETO By Lujke 17 October 2005
    if (ETO->query_current_attacker() == 0) {
        notify_fail("You are not in any danger!\n");
        return 0;
    }
    //set to recognize no tp places- dinji 8/24/2004
    // ETP changed to EETO by Lujke 17 October 2005, and objectp check added
    if (objectp(EETO)) {
        if (EETO->query_property("no teleport")) {
            notify_fail("A magical barrier halts your escape!");
            return 0;
        }
    }
    write("%^MAGENTA%^"
          "You concentrate on the rod and it senses your need to escape your surroundings!"
          "%^RESET%^"
          );
    say("%^MAGENTA%^"
        "The rod in " + TPQCN + "'s hand glows with a %^BOLD%^purple%^RESET%^%^MAGENTA%^ "
        "light!\n%^RESET%^%^YELLOW%^" + TPQCN + " vanishes!"
        "%^RESET%^"
        , TP);
    TP->move_player("/d/darkwood/room/road18.c", "with a puff of smoke and clap of thunder");
    TP->set_paralyzed(4, "%^MAGENTA%^You are stunned from the plane shift!%^RESET%^");
    uses = uses - 50;
    return 1;
}

int feed_fun()
{
    int cure;
    object obj;
    if (!(TO->query_wielded())) {
        notify_fail("You must wield the rod to use that power!\n");
        return 0;
    }
    // objectp check added by Lujke 17 October 2005
    if (!objectp(ETO)) {
        return 0;
    }
    if (ETO->query_bound() || ETO->query_paralyzed() || ETO->query_unconscious()) {
        ETO->set_paralyzed_message("info", ETO);
        return 1;
    }
    if (uses < 10) {
        notify_fail("The rod is currently too low of power!");
        return 0;
    }
/// several uses of TP replaced with ETO by Lujke 17 October 2005

    if (ETO->query_paralyzed() || ETO->query_disable()) {
        return 0;
    }

    if (ETO->query_current_attacker() != 0) {
        notify_fail("You are too busy fighting!\n");
        return 0;
    }
    if (obj = present("corpse", environment(TP))) {
        write("%^YELLOW%^"
              "You concentrate on the rod and it absorbs the soul from within the "
              "corpse before you.\n%^BLUE%^The rod tranfers the energy into replenishing "
              "energy for you!"
              "%^RESET%^"
              );
        say("%^YELLOW%^"
            "The rod in " + TPQCN + "'s hand glows with a %^BLUE%^blue%^YELLOW%^ "
            "light!\n%^BLUE%^The corpse before you vanishes!%^RESET%^"
            "%^RESET%^"
            , ETO);
        cure = random(10) + 15;
        uses = uses - cure / 3;
        ETO->add_hp(cure);
/// end of replacements
        obj->remove();
        return 1;
    } else {
        notify_fail("There is no corpse present!\n");
        return 0;
    }
}
