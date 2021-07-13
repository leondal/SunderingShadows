// /std/bank.c
// <<==-- Coded By Fire Dragon --==>>
// Adjusted by Thorn 970209

#include <std.h>
#include <daemons.h>
#include <money.h>
#include <bank.h>

#define BANK_ID getBankId()

#define PRICE_PER_CELL_TIER 1000

inherit VAULT;

string getBankId();

void create() {
   ::create();
   set_property("magic hold", 50);
   set_property("no castle", 1);
//   set_property("light", 2);
//   set_property("night light", 2);
   set_property("indoors", 1);
   set_short("A Bank");
   set_long("%^BOLD%^A Town Bank%^RESET%^\n");
   set_smell("default","The smell of money fills your nostrils.");
   set_listen("default","The sounds of rustling coins fill your ears.");
}

void init() {
   ::init();
   add_action("read", "read");
   add_action("open", "open");
   add_action("close", "close");
   add_action("deposit", "deposit");
   add_action("withdraw", "withdraw");
   add_action("balance", "balance");
   add_action("exchange", "exchange");
   add_action("storage", "storage");
   if (avatarp(TP)) {
       add_action("admdeposit", "admdeposit");
       add_action("admwithdraw", "admwithdraw");
   }
   /* add_action("cell_action","cell"); */
}

object load_cell(object player)
{
    object cell;

    if(player->query_property("bank_cell"))
    {
        cell=player->query_property("bank_cell");
    }

    if(!objectp(cell))
    {
        cell = new("/std/bank_storage");
        cell->setup_cell(player,getBankId());
        cell->load_inventory();
        cell->set_cell_tier(BANK_D->query_cell_tier(TP->query_name(),getBankId()));
        player->remove_property("bank_cell");
        player->set_property("bank_cell",cell);
    }

    return cell;
}

int list_cell()
{
    if(BANK_D->query_cell_tier(TP->query_name(),getBankId()))
    {
        object cell;

        cell = load_cell(TP);

        cell->show_list();

        return 1;
    }
    else
    {
        tell_object(TP,"Your don't have a cell in this bank.");
        return 1;
    }

    return 1;
}

int upgrade_cell()
{
    int tier = BANK_D->query_cell_tier(TP->query_name(),getBankId());
    if(tier)
    {
        int price;

        price=PRICE_PER_CELL_TIER*to_int(pow(10,tier));

        /* if(BANK_D->increment_cell_tier(TP->query_name(),BANK_ID)) */
        /* { */

        /* } */

    }
    else
    {
        tell_object(TP,"Your don't have a cell in this bank.");
        return 1;
    }

    return 1;

}

int cell_action(string str)
{
    if(str == "list")
    {
        return list_cell();
    }

    if(str == "upgrade")
    {
        return upgrade_cell();
    }

    return 1;
}

int storage(mixed arg)
{
    tell_object(this_player(), "You touch a magical handle on the wall, and begin to summon a chest.");
    "/cmds/spells/s/_secret_chest.c"->use_spell(this_player(), arg, 50);
    return 1;
}

