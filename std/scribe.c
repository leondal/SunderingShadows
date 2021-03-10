//Adding the ability to translate the writing on any object -
//You give the item to the scribe, he'll save it to
//a folder, with his name - remove it,
//translate it, you can then pick
//said item up anywhere from 3 - 10 minutes
//later based on how long the writing is
//and how many people are ahead of you - Saide - June 2008

#include <std.h>
#include <langs.h>
#include <security.h>
#include <daemons.h>

inherit NPC;

nosave string SCRIBE_KEY = "/realms/saide/scribe_key";
nosave string SAVE_LOC = "/d/save/scribe/";
nosave string REGION;
nosave string SAVE_DIR;
nosave string SCRIBE_FILE;
nosave string SCRIBE_OFILE;
nosave int div = 20;
nosave int CLEAR_TIME = 604800;
nosave int end_game(string str, object ob, string lang);
int add_item_to_list(object ob, string pname, int cost, int how_long, string lang, string skey);
int GetNextItemNum();
string *my_languages();

void do_restore_object(string fname);

string __ScribeName;
mapping SavedObjects = ([]);

//The max number of items he can be working on translating
//at any given time - should all of them be finished,
//he'll take on more - basically making it this way so
//we dont have to wait on A player picking up their
//item before B player can get something translated - Saide

int MaxItems = 10;

//Max number of items he'll translate for any given person
//at any given time - you have to pick them up before
//he'll translate anymore for you - Saide

int YourItems = 3;

void create()
{
	::create();
}

void set_region(string str)
{
	REGION = str;
}

string query_region() { return REGION; }

string strip_colors(string sh)
{
    	string output = "", *list = ({});
    	string *words = ({});
      int i;
	if(!sh)
	{
		return output;
	}
	words = explode(sh, "%^");

	list +=({"RED", "YELLOW", "BLUE",
	"GREEN", "MAGENTA", "ORANGE", "CYAN", "BLACK", "WHITE"});

	list += ({ "B_RED", "B_YELLOW", "B_BLUE", "B_GREEN",
	"B_MAGENTA", "B_ORANGE", "B_CYAN", "B_BLACK", "B_WHITE"});

	list += ({"BOLD", "FLASH", "RESET"});

    	for(i = 0;i < sizeof(list);i++)
	{
		words = words - ({ list[i] });
	}
	output = implode(words,"");
	return output;
}

void StartFencing()
{
	string ob_name, fname, s1, *files;
	object item;
	int x, i, j, count = 0;
	if(!SavedObjects) return;
	files = keys(SavedObjects);
	if(!sizeof(files)) return;
	for(x = 0;x < sizeof(files);x++)
	{
		if(time() - SavedObjects[files[x]][0] > CLEAR_TIME)
		{
			//Load the item, remove it from the mapping,
			//count how many items are removed, fence the item
			//remove the file - Saide
			//stolen from the inventory loading daemon - Saide

			fname = read_file(files[x] + ".o",1,1);
			if(!stringp(fname))
			{
				continue;
			}
     			sscanf(fname,"#%s.c",s1);
		      s1 = "/"+s1;
		      if (catch(item = new(s1)))
			{
      			continue;
		      }
      		j = catch(i = item->restore_me(files[x]));
      		if (j)
			{
				continue;
      		}
			//End of stolen code :P
			"/daemon/fence_d"->save_item(item);
			item->remove();
			rm(files[x] + ".o");
			map_delete(SavedObjects, files[x]);
			count++;
		}
	}
	if(count != 0)
	{
		save_object(SCRIBE_FILE);
	}
}

void set_scribe_name(string name)
{
	if(!name) return;
	if(!stringp(name)) return;
	__ScribeName = name;
	SAVE_DIR = SAVE_LOC + __ScribeName + "/";
	SCRIBE_FILE = SAVE_DIR + __ScribeName + "info";
	SCRIBE_OFILE = SAVE_DIR + __ScribeName + "_object_";
	if(!get_dir(SAVE_DIR))
	{
		mkdir(SAVE_DIR);
	}
	if(file_exists(SCRIBE_FILE + ".o"))
	{
		restore_object(SCRIBE_FILE);
		StartFencing();
	}
}

