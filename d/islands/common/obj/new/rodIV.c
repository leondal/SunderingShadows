#include <std.h>
inherit "/d/common/obj/weapon/mstaff.c";

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
    add_action("consume_fun", "consume");
    add_action("absorb_fun", "absorb");
    add_action("entangle_fun", "entangle");
    add_action("escape_fun", "escape");
    add_action("read_rod", "read");
    add_action("fireball", "burn");
    add_action("cone_of_cold", "freeze");
    add_action("prismatic_spray", "spray");
}

void create()
{
    ::create();
    set_name("rod of wizard IV");

    set_id(({ "rod", "rod of wizardry", "rod of wizardry IV" }));

    set_obvious_short("A rod");

    set_short("%^BOLD%^%^RED%^Rod of Wizardry IV%^RESET%^");

    set_long(
        "%^BOLD%^%^RED%^This rod is shaped from a twisted reddish metal of unknown origin." +
        " One end of the rod has been fashioned into a %^RESET%^%^RED%^dragons claw %^BOLD%^gripping a large" +
        " %^BLACK%^obsidian cr%^RESET%^y%^BOLD%^%^BLACK%^st%^RESET%^a%^BOLD%^%^BLACK%^l%^RED%^" +
        " that %^BLACK%^g%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^o%^BLUE%^w%^BLACK%^s %^RED%^with a %^RESET%^%^BLUE%^e%^BOLD%^%^BLACK%^e%^BLUE%^r%^RESET%^%^BLUE%^y" +
        " l%^BOLD%^%^BLACK%^i%^RESET%^%^BLUE%^g%^BOLD%^h%^RESET%^%^BLUE%^t%^BOLD%^%^RED%^" +
        ".  The %^RESET%^%^RED%^claw %^BOLD%^is incredibly lifelike, with each %^RESET%^talon %^BOLD%^r%^RESET%^a%^BOLD%^%^BLACK%^z%^RESET%^o%^BOLD%^r" +
        " sharp %^RED%^and every individual %^RESET%^%^RED%^scale %^BOLD%^carved with amazing detail.  Spiralling along the twisted metal are etchings of" +
        " strange %^YELLOW%^symbols %^BOLD%^%^RED%^constantly shifting and arranging themselves into random patterns" +
        " of ancient arcane language.%^RESET%^");

    set_value(370000);
    set_size(1);
    set_prof_type("rod");

    set_item_bonus("spell penetration", 4);
    set_item_bonus("caster level", 3);

    set_property("able to cast", 1);

    set_property("no curse", 1);
    set_property("enchantment", 7);

    set_wield((: TO, "wieldme" :));
    set_hit((: TO, "extra_hit" :));

    uses = 500;
    BLAST = 1;
}

int wieldme()
{
    if (member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^", ETO->query_mini_quests()) == -1) {
        tell_object(ETO, "%^BOLD%^%^RED%^You have not earned the right to make use of this item and it lashes out at you!");
        tell_room(EETO, "%^BOLD%^%^RED%^" + ETO->QCN + " suddenly gets a look of horror and recoils in pain!%^RESET%^ ", ({ ETO }));
        ETO->do_damage("head", 50);
        ETO->add_attacker(TO);
        ETO->continue_attack();
        ETO->remove_attacker(TO);
        uses = uses + 50;
        return 0;
    }
    if (!ETO->query_property("silent_wield")) {
        tell_object(ETO, "%^BOLD%^%^RED%^You grip the rod firmly and a strange sense of power overcomes you.");
        return 1;
    }
}

int read_rod(string str)
{
    if (!str) {
        return notify_fail("Read what?");
    }
    if (str == "rod") {
        if (((int)ETO->query_prestige_level("mage") < 45) && ((int)ETO->query_prestige_level("sorcerer") < 45)) {
            tell_object(ETO, "%^YELLOW%^As you squint to try to make sense of the strange symbols, the rod suddenly shocks you!");
            tell_room(EETO, "%^BOLD%^%^RED%^" + ETO->QCN + " is shocked by a bolt of energy as they try to make sense of the symbols on the rod!%^RESET%^ ", ({ ETO }));
            ETO->do_damage("head", 50);
            ETO->add_attacker(TO);
            ETO->continue_attack();
            ETO->remove_attacker(TO);
            uses = uses + 50;
            return 0;
        }
        write("%^BOLD%^%^RED%^Traced along the shaft of the rod in a spiralling pattern are the words %^YELLOW%^escape%^RED%^, %^YELLOW%^entangle%^RED%^, %^YELLOW%^absorb%^RED%^, %^YELLOW%^ consume%^RED%^, %^YELLOW%^expend%^RED%^, %^YELLOW%^charge%^RED%^, %^YELLOW%^blast%^RED%^, %^BOLD%^%^YELLOW%^burn%^BOLD%^%^RED%^, %^BOLD%^%^YELLOW%^freeze%^BOLD%^%^RED%^, and %^BOLD%^%^YELLOW%^spray%^BOLD%^%^RED%^.");
        return 1;
    }
}

int fireball(string str)
{
    object ob;
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (!query_wielded()) {
        return notify_fail("Wield it first?");
    }
    if (!str) {
        return notify_fail("You must designate a target!");
    }
    if (!(ob = present(str, ETP))) {
        return notify_fail("You do not see that!");
    }
    tell_room(ETP, "%^BOLD%^%^CYAN%^" + TPQCN + " raises " + TP->QP + " rod and utters a word!", TP);
    new("/cmds/spells/f/_fireball")->use_spell(TP, ob, TP->query_level(), 100, "mage");
    TP->set_paralyzed(2, "You are busy controlling the rod.");
    return 1;
}

