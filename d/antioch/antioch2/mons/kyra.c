#include <std.h>
#include <security.h>
#include "../antioch.h"
#include <daemons.h>
inherit MONSTER;

void do_greeting();
void do_departing();
int GREETING, DEPARTING, SUMMON;

void create()
{
    int mylevel = 65;
    ::create();
    SUMMON = 0;
    set_name("Cerviel");
    set_id(({ "paladin", "guard", "paladin guard", "pguard", "Paladin", "guardian", "gate guard", "knight", "cerviel", "captain", "cerviel", }));
    set_short("%^BOLD%^%^WHITE%^Cerviel, %^ORANGE%^a divine knight of %^WHITE%^Jarmila%^RESET%^");
    set_long(
        "%^BOLD%^%^WHITE%^This is Cerviel, captain deva of the Guard and a strong paladin of Jarmila. She is just shy of six feet tall and is very fit. She's taken her helmet off and long blonde hair is kept in a braid to keep it out of her face. Blue eyes twinkle with happiness and a smile seems to be permanent on her lips. Her plate armor is spotless and practically glows in the light. Two sets of huge feathery wings trail behind her back."
        );
    set_race("deva");
    set_gender("female");
    set_body_type("human");
    set_overall_ac(-70);
    set_alignment(1);

    set("aggressive", 2);
    set_property("swarm", 0);

    set_level(mylevel);
    set_class("paladin");
    set_mlevel("paladin", mylevel);
    set_mlevel("cleric", mylevel);

    set_property("no hold", 1);
    set_property("no death", 1);

    set_max_hp(18 * mylevel + 6000);
    set_hp(query_max_hp());
    set_property("spell damage resistance", 60);
    set_mob_magic_resistance("high"); //you aren't meant to be able to easily kill her
    set_property("damage resistance", 10);

    set_new_exp(mylevel, "boss");

    set("aggressive", 0);
    set_stats("strength", 22);
    set_stats("wisdom", 22);
    set_stats("intelligence", 12);
    set_stats("constitution", 22);
    set_stats("charisma", 26);
    set_stats("dexterity", 18);
    set_diety("jarmila");

    set("speech string", "%^BOLD%^%^ORANGE%^intone");
    set("describe string", "%^BOLD%^%^WHITE%^powerfully");

    new("/d/magic/symbols/jarmila_symbol.c")->move(TO);
    force_me("wear symbol");

    set_thief_skill("perception", 55);

    {
        object obj;
        int ench = 7;

        obj = new("/d/magic/obj/shields/jarmila");
        obj->set_property("enchantment", ench);
        obj->move(TO);
        obj->set_property("monster weapon", 1);
        force_me("wear shield");

        obj = new("/d/magic/obj/weapons/jarmila");
        obj->set_property("enchantment", ench);
        obj->move(TO);
        obj->set_property("monster weapon", 1);
        force_me("wield weapon");
    }

    set_monster_feats(({
        "reflection",
        "counter",
        "deflection",
        "parry",
        "shieldbash",
        "shieldwall",
        "rush",
        "smite",
    }));

    set_spells(({ "sunbeam",
                  "holy smite",
                  "sunburst", }));

    set_spell_chance(33);

    set_funcs(({ "rushit", "bashit", "smiteit" }));
    set_func_chance(33);

    set_property("cast and attack", 1);
    set_property("function and attack", 1);
}

void rushit(object targ)
{
    TO->force_me("rush " + targ->query_name());
}

void smiteit(object targ)
{
    TO->force_me("smite");
}

void bashit(object targ)
{
    TO->force_me("shieldbash " + targ->query_name());
}

//echo on helm line, answer questions, do call_out for ghosting & revenge

int query_watched()
{
    return 100;
}

void init()
{
    ::init();
    if (!interactive(TP)) {
        return;
    }
    if ((mixed*)TO->query_attackers() != ({ })) {
        return;
    }else if (GREETING == 1) {
        call_out("do_greeting", 1, TP);
        return;
    }else if (DEPARTING == 1) {
        call_out("do_departing", 1, TP);
        return;
    }
}

