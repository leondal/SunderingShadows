#include <std.h>
#include <magic.h>
#include "../dojo.h"
inherit WEAPONLESS;

int talking;
void quest_complete(object quester);

void create()
{
    ::create();
    set_name("Tattva");
    set_short("%^BOLD%^%^WHITE%^Tattva, the maiden of truth%^RESET%^");
    set_id(({ "tattva", "Tattva", "maiden", "maiden of truth" }));
    set_long("%^RESET%^%^GREEN%^This girl is only young, perhaps no more than ten years of age, but the depths of her "
             "%^BOLD%^%^BLACK%^dark eyes %^RESET%^%^GREEN%^reveal a being far older.  She bears a solemn, stoic %^MAGENTA%^grace "
             "%^GREEN%^about her in all that she does, making no unnecessary movements nor speaking without need.  A softly folded "
             "kimono of %^RESET%^pure white %^GREEN%^enshrouds her waifish form, leaving hands and face visible with %^ORANGE%^smooth "
             "olive skin%^GREEN%^.  %^BOLD%^%^BLACK%^Dark ringlets %^RESET%^%^GREEN%^of hair are pinned back from her face with two "
             "%^RESET%^ivory combs%^GREEN%^, brushed aside from the heart-shaped face that bespeaks a beauty yet to come in "
             "adulthood.  She watches you expectantly, as if wait for you to %^YELLOW%^greet her%^RESET%^%^GREEN%^.%^RESET%^");
    set_race("human");
    set_body_type("human");
    set_stats("intelligence", 18);
    set_stats("wisdom", 18);
    set_stats("strength", 12);
    set_stats("charisma", 16);
    set_stats("dexterity", 14);
    set_stats("constitution", 12);
    set_class("thief");
    set_mlevel("thief", 20);
    set_guild_level("thief", 20);
    set_alignment(5);
    set_gender("female");
    set_size(2);
    set_exp(0);
    set_overall_ac(-60);
    set_hd(20, 8);
    set_max_hp(9001);
    set_hp(query_max_hp());
    set("aggressive", 0);
    set_attack_limbs(({ "left hand" }));
    set_attacks_num(0);
    set_base_damage_type("slashing");
    set_damage(1, 2);
    set_mob_magic_resistance("high");
    set_property("no bows", 1);
    set_property("no death", 1);
    set_spoken("wizish");
    command("speech speak softly but clearly");
    command("pose kneeling on the tatami mat");
    talking = 0;
}

void init()
{
    ::init();
    if (!userp(TP)) {
        return;
    }
    if (present("dojospirittoken", TP)) {
        call_out("quest_complete", 1, TP);
    }
    add_action("request_weapon", "ask");
}

int query_talking()
{
    return talking;
}

void catch_say(string msg)
{
    if (!msg || talking) {
        return;
    }

    if ((strsrch(msg, "ello") != -1) || (strsrch(msg, "reetings") != -1)) {
        talking = 1;
        call_out("speech1", ROUND_LENGTH);
        return;
    }
    if (strsrch(msg, "participate") != -1) {
        talking = 1;
        call_out("participate1", ROUND_LENGTH);
        return;
    }
}

void speech1()
{
    force_me("emoteat tattva %^RESET%^%^CYAN%^$M rises from the tatami mat as you approach.%^RESET%^");
    write("");
    force_me("say %^MAGENTA%^'%^RESET%^Namastae, worthy travellers, and welcome to the Vasati Aadhyaatmika.%^MAGENTA%^'"
             "%^RESET%^");
    force_me("emoteat tattva %^RESET%^%^CYAN%^$M makes a slight bow made with hands pressed together before her chest, "
             "palms touching and fingers pointed upwards.%^RESET%^");
    write("");
    call_out("speech2", ROUND_LENGTH);
}

void speech2()
{
    force_me("say %^MAGENTA%^'%^RESET%^It is here that we seek enlightenment through meditation and perfection of the "
             "physical form. We would welcome any visitors to join us if they are so inclined.%^MAGENTA%^'%^RESET%^");
    force_me("emoteat tattva %^RESET%^%^CYAN%^$M makes a smooth motion with her left hand, gesturing to the chamber "
             "around her.%^RESET%^");
    write("");
    call_out("speech3", ROUND_LENGTH);
}

void speech3()
{
    force_me("say %^MAGENTA%^'%^RESET%^Please, simply ask me if you wish to know how you may %^YELLOW%^participate "
             "%^RESET%^in what we do here.%^MAGENTA%^'%^RESET%^");
    force_me("emoteat tattva %^RESET%^%^CYAN%^$M kneels back down on the tatami mat and calmly waits.%^RESET%^");
    write("");
    talking = 0;
}

void participate1()
{
    force_me("emoteat tattva %^RESET%^%^CYAN%^$M nods softly.%^RESET%^");
    force_me("say %^MAGENTA%^'%^RESET%^Each of our masters awaits patiently if you should wish to test your skill against "
             "them. But do not take this offer lightly. This must be done alone and unassisted.%^MAGENTA%^'%^RESET%^");
    force_me("emoteat tattva %^RESET%^%^CYAN%^$M's gaze becomes very serious, an expression that seems very much at odds "
             "with her apparent age.%^RESET%^");
    write("");
    call_out("participate2", ROUND_LENGTH);
}

