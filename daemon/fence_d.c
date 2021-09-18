//ACTIVELY USED

//fence_d

#include <std.h>
#include <security.h>
#include <new_exp_table.h>

#define SAVEOBJECT "/daemon/fence_d"
#define INVDIR "/inv/fence/"
#define LF(X) log_file("player/fencing",X);
#define DEBUG(X) TO->fnord(X);

#define BASE_FEE_PERCENT 50
// The standard cut.
#define MIN_FEE_PERCENT 15
// They won't let you rip them off, no matter how pretty or much you've done
#define MAX_FEE_PERCENT 95
// They will, however, bend you over backwards or forwards.
#define MAX_ITEMS 1000

inherit DAEMON;


nosave mapping loaded_objects = ([ ]);

void save_item(object item);

string query_short() { return "Fence daemon"; }
string query_name() { return "Fence daemon."; }
void Restore(){
  seteuid(UID_DAEMONSAVE);
  restore_object(SAVEOBJECT);
  seteuid(getuid());
}

void Save(){
  seteuid(UID_DAEMONSAVE);
  save_object(SAVEOBJECT);
  seteuid(getuid());
}

void create(){
  ::create();
  //Restore();
//  Save();
// We don't need to save anything yet.
}

void reset(){
  filter_array(keys(loaded_objects),"objectp",TO);
// Run through the list of elements, Check them to make sure they're good, and..
// Oops I forgot to finish this.  - Garrett
}
int addtoAccount(object who, int amount){
  int tot;
  if(!objectp(who)) {
    return 0;
  }
  if(who->query("thief account")) {
    tot = who->query("thief account");
    tot += amount;
    who->set("thief account",tot);
  } else {
    tot = amount;
    who->set("thief account",tot);
  }
  return tot;
}

int query_account(object who){
  if(!objectp(who)) {
    return 0;
  }
  return who->query("thief account");
}

int good_customer(object fence, object who, int adj, int base){
  int original_base=base;

  // Okay, when I get charisma_d running, we can either up/down the
  // $ value of the stuff they've brought in, or just take % points off
  // what the going rate is...

  switch (adj) {
  case 0..1000:
    base -= 0; // 50
    break;
  case 1001..5000:
    base -= 2; // 48
    break;
  case 5001..10000:
    base -= 4; // 46
    break;
  case 10001..40000:
    base -= 10; // 40
    break;
  case 40001..80000:
    base -= 15; // 35
    break;
  case 80001..150000:
    base -= 20; // 30
    break;
  default:
    base -= 25; // 25
  }

  if (base >= MAX_FEE_PERCENT) base = MAX_FEE_PERCENT ;
  if (base <= MIN_FEE_PERCENT) base = MIN_FEE_PERCENT ;
  switch (base-original_base) {
  case 26..10000:
    fence->force_me("say I can give you CREDIT for it, but....");
    // Nobody should be this pathetic... But maybe some are...
    break;
  case 11..25:
    fence->force_me("say Hmm. Lets see what I CAN do for you.");
    break;
  case -1..10:
    fence->force_me("say You're new here, you understand there'll be a fee for this... service.");
    fence->force_me("chuckle");
    break;
  case -3..-2:
    fence->force_me("say You look familiar, I'll give you a bit of a discount.");
    break;
  case -9..-4:
    fence->force_me("say Yeah, I think I know you.");
    break;
  case -14..-10:
    fence->force_me("say Hey, got more huh? Well I'll give you a break on the fee.");
    break;
  case -19..-15:
    fence->force_me("say I've got to say, don't remember your name, but you are a valuable member of our little community. I'll give you a break.");
    break;
  case -24..-20:
    fence->force_me("laugh out loud");
    fence->force_me("say Yeah yeah, I know, so how's life?");
    break;
  default:
    fence->force_me("emote shakes "+fence->query_possessive()+" head in amazement.");
    fence->force_me("say For you the guild master has a special rate.");
  }
  return base;
}

