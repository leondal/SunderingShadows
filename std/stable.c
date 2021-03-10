//Stable.c to sell the riding animals to the players of shadowgate

#include <std.h>
inherit VAULT;

private mapping animals;
private mapping price;
private mapping amount;
string *stalls;
int numstalls;

void buy_animal(string what);
void sell_animal(string what);
int query_num_animals();

void make_stable_hand()
{
    object ob;
    if(!present("stable hand")) 
    {
        ob = new(MONSTER);
        ob->set("long","This stable boy will sell you a mount.");
        ob->set("short","Stable hand");
        ob->set_id(({"stable hand","boy","stablehand"}));
        ob->set_gender("male");
        ob->set_race("human");
        ob->set_name("stable hand");
        ob->set_body_type("human");
        ob->move(TO);
    }
}


void create() 
{
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    if(!present("stable hand")) make_stable_hand();
}

void reset() 
{
    if(!present("stable hand")) make_stable_hand();  
}

void init() {
   ::init();
   add_action("buy","buy");
   add_action("sell","sell");
   add_action("read_sign","read");
   add_action("read_sign","look");
}

void set_stalls(int i){
   numstalls = i;
}

int query_stalls(){return numstalls;}

void set_animal(string *name, string *file) {
   int i;

   if(!name) return;
   if(!file) return;
   if(sizeof(name) != sizeof(file)) return;
   animals = ([]);
   i = sizeof(name);
   while(i--) animals[name[i]] = file[i];
}

void set_animal_price(string *name, int *prices) {
   int i;

   if(!name) return;
   if(!prices) return;
   if(sizeof(name) != sizeof(prices)) return;
   i = sizeof(name);
   price = ([]);
   while(i--) {
      if(!animals[name[i]])
         continue;
      price[name[i]] = prices[i];
   }
}

int buy(string str) {
   string *animal;
   object ob;
   string *petty;
   int i;

   if(!str) return 0;
   animal = keys(animals);
   if(member_array(str, animal) == -1) {
      notify_fail("You can't buy that here.\n");
      return 0;
   }
   petty = TP->query_pets();
   if (sizeof(petty) > 4)
      return notify_fail("You can only have 5 pets.  I won't condone animal hoarding.");
   if(!amount[str]) return notify_fail("We don't have any for sale right now. Please read the sign to see what is available.\n");
   if(!TP->query_funds("gold",price[str])) return notify_fail("You don't have the gold to pay for it.\n");
   tell_room(TO,"%^BOLD%^%^RED%^ The stable boy nods and walks toward the stalls at the end of the barn.%^RESET%^");
   tell_room(TO,"%^RED%^ The stable boy returns with a mount for "+TPQCN+".%^RESET%^",TP);
   write("%^RED%^ The stable boy returns with a mount for you.%^RESET%^");
   tell_room(TP,"%^RED%^ The stable boy says: "+price[str]+" gold.%^RESET%^");
   tell_room(TO,"%^GREEN%^The boy takes "+TP->query_possessive()+" money.%^RESET%^",TP);
   write("The lad takes your money.");
   buy_animal(str);
   ob = new(animals[str]);
   ob->set_owner(TP);
   TP->add_pet(ob);
   ob->move(TO);
   TP->use_funds("gold",price[str]);
   return 1;
}

void buy_animal(string what){
   int i;
   
   for(i=0;i<numstalls;i++){
      if(stalls[i] == what){
         stalls[i] = "";
         amount[what] -= 1;
         break;
      }   
   }
}

int sell(string str){
   string *animal, type;
   object ob;
   int amt, num;

   if(!str) return 0;
   if (!ob = present(str,TO)) {
      tell_object(TP,"%^MAGENTA%^The stable boy says: %^RESET%^I would have to see it before I can buy it.");
      return 1;
   }
   animal = keys(animals);
   if (sscanf(str,"%s %d",type,num)) str = type;
   if(member_array(str, animal) == -1) {
      tell_object(TP,"%^MAGENTA%^The stable boy says: %^RESET%^We have no use for one of those, we don't sell them here.");
      return 1;
   }
   if(TP != (object)ob->query_owner()) {
  if (objectp(ob->query_owner()) && present(ob->query_owner(),TP)) {
      tell_object(TP,"%^MAGENTA%^The stable boy says: %^RESET%^That is not yours to sell.");
      tell_object(ob->query_owner(),TPQCN+" is trying to sell your "+str+"!");
      return 1;
       }
   }
   if(ob->query_current_rider()){
      tell_object(TP,"%^MAGENTA%^The stable boy says: %^RESET%^I will need to inspect the "+str+". Nobody can be riding it.");
      return 1;
   }
   amt = price[str];
   amt = to_int(amt/4) + random(to_int(amt/2));
   tell_room(TO,"The stable boy nods and looks over the "+str+" carefully.");
   tell_room(TO,"The stable boy thinks carefully.");
   tell_object(TP,"%^MAGENTA%^The stable boy says:%^RESET%^ I will give you "+amt+" gold for this animal.");
   tell_room(TO,"The boy gives "+TPQCN+" some money.",TP);
   tell_object(TP,"The lad gives you the money.");
   tell_room(TO,"The stable boy takes the "+str+" to a stall.");
   sell_animal(str);
     if(objectp(ob->query_owner())) ob->query_owner()->remove_pet(ob);
    ob->move("/d/shadowgate/void");
    ob->remove();
   TP->add_money("gold",amt);
   return 1;
}

void sell_animal(string what){
   int i;
   
   for(i=0;i<numstalls;i++){
      if(stalls[i] == ""){
         stalls[i] = what;
         amount[what] += 1;
         break;
      }
   }
}

int read_sign(string str){
   string *pets;
   int x, num; 
   
   if(!str) return 0;
   if(str != "list" && str != "sign") return 0;
   pets = keys(animals);
   if(!query_num_animals()){
      write("There are no animals currently available for sale.");
      return 1;
   }
   write("%^MAGENTA%^We currently have the following animals for sale:%^RESET%^");
   write("%^GREEN%^"+arrange_string("Animal",15)+arrange_string("Price",15) + arrange_string("Number Available",17)+"%^RESET%^");
   write("%^MAGENTA%^==============================================%^RESET%^");
   for(x=0;x<sizeof(pets);x++){
      write(""+arrange_string(pets[x],15)+arrange_string(price[pets[x]]+" gold",15)+arrange_string(amount[pets[x]],3));   
   }
   write("%^MAGENTA%^==============================================%^RESET%^");
   return 1;
}

void fill_stalls(){
   int x,i;
   string *pets;
   
   if(!amount) amount = ([]);
   if(numstalls == 0) return;
   stalls = allocate(numstalls);
   for(x=0;x<numstalls;x++)
      if(stalls[x] == 0) stalls[x]="";
   pets = keys(animals);
   for(x=0;x<numstalls;x++){
      if(stalls[x] != "") continue;
      if(!random(5)){
         stalls[x] = "";
         continue;
      }
      i = random(sizeof(pets));
      stalls[x] = pets[i];
      amount[pets[i]] += 1;
   }
}

int query_num_animals(){
   int x, total;
   string *pets;

   if(!amount) return 0;
   if(!numstalls) return 0;
   total = 0;
   pets = keys(animals);
   for(x=0;x<sizeof(pets);x++){
      total += amount[pets[x]];
   }
   return total;
}
