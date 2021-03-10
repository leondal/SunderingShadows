#include <std.h>

#define GUILDSD "/daemon/guilds_d.c"

string guild_name;

void init() {
    add_action("query_cash", "balance");
    add_action("deposit", "deposit");
    add_action("read", "read");

}


void set_guild_name(string str) {
    guild_name = str;
    return;
}

int query_cash() {
    int amount;

    if (!guild_name) return notify_fail("Sorry you are in a wrong place.\n");
    if (!TP->in_guild(guild_name))
        tell_object(TP, "The bookie snarls at you, but answers after you wave your weapon in his face.");

    amount = GUILDSD->query_funds(guild_name);
    if(amount == -1){
        tell_player(TP, "Please contact a Wiz.");
        return 1;
    }
    tell_player(TP, guild_name+" has "+amount+" gold in funds available.\n");
    return 1;
}

int deposit(string str) {
    string type;
    int x;
    int amount;

    if (!str) {
        notify_fail("Correct syntax: <deposit [amount] gold>.  Gold only.\n");
        return 0;
    }

    if (sscanf(str, "%d %s", amount, type) != 2) {
        notify_fail("Correct syntax: <deposit [amount] gold>.  Gold only.\n");
        return 0;
    }

    if ((int)TP->query_money(type) < amount) {
        notify_fail("Your bookie tells you that you don't have enough money!\n");
        return 0;
    }

    if (type != "gold") {
        notify_fail("Your bookie sayz: We only deal in gold here cheapo!\n");
        return 0;
    }

    TP->add_money(type, -amount);
    TP->force_me("save");
    tell_object(TP, "The bookie takes "+amount+" of your gold with a scowl.\n");
    say(TPQCN+" forks over some of his hard earned cash.\n");
    x = GUILDSD->add_funds(guild_name, amount);
    return 1;
}

int read(string str) {
    if (!str) return notify_fail("read what?");
    if (str != "sign") return notify_fail("That is not here");

    tell_room(ETP, TPQCN+" reads the sign on the wall.", TP);
    tell_object(TP, "These are the commands available in this room :");
    tell_object(TP, "   balance : Lists the current balance of your guild's account.");
    tell_object(TP, "   deposit <amt> gold : Deposits <amt> of your own gold for guild use...   No refunds!!");
    return 1;
}