void launder(object fence, object who, int amount){

  int total, difficulty, adj, base, diff, adj_amount, exp;

  if(!objectp(who)) return;
  if(!objectp(fence)) return;

  total = who->query("stolen money");
  if (amount <= 0) {
  fence->force_me("say Look, I don't have time for this nonsense. Get on with it.");
  return;
}
  if (amount > total) {
    fence->force_me("say I'm only interested in stolen money. You're trying to launder more then you've stolen.");
    return;
  }

  fence->force_me("hmm");
  if (!who->query_funds("gold",amount)) {
    fence->force_me("say You don't even have that money. You spent it all on booze and such.");
    return;
  }
  base = BASE_FEE_PERCENT;
  adj = who->query("total laundered money");
  base = good_customer(fence, who,adj,base);
  who->use_funds("gold",amount);
  diff = total - amount;
  who->set("stolen money",diff);
  fence->force_me("emote takes the money.");
  adj_amount = amount - (amount*base)/100;
  if(amount == 1) {
     fence->force_me("say Don't be wasting my time with 1 gold punk.");
     adj_amount = 0;
  } else {
  fence->force_me("say I'm gonna give ya "+adj_amount+" for that hard work.");
  // '
  tell_object(who,"The fence puts "+adj_amount+" into your thief account.");
  }
  if (who->query("thief account")) {
    who->set("thief account",(int)who->query("thief account")+adj_amount);
  } else {
    who->set("thief account",adj_amount);
  }

  who->set("total laundered money",adj+amount);
//  who->add_exp(exp=(amount*((int)who->query_highest_level()/5 +1)));
  if (who->is_class("thief"))
    who->add_general_exp("thief",exp=(amount*((int)who->query_level("thief")/5 +1)));
  else if (who->is_class("bard"))
    who->add_general_exp("bard",exp=(amount*((int)who->query_level("bard")/10 +1)));
  else
    exp = 0;
  seteuid(UID_LOG);
  LF(who->query_name()+" laundered "+amount+" gold");
  LF(" for "+adj_amount+" credit and ");
  if (who->is_class("thief")) {
    LF(""+exp+" (thief) experience on "+ctime(time())+"\n");
  } else if (who->is_class("bard")) {
    LF(""+exp+" (bard) experience on "+ctime(time())+"\n");
  } else {
    LF("(No XP Intentionally!) on "+ctime(time())+"\n");
  }
  seteuid(getuid());
}

int value(object fence, object who, object item)
{
    int base, adj, value1;
    mapping stolen;

    base = BASE_FEE_PERCENT;
    adj = who->query("total fenced money");
    base = good_customer(fence, who, adj,base);

    stolen = (mapping)item->query_property("stolen");
    if(!stolen || !stolen[who->query_name()]) {
        return 0;
    }
    value1 = item->query_value();
    value1 = stolen[who->query_name()]["max value"] <= value1?stolen[who->query_name()]["max value"]:value1;

    value1 -= (value1*base)/100;
    return value1;
}

