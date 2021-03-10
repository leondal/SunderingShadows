//control_d/c

#include <std.h>

inherit DAEMON;


mapping __Mons;
mapping __Amounts;
int total;
int max_level;


void create(){
   ::create();

}

void set_max_level(int level){
   max_level = level;
}

void set_monsters(string * files, int * quantity){
   int i,j;

   if(sizeof(files) != sizeof(quantity)){
      return;
   }

   if(!__Mons) __Mons = ([]);

   if(!__Amounts) __Amounts = ([]);

   j = sizeof(files);
   for(i=0;i<j;i++){
      __Mons[files[i]] = ({});
      __Amounts[files[i]] = quantity[i];
      total += quantity[i];
   }

}

void cleanUpMons(string key){
   object *tmp = ({});
   int i,j;
   if(!__Mons[key]){
      __Mons[key] = ({});
      return;
   }
   j = sizeof(__Mons[key]);
   for(i=0;i<j;i++){
      if(!objectp(__Mons[key][i])){
	 tmp += ({__Mons[key][i]});
      }
   }
   __Mons[key] -= tmp;
}	

int clean_up(){return 1;}



void make_monsters(object room, int amount, int chance, int rand){
   int num, query, rang, i, j,k, flag;
   string *aKey;
   object ob;

   if(random(100)+1 > chance) return;
   if(rand){
      num = random(amount)+1;
   } else {
      num = amount;
   }
   k = sizeof(aKey = keys(__Amounts));

   for(i=0;i<num;i++){
      flag = 0;
      rang = 0;
      query = random(total)+1;
      j = 0;
      while(!flag){
	 rang += __Amounts[aKey[j]];
	 if(query <= rang){
	    cleanUpMons(aKey[j]);
	    if(sizeof(__Mons[aKey[j]]) < __Amounts[aKey[j]]){
	       ob = new (aKey[j] );
	       ob->set_max_level(max_level);
	       ob->move(room);
	       __Mons[aKey[j]] += ({ob});
	       flag = 1;
	    }
	 }
	 j++;
	 if(j >= sizeof(aKey)) flag = 1;

      }
   }

}


mapping query_mons(){
   return __Mons;
}