string query_scribe_name()
{
	if(!stringp(__ScribeName)) return "";
	return __ScribeName;
}


void init()
{
	::init();
    	add_action("write_stuff","write");
	if(stringp(__ScribeName))
	{
		add_action("translate_object", "translate");
		add_action("estimate_object", "estimate");
		add_action("pickup_object", "request");
	}
}

int get_last_item_time()
{
	int x, highest = 0;
	string *people;
	if(!SavedObjects) return 0;
	if(!sizeof(keys(SavedObjects))) return 0;
	people = keys(SavedObjects);
	for(x = 0;x < sizeof(people);x++)
	{
		if(SavedObjects[people[x]][0] > highest)
		{
			highest = SavedObjects[people[x]][0];
			continue;
		}
	}
	return highest;
}

int get_cost(int len)
{
	int x;
	if(!len) return 0;
	x = (len / 20) * 100;
	if(x < 300)
	{
		x = 300;
	}
	return x;
}

string get_translate_time(int len)
{
	int time_it_takes, mod;
	if(!len)
	{
		return "Something went wrong, notify SAIDE or bug report this, immediately.";
	}
	switch(len)
	{
		case 0..50:
			time_it_takes = 180;
			break;
		case 51..125:
			time_it_takes = 300;
			break;
		case 126..225:
			time_it_takes = 420;
			break;
		default:
			time_it_takes = 600;
			break;
	}
	mod = get_last_item_time();
	if(!mod)
	{
		return (time_it_takes / 60);
	}
	else
	{
		mod = (mod - time()) / 60;
	}
	return (time_it_takes / 60) + mod;
}

int get_items_translating()
{
	int x, amt = 0;
	string *people;
	if(!SavedObjects) return 0;
	people = keys(SavedObjects);
	if(!sizeof(people)) return 0;
	for(x = 0;x < sizeof(people);x++)
	{
		if(SavedObjects[people[x]][0] > time())
		{
			amt++;
			continue;
		}
	}
	return amt;
}

int get_your_items(string pname)
{
	int x, amt = 0;
	string *people;
	if(!pname)
	{
		return -1;
	}
	if(!SavedObjects) return 0;
	people = keys(SavedObjects);
	if(!sizeof(people)) return 0;
	for(x = 0;x < sizeof(people);x++)
	{
		if(SavedObjects[people[x]][1] == pname)
		{
			amt++;
			continue;
		}
	}
	return amt;
}


