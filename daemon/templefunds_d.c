#include <std.h>
#include <security.h>
#include <daemons.h>
#include <dieties.h>

#define SAVE_FILE "/daemon/save/templefunds"
inherit DAEMON;

mapping tAccounts;
mapping tWithdrawals;
mapping pDonations;

void create()
{
    ::create();
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE);
    seteuid(getuid());
    clear_data();
    save_data();
}

void save_data()
{
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
}


int query_temple_account(string temple)
{
    if (!tAccounts) {
        tAccounts = ([]);
    }
    if (!tAccounts[temple]) {
        tAccounts[temple] = 0;
    }
    return tAccounts[temple];
}

int query_temple_withdrawals(string temple)
{
    if (!tWithdrawals) {
        tWithdrawals = ([]);
    }
    if (!tWithdrawals[temple]) {
        tWithdrawals[temple] = 0;
    }
    return tWithdrawals[temple];
}

int query_donations(string name)
{
    int amount, i, j;
    string* which;
    string temple;
    if (!pDonations) {
        pDonations = ([]);
    }
    if (!pDonations[name]) {
        pDonations[name] = ([]);
    }
    if (!pDonations[name][temple]) {
        pDonations[name][temple] = 0;
    }
    j = sizeof(which);
    if (!pDonations[name]) {
        return (capitalize(name) + " doesn't seem to have made any donations to temples.");
    }
    return pDonations[name];
}

int clear_data()
{
    string usr;
    string diety;
    mapping donation;

    foreach(usr in keys(pDonations)) {
        donation = pDonations[usr];
        foreach(diety in keys(donation)) {
            if (member_array(diety, keys(DIETIES)) == -1) {
                map_delete(donation, diety);
            }
        }
        pDonations[usr] = donation;
    }

    foreach(usr in keys(pDonations)) {
        if (!user_exists(usr)) {
            map_delete(pDonations, usr);
        }
        if (!sizeof(pDonations[usr])) {
            map_delete(pDonations, usr);
        }
    }

    foreach(diety in keys(tAccounts)) {
        if (!file_exists(diety + ".c")) {
            map_delete(tAccounts, diety);
        }
    }
}

int clean_up()
{
    return 1;
}

int withdraw_funds(string temple, int amount, object who)
{
    int ok;
    if (avatarp(who)) {
        if (!tAccounts) {
            tAccounts = ([]);
        }
        if (!tAccounts[temple]) {
            tAccounts[temple] = 0;
        }
        if (!tWithdrawals) {
            tWithdrawals = ([]);
        }
        if (!tWithdrawals[temple]) {
            tWithdrawals[temple] = 0;
        }
        if (tAccounts[temple] < amount) {
            tell_object(who, "This temple only has " + tAccounts[temple] + " gold in "
                        "funds.  That's all you get.");
            amount = tAccounts[temple];
        }
        tAccounts[temple] -= amount;
        tWithdrawals[temple] += amount;
        tell_object(who, "You have withdrawn %^YELLOW%^" + amount + " gold %^RESET%^"
                    "of the funds of the temple of " + temple + ".");
        log_file("player/tithes", capitalize(who->query_name()) + " withdrew "
                 + amount + " gold from the temple of " + capitalize(temple) +
                 " on " + ctime(time()) + ".\n");
        save_data();
        return 1;
    }
    tell_object(who, "I'm quite sure you are not authorized.");
    return 0;
}

void add_temple_gold(string temple, int amount, string type, object who, string diety, int item)
{
    int amt2;
    string name;
    name = who->query_name();
    if (!item) {
        who->add_money(type, -amount);
    }
    who->force_me("save");
    log_file("player/tithes", capitalize(who->query_name()) + " donated " + amount + " " + type +
             " to the temple of " + capitalize(temple) + " on " + ctime(time()) + ".\n");
    if (!tAccounts) {
        tAccounts = ([]);
    }
    if (!tAccounts[temple]) {
        tAccounts[temple] = 0;
    }
    if (!pDonations) {
        pDonations = ([]);
    }
    if (!pDonations[name]) {
        pDonations[name] = ([]);
    }
    if (!pDonations[name][diety]) {
        pDonations[name][diety] = 0;
    }

    if (type != "gold") {
        amt2 = amount * (int)ECONOMY_D->currency_rate(type);
        amount = amt2 / (int)ECONOMY_D->currency_rate("gold");
    }
    tAccounts[temple] += (amount * 90 / 100);
    pDonations[name][diety] += amount;
    save_data();
}
