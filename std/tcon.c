//	/std/container.c
//	from the Nightmare mudlib
//	code inherited by all items which can hold things
//	created by Sulam@TMI for the TMI mudlib distribution
//	13 january 1992
// Bug with invisible objects fixed by Pallando 93-07-14

#include <std.h>

inherit OBJECT;

nosave private int internal_encumbrance;
nosave private int possible_to_close;
nosave private int is_closed;
nosave private int max_internal_encumbrance;

void set_max_internal_encumbrance(int max);
int query_max_internal_encumbrance();
int query_internal_encumbrance();
int receive_objects();
int add_encumbrance(int enc);


// Implement an object that can contain things.
// The 'remove()' function is implemented by the move.c object
// and will take care of any objects inside this object.

int is_container() {
   return 1;
}


void set_max_internal_encumbrance(int max) {
   max_internal_encumbrance = max;
}

void set_possible_to_close(int pos) {
   possible_to_close = pos;
}

int query_internal_encumbrance() {
   return internal_encumbrance;
}

int query_max_internal_encumbrance() {
   return max_internal_encumbrance;
}

int toggle_closed() {
   if(possible_to_close) {
      if(is_closed) is_closed = 0;
      else is_closed = 1;
      return 1;
   } else return 0;
}

void set_closed(int i) {
   if(possible_to_close) {
      is_closed = i;
   }
}

// This function is called from move()

int receive_objects() {
   if(is_closed) return 0;
   return 1;
}

int add_encumbrance(int enc) {
   if( !max_internal_encumbrance ) return 1;
   if(enc > 0 && enc + query_internal_encumbrance() > max_internal_encumbrance ) return 0;
   internal_encumbrance += enc;
   return 1;
}

string describe_living_contents(object *exclude) {
   object *inv;
   mapping list;
   string *shorts;
   string tmp, ret;
   int i, x;

   i = sizeof(inv = filter_array(all_inventory(this_object())-exclude,
                                 "filter_living", this_object()));
   if(!i) return "";
   list = ([]);
   while(i--) {
      if((inv[i]->query_invis() && avatarp(inv[i])) || !inv[i]->is_detectable()) {
         continue;
      }
      if(inv[i]->query_magic_hidden() && !TP->detecting_invis()) {
         continue;
      }
      if(inv[i]->query_hidden())
          continue;
      set_property("information",1);
      if(!(tmp = (string)inv[i]->query_short())) {
         remove_property("information");
         if(wizardp(inv[i]) || random(101)> (int)previous_object()->query_level()) continue;
      }
      if(!tmp)
         continue;
      else  {
         if (inv[i]->query_invis()) {
            tmp = "("+tmp+")";
         }
         if(!list[tmp])
            list[tmp] = ({ inv[i]});
         else
            list[tmp] += ({ inv[i]});
      }
   }
   i = sizeof(shorts = keys(list));
   ret = "";
   while(i--) {
      if((x=sizeof(list[shorts[i]])) < 2) ret += shorts[i]+"\n";
      else ret += capitalize(consolidate(x, shorts[i]))+"\n";
   }
   return ret;
}

string describe_item_contents(object *exclude) {
   object *inv;
   mapping list;
   string ret, tmp;
   string *shorts,*temp;
   int i, x;

   i = sizeof(inv = filter_array((all_inventory(this_object())-exclude),
                                 "filter_non_living", this_object()));
   if(!i) return "";
   list = ([]);
   while(i--) {
       if((inv[i]->query_hidden() || inv[i]->query_magic_hidden()) && (!TP->detectin_invis() || !inv[i]->is_detectable())){
                   if(TP!=TO)
         continue;
      }
      set_property("information",1);
      if(!(tmp = (string)inv[i]->query_short())) continue;
      remove_property("information");
      if(tmp == "") continue;
      if( (temp=explode(tmp," ")) == ({}) ) continue;

      if (inv[i]->query_hidden() || inv[i]->query_magic_hidden()) {
         tmp = "("+tmp+")";
      }
      if(!list[tmp]) list[tmp] = ({ inv[i]});
      else list[tmp] += ({inv[i]});
   }
   i = sizeof(shorts = keys(list));
   if(!i) return "";
   if((x=sizeof(list[shorts[--i]])) == 1)
      ret = capitalize(shorts[i]);
   else ret = capitalize(consolidate(x, shorts[i]));
   if(!i) return(x <2 ? ret+" is here.\n" : ret +" are here.\n");
   else if(i==1)
      return ret+", and "+consolidate(sizeof(list[shorts[0]]), shorts[0])+
      " are here.\n";
   else {
      while(i--) {
         if(!i) ret += ", and ";
         else ret += ", ";
         ret += consolidate(sizeof(list[shorts[i]]), shorts[i]);
      }
   }
   return ret+" are here.\n";
}

int filter_living(object ob) {return(living(ob) || ob->query("not living"));}

int filter_non_living(object ob) {return !(living(ob) || ob->query("not living"));}