void fence(object fence, object item, object who)
{
    //function was modified - check /daemon/fence_d.saide for the old function
    //the idea was to increase the amount of exp gained so that fencing is worthwhile
    //to any thief, regardless of
	mapping stolen;
	int value, adj_value, difficulty, adj, base;
	int ench, levelmod, expdiff, wholevel, expvalue;
	int x, myLev;
    float exp_perc;
	object *contents;

  	if(!objectp(fence)) return;
    if(!objectp(item))  return;
    if(!objectp(who))   return;

  	stolen = (mapping)item->query_property("stolen");
  	if(!stolen || !stolen[who->query_name()])
    {
        fence->force_me("say You didn't steal that, get out of here.");
        return;
    }

    value = item->query_value();
    value = stolen[who->query_name()]["max value"] <= value?stolen[who->query_name()]["max value"]:value;
    if(!value)
    {
        fence->force_me("say That has no value, do you think I'm a fool?");
        return;
    }
    base = BASE_FEE_PERCENT;
    adj = who->query("total fenced money");
    base = good_customer(fence, who, adj,base);

    fence->force_me("emote takes the merchandise.");
    adj_value = value - (value*base)/100;
    fence->force_me("say I'm gonna give ya "+adj_value+" for that hard work.");
    tell_object(who,"The fence puts "+adj_value+" into your thief account.");

    if (who->query("thief account")) who->set("thief account",(int)who->query("thief account")+adj_value);
    else who->set("thief account",adj_value);

    who->set("total fenced money", adj+value);
    difficulty = stolen[who->query_name()]["difficulty"];
    if(item->query_property("enchantment") > 0) { ench = item->query_property("enchantment"); }
    else ench = 1;
    if (who->is_class("thief")) wholevel = (int) who->query_level("thief");
    else if (who->is_class("bard")) wholevel = (int) who->query_level("bard");
    else wholevel = (int) who->query_lowest_level();
    levelmod = (wholevel / 3) + 1;
    switch(adj_value)
    {
        case 0..1000:   exp_perc = 0.025; break;
        case 1001..5000: exp_perc = 0.035; break;
        case 5001..25000: exp_perc = 0.04; break;
        case 25001..200000: exp_perc = 0.050; break;
        default: exp_perc = 0.050; break;
    }
    expdiff = ( (difficulty<=0?1:difficulty) /3);
    if(expdiff < 1) expdiff = 1;
    myLev = (int)who->query_adjusted_character_level();
    if(myLev > 100) myLev = 100;
    expvalue = to_int(to_float(exp_for_level(myLev)) * exp_perc);
    expvalue = to_int(to_float(expvalue * expdiff) / 33);
    tell_object(who, "exp value = "+expvalue);
    seteuid(UID_LOG);
    LF(who->query_name()+" ("+wholevel+") fenced "+item->query_short());
    LF(" worth "+value+" for "+adj_value+" credit and ");
    if (who->is_class("thief") || who->is_class("bard"))
    {
        who->add_exp(expvalue);
        LF(""+expvalue+" (thief or bard) experience.\n");
    }
    else
    {
        expvalue = 0;
        LF("(No XP Intentionally!)\n");
    }

    if(expvalue > (wholevel * 4000))
    {
        log_file("reports/fencing_high",who->query_name()+" ("+wholevel+
        ") fenced "+item->query_short()+" worth "+value+" for "+adj_value+
        " credit and "+expvalue+" exp. (diff.: "+difficulty+").\n");
    }
    seteuid(getuid());

    if(item->is_container())
    {
        contents = deep_inventory(item);
        for(x = 0;x < sizeof(contents);x++)
        {
            if(contents[x]->query_item_owner_prop("fence_clear"))
            {
                contents[x]->clear_item_owners();
            }
        }
    }
    if (!item->id("kitxyz"))
    if(item->query_item_owner_prop("fence_clear"))
    {
        item->clear_item_owners();
    }
    save_item(item);
    item->move("/d/shadowgate/void");
    item->remove();
}

object query_object_loaded_by_filename(string filename) {
// This queries the loaded_objects mapping and returns the object pointer to
// the object if it's indeed loaded. It returns 0 otherwise.
  int which;
  string * array;

  if(!stringp(filename) || filename == "")
    return 0;

  array = values(loaded_objects);
  if ((which=member_array(filename,array)) != -1)
    return (keys(loaded_objects)[which]);
  else
    return 0;
}

int query_loaded_somewhere(string filename) {
// This just returns true or false, using the above function to query the map
// This way if we change something, we don't have to change everything.
  if(!stringp(filename) || filename == "")
    return 0;
  if (objectp(query_object_loaded_by_filename(filename)))
    return 1;
  else
    return 0;
}


