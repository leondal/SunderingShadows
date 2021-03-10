//adapted from /std/lab.c
#include <std.h>
#include <move.h>

#define SAVE_FILE(x) "/d/magic/psi_comps/"+x+"/"

inherit VAULT;

int allowed_storage = 50;
string lab_id;
string owner = "none";

int help(string str);

void create() {
   ::create();
}

int is_psi_lab(){ return 1;}

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
   add_action("open","open");
   add_action("help","help");
}

int deposit(string str) {

   int amount;
   string stuff;
   object ob;
   object account;

   if(!str) {
      return help("workroom");
   }

   if(sscanf(str, "%d %s",amount, stuff) != 2) {
      stuff = str;
      amount = -1;
   }

   if((string)TPQN != owner && owner != "none") {
      return notify_fail("This isn't your workroom or a public workroom.\n");
   }
   
   if(!file_exists(SAVE_FILE(lab_id)+TPQN+".comp.o") ) {
      if(owner == "none") {
         return notify_fail("You have not opened an account with this workroom.\n");
      }

   }

   if(!ob = present(stuff,TP)) {
      return notify_fail("You are not carrying "+stuff+".\n");
   }


   if(amount < 0 || amount > ob->query_comp_quantity()) {
      amount = ob->query_comp_quantity();
   }

   if(member_array("component",ob->query_id()) == -1) {
      return notify_fail(capitalize(stuff)+" is not considered a crystal component.\n");
   }



   account = new ("/d/magic/psiCompAccount");
   account->set_owner(lab_id,TPQN);
   account->Restore();
   account->Save();

   if((int)account->query_comp_quantity(ob->query_name())+amount > allowed_storage) {
      amount = allowed_storage - (int)account->query_comp_quantity(ob->query_name());
      tell_object(TP,"That would result in an overflow of your storage space. You are forced to add only "+amount+" "+ob->query_name()+"s");
   }

   account->add_comp(ob->query_name(),amount);
   account->Save();
   account->remove();

   ob->set_comp_quantity((int)ob->query_comp_quantity() - amount);

   tell_object(TP,"%^BOLD%^%^CYAN%^You carefully take your "+ob->query_name()+" and add it to your storage space here.");
   tell_room(TO,"%^BOLD%^%^CYAN%^"+TPQCN+" carefully takes some "+ob->query_name()+" and adds it to "+TP->QP+" storage space.",TP);
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
      return help("workroom");
   }

   if(sscanf(str, "%d %s",amount, stuff) != 2) {
      stuff = str;
      amount = -1;
   }

   if((string)TPQN != owner && owner != "none") {
      return notify_fail("This isn't your workroom or a public workroom.\n");
   }

   if(!file_exists(SAVE_FILE(lab_id)+TPQN+".comp.o") ) {
      if(owner == "none") {
         return notify_fail("You have not opened an account with this workroom.\n");
      }

   }


   account = new ("/d/magic/psiCompAccount");
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
      tell_object(TP,"You only have "+amount+" available. You will withdraw that many.\n");
   }
   account->remove_comp(stuff,amount);
   account->Save();
   account->remove();
   ob = new("/d/magic/store_psi_comp.c");
   if(amount > 1) {
      ob->set_name(stuff);
      ob->set_id(({stuff,"component","crystal","psi_component"}));

      ob->set_short(capitalize(stuff)+" (a psionic crystal)");
      ob->set_long("             "+amount+" "+capitalize(stuff)+".\n"+ob->query_long());
      ob->set_comp_quantity(amount);
      if( (int)(ob->move(TP)) != MOVE_OK ) {
         write("You dropped the crystal as you cannot carry anymore.");
         ob->move(ETP);
      }

   } else {
      ob->set_name(stuff);
      ob->set_id(({stuff,"component","crystal","psi_component"}));
      ob->set_short(capitalize(stuff)+" (a psionic crystal)");
      ob->set_long("             1 "+capitalize(stuff)+".\n"+ob->query_long());
      ob->set_comp_quantity(1);
      if( (int)(ob->move(TP)) != MOVE_OK ) {
         write("You dropped the crystal as you cannot carry anymore.");
         ob->move(ETP);
      }
 
   }

   tell_object(TP,"%^BOLD%^%^CYAN%^You remove "+amount+" "+stuff+(amount>1?"s ":" ")+"from your store here.");
   tell_room(TO,"%^BOLD%^%^CYAN%^"+TPQCN+" removes "+amount+" "+stuff+(amount>1?"s ":" ")+"from "+TP->QP+" store here.",TP);
   return 1;


}

int list(string str){
   object account;

   if (!str) {
      return notify_fail("List what?\n");
   }
   if (str != "components" && str != "crystals") {
      return notify_fail("List what?\n");
   }
   if((string)TPQN != owner && owner != "none") {
      return notify_fail("This isn't your workroom or a public workroom.\n");
   }

   if(!file_exists(SAVE_FILE(lab_id)+TPQN+".comp.o") ) {
      if(owner == "none") {
         return notify_fail("You have not opened an account with this workroom.\n");
      }

   }

   account = new ("/d/magic/psiCompAccount");
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

   if (str != "workroom") {
      return 0;
   }


   write("       Workroom help");
   write("<============================>");
   write(" open account: opens a storage space for you, costs 10000 gold");
   write(" deposit <crystal>: deposits all of that crystal you possess.");
   write(" deposit <amount> <crystal>: deposits amount of the crystal");
   write(" withdraw <crystal>: withdraws all the crystal in your storage space");
   write(" withdraw <amount> <crystal>: withdraw the amount of crystal from your storage space");
   write(" list crystals: lists the contents of your storage space");
   write(" help workroom: shows this screen.");
   return 1;
}

int open(string str){

   object account;

   if(!str){
      return 0;
   }
   if (str != "account") {
      return 0;
   }
   if ((string)TPQN == owner) {
      return notify_fail("You own this workroom and needn't open an account.\n");
   }
   if((string)TPQN != owner && owner != "none") {
      return notify_fail("This isn't your workroom or a public workroom.\n");
   }
   if(file_exists(SAVE_FILE(lab_id)+TPQN+".comp.o") ) {
      return notify_fail("You already have an account here.\n");
   }
   if (!TP->query_funds("gold",10000)) {
      return notify_fail("You need 10000 gold to reserve a storage space here.\n");

   }
   TP->use_funds("gold",10000);
   account = new ("/d/magic/psiCompAccount");
   account->set_owner(lab_id,TPQN);
   account->Save();
   account->remove();
   tell_object(TP,"You now have a storage space in this workroom.");
   return 1;

}