int exchange(string str) {
   string from, to;
   float val;
   int amount, amt, amt2, diff, original, check;

   if(!str) {
      notify_fail("Correct syntax: <exchange NUM TYPE for TYPE>\n"+
                  "ex: <exchange 100 gold for copper>\n");
      return 0;
   }
   if(sscanf(str, "%d %s for %s", amount, from, to) !=3) {
      notify_fail("Correct syntax: <exchange NUM TYPE for TYPE\nex: "
                  "<exchange 100 gold for copper>\n");
      return 0;
   }
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(amount < 1) {
      notify_fail("That would be a nifty trick indeed!\n");
      return 0;
   }
   if((int)this_player()->query_money(from) < amount) {
      notify_fail("You do not have that much of that currency.\n");
      return 0;
   }
   if( member_array( from, MONEY_TYPES ) == -1 ) {
      write("The bank does not support "+from+".\n");
      return 0;
   }
   if( member_array( to, MONEY_TYPES ) == -1) {
      write("The bank does not support "+to+".\n");
      return 0;
   }
//Some of the calcs seem unnecessary, but I'm retaining them while reordering to avoid
//the player losing money when they don't have enough for the exchange, hence the new variable ~Circe~ 12/16/15
   original = amount;
   amt = amount;
   val = amount * (int)ECONOMY_D->currency_rate(from);
   amount = to_int(val / (int)ECONOMY_D->currency_rate(to));
   //check = (amount*85)/100; Currency exchange is free - Odin 5/4/2020
   check = amount;
   if(check < 1){
      notify_fail("That is not enough "+from+" to exchange it for "+to+".\n");
      return 0;
   }
   this_player()->add_money(from, -(original));
   amt2 = amount * (int)ECONOMY_D->currency_rate(to);
   amt2 = amt2 / (int)ECONOMY_D->currency_rate(from);
   diff = amt - amt2;
   if (diff > 0) TP->add_money(from,diff);
   //amount = (amount*85)/100; See above comment, we're punishing player with 15% deposit fee, shouldn't charge them for exchange
   this_player()->add_money(to, amount);
   write("You exchange your "+from+" coins for "+amount+" "+to+".");
   tell_room(ETP,TPQCN+" exchanges some money.",TP);
   return 1;
}

varargs int close(string str, int quiet)
{
    int i;
    mapping money;

    if(!str || str != "account")
        return 0;
    if(TP->query_bound() || TP->query_unconscious())
    {
        if(!quiet)
        {
            TP->send_paralyzed_message("info",TP);
            return 1;
        }
    }
    money = (mapping)BANK_D->query_balance((string)this_player()->query_name(), BANK_ID );
    if(!money || money == ([]))
    {
        if(!quiet)
        {
            write("%^MAGENTA%^The teller says%^RESET%^: You have no account here to close!");
            tell_room(ETP,TPQCN+" tries to close a non-existant account!",TP);
            return 1;
        }
        else return 0;
   }
    for(i=0; i<sizeof(HARD_CURRENCIES); i++)
    {
        if(money[HARD_CURRENCIES[i]])
            this_player()->add_money(HARD_CURRENCIES[i],money[HARD_CURRENCIES[i]]);
    }
    if(!quiet)
    {
        write("The teller hands you all your money.");
        tell_room(ETP,TPQCN+" collects all "+TP->query_possessive()+" money from the teller.",TP);
    }
    BANK_D->close_account((string)this_player()->query_name(), BANK_ID);
    return 1;
}

int open(string str) {
   int x;

   if(!str || str != "account") return 0;
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   x = (int)BANK_D->open_account((string)this_player()->query_name(),BANK_ID);
   if(x != TRANSACTION_OK) {
      write("You already have an account here!");
      return 1;
   }
   write("You open up an account at this bank.");
   tell_room(ETP,TPQCN+" opens an account.",TP);
   return 1;
}

int balance(string str) {
   mapping money;
   int i;

   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   money = (mapping)BANK_D->query_balance((string)this_player()->query_name(), BANK_ID);
   if(!money || money == ([])) {
      write("%^MAGENTA%^The teller says%^RESET%^: You have no account here!");
      return 1;
   }
   tell_room(ETP,TPQCN+" receives a piece of paper from the teller.",TP);
   write("\n\n The teller looks up your account. He writes something down");
   write(" on a small piece of paper and hands it to you. On the paper");
   write(" you see the following:\n");
   for(i=0; i<sizeof(HARD_CURRENCIES); i++) {
      printf("%-10s : %-15s coins\n",capitalize(HARD_CURRENCIES[i]),english_number(money[HARD_CURRENCIES[i]]));
   }
   write(" \nThe paper disappears from your hand.");
   return 1;
}

