/**
 * @file
 * @brief Church parent object
 */

// Added pre_exit_functions to keep ghosts from leaving - Styx 4/20/02
// lowering cost of removing curses & removing damage for needing a new symbol per discussions *Styx* 12/26/05
// expanded domain selection to support a third clerical domain for those with the feat. N, 3/13.
#include <std.h>
#include <spell_domains.h>
#include <daemons.h>
// temp items can be revoked once choose is out of this file!! N, 1/18
#include <dieties.h>
#define DIETY_D "/daemon/diety_d.c"
#define FORSAKE_DELAY 86400
#include <dieties.h>
// down to here, 3x variables can be removed
#define FUNDS "/daemon/templefunds_d.c"
#include <new_exp_table.h>
inherit ROOM;


void initialize_ob(string pcname, object myob);
void init()
{
    ::init();
    add_action("pray", "pray");
    add_action("return_me", "return");
    add_action("plea", "request");
    add_action("return_item", "recover");
    add_action("remove_curse", "revoke");
    add_action("identify_curse", "identify");
    add_action("__Read_me", "read");
    add_action("select_domain", "pick");
    add_action("clear_domains", "forget");
    add_action("select_diety", "choose");
}

void create()
{
    ::create();
    set_property("no castle", 1);
    set_property("church", 1);
    set_property("training", 1);
    set_items((["sign" : "You should read it."]));
    set_pre_exit_functions(
        ({ "north", "south", "east", "west", "out", "northeast", "northwest", "southeast", "southwest" }),
        ({ "no_ghosts", "no_ghosts", "no_ghosts", "no_ghosts", "no_ghosts", "no_ghosts", "no_ghosts", "no_ghosts", "no_ghosts", })
        );
}

int can_request()
{
    return 1;
}

int no_ghosts()
{
    if (!TP->query_ghost()) {
        return 1;
    }
    tell_object(TP, "Ghosts may not leave the church.  You must pray to get "
                "a new body first.");
    return 0;
}

int remove_curse(string str)
{
    string item;
    object ob;
    int amount, num1, donation;

    if (!str) {
        return 0;
    }
    if (sscanf(str, "curse from %s", item) != 1) {
        return 0;
    }
    if (!ob = present(item, TP)) {
        tell_object(TP, "You do not have any " + item + ".");
        return 1;
    }else {
        if (!TP->query_funds("gold", 500)) {
            tell_object(TP, "You need 500 gold for us to check if the " + item + " is cursed.");
            return 1;
        }
        if (ob->query_property("no remove curse")) {
            tell_object(TP, "The curse on that is too powerful for me to remove!");
            return 1;
        }
        if (!ob->query_property("enchantment") || ob->query_property("enchantment") >= 0) {
            TP->use_funds("gold", 500);
            tell_object(TP, "The " + item + " is not cursed.");
            return 1;
        }
        if (ob->query_property("no remove")) {
            return notify_fail("That curse I can't remove.\n");
        }
//      amount = (int)TP->query_lowest_level()*3000;
// making it lower so it's not so impossible on new players who are the ones who usually end up with the problem *Styx* 12/26/05
        amount = (int)TP->query_highest_level() * 1000;
        if (!TP->query_funds("gold", amount)) {
            tell_object(TP, "You will need " + amount + " gold to have one level of the curse lifted.");
            return 1;
        }else {
            TP->use_funds("gold", amount);
            num1 = ob->query_property("enchantment");
            num1++;
            while (ob->query_property("enchantment") < num1) {
                ob->set_property("enchantment", 1);
            }
            tell_object(TP, "%^BOLD%^An acolyte accepts your sizeable donation "
                        "and then a priest chants a spell over the cursed item.");
            tell_room(TO, "%^BOLD%^An acolyte accepts a sizeable donation from "
                      + TPQCN + " and then a priest chants a spell over the cursed item.", TP);
        }
    }
    return 1;
}

int identify_curse(string str)
{
    string item;
    object ob;

    if (!str) {
        return 0;
    }
    if (sscanf(str, "curse on %s", item) != 1) {
        return 0;
    }
    if (!TP->query_funds("gold", 500)) {
        return notify_fail("You need 500 gold to pay for the identification of a cursed item.\n");
    }
    if (!ob = present(item, TP)) {
        return notify_fail("You do not have any " + item + ".\n");
    }
    if (!TP->query_funds("gold", 500)) {
        return notify_fail("You need 500 gold to pay for the identification of a cursed item.\n");
    } else {
        TP->use_funds("gold", 500);
        if (!ob->query_property("enchantment") || ob->query_property("enchantment") >= 0) {
            tell_object(TP, "%^BOLD%^%^BLUE%^The " + item + " is not cursed!");
        } else {
            tell_object(TP, "%^BOLD%^%^RED%^The " + item + " is cursed!");
        }
    }
    return 1;
}

