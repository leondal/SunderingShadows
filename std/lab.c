//mage lab
//Edit 1/1/2012 by Ergo
//changed "open" command to "create" because it was conflicting with an identical command in labs with doors.

#include <std.h>
#include <move.h>

#define SAVE_FILE(x) "/d/magic/comps/"+x+"/"

inherit VAULT;

int allowed_storage = 50;
string lab_id;
string owner = "none";

int help(string str);

void create() {
   ::create();

}


int is_lab(){ return 1;}
void setAllowedStorage(int xxx) {
   allowed_storage= xxx;
}


int query_allowed_storage() {
   return allowed_storage;
}

void setLabId(string id) {
   lab_id= id;
   mkdir(SAVE_FILE(lab_id));
}

string getLabId() {
   return lab_id;
}


void setOwner(string xxx) {
   owner = xxx;
}

string getOwner() {
   return owner;
}

void init() {
   ::init();


   add_action("deposit","deposit");
   add_action("withdraw","withdraw");
   add_action("list","list");
   add_action("createaccount","create");
   add_action("help","help");
}

int deposit(string str) {

   int amount;
   string stuff;
   object ob;
   object account;

   if(!str) {
      return help("laboratory");
   }

   if(sscanf(str, "%d %s",amount, stuff) != 2) {
      stuff = str;
      amount = -1;
   }

   if((string)TPQN != owner && owner != "none") {
      return notify_fail("This isn't your laboratory or a public laboratory.\n");
   }
   
   if(!file_exists(SAVE_FILE(lab_id)+TPQN+".comp.o") ) {
      if(owner == "none") {
         return notify_fail("You have not created an account with this lab.\n");
      }

   }

   if(!ob = present(stuff,TP)) {
      return notify_fail("You are not carrying "+stuff+".\n");
   }


   if(amount < 0 || amount > ob->query_comp_quantity()) {
      amount = ob->query_comp_quantity();
   }

   if(member_array("component",ob->query_id()) == -1) {
      return notify_fail(capitalize(stuff)+" is not considered a component.\n");
   }



   account = new ("/d/magic/compAccount");
   account->set_owner(lab_id,TPQN);
   account->Restore();
   account->Save();

   if((int)account->query_comp_quantity(ob->query_name())+amount > allowed_storage) {
      amount = allowed_storage - (int)account->query_comp_quantity(ob->query_name());
      tell_object(TP,"That would result in an overflow of your cubby. You are forced to remove only add "+amount+" "+ob->query_name()+"s");
   }

   account->add_comp(ob->query_name(),amount);
   account->Save();
   account->remove();

   ob->set_comp_quantity((int)ob->query_comp_quantity() - amount);

   tell_object(TP,"%^BOLD%^You carefully take your "+ob->query_name()+" and place it in your allocated cubby hole.");
   tell_room(TO,"%^BOLD%^"+TPQCN+" carefully takes some "+ob->query_name()+" and places it in "+TP->query_possessive()+" cubby.",TP);
   if((int)ob->query_comp_quantity() < 1) {
      ob->remove();
   }
   return 1;

}