int deposit(string str) {
   string type;
   int x, amount, amount2;

   if(!str) {
      notify_fail("Correct syntax: <deposit AMOUNT TYPE>\n");
      return 0;
   }
   if(sscanf(str, "%d %s", amount, type) != 2) {
      notify_fail("Correct syntax: <deposit AMOUNT TYPE>\n");
      return 0;
   }
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if((int)this_player()->query_money(type) < amount) {
      write("%^MAGENTA%^The teller says%^RESET%^: You do not have that much money!\n");
      return 0;
   }

   amount2 = amount;
   amount2 = (amount * 90) / 100;
   x = (int)BANK_D->deposit((string)this_player()->query_name(), BANK_ID, amount2, type);
   if(x != TRANSACTION_OK) {
      switch(x) {
      case NO_ACCOUNT:
         write("%^MAGENTA%^The teller says%^RESET%^: You have no account here!\n");
         break;
      case BAD_MONEY:
         write("%^MAGENTA%^The teller says%^RESET%^: That is not a real money type!\n");
         break;
      default: write("%^MAGENTA%^The teller says%^RESET%^: You can't do that!\n");
      }
      return 1;
   }
   this_player()->add_money(type, -amount);
   this_player()->force_me("save");
   write("The teller takes your "+amount+" "+type+" coins.");
   tell_room(ETP,TPQCN+" deposits some money.",TP);
   return 1;
}