int pray()
{
    string* classes;
    object* stuff;

    if (!this_player()->query_ghost()) {
        notify_fail("The living do not need to pray for revival.\n");
        return 0;
    }
    TP->revive(-10);

    //Setting flags
    if (query_verb() == "pray" || TP->query("just_been_pkilled")) {
        TP->advance_death_time();
    }

    TP->delete("just_been_pkilled");
    TP->remove_property("last_death");
    TP->set_property("last_death", time());

    //Resetting status
    TP->set_hp(10);
    TP->set_blind(0);

    if (TP->query_quenched() < (int)TP->query_formula() / 6) {
        TP->add_quenched((int)TP->query_formula() / 6);
    }
    if (TP->query_stuffed() < (int)TP->query_formula() / 6) {
        TP->add_stuffed((int)TP->query_formula() / 6);
    }

    TP->set_heart_beat(1);
    TP->set_heal_rate(2);
    TP->add_stuffed(25);
    TP->add_quenched(25);

    if (TP->is_class("cleric") ||
        TP->is_class("ranger") ||
        TP->is_class("paladin")) {
        write("As a service to your faith, we will provide this new holy symbol.");
        new("/d/magic/symbols/holy_symbol")->move(TP);
    }

    TP->delete("RaisingRoom");
    TP->delete("RaisingPriestAlignment");
    TP->delete("RaisingPriestGod");
    TP->delete("RaisingExpLoss");
    TP->delete("RaisingType");

    stuff = all_inventory(TP);
    filter_array(stuff, (:$1->is_disease():))->remove();

    /* Punishment for non-newbies. */
    if (!newbiep(TP) &&
        ((int)TP->query_base_character_level() > 6)) {

        int exploss, expdelta, exp, thelevel;
        int i;
        string myclass;
        int charlvl;

        USER_D->scale_level_to(TP, TP->query_adjusted_character_level());
        /* Subtracting exp to next level  */
        thelevel = TP->query_adjusted_character_level();

        if (TP->query("active_class")) {
            myclass = TP->query("active_class");
        } else {
            myclass = TP->query_class();
        }

        classes = TP->query_classes();

        exp = (int)TP->query_exp();

        expdelta = exp_for_level(thelevel);

        // Weak punishment for low levels, but starting from L40 it will always take a level.
        exploss = expdelta * (7 * thelevel * thelevel - 30 * thelevel + 2000) / 12000;
        log_file("player/exp_loss", TPQN + " lost " + exploss + " in resurrection at a church.\n");

        if (TP->query("hardcore")) {
            if (sizeof(classes) > 1) {
                for (i = 1; i < sizeof(classes); i++) {
                    TP->set_guild_level(classes[i], 0);
                    TP->set_mlevel(classes[i], 0);
                    TP->remove_class(classes[i]);
                }
            }
            TP->set_posed(classes[0]);
            TP->set("active_class", classes[0]);
            TP->force_me("fixspells");
            TP->set("hp_array", 0);
            TP->make_new_hitpoint_rolls(TP);
            TP->InitInnate();
            TP->clear_feats();
            TP->delete("free_feat_wipe");
            TP->set_general_exp(myclass, total_exp_for_level(6));
        } else {
            if (exp - exploss <= total_exp_for_level(6)) {
                exploss = exp - total_exp_for_level(6);
            }
            TP->set_general_exp(myclass, exp - exploss);
        }

        TP->resetLevelForExp(0);

        /* Adding death tax */

        //TP->set_XP_tax(0, 0, "death");

        /* Damaging enchanted inventory. */
        stuff = all_inventory(TP);
        for (i = 0; i < sizeof(stuff); i++) {
            if (!objectp(stuff[i])) {
                continue;
            }
            if (!stuff[i]) {
                continue;
            }
            if (TP->query("hardcore")) {
                stuff[i]->remove();
                continue;
            }
            if (stuff[i]->is_armor() && stuff[i]->query_worn()) {
                stuff[i]->set_not_equipped();
            }
            if (stuff[i]->query_wielded()) {
                stuff[i]->set_not_inhand();
            }
            if (objectp(stuff[i])) {
                if (stuff[i]->id("questob")) {
                    stuff[i]->remove();
                    continue;
                }
                if (stuff[i]->query_property("enchantment") > 0) {
                    stuff[i]->set_overallStatus((int)stuff[i]->query_overallStatus() * 1 / 4);
                    continue;
                }
            }
        }
    }

    return 1;
}