string query_loaded_object(object ob) {
// This returns a filename of an object from the loaded array.
// Returns a null string if no object exists in the array.
  string hold;
  if (!objectp(ob))
    return "";
  if (stringp(hold=loaded_objects[ob]) && hold)
    return hold;
  else
    return "";
}

int add_loaded_object(object ob, string file_name) {
// Adds a object and filename into the mapping.
  if (!objectp(ob))
    return 0;
  if (!stringp(file_name) || file_name == "" || !file_exists(file_name))
    return 0;
  if (!mapp(loaded_objects))
    loaded_objects= ([ ]);
  loaded_objects[ob]=file_name;
  return 1;

}

int remove_loaded_object(object ob) {
  map_delete(loaded_objects,ob);
// Clears out an object from the mapping. (Used with fence_item)
// Note items aren't deleted on load. They're deleted on selling.
  return 1;
}



void save_item(object item){
  int i=0;
  if(item->id("bottle") || item->id("kit") || item->id("sack") || item->id("basket") || item->id("chest") || item->id("backpack")) return;
  if(!item->isMagic()) return;
  while(file_exists(INVDIR+"ob"+i+".o") ) {
    i++;
    if(i > MAX_ITEMS) {
      return;
    }
  }
  item->set("fenced item", 1);
  item->save_me(INVDIR+"ob"+i);

}

int restore_item(object dest){
  int i;
  string * items;
    string error;
  object ob;
  string filename, s1, v, thing;

  items = get_dir(INVDIR+"ob*.o");

  if(!sizeof(items)) {
    return 0;
  }

// I might be able to use filter_array here, But I didn't.
  i = sizeof(items);
  while (i--) {

//    DEBUG(identify(items));
//    DEBUG(i);
//    DEBUG(thing);

    thing = items[i];
    if (query_loaded_somewhere(INVDIR+thing))
      items -= ({ thing });

    if(!sizeof(items)) {
      return 0;
    }
  }

  if(!sizeof(items)) {
    return 0;
  }

  i= random(sizeof(items));

  thing = INVDIR + items[i];
  thing = thing[0..strlen(thing)-3];
// strlen - 3 gets the , off of the ,o for some reason, strlen -2 didn't
  v = read_file(INVDIR+items[i],1,1);
  if(!stringp(v))
    return 0;
  sscanf(v,"#%s.c",s1);
  s1 = "/"+s1;
     error = catch(ob=new(s1));
    if(error){
      LF("Error in loading "+s1+": "+error+"\n");
    return 0;
  }
  add_loaded_object(ob, INVDIR+items[i]);
  ob->restore_me(thing);
  ob->move(dest);
//  DEBUG(thing);

// If it's a bag...
  if (ob->is_baggy())
    ob->save_me(thing);
// Save it again. (resave the loaded contents out.)
//DEBUG(environment(ob)->save_contents()+identify(environment(ob)));
// ETO->query_property("save contents") wasn't working, so...
// Now it's ETO->save_contents();
//  LF("Restored "+ob->query_short()+" on "+ctime(time())+".\n");
  return sizeof(items);
  // tell us if we loaded one up. And tell us 1- the number of items remaining.

}

int fence_item(object ob) {
// This function handles removing the files from the fence directory.
  string file_name;
  int iter, object_num;
  string *associated_files;

  if ((file_name=query_loaded_object(ob)) == "")
    return 0;
  remove_loaded_object(ob);
// Zap it from the array.
  if (ob->is_baggy() && (sscanf(file_name,INVDIR+"ob%d.o",object_num))) {
    associated_files = get_dir(INVDIR+object_num+"save*.o");
    while (sizeof(associated_files)) {
//      DEBUG(associated_files[0]);
// Remove the bag's resaved contents.
      if(file_exists(INVDIR+associated_files[0]))
        rm(INVDIR+associated_files[0]);
      associated_files -= ({ associated_files[0] });
    }
  }
  rm(file_name);
// Then remove the file itself.
  return 1;
}
int query_no_clean() {return 1;}
int clean_up() {return 0;}
