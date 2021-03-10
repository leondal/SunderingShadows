#include <std.h>
#include <daemons.h>
#include <move.h>

inherit MONSTER;

#define SAVE_MON "/d/save/tulmak"
#define STORAGE_DIR "/d/save/fist/"
#define MAX 60

string *items;
int num;

void add_item(object ob);
int count();

void create() {
   ::create();
   items = allocate(MAX);
   seteuid(geteuid());
   restore_object(SAVE_MON);
   set_name("Tulmak");
   set_id( ({ "Tulmak", "tulmak", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Tulmak, keeper of the Iron Fist storage room");
   set("aggressive", 0);
   set_level(19);
   set_long("Tulmak keeps the Iron Fist storage room organized.\n");
   set_gender("male");
   set_alignment(5);
   set("race", "human");
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_exp(10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   num = count();
   save_object(SAVE_MON);
}

void init(){
   ::init();
   add_action("deposit_item","deposit");
   add_action("retrieve_item","retrieve");
   add_action("__Buy","buy");
   add_action("__Sell","sell");
   add_action("list_items","list");
   add_action("show_item","bin");
}

int __Buy(string str){
   write("You cannot buy objects here, but you can <retrieve> them from storage for a price.");
   return 1;
}

int __Sell(string str) {
   write("You cannot sell objects here, only <deposit> them for storage.");
   return 1;
}

int deposit_item(string str){
   object ob;

   if(!str) {
      write("Try 'deposit <object>'!");
      return 1;
   }
   if(!(ob = present(str, TP))) {
      write("You don't have any "+str+" to deposit!\n");
      return 1;
   }
   if(ob->query_worn()){
      write("Please remove that before depositing it.\n");
      return 1;
   }
   if(ob->query_wielded()){
      write("Please unwield that before depositing it.\n");
      return 1;
   }
   if(num >= MAX) {
      write("Sorry, you guys aren't selling what's in storage now!");
      return 1;
   }
   tell_room(ETO,"Tulmak takes the "+ob->query_name()+" and puts it into a bin for storage.");
   add_item(ob);
   num++;
   if(ob) ob->remove();
   save_object(SAVE_MON);
   return 1;
}

int retrieve_item(string which){
   object tmp;
   int i,value;
   string name, type;
   string fname,fn,s1;
   string guild;
   int j,q;

   if(!which){
      write("You must specify the number of the item to retrieve.");
      return 1;
   }
   sscanf(which,"%d",i);
   if(!i) {
      write("You must specify the number of the item to retrieve.");
      return 1;
   }
   i--;
   if(i>MAX){
      write("Not that many items are stored here.");
      return 1;
   }
   if(items[i]==0){
      write("There is nothing in that bin to retrieve.");
      return 1;
   }
   sscanf(items[i],"%s val %d type %s",name,value,type);
   if(!TP->query_funds(type,value)) {
      force_me("say You need to give me "+value+" "+type+" to get the "+name+" out of storage.");
      return 1;
   }
   fname = STORAGE_DIR+"ob"+i+".o";
   if(file_exists(fname)) {
      write("Tulmak goes to retrieve the item from storage.");
      fn = read_file(fname,1,1);
      if(!stringp(fn)) return 0;
      sscanf(fn,"#%s.c",s1);
      s1 = "/"+s1;
      if(catch(tmp = new(s1)))
         tell_object(TP,"Error: File "+s1+" not found");
      sscanf(fname,"%s.o",fn);
      j = catch(q = tmp->restore_me(fn));
      if(!j){
          TP->use_funds(type, value);
         guild = GUILD_D->query_control_guild("/d/guilds/fist/hall/main");
         GUILD_D->add_guild_gold(guild,value);
         write("Tulmak hands you "+name+".");
         if(tmp->move(TP) != MOVE_OK){
            tmp->move(ETP);
            tell_object(TP,"You drop it.");
	 }
         tmp->restore_me(fn+".o");
         rm(fname);
      }
      items[i]=0;
      num--;
      save_object(SAVE_MON);
      return 1;
   }
}

void add_item(object ob){
   string desc;
   int i;

   desc = ob->query_short()+" val "+ob->query_value()+" type "+ob->query_cointype();
   for(i=0;i<MAX;i++){
      if(items[i]==0) {
         items[i]=desc;
         ob->save_me(STORAGE_DIR+"ob"+i);
         break;
      }
   }
}

int list_items(string str){
   int inc;
   string tmp;
   string name,cointype;
   int value;
   object ob;

   if(str) return 0;
   tmp ="%^BOLD%^These are the items currently in storage:%^RESET%^\n\n";
   tmp += "%^BOLD%^%^RED%^Bin  Item                          Value%^RESET%^\n";
   tmp +="%^BLUE%^=============================================%^RESET%^\n";
   for(inc = 0; inc < sizeof(items);inc++){
      if(items[inc] == 0) continue;
      sscanf(items[inc],"%s val %d type %s",name,value,cointype);
      tmp += arrange_string((inc+1)+": ",5);
      tmp += arrange_string(name,30);
      tmp += arrange_string(value,5);
      tmp += arrange_string(cointype,8);
      tmp += "\n";
   }
   tmp += "\n";
   TP->more(explode(tmp,"\n"));
   return 1;
}

int show_item(string which){
   int i,value;
   string name, type;
   object tmp;
   string fname, fn, s1;
   int j,q;

   if(!which){
      write("You must specify the number of the bin to look in.");
      return 1;
   }
   sscanf(which,"%d",i);
   if(!i) {
      write("You must specify the number of the bin to look in.");
      return 1;
   }
   i--;
   if(i>MAX){
      write("Not that many items are stored here.");
      return 1;
   }
   if(items[i]==0){
      write("There is nothing in that bin.");
      return 1;
   }
   sscanf(items[i],"%s val %d type %s",name,value,type);
   fname = STORAGE_DIR+"ob"+i+".o";
   if(file_exists(fname)) {
      write("Tulmak opens bin "+(i+1)+" so you can look inside.");
      fn = read_file(fname,1,1);
      if(!stringp(fn)) return 0;
      sscanf(fn,"#%s.c",s1);
      s1 = "/"+s1;
      if(catch(tmp = new(s1)))
         tell_object(TP,"Error: File "+s1+" not found");
      sscanf(fname,"%s.o",fn);
      j = catch(q = tmp->restore_me(fn));
      if(!j){
         write("You look at "+name+" in bin "+(i+1)+".");
         tmp->restore_me(fn+".o");
         write(tmp->query_long());
      }
   }
   return 1;
}

int count(){
   int i,total;

   total = 0;
   for(i=0;i<MAX;i++)
      if(items[i]!=0) total++;
   return total;
}