int return_me()
{
    if (!this_player()->query_ghost()) {
        notify_fail("You can only return if you are dead!");
        return 0;
    }

    if (TP->query("just_been_pkilled")) {
        return notify_fail("You can only return if your most recent death was a normal death!");
    }

    TP->set_death_age(0);
    pray();
    return 1;
}

int plea()
{
    if (present("true holy symbol", TP)) {
        return notify_fail("You need not another symbol!! Return thee to thine life!\n");
    }
    if (!TP->query_diety() || (string)TP->query_diety() == "pan") {
        return notify_fail("You need to follow a deity before you need a holy symbol!\n");
    }
    if (!can_request()) {
        return notify_fail("You cannot retrieve a holy symbol here.\n");
    }
    if (!TP->query_funds("gold", 500)) {
        return notify_fail("You need 500 gold to pay for a new symbol.\n");
    }
    TP->use_funds("gold", 500);
    new("/d/magic/symbols/holy_symbol")->move(TP);
    write("An acolyte accepts your offering and brings you the new symbol.");
    tell_room(TO, "An acolyte accepts " + TPQCN + "'s offering and delivers a new symbol.", TP);
    return 1;
}

string query_long(string str)
{
    string hold;

    hold = room::query_long(str);
    if (!str || str == "") {
        hold += "\nThere is a sign here listing what can be done, please read it.\n";
    }
    return hold;
}