int withdraw(string str) {
   object ob, account;
   int amount;
   string stuff;


   if(!str) {
      return help("laboratory");
   }

   if(sscanf(str, "%d %s",amount, stuff) != 2) {
      stuff = str;
      amount = -1;
   }

   if((string)TPQN != owner && owner != "none") {
      return notify_fail("This isn't your laboratory or a public laboratory.\n");
   }

   if(!file_exists(SAVE_FILE(lab_id)+TPQN+".comp.o") ) {
      if(owner == "none") {
         return notify_fail("You have not created an account with this lab.\n");
      }

   }


   account = new ("/d/magic/compAccount");
   account->set_owner(lab_id,TPQN);
   account->Restore();
   account->Save();

   if (account->query_comp_quantity(stuff) < 1) {
      return notify_fail("You have no store of "+stuff+".\n");
   }
   
   if (amount < 0) {
      amount = account->query_comp_quantity(stuff);
   }



   if((int)account->query_comp_quantity(stuff) < amount) {
      amount = account->query_comp_quantity(stuff);
      tell_object(TP,"You only have "+amount+" available, you will withdraw that many.\n");
   }
   account->remove_comp(stuff,amount);
   account->Save();
   account->remove();
   ob = new("/d/magic/store_comp.c");

   if(amount > 1) {
      ob->set_name(stuff);
      ob->set_id(({stuff,"component"}));

      ob->set_short(capitalize(stuff)+" (a spell component)");
      ob->set_long("             "+amount+" "+capitalize(stuff)+".\n"+ob->query_long());
      ob->set_comp_quantity(amount);
      if( (int)(ob->move(TP)) != MOVE_OK ) {
         write("You dropped the component as you cannot carry anymore.");
         ob->move(ETP);
      }

   } else {
      ob->set_name(stuff);
      ob->set_id(({stuff,"component"}));
      ob->set_short(capitalize(stuff)+" (a spell component)");
      ob->set_long("             1 "+capitalize(stuff)+".\n"+ob->query_long());
      ob->set_comp_quantity(1);
      if( (int)(ob->move(TP)) != MOVE_OK ) {
         write("You dropped the component as you cannot carry anymore.");
         ob->move(ETP);
      }
 
   }

   tell_object(TP,"%^BOLD%^You withdraw "+amount+" "+stuff+(amount>1?"s ":" ")+"from your store here.");
   tell_room(TO,"%^BOLD%^"+TPQCN+" withdraws "+amount+" "+stuff+(amount>1?"s ":" ")+"from "+TP->query_possessive()+" store here.",TP);
   return 1;


}

int list(string str){
   object account;

   if (!str) {
      return notify_fail("List what?\n");
   }

   if (str != "components") {
      return notify_fail("List what?\n");
   }


   if((string)TPQN != owner && owner != "none") {
      return notify_fail("This isn't your laboratory or a public laboratory.\n");
   }

   if(!file_exists(SAVE_FILE(lab_id)+TPQN+".comp.o") ) {
      if(owner == "none") {
         return notify_fail("You have not created an account with this lab.\n");
      }

   }

   account = new ("/d/magic/compAccount");
   account->set_owner(lab_id,TPQN);
   account->Restore();
   account->listComps(TP);
   account->remove();
   return 1;

}


int help(string str){

   if (!str) {
      return 0;
   }

   if (str != "laboratory") {
      return 0;
   }

//Prettied up the help file a bit - ~Circe~ 1/4/08
   write("                        %^BOLD%^Laboratory Help");
   write("%^BOLD%^%^CYAN%^<==============================================================>");
   write(" %^BOLD%^create account: %^RESET%^spend 10,000 to purchase a storage cubby");
   write(" %^BOLD%^deposit <component>: %^RESET%^deposits all of the component you possess");
   write(" %^BOLD%^deposit <amount> <component>: %^RESET%^deposits amount of the component");
   write(" %^BOLD%^withdraw <component>: %^RESET%^withdraws all the component in your cubby");
   write(" %^BOLD%^withdraw <amount> <component>: %^RESET%^withdraw amount of the component");
   write(" %^BOLD%^list components: %^RESET%^lists the contents of your cubby");
   write(" %^BOLD%^help laboratory: %^RESET%^shows this screen");
   return 1;
}

int createaccount(string str){

   object account;

   if(!str){
      return 0;

   }

   if (str != "account") {
      return notify_fail("Create what?\n");
   }
   if ((string)TPQN == owner) {
      return notify_fail("You own this lab and needn't create an account.\n");
   }

   if((string)TPQN != owner && owner != "none") {
      return notify_fail("This isn't your laboratory or a public laboratory.\n");
   }


   if(file_exists(SAVE_FILE(lab_id)+TPQN+".comp.o") ) {
      return notify_fail("You already have an account here.\n");
   }


   if (!TP->query_funds("gold",10000)) {
      return notify_fail("You need 10000 gold to reserve a cubby here.\n");

   }

   TP->use_funds("gold",10000);

   account = new ("/d/magic/compAccount");
   account->set_owner(lab_id,TPQN);
   account->Save();
   account->remove();
   tell_object(TP,"You now have a cubby in this laboratory.");
   return 1;

}

