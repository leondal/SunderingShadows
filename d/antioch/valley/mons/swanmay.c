//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//level raised by Circe 2/19/05 to stop the problem of them not wearing
//the updated ranger tunic.

#include <std.h>
#include "/d/antioch/valley/valley.h"
inherit SM_WANDER;

int FLAG;

void create()
{
    ::create();
    set_name("swanmay");
    set_id(({ "swanmay", "monster", "swan may", "woman", "ranger", "human", "swan" }));
    set_short("A watchful ranger");
    set_long(
        "This beautiful woman appears to be a ranger. She is dressed" +
        " in green armor and has some hunting gear. The green off-sets" +
        " her lovely %^YELLOW%^golden%^RESET%^%^CYAN%^ hair and" +
        " %^BOLD%^%^BLUE%^deep blue%^RESET%^%^CYAN%^ eyes. She carries" +
        " two swords for defense and looks like she knows" +
        " how to wield them well. On her right hand she is wearing" +
        " an odd pewter ring. There is something about this woman" +
        " that is almost surreal, an aura of purity and wonder." +
        " Whoever or whatever the lady is, she is breath-taking."
        );
    set_gender("female");
    set_race("human");
    set_body_type("humanoid");
    set_hd(25, 6);
    set_max_level(25);
    set_size(2);
    set_alignment(7);
    set_overall_ac(-10);
    set_max_hp(random(50) + 200);
    set_hp(query_max_hp());
//   set_exp(13500);
    set_new_exp(25, "normal");
    set_level(30);
    set_class("ranger");
    set_mlevel("ranger", 25);
    set_stats("dexterity", 20);
    set_stats("charisma", 20);
    set_property("weapon resistance", 2);
    set_mob_magic_resistance("average");
    set_property("swarm", 1);
    set_property("full attacks", 1);
    set_property("alignment adjustment", -6);
    set_property("no dominate", 1);
    add_money("electrum", random(500));
    set_monster_feats(({ "ambidexterity", "two weapon fighting", "improved two weapon fighting", "unassailable parry" }));
    if (!present("leggings")) {
        if (!random(4)) {
            new(OBJ + "r_legs.c")->move(TO);
            command("wear leggings");
        }
    }
    if (!present("sword")) {
        if (!random(4)) {
            new(OBJ + "sunblade")->move(TO);
            command("wield sword");
        }else {
            new("/d/common/obj/weapon/longsword.c")->move(TO);
            command("wield sword");
        }
    }
    new("/d/common/obj/weapon/longsword.c")->move(TO);
    command("wield longsword");
    if (!present("armor")) {
        if (!random(8)) {
            new(OBJ + "r_tunic")->move(TO);
            command("wear armor");
        }else {
            new("/d/common/obj/armour/hide.c")->move(TO);
            command("wear armor");
        }
    }
    if (!present("crown")) {
        if (!random(6)) {
            new(OBJ + "leaf_crown")->move(TO);
            command("wear crown");
        }
    }
}

void init()
{
    object ob;
    ::init();
    if (ALIGN->is_evil(TP) && !TP->query_invis()) {
        kill_ob(TP, 1);
        return 1;
    }
}

void catch_say(string msg)
{
    call_out("reply_func", 1, msg, TP);
}

