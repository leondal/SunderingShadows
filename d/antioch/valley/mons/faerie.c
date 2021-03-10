//Code is take from /d/deku/monster/drakkan - Coded by Saide
//Made to give goodies a chance to get items without killing
//fey creatures - Cythera 04/05
#include <std.h>
#include <daemons.h>
#define OBJ "/d/antioch/valley/obj/" +

#define SEEK_ITEMS ({ "ogre club", "skull sword", "black belt", \
                      "hematite ring", "snake belt" })

#define DSEEK "moonstone_peasblossom_item_seeking"
#define ODSEEK "old_moonstone_peasblossom_item_seeking"

#define DKILLERS "moonstone_peasblossom_killers"

inherit NPC;

int flag, delay, flag2, already_helped;
string helper;
void do_help(object to);
void check_present();
void go_home(object to);
void special_attack(object targ);

void init()
{
    ::init();

    if (interactive(TP) && !TP->query_invis()) {
        do_help(TO);
    }
    add_action("choose_item", "choose");
    add_action("show_item", "showme");
}

void create()
{
    object ob;
    string* oitems, * items, oitem, nitem;
    ::create();
    set_name("peasblossom");
    set_id(({ "peasblossom", "faerie", "fairy", "fey" }));
    set_short("Peasblossom - The Mischievous Faerie");

    set_long("%^GREEN%^With her short %^MAGENTA%^purple%^GREEN%^" +
             " hair and angular face, Peasblossom has an almost " +
             "elven look to hear appearance.  Her slender willowy" +
             " body looks fragile and delicate, like that of most " +
             "fey creatures.  Her %^BOLD%^verdant green%^RESET%^" +
             "%^GREEN%^ eyes sparkle with a mischievous light.  " +
             "A sassy grin seems permanently etched on her lips.  " +
             "A small pouch made from %^YELLOW%^tulip%^RESET%^%^GREEN%^" +
             " petals hangs from her small waist.  Ethereal gossamer wings" +
             " flutter about behind her, in muted tones of %^CYAN%^cyan%^GREEN%^" +
             ", %^BOLD%^%^BLUE%^blue%^RESET%^%^GREEN%^, %^BOLD%^%^MAGENTA%^" +
             "pink%^RESET%^%^GREEN%^ and%^YELLOW%^ gold%^RESET%^%^GREEN%^.  " +
             "As she flies about a trail of %^YELLOW%^golden%^RESET%^%^GREEN%^" +
             " sparkling dust is left in her wake.");

    set_gender("female");
    set_race("faerie");
    set_body_type("humanoid");
    set_class("cleric");
    set_class("thief");
    set_guild_level("cleric", 20 + random(3));
    set_mlevel("cleric", query_guild_level("cleric"));
    set_guild_level("cleric", 20);
    set_mlevel("thief", 20);
    set_mob_magic_resistance("average");
    set_spell_chance(40);
    set_spells(({ "call lightning", "airbolt", "dispel magic" }));
    set_scrambling(1);
    set_alignment(7);
    set_hp(query_level() * 20);
//    set_exp(query_max_hp() * 30);
    set_new_exp(20, "high");
    add_limb("left wing", "torso", 0, 0, 0);
    add_limb("right wing", "torso", 0, 0, 0);
    flag = 0;
    set_stats("strength", 15);
    set_stats("wisdom", 17);
    set_stats("intelligence", 15);
    set_stats("charisma", 19);
    set_stats("constitution", 17);
    set_stats("dexterity", 18);
    set_attack_bonus(10);
    set_damage_bonus(4);
    set_property("full attacks", 1);
    set_property("no death", 1);
    set_property("no paralyze", 1);
    set_overall_ac(-5 - (random(7)));
    set_property("magic", 1);
    switch (random(35)) {
    case 0..5:
        ob = new(OBJ "dryad_staff");
        ob->set_size(2);
        ob->move(TO);
        command("wield staff");
        break;

    case 6..12:
        new(OBJ "leaffan")->move(TO);
        command("wield fan");
        break;

    case 13..14:
        new(OBJ "dknife")->move(TO);
        command("wield kama");
        break;

    case 15..19:
        ob = new(OBJ "tlongsword")->move(TO);
        command("wield sword");
        break;

    case 20..24:
        new(OBJ "sspear")->move(TO);
        command("wield spear");
        break;

    case 25..29:
        new(OBJ "sirine_sword")->move(TO);
        command("wield sword");
        break;

    default:
        new(OBJ "sea_dagger")->move(TO);
        command("wield dagger");
    }
    switch (random(49)) {
    case 0..9:
        ob = new(OBJ "buckler")->move(TO);
        command("wear buckler");
        break;

    case 10..19:
        new(OBJ "sshield")->move(TO);
        command("wear shield");
        break;

    case 20..29:
        ob = new(OBJ "vine_necklace")->move(TO);
        command("wear necklace");
        break;

    case 30..34:
        new(OBJ "pshoes")->move(TO);
        command("wear shoes");
        break;

    case 35..39:
        new(OBJ "phat")->move(TO);
        command("wear hat");
        break;

    case 40..49:
        new(OBJ "feathercloak")->move(TO);
        command("wear cloak");
        break;
    }
    switch (random(70)) {
    case 0..29:
        ob = new(OBJ "tunics");
        ob->move(TO);
        command("wear tunic");
        break;

    case 30..39:
        ob = new(OBJ "flower_dress");
        ob->set_property("enchantment", 1);
        ob->move(TO);
        command("wear dress");
        break;

    case 40..49:
        ob = new(OBJ "shifts")->move(TO);
        command("wear top");
        break;

    case 50..59:
        ob = new(OBJ "air_robes")->move(TO);
        command("wear dress");
        break;

    case 60..69:
        new(OBJ "bikini")->move(TO);
        command("wear top");
        break;
    }

    command("wearall");
    if (sizeof(SAVE_D->query_array(DSEEK)) < 1) {
        items = SEEK_ITEMS;
        if (sizeof(SAVE_D->query_array(ODSEEK))) {
            oitems = SAVE_D->query_array(ODSEEK);
            oitem = oitems[0];
            items -= ({ oitem });
        }
        nitem = items[random(sizeof(items))];
        SAVE_D->remove_array(ODSEEK);
        SAVE_D->set_value(ODSEEK, nitem);
        SAVE_D->set_value(DSEEK, nitem);
    }
}