int withdraw(string str) {
   string type;
   int x, amount;

   if(!str) {
      notify_fail("Correct syntax: <withdraw AMOUNT TYPE>\n");
      return 0;
   }
   if(sscanf(str, "%d %s", amount, type) != 2) {
      notify_fail("Correct syntax: <withdraw AMOUNT TYPE>\n");
      return 0;
   }
   if(TP->query_ghost()){
      notify_fail("Ghosts cant hold money.\n");
      return 1;
   }
   if(TP->query_bound() || TP->query_unconscious()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(amount < 0) {
      write("%^MAGENTA%^The teller says%^RESET%^: That would be a neat trick!\n");
      return 0;
   }
   x = (int)BANK_D->withdraw((string)this_player()->query_name(), BANK_ID, amount, type);
   if(x != TRANSACTION_OK) {
      switch(x) {
      case NO_ACCOUNT:
         write("%^MAGENTA%^The teller says%^RESET%^: You have no account here!\n");
         break;
      case BAD_MONEY:
         write("%^MAGENTA%^The teller says%^RESET%^: That is not a real money type!\n");
         break;
      default: write("%^MAGENTA%^The teller says%^RESET%^: You can't do that!\n");
      }
      return 1;
   }

   //amount = (amount*90)/100;
   this_player()->add_money(type, amount);
   write("The teller gives you your "+amount+" "+type+" coins.");
   tell_room(ETP,TPQCN+" withdraws some money.",TP);
   return 1;
}

int read(string str) {
   if(str != "sign") return notify_fail("Read what?\n");
   write(
@MELNMARN

%^CYAN%^%^BOLD%^ open account%^BLACK%^ ------------------------- %^RESET%^: %^CYAN%^Will open an account for you.
%^CYAN%^%^BOLD%^ close account%^BLACK%^ ------------------------ %^RESET%^: %^CYAN%^Closes your account.
%^CYAN%^%^BOLD%^ balance%^BLACK%^ ------------------------------ %^RESET%^: %^CYAN%^Gives your account balance info.
%^CYAN%^%^BOLD%^ deposit NUM TYPE%^BLACK%^ --------------------- %^RESET%^: %^CYAN%^Deposits NUM of currency of TYPE.
%^CYAN%^%^BOLD%^ withdraw NUM TYPE%^BLACK%^ -------------------- %^RESET%^: %^CYAN%^Withdraws NUM of currency of TYPE.
%^CYAN%^%^BOLD%^ exchange NUM TYPE for TYPE2%^BLACK%^ ---------- %^RESET%^: %^CYAN%^Exchanges currencies.
%^CYAN%^%^BOLD%^ storage%^BLACK%^ ------------------------------ %^RESET%^: %^CYAN%^Summon your magical storage chest.
%^CYAN%^%^BOLD%^ - give ITEM to chest%^BLACK%^ ----------------- %^RESET%^: %^CYAN%^Stores an item in the storage chest.
%^CYAN%^%^BOLD%^ - command chest to give ITEM to WHOM%^BLACK%^ - %^RESET%^: %^CYAN%^Gives ITEM from chest to WHOM.
%^CYAN%^%^BOLD%^ - dismiss chest %^BLACK%^ --------------------- %^RESET%^: %^CYAN%^Returns the storage chest to the bank.

A 10% service fee will be charged to all deposits.
MELNMARN
   );
   if(archp(TP)) {
      write("\nAlso, admdeposit (x) (type) (player name)\nadmwithdraw (x) (type) (player name)\n");
   }
   return 1;
}

float dnd_currency_rate(string from) {
   switch( from ) {
   case "copper"   : return 1;
      break;
   case "silver"   : return 10;
      break;
   case "electrum" : return 50;
      break;
   case "gold"     : return 100;
      break;
   case "platinum" : return 500;
      break;
   }
   return 0;
}

int admdeposit(string str) {
   string type, player;
   int x, amount;

   if(!str) {
      notify_fail("Correct syntax: <admdeposit AMOUNT TYPE PLAYER>\n");
      return 0;
   }
   if(sscanf(str, "%d %s %s", amount, type, player) != 3) {
      notify_fail("Correct syntax: <admdeposit AMOUNT TYPE PLAYER>\n");
      return 0;
   }
   x = (int)BANK_D->deposit(
                           player, BANK_ID, amount, type
                           );
   if(x != TRANSACTION_OK) {
      switch(x) {
      case NO_ACCOUNT:
         write("%^MAGENTA%^The teller says%^RESET%^: Hmm, that account does not exist, my lord!\n");
         break;
      case BAD_MONEY:
         write("%^MAGENTA%^The teller says%^RESET%^: That is not a real money type, my lord.\n");
         break;
      default: write("%^MAGENTA%^The teller says%^RESET%^: I am too puny to do that, my lord.\n");
      }
      return 0;
   }
   write("The teller adds "+amount+" "+type+" coins to the "+capitalize(player)+" account.");
   return 1;
}

int admwithdraw(string str) {
   string type, player;
   int x, amount;

   if(!str) {
      notify_fail("Correct syntax: <admwithdraw AMOUNT TYPE PLAYER>\n");
      return 0;
   }
   if(sscanf(str, "%d %s %s", amount, type, player) != 3) {
      notify_fail("Correct syntax: <admwithdraw AMOUNT TYPE PLAYER>\n");
      return 0;
   }
   if(amount < 0) {
      write("%^MAGENTA%^The teller says%^RESET%^: Account is empty, my lord!\n");
      return 0;
   }
   x = (int)BANK_D->withdraw(
                            player, BANK_ID, amount, type
                            );
   if(x != TRANSACTION_OK) {
      switch(x) {
      case NO_ACCOUNT:
         write("%^MAGENTA%^The teller says%^RESET%^: Hmm, that account does not exist, my lord!\n");
         break;
      case BAD_MONEY:
         write("%^MAGENTA%^The teller says%^RESET%^: That is not a real money type, my lord.\n");
         break;
      default: write("%^MAGENTA%^The teller says%^RESET%^: I am too puny to do that, my lord.\n");
      }
      return 0;
   }
   this_player()->add_money(type, amount);
   write("The teller gives you your "+amount+" "+type+" coins from the "+capitalize(player)+" account.");
   return 1;
}

string getBankId(){
    return get_area_name(TO);
}
