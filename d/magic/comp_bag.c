//   Components Bag for Wizard Characters [v0.2]
//   Thorn@Shadowgate
//   10/10/94 [0.2: 12/7/94]
//   General Wizard Class Items
//   comp_bag.c
//   0.2.1: New components list fun added; components saved to disk file, improved!
//   0.2.2: New components producing fun added;
// converted to generic component storage for all classes. N, 5/14.
// please be sure to update /d/common/obj/clothing/magerobes if there is any change
// to the functionality of this item; both function the same way.
#include <std.h>
#include <move.h>
inherit OBJECT;

#include <spellcomponents.h>

mapping comp;
string *comps;

void sort();
private void swap(int i, int j);

void create() {
   ::create();
   comp = ([]);
   set_weight(10);
   set_value(0);
   set_id(({"componenter", "bag","leather bag", "components bag", "compx"}));
   set_name("components bag");
   set_short("A leather bag");
   set_long(
@MAGICK
This is a small to medium-sized leather bag.  It is only in this bag that you store the material components for casting your spells.

To check what is in the bag type %^ORANGE%^<components>%^RESET%^.
To put a component into the bag type:
%^ORANGE%^<put %^ORANGE%^%^ULINE%^COMPONENT%^RESET%^%^ORANGE%^ into components bag>%^RESET%^
To retrieve components from the bag type:
%^ORANGE%^<produce %^ORANGE%^%^ULINE%^QUANTITY%^RESET%^%^ORANGE%^|all %^ORANGE%^%^ULINE%^COMPONENT%^RESET%^>%^RESET%^
To see how many of a particular component you have, type:
%^ORANGE%^<rummage for %^ORANGE%^%^ULINE%^COMMPONENT%^RESET%^%^ORANGE%^>%^RESET%^
To produce all components in the bag at once, type:
%^ORANGE%^<empty bag>%^RESET%^

%^BOLD%^%^RED%^N.B.:%^RESET%^ Make sure the bag you want to empty is the first in your inventory.
This satchel will only hold those components needed for spellcasting.
MAGICK
           );
}


void remote_set_comp(string item, int quantity) {
   comp[item] = quantity;
}

void set_comp(string item, int quantity) {
   comp[item] = quantity; 
}

int query_comp(string item) {
   return comp[item];
}

void init() {
   ::init();
   add_action("components","components");
   add_action("produce","produce");
   add_action("empty","empty");
   add_action("rummage","rummage");
}

int components(string which) {
   int x,amt;
   if (ETO != TP) {
      return 0;
   }
//check added so people cannot count components while blinded.  Circe 11/22/03
    if(TP->query_blind()){
        write("You are blind and cannot see anything.");
        return 1;
    }
   if (which) {
      if (present("compx "+which, TP) != TO) {
         return 0;
      }
   }
   comps = keys(comp);
   write("-------------------------------------------------------");
   write("%^GREEN%^BOLD%^Contents of this Components Bag%^RESET%^");
   write("-------------------------------------------------------");
   write(arrange_string("Component:", 30) + "Amount:");
   write("-------------------------------------------------------");
   sort();
   for(x = 0; x < sizeof(comps);x++) {
      amt = comp[comps[x]];
    if (!amt) { map_delete(comp, comps[x]) ; }
     else
      write(arrange_string(comps[x], 30) + amt);
   }
   write("-------------------------------------------------------");
   write("\n");
   return 1;
}

int rummage(string str) {
   int comp_amt;
   string compname;
   if(!str) {
      write("Rummage for what?");
      return 1;
   }
   if(sscanf(str, "for %s", compname) != 1) {
      write("Syntax: <rummage for component>");
      return 1;
   }
   comp_amt = this_object()->query_comp(compname);
   if(comp_amt > 1) {
      write("There are "+comp_amt+" "+compname+"s in the garment.\n");
      return 1;
   }
   if(comp_amt < 1) {
      write("There are no "+compname+"s in the garment.\n");
      return 1;
   }
   if(comp_amt = 1) {
      write("There is one "+compname+" in the garment.\n");
      return 1;
   }
}