void heart_beat()
{
    int x;
    string* enemies;
    object cor;
    ::heart_beat();
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    enemies = query_attackers();

    if (flag2 == 0 && query_current_attacker()) {
        if (ETO->query_property("used sticks")) {
            ETO->remove_property("used sticks");
        }
        new("/cmds/spells/s/_sticks_into_snakes.c")->use_spell(TO, 0, 20, 20, "cleric");
        flag2 = 1;
        return;
    }
    if (delay > 400) {
        flag2 = 0;
        delay = 0;
    }
    if (flag2 == 1) {
        delay++;
    }
    if (cor = present("corpse", ETP)) {
        if (living(cor)) {
            return;
        }
    }
}

void reset()
{
    ::reset();
}

void do_help(object to)
{
    object* alive;
    int people, x;

    if (!objectp(ETO)) {
        return;
    }
    if (!objectp(to)) {
        return;
    }
    if (already_helped == 1) {
        return;
    }

    alive = filter_array(all_living(ETO), "is_non_immortal_player", FILTERS_D);

    if (sizeof(alive) < 1) {
        if (!objectp(to)) {
            return;
        }
        return;
    }
    command("emote flutters around your head on her colorful wings.");
    command("speak wizish");
    command("say Hello there!  Would you like to help me?");
    command("emote smiles to you.");
}

void catch_say(string msg)
{
    ::catch_say(msg);
    if (interactive(TP)) {
        call_out("response", 1, msg, TP);
    }
}