void estimate_object(string str)
{
	object ob, *contents;
	string *written, actual_writing;
	int len, cost, x;
	if(!str)
	{
		tell_object(TP, "What do you want an estimate for?  Use <estimate [item_name]>");
		return 1;
	}
	if(!objectp(ob = present(str, TP)))
	{
		tell_object(TP, "You dont have a "+str+"!");
		return 1;
	}

	tell_room(ETP, TPQCN + " walks up to to " + query_short() + " and shows "+
	QO + " something.", TP);
	tell_object(TP, "You walk up to "+query_short() + " and show "+QO+
	" "+ob->query_short()+".");

	if(!ob->query("read"))
	{
		force_me("say I'm afraid I dont see any writing on that.");
		return 1;
	}
	if(ob->is_container())
	{
		contents = all_inventory(ob);
		if(sizeof(contents))
		{
			force_me("say if you want me to translate the writing on "+
			"that you're going to have to empty it.  I've got to much "+
			"to worry about already than to try to keep all "+
			"your stuff together.");
			return 1;
		}
	}
	written = ob->query("read");
	if(sizeof(written))
	{
		actual_writing = written[0];
	}
	else actual_writing = written;
	if(get_items_translating() > MaxItems)
	{
		force_me("say I'm sorry, but I'm busy translating other things "+
		"at the moment.  Check back later.");
		return 1;
	}
	x = get_your_items((string)TP->query_name());
	if(x == -1)
	{
		force_me("say something went wrong... please either bug report "
		"this or tell Saide directly.");
		return 1;
	}
	if(x >= YourItems)
	{
		force_me("say I'm already translating "+x+ " items for you, "+
		"either wait until I'm finished with those or pick some of "+
		"them up.");
		return 1;
	}
	len = strlen(strip_colors(actual_writing));
	cost = get_cost(len);
	force_me("say that will cost you about "+cost+" gold coins.");
	force_me("say and it will take me about "+get_translate_time(len)+
	" minutes to complete.");
	force_me("say Also, remember that you must leave the item with me until it is "+
	"finished.");
	return 1;
}
//Region Functions - Saide
string *my_languages()
{
	if(!REGION)
	{
		return ALL_LANGS;
	}
	switch(REGION)
	{
		case "shadow": case "tabor":
			return ({"common", "elven", "dwarvish", "halfling"});
		case "tonovi": case "juran":
			return ({"common", "undercommon", "drow", "kobold", "ogrish",
			"orcish", "beast", "goblin", "giant"});
		case "kinaro":
			return ({"common", "dwarvish", "gnomish", "halfling"});
		case "torm": case "azha": case "tharis":
			return ({"common", "giant", "dwarvish", "gnomish", "halfling",
			"ogrish", "orcish", "goblin", "kobold", "beast",
			"undercommon", "elven"});
		default:
			return ({"common"});
	}
}

string say_my_languages()
{
	if(!REGION)
	{
		return "all languages.";
	}
	switch(REGION)
	{
		case "shadow": case "tabor":
			return "languages common, dwarvish, and elven.";
		case "tonovi":
			return "languages common, undercommon, drow, kobold, ogrish, "+
			"orcish, goblin, and beast.";
		case "kinaro":
			return "dwarvish, gnomish, and halfling";
		case "torm": case "azha": case "tharis":
			return "common, giant, dwarvish, gnomish, halfling, "+
			"ogrish, orcish, goblin, kobold, "+
			"beast, and undercommon.";
		case "juran":
			return "drow, orcish, kobold, goblin, ogrish, "+
			"undercommon, and beast.";
		case "verbobone":
			return "common, ogrish, kobold, orcish, undercommon, beast, and "+
			"drow.";
		default:
			return "common language.";
	}
}
//END OF region functions


