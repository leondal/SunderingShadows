//	/std/container.c
//	from the Nightmare mudlib
//	code inherited by all items which can hold things
//	created by Sulam@TMI for the TMI mudlib distribution
//	13 january 1992
// Bug with invisible objects fixed by Pallando 93-07-14

#include "std.h"
#include "daemons.h"

//inherit OBJECT;
inherit "/adm/failsafe/Object_failsafe.c";

//These were static - removed the static part to see if it
//will fix the problem with lockable chests 
//being able to receive items even while locked - Saide
private static int internal_encumbrance;
private int possible_to_close;
private int is_closed;
private static int max_internal_encumbrance;

void set_max_internal_encumbrance(int max);
int query_max_internal_encumbrance();
int query_internal_encumbrance();
varargs receive_objects(object ob);
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

int query_possible_to_close() {
   return possible_to_close;
}


void set_possible_to_close(int pos) {
   possible_to_close = pos;
}

int query_internal_encumbrance() 
{
	object *this_inven=({});
	int i,weight;

	if(!objectp(TO)) { return internal_encumbrance; }
	this_inven = all_inventory(TO);
	if(sizeof(this_inven))
	{
		for(i=0;i<sizeof(this_inven);i++)
		{
			if(!objectp(this_inven[i])) { continue; }
			weight += (int)this_inven[i]->query_weight();
		}
	}
	internal_encumbrance = weight;
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
int query_closed(){
    return is_closed;
}

// This function is called from move()

varargs int loose_object(object ob){ return 1;}
varargs receive_objects(object ob)
{
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
    object work;
  mapping list;
  string *shorts;
  string tmp, ret;
  int i, x;

  int death_time;
  mixed *deaths;

  i = sizeof(inv = filter_array(all_inventory(this_object())-exclude,
				"filter_living", this_object()));
  if(!i) return "";
  list = ([]);
  while(i--) {
    if((inv[i]->query_true_invis() && avatarp(inv[i])) || !inv[i]->is_detectable()) {
      continue;
    }
    work = (objectp(TP))?TP:PO;
    if(inv[i]->query_magic_hidden() && !work->detecting_invis()) {
      continue;
    }

    if(inv[i]->query_hidden() && !work->detecting_invis()) { continue; }
    if(inv[i]->query_hidden() && !living(inv[i])) { continue; }

    TO->set_property("information",1);
    if(!(tmp = (string)inv[i]->query_short())) {
      TO->remove_property("information");
      if(wizardp(inv[i]) || random(101)> (int)previous_object()->query_level()) continue;
    }
    if(!tmp) 
      continue;
    else  {
/******* moving to user.c so it shows everywhere consistently & use new death & pk flags 
** *Styx* 9/23/06
**    if (objectp(inv[i]) && userp(inv[i])) {
**	if (x=sizeof(deaths=(mixed *)inv[i]->query_deaths())){
**	  death_time = deaths[x-1][1];
**	  if ((time() - death_time) < 1800)
**	    tmp = "%^BOLD%^%^RED%^D %^BOLD%^%^GREEN%^" + tmp;
**      }
**  	  if (newbiep(inv[i])) tmp = "%^BOLD%^%^CYAN%^N%^BOLD%^%^RED%^ "+tmp;
**    }
********/
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

string describe_item_contents(object *exclude) 
{
    object *inv,shape,ob,*temp=({});
    mapping list;
    string ret, tmp,*shorts;
    int i, x;

    if(objectp(shape = TO->query_property("shapeshifted")))
    {
        inv = all_inventory(TO);
        if(!pointerp(exclude)) { exclude = ({}); }
        temp = inv;
        for(i=0;i<sizeof(inv);i++)
        {
            if(!objectp(ob = inv[i])) 
            {
                temp -= ({ 0 });
                continue; 
            }

            if(base_name(ob) == "/d/azha/obj/gmr_ring") { temp -= ({ ob }); }
            if(base_name(ob) == "/d/azha/obj/mr_ring") { temp -= ({ ob }); }
            if(ob->id("kitxyz")) { temp -= ({ ob }); }

            if(FEATS_D->usable_feat(TO,"wild knowledge") && (PO == TO))
            {
                if(!ob->query_worn() && !ob->query_wielded()) { temp -= ({ ob }); }
            }
        }

        //temp = inv - temp;
    }
    
    if(pointerp(exclude)) { exclude += temp; }
    else { exclude = temp; }

    i = sizeof(inv = filter_array((all_inventory(this_object())-exclude),"filter_non_living", TO));
    if(!i) { return ""; }
    list = ([]);
    
    while(i--) 
    {
        if(!objectp(TO)) { continue; }
        if(inv[i]->query_magic_hidden() && (!TO->detecting_invis() || !inv[i]->is_detectable())) { continue; }
        if(inv[i]->query_hidden() && !TO->detecting_invis()) { continue; }
        if(inv[i]->query_hidden() && !living(inv[i])) { continue; }
        
        TO->set_property("information",1);
        if(!(tmp = (string)inv[i]->query_short())) continue;
        TO->remove_property("information");
        if(tmp == "") continue;
        if( (temp=explode(tmp," ")) == ({}) ) continue;
        if (inv[i]->query_hidden() || inv[i]->query_magic_hidden()) 
        {
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
    else 
    {
        while(i--) 
        {
            if(!i) ret += ", and ";
            else ret += ", ";
            ret += consolidate(sizeof(list[shorts[i]]), shorts[i]);
        }
    }
    return ret+" are here.\n";
}

int filter_living(object ob) {return(living(ob) || ob->query("not living"));}

int filter_non_living(object ob) {return !(living(ob) || ob->query("not living"));}


void init(){
    ::init();

    add_action("search", "search");
}


int search(string str){
    object *found;
    int i;

    if(this_player()->query_paralyzed())
      return notify_fail("You are unable to move.\n");
   if(this_player()->query_bound() || this_player()->query_tripped()) {
   this_player()->send_paralyzed_message("info",this_player());
      return notify_fail("");
   }
   if(this_player()->query_ghost())
      return notify_fail("You cannot do that in your immaterial state.\n");
   if((mixed *)this_player()->query_attackers() != ({ }))
      return notify_fail("You are too busy fighting to have time to search!\n");
   if(this_player()->query_unconscious())
      return notify_fail("Unconscious people can't do that.\n");
   if(this_player()->query_bound())
      return notify_fail("Bound people can't search.\n");
   if(this_player()->query_blind())
      return notify_fail("It's rather hard to search without being able to see.\n");
//    if(effective_light(this_player()) < 0)
//      return notify_fail("It is too dark.\n");
//    if(effective_light(this_player()) > 7)
//      return notify_fail("It is too bright to see anything.\n");

  if (TP->light_blind(0))
    return notify_fail(TP->light_blind_fail_message(TP->light_blind())+"\n");

    if (!stringp(str) && !TO->is_room()) {
        return 0;
    }
    if (!TO->is_room() && stringp(str) && !(TO == present(str, TP)) && !(TO == present(str, ETP))) {
        return notify_fail("There is no "+str+" to search here.\n");
    }

    if(living(TO) && !TO->query_bound() && !TO->query_unconscious() && !TO->query_paralyzed()) return notify_fail("They won't allow that,\n");
    found = "/daemon/hide_d"->searchContainer(TO,TP);
    if (!found || !sizeof(found) && !TO->is_room()) {
        message("my_action", "You find nothing odd.", this_player());
        return 1;
    }

    if(!found || !sizeof(found) && TO->is_room()){
         return 1;
    }
    for (i=0;i<sizeof(found);i++) {
        write("%^BOLD%^You find hidden in the "+query_short()+" a "+found[i]->query_short()+".");
    }
    return 2;
}

mixed query_property(string asking) {
  if (asking == "light") {
    if (::query_property("light_opaque") || TO->is_light_opaque())
      return 0;
  }
  return ::query_property(asking);
}
int query_light() {
  if (::query_property("light_opaque") || TO->is_light_opaque()) return 0;
  return ::query_light();
}
