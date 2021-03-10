// changing beginning common to 55 + random(int) for all races per discussions
// also maxing % to learn more than one based on int.
// last change was 9/03 *Styx* 9/16/06
//fixed the subtract_lang_overload() function so that garble will work
//changed query_all_langs() so that if its 0 in the langoverload 
//mapping it add it and thus you shouldn't see a bunch of 
//0's in the languages command - Saide - June 2008
// Bumping base common/undercommon to 75+ as per bunneez approved. Nienne, 04/09.

#include "std.h"
#include "daemons.h"
#include "langs.h"

//#define INTS ([1:1,2:1,3:1,4:1,5:1,6:1,7:1,8:1,9:2,10:2,11:2,12:3,13:3,14:4,15:4,16:5,17:6,18:7,19:7,20:8,21:8,22:9,23:10,24:11,25:12])
#define INTS ([1:1,2:1,3:1,4:1,5:1,6:1,7:1,8:1,9:2,10:2,11:2,12:3,13:3,14:4,15:4,16:5,17:5,18:6,19:6,20:7,21:7,22:8,23:8,24:9,25:9])


mapping __Lang;
mapping _grammar;
mapping subgrammar;
string choice;
static mapping langOverload = ([]);

void init_lang();

void set_grammar(string type,int level);

void set_lang(string type, int level) {
   if(!__Lang) init_lang();
   choice = "common";

   __Lang[type] = level;
   set_grammar(type,0);
   subgrammar[type] = 1;
}

mapping query_all_langs() 
{
   	mapping ret;
   	string *langs;
   	int i;
   
   	if(!__Lang) init_lang();
   	ret=([]);
   	ret += __Lang;
   	if (!langOverload) return ret;
   	langs = keys(langOverload);
   	for (i=0;i<sizeof(langs);i++)
	{
        	if (!ret[langs[i]])
		{
			if(langOverload[langs[i]] != 0)
			{
				ret[langs[i]] = langOverload[langs[i]];
			}
		}
        	else ret[langs[i]] += langOverload[langs[i]];
   	}
   	return ret;
}

int query_lang(string type) {
    int ability;
   if(!__Lang) init_lang();

    if(!__Lang[type]) ability = 0;
    else ability = __Lang[type];
    if(!langOverload || !langOverload[type]) return ability;
     return ability+langOverload[type];
   return __Lang[type];

}

int add_lang(string type) {
   if(sizeof(keys(__Lang)) >= INTS[TO->query_stats("intelligence")]) {
      return 0;
   }
   if (query_lang(type)) {
       return 0;
   }
   set_lang(type,1);
   return 1;
}

void init_lang() {
   string race;
   int intel;
   int x,i,j;
   __Lang = ([]);
   _grammar = ([]);
   subgrammar = ([]);

   intel = TO->query_stats("intelligence");
   race = TO->query_race();
   if(!race || race == "") return;
   if(!LANGS[race]) {
      race = "human";
   }
// adding a +1 to the random(intel) rolls so it doesn't come out 0 and preclude learning at all *Styx*  9/1/2003
   if(strsrch(race,"half-") != -1) {  // used to include  && intel > 8 (*Styx* 9/06)
     if(random(2)) {
       set_lang("common",100);
       set_lang(LANGS[race][0], (random(intel)+1) * 4);
     } else {
       set_lang("common",(75 + random(5)) );  // was (55 + random(intel))
       set_lang(LANGS[race][0],100);
     }
   } else {
     set_lang(LANGS[race][0],100);
   }
// was at the end, moving up so everyone gets common *Styx* 9/06
// altered so beast/underdark races get undercommon instead as default.
   if(member_array(TO->query_race(),LIVING_D->night_races()) == -1) { // if is not a night race
     if(!query_lang("common"))   // removed the intel > 8 && *Styx* 9/06
       set_lang("common",(75 + random(5)) );  // was (55 + random(intel))
   }
   else {
     if(!query_lang("common") && !query_lang("undercommon"))
       set_lang("undercommon",(75 + random(5)) );
   }
   j = INTS[intel]-3;  // changing from 2 to 3 to leave one slot open
   if(sizeof(LANGS[race]) < 2) return; // this won't apply now but I'll leave it *Styx*

   for(i=0;i<j;i++) {
      x = random(sizeof(LANGS[race])-1) +1;
      set_lang(LANGS[race][x],(random(intel)+5) * 4);  // adding +5 to int roll *Styx* 9/06
   }
}

void set_grammar(string type, int level) {
   if(!_grammar) _grammar = ([]);
   _grammar[type] = level;
}

int query_grammar(string type) {
   if(!_grammar) _grammar = ([]);
   if(!_grammar[type]) return 0;
   return _grammar[type];
}

mapping query_all_grammar() {
   return _grammar;
}

void add_grammar(string type, int level) {
   int needed;
   int intel;

   if(!query_lang(type))
      if(!add_lang(type))
         return;
   if (!__Lang[type] && langOverload[type]) {
       return;
   }
   if(!_grammar) _grammar=([]);
   if(!_grammar[type]) _grammar[type] = 1;
   if(!subgrammar) subgrammar = ([]);
   if(!subgrammar[type]) subgrammar[type]=1;
   intel = TO->query_stats("intelligence");
// to cap learning based on int *Styx* 9/06
   if(intel < 9)
	return;   // can't get over their original in common per discussion *Styx* 9/06
//   if(query_lang(type) > (82 + intel) ) // not doing this yet after all...
//        return;
// to slow down the last 10% of proficiency *Styx* 9/06
   if( (query_lang(type) > 90)  && random(25 - intel) )
	return;	
   needed = query_lang(type) - intel;
   if(needed < 1) needed = 1;
   subgrammar[type]+=level;
   while(subgrammar[type] > needed) {
      _grammar[type]+=1;
      subgrammar[type] -= needed;
   }
   while(_grammar[type] > 99) {
      __Lang[type] += 1;
      _grammar[type] -= 99;
   }
}

int set_spoken(string str) {
   if(TO->is_monster()) {
      choice = str;
      return 1;
   }
   if(!__Lang) init_lang();
    if(!query_lang(str)){
      return 0;
   }
   choice = str;
   return 1;
}

string query_spoken() {
   if(choice == 0) choice = "common";
   return choice;
}

void remove_lang(string str) {
   if(!str) return;
   if(member_array(str, keys(__Lang)) == -1) return;
   map_delete(__Lang, str);
   return;
}

int query_base_lang(string type){
    if(!__Lang || !__Lang[type]) return 0;
     return __Lang[type];
}

void add_lang_overload(string type, int amount)
{
	if(!langOverload) langOverload = ([]);
     	if(!langOverload[type]) langOverload[type] = amount;
    	else langOverload[type] += amount;
}

int query_lang_overload(string type)
{
       if (!langOverload[type]) return 0;
       return langOverload[type];
}

void remove_lang_overload(string type){
   if(!langOverload) return;
    if(!langOverload[type]) return;
     langOverload[type] = 0;
}

void subtract_lang_overload(string type, int amount)
{
	if(!amount) return;
   	if(!langOverload) langOverload = ([]);
    	if(!langOverload[type]) langOverload[type] = -amount;
	else langOverload[type] -= amount;
}

mapping query_over_load_mapping(){
    return langOverload;
}

mapping query_base_lang_mapping(){
    return __Lang;
}