void translate_object(string str)
{
	object ob, key, *contents;
	string lang, targ, *written, actual_writing, skey;
	int len, cost, x;
	if(!str)
	{
		tell_object(TP, "What do you want translated?  and into what language? "+
		"use <translate [object] to [lang]>");
		return 1;
	}
	if(sscanf(str, "%s to %s", targ, lang) != 2)
	{
		tell_object(TP, "What do you want translated?  and into what language? "+
		"use <translate [object] to [lang]>");
		return 1;
	}
	if(member_array(lang, ALL_LANGS) == -1)
	{
		tell_object(TP, capitalize(lang) + " is not a valid language.");
		return 1;
	}
	if(!objectp(ob = present(targ, TP)))
	{
		tell_object(TP, "You do not have a "+targ+"!");
		return 1;
	}
	tell_room(ETP, TPQCN + " walks up to to " + query_short() + " and shows "+
	QO + " something.", TP);
	tell_object(TP, "You walk up to "+query_short() + " and show "+QO+
	" "+ob->query_short()+".");
	if(!ob->query("read"))
	{
		force_me("say I'm afraid I dont see any writing on that.");
		return 1;
	}
	if(member_array(lang, my_languages()) == -1)
	{
		force_me("say I'm afraid I dont know the "+lang+" language.");
		force_me("say I only understand the "+ say_my_languages());
		return 1;
	}
	if(member_array((string)ob->query_language(), my_languages()) == -1)
	{
		force_me("say I'm afraid I dont know the "+(string)ob->query_language() +
		" language to translate it for you.");
		force_me("say I only understand the "+ say_my_languages());
		return 1;
	}
	if((string)ob->query_language() == lang)
	{
		force_me("say the writing on that object is already written in "+
		lang+".  I'm afraid my services would not help you.");
		return 1;
	}
	if(ob->query_worn())
	{
		force_me("say I'm not going to translate something you're wearing.  "+
		"Please remove it first.");
		return 1;
	}
	if(ob->query_wielded())
	{
		force_me("say I'm not going to translate something you're wielding.  "+
		"Please let go of it first.");
		return 1;
	}
	written = ob->query("read");
	if(sizeof(written))
	{
		actual_writing = written[0];
	}
	else actual_writing = written;
	if(ob->is_container())
	{
		contents = all_inventory(ob);
		if(sizeof(contents))
		{
			force_me("say if you want me to translate the writing on "+
			"that you're going to have to empty it.  I've got to much "+
			"to worry about already than to try to keep all "+
			"your stuff together.");
			return 1;
		}
	}
	if(get_items_translating() > MaxItems)
	{
		force_me("say I'm sorry, but I'm busy translating other things "+
		"at the moment.  Check back later.");
		return 1;
	}
	x = get_your_items((string)TP->query_name());
	if(x == -1)
	{
		force_me("say something went wrong... please either bug report "
		"this or tell Saide directly.");
		return 1;
	}
	if(x >= YourItems)
	{
		force_me("say I'm already translating "+x+ " items for you, "+
		"either wait until I'm finished with those or pick some of "+
		"them up.");
		return 1;
	}
	len = strlen(strip_colors(actual_writing));
	cost = get_cost(len);
	if(!TP->query_funds("gold", cost))
	{
		force_me("say you dont have enough money to pay me.  It will cost "+
		cost + " gold coins to translate this item.");
		return 1;
	}
	force_me("emote takes the "+ob->query_short() + " from "+TPQCN+" and puts it "+
	"away.");
	force_me("say I should have it done in about "+get_translate_time(len)+
	" minutes, come see me then.  Dont forget to bring along "+cost+" gold coins.");
	key = new(SCRIBE_KEY);
	key->set_weight(ob->query_weight());
	key->set_scribe_key();
	key->set_scribe_owner(__ScribeName);
	skey = (string)key->query_scribe_key();

	if(add_item_to_list(ob, (string)TP->query_name(),
	cost, to_int(get_translate_time(len)), lang, skey) != 0)
	{
		key->move(TO);
		force_me("say oh and dont forget this, which I call a scribe key.  "+
		"It's how I'll determine which item is yours.");
		force_me("emote hands "+TPQCN+" a rune covered stone.");
		force_me("say Also, if you're not back within a week, I'm getting rid of the "+
		"item.");
		force_me("give rock to "+TPQN);
		if(present("scribe key", TO))
		{
			force_me("say it doesn't appear that you can carry it... "+
			"I'll just lay it on the "+
			"counter.");
			force_me("drop scribe key");
		}
		ob->remove();
	}
	if(environment(key) == TO)
	{
		key->remove();
	}
	return 1;
}

int add_item_to_list(object ob, string pname, int cost, int how_long, string lang, string skey)
{
	int item_num = 0;
	int finished_time;
	if(!ob) return 0;
	if(!stringp(pname)) return 0;
	if(!stringp(__ScribeName)) return 0;
	if(!stringp(skey)) return 0;
	if(!stringp(lang)) return 0;
	item_num = GetNextItemNum();
	if(item_num == -1) return 0;
	ob->save_me(SCRIBE_OFILE + item_num);
	if(!SavedObjects) SavedObjects = ([]);
	if(!SavedObjects[SCRIBE_OFILE + item_num])
	{
		finished_time = time() + (how_long  * 60);
		SavedObjects += ([ SCRIBE_OFILE + item_num : ({finished_time, pname, cost,
		ob->query_id(), lang, skey})]);
	}
	save_object(SCRIBE_FILE);
	return 1;
}