void reply_func(string msg, object who)
{
    if (!msg || !objectp(who)) {
        return;
    }
    if (base_name(who) == base_name(TO)) {
        return;
    }
    if ((strsrch(msg, "sunblade") != -1) && present("sunblade", TO)) {
        force_me("say Yes yes yes, take a look.");
        force_me("show sunblade to " + who->query_name());
        force_me("say I use the blade to protect the valley.");
        force_me("say I have heard of an evil plant. It sucks the minds "
                 "out of helpless victims and turns them into zombies.");
        force_me("say I have not yet found the evil creature. It must be "
                 "destroyed. It must be...");
        return;
    }
    if (strsrch(msg, "crown") != -1 && FLAG == 1) {
        if (!present("crown", TO)) {
            force_me("say I'm sorry, I do not have a crown right now. Choose something" +
                     " that I do have.");
            return;
        }else if (present("crown", TO)) {
            force_me("say Here is the reward you picked for vanquishing that evil!");
            force_me("give crown to " + TPQN);
            FLAG = 0;
            return;
        }
    }else if (strsrch(msg, "leggings") != -1 && FLAG == 1) {
        if (!present("leggings", TO)) {
            force_me("say I'm sorry, I do not have any leggings right now. Choose something" +
                     " that I do have.");
            return;
        }else if (present("leggings", TO)) {
            force_me("say Here is the reward you picked for vanquishing that evil!");
            force_me("give leggings to " + TPQN);
            FLAG = 0;
            return;
        }
    }else if (strsrch(msg, "tunic") != -1 && FLAG == 1) {
        if (!present("tunic", TO)) {
            force_me("say I'm sorry, I do not have a tunic right now. Choose something" +
                     " that I do have.");
            return;
        }else if (present("tunic", TO)) {
            force_me("say Here is the reward you picked for vanquishing that evil!");
            force_me("give tunic to " + TPQN);
            FLAG = 0;
            return;
        }
    }else if (strsrch(msg, "sunblade") != -1 && FLAG == 1) {
        if (!present("sunblade", TO)) {
            force_me("say I do not have a sunblade right now, and even if I did I would" +
                     " only give it to you if you had proved that you had killed the evil within" +
                     " the Dark Forest.");
            return;
        }else {
            force_me("say I told you, you may have anything BUT the sunblade. To earn" +
                     " that you must kill a greater evil. Now choose something else.");
            return;
        }
    }
    if (strsrch(msg, "crown") != -1 || strsrch(msg, "tunic") != -1 ||
        strsrch(msg, "leggings") != -1) {
        if (!present("crown", TO) && !present("tunic", TO) && !present("leggings", TO)) {
            return;
        }else {
            force_me("say Seems you are interested in it.");
            force_me("ponder");
            force_me("say There is a vicious snake hiding somewhere in the valley. "
                     "It is a threat to the valley residents. If you can destroy it and "
                     "bring me its tear drop, I will consider giving something to you.");
            force_me("smile " + TPQN);
            return;
        }
    }
    if (strsrch(msg, "hello") != -1 || strsrch(msg, "hi") != -1 || strsrch(msg, "greeting") != -1) {
        force_me("say Greetings");
        return;
    }
    switch (random(3)) {
    case 0:
        force_me("say Are you in need of something?");
        break;

    case 1:
        force_me("say Beware of the Dark Forest, it is a dangerous place.");
        break;

    case 2:
        force_me("say There are hidden dangers in the valley. Be on guard.");
        break;

    default:
        force_me("smile");
    }
    return;
}

void receive_given_item(object obj)
{
    if (!objectp(obj)) {
        return;
    }
    if ((string)obj->query_name() == "%^MAGENTA%^orchid%^RESET%^") {
        force_me("smile " + TPQN);
        force_me("say Thank you for destroying that evil creature for me. "
                 "I am in debt to you.");
        force_me("emote throws the orchid on the floor and smashes it "
                 "with her feet.");
        obj->remove();
        if (present("sunblade", TO)) {
            force_me("give sunblade to " + TPQN);
        }else if (present("crown", TO)) {
            force_me("give crown to " + TPQN);
        }else if (present("leggings", TO)) {
            force_me("give leggings to " + TPQN);
        }else if (present("tunic", TO)) {
            force_me("give tunic to " + TPQN);
        }else if (present("hide", TO)) {
            force_me("give hide to " + TPQN);
        }else if (present("sword", TO)) {
            force_me("give sword to " + TPQN);
        }else {
            force_me("give " + query_money("electrum") + " electrum coins to " + TPQN);
        }
        force_me("say Please take it. I don't have much to give.");
        return;
    }
    if ((string)obj->query_name() == "%^GREEN%^green teardrop%^RESET%^") {
        force_me("smile " + TPQN);
        force_me("say You did well!");
        force_me("emote throws the tear drop on the ground, shattering it.");
        obj->remove();
        force_me("say You may pick anything of value that I have, except the sunblade." +
                 " For that you must kill a greater evil.");
        FLAG = 1;
        call_out("reset_give_out", 30);
        return;
    }
    return;
}

void reset_give_out()
{
    FLAG = 0;
}