void participate2()
{
    force_me("say %^MAGENTA%^'%^RESET%^None here will offer death as punishment for failure, for in doing so we leave no "
             "path for the lessons taught by your experience here. But you may find yourself weakened from your exertions, and the "
             "responsibility lies upon yourself to choose if you are willing to suffer such a lesson.%^MAGENTA%^'%^RESET%^");
    force_me("emoteat tattva %^RESET%^%^CYAN%^$M draws her hands back together with palms touching, and steps aside to "
             "allow you to progress forward unimpeded.%^RESET%^");
    write("");
    call_out("participate4", ROUND_LENGTH);
}

void participate4()
{
    force_me("say %^MAGENTA%^'%^RESET%^Go, as you will, with the blessing of the spirits.  Simply %^YELLOW%^touch "
             "%^RESET%^any door you wish to enter, and from there your actions will dictate your path.  But you will only be permitted "
             "to enter our sensei's room above when you have first bested the four masters here below.%^MAGENTA%^'%^RESET%^");
    force_me("emoteat tattva %^RESET%^%^CYAN%^$M offers a gesture with the palm of her left hand, towards the spiral "
             "staircase leading to the room above.%^RESET%^");
    write("");
    call_out("participate5", ROUND_LENGTH);
}

void participate5()
{
    force_me("say %^MAGENTA%^'%^RESET%^If you should return to me with the combined tokens of the five masters, I will "
             "grant you the right to wield such a weapon as any of the masters themselves see fit.%^MAGENTA%^'%^RESET%^");
    force_me("emoteat tattva %^RESET%^%^CYAN%^$M kneels back down on the tatami mat and calmly just watches.%^RESET%^");
    write("");
    talking = 0;
}

void heart_beat()
{
    int i, j;
    object* myinven;
    ::heart_beat();
    if (sizeof(TO->query_attackers()) > 0) {
        force_me("say %^MAGENTA%^'%^RESET%^Your anger brings me great sorrow. Go, stranger, and return if you are prepared "
                 "to challenge one of the masters.%^MAGENTA%^'%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^WHITE%^Tattva calmly raises a hand before her and speaks a word that seems to disappear "
                  "from your memory a second later.  Everything goes calm and still.  She simply shakes her head and kneels back down on "
                  "the mat, once again a picture of serenity.");
        myinven = all_living(ETO);
        for (i = 0; i < sizeof(myinven); i++) {
            for (j = 0; j < sizeof(myinven); j++) {
                if (member_array(myinven[i], myinven[j]->query_attackers()) != -1) {
                    myinven[i]->remove_attacker(myinven[j]);
                    myinven[j]->remove_attacker(myinven[i]);
                }
            }
        }
        return;
    }
}

void die(object ob)
{
    int i, j;
    object* myinven;
    set_hp(query_max_hp());
    force_me("say %^MAGENTA%^'%^RESET%^Your anger brings me great sorrow. Go, stranger, and return if you are prepared "
             "to challenge one of the masters.%^MAGENTA%^'%^RESET%^");
    if (sizeof(TO->query_attackers()) > 0) {
        tell_room(ETO, "%^BOLD%^%^WHITE%^Tattva calmly raises a hand before her and speaks a word that seems to disappear "
                  "from your memory a second later.  Everything goes calm and still.  She simply shakes her head and kneels back down on "
                  "the mat, once again a picture of serenity.");
        myinven = all_living(ETO);
        for (i = 0; i < sizeof(myinven); i++) {
            for (j = 0; j < sizeof(myinven); j++) {
                if (member_array(myinven[i], myinven[j]->query_attackers()) != -1) {
                    myinven[i]->remove_attacker(myinven[j]);
                    myinven[j]->remove_attacker(myinven[i]);
                }
            }
        }
        return;
    }
}

void quest_complete(object quester)
{
    if (!objectp(quester)) {
        return;
    }
    if (!userp(quester)) {
        return;
    }
    if (!present("dojospirittoken", quester)) {
        return;
    }
    if (quester->query_property("dojo weapon claimable")) {
        return;
    }
    quester->set_property("dojo weapon claimable", 1);

// if not previously done, award the quest!
    if (member_array("%^RESET%^%^MAGENTA%^%^Defeated the masters of the Vasati Aadhyaatmika.%^RESET%^", quester->query_mini_quests()) == -1) {
        force_me("emoteat " + quester->query_name() + " %^RESET%^%^CYAN%^$M smiles at $N.%^RESET%^");
        force_me("say %^MAGENTA%^'%^RESET%^I see that you have, for the first time, overcome our masters.  Well done.%^MAGENTA%^'%^RESET%^");
        quester->set_mini_quest("%^RESET%^%^MAGENTA%^%^Defeated the masters of the Vasati Aadhyaatmika.%^RESET%^", 3100000, "%^RESET%^%^MAGENTA%^%^Defeated the masters of the Vasati Aadhyaatmika.%^RESET%^");
        tell_object(TP, "%^YELLOW%^You have achieved: %^RESET%^%^MAGENTA%^%^Defeated the masters of the Vasati Aadhyaatmika!%^RESET%^");
    }
    force_me("emoteat tattva %^RESET%^%^CYAN%^$M gracefully inclines her head.%^RESET%^");
    force_me("say %^MAGENTA%^'%^RESET%^With this victory, it would gladden us to offer you such a weapon as would serve "
             "you well.  Simply produce the five tokens you have earned, and %^YELLOW%^ask for %^RESET%^the weapon you wish.%^MAGENTA%^'%^RESET%^");
    force_me("say %^MAGENTA%^'%^RESET%^You may request Tejas' %^YELLOW%^orb%^RESET%^, Pavan's %^YELLOW%^tonfa%^RESET%^, "
             "Bhumi's %^YELLOW%^gladius%^RESET%^, Jala's %^YELLOW%^whip%^RESET%^, or Akasha's %^YELLOW%^staff%^RESET%^.%^MAGENTA%^'%^RESET%^");
}