int GetNextItemNum()
{
	int num = 0, x;
	string *files, *tmp;
	if(!SAVE_DIR) return -1;
	if(!SCRIBE_FILE) return -1;
	files = get_dir(SAVE_DIR);
	for(x = 0;x < sizeof(files);x++)
	{
		if(files[x][(strlen(files[x])-2)..(strlen(files[x]))] != ".o") continue;
		if(SAVE_DIR + files[x] == SCRIBE_FILE + ".o") continue;
		//tell_object(find_player("saide"), "Counted file = "+files[x]);
		//tell_object(find_player("saide"), "Scribe file = "+SCRIBE_FILE);
		tmp = explode(files[x], "_");
		if(sizeof(tmp) > 1)
		{
			if(to_int(tmp[2]) >= num)
			{
				num = to_int(tmp[2]) + 1;
			}
		}
		continue;
	}
	return num;
}

string get_object_by_key(string pkey)
{
	int x;
	string *obs, tmp = "";
	if(!pkey) return tmp;
	if(!SavedObjects) return tmp;
	obs = keys(SavedObjects);
	if(!sizeof(obs)) return tmp;
	for(x = 0; x < sizeof(obs);x++)
	{
		if(SavedObjects[obs[x]][5] == pkey)
		{
			tmp = obs[x];
			return tmp;
		}
	}
	return tmp;

}

void pickup_object(string str)
{
	string key_name, passkey, ob_name, fname, s1, item_id, *written, actual_writing, *item_ids;
	object ob, item, paper;
	int x, i, j;
	if(!str)
	{
		tell_object(TP, "You have to specify what you want to request.");
		tell_object(TP, "Just use <request item from [scribe key]>.");
		return 1;
	}
	if(sscanf(str, "item from %s", key_name) != 1)
	{
		tell_object(TP< "You have to specify which scribe key you want to use.");
		tell_object(TP, "Just use <request item from [scribe key]>.");
		return 1;
	}
	if(!objectp(ob = present(key_name, TP)))
	{
		tell_object(TP, "You do not have a "+key_name+"!");
		return 1;
	}
	tell_object(TP, "You walk up to "+query_short() + " and let "+QO+
	" examine "+ob->query_short()+ ".");
	tell_room(ETP, TPQCN + " walks up to "+query_short()+ " and lets "+QO+
	" examine "+ob->query_short()+".", TP);
	if((string)ob->query_scribe_owner() != __ScribeName)
	{
		force_me("say that is not a scribe key that I've given out.  Sorry.");
		return 1;
	}
	passkey = (string)ob->query_scribe_key();
	if(!passkey)
	{
		force_me("say that hasn't been marked by me.  Sorry.");
		return 1;
	}
	ob_name = get_object_by_key(passkey);
	if(ob_name == "")
	{
		force_me("say I'm not currently translating anything for that "+
		"scribe key.");
		return 1;
	}
	if(SavedObjects[ob_name][0] > time())
	{
		force_me("emote grumbles loudly");
		force_me("say I haven't gotten around to translating that item yet.  I need "+
		"more time!  Come back in about "+((SavedObjects[ob_name][0] - time()) / 60) +
		" minutes.");
		return 1;
	}
	if(!TP->query_funds("gold", (int)SavedObjects[ob_name][2]))
	{
		force_me("say you dont seem to have enough gold to pay for my services.  "+
		"Come back with at least "+SavedObjects[ob_name][2]+ " gold coins.");
		return 1;
	}
	if(!file_exists(ob_name+".o"))
	{
		force_me("say something went wrong... bug report this or notify Saide "+
		"IMMEDIATELY!!");
		return 1;
	}
	//stolen from the inventory loading daemon - Saide

	fname = read_file(ob_name + ".o",1,1);
	if(!stringp(fname))
	{
		force_me("say something went wrong.. bug report me");
		return 1;
	}
     	sscanf(fname,"#%s.c",s1);
      s1 = "/"+s1;
      if (catch(item = new(s1)))
	{
      	force_me("say Error: File "+s1+" not found");
            return 1;
      }
      j = catch(i = item->restore_me(ob_name));
      if (j)
	{
      	force_me("say There is a problem with this item.  Bug report me.");
		return 1;
      }

	//End of stolen code :P
	item->move(TO);
	written = item->query("read");
	if(sizeof(written))
	{
		actual_writing = written[0];
	}
	else actual_writing = written;
	paper = new("/d/tharis/obj/paper");
	paper->set_read(actual_writing);
	paper->set_language((string)SavedObjects[ob_name][4]);
	paper->move(TO);
	paper->add_id("scribe_translation_text");
	TP->force_me("emote hands the rock over to the scribe");
	ob->remove();
	force_me("say here is the translation.");
	force_me("give scribe_translation_text to "+TPQN);
	if(present("scribe_translation_text", TO))
	{
		force_me("say I guess you cant carry it.  I'll lay it on the counter instead.");
		force_me("drop scribe_translation_text");
	}
	item_ids = item->query_id();
	item_id = item_ids[0];
	force_me("say here is your item back.");
	force_me("give "+item_id+ " to " + TPQN);
	if(present(item_id, TO))
	{
		force_me("say I dont think you can carry it.  I'll lay it on the counter instead.");
		force_me("drop "+item_id);
	}
	tell_room(ETP, TPQCN + " pays the scribe and "+QS+ " takes a slight bow.", TP);
	tell_object(TP, "You pay the scribe and "+QS+" takes a slight bow.");
	TP->use_funds("gold", (int)SavedObjects[ob_name][2]);

	map_delete(SavedObjects, ob_name);
	save_object(SCRIBE_FILE);
	rm(ob_name + ".o");
	return 1;
}

