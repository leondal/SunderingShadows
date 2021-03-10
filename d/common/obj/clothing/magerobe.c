// the new magerobes! complete with component storage in the pockets.
// they no longer carry component bags; 1x mage book only.
// casting can be done directly from the robe itself. N, 5/14.
// please be sure to update /d/magic/comp_bag if there is any change
// to the functionality of this item; both function the same way.
// taking the lock off non-casters; there's now no real extra benefit to them so no reason not to let them wear (unless specific items are geared to mages/etc). N, 10/15.
#include <std.h>
#include <move.h>
inherit "/std/pocketarmour";

#include <spellcomponents.h>

mapping comp;
string *comps;

void sort();
private void swap(int i, int j);

void create() {
    ::create();
    comp = ([]);
    set_name("robe");
    set_id(({ "robe","simple robe" }));
    set_short("simple robe");
    set_long("This is a simple but serviceable robe, crafted of sturdy linen with long sleeves and a nearly ground-length hemline. There are pockets inside to keep a few belongings. It would be good for day-to-day activities and travel.");
    set_weight(8);
    set_value(10);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
    set_ac(0);
    set_max_internal_encumbrance(21);
    set_property("no animate",1);
    set_wear((:TO,"wear_stuff":));
}

mapping query_comp_map() { return comp; }

void set_comp_map(mapping info) { comp = info; }

int wear_stuff(){
    return 1; //Don't remove it since non-lambda closures save.
}

void init() {
   ::init();
   if(member_array("compx",TO->query_id()) == -1) TO->add_id("compx"); // will fix casting on existing robes.
   if(member_array("componenter",TO->query_id()) == -1) TO->add_id("componenter"); // will fix casting on existing robes.
   add_action("components","components");
   add_action("produce","produce");
   add_action("empty","empty");
   add_action("rummage","rummage");
   add_action("help","help");
}

int item_allowed(object item) { // these now only need to store a magebook. Bards have instrument cases, psions can wear their crystals.
   if(sizeof(all_inventory(TO)) > 0) {
     notify_fail("This garment is already holding something.\n");
     return 0;
   }
   if(base_name(item) == "/d/magic/spellbook") {
      return 1;
   }
   write("Only components or a small book would fit in the robe.");
   return 0;
}

void remote_set_comp(string item, int quantity) { comp[item] = quantity; }

void set_comp(string item, int quantity) { comp[item] = quantity; }

int query_comp(string item) { return comp[item]; }

int components(string which) {
   int x,amt;
   if (ETO != TP) return 0;
   if(TP->query_blind()){
       write("You are blind and cannot see anything.");
       return 1;
   }
   if (which) {
      if (present("compx "+which, TP) != TO) return 0;
   }
   comps = keys(comp);
   write("%^MAGENTA%^--=%^BOLD%^< %^WHITE%^Contents of this Arcane Garment %^MAGENTA%^>%^RESET%^%^MAGENTA%^=--%^RESET%^");
   write(arrange_string("Component:", 30) + "Amount:");
      sort();
   for(x = 0; x < sizeof(comps);x++) {
      amt = comp[comps[x]];
    if (!amt) { map_delete(comp, comps[x]) ; }
     else
      write("%^BLUE%^"+arrange_string(comps[x], 30) + amt);
   }
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
   	if(sscanf(str,"%s %s",num,name) != 2) return notify_fail("Syntax <produce [quantity] [component]>\n");
   	amt = this_object()->query_comp(name);
	if(num == "all") num = amt;
	else num = to_int(num);

   	if(num <= 0) return notify_fail("Get real!\n");
   	if(num > amt) return notify_fail("Not enough "+name+" in the garment!\n");
   	if(num > 100) return notify_fail("Too much at a time! Aborting...\n");
   	after_amt = amt - num;
   	if(after_amt < 0) return notify_fail("Something wrong! Aborting...\n");

      ob = new("/d/magic/store_comp.c");
      if(amt > 1) {
        write("%^CYAN%^There are now %^YELLOW%^"+after_amt+" %^CYAN%^"+name+"s%^RESET%^%^CYAN%^ in the garment.%^RESET%^");
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
        notify_fail("There are no "+name+"s in the garment, sorry.\n");
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
   if(str != "garment") return notify_fail("You can't empty that! Try <empty garment>.\n");

   comps = keys(comp);
   if(!sizeof(comps)) return notify_fail("The garment is already empty!\n");

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
   tell_object(ETO,"You finish emptying the garment of all its components.");
   tell_room(EETO,""+ETOQCN+" empties the garment of components.",ETO);
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
      write("There are now "+after_use+" "+str+"s in the garment.\n");
      return 1;
   }
  else if (after_use == 1) {
   write("You only have one "+str+" remaining in your garment!\n");
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

string query_long(string str) {
    string ret;

    ret = ::query_long(str);
    ret += "\nYou realise that this is an arcane garment with pockets for components. See <help garment> for commands.\n";
    return ret;
}

int help(string str){
    if (!str) return 0;
    if (str != "garment") return 0;
    if (!interactive(TP)) return 0;

    tell_object(TP,"%^RESET%^This garment is designed with pockets for all kinds of spell components.");
    tell_object(TP,"%^RESET%^To check what is in the pockets type %^YELLOW%^<components>%^RESET%^.");
    tell_object(TP,"%^RESET%^To put a component into the garment type %^YELLOW%^<put [component] into garment>%^RESET%^.");
    tell_object(TP,"%^RESET%^To retrieve components from the bag type %^YELLOW%^<produce [quantity] [component]>%^RESET%^ or %^YELLOW%^<produce [all] [component]>%^RESET%^.");
    tell_object(TP,"%^RESET%^You can %^YELLOW%^<rummage for [component]>%^RESET%^ to see how many you have of that particular component.");
    tell_object(TP,"%^RESET%^Finally, %^YELLOW%^<empty garment>%^RESET%^ will remove all the components from the pockets.");
    tell_object(TP,"%^BOLD%^%^WHITE%^Note that any components bags or other arcane robes held in your inventory may interfere with the use of this garment.%^RESET%^");
    return 1;
}