int request_weapon(string str)
{
    string selection;
    object ob1, ob2, ob3, ob4, ob5, weppin;
    int failflag;

    if (!objectp(TP)) {
        return 0;
    }
    if (!userp(TP)) {
        return 0;
    }
    if (sscanf(str, "for %s", selection) != 1) {
        tell_object(TP, "%^YELLOW%^You should <ask for weapon>.  You remember that Tattva mentioned an orb, a tonfa, a gladius, a whip, or a staff.%^RESET%^");
        return 1;
    }
    if (!TP->query_property("dojo weapon claimable")) {
        tell_object(TP, "%^YELLOW%^You realise you currently have no claim to a weapon.  Perhaps you could earn one?%^RESET%^");
        return 1;
    }

    ob1 = present("dojoairtoken", TP);
    if (!ob1 || base_name(ob1) != OBJ "airtoken") {
        failflag = 1;
    }
    ob2 = present("dojofiretoken", TP);
    if (!ob2 || base_name(ob2) != OBJ "firetoken") {
        failflag = 1;
    }
    ob3 = present("dojowatertoken", TP);
    if (!ob3 || base_name(ob3) != OBJ "watertoken") {
        failflag = 1;
    }
    ob4 = present("dojoearthtoken", TP);
    if (!ob4 || base_name(ob4) != OBJ "earthtoken") {
        failflag = 1;
    }
    ob5 = present("dojospirittoken", TP);
    if (!ob5 || base_name(ob5) != OBJ "spirittoken") {
        failflag = 1;
    }

    if (failflag) {
        force_me("emoteat " + TP->query_name() + " %^RESET%^%^CYAN%^$M acknowledges your weapon request with a nod, but does not move to offer one.%^RESET%^");
        force_me("say %^MAGENTA%^'%^RESET%^You have earned a weapon, but I see you are missing at least one of the tokens.  When you have all five, "
                 "I may offer you a weapon of your choice.%^MAGENTA%^'%^RESET%^");
        return 1;
    }
    if (selection != "orb" && selection != "tonfa" && selection != "gladius" && selection != "whip" && selection != "staff") {
        force_me("emoteat " + TP->query_name() + " %^RESET%^%^CYAN%^$M acknowledges your weapon request with a nod, but does not move to offer one.%^RESET%^");
        force_me("say %^MAGENTA%^'%^RESET%^I cannot offer you a " + selection + ".  I can offer you Tejas' %^YELLOW%^orb%^RESET%^, Pavan's %^YELLOW%^tonfa"
                 "%^RESET%^, Bhumi's %^YELLOW%^gladius%^RESET%^, Jala's %^YELLOW%^whip%^RESET%^, or Akasha's %^YELLOW%^staff%^RESET%^.%^MAGENTA%^'%^RESET%^");
        return 1;
    }
    force_me("emoteat " + TP->query_name() + " %^RESET%^%^CYAN%^$M acknowledges your weapon request with a nod.%^RESET%^");
    force_me("say %^MAGENTA%^'%^RESET%^Very well.  Here is the " + selection + ".  Use it wisely.%^MAGENTA%^'%^RESET%^");
    force_me("emoteat " + TP->query_name() + " %^RESET%^%^CYAN%^With a wave of $M's hand, the tokens vanish, and a weapon appears at $np feet.%^RESET%^");
    TP->remove_property("dojo weapon claimable");
    ob1->remove();
    ob2->remove();
    ob3->remove();
    ob4->remove();
    ob5->remove();
    switch (selection) {
    case "orb": weppin = OBJ "spellorb"; break;

    case "tonfa": weppin = OBJ "tonfa"; break;

    case "gladius": weppin = OBJ "gladius"; break;

    case "whip": weppin = OBJ "chainwhip"; break;

    case "staff": weppin = OBJ "bostaff"; break;

    default: tell_room(ETO, "%^BOLD%^%^RED%^The weapon selection is broken! Please contact Nienne.%^RESET%"); break;
    }
    weppin->move(ETO);
    return 1;
}