void speak(string msg)
{
    force_me("say %^BOLD%^%^WHITE%^" + msg + "%^RESET%^");
}

void do_greeting()
{
    string race; // added by *Styx* to avoid doing query_race() so many times 12/25/05
    object shape;
    if (member_array(TP->query_name(), KILLING_D->query_bounties()) != -1) {
        speak(" We do not allow law breakers into this town. Leave here" +
              " at once, before I summon the guards!");
        return 1;
    }
    if (ALIGN->is_evil(TP)) {
        if (!TP->query_invis()) {
            tell_room(ETO, "Cerviel turns towards " + TP->query_cap_name() + ".", TP);
            tell_object(TP, "Cerviel turns towards you.");
            speak(" Evil is not welcome here, I would suggest you turn around" +
                  " and think of a more suitable destination.");
            return 1;
        }else {
            tell_room(ETO, "Cerviel shifts and looks around uneasily.");
            speak(" I can feel the presence of evil, everyone" +
                  " be on guard.");
            return 1;
        }
        return 1;
    }

    if (TP->query_invis()) {
        return;
    }
    if ((string)TP->query_diety() == "jarmila") {
        if (TP->is_class("paladin") || TP->is_class("cavalier")) {
            tell_object(TP, "Cerviel smiles warmly at you.");
            tell_room(ETO, "Cerviel smiles warmly at " + TP->query_cap_name() + ".", TP);
            speak(" It is good to see a fellow Knight of Jarmila." +
                  " I hope that your journey wasn't too hard.");
            if (TP->query_level() < 6) {
                speak(" Many new adventures await you still," +
                      " but if you ever grow tired of them, I'm sure I" +
                      " can find you a place here in the guard.");
                return 1;
            }
            if (TP->query_level() < 16) {
                speak(" With a little bit of training, you'd" +
                      " make a fine guard here.");
                return 1;
            }else {
                speak(" I can tell you're a seasoned veteran." +
                      " If ever you want to quit your adventures, I'd be" +
                      " more than happy to have you in the guards.");
                return 1;
            }
        }
        if (TP->is_class("cleric")) {
            tell_object(TP, "Cerviel looks you over and smiles.");
            tell_room(ETO, "Cerviel looks at " + TP->query_cap_name() + "" +
                      " and smiles.", TP);
            speak(" A cleric of Jarmila, this is an honor." +
                  " There is a church inside, newly built and" +
                  " I'm sure Brother Sebastian would love to chat with" +
                  " a fellow clergyman. You should pay him a visit, it's" +
                  " on the northeastern side of the city.");
            return 1;
        }
        if (TP->is_class("mage")) {
            speak(" With Ignatius back to his old self," +
                  " there have been many mages coming to Antioch to" +
                  " study magic again. Be sure to pay a visit to" +
                  " Orflack, he's in the palace.");
            return 1;
        }else {
            if ((string)TP->query_gender() == "male") {
                speak(" May Jarmila's's blessing be on you, and I hope" +
                      " you enjoy your stay, good brother.");
                return 1;
            }else {
                speak(" May Jarmila's blessing be on you, and I hope" +
                      " you enjoy your stay here, sister.");
                return 1;
            }
        }
        return 1;
    }
    race = TP->query_race();
    if (objectp(shape = TP->query_property("shapeshifted"))) {
        race = (string)shape->query_shape_race();
    }

    if (race == "drow" || race == "ogre" || race == "half-ogre" || race == "goblin" || race == "orc" || race == "half-orc" || race == "hobgoblin" || race == "ogre-mage" || race == "gnoll" || race == "half-drow" || race == "kobold" || race == "bugbear" || race == "minotaur" || race == "yuan-ti" || race == "shade") {
        speak(" The citizens aren't too fond of " + TP->query_race() + "s wandering" +
              " through their city. I'd find someplace else to go, you'll get no welcome here.");
        return 1;
    }
    if (race == "dragon") {
        force_me("emote pales, but holds her ground.");
        speak(" You cannot enter, beast. The power of Jarmila will protect us!");
        return 1;
    }
    if (race == "elf" && (string)TP->query("subrace") == "fey'ri" && !TP->query_property("altered")) {
        speak(" The citizens aren't too fond of fey'ri wandering" +
              " through their city. I'd find someplace else to go, you'll get no welcome here.");
        return 1;
    }
    if (TP->is_class("paladin")) {
        tell_object(TP, "Cerviel smiles at you.");
        tell_room(ETO, "Cerviel smiles at " + TP->query_cap_name() + ".", TP);
        speak(" Paladins are always welcome in this city," +
              " it is a rough profession and I hope your visit here is" +
              " relaxing.");
        return 1;
    }
    if (TP->is_class("mage")) {
        tell_object(TP, "Cerviel looks you over and nods.");
        tell_room(ETO, "Cerviel looks over " + TP->query_cap_name() + "" +
                  " and nods.", TP);
        speak(" You're a mage, right?");
        speak(" We get so many of them now with Ignatius restored, the component" +
              " shops are really doing well. I hope you find everything you need here.");
        return 1;
    }
    if (TP->is_class("cavalier")) {
        if (present("horse")) {
            speak(" Knights are always welcome here. Please" +
                  " stable your horse before making a visit to the" +
                  " palace, though.");
            speak(" We have had a few who tried to march" +
                  " their horses right in!");
            force_me("emote laughs merrily.");
            return 1;
        }else {
            speak(" A Knight! But I see you don't have a" +
                  " mount.");
            speak(" I know the trip up here can be a little tough" +
                  " on hooves. There's a good stable on the western side" +
                  " if you'd like to purchase a new mount.");
            return 1;
        }
    }else {
        speak(" Welcome to the new city of Antioch! We're" +
              " slowly expanding back to our old size, I hope that" +
              " you find everything satisfactory.");
        speak(" I'll be happy to answer any questions you may have, and the" +
              " inn is on the north side of the city.");
        return 1;
    }
    return;
}