void convert_item_to_msg(string item, int x)
{
    if (x == 0) {
        command("emote claps her hands.");
        command("say So you will help me!");
    }
    if (item == "ogre club") {
        switch (x) {
        case 0:
            command("say The ogres have gotten out of hand!  " +
                    "I saw a creepy man with them once, enslaving the" +
                    " spirit of some poor woman into a large club.  Such" +
                    " a mean and cruel thing to do!  If you can find me " +
                    "this club and bring it back, I shall reward you with" +
                    " one of my items.");
            break;

        case 1:
            command("say I am looking for the ogre's scary club " +
                    "right now. I am not interested in that, sorry.");
            break;

        case 2:
            command("say The druids will know what to do about" +
                    " the club.  We can't leave that poor woman's spirit" +
                    " trapped there, can we?");
            command("say The ogres can be found down in the Dark Trail." +
                    "  They usually stick together in a group.");
            break;
        }
    }
    if (item == "black belt") {
        switch (x) {
        case 0:
            command("say The Shades have been growing bolder with" +
                    " their undead allies!  If you could bring me back " +
                    "the black belt that one of the shades wear, I can reward you!.");
            break;

        case 1:
            command("say This is not what I was looking for.  I wanted the" +
                    " black belt from a shade.");
            break;

        case 2:
            command("say A shade once tried to enter the valley!  He got" +
                    " as far as the cherry tree before the druids destroyed" +
                    " him.  Please help quell the number of these undead.  " +
                    "Besides his belt is ugly.");
            command("say The Shade can be found on the Dark Trail.  " +
                    "They seem to come out during the night more than the day.");
            break;
        }
    }
    if (item == "skull sword") {
        switch (x) {
        case 0:
            command("say I am looking for a spooky sword with a skull on " +
                    "it.  It's a TERRIBLE blade!  If you bring it to me, I will " +
                    "reward you.");
            break;

        case 1:
            command("say This is nice, but not what I am looking for. " +
                    "I wanted a great sword with a skull on it.");
            break;

        case 2:
            command("say The sword burns with an evil and tainted aura!" +
                    "  It is just horrible!");
            command("emote shivers as she flies around you.");
            command("say I heard one of the druids say that skeletons on " +
                    "the Dark Trail have been spotted with a sword that bears a skull.");
            break;
        }
    }
    if (item == "snake belt") {
        switch (x) {
        case 0:
            command("say If you've spoken to the swanmays, then" +
                    " you know of the serpent.  A teardrop is not what" +
                    " I seek, though.  I need a belt made of snake skin!" +
                    "  Bring me this belt and I shall find a reward for you!");
            break;

        case 1:
            command("say Hmm.. this does not look like the belt made" +
                    " of snake skin, you silly goose!");
            break;

        case 2:
            command("say The belt is for me to wear at the" +
                    " next Midsummer's Eve festival.  I can't wait to" +
                    " see what Miss Prissy Poo has to say when she sees" +
                    " my outfit.  The snake is somewhere in this valley," +
                    " hiding in the grass.  Please can you find me the belt!");
            break;
        }
    }
    if (item == "hematite ring") {
        switch (x) {
        case 0:
            command("say Hidden in the creepy dark parts of the" +
                    " dark forest are a pack of dog.  Well, not dogs." +
                    "  More like jackals.  Jackalweres is what the " +
                    "druids call them.  If you bring me back one of " +
                    "their hematite rings, I shall reward you with" +
                    " anything I am wearing.");
            break;

        case 1:
            command("say Oh look! This is very nice, but it is " +
                    "not the hematite ring that I seek.");
            break;

        case 2:
            command("say The jackalweres have been threatening" +
                    " my friends the pixies and the brownies.  Please" +
                    " help us poor little fey folk by finding these " +
                    "jackalweres and making them stop.  I heard one of" +
                    " them even say that you looked fat and weak!  " +
                    "You don't like to be called names do you?");
            command("emote 's lips curl up to form a sassy grin.");
            break;
        }
    }
    if (x == 0) {
        command("say If you  need more %^CYAN%^information%^RESET%^ " +
                "just ask me.");
        command("say if you want to look at an item that I have " +
                "available for rewards you can %^CYAN%^showme item%^RESET%^ " +
                "and I'll show you the item.");
        return;
    }
}

void show_item(string str)
{
    object ob;
    if (!str) {
        return;
    }
    if (str) {
        if (TP->query_invis()) {
            command("say what?  Who goes there?");
            return 1;
        }

        TP->force_me("emoteat peasblossom catches $np attention and points at " +
                     "something.");

        if (!(ob = present(str, TO))) {
            command("shake");
            command("say I don't think I have that on me...");
            return 1;
        }
        command("emote smiles");
        command("say Yeah!  Here is what the " + str + " looks like.");
        command("show " + str + " to " + TPQN);
        if (ob->query_property("enchantment") < 0) {
            command("whisper " + TPQN + " the magic on that item is " +
                    "cursed and will only cause you harm.  It would be mean" +
                    " of me to give it to you!");
        }
        return 1;
    }
}