int produce(string str) {
   	int amt,after_amt;
	mixed num;
   	string name;
   	object ob;

   	if(!str) return notify_fail("Produce what?\n");
   	if(sscanf(str,"%s %s",num,name) != 2)
   	{
		return notify_fail("Syntax <produce [quantity] [component]>\n");
   	}
   	amt = this_object()->query_comp(name);
	if(num == "all")
	{
		num = amt;
	}
	else
	{
		num = to_int(num);
	}

   	if(num <= 0) return notify_fail("Get real!\n");
   	if(num > amt) return notify_fail("Not enough "+name+" in the bag!\n");
   	if(num > 100) return notify_fail("Too much at a time! Aborting...\n");
   	after_amt = amt - num;
   	if(after_amt < 0) return notify_fail("Something wrong! Aborting...\n");

   ob = new("/d/magic/store_comp.c");
   if(amt > 1) {
      write("There are now "+after_amt+" "+name+"s in the bag.\n");
      this_object()->set_comp(name, after_amt);
      ob->set_name(name);
      ob->set_id(({name,"component"}));
      ob->set_short(capitalize(name)+" (a spell component)");
      ob->set_long("             %^BOLD%^"+num+" "+capitalize(name)+".\n"+ob->query_long());
      ob->set_comp_quantity(num);
      if( (int)(ob->move(TP)) != MOVE_OK ) {
         write("You dropped the component as you cannot carry anymore.");
         ob->move(ETP);
      }

      return 1;
   }
   if(amt < 1) {
      notify_fail("There are no "+name+"s in the bag, sorry.\n");
      return 0;
   }
   if(amt = 1) {
      write("You produce your only "+name+".\n");
      this_object()->set_comp(name, 0);
      ob->set_name(name);
      ob->set_id(({name,"component"}));
      ob->set_short(capitalize(name)+" (a spell component)");
      ob->set_long("             %^BOLD%^1 "+capitalize(name)+".\n"+ob->query_long());
      ob->set_comp_quantity(1);
      ob->move(this_player());
      return 1;
   }
}

int empty(string str) {
   object ob;
   int x, amt;
   string name;

   if(!str) return notify_fail("Empty what?\n");

   if(str != "bag") return notify_fail("You can't empty that! Try <empty bag>.\n");

   comps = keys(comp);

   if(!sizeof(comps)) return notify_fail("The bag is already empty!\n");

   for(x = 0; x < sizeof(comps);x++) {
      amt = comp[comps[x]];
      name = comps[x];
      if(!amt){ 
         map_delete(comp, comps[x]); 
      }else{
         ob = new("/d/magic/store_comp.c");
         TO->set_comp(name, 0);
         ob->set_name(name);
         ob->set_id(({name,"component"}));
         ob->set_short(capitalize(name)+" (a spell component)");
         ob->set_long("             "+amt+" "+capitalize(name)+".\n"+ob->query_long());
         ob->set_comp_quantity(amt);
         tell_object(ETO,"You produce "+amt+" "+name+", leaving none in the bag.");
         if( (int)(ob->move(TP)) != MOVE_OK ) {
            write("You dropped the component as you cannot carry anymore.");
            ob->move(ETP);
         }
      }
   }
   tell_object(ETO,"You finish emptying the bag of all its components.");
   tell_room(EETO,""+ETOQCN+" empties the bag of components.",ETO);
   return 1;
}

int use_comp(string str, int amount) {
   int use_amt,after_use,before_use;
   if(!str) return 0;
   if(!amount) {
      use_amt = 1;
   }
   else if(amount == -1) use_amt = 0;
   else {
      use_amt = amount;
   }
   before_use = this_object()->query_comp(str);
   if(before_use < 1) return 0;
   after_use = before_use - use_amt;
   if(after_use < 0) return 0;
   if(!after_use) {
      map_delete(comp,str);
   }
   else this_object()->set_comp(str, after_use);
   if(before_use == 1) {
      tell_player(ETO,"You produce your only "+str+".\n");
      return 1;
   }
   if(after_use > 1) {
      write("There are now "+after_use+" "+str+"s in the bag.\n");
      return 1;
   }
  else if (after_use == 1) {
   write("You only have one "+str+" remaining in your bag!\n");
  return 1;
  }
   return 1;
}

void sort() {
   int i,j;
   for(j=0;j<sizeof(comps);j++)
      for(i=sizeof(comps)-1;i>j;i--) {
         if(comps[i] < comps[i-1]) {
            swap(i-1,i);
         }
      }
}

private void swap(int i, int j) {
   string tmp;
   tmp = comps[i];
   comps[i]=comps[j];
   comps[j]=tmp;
}

int query_value(){
   int i,j,k;
   string *keyss;
   mapping compcosts;

   compcosts = COMPONENTS1;
   k = ::query_value();
    keyss = keys(comp);
       for(i = 0;i<sizeof(keyss);i++){
    k += compcosts[keyss[i]] * comp[keyss[i]];
}
return k;
}