int cone_of_cold(string str)
{
    object ob;
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (!query_wielded()) {
        return notify_fail("Wield it first?");
    }
    if (uses < 10) {
        notify_fail("The rod does not have enough power!");
        return 0;
    }
    if (!str) {
        return notify_fail("You must designate a target!");
    }
    if (!(ob = present(str, ETP))) {
        return notify_fail("You do not see that!");
    }
    tell_room(ETP, "%^BOLD%^%^RED%^" + TPQCN + " raises " + TP->QP + " rod and utters a word!", TP);
    new("/cmds/spells/c/_cone_of_cold")->use_spell(TP, ob, TP->query_level(), 100, "mage");
    TP->set_paralyzed(2, "You are busy controlling the rod.");
    uses = uses - 10;
    return 1;
}

int prismatic_spray(string str)
{
    object ob;
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if (!query_wielded()) {
        return notify_fail("Wield it first?");
    }
    if (uses < 12) {
        notify_fail("The rod does not have enough power!");
        return 0;
    }
    if (!str) {
        return notify_fail("You must designate a target!");
    }
    if (!(ob = present(str, ETP))) {
        return notify_fail("You do not see that!");
    }
    tell_room(ETP, "%^BOLD%^%^YELLOW%^" + TPQCN + " raises " + TP->QP + " rod and utters a word!", TP);
    new("/cmds/spells/p/_prismatic_spray")->use_spell(TP, ob, TP->query_level(), 100, "mage");
    TP->set_paralyzed(2, "You are busy controlling the rod.");
    uses = uses - 15;
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
                + vic->QCN +
                " with the rod!%^RESET%^"
                , ETO);
        message("other_action", "%^ORANGE%^"
                + ETO->QCN +
                " smites "
                + vic->QCN +
                " with the rod!"
                "%^RESET%^"
                , environment(vic), (({ ETO, vic })));
        message("my_action", "%^ORANGE%^"
                + ETO->QCN +
                " smites "
                "you with the rod in "
                + ETO->QP +
                " hand!%^RESET%^"
                , vic);
        dam = random(10) + 5;
        return dam;
    } else {
        if (BLAST == 0) {
            message("my_action", "%^CYAN%^"
                    "The rod glows as you strike "
                    + vic->QCN +
                    "!"
                    "%^RESET%^"
                    , ETO);
            message("other_action", "%^CYAN%^"
                    "The rod wielded by "
                    + ETO->QCN +
                    " glows as it strikes "
                    + vic->QCN +
                    "!"
                    "%^RESET%^"
                    , environment(vic), (({ ETO, vic })));
            message("my_action", "%^CYAN%^"
                    "The rod wielded by "
                    + ETO->QCN +
                    " glows as it strikes "
                    "you!"
                    "%^RESET%^"
                    , vic);
            uses = uses + random(5) + 1;
            if (uses > 500) {
                uses = 500;
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
                    + vic->QCN +
                    "!"
                    "\n%^RESET%^%^RED%^"
                    + vic->QCN +
                    " is burned badly by the fiery " + BALL + "!"
                    "%^RESET%^"
                    , ETO);
            message("other_action", "%^YELLOW%^"
                    "The rod wielded by "
                    + ETO->QCN +
                    " releases " + i + " " + BALL + " of %^RED%^fiery energy%^YELLOW%^ as it strikes "
                    + vic->QCN +
                    "!"
                    "\n%^RESET%^%^RED%^"
                    + vic->QCN +
                    " is burned badly by the fiery " + BALL + "!"
                    "%^RESET%^"
                    , environment(vic), (({ ETO, vic })));
            message("my_action", "%^YELLOW%^"
                    "The rod wielded by "
                    + ETO->QCN +
                    " releases " + i + " " + BALL + " of %^RED%^fiery energy%^YELLOW%^ as it strikes "
                    "you!"
                    "%^RESET%^"
                    , vic);
            for (x = 0; x < i; x++) {
                message("my_action", "%^RED%^"
                        "A fiery ball burns your body!"
                        "%^RESET%^"
                        , vic);
                vic->do_damage(vic->return_target_limb(), random(5) + 8);
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
        "The rod in " + TPQCN + "'s hand glows with a %^RESET%^white%^CYAN%^ "
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
        notify_fail(ob->QCN + " is not a living thing!\n");
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
              "%^BLUE%^" + ob->QCN + "'s body is gripped with immense pain as " + dam + " of the beam surrounds "
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
    ETO->set_paralyzed(4, "%^BLUE%^You are busy expending the rod's energy!%^RESET%^");
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
        notify_fail(ob->QCN + " is not a living thing!\n");
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
              "entangles " + ob->QCN + "'s body!"
              "%^RESET%^"
              , ({ ETO, ob }));
    // TP replaced by ETO Lujke 17 Oct 2005
    tell_object(ETO,
                "%^BOLD%^%^GREEN%^You concentrate on the rod and it transforms into a large "
                "%^RED%^python%^GREEN%^ and quickly entangles " + ob->QCN + "'s body!"
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
    if (ETO->query_current_attacker() == 0) {
        notify_fail("You are not in any danger!\n");
        return 0;
    }
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
    TP->set_paralyzed(2, "%^MAGENTA%^You are stunned from the plane shift!%^RESET%^");
    uses = uses - 50;
    return 1;
}

int consume_fun()
{
    int cure;
    object obj;
    if (!(TO->query_wielded())) {
        notify_fail("You must wield the rod to use that power!\n");
        return 0;
    }

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
        uses = uses + cure / 3;
        ETO->add_hp(cure);
        obj->remove();
        return 1;
    } else {
        notify_fail("There is no corpse present!\n");
        return 0;
    }
}