int __Read_me(string str)
{
    if (!str || str != "sign") {
        return 0;
    }
    write("%^CYAN%^You can ask divines to return you to the true life here:%^RESET%^

  %^ORANGE%^<pray>%^RESET%^                    Return to life, with %^BOLD%^%^RED%^Gr%^RESET%^ace time protection from player kill
  %^ORANGE%^<return>%^RESET%^                  Return to life, without the %^BOLD%^%^RED%^Gr%^RESET%^ flag

%^MAGENTA%^The church performs the following tasks, most for a fee of course:%^RESET%^

  %^ORANGE%^<request symbol>%^RESET%^          Get a new holy symbol
  %^ORANGE%^<new symbol>%^RESET%^              Receive a fancy holy symbol, if your temple has one
  %^ORANGE%^<recover>%^RESET%^                 Return your wedding ring
  %^ORANGE%^<identify curse on %^ORANGE%^%^ULINE%^ITEM%^RESET%^%^ORANGE%^>%^RESET%^  Will tell you if an item is cursed
  %^ORANGE%^<revoke curse from %^ORANGE%^%^ULINE%^ITEM%^RESET%^%^ORANGE%^>%^RESET%^  Will remove curses from an item, one level at a time


  %^ORANGE%^<choose %^ORANGE%^%^ULINE%^DEITY%^RESET%^%^ORANGE%^>%^RESET%^         Select a new god
  %^ORANGE%^<forsake>%^RESET%^              Forsake the deity of this temple

  %^ORANGE%^<pick domain %^ORANGE%^%^ULINE%^DOMAIN%^RESET%^%^ORANGE%^>%^RESET%^   Choose a domain
  %^ORANGE%^<forget domains>%^RESET%^       Forget all current domains

  %^ORANGE%^<pick way %^ORANGE%^%^ULINE%^WAY%^RESET%^%^ORANGE%^>%^RESET%^         Dedicate to that emphasis of Ki. E.g. <pick way of the fist>.

Temples also have donation boxes. You will probably want to %^ORANGE%^<donate>%^RESET%^ coins or items to various deities. You can also %^ORANGE%^<look donation box>%^RESET%^ in temples even if there isn't one explicitly in the description.");
    return 1;
}

int return_item(string str)
{
    object ob;
    int money;

    if (present("wedding ring", TP)) {
        return notify_fail("You already have a wedding ring, don't be asking for another!\n");
    }
    if (!TP->query_married()) {
        return notify_fail("You have no spouse, get married first then you may have a ring!\n");
    }
    money = (int)TP->query_lowest_level() * 50;
    if (!TP->query_funds("gold", money)) {
        return notify_fail("You need " + money + " gold to pay us not to tell your spouse!\n");
    }
    TP->use_funds("gold", money);
    seteuid(getuid());
    ob = new("/std/obj/wed_ring");
    ob->set_spouse(TP->query_married());
    ob->set_me(TPQN);
    ob->move(TP);
    tell_room(ETP, "%^BOLD%^%^BLUE%^Another wedding ring has been successfully returned!");
    return 1;
}

int clear_domains(string str)
{
    if (!stringp(str)) {
        return 0;
    }

    if (str != "domains") {
        return 0;
    }

    if (TP->query("domains_cleared") + 60 * 60 * 24 * 7 * 3 > time()) {
        tell_object(TP, "%^BOLD%^%^RED%^You can clear your domains only once per three weeks.");
        return 1;
    }

    TP->set_divine_domain(({}));
    TP->delete("domains_cleared");
    TP->set("domains_cleared", time());
    TP->InitInnate();
    tell_object(TP, "%^BOLD%^%^WHITE%^You sense you have forgotten your domains and can select new ones.");
    return 1;
}

int is_alignment_domain(string domain)
{
    string * align_domains = ({"law", "chaos", "good", "evil"});

    if (member_array(domain, align_domains) != -1) {
        return 1;
    }

    return 0;
}

int select_domain(string str)
{
    string* possible_domains, * player_domains, * info, player_deity, temple_deity, selection, which;
    int num_classes;

    if (!stringp(str)) {
        return 0;
    }
    info = explode(str, " ");
    if (sizeof(info) < 2) {
        return 0;
    }                                  // To prevent those annoying illegal index errors
    if (lower_case(info[0]) != "domain" && lower_case(info[0]) != "way") {
        return 0;
    }
    which = lower_case(info[0]);
    switch (which) {
    case "way":
        if (!TP->is_class("monk")) {
            tell_object(TP, "You must be a monk to pick a specialized way.");
            return 1;
        }
        if ((int)TP->query_class_level("monk") < 3) {
            tell_object(TP, "You must be at least level 3 in your monk class before you can pick " +
                        "a specialized way.");
            return 1;
        }
        if (str != "way of the fist" && str != "way of the elements" && str != "way of the shadow") {
            tell_object(TP, "A monk can only pick %^YELLOW%^way of the fists%^RESET%^, " +
                        "%^YELLOW%^way of the elements%^RESET%^, or %^YELLOW%^way of the shadow" +
                        "%^RESET%^!");
            return 1;
        }
        if (stringp(TP->query("monk way"))) {
            tell_object(TP, "You have already chosen to specialize in the " +
                        "%^YELLOW%^" + (string)TP->query("monk way") + "%^RESET%^!");
            return 1;
        }
        player_deity = (string)TP->query_diety();
        temple_deity = (string)TO->query_diety();
        if (!temple_deity) {
            temple_deity = "pan";
        }
        if (TO->query_property("conversion room")) {
            temple_deity = player_deity;
        }
        player_domains = TP->query_divine_domain();
        possible_domains = SPELL_DOMAINS[lower_case(player_deity)];
        num_classes = sizeof(TP->query_classes());
        tell_object(TP, "%^BOLD%^%^WHITE%^You have chosen to specialize in the " +
                    "%^YELLOW%^" + str + "%^BOLD%^%^WHITE%^!%^RESET%^");
        TP->set("monk way", str);
        USER_D->init_ki(TP);
        return 1;
        break;
    case "domain":
        if (sizeof(info) > 2) {
            tell_object(TP, "Syntax: <pick domain> <domain>   Please pick only one domain at a time.");
            return 1;
        }

        selection = lower_case(info[1]);
        player_deity = (string)TP->query_diety();
        temple_deity = (string)TO->query_diety();
        if (TO->query_property("conversion room")) {
            temple_deity = player_deity;
        }
        player_domains = TP->query_divine_domain();

        possible_domains = ({});

        if (TP->is_class("cleric")) {
            possible_domains += SPELL_DOMAINS[lower_case(player_deity)];
        }

        if (TP->is_class("druid")) {
            possible_domains += ({ "air", "animal", "earth", "fire", "plant", "cold", "sun" });
        }

        possible_domains = distinct_array(possible_domains);
        num_classes = sizeof(TP->query_classes());

        if (member_array(selection, possible_domains) == -1) {
            tell_object(TP, "You can't select the " + selection + " domain. Select "
                        "from the following domains: " + implode(possible_domains, " ") + "");
            return 1;
        }

        if (is_alignment_domain(selection)) {
            string tmpdom;

            foreach(tmpdom in player_domains)
            {
                if (is_alignment_domain(tmpdom)) {
                    tell_object(TP, "You can not select more than one alignment domain, as you already have " + tmpdom + " domain. Choose something else.");
                    return 1;
                }
            }
        }

        if (FEATS_D->usable_feat(TP, "divine domain")) {
            if (!sizeof(player_domains)) {
                TP->set_divine_domain(({ selection }));
                tell_object(TP, "You have choosen to select the " + selection + " domain.\n");
                TP->set("domains_changed", 1);
                return 1;
            }
            if (sizeof(player_domains) < 2) {
                if (!FEATS_D->usable_feat(TP, "second divine domain")) {
                    tell_object(TP, "You haven't yet gained enough ability to harness the spells of two domains.\n");
                    return 1;
                }
                if (player_domains[0] == selection) {
                    tell_object(TP, "You already have the " + selection + " domain, please choose a different "
                                "one.  You may choose from the following domains: " + implode(SPELL_DOMAINS[player_deity], " ") + "");
                    return 1;
                }
                TP->set_divine_domain(({ player_domains[0], selection }));
                tell_object(TP, "You have chosen to select the " + selection + " domain.");
                tell_object(TP, "Your now have the following domains: " + player_domains[0] + " and " + selection + "\n");
                return 1;
            }
            if (sizeof(player_domains) < 3) {
                if (!FEATS_D->usable_feat(TP, "third divine domain")) {
                    tell_object(TP, "Only the most advanced and favored clerics can gain a third domain.\n");
                    return 1;
                }
                if (member_array(selection, player_domains) != -1) {
                    tell_object(TP, "You already have the " + selection + " domain, please choose a different "
                                "one.  You may choose from the following domains: " + implode(SPELL_DOMAINS[player_deity], " ") + "");
                    return 1;
                }
                TP->set_divine_domain(({ player_domains[0], player_domains[1], selection }));
                TP->InitInnate();
                tell_object(TP, "You have chosen to select the " + selection + " domain.");
                tell_object(TP, "Your now have the following domains: " + player_domains[0] + ", " + player_domains[1] + " and " + selection + "\n");
                return 1;
            }

            tell_object(TP, "Even the greatest of clerics cannot choose more than three domains!\n");
            return 1;
        }
        break;
    }
    return 1;
}

void initialize_ob(string pcname, object myob)
{
    if (!userp(find_player(pcname))) {
        return;
    }
    myob->set_item_owner_prop("sale_clear", 0);
    myob->set_item_owner_prop("fence_clear", 0);
    myob->set_item_owner_prop("death_remove", 0);
    myob->set_item_owner_prop("death_clear", 0);
    myob->set_item_owner_prop("multiple_owners", 0);
    myob->add_item_owner(pcname);
    myob->set_property("donationgear", (string)find_player(pcname)->query_diety());
}

int select_diety(string str)
{
    string old;
    object symbol;
    int align;

    if (!str) {
        return notify_fail("Try choose <name>.");
    }
    str = lower_case(str);
    if (member_array(str, keys(DIETIES)) == -1) {
        return notify_fail("You can only choose to follow one of the new gods while here. See <help deities>.\n");
    }
    if (TP->query_property("dominated")) {
        return notify_fail("The god senses your true feelings and does not accept you as a follower.\n");
    }
    align = TP->query_true_align();
    if ((int)TP->query("last forsake") + FORSAKE_DELAY > time() && !avatarp(TP)) {
        tell_object(TP, "You must ponder your recent decision to forsake a god longer.");
        return 1;
    }
    if (!DIETY_D->allowed_follow((string)TP->query_name(), str)) {
        tell_object(TP, capitalize(str) + "will not have you as a follower. You must prove your faith.");
        return 1;
    }
    if (member_array(align, DIETIES[str][1]) == -1) {
        tell_object(TP, capitalize(str) + " does not allow followers of your alignment.");
        return 1;
    }
    if (TP->is_class("paladin") || TP->is_class("cavalier") || TP->is_class("cleric") || TP->is_class("monk")) {
        if (member_array(align, DIETIES[str][2]) == -1) {
            tell_object(TP, capitalize(str) + " does not allow clergy of your alignment.");
            return 1;
        }
    }

    old = TP->query_diety();
    symbol = present("holy symbol", TP);
    if (old && old != "pan" && old != "godless") {
        tell_object(TP, "You have already chosen to follow " + capitalize(old) + "!");
        return 1;
    }
    tell_object(TP, "%^BOLD%^You have decided to follow " + capitalize(str) + "!");
    TP->set_diety(str);
    TP->set_sphere(DIETIES[str][0]);
    TP->forget_all_cl_spells();
    if (objectp(symbol)) {
        symbol->remove();
    }
    TP->set("god changed", 1);
    TP->update_channels();
    log_file("player/god_change", capitalize(TP->query_name()) + " joined " + capitalize(str) + ": " + ctime(time()) + "\n");
    "/cmds/avatar/_note.c"->cmd_note("ckpt " + TPQN + " %^BOLD%^%^CYAN%^chose to follow " + capitalize(str) + ".");
    return 1;
}
