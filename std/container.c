//	/std/container.c
//	from the Nightmare mudlib
//	code inherited by all items which can hold things
//	created by Sulam@TMI for the TMI mudlib distribution
//	13 january 1992
// Bug with invisible objects fixed by Pallando 93-07-14

#include <std.h>
#include <daemons.h>
#define MAX_ENCUMBRANCE ({15,25,35,45,60,85,105,125,145,160,180,195,210,225,235,245,255,270,285,300,305,310,315,320,325,330,335,340,345,350,355,\
                          360,365,370,375,380,385,390,395,400,405,410,415,420,425,430,435,440,445,450,455,460,465,470,475,480,485,495,500,505,510,\
                          515,520,525,530,535,540,545,550,555,565,576,585,590,595,600,605,610})
inherit OBJECT;

nosave private int internal_encumbrance;
private int possible_to_close;
private int is_closed;
nosave private int max_internal_encumbrance;

void set_max_internal_encumbrance(int max);
int query_max_internal_encumbrance();
int query_internal_encumbrance();
varargs receive_objects(object ob);
int add_encumbrance(int enc);


// Implement an object that can contain things.
// The 'remove()' function is implemented by the move.c object
// and will take care of any objects inside this object.

void create() { ::create(); }
void reset() { ::reset(); }

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

int query_max_internal_encumbrance()
{
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

int add_encumbrance(int enc)
{
    if (!max_internal_encumbrance) {
        return 1;
    }
    if (enc > 0 && enc + query_internal_encumbrance() > (int)TO->query_max_internal_encumbrance()) {
        return 0;
    }
    internal_encumbrance += enc;
    return 1;
}

int query_living_visibility(object item, object viewer)
{
    if (item->is_disease()) {
        return 0;
    }

    if (!objectp(viewer)) {
        return 0;
    }
    
    if(viewer->is_class("ranger"))
    {
        if(FEATS_D->is_active(viewer, "wild hunter"))
        {
            if(viewer->query_property("quarry") == item)
                return 1;
        }
    }

    if ((item->query_true_invis() && avatarp(item) && !avatarp(viewer)) || !item->is_detectable()) {
        return 0;
    }

    if (item->query_magic_hidden() && !(avatarp(viewer) || viewer->detecting_invis() || viewer->true_seeing())) {
        return 0;
    }

    //if (item->query_hidden() && !viewer->true_seeing()) {
    if(item->query_hidden())
    {
        return 0;
    }

    if (item->query_magic_hidden()) {
        return 2;
    }

    return 1;
}

string describe_living_contents(object* exclude)
{
    object* inv;
    object work;
    mapping list;
    string* shorts;
    string tmp, ret;
    int i, x;

    int death_time;
    mixed* deaths;

    i = sizeof(inv = filter_array(all_inventory(this_object()) - exclude, "filter_living", this_object()));
    if (!i) {
        return "";
    }
    list = ([]);
    while (i--) {

        work = (objectp(TP))?TP:PO;

        if (!query_living_visibility(inv[i], work)) {
            continue;
        }

        TO->set_property("information", 1);
        if (!(tmp = (string)inv[i]->query_short())) {
            TO->remove_property("information");
        }
        if (!tmp) {
            continue;
        }else {
            if (inv[i]->query_invis()) {
                tmp = (inv[i]->query_magic_hidden()?"%^RESET%^%^CYAN%^(inv)":"%^RESET%^%^ORANGE%^(hid)") + "%^RESET%^ " + tmp;
            }
            if (!list[tmp]) {
                list[tmp] = ({ inv[i] });
            }else {
                list[tmp] += ({ inv[i] });
            }
        }
    }
    i = sizeof(shorts = keys(list));
    ret = "";
    while (i--) {
        if ((x = sizeof(list[shorts[i]])) < 2) {
            ret += shorts[i] + "\n";
        }else {
            ret += capitalize(consolidate(x, shorts[i])) + "\n";
        }
    }
    return ret;
}

string describe_item_contents(object *exclude)
{
    object* inv, shape, ob, eto, * temp = ({});
    mapping list;
    string ret, tmp, * shorts;
    int i, x;

    if (objectp(shape = TO->query_property("shapeshifted"))) {
        inv = all_inventory(TO);
        if (!pointerp(exclude)) {
            exclude = ({});
        }
        temp = inv;
        for (i = 0; i < sizeof(inv); i++) {
            if (!objectp(ob = inv[i])) {
                temp -= ({ 0 });
                continue;
            }

            eto = environment(ob);

            if (base_name(ob) == "/d/azha/obj/gmr_ring") {
                temp -= ({ ob });
            }
            if (base_name(ob) == "/d/azha/obj/mr_ring") {
                temp -= ({ ob });
            }
            if (ob->id("kitxyz")) {
                temp -= ({ ob });
            }

            if (FEATS_D->usable_feat(TO, "wild knowledge") && (eto == TO)) {
                if (!ob->query_worn() && !ob->query_wielded()) {
                    temp -= ({ ob });
                }
            }
        }

        //temp = inv - temp;
    }

    if (pointerp(exclude)) {
        exclude += temp;
    }else {
        exclude = temp;
    }

    i = sizeof(inv = filter_array((all_inventory(this_object()) - exclude), "filter_non_living", TO));
    if (!i) {
        return "";
    }
    list = ([]);

    while (i--) {
        if (!objectp(TO)) {
            continue;
        }
        if (inv[i]->query_magic_hidden() && (!TO->detecting_invis() || !inv[i]->is_detectable())) {
            continue;
        }
        if (inv[i]->query_hidden() && !(avatarp(TO) || TO->true_seeing())) {
            continue;
        }
        if (inv[i]->query_hidden() && !living(inv[i])) {
            continue;
        }
        if (inv[i]->is_disease()) {
            continue;
        }
        TO->set_property("information", 1);
        if (!(tmp = (string)inv[i]->query_short())) {
            continue;
        }
        TO->remove_property("information");
        if (tmp == "") {
            continue;
        }
        if ((temp = explode(tmp, " ")) == ({})) {
            continue;
        }
        if (inv[i]->query_hidden() || inv[i]->query_magic_hidden()) {
            tmp = "%^ORANGE%^(hid)%^RESET%^ " + tmp;
        }
        if (!list[tmp]) {
            list[tmp] = ({ inv[i] });
        } else {
            list[tmp] += ({ inv[i] });
        }
    }
    i = sizeof(shorts = keys(list));
    if (!i) {
        return "";
    }
    if ((x = sizeof(list[shorts[--i]])) == 1) {
        ret = capitalize(shorts[i]);
    } else {
        ret = capitalize(consolidate(x, shorts[i]));
    }
    if (!i) {
        return (x < 2 ? ret + " is here.\n" : ret + " are here.\n");
    } else if (i == 1) {
        return ret + ", and " + consolidate(sizeof(list[shorts[0]]), shorts[0]) +
               " are here.\n";
    } else {
        while (i--) {
            if (!i) {
                ret += ", and ";
            } else {
                ret += ", ";
            }
            ret += consolidate(sizeof(list[shorts[i]]), shorts[i]);
        }
    }
    return ret + ".\n";
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
	if(!objectp(this_object())) return 0;
	if(!objectp(this_player())) return 0;
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