void choose_item(string str)
{
    object ob;
    if (!str) {
        return;
    }
    if (str) {
        TP->force_me("emoteat peasblossom walks up to $N and points at " +
                     "something.");

        if ((string)TPQN != helper) {
            command("emote flutters around and giggles.");
            command("say You have never helped me, I owe you no reward");
            return 1;
        }
        if (!(ob = present(str, TO))) {
            command("shake");
            command("say Take a closer look please, I don't seem to have that.");
            return 1;
        }
        if (ob->query_property("enchantment") < 0) {
            command("shake");
            command("say Oh no!  I can't give that away.");
            command("whisper " + helper + " the magic of this item is " +
                    "a curse and will harm you, that would be mean of me to give it to you.");
            return 1;
        }
        command("emote smiles and claps her hands together.");
        command("say Yeah!  You did a great job!  This is yours now.");
        if (ob->query_property("monsterweapon")) {
            ob->remove_property("monsterweapon");
        }
        command("give " + str + " to " + helper);
        command("say Thank you for helping me.");
        command("emote waves to you as she flies away.");
        remove_call_out("go_home");
        go_home(TO);
        return 1;
    }
}

void response(string msg, object ob)
{
    string* list, item;
    if (!objectp(ob)) {
        return;
    }
    list = SAVE_D->query_array(DSEEK);
    if (sizeof(list) < 1) {
        return;
    }
    if (sizeof(list) > 0) {
        item = list[0];
    }
    if (ob->query_invis() && !ob->query_true_invis()) {
        new("/cmds/spells/d/_dispel_magic")->use_spell(TO, 0, 35, 35, "cleric");
        return;
    }
    if ((strsrch(msg, "ello") != -1 || strsrch(msg, "reeting") != -1
         && already_helped != 1)) {
        do_help(TO);
        return;
    }

    if ((strsrch(msg, "adventure") != -1
         || strsrch(msg, "Adventure") != -1
         || strsrch(msg, "yes") != -1 || strsrch(msg, "Yes") != -1
         || strsrch(msg, "help") != -1 || strsrch(msg, "Help") != -1
         && already_helped != 1)) {
        command("emote smiles and claps her hands together.");
        command("speech speak quickly");
        convert_item_to_msg(item, 0);
        return;
    }
    if (strsrch(msg, item) != -1 || strsrch(msg, "info") != -1) {
        command("speech speak in a high pitch tone");
        //command("emote nods and takes a deep breath");
        convert_item_to_msg(item, 2);
        return;
    }
}

void go_home(object to)
{
    if (!objectp(to)) {
        return;
    }
    tell_room(environment(to), "Peasblossom leaves a trail of faerie" +
              " dust in her wake as she flies away.");
    to->move("/d/shadowgate/void");
    to->remove();
}

void receive_given_item(object ob)
{
    string item, * list, * nams;
    list = SAVE_D->query_array(DSEEK);
    nams = ob->query_id();
    if (sizeof(list) < 1) {
        command("give " + nams[0] + " to " + TPQN);
        command("say I don't need that.");
        if (already_helped != 1) {
            command("say AHHH! Code demon have possesed me! Hurry mail" +
                    " Cythera before it's to late!");
            return 1;
        }
    }
    item = list[0];
    if (ob->id(item)) {
        command("say WOW! You found it!");
        SAVE_D->remove_array(DSEEK);
        command("say You did a great job!  You can pick from" +
                " anything I have now as your reward.  Be quick though" +
                " please.  In five minutes a dryad is going to brush her hair.");
        command("say You can have me %^CYAN%^showme item%^RESET%^ and get a " +
                "look at what you want before you choose.  When you have made" +
                " your choice you can %^CYAN%^choose item%^RESET%^");
        command("emote tosses the " + ob->query_name() + " into her pouch.");
        ob->remove();
        helper = TPQN;
        already_helped = 1;
        call_out("go_home", 300, TO);
        return 1;
    }
    command("shake");
    convert_item_to_msg(item, 1);
    command("give " + nams[0] + " to " + TPQN);
    return 1;
}

void die(object ob)
{
    int x;
    object* inv;
    tell_room(ETO, "Glittering %^YELLOW%^faerie dust%^RESET%^ surrounds " +
              "peasblossom as she falls to the ground, dissolving most of what " +
              "she has!");
    inv = all_inventory(TO);
    for (x = 0; x < sizeof(inv); x++) {
        if (inv[x]->query_property("monsterweapon")) {
            if (!random(12)) {
                inv[x]->remove_property("monsterweapon");
                continue;
            }
        }
    }
    return ::die(ob);
}