void write_stuff(string str)
{
	object ob;
    	string lang;

    	if (!str)
	{
      	force_me("say In what language should I write this?");
        	force_me("emote sits up, focusing intently, saying 'I know the "+say_my_languages()+
		"'");
        	return 1;
    	}
    	if (sscanf(str,"in %s",lang) != 1)
	{
      	force_me("say In what language should I write this?");
        	force_me("say Please it's simple enough, \"write in <lang>\".");
        	return 1;
    	}
    	if (member_array(lang,ALL_LANGS) == -1)
	{
      	force_me("say I am quite certain that "+lang+" is not a real language.");
        	return 1;
    	}
	if (member_array(lang, my_languages()) == -1)
	{
		force_me("say I do not understand the language "+ lang+" well enough to write "+
		"anything in it.");
		force_me("say I only know the "+say_my_languages());
		return 1;
	}
    	if (!TP->query_funds("gold",100))
	{
      	force_me("say You haven't the funds to hire me.");
        	return 1;
   	}

    	force_me("say %^RESET%^Very well, and how would you like for it to read?");
    	write("Please write your message, Please hit <return> after each line.");
    	write("** to end message");
    	ob = new("/d/tharis/obj/paper");
    	input_to("long_desc","", ob, lang);
    	return 1;
}

void long_desc(string str, string long, object ob,string lang)
{
	if (str == "**")
	{
      	end_game(long,ob,lang);
    	}
	else
	{
      	if (!long) long = str+"\n";
        	else long = long+str+"\n";
        	input_to("long_desc", long, ob, lang);
    	}
}

protected int end_game(string str, object ob, string lang)
{
    if(!objectp(ob)) { return 0; }
    if(!stringp(str)) { str = ""; }
    if(!stringp(lang) || lang == "" || lang == " ") { lang = "common"; }

	ob->set("read",str);
    	ob->set("language",lang);
    	tell_player(TP, str);
    	tell_room(environment(this_player()),"The scribe meticulously finishes "+
	"the request.");
    	tell_room(environment(this_player()),"The scribe receives payment "+
	"then hands the paper over to "+TPQCN, TP);
    	write("The scribe receives payment with a smile and a bow "+
	"then hands the paper over to you.");
    	TP->use_funds("gold", 100);
    	ob->move(TP);
    	return 1;
}

void get_objects_data()
{
	return SavedObjects;
}