void do_departing()
{
    if (ALIGN->is_evil(TP)) {
        tell_object(TP, "Cerviel eyes you suspiciously.");
        tell_room(ETO, "Cerviel eyes " + TPQCN + " suspiciously.", TP);
        speak(" How did you get into the city?");
        return;
    }else if (member_array(TP->query_name(), KILLING_D->query_bounties()) != -1) {
        speak(" I don't know how you slipped passed me, but you'd best be on your" +
              " way " + TPQCN + ".");
        return;
    }else {
        speak(" I hope you had a pleasant stay.");
        force_me("smile");
        return;
    }
}

void catch_say(string message)
{
    if ((mixed*)TO->query_attackers() != ({ })) {
        speak(" Give me a hand here!");
        return 1;
    }else if (strsrch(message, "jarmila") != -1) {
        call_out("praise_jarmila", 1, TP);
        return 1;
    }else if (strsrch(message, "ruins") != -1) {
        call_out("do_warning", 1, TP);
        return 1;
    }else if (strsrch(message, "ignatius") != -1) {
        call_out("do_history", 1, TP);
        return 1;
    }
}

int praise_jarmila()
{
    speak(" Jarmila is the ultimate Guardian of Antioch. Only through Her example can we" +
          " hope to succeed in our tasks.");
    if ((string)TP->query_diety() == "jarmila") {
        force_me("smile " + TPQN + "");
        speak(" The path we both travel is long and hard, but rewarding in and of itself.");
        return 1;
    }
    speak(" Perhaps some day you will see the truth in this.");
    return 1;
}

