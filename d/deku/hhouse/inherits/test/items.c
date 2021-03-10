//      /std/room/items.c
//      from the Nightmare mudlib
//      allows player to create dummy items for the room
//      created by Descartes of Borg 16 june 1993
#include <std.h>
#include <config.h>
#include <daemons.h>
#include <astronomy.h>

#define DEFAULT_MSG "You do not notice that here.\n"
#define ASTRA (: find_object(ASTRONOMY_D), "la_sky" :)
#define DEFAULT_ITEMS ([ "sky":ASTRA, "sun":ASTRA, "moon":ASTRA, "moons":ASTRA,\
MOONS[0]:ASTRA, MOONS[1]:ASTRA, MOONS[2]:ASTRA, MOON_DESC[0]:ASTRA,\
MOON_DESC[1]:ASTRA, MOON_DESC[2]:ASTRA ])

private mapping __Items;

void set_items(mapping mp);
void add_item(string str, mixed val);
void remove_item(string str);
mapping query_items();

void create() 
{
    log_file("deku_code", "@@START@@\n items.c start of create function\n");
if(!__Items)
    __Items = DEFAULT_ITEMS;

log_file("deku_code", "@@END@@\n items.c end of create function\n");
}

string *query_id() { return keys(__Items); }

int id(string str) { return (str && query_items()[str]); }

void set_items(mapping mp) {
    mapping tmp;
    string *special;
    mixed *cles;
    int i, j;

    i = sizeof(cles = keys(mp));
    tmp = mp;
    while(i--) {
        if(functionp(mp[cles[i]]) && geteuid(this_object())
          != geteuid(mp[cles[i]][0])) return;

        if(pointerp(cles[i])) {
          j = sizeof(cles[i]);
          while(j--) tmp[cles[i][j]] = mp[cles[i]];
          map_delete(tmp, cles[i]);
        }
    }
    __Items = DEFAULT_ITEMS + tmp;
}

void add_item(string *str, mixed *val) {
    int i, j;
    string item;
    if(!__Items) __Items = DEFAULT_ITEMS;
    if(functionp(val) && geteuid(this_object()) != geteuid(val[0])) return;
    if(!pointerp(str)) {
      if(!pointerp(val)) {
         __Items[str] = val;
       }
      for(i = 0;i < sizeof(val);i++) {
        if(!__Items[str]) {
          __Items[str] = ({val[i]});
          continue;
        }
        __Items[str] += ({val[i]});
      }
    }

    for(i = 0;i < sizeof(str);i++) {
      item = str[i];
      if(!pointerp(val)) {
         __Items[item] = val;
      }
      for(j = 0;j < sizeof(val);j++) {
        if(!__Items[item]) {
           __Items[item] = ({val[j]});
           continue;
        } 
        __Items[item] += ({val[j]});
      }
    }

}

void remove_item(string *str) {
   int i;
   if(!__Items) __Items = DEFAULT_ITEMS;
   if(!pointerp(str)) {
     if(!__Items[str]) return;
     map_delete(__Items,str);
   }
   for(i = 0;i < sizeof(str);i++) {
     if(!__Items[str[i]]) continue;
     map_delete(__Items, str[i]);
   }
}

mixed query_item_description(string str) { 
   string *item_info;
   if(pointerp(query_items()[str])) {
      return query_items()[str][0];
    }
    return query_items()[str];
}

string query_no_item() { return DEFAULT_MSG; }

string describe(string str) {
    string tmp;
    mapping items = query_items();

    if(!items[str]) return query_no_item();
    else if(functionp(items[str]))
    return ( (stringp(tmp=(string)((*items[str])(str)))) ? tmp: "" );
    //modified to show the description of items - if the values
    //for a key are an in array and if those values are 
    //function pointers
    else if(pointerp(items[str])) 
      if(functionp(items[str][0])) {
        return ( (stringp(tmp=(string)((*items[str][0])(str)))) ? tmp: "" );
      }
      else {
        return items[str][0];
      }
    else return items[str];
}

mapping query_items() 
{ 
    if(!__Items || !sizeof(__Items)) { __Items = DEFAULT_ITEMS; }
    return __Items; 
}

void add_items(string * stuff2, string stuff){
    int i,j;
     j = sizeof(stuff2);
   for(i = 0;i<j;i++){
   add_item(stuff2[i],stuff);
  }
}

//added to show the writing on items in a room as well as 
//translate the writing per language they are written 
//in

__Read(string str) 
{
    string text, lang, tmp;
    string *data;
    if(!str) return 0;
	if(!objectp(this_player())) return 0;
	if(!objectp(this_object())) return 0;
    if(sizeof(__Items)) 
    {
        if(pointerp(__Items[str])) 
        {
            if(sizeof(__Items[str]) == 1) 
            {
                return 0;
            }
        
            if(sizeof(__Items[str]) < 3) 
            {
                __Items[str] += ({"common"});
            }
            if(sizeof(__Items[str]) < 3)
		{
			return 0;
		}
            if(functionp(__Items[str][1])) 
            {
                text = ((stringp(tmp=(string)((*__Items[str][1])(str)))) ? tmp: "default message" );
            }
        
            if(functionp(__Items[str][2])) 
            {
                lang = ((stringp(tmp=(string)((*__Items[str][2])(str)))) ? tmp: "common" );
            }
            
            if(!text) 
            {
                text = __Items[str][1];
            }
        
            if(!lang) 
            {
                lang = __Items[str][2];
            }
        
            if(objectp(TP)) 
            {
                text = "/daemon/language_d"->translate(text,lang,TP);
                tell_object(TP,text);
                if(!TP->query_invis()) 
                {
                    tell_room(TO,TP->QCN+" reads the "+str,TP);
                }
            return 1;
            }       
        }
        return 0;
    } 
    return 0;
}