int do_warning()
{
    speak(" The ruins of Antioch are still a deadly place!");
    speak(" Although the center of that evil has been destroyed," +
          " remnants of it still remain.");
    speak(" Many adventurers have disappeared when they ventured in there" +
          " despite the warnings.");
    speak(" Especially at night, I can feel the evil awaken then.");
    speak(" Yet there is still some great evil that sleeps there, waiting" +
          " for some young fool to release it.");
    force_me("emote shivers and makes the sign of Jarmila.");
    return 1;
}

int do_history()
{
    speak(" Ah yes, Ignatius. He was once the ruler of Antioch, kind and gentle," +
          " until he was taken over by a greater evil god who turned the citizens of" +
          " Antioch into mindless slaves of his will.");
    speak(" But a group of brave adventurers were able to summon divine aid to help "
          "them free the city. They fought the dark god that sought" +
          " to gain foothold in this realm, finally defeating him.");
    speak(" Those who believed in Jarmila's protection became healed and were" +
          " free. The rest of the city was destroyed in the fight between the gods, and" +
          " are the ruins that you probably noticed to the east.");
    speak(" The ruins are still plagued with evil creatures, which is why" +
          " we must always be on our guard. I would not go to the ruins if I were you.");
    speak(" The citizens built this new city of Antioch with the help of" +
          " Ignatius. There is a large and impressive church dedicated to Jarmila on the" +
          " eastern side.");
    return 1;
}

void heart_beat()
{
    object* user;
    int i, j;

    ::heart_beat();
    
    if(!this_object())
        return;
    
    if ((mixed*)TO->query_attackers() != ({ }) && SUMMON != 1) {
        force_me("yell Help! There are attackers at the gates!");
        SUMMON = 1;
    }
    if (sizeof(TO->query_attackers())) {
        if (!TO->query_property("angelic_aspect")) {
            new("/cmds/spells/g/_greater_angelic_aspect")->use_spell(TO, TO, 70, 100);
        }

        if (TO->query_hp() < TO->query_max_hp() / 2) {
            if (!random(8)) {
                new("/cmds/spells/h/_heal")->use_spell(TO, TO, 30, 100);
            }
        }
    }
}

void die(object obj)
{
    start_event();
    return ::die(obj);
}

void set_direction(string str)
{
    if (str == "west") {
        GREETING = 1;
        DEPARTING = 0;
        return;
    }
    if (str == "east") {
        DEPARTING = 1;
        GREETING = 0;
        return;
    }
}

void bounty_collection(object targ)
{
    if ((mixed*)TO->query_attackers() != ({ })) {
        return;
    }
    if (member_array(TP->query_name(), KILLING_D->query_bounties()) != -1) {
        speak(" Very well, " + TPQCN + ", since you will not leave I shall summon" +
              " the guards to collect that law bounty.");
        force_me("emote sends a signal to the watchtower.");
        force_me("kill " + TP->query_name() + "");
        return 1;
    }
    if (member_array(TP->query_name(), KILLING_D->query_evil_bounties()) != -1) {
        speak(" Very well, " + TPQCN + ", since you will not leave I shall summon" +
              " the guards to collect that bounty.");
        force_me("emote sends a signal to the watchtower.");
        force_me("kill " + TP->query_name() + "");
        return 1;
    }
}

start_event()
{
    int power;//%
    power = 10 + random(5);
    WORLD_EVENTS_D->kill_event("Slain Divine Knight");
    WORLD_EVENTS_D->inject_event((["Slain Divine Knight" : (["start message" : "%^WHITE%^%^BOLD%^Wide beam of light descends upon Antioch from the heavens, an angelic figure seen ascending in it.%^RESET%^

%^RESET%^%^BOLD%^Unwavering voice echoes across the world: %^ORANGE%^May She forgive you, %^WHITE%^for I will not.%^RESET%^",
                                                             "event type" : "exp bonus", "length" : 120, "notification" : power + "% Bonus Exp",
                                                             "event name" : "Slain Divine Knight", "modifier" : power, "announce" : 1, "announce to" : "world" ]), ])
                                 );
}
